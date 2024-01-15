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

#ifndef     __COMMONLIB_MATH_VECBASE_HEAD__
#define     __COMMONLIB_MATH_VECBASE_HEAD__

#include <commonlib/math/detail/config.hxx>

namespace commonlib
{
namespace math
{
    template <length_t len_v, typename val_t> struct vec
    {
        typedef length_t    length_type;
        typedef val_t       value_type;
    };
}
// namespace math
}
// namespace commonlib

#endif //   __COMMONLIB_MATH_VECBASE_HEAD__