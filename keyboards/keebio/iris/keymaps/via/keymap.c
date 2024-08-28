#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
// #define HM_D LCTL_T(KC_D)
#define HM_D KC_E
#define HM_F LSFT_T(KC_F)

// Right-hand home row mods
#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

#define LT_Z LT(1, KC_Z)
#define LT_SLSH LT(1, KC_SLSH)
#define LT_ESC LT(2, KC_ESC)
#define LT_BSPC LT(3, KC_BSPC)
#define LT_TAB LT(4, KC_TAB)
#define LT_ENT LT(5, KC_ENT)
#define LT_SPC LT(6, KC_SPC)
#define LT_DEL LT(7, KC_DEL)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    // Your macros ...

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning 0 means we
    // instead want to "force hold" and disable key repeating.
    switch (keycode) {
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_J:
        case HM_K:
        case HM_L:
        case HM_SCLN:
            return QUICK_TAP_TERM; // Enable key repeating.
        default:
            return 0; // Otherwise, force hold and disable key repeating.
    }
}

enum custom_layer {
    _BASE,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
    _FN5,
    _FN6,
    _FN7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_LGUI, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                               KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, LT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,            KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  LT_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_ESC,  LT_BSPC, LT_TAB,                    LT_ENT,  LT_SPC,  LT_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN,                            KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                            KC_TRNS, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN, KC_BTN2,          KC_BTN2, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_BTN3, KC_BTN1, KC_BTN2,                   KC_BTN2, KC_BTN1, KC_BTN3
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_CIRC, KC_WBAK, KC_WSTP, KC_WREF, KC_WFWD, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                            KC_EQL,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_PLUS, KC_WSCH, KC_WHOM, KC_BRIU, KC_BRID, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_TRNS, KC_TRNS,                   KC_MSTP, KC_MPLY, KC_MUTE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_TRNS,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT, KC_TRNS,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENT,  KC_INS,  KC_PGDN, KC_HOME, KC_PGUP, KC_END,  KC_TRNS,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_TRNS, KC_NO,   KC_TRNS,                   KC_ENT,  KC_SPC,  KC_DEL
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),

  [_FN4] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                              KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_TRNS, KC_TRNS, KC_NO,                     KC_BTN2, KC_BTN1, KC_BTN3
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),

  [_FN5] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_LCBR, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                            KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_UNDS,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LPRN, KC_RPRN, KC_UNDS,                   KC_NO,   KC_TRNS, KC_TRNS
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),

  [_FN6] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                             KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_MINS,          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_DOT,  KC_0,    KC_MINS,                   KC_TRNS, KC_NO,   KC_TRNS
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 ),

  [_FN7] = LAYOUT(
 //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                            KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_TAB,           KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
 //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_APP,  KC_BSPC, KC_TAB,                    KC_TRNS, KC_TRNS, KC_NO
                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
 )};

// clang-format on
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
