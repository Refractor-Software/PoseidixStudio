/*/
 * Copyright William Pimentel-Tonche. All rights reserved.
/*/
#pragma once

/// @file       Id.hxx
/// @brief      Implements an integral ID, used to efficiently refer to
///             an entity's transform, parent, or data.

#include <Common/Types.hxx>

namespace rpf::engine::common_id {

using type = u32;

    namespace detail {

    /// @brief  Number of bits in the ID to allocate to the generation.
    constexpr type gen_bits = (sizeof(type) * 8) / 4;
    /// @brief  Number of bits in the ID to allocate to the index.
    constexpr type idx_bits = (sizeof(type) * 8) - gen_bits;

    /// @brief  Invalid generation (and mask for ID's generation bits).
    constexpr type gen_mask = (type{1} << gen_bits) - type{1};
    /// @brief  Invalid index (and mask for ID's index bits).
    constexpr type idx_mask = (type{1} << idx_bits) - type{1};
    /// @brief  Invalid ID (and mask for ID as a whole).
    constexpr type id_mask  = static_cast<type>(-1);

    /// @brief  Maximum number of valid generations given gen_bits.
    constexpr type gen_max  = gen_mask - 1;
    /// @brief  Maximum number of valid indices given idx_bits.
    constexpr type idx_max  = idx_mask - 1;

    } // namespace detail

inline bool
is_valid(type in_id)
{
    return in_id != detail::id_mask;
}

inline type
index(type in_id)
{
    return in_id & detail::idx_mask;
}

inline type
generation(type in_id)
{
    return (in_id >> detail::idx_bits) & detail::gen_mask;
}

inline type
increment_gen(type in_id)
{
    const type loc_gen = common_id::generation(in_id) + 1;
    return common_id::index(in_id) | (loc_gen << detail::idx_bits);
}

} // namespace rpf::engine::id