#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

uint8_t underglow_enabled = 1;
//uint8_t vbox_mediakeys_enabled = 0;
// FIXME: default for testing
uint8_t vbox_mediakeys_enabled = 0;

#define SS_DOWN_MEH() SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI)
#define SS_UP_MEH() SS_UP(X_LCTRL)SS_UP(X_LALT)SS_UP(X_LGUI)
#define SS_MEH(kc) SS_DOWN_MEH()SS_TAP(kc)SS_UP_MEH()

#define KC_CAD LALT(LCTL(KC_DEL))

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
  TRGB, // Toggle RGB underglow
  TVBX, // Toggle VirtualBox media keys
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
#define KC_TRGB TRGB
#define KC_TVBX TVBX
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
     RCTL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,CAD ,
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
     TRGB,TVBX,    ,    ,    ,    ,                   ,    ,    ,INS ,HOME,PGUP,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,SMC1,PMC1,STMC,    ,               VOLU,    ,MSTP,DEL ,END ,PGDN,
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
     LGUI,    ,    ,    ,    ,    ,                   , AL , AD , AU , AR ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T  ,                   ,LEFT,DOWN, UP ,RGHT,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, A  , S  , D  , F  , G  ,                   ,MS_L,MS_D,MS_U,MS_R,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       M , Z  , X  , C  , V  , B  ,MAU5,         ,    ,WH_L,WH_D,WH_U,WH_R,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LSFT,    ,         BTN1,BTN2,BTN3
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
  case TRGB:
    if (record->event.pressed) {
      underglow_enabled = ! underglow_enabled;
    }
    return false;
  case TVBX:
    if (record->event.pressed) {
      vbox_mediakeys_enabled = ! vbox_mediakeys_enabled;
    }
    return false;
  // Intercept media keys for VirtualBox
  case KC_MPLY:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_A));
      return false;
    }
    break;
  case KC_MSTP:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_B));
      return false;
    }
    break;
  case KC_MNXT:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_C));
      return false;
    }
    break;
  case KC_MPRV:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_D));
      return false;
    }
    break;
  case KC_VOLU:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_E));
      return false;
    }
    break;
  case KC_VOLD:
    if (record->event.pressed && vbox_mediakeys_enabled) {
      SEND_STRING(SS_MEH(X_F));
      return false;
    }
    break;
  }
  return true;
}

void led_set_grad_left_green(void) {
  // Should be at most 255 / 7 (~36)
  const unsigned int grad_magnitude = 30;

  // Left side
  for (unsigned int i = 0; i <= 6; i++) {
    unsigned int x = 6 - i;
    rgblight_setrgb_at(x * grad_magnitude, 255 - x * grad_magnitude, 0, i);
  }
}

void disable_underglow(void) {
    for (unsigned int i = 0; i <= 14; i++) {
      rgblight_setrgb_at(0, 0, 0, i);
    }
}

void led_set_user(uint8_t usb_led) {
  // Constant values - no pulsing or anything
  rgblight_mode(1);

  if ( ! underglow_enabled) {
    disable_underglow();
    return;
  }

  if (IS_LAYER_ON(_MOUSE)) {
    led_set_grad_left_green();

    // Should be at most 255 / 7 (~36)
    const unsigned int grad_magnitude = 30;

    // Right side
    for (unsigned int i = 7; i <= 13; i++) {
      unsigned int x = i - 7;
      rgblight_setrgb_at(x * grad_magnitude, 255 - x * grad_magnitude, 0, i);
    }
  } else {
    led_set_grad_left_green();

    // Should be at most 255 / 7 (~36)
    const unsigned int grad_magnitude = 30;

    // Right side
    for (unsigned int i = 7; i <= 13; i++) {
      unsigned int x = i - 7;
      rgblight_setrgb_at(x * grad_magnitude, 0, 255 - x * grad_magnitude, i);
    }
  }

  // Rightmost LED set to red, to indicate mediakeys mode is toggled
  if (vbox_mediakeys_enabled) {
    rgblight_setrgb_at(255, 0, 0, 13);
  }
}
