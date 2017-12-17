/*
 *      Copyright (C) 2016-2018 Team Kodi
 *      http://kodi.tv
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
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <stdint.h>
#include <vector>

namespace LIBRETRO
{
  class CAudioStream;

  class CSingleFrameAudio
  {
  public:
    CSingleFrameAudio(CAudioStream* audioStream);

    void AddFrame(int16_t left, int16_t right);

  private:
    CAudioStream* const  m_audioStream;
    std::vector<int16_t> m_data;
  };
}
