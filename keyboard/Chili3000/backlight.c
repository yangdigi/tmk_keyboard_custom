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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "backlight.h"
#ifdef SOFTPWM_LED_ENABLE
#include "softpwm_led.h"
#else
#include "breathing_led.h"
#endif
#include "hook.h"

#ifdef BACKLIGHT_ENABLE

static uint8_t backlight_mode;

void backlight_enable(void);
void backlight_disable(void);
inline void backlight_set_raw(uint8_t raw);

#ifndef SOFTPWM_LED_ENABLE
#endif

static const uint8_t backlight_table[] PROGMEM = {
    0, 16, 128, 255
};

/* Backlight pin configuration
 * GPIO: PB7  PB3  PB2  PB1
 */
void backlight_enable(void)
{
#ifdef SOFTPWM_LED_ENABLE
    softpwm_led_enable_all();
#else
    DDRF  |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
    PORTF |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
    cli();
    TCCR1B |= (1<<WGM12);
    TCCR1B |= (1<<CS10);
    OCR1AH = (SOFTPWM_TIMER_TOP>>8)&0xff;
    OCR1AL = SOFTPWM_TIMER_TOP&0xff;
    TIMSK1 |= (1<<OCIE1A);
    sei();
#endif
}

void backlight_disable(void)
{
#ifdef SOFTPWM_LED_ENABLE
    softpwm_led_disable_all();
#else
    DDRF &= ~(1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
    cli();
    TCCR1B &= ~(1<<WGM12);
    TCCR1B &= ~(1<<CS10);
    TIMSK1 &= ~(1<<OCIE1A);
    sei();
    OCR1A = 0;
#endif
}

void backlight_set(uint8_t level)
{
    backlight_mode = level;
    softpwm_enable();
#ifdef BREATHING_LED_ENABLE
    switch (level) {
        case 1:
        case 2:
        case 3:
            backlight_enable();
#ifdef SOFTPWM_LED_ENABLE
            fading_led_disable_all();
            breathing_led_disable_all();
#else
            breathing_led_disable();
#endif
            backlight_set_raw(pgm_read_byte(&backlight_table[level]));
            break;
        case 4:
        case 5:
        case 6:
            backlight_enable();
#ifdef SOFTPWM_LED_ENABLE
            breathing_led_enable_all();
            fading_led_disable_all();
            breathing_led_set_duration(6 - level);
#else
            breathing_led_enable();
            breathing_led_set_duration(6 - level);
#endif
            break;
        case 7:
            backlight_enable();
            fading_led_enable_all();
            breathing_led_disable_all();
            fading_led_set_direction_all(FADING_LED_FADE_IN);
            fading_led_set_duration(3);
            break;
        case 8:
            backlight_enable();
            fading_led_enable_all();
            breathing_led_disable_all();
            fading_led_set_direction_all(FADING_LED_FADE_OUT);
            fading_led_set_duration(3);
            break;
        case 0:
        default:
#ifdef SOFTPWM_LED_ENABLE
            fading_led_disable_all();
            breathing_led_disable_all();
#else
            breathing_led_disable();
#endif
            backlight_disable();
            break;
    }
#else
    if (level > 0) {
        backlight_enable();
        backlight_set_raw(pgm_read_byte(&backlight_table[level]));
    }
    else {
        backlight_disable();
    }
#endif
}

#ifndef SOFTPWM_LED_ENABLE
#ifdef BREATHING_LED_ENABLE
void breathing_led_set_raw(uint8_t raw)
{
    backlight_set_raw(raw);
}
#endif
#endif

inline void backlight_set_raw(uint8_t raw)
{
#ifdef SOFTPWM_LED_ENABLE
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        softpwm_led_set(i, raw);
    }
#else
    softpwm_ocr_buff = raw;
#endif
}

#ifdef SOFTPWM_LED_ENABLE
#ifndef LEDMAP_ENABLE

void softpwm_led_init(void)
{
    DDRF  |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
}

void softpwm_led_on(uint8_t index)
{
    PORTF &= ~(1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
}

void softpwm_led_off(uint8_t index)
{
    PORTF |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
}

#endif
#endif

void hook_matrix_change(keyevent_t event)
{
    if (backlight_mode == 7) {
        if (event.pressed) {
            fading_led_set_delay_all(32);
            softpwm_led_decrease_all(16);
        }
    }
    if (backlight_mode == 8) {
        if (event.pressed) {
            fading_led_set_delay_all(32);
            softpwm_led_increase_all(16);
        }
    }
}


#ifndef SOFTPWM_LED_ENABLE
ISR(TIMER1_COMPA_vect)
{
    static uint8_t pwm = 0;
    pwm++;
    // LED on
    if (pwm == 0) {
        //PORTB |= (1<<PB6);
        PORTF &= ~(1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
        softpwm_ocr = softpwm_ocr_buff;
    }
    // LED off
    if (pwm == softpwm_ocr) {
        //PORTB &= ~(1<<PB6);
        PORTF |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
    }
}
#endif

#endif
