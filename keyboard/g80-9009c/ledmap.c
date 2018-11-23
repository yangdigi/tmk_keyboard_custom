#include <avr/pgmspace.h>
#include "ledmap.h"


#ifdef LEDMAP_ENABLE

static const uint16_t ledmaps[LED_COUNT] PROGMEM = {
    [0] = LEDMAP_CAPS_LOCK | LEDMAP_BACKLIGHT,   // LED L  - PC6
    [1] = LEDMAP_NUM_LOCK | LEDMAP_BACKLIGHT,       // PD3
    [2] = LEDMAP_SCROLL_LOCK | LEDMAP_BACKLIGHT,  //PD0
};

ledmap_t ledmap_get_code(uint8_t index)
{
    return (ledmap_t) { .code = pgm_read_word(&ledmaps[index]) };
}

void ledmap_led_init(void)
{
    DDRC  |=  (1<<PC6);
    PORTC |=  (1<<PC6);
    DDRD  |=  (1<<PD3);
    PORTD |=  (1<<PD3);
    DDRD  |=  (1<<PD0);
    PORTD |=  (1<<PD0);
}

void ledmap_led_on(uint8_t index)
{
    switch (index) {
        case 0:
            PORTC &= ~(1<<PC6);
            break;
        case 1:
            PORTD &= ~(1<<PD3);
            break;
        case 2:
            PORTD |=  (1<<PD0);
            break;
    }
}

void ledmap_led_off(uint8_t index)
{
    switch (index) {
        case 0:
            PORTC |= (1<<PC6);
            break;
        case 1:
            PORTD |=  (1<<PD3);
            break;
        case 2:
            PORTD |=  (1<<PD0);
            break;
    }
}

#endif
