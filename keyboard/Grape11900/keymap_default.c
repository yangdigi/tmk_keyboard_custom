#include "keymap_common.h"

// Default
#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[KEYMAPS_COUNT][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Keymap 0: Default Layer
     * ,--------------------------------------------------------------------------------.
     * |ESC|  |F1 |F2 |F3 |F4 |F5 |F6 |  |Ins|Hom|PgU|Psc|  |Pau| o o o |Num| / | * | - |
     * |---'  |-----------------------|  |---------------|  `---'       |---+---+---+---|
     * |      |F7 |F8 |F9 |F10|F11|F12|  |Del|End|PgD|Scr|              | 7 | 8 | 9 | + |
     * |      `-----------------------'  `---------------'              |---+---+---+---|
     * |                                                                | 4 | 5 | 6 |+++|
     * |-----------------------------------------------------------.    |---+---+---+---|
     * | ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | BS,BS2|    | 1 | 2 | 3 |Ent|
     * |-----------------------------------------------------------|    |---+---+---+---|
     * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |    | 0 |000| . |E&T|
     * |-----------------------------------------------------------|    `---------------|
     * | Caps | A | S | D | F | G | H | J | K | L | ; | ' |  Enter |        |FN |FN |FN |
     * |----------------------------------------------------------,---.     |---+---+---|
     * | LS,LS2 | Z | X | C | V | B | N | M | , | . | / | RS,RS2 ||Up |	    |FN |FN |FN |
     * |------------------------------------------------------,---+---+---. |---+---+---|
     * |Ctrl| Gui| Alt|   Fn   |  Space  |Alt |Gui |App |Ctrl||Lef|Dow|Rig| | BTN1|BTN2 |
     * `------------------------------------------------------`-----------'-`-----------'
     */

    KEYMAP(
        ESC,    F1,  F2,  F3,  F4,  F5,  F6,     INS, HOME,PGUP,PSCR,    FN0,               NLCK,PSLS,PAST,PMNS,\
		        F7,  F8,  F9,  F10, F11, F12,    DEL, END, PGDN,SLCK,                       P7,  P8,  P9,  PPLS,\
                                                                                            P4,  P5,  P6,  PPLS,\
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,BSPC,         P1,  P2,  P3,  PENT,\
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,              P0,  P0,  PDOT,PENT,\
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                    1,   2,   3,   \
        LSFT,LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,RSFT,      UP,          4,   5,   6,   \
        LCTL,LGUI,LALT,      SPC,     SPC,      RALT,RGUI,APP, RCTL,           LEFT,DOWN,RGHT,   BTN1,BTN2    ),
    /* Keymap 1: Fn Layer
     * ,--------------------------------------------------------------------------------.
     * |FN4|  |   |   |   |   |   |   |  |   |   |   |   |  |FN0| o o o |CAL|   |   |   |
     * |---'  |-----------------------|  |---------------|  `---'       |---+---+---+---|
     * |      |   |   |   |   |   |   |  |FN5|   |   |   |              |   |   |   |   |
     * |      `-----------------------'  `---------------'              |---+---+---+---|
     * |                                                                |   |   |   |   |
     * |-----------------------------------------------------------.    |---+---+---+---|
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |   |   |   |   |
     * |-----------------------------------------------------------|    |---+---+---+---|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |   |   |   |   |
     * |-----------------------------------------------------------|    `---------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |        |   |   |   |
     * |----------------------------------------------------------,---.     |---+---+---|
     * |        |BL<|BL |BL>|   |   |   |   |   |   |   |        ||VOU|	    |   |   |   |
     * |------------------------------------------------------,---+---+---. |---+---+---|
     * |    |    |    |        |         |    |    |    |    ||MUT|VOD|   | |     |     |
     * `------------------------------------------------------`-----------'-`-----------'
     */

    KEYMAP(
        FN4,    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,    TRNS,              CALC,TRNS,TRNS,TRNS,\
		        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   FN5, TRNS,TRNS,TRNS,                       TRNS,TRNS,TRNS,TRNS,\
                                                                                            TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,              TRNS,TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,                   TRNS,TRNS,TRNS,\
        TRNS,TRNS,FN2, FN1, FN3, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      VOLU,        TRNS,TRNS,TRNS,\
        TRNS,TRNS,TRNS,     TRNS,     TRNS,     TRNS,TRNS,TRNS,TRNS,           MUTE,VOLD,TRNS,   TRNS,TRNS    ),
};
/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[FN_ACTIONS_COUNT] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif

//    [0] = ACTION_LAYER_MOMENTARY(1),                       // to Fn overlay
    [0] = ACTION_LAYER_TAP_KEY(1, KC_PAUSE),               // Hold PAUSE to FN Layer
    [1] = ACTION_BACKLIGHT_TOGGLE(),                       // Backlight Toggle
    [2] = ACTION_BACKLIGHT_DECREASE(),                     // Backlight -
    [3] = ACTION_BACKLIGHT_INCREASE(),                     // Backlight +
    [4] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC),      // Task(RControl,RShift+Esc)
    [5] = ACTION_MODS_KEY(MOD_RCTL | MOD_RALT, KC_DELETE), // RControl+RALT+DEL
    [6] = ACTION_LAYER_TOGGLE(2),                          // toggle lay2 overlay
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif

/*
 * Action macro definition
 */
enum macro_id {
    KEYPAD_00 = 0,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case KEYPAD_00:
            return (record->event.pressed ?
                    MACRO( T(P0), T(P0), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
