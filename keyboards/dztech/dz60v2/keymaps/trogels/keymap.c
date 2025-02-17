
#include QMK_KEYBOARD_H
//#include "quantum.h"
// tap dance declarations
enum tap_dance { TD_ESC, TD_LCTL, TD_RCTL };

enum custom_keycodes {
    C_MAIL = SAFE_RANGE,
    C_SSHK,
    C_PASS,
    C_HELP
    
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_BTN4),
    [TD_RCTL] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_BTN5)};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_all(
        TD(TD_ESC),   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,        KC_BSPC,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,       KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_RSFT,      KC_NO,
        TD(TD_LCTL), KC_LGUI, KC_LALT,                   KC_NO,   KC_SPC,  KC_NO,            KC_RALT, MO(1),   KC_NO, KC_APP,    TD(TD_RCTL)
    ),
    LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        OSL(2), _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN,          KC_KP_ENTER,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, MO(2), _______
    ),
    LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
        _______, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, EE_CLR, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,  BL_STEP, _______, _______, _______, _______, KC_HELP, _______, _______,
        _______, _______, _______,                   _______, KC_HELP, _______,          _______, _______, _______, _______, _______
    ),
    LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, XXXXXXX,
        _______, _______, _______,                   XXXXXXX, _______, XXXXXXX,          _______, _______, XXXXXXX, MO(1)  , _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_HELP:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("KEYBOARD INSTRUCTIONS\n######## ############\n");
            SEND_STRING("\n");
            SEND_STRING(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");
            SEND_STRING("| ~  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] | <-    |\n");
            SEND_STRING("|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|\n");
            SEND_STRING("| ->| | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \\  |\n");
            SEND_STRING("|-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|\n");
            SEND_STRING("| caps | A | S | D | F | G | H | J | K | L | ; | '  |  enter |\n");
            SEND_STRING("|------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|\n");
            SEND_STRING("| shift  | Z | X | C | V | B | N | M | , | . | / |    shift |\n");
            SEND_STRING("|------,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|\n");
            SEND_STRING("| ctl | win | alt |                 | alt | fn  | mnu | ctl |\n");
            SEND_STRING("'-----'-----'-----'-----------------'-----'-----'-----'-----'\n");
            SEND_STRING("\n");
            SEND_STRING("FN layer\n");
            SEND_STRING(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");
            SEND_STRING("| ~  |   |   |   |   | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] | del  |\n");
            SEND_STRING("|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|\n");
            SEND_STRING("| ->| |   | ↑ |   |   |   | Y | U | I | O | P | [ | ] |  \\  |\n");
            SEND_STRING("|-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|\n");
            SEND_STRING("| caps | ← | ↓ | → |   |   | H | J | K | L | ; | '  |kp enter|\n");
            SEND_STRING("|------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|\n");
            SEND_STRING("| shift  |   |   |   |   | B | N | M | , | . | / |    shift |\n");
            SEND_STRING("|------,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|\n");
            SEND_STRING("| ctrl | supr | alt |               | alt | fn | mo2 | ctrl |\n");
            SEND_STRING("'------'------'-----'---------------'-----'----'-----'------'\n");

        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};



// KEYBOARD INSTRUCTIONS
// ######## ############

// ,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
// | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] | <-    |
// |---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
// | ->| | Q | W | E | R | T | Y | U | I | O | P | [ | ] | . \  |
// |-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|
// | caps | A | S | D | F | G | H | J | K | L | ; | ' |  enter |
// |------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|
// | shift  | Z | X | C | V | B | N | M | , | . | / |  .  shift |
// |------,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
// | ctrl | supr | alt |               | alt | fn | mnu | ctrl |
// '------'------'-----'---------------'-----'----'-----'------''



//enum layers { _BASE, _FN1, _FN2, _STANDARD, _MACOS, _DAYZ };

// #include QMK_KEYBOARD_H

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//   [0] = LAYOUT_60_ansi(//base
//     TD(_TD_ESC),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_BSPC,
//     KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,        KC_RBRC,        KC_BSLS,
//     KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                        KC_ENT,
//     KC_LSFT,                        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                        KC_RSFT,
//     TD(_TD_LCTRL),  KC_LGUI,        KC_LALT,                                                        KC_SPC,                                                         KC_RALT,        MO(1),          KC_APP,         TD(_TD_RCTRL)
//   ),
//   [1] = LAYOUT_60_ansi(//fn1
//     KC_GRV,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_DEL,
//     OSL(2),         KC_TRNS,        KC_UP,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PSCR,        KC_HOME,        KC_END,         KC_TRNS,
//     KC_TRNS,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_KP_ENTER,
//     KC_TRNS,                        KC_VOLD,        KC_MUTE,        KC_VOLU,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_INS,         K_HELP,                         KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
//   ),
//   [2] = LAYOUT_60_ansi(//fn2
//     KC_TRNS,        TO(0),          TO(3),          TO(4),          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        SSHKEY,         EMAIL,          PASSWD,         K_RELOAD,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
//     KC_TRNS,                        KC_TRNS,        KC_TRNS,        K_CAT,          KC_TRNS,        QK_BOOT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
//   ),
//   [3] = LAYOUT_60_ansi(//macos
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
//     KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
//     KC_TRNS,        KC_LALT,        KC_LGUI,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
//   ),
//   [4] = LAYOUT_60_ansi(//dayz
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
//     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_TRNS,
//     KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
//     KC_TRNS,        KC_NO,          KC_LALT,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
//   )
// };
