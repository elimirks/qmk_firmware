#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _ALPHA 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 4

// Set to _ALPHA when no layer button is pressed
static uint8_t pressed_layer = _ALPHA;
static bool lock_is_pressed  = false;

enum custom_keycodes {
  ALPHA = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  LOCK, // For locking layers
};

#define TRNS KC_TRNS
#define KC_ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MAU5 MOUSE
#define KC_LOCK LOCK

/* TODO
 * https://docs.qmk.fm/feature_mouse_keys.html
 * http://www.openstenoproject.org/ LEARN STENOGRAPHY
 */

// Referenc: https://docs.qmk.fm/keycodes.html
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,RASE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,QUOT,PPLS,PMNS, P  , Y  ,                F  , G  , C  , R  , L  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MAU5,UNDS, Q  , J  , K  , X  ,RASE,     LOCK, B  , M  , W  , V ,  Z  ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LSFT,SPC ,         LOWR,LCTL,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    , AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,PIPE,EQL ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     COLN,LCBR,LABK,LPRN,LBRC,SLSH,               BSLS,RBRC,RPRN,RABK,RCBR,SCLN,
  //|----+----+----+----+----+----+---.    ,----|----+----+----+----+----+----|
         ,EXLM,COMM,DOT ,QUES,TILD,    ,     LOCK,LEFT,DOWN, UP ,RGHT,GRV ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LSFT,SPC ,         LOWR,LCTL,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               VOLU,    ,MSTP,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               VOLD,MPRV,MPLY,MNXT,    ,    ,
  //|----+----+----+----+----+----+---.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,RASE,         ,MUTE,    ,    ,    ,    ,    ,
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
     MAU5, Z  , X  , C  , V  , B  , M  ,     LOCK,    ,    ,    ,    ,    ,    ,
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
  case LOCK:
    lock_is_pressed = record->event.pressed;
    return false;
  }
  return true;
}
