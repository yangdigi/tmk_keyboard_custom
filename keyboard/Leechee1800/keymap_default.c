#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-------------------------------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|           |Ins|Hom|PgU|Psc|
     * |---------------------------------------------------'    o o o  |---+---+---+---|
     * |                                                               |Del|End|PgD|Scr|
     * |-----------------------------------------------------------.   |---+---+---+---|
     * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | BS,BS2|   |Num| / | * |Pau|
     * |-----------------------------------------------------------|   |---+---+---+---|
     * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |   | 7 | 8 | 9 | - |
     * |-----------------------------------------------------------|   |---+---+---+---|
     * | Caps | A | S | D | F | G | H | J | K | L | ; | ' |  Enter |   | 4 | 5 | 6 | + |
     * |-----------------------------------------------------------'   |---+---+---+---|
     * | LS,LS2 | Z | X | C | V | B | N | M | , | . | / | RShift| ,---.| 1 | 2 | 3 |Ent|
     * |--------------------------------------------------------' | Up|`---+---+---+---|
     * |Ctrl| Gui| Alt| Fn |     Space   |Alt |Gui |App |Ctrl|,---+---+---.| 0 | . |E&T|
     * |------------------------------------------------------|Lef|Dow|Rig|------------|
     * `------------------------------------------------------`-----------'------------'
     */    
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           INS, HOME,PGUP,PSCR, \
                                                                                   DEL, END, PGDN,SLCK, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,1,   NLCK,PSLS,PAST,PAUS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     P7,  P8,  P9,  PMNS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,   ENT,        P4,  P5,  P6,  PPLS, \
        LSFT,2,   Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,  UP,     P1,  P2,  P3,  PENT, \
        LCTL,LGUI,LALT,FN0,          SPC,       RALT,RGUI,APP, RCTL,  LEFT,DOWN,RGHT,   P0,  PDOT    ),
    /* Keymap 1: Fn Layer
     * ,-------------------------------------------------------------------------------.
     * |FN4|   |   |   |   |   |   |   |   |   |   |   |   |           |   |   |   |   |
     * |---------------------------------------------------'    o o o  |---+---+---+---|
     * |                                                               |   |   |   |   |
     * |-----------------------------------------------------------.   |---+---+---+---|
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|   |---+---+---+---|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |   |   |   |   |
     * |-----------------------------------------------------------|   |---+---+---+---|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |   |   |   |   |
     * |-----------------------------------------------------------'   |---+---+---+---|
     * |        |FN2|FN1|FN3|   |   |   |   |   |   |   |       | ,---.|   |   |   |   |
     * |--------------------------------------------------------' |VOU|`---+---+---+---|
     * |    |    |    |    |             |    |    |    |    |,---+---+---.|   |   |   |
     * |------------------------------------------------------|MUT|VOD|   |------------|
     * `------------------------------------------------------`-----------'------------'
     */  
    KEYMAP(
        FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,TRNS, \
                                                                                   TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN6, TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,MS_U,FN10,TRNS,TRNS,TRNS,TRNS,TRNS,BTN1,BTN2,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,WH_U,WH_D,TRNS,TRNS,  TRNS,        TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,FN2, FN1, FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  VOLU,   TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,    TRNS,           TRNS,TRNS,TRNS,TRNS,  MUTE,VOLD,TRNS,   CALC,TRNS   ),
    /* Keymap 2: Fn_Lock Layer
     * ,-------------------------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |           |   |   |   |   |
     * |---------------------------------------------------'    o o o  |---+---+---+---|
     * |                                                               |   |   |   |   |
     * |-----------------------------------------------------------.   |---+---+---+---|
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     * |-----------------------------------------------------------|   |---+---+---+---|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |   |   |   |   |
     * |-----------------------------------------------------------|   |---+---+---+---|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |   |   |   |   |
     * |-----------------------------------------------------------'   |---+---+---+---|
     * |        |   |   |   |   |   |   |   |   |   |   |       | ,---.|   |   |   |   |
     * |--------------------------------------------------------' |   |`---+---+---+---|
     * |    |    |    |    |             |    |    |    |    |,---+---+---.|   |   |   |
     * |------------------------------------------------------|   |   |   |------------|
     * `------------------------------------------------------`-----------'------------'
     */ 
    KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,TRNS, \
                                                                                   TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,        TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,   TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,    TRNS,           TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,   TRNS,TRNS   ),
};

enum macro_id {
    MACRO_0,
    MACRO_1,
    MACRO_2,
    MACRO_3,
    MACRO_4,
    MACRO_5,
    MACRO_6,
    MACRO_7,
    MACRO_8,
    MACRO_9,
    MACRO_10,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case MACRO_0:
            return (event.pressed ?
                    MACRO( T(8), T(3), T(4), T(3), T(7), T(4), T(7), D(LSFT), T(2), U(LSFT), T(Q), T(Q), T(DOT), T(C), T(O), T(M), END ) :
                    MACRO( END ));
        case MACRO_1:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(1), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_2:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(2), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_3:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(3), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_4:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(4), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_5:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(5), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_6:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(6), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_7:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(7), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_8:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(8), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_9:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(9), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
        case MACRO_10:
            return (event.pressed ?
                    MACRO( D(LSFT), T(COMM), U(LSFT), T(1), T(0), D(LSFT), T(DOT), U(LSFT), END ) :
                    MACRO( END ));
    }
    return MACRO_NONE;
}

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(1),                       //  to Fn overlay
    [1] = ACTION_BACKLIGHT_TOGGLE(),                       //  BackLight TOGGLE
    [2] = ACTION_BACKLIGHT_DECREASE(),                     //  BackLight -
    [3] = ACTION_BACKLIGHT_INCREASE(),                     //  BackLight +
    [4] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC),      //  Task(RControl,RShift+Esc)
    [5] = ACTION_MACRO(MACRO_0),                           //  8343747@qq.com
    [6] = ACTION_MODS_KEY(MOD_RCTL|MOD_RALT, KC_DELETE),   //  ctrl+alt+del
    [7] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),               //  space fn
//    [7] = ACTION_LAYER_TOGGLE(2),                          //  Lay 2 TOGGLE
//    [6] = ACTION_DEFAULT_LAYER_SET(1),  // set colemak layout
//    [7] = ACTION_DEFAULT_LAYER_SET(2),  // set dvorak layout
//    [8] = ACTION_DEFAULT_LAYER_SET(3),  // set workman layout
    [11] = ACTION_MACRO(MACRO_1),                          //  <1>
    [12] = ACTION_MACRO(MACRO_2),                          //  <2>
    [13] = ACTION_MACRO(MACRO_3),                          //  <3>
    [14] = ACTION_MACRO(MACRO_4),                          //  <4>
    [15] = ACTION_MACRO(MACRO_5),                          //  <5>
    [16] = ACTION_MACRO(MACRO_6),                          //  <6>
    [17] = ACTION_MACRO(MACRO_7),                          //  <7>
    [18] = ACTION_MACRO(MACRO_8),                          //  <8>
    [19] = ACTION_MACRO(MACRO_9),                          //  <9>
    [20] = ACTION_MACRO(MACRO_10),                         //  <10>

    [21] = ACTION_KEY(KC_A),
    [22] = ACTION_KEY(KC_B),
    [23] = ACTION_KEY(KC_C),
    [24] = ACTION_KEY(KC_D),
    [25] = ACTION_KEY(KC_E),

};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
