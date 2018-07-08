#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _WINPRG 3
#define _MACPRG 4
#define _PRGEXT 6
#define _L5 5

#define SPCWINP LT(_WINPRG, KC_SPC)
#define SPCMACP LT(_MACPRG, KC_SPC)
#define CTALDEL LALT(LCTL(KC_DEL)) // ctrl+alt+del

#define TD_GOES_TO TD(SBL_TD_GOES_TO)

enum {
  SBL_TD_GOES_TO = 0
};

void goes_to(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
  [SBL_TD_GOES_TO] = ACTION_TAP_DANCE_FN(goes_to)
};

// Fillers to make layering more clear
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MO(_L2), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, LT(_L3, KC_ENT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                   SPCWINP, KC_SPC,                    NO_ALGR, _______, MO(_L5) 
  ),
  [_L1] = LAYOUT( /* Override programming layer */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   SPCMACP, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* Fn layer */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
    _______, KC_APP,  _______, _______, _______, KC_END , KC_PGUP, KC_PGDN, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L3] = LAYOUT( /* F */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_WINPRG] = LAYOUT( /* Programming Win */
    KC_ESC,      _______, NO_QUO2, _______, _______, KC_F5,   NO_SLSH,    _______, NO_PIPE, _______, NO_QUOT, NO_AA,
    MO(_PRGEXT), _______, _______, _______, KC_F10,  KC_F11,  NO_LCBR,    NO_LPRN, NO_RPRN, NO_RBRC, NO_APOS, NO_AE,
    _______,     _______, _______, _______, _______, _______, TD_GOES_TO, NO_GRTR, _______, NO_APOS, _______, _______,
    _______,     _______, _______,                   _______, KC_ENT,                       _______, _______, _______
  ),
  [_MACPRG] = LAYOUT( /* Programming Mac */
    KC_ESC,      _______, NO_QUO2, _______, _______, KC_F5,   NO_SLSH,     _______, NO_PIPE_MAC, _______,     NO_QUOT, NO_AA,
    MO(_PRGEXT), _______, _______, _______, KC_F10,  KC_F11,  NO_LCBR_MAC, NO_LPRN, NO_RPRN,     NO_RCBR_MAC, NO_APOS, NO_AE,
    _______,     _______, _______, _______, _______, _______, TD_GOES_TO,  NO_GRTR, _______,     NO_APOS,     _______, _______,
    _______,     _______, _______,                   _______, KC_ENT,                            _______,     _______, _______
  ),
  [_PRGEXT] = LAYOUT( /* Programming extended */
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, NO_LBRC,  _______, _______, NO_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                    _______, _______, _______
  ),
  [_L5] = LAYOUT(
    TG(_L1), KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, NO_PLUS, _______, CTALDEL,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  )
};

/*
  [_LX] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  )
*/

const uint16_t PROGMEM fn_actions[] = { };

void goes_to(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_NUBS);
    unregister_code (KC_NUBS);
  } else if (state->count >= 2) {
    register_code (KC_SPC);
    unregister_code (KC_SPC);
    register_code (KC_RSFT);
    register_code (KC_0);
    unregister_code (KC_0);
    register_code (KC_NUBS);
    unregister_code (KC_NUBS);
    unregister_code (KC_RSFT);
    register_code (KC_SPC);
    unregister_code (KC_SPC);
    reset_tap_dance (state);
  }
}
