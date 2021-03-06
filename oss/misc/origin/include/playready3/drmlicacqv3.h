/**@@@+++@@@@******************************************************************
**
** Microsoft (r) PlayReady (r)
** Copyright (c) Microsoft Corporation. All rights reserved.
**
***@@@---@@@@******************************************************************
*/

#ifndef __DRM_LICACQ_V3_H
#define __DRM_LICACQ_V3_H

#include <drmxmlsig.h>
#include <drmnoncestore.h>
#include <drmmanagertypes.h>

ENTER_PK_NAMESPACE;

/*
** Define the maximum number of rights
** that can be requested at one time.
*/
#define DRM_MAX_RIGHTS_REQUESTED    1

/*
** List of license response processing flags
*/
typedef enum _DRM_PROCESS_LIC_RESPONSE_FLAG
{
    DRM_PROCESS_LIC_RESPONSE_NO_FLAGS                  = 0x00000000L,      /* Opt-in response verification (default) */
    DRM_PROCESS_LIC_RESPONSE_SIGNATURE_NOT_REQUIRED    = 0x00000001L,      /* Signature is not required, i.e. Opt-out response verification */
} DRM_PROCESS_LIC_RESPONSE_FLAG;

/*
** There are 4 types of revocation data:
** PlayReadyApp, PlayReadyRuntime, WMDRMNET, and REV_INFO v2.
*/
#define MAX_REVLIST_INFO    4

/*
** Structure that stores the version information of
** a particular revocation list.
*/
typedef struct
{
    const DRM_GUID *m_poGUID;

    DRM_DWORD m_dwVersion;
} _REVLIST_INFO;

/*
** Structure that encapsulates the all the information
** needed for the license acquisition challenge XML.
** When the structure is first created, it should be
** zeroed to have all of its member fields initialized.
*/
typedef struct
{
    /* The content header. */
    DRM_CONST_STRING m_dstrContentHeader;

    /* Total number of rights ( actions ). */
    DRM_DWORD m_cRights;

    /* The client's current secure system time */
    DRM_DWORD m_dwClientTime;

    /*
    ** An array of DRM string pointer that
    ** defines a set of rights ( actions ).
    */
    const DRM_CONST_STRING **m_ppdstrRights;

    /* An array of revocation version information. */
    _REVLIST_INFO m_rgoRevListInfo[ MAX_REVLIST_INFO ];

    /* Size ( number of characters ) of a device certificate. */
    DRM_DWORD m_cchDeviceCert;

    /*
    ** Size ( number of characters ) of a collection of domain
    ** certificates to be passed to the server. Please note
    ** it includes the intermediate <CertificateChain>
    ** tags that separate neighboring domain certificates.
    */
    DRM_DWORD m_cchDomainCerts;

    /* The custom data string to be sent to the server. */
    DRM_ANSI_CONST_STRING m_dastrCustomData;

    /*
    ** Service ID extracted from the content header. Only those
    ** domain certificates that match the service ID will
    ** be incorporated into the challenge. This field is used
    ** only for domain bound content.
    */
    DRM_GUID m_oServiceID;

    /*
    ** Stack allocator used for getting temporary buffers.
    ** User should initialize with a buffer that is big enough.
    */
    DRM_STACK_ALLOCATOR_CONTEXT m_oStackAllocatorContext;

    /*
    ** Key information used for XML encryption/signature.
    ** User should call DRM_SOAPXML_InitXMLKey() to initialize.
    */
    DRM_XML_KEY m_oXMLKey;

    /* Pointer to a domain store context. */
    DRM_DOMAINSTORE_CONTEXT *m_poDomainStoreContext;

    /* Pointer to an OEM specific context. */
    DRM_VOID *m_poOEMContext;

    /* Nonce associated with the challenge. */
    DRM_ID m_oNonce;

    /* Pointer to a secure core context. */
    DRM_SECURECORE_CONTEXT *pSecureCoreCtx;
} DRM_LICCHLG_CONTEXT_V3;

typedef struct
{
    /* Pointer to a license evaluation context. */
    DRM_LICEVAL_CONTEXT *m_poLicEvalContext;

    /* Pointer to a license store context. */
    DRM_LICSTORE_CONTEXT *m_poLicStoreContext;

    /* Pointer to a data store context. */
    DRM_DST  *m_poDatastore;

    /* Pointer to a license buffer. */
    DRM_BYTE *m_pbLicenseBuffer;

    /* Size of license buffer (in bytes). */
    DRM_DWORD m_cbLicenseBufferSize;

    /* Pointer to a secure core context. */
    DRM_SECURECORE_CONTEXT *pSecureCoreCtx;

    /* Pointer to a global secure store context. */
    DRM_SECSTORE_CONTEXT *m_poSecStoreGlobalContext;

    /* Pointer to a revocation store context. */
    DRM_REVOCATIONSTORE_CONTEXT *m_poRevStoreContext;

    /* Pointer to a revocation data buffer */
    DRM_BYTE *m_pbRevocationBuffer;

    /* Size (in bytes) of revocation data buffer */
    DRM_DWORD m_cbRevocationBuffer;

    /* Pointer to a nonce store context. */
    DRM_NONCESTORE_CONTEXT *m_poNonceStoreContext;

    /* License response flag */
    DRM_PROCESS_LIC_RESPONSE_FLAG m_eLicResponseFlag;

} DRM_LICRESP_CONTEXT_V3;

/* Define the maximum size in bytes of a transaction ID. */
#define DRM_MAX_TRANSACTION_ID  100

/*
** Defines the maximum number of licenses can be contained
** in a single license response.
*/
#define DRM_MAX_LICENSE_ACK     20

/*
** Structure that is used to store the result of
** license processing and storage.
*/
typedef struct
{
    /* KID of the license. */
    DRM_KID m_oKID;

    /* LID of the license. */
    DRM_LID m_oLID;

    /* DRM result code of the processing and storage. */
    DRM_RESULT m_dwResult;

    /* Flag specifying post-processing behavior. */
    DRM_DWORD m_dwFlags;

} DRM_LICENSE_ACK;

/* Values for m_dwFlags */
#define DRM_LICENSE_ACK_FLAGS_EMBED 1


/* Enumeration of license protocols. */
typedef enum
{
    /* Unrecognized protocol. */
    eUnknownProtocol = 0,

    /* V2 protocol. */
    eV2Protocol,

    /* V3 protocol. */
    eV3Protocol

} DRM_LICENSE_PROTOCOL_TYPE;

/* Structure that encapsulates the license processing result. */
typedef struct
{
    /* __inout  Type of license protocol detected. */
    DRM_LICENSE_PROTOCOL_TYPE m_eType;

    /* __out    Buffer to store the transaction ID. */
    DRM_BYTE m_rgbTransactionID[ DRM_MAX_TRANSACTION_ID ];

    /*
    ** __out    Actual size in bytes of the transaction ID.
    **          Should <= DRM_MAX_TRANSACTION_ID.
    */
    DRM_DWORD m_cbTransactionID;

    /*
    ** __out    Array that contains license processing storage results.
    **          Not used if m_cMaxAcks > zero.  Refer to m_pAcks.
    */
    DRM_LICENSE_ACK m_rgoAcks[ DRM_MAX_LICENSE_ACK ];

    /*
    ** __inout  Pointer to a caller-allocated array that
    **          contains license processing storage results.
    **          Required if the number of licenses > DRM_MAX_LICENSE_ACK.
    **          If NULL, m_rgoAcks is used.
    **          Must be NULL or a valid pointer.
    **          Must be a valid pointer if m_cMaxAcks is non-zero.
    **          Must be NULL if m_cMaxAcks is zero.
    */
    DRM_LICENSE_ACK *m_pAcks;

    /*
    ** __in     Number of elements in m_pAcks.
    **          Must be zero if m_pAcks is NULL.
    **          Must be non-zero if m_pAcks is non-NULL.
    */
    DRM_DWORD m_cMaxAcks;

    /*
    ** __out    Actual number of initialized elements in m_rgoAcks or m_pAcks.
    **          Will be <= DRM_MAX_LICENSE_ACK if m_pAcks is NULL.
    **          Will be <= m_cMaxAcks if m_pAcks is non-NULL.
    **          If Drm_LicenseAcq_ProcessResponse succeeds OR it fails
    **          with DRM_E_LICACQ_TOO_MANY_LICENSES,
    **          then on output this member will be set to the number of
    **          licenses in the response (and can be arbitrarily large).
    **          In the failure case, this enables the caller to allocate
    **          a sufficiently large array, assign correct values to
    **          m_pAcks and m_cMaxAcks, and re-call
    **          Drm_LicenseAcq_ProcessResponse.
    */
    DRM_DWORD m_cAcks;

    /*
    ** __out    The LA batch ID associated with licenses extracted from the response.
    **          Will be filled only in case of In-memory only licenses.
    **          Value can be passed later to Drm_StoreMgmt_DeleteInMemoryLicenses
    **          to remove the associated licenses from the in memory license store
    */
    DRM_ID m_oBatchID;

    /* __out    Status code parsed from the server response. */
    DRM_RESULT m_dwResult;

} DRM_LICENSE_RESPONSE;

/*
** Internal functions but are called from other files.
*/
DRM_API DRM_RESULT DRM_CALL DRM_LA_ParseServiceID(
    __in  const DRM_CONST_STRING *f_pdstrContentHeader,
    __out       DRM_GUID         *f_pServiceID );

DRM_API DRM_RESULT DRM_CALL DRM_LA_ParseLicenseAcquisitionURL(
    __in                     const DRM_CONST_STRING *f_pdstrContentHeader,
    __in                           DRM_BOOL          f_fSilent,
    __out_ecount_opt( *f_pcchURL ) DRM_CHAR         *f_pchURL,
    __inout                        DRM_DWORD        *f_pcchURL );

DRM_API DRM_RESULT DRM_CALL DRM_LA_ProcessRevocationPackage(
    __inout     DRM_LICRESP_CONTEXT_V3 *f_poLicRespContext,
    __in  const DRM_ANSI_CONST_STRING  *f_pdastrResponse,
    __inout_opt DRM_REVLIST_ID_VALUES  *f_pRevListIDsCopy );

DRM_API DRM_RESULT DRM_CALL DRM_LA_GenerateChallengeV3(
    __in                                DRM_LICCHLG_CONTEXT_V3 *f_poLicChlgContext,
    __out_bcount_opt( *f_pcbChallenge ) DRM_BYTE               *f_pbChallenge,
    __inout                             DRM_DWORD              *f_pcbChallenge,
    __in_ecount( 1 )              const PUBKEY_P256            *f_poECC256PubKey );

DRM_API DRM_RESULT DRM_CALL DRM_LA_CheckForCustomData(
    __in_bcount( f_cbResponse ) const DRM_BYTE *f_pbResponse,
    __in                              DRM_DWORD f_cbResponse );

DRM_API DRM_RESULT DRM_CALL DRM_LA_ProcessResponseV3(
    __inout                                         DRM_APP_CONTEXT          *f_poAppContext,
    __in                                            DRM_LICRESP_CONTEXT_V3   *f_poLicRespContext,
    __in                                            DRM_ANSI_CONST_STRING    *f_pdastrResponse,
    __inout                                         DRM_LICENSE_RESPONSE     *f_poLicenseResponse,
    __out_ecount_part( *f_pcLicAcks, *f_pcLicAcks ) DRM_LICENSE_ACK          *f_poLicAcks,
    __inout                                         DRM_DWORD                *f_pcLicAcks );

DRM_API DRM_RESULT DRM_CALL DRM_LA_GenerateAckV3(
    __in_opt                            DRM_VOID                    *f_poOEMContext,
    __inout                             DRM_SECURECORE_CONTEXT      *f_pSecureCoreCtx,
    __in                                DRM_STACK_ALLOCATOR_CONTEXT *f_poStackAllocatorContext,
    __in                                DRM_LICENSE_RESPONSE        *f_poLicenseResponse,
    __out_bcount_opt( *f_pcbChallenge ) DRM_BYTE                    *f_pbChallenge,
    __inout                             DRM_DWORD                   *f_pcbChallenge,
    __in_ecount( 1 )              const PUBKEY_P256                 *f_poECC256PubKey);

DRM_API DRM_RESULT DRM_CALL DRM_LA_ValidateResponseId(
    __in_bcount( f_cbResponse )   const DRM_BYTE               *f_pbResponse,
    __in                          const DRM_DWORD               f_cbResponse,
    __in_bcount( f_cbDeviceId )   const DRM_BYTE               *f_pbDeviceId,
    __in                          const DRM_DWORD               f_cbDeviceId );

EXIT_PK_NAMESPACE;

#endif /* __DRM_LICACQ_V3_H */
