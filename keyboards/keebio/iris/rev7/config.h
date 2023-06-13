/*
Copyright 2021 Danny Nguyen <danny@keeb.io>

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

#define SPLIT_HAND_PIN D5


/* ws2812 RGB LED */
#    define RGBLED_NUM 68
#    define RGBLED_SPLIT { 34, 34 }
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 120 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP         /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*    == enabled animations ==
      == Multiple animations have been disabled in order to both save space and limit the number of
         keypresses required in order to get to desired settings
         space saved by disabling below animations = 
*/
#    define RGBLIGHT_EFFECT_BREATHING
// #    define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #    define RGBLIGHT_EFFECT_SNAKE
// #    define RGBLIGHT_EFFECT_KNIGHT
// #    define RGBLIGHT_EFFECT_CHRISTMAS
// #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #    define RGBLIGHT_EFFECT_RGB_TEST
// #    define RGBLIGHT_EFFECT_ALTERNATING
// #    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_DEFAULT_VAL 90
#    define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_BREATHING + 1)
// RGB Matrix
// #    ifdef RGB_MATRIX_ENABLE
// #        define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #        define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #        define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        define ENABLE_RGB_MATRIX_BREATHING
// #        define ENABLE_RGB_MATRIX_BAND_SAT
#        define ENABLE_RGB_MATRIX_BAND_VAL
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #        define ENABLE_RGB_MATRIX_CYCLE_ALL
// #        define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #        define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #        define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #        define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #        define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #        define ENABLE_RGB_MATRIX_DUAL_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#        define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#        define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#        define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #        define ENABLE_RGB_MATRIX_SPLASH
// #        define ENABLE_RGB_MATRIX_MULTISPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#        define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#        define RGB_MATRIX_DEFAULT_VAL 90
#        define RGB_MATRIX_DEFAULT_HUE 190
#        define RGB_MATRIX_DEFAULT_SAT 255
#        define RGB_MATRIX_DEFAULT_SPD 120
#        define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_VAL
#        define RGB_MATRIX_LED_COUNT RGBLED_NUM
#        define RGB_MATRIX_SPLIT { 34, 34 }
#        define RGB_DISABLE_WHEN_USB_SUSPENDED
#        define RGB_MATRIX_KEYPRESSES

// defines the length of the tapping term, in MS
// #define QUICK_TAP_TERM 175

// when a user holds a key after tapping it, will now activate hold function instead of (default) auto-repeating the tapping function
// this is on a per-key basis, defined in keymap
#define QUICK_TAP_TERM_PER_KEY

// inputs Layertoggle keypress on keypress instead of waiting for TAPPING_TERM delay
// #define HOLD_ON_OTHER_KEY_PRESS

// Sets the length of the tapping term, in MS
#define TAPPING_TERM 123

// Enables override of tapping term on a per-key basis
#define TAPPING_TERM_PER_KEY

// Changes tap / hold decision to interpret as a hold when a mod is pressed, then second key is pressed and released before tapping term
#define PERMISSIVE_HOLD

// increased layers from 4 to 6
#define DYNAMIC_KEYMAP_LAYER_COUNT 6