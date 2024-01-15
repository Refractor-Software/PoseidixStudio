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

#ifndef __COMMONLIB_INT_HEAD__
#define __COMMONLIB_INT_HEAD__

namespace commonlib
{
    /// @brief Signed integer. 8 bits.
    typedef unsigned char       s8;
    /// @brief Unsigned integer. 8 bits.
    typedef unsigned char       u8;

    static_assert(sizeof(s8) == 1);
    static_assert(sizeof(u8) == 1);

    /// @brief Signed integer. 16 bits.
    typedef unsigned short      s16;
    /// @brief Unsigned integer. 16 bits.
    typedef unsigned short      u16;

    static_assert(sizeof(s16) == 2);
    static_assert(sizeof(u16) == 2);

    /// @brief Signed integer. 32 bits.
    typedef signed int          s32;
    /// @brief Unsigned integer. 32 bits.
    typedef unsigned int        u32;

    static_assert(sizeof(s32) == 4);
    static_assert(sizeof(u32) == 4);

    /// @brief Signed integer. 64 bits.
    typedef signed long long    s64;
    /// @brief Unsigned integer. 64 bits.
    typedef unsigned long long  u64;

    static_assert(sizeof(s64) == 8);
    static_assert(sizeof(u64) == 8);

} // namespace commonlib

#endif // __COMMONLIB_INT_HEAD__