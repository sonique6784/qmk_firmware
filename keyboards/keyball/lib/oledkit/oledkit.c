/*
Copyright 2021 @Yowkees
Copyright 2021 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

#if defined(OLED_ENABLE) && !defined(OLEDKIT_DISABLE)

__attribute__((weak)) void oledkit_render_logo_user(void) {
    // Snake animation revealing the Keyball logo
    // Requires font characters 0xC4-0xC7 in logofont.c
    static uint16_t anim_start = 0;
    static bool     anim_done  = false;

    // Head column per frame (-1 = off-screen)
    static const int8_t head_cols[10] = {
        2, 4, 6, 8, 10, 12, 14, 15, 16, 20
    };

    const uint16_t FRAME_MS = 150;

    if (!anim_done) {
        if (anim_start == 0) anim_start = timer_read();

        uint8_t frame = timer_elapsed(anim_start) / FRAME_MS;
        if (frame > 9) { frame = 9; anim_done = true; }

        int8_t hc = head_cols[frame];
        int8_t tc = hc - 4;

        for (int y = 0; y < 3; y++) {
            oled_write_P(PSTR("  "), false);
            for (int x = 0; x < 16; x++) {
                uint8_t ch;
                bool in_snake = (x >= tc && x <= hc && x >= 0 && x <= 15);

                if (in_snake) {
                    if (x == hc && hc <= 15)
                        ch = 0xC4;
                    else if (x == tc && tc >= 0)
                        ch = 0xC7;
                    else
                        ch = ((hc - x) & 1) ? 0xC5 : 0xC6;
                } else if (x < tc || hc < 0) {
                    ch = 0x80 + y * 16 + x;
                } else {
                    ch = 0x7F;
                }
                oled_write_char(ch, false);
            }
            oled_advance_page(false);
        }
        return;
    }

    char ch = 0x80;
    for (int y = 0; y < 3; y++) {
        oled_write_P(PSTR("  "), false);
        for (int x = 0; x < 16; x++) {
            oled_write_char(ch++, false);
        }
        oled_advance_page(false);
    }
}

__attribute__((weak)) void oledkit_render_info_user(void) {
    oledkit_render_logo_user();
}

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oledkit_render_info_user();
    } else {
        oledkit_render_logo_user();
    }
    return true;
}

__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // Logo needs to be rotated 180 degrees.
    //
    // A typical OLED has a narrow margin on the left side near the origin, and
    // a wide margin on the right side. The Keyball logo consists of three
    // lines. If the logo is displayed on an OLED consisting of four lines, the
    // margin on the right side will be too large and the balance is not good.
    //
    // Additionally, by rotating it, the left side of the logo will be above
    // the OLED screen, giving it a natural look.
    return !is_keyboard_master() ? OLED_ROTATION_180 : rotation;
}

#endif // OLED_ENABLE
