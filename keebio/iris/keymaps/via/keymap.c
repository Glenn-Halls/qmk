#include QMK_KEYBOARD_H

// Layer declarations
enum custom_layer {
    _MAIN,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
    _FN5,
};


// Tap Dance declarations

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
    TD_TRIPLE_SINGLE_TAP,
    TD_QUAD_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    ESC_CAPS,
    WIN_CAPS,
    ENT_L235_L0,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void ent_finished(qk_tap_dance_state_t *state, void *user_data);
void ent_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────────────┬────────┬────────┬────────┬────────┬────────┐                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TD(ESC_CAPS),     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD(WIN_CAPS),
  //├────────────────┼────────┼────────┼────────┼────────┼────────┤                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_GRV,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌──────────────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    LT(1,KC_DEL),    MT(MOD_RSFT,KC_TAB), KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────────────┬─┴────────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, MT(MOD_LSFT,KC_BSPC),    LT(1,KC_SPC), TD(ENT_L235_L0), CAPS_WORD
                                // └────────┴────────┴────────┘                └────────────┴──────────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PLUS, KC_PSCR,  KC_INS,  KC_UP,   KC_PGUP, KC_ENT,                               KC_BSLS, KC_P7,   KC_P8,   KC_P9,   KC_EQL,  KC_TILD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_UNDS,  KC_LPRN, KC_LEFT,  KC_DOWN, KC_RGHT, KC_LCBR,                           KC_AT,   KC_P4,   KC_P5,   KC_P6,   KC_COLN, KC_DQUO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCBR,  KC_RPRN, KC_HOME,  KC_END,  KC_PGDN, KC_RCBR, KC_BSPC,         _______, KC_PIPE, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_RCBR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_SPC,   _______,  KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN4] = LAYOUT(
  //┌────────────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TD(ESC_CAPS),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, FN_MO13, MT(MOD_LSFT,KC_BSPC),    LT(1,KC_SPC), _______, CAPS_WORD
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN5] = LAYOUT(
  //┌────────────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TD(ESC_CAPS),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, FN_MO13, MT(MOD_LSFT,KC_BSPC),    LT(1,KC_SPC), _______, CAPS_WORD
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// defines the keycodes for which TAPPING_FORCE_HOLD_PER_KEY should be enacted
// when a user holds a key after tapping it, will now activate hold function instead of
// (default) auto-repeating the tapping function
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT,KC_BSPC):
            return true;
        case LT(1,KC_SPC):
            return true;
        default:
            return false;
    }
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        // same as for TD_DOUBLE_SINGLE_TAP but for TD_TRIPLE_SINGLE_TAP
        if (state->interrupted) return TD_TRIPLE_SINGLE_TAP;
        else if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }

    // see note below from original documentation: alteration here is to make the same apply for quad-tap,
    // which will break the dance, and return the basic KC the number of times it was pressed

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count >= 4) return TD_QUAD_TAP;
    
    else return TD_UNKNOWN;
    
}


// Create an instance of 'td_tap_t' for the 'ent' tap dance.
static td_tap_t enttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ent_finished(qk_tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ENT); break;
        case TD_SINGLE_HOLD: layer_on(_FN2); break;
        case TD_DOUBLE_TAP: tap_code(KC_ENT); register_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: layer_on(_FN3); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_ENT); register_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: layer_on(_FN5); break;
        case TD_TRIPLE_TAP: layer_off(_FN1); layer_off(_FN2); layer_off(_FN3); layer_off(_FN4); layer_off(_FN5); break;
        case TD_TRIPLE_SINGLE_TAP: register_code(KC_ENT); break;
        case TD_QUAD_TAP: register_code(KC_ENT); break;
        default: break;
    }
}

void ent_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENT); break;
        case TD_SINGLE_HOLD: layer_off(_FN2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ENT); break;
        case TD_DOUBLE_HOLD: layer_off(_FN3); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: layer_off(_FN5); break;
        case TD_TRIPLE_TAP: layer_on(_MAIN); break;
        case TD_TRIPLE_SINGLE_TAP:
        case TD_QUAD_TAP: {
            for (int i = 1; i < state->count; i++) {
               tap_code(KC_ENT);
            }
            unregister_code(KC_ENT);
            break;
        }
        default: break;
    }
    enttap_state.state = TD_NONE;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for Windows key, twice for Caps Lock
    [WIN_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_CAPS),
    // Tap once for Enter, hold for L2, double hold for L3
    [ENT_L235_L0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset),
};
