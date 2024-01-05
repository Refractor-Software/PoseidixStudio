/*/
 * Copyright William Pimentel-Tonche. All rights reserved.
/*/
#pragma once

#include <Common/Types.hxx>

namespace rpf::engine::math::quat {

struct type final
{
    union
    {
        struct
        {
            f32 x_;
            f32 y_;
            f32 z_;
            f32 w_;
        };

        f32 xyzw_[4];
    };
};

} // namespace rpf::engine::math