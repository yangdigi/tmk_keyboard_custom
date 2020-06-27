#include <avr/pgmspace.h>
#include "ledmap.h"
#include "debug.h"


#ifdef LEDMAP_ENABLE

static const uint16_t ledmaps[LED_COUNT] PROGMEM = {
    [0] = LEDMAP_NUM_LOCK,                      // LEDMAP_NUM_LOCK     - PB2
    [1] = LEDMAP_CAPS_LOCK,                     // LEDMAP_CAPS_LOCK    - PB1
    [2] = LEDMAP_LAYER(1),            //lay1    // LEDMAP_SCROLL_LOCK  - PB0
    [3] = LEDMAP_BACKLIGHT,                     // BL                  - PB7
};

ledmap_t ledmap_get_code(uint8_t index)
{
    return (ledmap_t) { .code = pgm_read_word(&ledmaps[index]) };
}

void ledmap_led_init(void)
{
    DDRB  |= (1<<PB7 | 1<<PB2 | 1<<PB1 | 1<<PB0);
    PORTB |= (1<<PB7 | 1<<PB2 | 1<<PB1 | 1<<PB0);
}

void ledmap_led_on(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB &= ~(1<<PB2);
            break;
        case 1:
            PORTB &= ~(1<<PB1);
            break;
        case 2:
            PORTB &= ~(1<<PB0);
            break;
        case 3:
            PORTB &= ~(1<<PB7);
            break;
    }
}

void ledmap_led_off(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB |=  (1<<PB2);
            break;
        case 1:
            PORTB |=  (1<<PB1);
            break;
        case 2:
            PORTB |=  (1<<PB0);
            break;
        case 3:
            PORTB |=  (1<<PB7);
            break;
    }
}

#endif