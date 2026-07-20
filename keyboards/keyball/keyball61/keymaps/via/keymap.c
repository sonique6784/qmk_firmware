/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC        , KC_1      , KC_2    , KC_3      , KC_4     , KC_5     ,                                        KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_GRAVE      , KC_Q      , KC_W    , KC_E      , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_EQL  ,
    LSFT_T(KC_TAB), KC_A      , KC_S    , KC_D      , LT(1,KC_F)     , LT(2,KC_G),                                       KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT       , KC_Z      , KC_X    , KC_C      , KC_V     , KC_B     , KC_LBRC  ,                   KC_RBRC,  LT(1,KC_N), KC_M    , KC_COMM  , KC_DOT   , KC_SLSH  , RSFT_T(KC_BSLS)  ,
    SCRL_MO       , KC_LCTL  , _______  , KC_LCTL   , KC_LALT,KC_LGUI,LSFT_T(KC_SPACE),                        RSFT_T(KC_ENT),KC_BSPC,LT(1,KC_LNG2),KC_RGUI, _______ , KC_LEFT  , KC_RGHT
  ),



  [1] = LAYOUT_universal(
    SSNP_FRE , _______  , _______ , _______  , _______  , _______  ,                                  KC_VOLD  , KC_VOLU  , _______  , _______  , _______  , _______  ,
    SSNP_VRT , _______  , _______ , _______  , _______  , _______  ,                                  KC_PGUP  , _______  , KC_UP    , _______  , _______  , _______  ,
    SSNP_HOR , _______  , _______ , _______  , _______  , _______ ,                                  KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , _______  , _______ , _______  , _______  , _______ , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______ , _______  , _______  , _______  , _______  ,             _______  , _______  , _______  , _______  , _______  , KC_MPRV  , KC_MNXT
  ),

  [2] = LAYOUT_universal(
    UG_TOGG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    UG_NEXT  , UG_HUEU  , UG_SATU  , UG_VALU  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    UG_PREV  , UG_HUED  , UG_SATD  , UG_VALD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  ),

  [3] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______  ,                                  _______  , MS_BTN1  , _______  , MS_BTN2  , MS_BTN3 , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , _______   ,            _______   , _______  , _______  , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______    , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______ , _______ , _______  , _______ , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , _______   ,            _______   , _______  , _______  , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______    , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______ , _______ , _______  , _______ , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , _______   ,            _______   , _______  , _______  , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______    , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______ , _______ , _______  , _______ , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , _______   ,            _______   , _______  , _______  , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______    , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [7] = LAYOUT_universal(
    _______  , _______   , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______ , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    _______ , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______ , _______ , _______  , _______ , _______  ,
    _______  , _______  , _______ , _______ , _______  , _______  , _______   ,            _______   , _______  , _______  , _______  , _______   , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______    , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is ENABLE_AUTO_SCROLL_LAYER
    keyball_set_scroll_mode(get_highest_layer(state) == ENABLE_AUTO_SCROLL_LAYER);
    return state;
}


void pointing_device_init_user(void) {
    set_auto_mouse_layer(3);
    set_auto_mouse_enable(true); // Required to activate the feature
}


#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
