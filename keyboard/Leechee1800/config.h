
#ifndef CONFIG_H
#define CONFIG_H


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gacathon
#define PRODUCT         LEECHEE 1800 KeyBoard
#define DESCRIPTION     t.m.k. keyboard firmware for 1800

/* key matrix size */
#define MATRIX_ROWS 11
#define MATRIX_COLS 10

/* keymap in eeprom */
#define FN_ACTIONS_COUNT 32
#define KEYMAPS_COUNT 8
#define EECONFIG_KEYMAP_IN_EEPROM 0x11

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* number of backlight levels */
#ifdef BREATHING_LED_ENABLE
//#ifdef FADING_LED_ENABLE
#define BACKLIGHT_LEVELS 8
#else
/*#define BACKLIGHT_LEVELS 6
#endif
#else*/
#define BACKLIGHT_LEVELS 3
#endif

/* enable customized backlight logic */
/*#define BACKLIGHT_CUSTOM
#define RGB_LED_ENABLE
#define CUSTOM_LED_ENABLE
#define SOFTPWM_LED_FREQ 80*/

/* number of leds */
#define LED_COUNT 4

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
