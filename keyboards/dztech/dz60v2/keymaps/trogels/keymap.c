#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_all(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_RSFT, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_NO,   KC_SPC,  KC_NO,            KC_RALT, KC_RGUI, KC_NO,   MO(1),   KC_RCTL
    ),
    LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PRCR, KC_HOME, KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN,          KC_KP_ENTER,
        _______, _______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,  BL_STEP, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
    LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,  BL_STEP, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};


//enum layers { _BASE, _FN1, _FN2, _STANDARD, _MACOS, _DAYZ };

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_60_ansi(//base
    TD(_TD_ESC),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,        KC_RBRC,        KC_BSLS,
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                        KC_ENT,
    KC_LSFT,                        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                        KC_RSFT,
    TD(_TD_LCTRL),  KC_LGUI,        KC_LALT,                                                        KC_SPC,                                                         KC_RALT,        MO(1),          KC_APP,         TD(_TD_RCTRL)
  ),
  [1] = LAYOUT_60_ansi(//fn1
    KC_GRV,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_DEL,
    OSL(2),         KC_TRNS,        KC_UP,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PSCR,        KC_HOME,        KC_END,         KC_TRNS,
    KC_TRNS,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_KP_ENTER,
    KC_TRNS,                        KC_VOLD,        KC_MUTE,        KC_VOLU,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_INS,         K_HELP,                         KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [2] = LAYOUT_60_ansi(//fn2
    KC_TRNS,        TO(0),          TO(3),          TO(4),          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        SSHKEY,         EMAIL,          PASSWD,         K_RELOAD,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        K_CAT,          KC_TRNS,        QK_BOOT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [3] = LAYOUT_60_ansi(//macos
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_LALT,        KC_LGUI,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [4] = LAYOUT_60_ansi(//dayz
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_NO,          KC_LALT,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  )
};
