/*/
 * Copyright William Pimentel-Tonche. All rights reserved.
/*/
#pragma once

#include <Common/Types.hxx>

namespace rpf::engine {

// forward declarations
struct id;
struct transform;
struct transform_init_info;

void create_transform(const transform_init_info *init_info);

transform *get_transform(const common_id *in_id);

}