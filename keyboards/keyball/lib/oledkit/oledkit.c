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

// Defined in logofont.c — 30 frames × 288 bytes each in PROGMEM.
#define ANIM_FRAME_COUNT 30
#define ANIM_FRAME_SIZE  288
extern const uint8_t anim_frames[][ANIM_FRAME_SIZE] PROGMEM;

__attribute__((weak)) void oledkit_render_logo_user(void) {
    // Frame-by-frame animation of the Keyball logo.
    // Each frame is a raw 3-page bitmap (288 bytes) stored in PROGMEM.
    // anim_frames[0] is blank, anim_frames[ANIM_FRAME_COUNT-1] is the
    // final logo.  After the last frame, the logo stays visible.
    static uint16_t anim_start;
    static uint8_t  rendered_frame = ANIM_FRAME_COUNT;
    static bool     anim_started;

    const uint16_t FRAME_MS = 150;

    if (!anim_started) {
        anim_start   = timer_read();
        anim_started = true;
    }

    uint8_t frame = timer_elapsed(anim_start) / FRAME_MS;
    if (frame >= ANIM_FRAME_COUNT) {
        frame = ANIM_FRAME_COUNT - 1;
    }

    // oled_task_user() runs every OLED update interval.  Skip both the flash
    // reads and buffer comparisons until it is time to show a new frame.
    if (frame == rendered_frame) {
        return;
    }

    const uint8_t *p = anim_frames[frame];
    for (int page = 0; page < 3; page++) {
        oled_set_cursor(2, page);
        oled_write_raw_P((const char *)(p + page * 96), 96);
    }

    rendered_frame = frame;
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
