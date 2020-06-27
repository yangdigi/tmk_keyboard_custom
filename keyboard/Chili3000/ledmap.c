#include <avr/pgmspace.h>
#include "ledmap.h"
#include "debug.h"


#ifdef LEDMAP_ENABLE

static const uint16_t ledmaps[LED_COUNT] PROGMEM = {
    [0] = LEDMAP_NUM_LOCK,                      // NUM_LOCK     - PB1
    [1] = LEDMAP_CAPS_LOCK,                     // CAPS_LOCK    - PB2
    [2] = LEDMAP_SCROLL_LOCK, //LEDMAP_LAYER(1) // SCROLL_LOCK  - PB3
    [3] = LEDMAP_BACKLIGHT,                     // BACKLIGHT    - PB7
};

ledmap_t ledmap_get_code(uint8_t index)
{
    return (ledmap_t) { .code = pgm_read_word(&ledmaps[index]) };
}

void ledmap_led_init(void)
{
    DDRB  |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
    PORTB |= (1<<PB7 | 1<<PB3 | 1<<PB2 | 1<<PB1);
}

void ledmap_led_on(uint8_t index)
{
    switch (index) {
        case 0:
            PORTB &= ~(1<<PB1);
            break;
        case 1:
            PORTB &= ~(1<<PB2);
            break;
        case 2:
            PORTB &= ~(1<<PB3);
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
            PORTB |=  (1<<PB1);
            break;
        case 1:
            PORTB |=  (1<<PB2);
            break;
        case 2:
            PORTB |=  (1<<PB3);
            break;
        case 3:
            PORTB |=  (1<<PB7);
            break;
    }
}

#endif