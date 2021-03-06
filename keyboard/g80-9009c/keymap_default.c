#include "keymap_common.h"
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer*/
    KEYMAP(
                                                                                                   VOLD,VOLU,     F1,  F2,  F3,  F4, \
         ESC,                                                                                        MUTE,        F5,  F6,  F7,  F8, \
         ESC,   ESC,    F1,  F2,  F3,  F4,    F5,  F6,  F7,  F8,     F9,  F10,  F11,  F12,       PSCR,  PAUS,     F9, F10, F11, F12, \
         ESC,   ESC,    F1,  F2,  F3,  F4,    F5,  F6,  F7,  F8,     F9,  F10,  F11,  F12,    PSCR,SLCK,PAUS,       VOLD,    VOLU,   \
        F1,F2,  GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,     BSPC,    INS, HOME,PGUP,   NLCK,PSLS,PAST,PMNS, \
        F3,F4,  TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,  ENT,     DEL, END, PGDN,     P7,  P8,  P9,PPLS, \
        F5,F6,  CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,                              P4,  P5,  P6,      \
        F7,F8,  LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,               UP,          P1,  P2,  P3,PENT, \
        F9,F10, LCTL,  LGUI,LALT,          SPC,                        RALT,RGUI,  RCTL,      LEFT,DOWN,RGHT,     P0,       PDOT     ),


};
/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    /* Default Layout */
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
