#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0 
     * ,-----------------------------------------------------------------------.
     * |Esc|   | F1| F2| F3| F4| | F5| F6| F7| F8| | F9|F10|F11|F12|Psc|Slk|Pau|   o   o   o
     * |-----------------------------------------------------------+---+---+---+---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins|Hom|PgU|Num|  /|  *|  -|
     * |-----------------------------------------------------------+---+---+---+---+---+---+---|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del|End|PgD|  7|  8|  9|   |
     * |-----------------------------------------------------------+-----------+---+---+---+ + |
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |           |  4|  5|  6|   |
     * |-----------------------------------------------------------|   ,---.   |---+---+---+---|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |   |Up |   |  1|  2|  3|   |
     * |-----------------------------------------------------------+---+---+---+---+---+---+Ent|
     * |Ctrl|Gui |Alt |    Fn0    |    Space   |Alt |Gui |APP |Ctrl|Lef|Dow|Rig|   0   | . |   |
     * `-----------------------------------------------------------------------'---------------'
     */
    KEYMAP(
        ESC,      F1,  F2,  F3,  F4,    F5,  F6,  F7,  F8,     F9,  F10, F11, F12, PSCR,SLCK,PAUS,                     \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,BSPC,INS, HOME,PGUP,NLCK,PSLS,PAST,PMNS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,DEL, END, PGDN,P7,  P8,  P9,  PPLS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,          ENT,                P4,  P5,  P6,  PPLS, \
        LSFT,LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     RSFT,     UP,       P1,  P2,  P3,        \
        LCTL,LGUI,LALT,          FN0,           SPC,           RALT,RGUI,FN7, RCTL,LEFT,DOWN,RGHT,P0,  P0,  PDOT,PENT  ),
    /* layer 1 */
    KEYMAP(
        FN4,      TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                     \
        TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTN1,BTN2,     TRNS,FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_U,WH_D,          TRNS,               TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,FN2, FN1, FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     VOLU,     TRNS,TRNS,TRNS,      \
        TRNS,TRNS,TRNS,          TRNS,          TRNS,          TRNS,MYCM,TRNS,TRNS,MUTE,VOLD,TRNS,CALC,FN6, TRNS,TRNS  ),
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
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case MACRO_0:
            return (event.pressed ?
                    MACRO( T(P0), T(P0), END ) :
                    MACRO( END ));
        case MACRO_1:
            return (event.pressed ?
                    MACRO( T(8), T(3), T(4), T(3), T(7), T(4), T(7), D(LSFT), T(2), U(LSFT), T(Q), T(Q), T(DOT), T(C), T(O), T(M), END ) :
                    MACRO( END ));
        case MACRO_2:
            return (event.pressed ?
                    MACRO( END ) :
                    MACRO( END ));
        case MACRO_3:
            return (event.pressed ?
                    MACRO( END ) :
                    MACRO( END ));
        case MACRO_4:
            return (event.pressed ?
                    MACRO( END ) :
                    MACRO( END ));
        case MACRO_5:
            return (event.pressed ?
                    MACRO( END ) :
                    MACRO( END ));
        case MACRO_6:
            return (event.pressed ?
                    MACRO( END ) :
                    MACRO( END ));
        case MACRO_7:
            return (event.pressed ?
                    MACRO( END ) :
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
    [5] = ACTION_MODS_KEY(MOD_RCTL|MOD_RALT, KC_DELETE),   //  RControl+RAlt+Del
    [6] = ACTION_MACRO(MACRO_0),                           //  00
    [7] = ACTION_LAYER_TAP_KEY(1, KC_APP),                 //  KC_* in ..\doc\keycode.txt
//    [7] = ACTION_LAYER_TOGGLE(2),       //  Lay 2 TOGGLE
//    [6] = ACTION_DEFAULT_LAYER_SET(1),  //  set colemak layout
//    [7] = ACTION_DEFAULT_LAYER_SET(2),  //  set dvorak layout
//    [8] = ACTION_DEFAULT_LAYER_SET(3),  //  set workman layout


};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
