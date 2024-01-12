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

#ifndef __COMMONLIB_FLT16_HEAD__
#define __COMMONLIB_FLT16_HEAD__

#include <commonlib/math/int.h>
#include <commonlib/math/flt.h>

#include <cstring>

namespace commonlib {

    typedef struct f16
    {
        union
        {
            struct
            {
                u16 mantissa : 10;
                u16 exponent : 5;
                u16 sign : 1;
            };

            u16 val;
        };
    }
    f16;

    f32 f16_to_f32(f16 in_f)
    {
        u32 as_u32 = 0;
        std::memcpy(&as_u32, &in_f.val, sizeof(as_u32));
        // This is super very extremely not safe but we're doing it anyway
        return *reinterpret_cast<f32*>(&as_u32);
    }

} // namespace commonlib

#endif // __COMMONLIB_FLT16_HEAD__