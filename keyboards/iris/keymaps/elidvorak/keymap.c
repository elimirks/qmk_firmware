#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _ALPHA 0
#define _SHIFT 1
#define _LOWER 2
#define _RAISE 4
#define _MOUSE 8

// Set to _ALPHA when no layer button is pressed
static uint8_t pressed_layer = _ALPHA;
static bool lock_is_pressed  = false;

enum custom_keycodes {
  ALPHA = SAFE_RANGE,
  SHIFT,
  LOWER,
  RAISE,
  MOUSE,
  LOCK, // For locking layers
  TOOA,
  EMAI,
  EARS,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define TRNS KC_TRNS
#define KC_ KC_TRNS
#define KC_LOWR LOWER
#define KC_SHFT SHIFT
#define KC_RASE RAISE
#define KC_MAU5 MOUSE
#define KC_LOCK LOCK
#define KC_TOOA TOOA
#define KC_EMAI EMAI
#define KC_EARS EARS
#define KC_SMC1 DYN_REC_START1
#define KC_PMC1 DYN_MACRO_PLAY1
#define KC_STMC DYN_REC_STOP

/* TODO
 * http://www.openstenoproject.org/ LEARN STENOGRAPHY
 */

// Referenc: https://docs.qmk.fm/keycodes.html
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,LOCK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,UNDS, Q  , J  , K  , X  ,MAU5,     RASE, B  , M  , W  , V ,  Z  ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,SHFT,SPC ,         LOWR,LCTL,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_SHIFT] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,TOOA,EMAI,EARS,    ,    ,                   ,    ,    ,SMC1,PMC1,STMC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,QUES,EXLM,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+---.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,SHFT,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,SCLN, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,PIPE,EQL ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LCBR,LABK,LPRN,LBRC,SLSH,               BSLS,RBRC,RPRN,RABK,RCBR,    ,
  //|----+----+----+----+----+----+---.    ,----|----+----+----+----+----+----|
         ,COLN,    ,PLUS,MINS,TILD,    ,         ,LEFT,DOWN, UP ,RGHT,GRV ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LSFT,SPC ,         LOWR,LCTL,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,HOME,PGUP,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               VOLU,    ,MSTP,    ,END ,PGDN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               VOLD,MPRV,MPLY,MNXT,    ,    ,
  //|----+----+----+----+----+----+---.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,     RASE,MUTE,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T  ,                   ,WH_L,WH_D,WH_U,WH_R,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, A  , S  , D  , F  , G  ,                   ,MS_L,MS_D,MS_U,MS_R,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       M , Z  , X  , C  , V  , B  ,MAU5,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,LSFT,    ,         BTN1,BTN2,BTN3
  //                  `----+----+----'        `----+----+----'
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void switch_to_layer(uint8_t layer, bool pressed) {
  if (pressed) {
    layer_on(layer);
    pressed_layer = layer;
  } else {
    if (!lock_is_pressed) {
      layer_off(layer);
      pressed_layer = _ALPHA;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
  case LOWER:
    switch_to_layer(_LOWER, record->event.pressed);
    return false;
  case RAISE:
    switch_to_layer(_RAISE, record->event.pressed);
    return false;
  case MOUSE:
    switch_to_layer(_MOUSE, record->event.pressed);
    return false;
  case SHIFT:
    switch_to_layer(_SHIFT, record->event.pressed);

    if (record->event.pressed) {
      register_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }

    return false;
  case LOCK:
    lock_is_pressed = record->event.pressed;
    return false;
  case TOOA:
    if (record->event.pressed) {
      SEND_STRING("Have you tried turning it off and on again?");
    }
    return false;
  case EMAI:
    if (record->event.pressed) {
      SEND_STRING("elimirks@gmail.com");
    }
    return false;
  case EARS:
    if (record->event.pressed) {
      SEND_STRING("Just rip its fucking ears off!");
    }
    return false;
  }
  return true;
}
