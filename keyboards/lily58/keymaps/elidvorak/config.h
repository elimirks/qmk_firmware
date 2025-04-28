// #ifndef CONFIG_USER_H
// #define CONFIG_USER_H
//
// #include "config_common.h"
//
// /* Use I2C or Serial, not both */
//
// #define USE_SERIAL
// // #define USE_I2C
//
// /* Select hand configuration */
//
// #define MASTER_LEFT
// // #define MASTER_RIGHT
// // #define EE_HANDS
//
// #undef RGBLED_NUM
// #define RGBLIGHT_ANIMATIONS
// #define RGBLED_NUM 14
// #define RGBLIGHT_HUE_STEP 16
// #define RGBLIGHT_SAT_STEP 16
// #define RGBLIGHT_VAL_STEP 16
// // Sleep lights when computer is off
// #define RGBLIGHT_SLEEP
//
// // Make mouse keys usable
// #define MOUSEKEY_DELAY 0
// #define MOUSEKEY_TIME_TO_MAX 20
// #define MOUSEKEY_MAX_SPEED 20
//
// #define TAPPING_TOGGLE 2
//
// // #define PREVENT_STUCK_MODIFIERS
//
// #endif



#pragma once

// Mod tap settings
#define QUICK_TAP_TERM 100
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2

#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_LED_COUNT 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

// Make mouse keys usable
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 8

#define PREVENT_STUCK_MODIFIERS
