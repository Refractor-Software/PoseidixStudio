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

#ifndef __COMMONLIB_HAL_PLATFORM_HEAD__
#define __COMMONLIB_HAL_PLATFORM_HEAD__

/// @brief This uses simplified platform, compiler, and architecture
/// checks inspired by on (but not copied verbatim from) GLM.

#define CLB_PFM_NULL            0
#define CLB_PFM_WIN             1
#define CLB_PFM_LNX             2
#define CLB_PFM_APL             3
#define CLB_PFM_ANDR            4

#if     defined(_WIN32)
#   define CLB_PLATFORM CLB_PFM_WIN
#elif   defined(__linux)
#   define CLB_PLATFORM CLB_PFM_LNX
#elif   defined(__APPLE__)
#   define CLB_PLATFORM CLB_PFM_APL
#elif   defined(__ANDROID__)
#   define CLB_PLATFORM CLB_PFM_ANDR
#else
#   define CLB_PLATFORM CLB_PFM_NULL
#endif

#define CLB_CMP_NULL            0

#define CLB_CMP_MSVC            1
#define CLB_CMP_CLANG           2
#define CLB_CMP_GCC             3

#if     defined(__clang__)
#   define CLB_COMPILER CLB_CMP_CLANG
#elif   defined(_MSC_VER)
#   define CLB_COMPILER CLB_CMP_MSVC
#elif   defined(__GNUC__)
#   define CLB_COMPILER CLB_CMP_GCC
#else
#   define CLB_COMPILER CLB_CMP_NULL
#endif

#endif // __COMMONLIB_GLM_FWD_HEAD__

#define CLB_ARCH_NULL           0
#define CLB_ARCH_X86            1
#define CLB_ARCH_ARM            2
#define CLB_ARCH_ARM64          3

#if defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86) || defined(__i386__)
#   define CLB_ARCH CLB_ARCH_X86
#elif defined(__arm__) || defined(_M_ARM64)
#   define CLB_ARCH CLB_ARCH_ARM
#elif defined(__ARM_ARCH) && (__ARM_ARCH >= 8)
#   define CLB_ARCH CLB_ARCH_ARM64
#else
#   define CLB_ARCH CLB_ARCH_NULL
#endif