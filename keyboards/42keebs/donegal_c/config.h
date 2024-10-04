/*

THIS IS FOR THE GINGERHAM FORK BY GIPETTO
Copyright 2019 Yiancar

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#include "config_common.h"

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

/* A Custom matrix.c is used to poll the port expander C6 shows that the pins are hardwired there */
#define MATRIX_ROW_PINS { B1, B2, B3, B4, D5, D6, D7, B0, C4 }
#define MATRIX_COL_PINS { D0, D1, D4, B5, C3, C2, C1, C0 }

/* COL2ROW, ROW2COL*/

//#define NO_UART 1

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

//#define WAIT_FOR_USB

#define NO_USB_STARTUP_CHECK