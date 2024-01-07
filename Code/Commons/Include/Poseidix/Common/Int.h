/// Poseidix Studio
/// Copyright (C) 2024 Poseidix Software
///
/// Poseidix Studio is free software; you can redistribute it and/or
/// modify it under the terms of the GNU Lesser General Public
/// License as published by the Free Software Foundation; either
/// version 2.1 of the License, or (at your option) any later version.
///
/// Poseidix Studio is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Lesser General Public License for more details.
///
/// You should have received a copy of the GNU Lesser General Public
/// License along with Poseidix Studio; if not, write to the Free Software
/// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
/// USA

#ifndef __POSEIDIX_COMMON_INT_HEAD__
#define __POSEIDIX_COMMON_INT_HEAD__

#include <cstdint>

namespace Poseidix::Common
{
    using u8_t      = std::uint8_t;
    using u16_t     = std::uint16_t;
    using u32_t     = std::uint32_t;
    using u64_t     = std::uint64_t;

    using s8_t      = std::int8_t;
    using s16_t     = std::int16_t;
    using s32_t     = std::int32_t;
    using s64_t     = std::int64_t;

    using f32_t     = float;
    using f64_t     = double;

    using ch16_t    =
    #ifdef _WIN32
        wchar_t;
    #else
        char16_t
    #endif
    ;
}

#endif // __POSEIDIX_COMMON_INT_HEAD__