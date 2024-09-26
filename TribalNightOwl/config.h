/*
This is the c configuration file for the keymap

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

#pragma once

#undef  RGBLIGHT_DEFAULT_MODE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_LAYERS

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 4

#define KEYBALL_SCROLLSNAP_ENABLE SSNP_FRE

#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef  TAPPING_TERM
#define TAPPING_TERM 200

#undef  DEBOUNCE
#define DEBOUNCE 5

#undef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 9