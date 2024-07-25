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
#include "tapdances.h"

#define _QWERTY 0
#define _NUMB 1
#define _MOVE 2
#define _WHEEL 3
#define _TRACKBALL 4

#define MOVE MO(_MOVE)
#define NUMB MO(_NUMB)
#define TRACKBALL MO(_TRACKBALL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_left_ball(
    KC_ESC    , KC_1            , KC_2       , KC_3         , KC_4         , KC_5  ,                                                                                    KC_6          , KC_7          , KC_8             , KC_9                        , KC_0                      , KC_PSCR ,
    KC_INS    , KC_Q            , ALT_T(KC_W), CTL_T(KC_E)  , LSFT_T(KC_R) , KC_T  ,                                                                                    KC_Y          , RSFT_T(KC_U)  , RCTL_T(KC_I)     , LALT_T(KC_O)                , KC_P                      , _______ ,
    KC_DELETE , LT(_WHEEL,KC_A) , ALT_T(KC_S), LCMD_T(KC_D) , LSFT_T(KC_F) , KC_G  ,                                                                                    KC_H          , RSFT_T(KC_J)  , RCMD_T(KC_K)     , LALT_T(KC_L)                , TD(CT_MINUS_UNDSCR_EQUAL) , KC_GRAVE,
    _______   , KC_Z            , KC_X       , KC_C         , KC_V         , LT(MOVE,KC_B)    , TD(CT_LPRN_LBRC_LCBR_LTHAN) ,                 TD(CT_RPRN_RBRC_RCBR_GTHAN), LT(MOVE,KC_N) , KC_M          , TD(CT_COMM_SCLN) , TD(CT_DOT_CLN)              , TD(CT_SLSH_PIPE_BSLSH)    , _______ ,
    _______   , TD(CT_TMUX)                                                , LT(MOVE,KC_BSPC) , LT(NUMB,KC_TAB)             ,                 KC_ENT                     , KC_SPC        , OSM(MOD_RSFT) , TD(CT_TMUX)      , TD(CT_SQTE_DQTE_BQTE_CARET) ,  _______                  , _______
  ),

  [_NUMB] = LAYOUT_left_ball(
    KC_ESC  , _______  , _______      , _______      , _______      , TO(_QWERTY) ,                                         _______  , _______      , _______      , _______      , _______ , KC_F12    ,
    _______ , KC_F1    , KC_F2        , KC_F3        , KC_F4        , KC_F5       ,                                         KC_F6    , KC_F7        , KC_F8        , KC_F9        , KC_F10  , KC_F11    ,
    _______ , KC_1     , LALT_T(KC_2) , LCTL_T(KC_3) , LSFT_T(KC_4) , KC_5        ,                                         KC_6     , RSFT_T(KC_7) , RCTL_T(KC_8) , LALT_T(KC_9) , KC_0    , TD(CT_MINUS_UNDSCR_EQUAL) ,
    _______ , _______  , _______      , _______      , _______      , _______     , _______  ,                   _______  , _______  , _______      , _______      , _______      , _______ , _______                   ,
    _______ , _______                                               , _______     , _______  ,                   _______  , _______  , _______      , _______      , _______      , _______ , _______
  ),

  [_MOVE] = LAYOUT_left_ball(
    _______ , _______ , _______ , _______ , _______  , TO(_QWERTY) ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , KC_PGUP , KC_HOME , KC_UP   , KC_END   , KC_NO       ,                                 KC_PGUP , KC_HOME , KC_UP   , KC_END  , KC_NO   , _______ ,
    _______ , KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT , KC_NO       ,                                 KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT, KC_NO   , _______ ,
    _______ , _______ , _______ , _______ , _______  , _______     , _______ ,            _______  , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______                                , _______     , _______ ,            _______  , _______ , _______ , _______ , _______ , _______ , _______
  ),

  [_WHEEL] = LAYOUT_left_ball(
    RGB_TOG , _______ , _______ , _______ , _______ , TO(_QWERTY) ,                                        _______ , _______ , _______ , _______ , _______ , _______ ,
    RGB_MOD , KC_NO   , KC_NO   , KC_WH_U , KC_NO   , KC_NO       ,                                        KC_NO   , KC_NO   , KC_WH_U , KC_NO   , KC_NO   , _______ ,
    _______ , KC_NO   , KC_WH_L , KC_WH_D , KC_WH_R , KC_NO       ,                                        KC_NO   , KC_WH_L , KC_WH_D , KC_WH_R , KC_NO   , _______ ,
    _______ , KC_NO   , KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3     , _______  ,                   _______ , KC_NO   , KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ ,
    _______ , _______                               , _______     , _______  ,                   _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),

  [_TRACKBALL] = LAYOUT_left_ball(
    RGB_TOG , _______ , _______ , _______ , _______ , TO(_QWERTY) ,                                        _______ , _______ , _______ , _______ , _______ , _______ ,
    RGB_MOD , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO       ,                                        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
    _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO       ,                                        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
    _______ , KC_BTN3 , KC_BTN2 , KC_BTN1 , KC_NO   , KC_NO       , _______  ,                   _______ , KC_NO   , KC_NO   , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ ,
    _______ , _______                               , _______     , _______  ,                   _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
};
// clang-format on


// const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 70, HSV_WHITE}
// );

// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, HSV_BLUE}
// );

// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {10, 1, HSV_GREEN}
// );

// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {20, 1, HSV_RED}
// );


// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_layer0_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _NUMB));
//     rgblight_set_layer_state(2, layer_state_cmp(state, _MOVE));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _TRACKBALL));
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    // keyball_set_scroll_mode(get_highest_layer(state) == 6);

  switch(biton32(state)) {
    case _MOVE:
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case _NUMB:
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case _WHEEL:
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      break;
    case _TRACKBALL:
      rgblight_enable_noeeprom();	
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
    default:
      rgblight_sethsv_noeeprom(HSV_WHITE);
      break;
  }

    return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

/*
LEDs

Left
x  x x  x x x
x  x x  x x x
x  x x  x x x
10 x 20 x x x x
x x       x x

Left under
x x x
x x 1 0

Right
  1 x x  x x  x
  x x 10 x 20 x
  x x x  x x  x
1 x x x  x x  x
x x x x  x x  x

Right under
x x x
x x x x
*/