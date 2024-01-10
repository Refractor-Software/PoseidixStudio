/// CommonLib
/// Copyright (C) 2024 William Pimentel-Tonche
///
/// CommonLib is free software; you can redistribute it and/or
/// modify it under the terms of the GNU Lesser General Public
/// License as published by the Free Software Foundation; either
/// version 2.1 of the License, or (at your option) any later version.
///
/// CommonLib is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Lesser General Public License for more details.
///
/// You should have received a copy of the GNU Lesser General Public
/// License along with CommonLib; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
/// USA

#ifndef __COMMONLIB_FPREG_HEAD__
#define __COMMONLIB_FPREG_HEAD__

namespace commonlib::math {

    /// @brief 128-bit floating-point register.
    struct fp4
    {
        union
        {
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };

            float rg[4];
        };
    };

    

} // namespace commonlib::math

#endif // __COMMONLIB_FPREG_HEAD__