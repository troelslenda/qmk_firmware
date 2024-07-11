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
#include <stdio.h>

//
//#if (__has_include("secrets.h") && !defined(NO_SECRETS))
//#include "secrets.h"
//#endif




// tap dance declarations
enum tap_dance { _TD_ESC, _TD_LCTRL, _TD_RCTRL };

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    SSHKEY,
    PASSWD,
    K_HELP,
    K_CAT,
    K_RELOAD
};

enum oled_modes {
    SPLASH,
    DEFAULT,
    HELP,
    CAT,
    RESET
};

#include "layers.h"

uint16_t oled_sleep_timer;

bool show_help;
bool show_cat = false;
bool show_reload = false;
bool show_layers = false;




static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

#ifdef OLED_ENABLE
bool oled_task_kb(void) {
  if (!oled_task_user()) { return false; }

oled_sleep_timer = 0;
char active_mode = SPLASH;

if (show_cat) {
    active_mode = CAT;
}

if (show_layers) {
    active_mode = DEFAULT;
}

if (show_help) {
    active_mode = HELP;
}


switch(active_mode) {

    case SPLASH:
        if (timer_elapsed32(oled_sleep_timer) < 3000) {
            oled_write_ln_P(PSTR("      donegal-c     "), false);
            oled_write_ln_P(PSTR("assembled by trogels"), false);
        }
        if (timer_elapsed32(oled_sleep_timer) < 6000 && timer_elapsed32(oled_sleep_timer) > 3000) {
             oled_write_ln_P(PSTR("         powered by"), false);
             render_logo();
        }
        if(timer_elapsed32(oled_sleep_timer) > 6000) {
            oled_clear();
            show_layers=true;
        }
        break;
    case DEFAULT:
        if (IS_LAYER_ON(_BASE) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
            oled_write_ln_P(PSTR("      Default      1"), false);
        }
        if (IS_LAYER_ON(_MACOS) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
            oled_write_ln_P(PSTR("       MACOS       2"), false);
        }
        if (IS_LAYER_ON(_DAYZ) && !IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
            oled_write_ln_P(PSTR("        DayZ       3"), false);
        }
        if (IS_LAYER_ON(_FN1) && !IS_LAYER_ON(_FN2)) {
            oled_write_ln_P(PSTR("        Lift        "), false);
        }
        if (IS_LAYER_ON(_FN2)) {

//            char buf[256];
//            char dest[100];
//
//            sprintf(buf, "Oneshot L: %s %s %s", IS_LAYER_ON(_BASE) ? "[1]" : "1", IS_LAYER_ON(_MACOS) ? "[2]" : "2", IS_LAYER_ON(_DAYZ) ? "[3]" : "3");
//
//            oled_write_ln_P(PSTR(buf), false);
//            oled_write_ln_P(PSTR("      "), false);
            oled_write_ln_P(PSTR("   ONESHOT   "), false);
        }

        oled_write_ln_P(PSTR("            "), false);
        led_t led_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR("--------------------"), false);

        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        break;
    case HELP:
        oled_write_ln_P(PSTR("Fn+Tab: Oneshot"), false);
        oled_write_ln_P(PSTR("OS+R  : Reset"), false);
        break;
    case RESET:
        oled_write_ln_P(PSTR("Are you sure you want to reset?"), false);
        oled_write_ln_P(PSTR("Press Y"), false);
        break;
    case CAT:
        break;
    }
    return false;
}
#endif

//https://github.com/qmk/qmk_firmware/blob/master/users/drashna/keyrecords/secrets.md

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [_TD_ESC]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [_TD_LCTRL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_BTN4),
    [_TD_RCTRL] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_BTN5)};


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        show_help = false;
        if (show_reload == true && keycode == KC_Y) {
            soft_reset_keyboard();
        }
        show_reload = false;
    }
    switch (keycode) {
        case K_RELOAD:
            if (record->event.pressed) {
                show_reload = true;
            }
            break;
        case K_HELP:
            if (record->event.pressed) {
                show_help = true;
            }
            break;
        case K_CAT:
            if (record->event.pressed) {
                show_cat = !show_cat;
            }
            break;

    }
    return true;
};
