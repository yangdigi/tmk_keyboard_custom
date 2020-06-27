
#include <avr/io.h>
#include "stdint.h"
#include "led.h"


#ifndef LEDMAP_ENABLE
void led_set(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        DDRB  |=  (1 << PB2);
        PORTB &= ~(1 << PB2);
    } else {
        DDRB  &= ~(1 << PB2);
        PORTB &= ~(1 << PB2);
    }
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB  |=  (1 << PB1);
        PORTB &= ~(1 << PB1);
    } else {
        DDRB  &= ~(1 << PB1);
        PORTB &= ~(1 << PB1);
    }
    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        DDRB  |=  (1 << PB0);
        PORTB &= ~(1 << PB0);
    } else {
        DDRB  &= ~(1 << PB0);
        PORTB &= ~(1 << PB0);
    }
}
#endif
