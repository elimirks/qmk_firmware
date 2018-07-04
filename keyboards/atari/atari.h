/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#ifndef ATARI_H
#define ATARI_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
// Reference: http://members.casema.nl/hhaydn/howel/logic/burched/b5_800xl_kbd.htm
#define KEYMAP( \
	k10, k11, k12, k13, k14, k15, k17, k07, k05, k04, k03, k02, k01, k00, k08, \
	k30, k31, k32, k33, k34, k35, k37, k27, k25, k24, k23, k22, k21, k20,      \
	k48, k51, k52, k53, k54, k55, k56, k46, k45, k44, k43, k42, k41, k50,      \
	k78, k71, k72, k73, k74, k75, k67, k65, k64, k63, k62,      k61,           \
													 k66,         k76                                  \
) \
{ \
  { k00,   k01, k02, k03, k04, k05, KC_NO, k07,   k08   }, \
  { k10,   k11, k12, k13, k14, k15, KC_NO, k17,   KC_NO }, \
  { k20,   k21, k22, k23, k24, k25, KC_NO, k27,   KC_NO }, \
  { k30,   k31, k32, k33, k34, k35, KC_NO, k37,   KC_NO }, \
  { KC_NO, k41, k42, k43, k44, k45, k46,   KC_NO, k48   }, \
  { k50,   k51, k52, k53, k54, k55, k56,   KC_NO, KC_NO }, \
  { KC_NO, k61, k62, k63, k64, k65, k66,   k67,   KC_NO }, \
  { KC_NO, k71, k72, k73, k74, k75, k76,   KC_NO, k78   }  \
}

#endif

     
