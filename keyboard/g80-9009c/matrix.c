/*
Copyright 2013,2014 Kai Ryu <kai1103@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void init_rows(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // disable JTAG
    MCUCR = (1<<JTD);
    MCUCR = (1<<JTD);

    // initialize row and col
    init_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 *  col: 0   1   2   3   4   5   6   7   8   9  
 *  pin: PC7 PB5 PB6 PB4 PD7 PD4 PD6 PD5 PD2 PD1
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRD  &= ~(1<<PD7 | 1<<PD6 | 1<<PD5 | 1<<PD4 | 1<<PD2 | 1<<PD1);
    PORTD |=  (1<<PD7 | 1<<PD6 | 1<<PD5 | 1<<PD4 | 1<<PD2 | 1<<PD1);
    DDRC  &= ~(1<<PC7);
    PORTC |=  (1<<PC7);
    DDRB  &= ~(1<<PB6 | 1<<PB5 | 1<<PB4);
    PORTB |=  (1<<PB6 | 1<<PB5 | 1<<PB4);
}

static matrix_row_t read_cols(void)
{
    return (PINC&(1<<PC7) ? 0 : (1<<0)) |
           (PINB&(1<<PB5) ? 0 : (1<<1)) |
           (PINB&(1<<PB6) ? 0 : (1<<2)) |
           (PINB&(1<<PB4) ? 0 : (1<<3)) |
		   (PIND&(1<<PD7) ? 0 : (1<<4)) |
           (PIND&(1<<PD4) ? 0 : (1<<5)) |
           (PIND&(1<<PD6) ? 0 : (1<<6)) |
		   (PIND&(1<<PD5) ? 0 : (1<<7)) |
           (PIND&(1<<PD2) ? 0 : (1<<8)) |
           (PIND&(1<<PD1) ? 0 : (1<<9));
}

/* Row pin configuration
 * pin:     PF6 PF5 PF4 PF1 PF0
 * row: off  1   x   x   x   x
 *      0    0   0   0   0   0
 *      1    0   0   0   0   1
 *      2    0   0   0   1   0
 *      3    0   0   0   1   1
 *      4    0   0   1   0   0
 *      5    0   0   1   0   1
 *      6    0   0   1   1   0
 *      7    0   0   1   1   1
 *      8    0   1   0   0   0
 *      9    0   1   0   0   1
 *      10   0   1   0   1   0
 *      11   0   1   0   1   1
 *      12   0   1   1   0   0
 *      13   0   1   1   0   1
 *      14   0   1   1   1   0
 *      15   0   1   1   1   1
 */
static void init_rows(void)
{
    DDRF  |= (1<<PF6 | 1<<PF5 | 1<<PF4 | 1<<PF1 | 1<<PF0);
}

static void unselect_rows(void)
{
    // Output high(DDR:1, PORT:1) to unselect
    PORTF &= ~(1<<PF6);
    PORTF |= (1<<PF5);
    PORTF |= (1<<PF4);
    PORTF |= (1<<PF1);
    PORTF |= (1<<PF0);
}

static void select_row(uint8_t row)
{
    (row & (1<<0)) ? (PORTF |= (1<<PF0)) : (PORTF &= ~(1<<PF0));
    (row & (1<<1)) ? (PORTF |= (1<<PF1)) : (PORTF &= ~(1<<PF1));
    (row & (1<<2)) ? (PORTF |= (1<<PF4)) : (PORTF &= ~(1<<PF4));
    (row & (1<<3)) ? (PORTF |= (1<<PF5)) : (PORTF &= ~(1<<PF5));
}