#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _ALPHA 0
#define _SHIFT 1
#define _LOWER 2
#define _RAISE 4
#define _MOUSE 8

enum custom_keycodes {
  ALPHA = SAFE_RANGE,
  SHIFT,
  TOOA,
  EMAI,
  EARS,
  FISH,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define TRNS KC_TRNS
#define KC_ KC_TRNS
#define KC_SHFT SHIFT
#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_MAU5 TT(_MOUSE)
#define KC_TOOA TOOA
#define KC_EMAI EMAI
#define KC_EARS EARS
#define KC_FISH FISH
#define KC_SMC1 DYN_REC_START1
#define KC_PMC1 DYN_MACRO_PLAY1
#define KC_STMC DYN_REC_STOP
#define KC_AL   LALT(KC_LEFT)
#define KC_AD   LALT(KC_DOWN)
#define KC_AU   LALT(KC_UP)
#define KC_AR   LALT(KC_RIGHT)

// Reference: https://docs.qmk.fm/keycodes.html
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
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
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,QUES,EXLM,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+---.     , ---|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,SHFT,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    , AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,PIPE,EQL ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LCBR,LABK,LPRN,LBRC,SLSH,               BSLS,RBRC,RPRN,RABK,RCBR,    ,
  //|----+----+----+----+----+----+---.     ,----|----+----+----+----+----+----|
         ,    ,TILD,PLUS,MINS,    ,    ,         ,    ,COLN,SCLN,GRV ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LSFT,SPC ,         LOWR,LCTL,LALT
  //                  `----+----+----'        `----+----+----'
  ),
  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,HOME,PGUP,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,SMC1,PMC1,STMC,    ,               VOLU,    ,MSTP,    ,END ,PGDN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TOOA,EMAI,EARS,FISH,    ,               VOLD,MPRV,MPLY,MNXT,    ,    ,
  //|----+----+----+----+----+----+---.     ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,     RASE,MUTE,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
  [_MOUSE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   , AL , AD , AU , AR ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T  ,                   ,LEFT,DOWN, UP ,RGHT,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, A  , S  , D  , F  , G  ,                   ,MS_L,MS_D,MS_U,MS_R,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       M , Z  , X  , C  , V  , B  ,MAU5,         ,    ,WH_L,WH_D,WH_U,WH_R,    ,
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
  } else {
    layer_off(layer);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (action_for_key(_SHIFT, record->event.key).code != ACTION_TRANSPARENT) {
    unregister_code(KC_LSFT);
  }

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
  case SHIFT:
    switch_to_layer(_SHIFT, record->event.pressed);

    if (record->event.pressed) {
      register_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }

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
  case FISH:
    if (record->event.pressed) {
      SEND_STRING("'~,.,~''~,.,~'  '~,.,~''~,.,~'");
      for (int i = 0; i < 15; i++) {
        SEND_STRING(SS_TAP(X_LEFT));
      }
    }
    return false;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
  rgblight_mode(1);

  // Should be at most 255 / 7 (~36)
  const unsigned int grad_magnitude = 30;

  // Left side
  for (unsigned int i = 0; i <= 6; i++) {
    unsigned int x = 6 - i;
    rgblight_setrgb_at(x * grad_magnitude, 255 - x * grad_magnitude, 0, i);
  }

  // Right side
  for (unsigned int i = 7; i <= 14; i++) {
    unsigned int x = i - 7;
    rgblight_setrgb_at(x * grad_magnitude, 0, 255 - x * grad_magnitude, i);
  }
}
