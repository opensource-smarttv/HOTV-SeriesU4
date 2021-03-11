/**@@@+++@@@@******************************************************************
**
** Microsoft (r) PlayReady (r)
** Copyright (c) Microsoft Corporation. All rights reserved.
**
***@@@---@@@@******************************************************************
*/

/*
** This file includes the #defines normally set by a profile.
** It should be #included at the top of drmfeatures.h if you
** are not using the provided .mk files.
*/

#ifndef __DRMPROFILEOEMPLAYONLYMK_H__
#define __DRMPROFILEOEMPLAYONLYMK_H__

/********************************************************************************
**
** MICROSOFT INTERNAL PROFILE
** This profile, in spite of its name, is included as part of the PK MSI
** for Microsoft-internal reasons.  You should NOT use this profile.
**
********************************************************************************/
#ifndef DRM_BUILD_PROFILE
#define DRM_BUILD_PROFILE 11
#endif /* DRM_BUILD_PROFILE */

#ifndef DRM_ACTIVATION_PLATFORM
#define DRM_ACTIVATION_PLATFORM 0
#endif /* DRM_ACTIVATION_PLATFORM */

#ifndef DRM_SUPPORT_FILE_LOCKING
#define DRM_SUPPORT_FILE_LOCKING 0
#endif /* DRM_SUPPORT_FILE_LOCKING */

#ifndef DRM_SUPPORT_MULTI_THREADING
#define DRM_SUPPORT_MULTI_THREADING 0
#endif /* DRM_SUPPORT_MULTI_THREADING */

#ifndef DRM_SUPPORT_ECCPROFILING
#define DRM_SUPPORT_ECCPROFILING 1
#endif /* DRM_SUPPORT_ECCPROFILING */

#ifndef DRM_SUPPORT_INLINEDWORDCPY
#define DRM_SUPPORT_INLINEDWORDCPY 0
#endif /* DRM_SUPPORT_INLINEDWORDCPY */

#ifndef DRM_SUPPORT_DATASTORE_PREALLOC
#define DRM_SUPPORT_DATASTORE_PREALLOC 1
#endif /* DRM_SUPPORT_DATASTORE_PREALLOC */

#ifndef DRM_SUPPORT_REACTIVATION
#define DRM_SUPPORT_REACTIVATION 0
#endif /* DRM_SUPPORT_REACTIVATION */

#ifndef DRM_SUPPORT_NATIVE_64BIT_TYPES
#define DRM_SUPPORT_NATIVE_64BIT_TYPES 1
#endif /* DRM_SUPPORT_NATIVE_64BIT_TYPES */

#ifndef DRM_SUPPORT_FORCE_ALIGN
#define DRM_SUPPORT_FORCE_ALIGN 0
#endif /* DRM_SUPPORT_FORCE_ALIGN */

#ifndef DRM_SUPPORT_ASSEMBLY
#define DRM_SUPPORT_ASSEMBLY 1
#endif /* DRM_SUPPORT_ASSEMBLY */

#ifndef DRM_SUPPORT_PRECOMPUTE_GTABLE
#define DRM_SUPPORT_PRECOMPUTE_GTABLE 0
#endif /* DRM_SUPPORT_PRECOMPUTE_GTABLE */

/********************************************************************************
**
** Enabling DRM_SUPPORT_SECUREOEMHAL has the following effects.
** 1. Key-material functionality that cannot be supported by the secure HAL is completely removed from the HAL (via if / endif).
** 2. Feature areas which cannot be supported with a secure HAL will fail to compile.
** These will put your system into a more "secure" mode where there is a smaller attack surface area in exchange for fewer supported features.
** Note: You may need to explicitly remove the failing feature areas from your build system to compile successfully.
** Note: Microsoft makes no guarantees about the security of the "secure" HAL.
** Note: The PK licensee is still responsible for following the PlayReady Compliance and Robustness Rules.
**
********************************************************************************/
#ifndef DRM_SUPPORT_SECUREOEMHAL
#define DRM_SUPPORT_SECUREOEMHAL 1
#endif /* DRM_SUPPORT_SECUREOEMHAL */

/********************************************************************************
**
** Enabling DRM_SUPPORT_SECUREOEMHAL_PLAY_ONLY_VIA_PROFILE has the following effect.
** 1. Key-material functionality that is not required by the secure HAL is completely removed from the HAL (via if / endif).
** This will put your system into a more "secure" mode where there is a smaller attack surface area in exchange for fewer supported features.
** Note: Microsoft makes no guarantees about the security of the "secure" HAL.
** Note: The PK licensee is still responsible for following the PlayReady Compliance and Robustness Rules.
**
********************************************************************************/
#ifndef DRM_SUPPORT_SECUREOEMHAL_PLAY_ONLY
#define DRM_SUPPORT_SECUREOEMHAL_PLAY_ONLY 1
#endif /* DRM_SUPPORT_SECUREOEMHAL_PLAY_ONLY */

/********************************************************************************
**
** Refer to comments in DrmOverrideFeatureDefaults.mk for details on
** each DRM_SUPPORT_TEE option and what it means.
**
********************************************************************************/
#ifndef DRM_SUPPORT_TEE
#define DRM_SUPPORT_TEE 2
#endif /* DRM_SUPPORT_TEE */

#ifndef DRM_SUPPORT_TRACING
#define DRM_SUPPORT_TRACING 0
#endif /* DRM_SUPPORT_TRACING */

#ifndef _DATASTORE_WRITE_THRU
#define _DATASTORE_WRITE_THRU 1
#endif /* _DATASTORE_WRITE_THRU */

#ifndef _ADDLICENSE_WRITE_THRU
#define _ADDLICENSE_WRITE_THRU 0
#endif /* _ADDLICENSE_WRITE_THRU */

#ifndef DRM_HDS_COPY_BUFFER_SIZE
#define DRM_HDS_COPY_BUFFER_SIZE 32768
#endif /* DRM_HDS_COPY_BUFFER_SIZE */

#ifndef DRM_SUPPORT_TOOLS_NET_IO
#define DRM_SUPPORT_TOOLS_NET_IO 0
#endif /* DRM_SUPPORT_TOOLS_NET_IO */

#ifndef DRM_TEST_SUPPORT_ACTIVATION
#define DRM_TEST_SUPPORT_ACTIVATION 0
#endif /* DRM_TEST_SUPPORT_ACTIVATION */

#ifndef USE_PK_NAMESPACES
#define USE_PK_NAMESPACES 0
#endif /* USE_PK_NAMESPACES */

#ifndef DRM_INCLUDE_PK_NAMESPACE_USING_STATEMENT
#define DRM_INCLUDE_PK_NAMESPACE_USING_STATEMENT 0
#endif /* DRM_INCLUDE_PK_NAMESPACE_USING_STATEMENT */

#ifndef DRM_KEYFILE_VERSION
#define DRM_KEYFILE_VERSION 3
#endif /* DRM_KEYFILE_VERSION */

#ifndef DRM_NO_OPT
#define DRM_NO_OPT 0
#endif /* DRM_NO_OPT */


#endif /* __DRMPROFILEOEMPLAYONLYMK_H__ */
