/*******************
 * boot_screen.cpp *
 *******************/

/****************************************************************************
 *   Written By Mark Pelletier  2017 - Aleph Objects, Inc.                  *
 *   Written By Marcio Teixeira 2018 - Aleph Objects, Inc.                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <http://www.gnu.org/licenses/>.                              *
 ****************************************************************************/

#include "../config.h"

#if BOTH(LULZBOT_TOUCH_UI, JUNCTION_DEVIATION)

#include "screens.h"

using namespace FTDI;
using namespace ExtUI;
using namespace Theme;

void JunctionDeviationScreen::onRedraw(draw_mode_t what) {
  widgets_t w(what);
  w.precision(2);
  w.units(GET_TEXT_F(UNITS_MM));
  w.heading(GET_TEXT_F(JUNC_DEVIATION));
  w.color(other) .adjuster( 2, PSTR(""), getJunctionDeviation_mm() );
  w.increments();
}

bool JunctionDeviationScreen::onTouchHeld(uint8_t tag) {
  const float increment = getIncrement();
  switch (tag) {
    case  2: UI_DECREMENT(JunctionDeviation_mm); break;
    case  3: UI_INCREMENT(JunctionDeviation_mm); break;
    default:
      return false;
  }
  SaveSettingsDialogBox::settingsChanged();
  return true;
}

#endif // LULZBOT_TOUCH_UI
