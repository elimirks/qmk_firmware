#include QMK_KEYBOARD_H

// ----------------------------------------------------
// Layers
// ----------------------------------------------------
//

enum layer_number {
    _ALPHA = 0,
    _SHIFT,
    _LOWER,
    _RAISE,
    _MOUSE,
};

// ----------------------------------------------------
// Virtual Keycodes
// ----------------------------------------------------

enum custom_keycodes {
    SHIFT_LAYER = SAFE_RANGE,
};

#define EL_CAD  LALT(LCTL(KC_DEL))
#define EL_SHFT SHIFT_LAYER
// Layer virtual "keycodes"
#define TT_MAU5 TT(_MOUSE)
#define MO_RASE MO(_RAISE)
#define MO_LOWR MO(_LOWER)

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md

#define MT_O MT(MOD_LGUI, KC_O)
#define MT_E MT(MOD_LALT, KC_E)
#define MT_U MT(MOD_LCTL, KC_U)

#define MT_H MT(MOD_RCTL, KC_H)
#define MT_T MT(MOD_RALT, KC_T)
#define MT_N MT(MOD_RGUI, KC_N)

// ----------------------------------------------------
// Mapping
// ----------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    EL_CAD,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    MT_E,    MT_U,    KC_I,                      KC_D,    MT_H,    MT_T,    MT_N,    KC_S,    KC_ENT,
  _______, KC_UNDS, KC_Q,    KC_J,    KC_K,    KC_X,    TT_MAU5, MO_RASE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
                             _______, KC_LGUI, EL_SHFT, KC_SPC,  MO_LOWR, KC_LCTL, KC_LALT, _______
),
[_SHIFT] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, KC_QUES, KC_EXLM, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, EL_SHFT, _______, _______, _______, _______, _______
),
[_LOWER] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_EQL,  _______,
  _______, KC_LCBR, KC_LABK, KC_LPRN, KC_LBRC, KC_SLSH,                   KC_BSLS, KC_RBRC, KC_RPRN, KC_RABK, KC_RCBR, _______,
  _______, _______, KC_TILD, KC_PLUS, KC_MINS, _______, _______, _______, _______, KC_COLN, KC_SCLN, KC_GRV,  _______, _______,
                             _______, _______, _______, _______, MO_LOWR, _______, _______, _______
),
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,                   KC_VOLU, _______, _______, _______, _______, _______,
  _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______,                   KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, MO_RASE, KC_MUTE, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
[_MOUSE] = LAYOUT(
  KC_LGUI, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      _______, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
  KC_M,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TT_MAU5, _______, _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,
                             _______, KC_LCTL, KC_LSFT, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void switch_to_layer(uint8_t layer, bool pressed) {
    if (pressed) {
        layer_on(layer);
    } else {
        layer_off(layer);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }
    if (action_for_key(_SHIFT, record->event.key).code != ACTION_TRANSPARENT) {
        unregister_code(KC_LSFT);
    }

    switch (keycode) {
        case SHIFT_LAYER:
            switch_to_layer(_SHIFT, record->event.pressed);

            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}
