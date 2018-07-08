#include "ok60.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define _BASE 0
#define _L1 1
#define _L2 2
#define _WINPRG 3
#define _MACPRG 4
#define _PRGEXT 6
#define _L5 5

#define _______ KC_TRNS
#define XXXXXXX KC_NO
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_60_iso(
        KC_ESC,   KC_1,     KC_2,    KC_3,   KC_4,    KC_5,   KC_6,    KC_7,   KC_8,   KC_9,    KC_0,     NO_PLUS,  NO_ACUT,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,    KC_U,   KC_I,   KC_O,    KC_P,     NO_AA,    NO_QUOT,
        MO(_L2),  KC_A,     KC_S,    KC_D,   KC_F,    KC_G,   KC_H,    KC_J,   KC_K,   KC_L,    NO_OSLH,  NO_AE,    NO_APOS,  KC_ENT,
        KC_LSFT,  KC_NUBS,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                          SPCWINP,                          NO_ALGR,  MO(_L2),  _______,  KC_RCTL),

    [_L1] = LAYOUT_60_iso( /* Override programming layer */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______,                            SPCMACP,                            _______, _______, _______, _______),
    
    [_L2] = LAYOUT_60_iso(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_PGUP, _______, KC_PGDN, KC_PSCR, _______, _______,
        _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______, _______, _______,
        _______, _______, KC_APP,  _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, MO(_L5)),
    
    [_WINPRG] = LAYOUT_60_iso( /* Win programming */
        _______,     _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, NO_SLSH, _______,    NO_PIPE, _______, _______, _______, _______,
        MO(_PRGEXT), _______, _______, _______, _______, _______, NO_LCBR, NO_LPRN,    NO_RPRN, NO_RCBR, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, TD_GOES_TO, NO_GRTR, _______, _______, _______, _______,
        _______,     _______, _______,                            _______,                               _______, _______, _______, _______),

    [_MACPRG] = LAYOUT_60_iso( /* Mac programming */
        _______,     _______, _______, _______, _______, _______, _______,     _______,    _______,     _______,     _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, NO_SLSH,     _______,    NO_PIPE_MAC, _______,     _______, _______, _______,
        MO(_PRGEXT), _______, _______, _______, _______, _______, NO_LCBR_MAC, NO_LPRN,    NO_RPRN,     NO_RCBR_MAC, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,     TD_GOES_TO, NO_GRTR,     _______,     _______, _______, _______,
        _______,     _______, _______,                            _______,                                           _______, _______, _______, _______),

    [_PRGEXT] = LAYOUT_60_iso( /* Programming extended */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, NO_LBRC, _______, _______, NO_RBRC, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______),

    [_L5] = LAYOUT_60_iso(
        RESET,   TG(_L1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_TOG, CTALDEL,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,   _______,                            _______,                            _______, _______, _______, _______)

};

void goes_to (qk_tap_dance_state_t *state, void *user_data) {
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
