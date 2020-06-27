/*
Copyright 2014 Kai Ryu <kai1103@gmail.com>

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

#include <avr/io.h>
#include "stdint.h"
#include "led.h"

#ifndef LEDMAP_ENABLE

/* LED pin configuration
 * NumLock:  PF1
 * CapsLock: PF0
 * ScrLock:  PE6
 */
void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // output low
        DDRF |= (1<<PF1);
        PORTF &= ~(1<<PF1);
    }
    else {
        // Hi-Z
        DDRF &= ~(1<<PF1);
        PORTF &= ~(1<<PF1);
    }
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRF |= (1<<PF0);
        PORTF &= ~(1<<PF0);
    }
    else {
        // Hi-Z
        DDRF &= ~(1<<PF0);
        PORTF &= ~(1<<PF0);
    }
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        // output low
        DDRE |= (1<<PE6);
        PORTE &= ~(1<<PE6);
    }
    else {
        // Hi-Z
        DDRE &= ~(1<<PE6);
        PORTE &= ~(1<<PE6);
    }
}

#endif
