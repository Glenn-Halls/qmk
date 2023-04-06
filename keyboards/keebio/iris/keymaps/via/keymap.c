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

// TapDance keys
enum {
    WIN_QWERTY,
    CW_CL,
    ENT_L235_L0,
};

// Macro Definitions
enum custom_keycodes {
    MCR_00 = SAFE_RANGE,
    MCR_01,
    MCR_02,
    MCR_03,
    MCR_04,
    MCR_05,
    MCR_06,
    MCR_07,
    MCR_08,
    MCR_09,
    MCR_10,
    MCR_11,
    MCR_12,
    MCR_13,
    MCR_14,
    MCR_15,
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MCR_00:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("Testing 1, 2, 3...   Testing 1, 2, 3...");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case MCR_01:
    // QMK - HYPR
        if (record->event.pressed) {
            SEND_STRING("HYPR(");
            tap_code16(C(KC_RIGHT));
            tap_code16(S(KC_0));
        }
        break;

    case MCR_02:
    //  QMK - MEH
        if (record->event.pressed) {
            SEND_STRING("MEH(");
            tap_code16(C(KC_RIGHT));
            tap_code16(S(KC_0));
        }
        break;

    case MCR_03:
    //  Android: Ctrl + .
        if (record->event.pressed) {
            tap_code16(C(KC_DOT));
        }
        break;

    case MCR_04:
    // Java: print
        if (record->event.pressed) {
            SEND_STRING("System.out.print(\"\");" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;

    case MCR_05:
    //  Java: println
        if (record->event.pressed) {
            SEND_STRING("System.out.println(\"\");" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;

    case MCR_06:
    // Java: printf
        if (record->event.pressed) {
            SEND_STRING("System.out.printf(\"\");" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;
    
    case MCR_09:
    //  Java PSVM
        if (record->event.pressed) {
            SEND_STRING("public static void main(String[] args) {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
        }
        break;

    case MCR_13:
    //  Starcraft 2 QUIT 
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F10) SS_DELAY(23) SS_TAP(X_N));
        }
        break;
    }
    return true;
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void ent_finished(tap_dance_state_t *state, void *user_data);
void ent_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌───────┬────────┬────────┬────────┬────────┬────────┐                                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD(WIN_QWERTY),
  //├───────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_GRV,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌──────────────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    LT(1,KC_DEL),    MT(MOD_RSFT,KC_TAB), KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────────────┬─┴────────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, MT(MOD_LSFT,KC_BSPC),    LT(1,KC_SPC),  TD(ENT_L235_L0),  TD(CW_CL)
                                // └────────┴────────┴────────┘                └────────────┴──────────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PLUS, KC_PSCR,  KC_PGUP, KC_UP,   KC_INS,  KC_ENT,                            KC_BSLS,  KC_7,    KC_8,    KC_9,    KC_EQL,  KC_TILD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_UNDS,  KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                           KC_ASTR,  KC_4,    KC_5,    KC_6,    KC_COLN, KC_DQUO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCBR,  KC_EXLM, KC_PGDN, KC_HOME, KC_END,  KC_AMPR, KC_BSPC,         _______, KC_PIPE,  KC_1,    KC_2,    KC_3,    KC_0,    KC_RCBR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_SPC,   _______, KC_F11
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
LSFT(KC_F12), LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), LSFT(KC_F5), LSFT(KC_F6), LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUI, RGB_RMOD, KC_MRWD, KC_VOLU, KC_MFFD, RGB_MOD,                            MCR_10,  MCR_07,  MCR_08,  MCR_09,  MCR_13,  QK_MACRO_0,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUD,  RGB_VAI, KC_MSTP, KC_VOLD, KC_MPLY, RGB_SPI,                            MCR_11,  MCR_04,  MCR_05,  MCR_06,  MCR_14,  QK_MACRO_1,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT,  RGB_VAD, KC_MPRV, KC_MUTE, KC_MNXT, RGB_SPD, _______,         _______,  MCR_12,  MCR_01,  MCR_02,  MCR_03,  MCR_15,  MCR_00,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    RGB_TOG, _______,  TG(1)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
  //┌─────────────┬───────────┬───────────┬───────────┬───────────┬────────────┐                                    ┌───────────┬───────────┬─────────────┬───────────┬──────────────┬───────────┐
     HYPR(KC_ESC), HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5),                                        HYPR(KC_6), HYPR(KC_7), HYPR(KC_8),   HYPR(KC_9), HYPR(KC_0),    _______,
  //├─────────────┼───────────┼───────────┼───────────┼───────────┼────────────┤                                    ├───────────┼───────────┼─────────────┼───────────┼──────────────┼───────────┤
     HYPR(KC_EQL), HYPR(KC_Q), HYPR(KC_W), HYPR(KC_F), HYPR(KC_P), HYPR(KC_B),                                        HYPR(KC_J), HYPR(KC_L), HYPR(KC_U),   HYPR(KC_Y), HYPR(KC_SCLN), HYPR(KC_GRV),
  //├─────────────┼───────────┼───────────┼───────────┼───────────┼────────────┤                                    ├───────────┼───────────┼─────────────┼───────────┼──────────────┼───────────┤
     HYPR(KC_MINS), HYPR(KC_A), HYPR(KC_R), HYPR(KC_S), HYPR(KC_T), HYPR(KC_G),                                       HYPR(KC_M), HYPR(KC_ENT), HYPR(KC_E),   HYPR(KC_I), HYPR(KC_O),    HYPR(KC_QUOT),
  //├─────────────┼───────────┼───────────┼───────────┼───────────┼────────────┼────────┐        ┌──────────────────┼───────────┼───────────┼─────────────┼───────────┼──────────────┼───────────┤
     HYPR(KC_LBRC), HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_D), HYPR(KC_V), _______,                    _______, HYPR(KC_K), HYPR(KC_H), HYPR(KC_COMM),HYPR(KC_DOT),HYPR(KC_SLSH), HYPR(KC_RBRC),
  //└─────────────┴───────────┴───────────┴──────┬────┴──────┬────┴───────┬────┴───┬────┘        └───┬────────────┬─┴───────────┴───┬───────┴───┬─────────┴───────────┴──────────────┴───────────┘
                                                    _______,     _______,   _______,                      _______,     _______,         TG(2)
                                              // └───────────┴────────────┴────────┘                 └────────────┴─────────────────┴───────────┘
  ),

  [_FN4] = LAYOUT(
  //┌───────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    LT(1,KC_SPC), _______, TD(CW_CL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN5] = LAYOUT(
  //┌───────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├───────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├───────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└───────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, MT(MOD_LSFT,KC_BSPC),    LT(1,KC_SPC), _______, TD(CW_CL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

// defines the keycodes for which TAPPING_FORCE_HOLD_PER_KEY should be enacted
// when a user holds a key after tapping it, will now activate hold function instead of
// (default) auto-repeating the tapping function
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT,KC_BSPC):
            return 0;
        case LT(1,KC_SPC):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}


td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        // altered below if conditions from documented || to && to single tap for faster typing
        if (state->interrupted && !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else if (state->pressed) return TD_SINGLE_HOLD;
        else return TD_SINGLE_TAP;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted && !state->pressed) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        // same as for TD_DOUBLE_SINGLE_TAP but for TD_TRIPLE_SINGLE_TAP
        if (state->interrupted && !state->pressed) return TD_TRIPLE_SINGLE_TAP;
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


/*
*   TapDance for ENTER Key:
*   tap = enter
*   hold = layer 2
*   double-tap = 2x enter
*   double-hold = layer 3
*   double-single-tap = 2x enter
*   triple-tap = reset to layer 0
*   triple-hold = layer 5
*   triple-single-tap = 3x enter
*   Y > 3 taps = Yx enter
*/

void ent_tap(tap_dance_state_t *state, void *user_data) {
    switch (state->count){
        case 1:
        case 2:
        case 3:
            break;
        default: tap_code(KC_ENT); break;
    }
}

void ent_finished(tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ENT); break;
        case TD_SINGLE_HOLD: layer_on(_FN2); break;
        case TD_DOUBLE_HOLD: layer_on(_FN3); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: layer_on(_FN5); break;
        case TD_TRIPLE_TAP: layer_off(_FN1); layer_off(_FN4); break;
        case TD_TRIPLE_SINGLE_TAP: register_code(KC_ENT); break;
        default: break;
    }
}

void ent_reset(tap_dance_state_t *state, void *user_data) {
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ENT); break;
        case TD_SINGLE_HOLD: layer_off(_FN2); break;
        case TD_DOUBLE_HOLD: layer_off(_FN3); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ENT); tap_code(KC_ENT); break;
        case TD_TRIPLE_HOLD: layer_off(_FN5); break;
        case TD_TRIPLE_TAP: layer_on(_MAIN); break;
        case TD_TRIPLE_SINGLE_TAP: unregister_code(KC_ENT); tap_code(KC_ENT); tap_code(KC_ENT); break;
        default: tap_code(KC_ENT); tap_code(KC_ENT); tap_code(KC_ENT); break;
    }
    clear_mods();
    enttap_state.state = TD_NONE;
}

/*
*   TapDance for WIN_QWERTY Key:
*   tap = windows
*   hold = windows
*   double-tap = all layers off and switch to layer 0
*   double-hold = windows & layer 1 (for screen dragging)
*   double-single-tap = same as double-tap
*/
void win_finished(tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_RGUI); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_RGUI)); break;
        case TD_DOUBLE_HOLD: register_mods(MOD_BIT(KC_RGUI)); layer_on(_FN1); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: layer_off(_FN1); layer_off(_FN2); layer_off(_FN3); layer_off(_FN5); break;
        default: break;
    }
}

void win_reset(tap_dance_state_t *state, void *user_data) {
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_RGUI); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_RGUI)); break;
        case TD_DOUBLE_HOLD: unregister_mods(MOD_BIT(KC_RGUI)); layer_off(_FN1); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: layer_on(_FN4); break;
        default: break;
    }
    enttap_state.state = TD_NONE;
}


/*
*   TapDance for CW_CL Key:
*   tap = Caps Word
*   hold = LAlt + Layer 1
*   double-tap = Caps Word off and toggle Caps Lock
*   double-hold = LAlt + LCtrl + Layer 1
*   double-single-tap = same as double-tap
*/
void caps_finished(tap_dance_state_t *state, void *user_data) {
    enttap_state.state = cur_dance(state);
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: caps_word_toggle(); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LALT)); layer_on(_FN1); break;
        case TD_DOUBLE_HOLD: register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); layer_on(_FN1); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: caps_word_off(); register_code(KC_CAPS); break;
        default: break;
    }
}

void caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (enttap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LALT)); layer_off(_FN1);break;
        case TD_DOUBLE_HOLD: unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); layer_off(_FN1); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_CAPS); break;
        default: break;
    }
    layer_off(_FN1);
    enttap_state.state = TD_NONE;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Windows key, twice for Layer 0, twice and hold for win and L1
    [WIN_QWERTY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset),
    // Tap once to toggle Caps Word, hold for alt (L1), tap twice for Caps Lock, double hold for ctrl + alt (L1),
    [CW_CL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset),
    // Tap once for Enter, hold for L2, double hold for L3
    [ENT_L235_L0] = ACTION_TAP_DANCE_FN_ADVANCED(ent_tap, ent_finished, ent_reset),
};
