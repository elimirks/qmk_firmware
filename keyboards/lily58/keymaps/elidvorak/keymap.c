#include QMK_KEYBOARD_H

// ----------------------------------------------------
// Layers
// ----------------------------------------------------
//

enum layer_number {
    //_ALPHA = 0,
    _ALPHA_PRIME = 0,
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
// Layer virtual "keycodes"
#define TT_MAU5 TT(_MOUSE)
#define MO_RASE MO(_RAISE)
#define MO_LOWR MO(_LOWER)

// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md

#define MT_TAB  MT(MOD_LALT, KC_TAB)
#define MT_ESC  MT(MOD_LCTL, KC_ESC)
#define MT_BSPC MT(MOD_RALT, KC_BSPC)
#define MT_ENT  MT(MOD_RCTL, KC_ENT)

#define MT_COMM MT(MOD_LALT, KC_COMM)
#define MT_DOT  MT(MOD_LCTL, KC_DOT)
#define MT_C MT(MOD_RCTL, KC_C)
#define MT_R MT(MOD_RALT, KC_R)

#define MT_P MT(MOD_LCTL, KC_P)
#define MT_Y  MT(MOD_LALT, KC_Y)
#define MT_F MT(MOD_RALT, KC_F)
#define MT_G MT(MOD_RCTL, KC_G)

const key_override_t key_override_comm = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t key_override_dot = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);

const key_override_t *key_overrides[] = {
    &key_override_comm,
    &key_override_dot,
};

// ----------------------------------------------------
// Mapping
// ----------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_ALPHA] = LAYOUT(
//   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    EL_CAD,
//   MT_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    MT_BSPC,
//   MT_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    MT_ENT,
//   _______, KC_UNDS, KC_Q,    KC_J,    KC_K,    KC_X,    TT_MAU5, MO_RASE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
//                              _______, KC_LGUI, KC_LSFT, KC_SPC,  MO_LOWR, KC_LCTL, KC_LALT, _______
// ),
[_ALPHA_PRIME] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    EL_CAD,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  MT_P,    MT_Y,                      MT_F,    MT_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  _______, KC_UNDS, KC_Q,    KC_J,    KC_K,    KC_X,    TT_MAU5, MO_RASE, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
                             _______, KC_LGUI, KC_LSFT, KC_SPC,  MO_LOWR, KC_LCTL, KC_LALT, _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// ----------------------------------------------------
// Steno
// ----------------------------------------------------

#define VOCAB_LIST\
    VOCAB_ENTRY(dash,     "--",       KC_MINS, KC_UNDS)\
    VOCAB_ENTRY(the,      "the",      KC_T, KC_H, KC_E)\


// Helper macros to count the number of arguments
#define COUNT_ARGS(...) COUNT_ARGS_(__VA_ARGS__, 10,9,8,7,6,5,4,3,2,1)
#define COUNT_ARGS_(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,N,...) N

// 1. Enumerate the combos
enum combo_events {
#define VOCAB_ENTRY(NAME, STRING, ...)  COMBO_##NAME,
    VOCAB_LIST
#undef VOCAB_ENTRY
    COMBO_PARENS,
    COMBO_BRACES,
    COMBO_BRACKETS,
    COMBO_ANGLES,
};

// 2. Key arrays - create array named combo_<name> for each, with variable length
#define MAKE_KEY_ARRAY(NAME, STRING, ...) \
    const uint16_t PROGMEM combo_##NAME[] = { __VA_ARGS__, COMBO_END };

const uint16_t PROGMEM combo_PARENS[] = { KC_LPRN, KC_RPRN, COMBO_END };
const uint16_t PROGMEM combo_BRACES[] = { KC_LCBR, KC_RCBR, COMBO_END };
const uint16_t PROGMEM combo_BRACKETS[] = { KC_LBRC, KC_RBRC, COMBO_END };
const uint16_t PROGMEM combo_ANGLES[] = { KC_LABK, KC_RABK, COMBO_END };

#define VOCAB_ENTRY MAKE_KEY_ARRAY
VOCAB_LIST
#undef VOCAB_ENTRY

// Combo array (make sure ordering matches enum!)
combo_t key_combos[] = {
#define VOCAB_ENTRY(NAME, STRING, ...) \
    [COMBO_##NAME] = COMBO_ACTION(combo_##NAME),
    VOCAB_LIST
#undef VOCAB_ENTRY
    [COMBO_PARENS] = COMBO_ACTION(combo_PARENS),
    [COMBO_BRACES] = COMBO_ACTION(combo_BRACES),
    [COMBO_BRACKETS] = COMBO_ACTION(combo_BRACKETS),
    [COMBO_ANGLES] = COMBO_ACTION(combo_ANGLES),
};

// 6. Unified event handler
void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;
    switch (combo_index) {
#define VOCAB_ENTRY(NAME, STRING, ...) \
        case COMBO_##NAME: SEND_STRING(STRING); break;
    VOCAB_LIST
#undef VOCAB_ENTRY
        case COMBO_PARENS:
            SEND_STRING("()");
            tap_code(KC_LEFT);
            break;
        case COMBO_BRACES:
            SEND_STRING("{}");
            tap_code(KC_LEFT);
            break;
        case COMBO_BRACKETS:
            SEND_STRING("[]");
            tap_code(KC_LEFT);
            break;
        case COMBO_ANGLES:
            SEND_STRING("<>");
            tap_code(KC_LEFT);
            break;
    }
}
