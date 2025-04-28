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
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
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
    switch (keycode) {
        case SHIFT_LAYER:
            switch_to_layer(_SHIFT, record->event.pressed);

            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                if (action_for_key(_SHIFT, record->event.key).code != ACTION_TRANSPARENT) {
                    unregister_code(KC_LSFT);
                }
            }
            return false;
    }
    return true;
}

// ----------------------------------------------------
// Steno(ish)
// ----------------------------------------------------

#define VOCAB_LIST\
    VOCAB_ENTRY(dash,     "--",       KC_MINS, KC_UNDS)\
    VOCAB_ENTRY(the,      "the",      KC_T, KC_H, KC_E)\
    VOCAB_ENTRY(ing,      "ing",      KC_I, KC_N, KC_G)\
    VOCAB_ENTRY(out,      "out",      KC_O, KC_U, KC_T)\
    VOCAB_ENTRY(wha,      "wha",      KC_W, KC_H, KC_A)\
    VOCAB_ENTRY(and,      "and",      KC_A, KC_N, KC_D)\
    VOCAB_ENTRY(ion,      "ion",      KC_I, KC_O, KC_N)\
    VOCAB_ENTRY(her,      "her",      KC_H, KC_E, KC_R)\
    VOCAB_ENTRY(for,      "for",      KC_F, KC_O, KC_R)\
    VOCAB_ENTRY(tha,      "tha",      KC_T, KC_H, KC_A)\
    VOCAB_ENTRY(tio,      "tio",      KC_T, KC_I, KC_O)\
    VOCAB_ENTRY(ent,      "ent",      KC_E, KC_N, KC_T)\
    VOCAB_ENTRY(ati,      "ati",      KC_A, KC_T, KC_I)\
    VOCAB_ENTRY(his,      "his",      KC_H, KC_I, KC_S)\
    VOCAB_ENTRY(thi,      "thi",      KC_T, KC_H, KC_I)\
    VOCAB_ENTRY(pre,      "pre",      KC_P, KC_R, KC_E)\
    VOCAB_ENTRY(whi,      "whi",      KC_W, KC_H, KC_I)\
    VOCAB_ENTRY(ter,      "ter",      KC_T, KC_E, KC_R)\
    VOCAB_ENTRY(ate,      "ate",      KC_A, KC_T, KC_E)\
    VOCAB_ENTRY(con,      "con",      KC_C, KC_O, KC_N)\
    VOCAB_ENTRY(res,      "res",      KC_R, KC_E, KC_S)\
    VOCAB_ENTRY(has,      "has",      KC_H, KC_A, KC_S)\
    VOCAB_ENTRY(est,      "est",      KC_E, KC_S, KC_T)\
    VOCAB_ENTRY(can,      "can",      KC_C, KC_A, KC_N)\
    VOCAB_ENTRY(cha,      "cha",      KC_C, KC_H, KC_A)\
    VOCAB_ENTRY(nce,      "nce",      KC_N, KC_C, KC_E)\
    VOCAB_ENTRY(git,      "git",      KC_G, KC_I, KC_T)\
    VOCAB_ENTRY(tion,     "tion",     KC_T, KC_I, KC_O, KC_N)\
    VOCAB_ENTRY(ther,     "ther",     KC_T, KC_H, KC_E, KC_R)\
    VOCAB_ENTRY(ment,     "ment",     KC_M, KC_E, KC_N, KC_T)\
    VOCAB_ENTRY(this,     "this",     KC_T, KC_H, KC_I, KC_S)\
    VOCAB_ENTRY(ould,     "ould",     KC_O, KC_U, KC_L, KC_D)\
    VOCAB_ENTRY(have,     "have",     KC_H, KC_A, KC_V, KC_E)\
    VOCAB_ENTRY(when,     "when",     KC_W, KC_H, KC_E, KC_N)\
    VOCAB_ENTRY(ance,     "ance",     KC_A, KC_N, KC_C, KC_E)\
    VOCAB_ENTRY(ence,     "ence",     KC_E, KC_N, KC_C, KC_E)\
    VOCAB_ENTRY(able,     "able",     KC_A, KC_B, KC_L, KC_E)\
    VOCAB_ENTRY(ator,     "ator",     KC_A, KC_T, KC_O, KC_R)\
    VOCAB_ENTRY(ates,     "ates",     KC_A, KC_T, KC_E, KC_S)\
    VOCAB_ENTRY(ouse,     "ouse",     KC_O, KC_U, KC_S, KC_E)\
    VOCAB_ENTRY(sent,     "sent",     KC_S, KC_E, KC_N, KC_T)\
    VOCAB_ENTRY(base,     "base",     KC_B, KC_A, KC_S, KC_E)\
    VOCAB_ENTRY(some,     "some",     KC_S, KC_O, KC_M, KC_E)\
    VOCAB_ENTRY(once,     "once",     KC_O, KC_N, KC_C, KC_E)\
    VOCAB_ENTRY(just,     "just",     KC_J, KC_U, KC_S, KC_T)\
    VOCAB_ENTRY(most,     "most",     KC_M, KC_O, KC_S, KC_T)\


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
