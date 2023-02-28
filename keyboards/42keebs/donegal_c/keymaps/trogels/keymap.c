/* Copyright 2018 Yiancar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "donegal_c.h"

enum { _BASE, _FN1, _FN2, _STANDARD, _MACOS, _DAYZ };

// tap dance declarations
enum { _TD_ESC, _TD_LCTRL, _TD_RCTRL };

int counter = 0;

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    SSHKEY,
    PASSWD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_60_ansi(
    TD(_TD_ESC),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRC,        KC_RBRC,        KC_BSLS,
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,                        KC_ENT,
    KC_LSFT,                        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,                        KC_RSFT,
    TD(_TD_LCTRL),  KC_LGUI,        KC_LALT,                                                        KC_SPC,                                                         KC_RALT,        MO(_FN1),       KC_APP,         TD(_TD_RCTRL)
  ),
  [_FN1] = LAYOUT_60_ansi(
    KC_GRV,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_DEL,
    OSL(_FN2),      KC_TRNS,        KC_UP,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PSCR,        KC_HOME,        KC_END,         KC_TRNS,
    KC_TRNS,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_TRNS,
    KC_TRNS,                        KC_VOLU,        KC_VOLD,        KC_MUTE,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_INS,         KC_DEL,                         KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [_FN2] = LAYOUT_60_ansi(
    KC_TRNS,        TO(_BASE),      TO(_MACOS),     TO(_DAYZ),      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        SSHKEY,         EMAIL,          PASSWD,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        QK_BOOT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [_MACOS] = LAYOUT_60_ansi(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_LALT,        KC_LGUI,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [_DAYZ] = LAYOUT_60_ansi(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PGUP,        KC_PGDN,                        KC_TRNS,
    KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,
    KC_TRNS,        KC_NO,          KC_LALT,                                                        KC_TRNS,                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
  )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (timer_elapsed32(oled_sleep_timer) < 3000) {
       oled_write_ln_P(PSTR("      donegal-c     "), false);
       oled_write_ln_P(PSTR("assembled by trogels"), false);
    }
    if (timer_elapsed32(oled_sleep_timer) < 6000 && timer_elapsed32(oled_sleep_timer) > 3000) {
       oled_write_ln_P(PSTR("     powered by     "), false);
       oled_write_ln_P(PSTR("        QMK         "), false);
    }
    if (timer_elapsed32(oled_sleep_timer) > 6000) {
       if (IS_LAYER_ON(_BASE) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
           oled_write_ln_P(PSTR("      Default      "), false);
       }
       if (IS_LAYER_ON(_MACOS) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
           oled_write_ln_P(PSTR("       MACOS       "), false);
       }
       if (IS_LAYER_ON(_DAYZ) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
           oled_write_ln_P(PSTR("        DayZ        "), false);
       }
       if (IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
           oled_write_ln_P(PSTR("        Lift        "), false);
       }
       if (IS_LAYER_ON(_FN2)) {
           oled_write_ln_P(PSTR("      Oneshot      "), false);
       }

       oled_write_ln_P(PSTR("            "), false);
       led_t led_state = host_keyboard_led_state();
       oled_write_ln_P(PSTR("--------------------"), false);

       oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    }1
    return false;
}
#endif

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [_TD_ESC]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [_TD_LCTRL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_BTN4),
    [_TD_RCTRL] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_BTN5)};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SSHKEY:
            if (record->event.pressed) {
                SEND_STRING("1");
            }
            break;

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("2");
            }
            break;

        case PASSWD:
            if (record->event.pressed) {
                SEND_STRING("3");
            }
            break;
    }
    return true;
};