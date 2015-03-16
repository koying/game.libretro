/*
 *      Copyright (C) 2015 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "kodi/xbmc_game_types.h"

#include <stdint.h>

struct retro_input_descriptor;

namespace LIBRETRO
{
  typedef unsigned int libretro_device_t;
  typedef uint64_t     libretro_device_caps_t;

  class CInputManager
  {
  public:
    static CInputManager& Get(void);

    libretro_device_caps_t GetDeviceCaps(void);

    libretro_device_t UpdatePort(unsigned int port, bool bPortConnected);

    void EnableSource(bool bEnabled, unsigned int port, GAME_INPUT_EVENT_SOURCE source, unsigned int index);

    void InputEvent(unsigned int port, const game_input_event& event);

    void SetInputDescriptors(const retro_input_descriptor* descriptors);

    bool DigitalButtonState(unsigned int port, unsigned int index);
    bool AnalogStickState(unsigned int port, unsigned int index, float& x, float& y);
    bool AccelerometerState(unsigned int port, unsigned int index, float& x, float& y, float& z);
    int16_t MouseDeltaX(unsigned int port);
    int16_t MouseDeltaY(unsigned int port);

  private:
    CInputManager(void) { }
  };
}