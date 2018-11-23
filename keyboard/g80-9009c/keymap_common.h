/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the Licens4, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "keymap_in_eeprom.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* 
 * 15x10 keymap
 */
#define KEYMAP( \
                                                                               KL0,KL1,  KK9,KP9,KL9,KQ9, \
     KM5,                                                                        KL2,    KK8,KP8,KL8,KQ8, \
     KM2,     KM1,  KM0,KN0,KN1,KN2,  KQ2,KQ1,KQ0,KK0,  KK1,KK2,KP1,KP2,     KM3,  KM4,  KP5,KP6,KK5,KP7, \
     KQ3,     KQ4,  KQ5,KQ6,KQ7,KL6,  KL5,KL3,KL4,KK3,  KK4,KP3,KP4,KN3,   KN4,KN5,KN6,    KK6,    KK7,   \
    KA9,KB9,  KA0,KB0,KA1,KB1,KA2,KB2,KA3,KD3,KB3,KA4,KB4,KD4,KB5,  KA5,   KB6,KA6,KD6,  KB7,KA7,KA8,KF8, \
    KD9,KC9,  KD0,  KC0,KD1,KC1,KF2,KD2,KC2,KF3,KC3,KF4,KC4,KC5,KD5, KF5,  KC6,KF6,KE6,  KD7,KC7,KC8,KG8, \
    KF9,KE9,  KF0,   KE0,KF1,KE1,KG1,KG2,KE2,KG3,KE3,KG4,KE4,KG5,KE5,                    KG7,KE7,KE8,     \
    KI9,KG9,  KI0, KF7,KG0,KI1,KJ1,KI2,KJ2,KI3,KJ3,KI4,KJ4,KI5,    KJ5,        KG6,      KI7,KJ7,KI8,KH8, \
    KJ9,KH9,  KJ0,  KH0,KH1,        KH2,                   KH3,KH4,  KH5,  KI6,KH6,KJ6,  KH7,    KJ8      \
) { \
    { KC_##KA0, KC_##KA1, KC_##KA2, KC_##KA3, KC_##KA4, KC_##KA5, KC_##KA6, KC_##KA7, KC_##KA8, KC_##KA9 }, \
    { KC_##KB0, KC_##KB1, KC_##KB2, KC_##KB3, KC_##KB4, KC_##KB5, KC_##KB6, KC_##KB7,    KC_NO, KC_##KB9 }, \
    { KC_##KC0, KC_##KC1, KC_##KC2, KC_##KC3, KC_##KC4, KC_##KC5, KC_##KC6, KC_##KC7, KC_##KC8, KC_##KC9 }, \
    { KC_##KD0, KC_##KD1, KC_##KD2, KC_##KD3, KC_##KD4, KC_##KD5, KC_##KD6, KC_##KD7,    KC_NO, KC_##KD9 }, \
    { KC_##KE0, KC_##KE1, KC_##KE2, KC_##KE3, KC_##KE4, KC_##KE5, KC_##KE6, KC_##KE7, KC_##KE8, KC_##KE9 }, \
    { KC_##KF0, KC_##KF1, KC_##KF2, KC_##KF3, KC_##KF4, KC_##KF5, KC_##KF6, KC_##KF7, KC_##KF8, KC_##KF9 }, \
    { KC_##KG0, KC_##KG1, KC_##KG2, KC_##KG3, KC_##KG4, KC_##KG5, KC_##KG6, KC_##KG7, KC_##KG8, KC_##KG9 }, \
    { KC_##KH0, KC_##KH1, KC_##KH2, KC_##KH3, KC_##KH4, KC_##KH5, KC_##KH6, KC_##KH7, KC_##KH8, KC_##KH9 }, \
    { KC_##KI0, KC_##KI1, KC_##KI2, KC_##KI3, KC_##KI4, KC_##KI5, KC_##KI6, KC_##KI7, KC_##KI8, KC_##KI9 }, \
    { KC_##KJ0, KC_##KJ1, KC_##KJ2, KC_##KJ3, KC_##KJ4, KC_##KJ5, KC_##KJ6, KC_##KJ7, KC_##KJ8, KC_##KJ9 }, \
    { KC_##KK0, KC_##KK1, KC_##KK2, KC_##KK3, KC_##KK4, KC_##KK5, KC_##KK6, KC_##KK7, KC_##KK8, KC_##KK9 }, \
    { KC_##KL0, KC_##KL1, KC_##KL2, KC_##KL3, KC_##KL4, KC_##KL5, KC_##KL6,    KC_NO, KC_##KL8, KC_##KL9 }, \
    { KC_##KM0, KC_##KM1, KC_##KM2, KC_##KM3, KC_##KM4, KC_##KM5,    KC_NO,    KC_NO,    KC_NO,    KC_NO }, \
    { KC_##KN0, KC_##KN1, KC_##KN2, KC_##KN3, KC_##KN4, KC_##KN5, KC_##KN6,    KC_NO,    KC_NO,    KC_NO }, \
    {    KC_NO, KC_##KP1, KC_##KP2, KC_##KP3, KC_##KP4, KC_##KP5, KC_##KP6, KC_##KP7, KC_##KP8, KC_##KP9 }, \
    { KC_##KQ0, KC_##KQ1, KC_##KQ2, KC_##KQ3, KC_##KQ4, KC_##KQ5, KC_##KQ6, KC_##KQ7, KC_##KQ8, KC_##KQ9 }  \
}



#endif
