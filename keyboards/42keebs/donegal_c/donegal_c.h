/* Copyright 2019 Yiancar
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

#pragma once

#define XXX KC_NO

#include "quantum.h"

// k<row><col>
#define LAYOUT_all( \
    k300, k101, k001, k002, k102, k003, k103, k004, k104, k005, k105, k006, k106, k007, k107, \
    k200, k201, k301, k202, k302, k203, k303, k204, k304, k205, k305, k206, k207, k407, \
    k100, k401, k501, k402, k502, k403, k503, k404, k504, k405, k306, k406, k307,   \
    k400, k500, k000, k601, k602, k702, k603, k604, k704, k505, k605, k506, k507, k707,  \
    k600, k700, k701,       k802, k703, k804,       k705, k606, k706, k607 \
) { \
    {k000, k001, k002, k003, k004, k005, k006, k007}, \
    {k100, k101, k102, k103, k104, k105, k106, k107}, \
    {k200, k201, k202, k203, k204, k205, k206, k207}, \
    {k300, k301, k302, k303, k304, k305, k306, k307}, \
    {k400, k401, k402, k403, k404, k405, k406, k407},  \
	{k500, k501, k502, k503, k504, k505, k506, k507}, \
	{k600, k601, k602, k603, k604, k605, k606, k607}, \
	{k700, k701, k702, k703, k704, k705, k706, k707}, \
	{XXX,  XXX,  k802, XXX,  k804, XXX,  XXX,  XXX} \
}

#define LAYOUT_60_ansi( \
    k300, k101, k001, k002, k102, k003, k103, k004, k104, k005, k105, k006, k106, k007, \
    k200, k201, k301, k202, k302, k203, k303, k204, k304, k205, k305, k206, k207, k407, \
    k100, k401, k501, k402, k502, k403, k503, k404, k504, k405, k306, k406, k307,   \
    k400,       k000, k601, k602, k702, k603, k604, k704, k505, k605, k506,       k707,  \
    k600, k700, k701,             k703,             k705, k606, k706, k607 \
) { \
    {k000, k001, k002, k003, k004, k005, k006, k007}, \
    {k100, k101, k102, k103, k104, k105, k106, XXX}, \
    {k200, k201, k202, k203, k204, k205, k206, k207}, \
    {k300, k301, k302, k303, k304, k305, k306, k307}, \
    {k400, k401, k402, k403, k404, k405, k406, k407},  \
	{XXX,  k501, k502, k503, k504, k505, k506, XXX}, \
	{k600, k601, k602, k603, k604, k605, k606, k607}, \
	{k700, k701, k702, k703, k704, k705, k706, k707}, \
	{XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX} \
}
