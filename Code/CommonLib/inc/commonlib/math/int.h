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

#include <cstdint>

namespace commonlib {

    /// @brief 8-bit unsigned integer.
    using u8    = std::uint8_t;
    /// @brief 16-bit unsigned integer.
    using u16   = std::uint16_t;
    /// @brief 32-bit unsigned integer.
    using u32   = std::uint32_t;
    /// @brief 64-bit unsigned integer.
    using u64   = std::uint64_t;

    /// @brief 8-bit signed integer.
    using s8    = std::int8_t;
    /// @brief 16-bit signed integer.
    using s16   = std::int16_t;
    /// @brief 32-bit signed integer.
    using s32   = std::int32_t;
    /// @brief 64-bit signed integer.
    using s64   = std::int64_t;

} // namespace commonlib

#endif // __COMMONLIB_INT_HEAD__