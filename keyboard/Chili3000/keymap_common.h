/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "keymap_in_eeprom.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* keymap definition macro
 */
#define KEYMAP( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K069, K068, K067, K066, K065, K064, \
    K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, K079, K078, K077, K076, K075, K074,	K073, K072, K063, K062, K061, K060, \
    K020, K021, K022, K023, K024, K025, K026, K027, K028, K029, K089, K088, K087, K086, K085, K084, K083, K082, K081, K080, K070, \
    K030, K031, K032, K033, K034, K035, K036, K037, K038, K039, K099, K098, K097, K095, K092, K071, K090, \
    K040, K041, K042, K043, K044, K045, K046, K047, K048, K049, K109, K108, K107, K106, K096, K094, K093, K091, \
    K050, K051, K052, K053, K054, K055, K056, K057, K058, K059, K105, K104, K103, K102, K101, K100 \
) { \
    { KC_##K000, KC_##K001, KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, }, \
    { KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, KC_##K015, KC_##K016, KC_##K017, KC_##K018, KC_##K019, }, \
    { KC_##K020, KC_##K021, KC_##K022, KC_##K023, KC_##K024, KC_##K025, KC_##K026, KC_##K027, KC_##K028, KC_##K029, }, \
    { KC_##K030, KC_##K031, KC_##K032, KC_##K033, KC_##K034, KC_##K035, KC_##K036, KC_##K037, KC_##K038, KC_##K039, }, \
    { KC_##K040, KC_##K041, KC_##K042, KC_##K043, KC_##K044, KC_##K045, KC_##K046, KC_##K047, KC_##K048, KC_##K049, }, \
    { KC_##K050, KC_##K051, KC_##K052, KC_##K053, KC_##K054, KC_##K055, KC_##K056, KC_##K057, KC_##K058, KC_##K059, }, \
    { KC_##K060, KC_##K061, KC_##K062, KC_##K063, KC_##K064, KC_##K065, KC_##K066, KC_##K067, KC_##K068, KC_##K069, }, \
    { KC_##K070, KC_##K071, KC_##K072, KC_##K073, KC_##K074, KC_##K075, KC_##K076, KC_##K077, KC_##K078, KC_##K079, }, \
    { KC_##K080, KC_##K081, KC_##K082, KC_##K083, KC_##K084, KC_##K085, KC_##K086, KC_##K087, KC_##K088, KC_##K089, }, \
    { KC_##K090, KC_##K091, KC_##K092, KC_##K093, KC_##K094, KC_##K095, KC_##K096, KC_##K097, KC_##K098, KC_##K099, }, \
    { KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, }, \
}

#endif


