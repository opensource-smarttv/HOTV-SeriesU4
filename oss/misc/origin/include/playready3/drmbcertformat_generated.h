/**@@@+++@@@@******************************************************************
**
** Microsoft (r) PlayReady (r)
** Copyright (c) Microsoft Corporation. All rights reserved.
**
***@@@---@@@@******************************************************************
*/

/* This source was autogenerated by xbgen.
** DO NOT EDIT THIS SOURCE MANUALLY.
** If changes need to be applied update the XML and regenerate this source.
*/
/*
** This file defines the following generated formats
** DRM_BCERTFORMAT_CERT
** DRM_BCERTFORMAT_CERT_HEADER
** DRM_BCERTFORMAT_CHAIN
*/
#ifndef __BINCERT_H__
#define __BINCERT_H__ 1

ENTER_PK_NAMESPACE;

PREFAST_PUSH_DISABLE_EXPLAINED( __WARNING_POOR_DATA_ALIGNMENT_25021, "Ignore poor alignment of XBinary data structures" );

#define DRM_BCERTFORMAT_CURRENT_VERSION 1
#define DRM_BCERTFORMAT_PARSER_STACK_SIZE_MIN 1024
#define DRM_BCERTFORMAT_BUILDER_STACK_SIZE_MIN 1300
#define DRM_BCERTFORMAT_STACK_SIZE 4096
#define DRM_BCERTFORMAT_PARSER_STACK_SIZE_MAX (DRM_BCERTFORMAT_PARSER_STACK_SIZE_MIN * 8)
#define DRM_BCERTFORMAT_BUILDER_STACK_SIZE_MAX (DRM_BCERTFORMAT_BUILDER_STACK_SIZE_MIN * 8)
#define DRM_BCERTFORMAT_OBJTYPE_BASIC 0x0001
#define DRM_BCERTFORMAT_OBJTYPE_DOMAIN 0x0002
#define DRM_BCERTFORMAT_OBJTYPE_PC 0x0003
#define DRM_BCERTFORMAT_OBJTYPE_DEVICE 0x0004
#define DRM_BCERTFORMAT_OBJTYPE_FEATURE 0x0005
#define DRM_BCERTFORMAT_OBJTYPE_KEY 0x0006
#define DRM_BCERTFORMAT_OBJTYPE_MANUFACTURER 0x0007
#define DRM_BCERTFORMAT_OBJTYPE_SIGNATURE 0x0008
#define DRM_BCERTFORMAT_OBJTYPE_SILVERLIGHT 0x0009
#define DRM_BCERTFORMAT_OBJTYPE_METERING 0x000A
#define DRM_BCERTFORMAT_OBJTYPE_EXTDATASIGNKEY 0x000B
#define DRM_BCERTFORMAT_OBJTYPE_EXTDATACONTAINER 0x000C
#define DRM_BCERTFORMAT_OBJTYPE_EXTDATASIGNATURE 0x000D
#define DRM_BCERTFORMAT_OBJTYPE_EXTDATA_HWID 0x000E
#define DRM_BCERTFORMAT_OBJTYPE_SERVER 0x000F
#define DRM_BCERTFORMAT_OBJTYPE_SECURITY_VERSION 0x0010
#define DRM_BCERTFORMAT_OBJTYPE_SECURITY_VERSION_2 0x0011
#define DRM_BCERTFORMAT_UNKNOWN_OBJECT_ID 0xFFFD

typedef struct __tagDRM_BCERTFORMAT_KEY_TYPE
{
    DRM_BOOL             fValid;
    DRM_WORD             wType;
    DRM_WORD             wKeyLength;
    DRM_DWORD            dwFlags;
    DRM_XB_BYTEARRAY     xbbaKeyValue;
    DRM_XB_DWORDLIST     dwlKeyUsages;
    DRM_DWORD            dwUsageSet;
} DRM_BCERTFORMAT_KEY_TYPE;

typedef struct __tagDRM_BCERTFORMAT_EXTENDED_HEADER
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwVersion;
    DRM_DWORD     dwLength;
    DRM_DWORD     dwSignedLength;
} DRM_BCERTFORMAT_EXTENDED_HEADER;

typedef struct __tagDRM_BCERTFORMAT_CHAIN_EXTENDED_HEADER
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwVersion;
    DRM_DWORD     cbChain;
    DRM_DWORD     dwFlags;
    DRM_DWORD     cCerts;
} DRM_BCERTFORMAT_CHAIN_EXTENDED_HEADER;

typedef enum __tagDRM_BCERTFORMAT_CERT_TYPES
{
    DRM_BCERTFORMAT_BASIC_INFO_ENTRY_TYPE               = 0x1,
    DRM_BCERTFORMAT_DOMAIN_INFO_ENTRY_TYPE              = 0x2,
    DRM_BCERTFORMAT_PC_INFO_ENTRY_TYPE                  = 0x3,
    DRM_BCERTFORMAT_DEVICE_INFO_ENTRY_TYPE              = 0x4,
    DRM_BCERTFORMAT_FEATURE_INFO_ENTRY_TYPE             = 0x5,
    DRM_BCERTFORMAT_KEY_INFO_ENTRY_TYPE                 = 0x6,
    DRM_BCERTFORMAT_MANUFACTURER_INFO_ENTRY_TYPE        = 0x7,
    DRM_BCERTFORMAT_SIGNATURE_INFO_ENTRY_TYPE           = 0x8,
    DRM_BCERTFORMAT_SILVERLIGHT_INFO_ENTRY_TYPE         = 0x9,
    DRM_BCERTFORMAT_METERING_INFO_ENTRY_TYPE            = 0xA,
    DRM_BCERTFORMAT_EX_DATA_SIGKEY_INFO_ENTRY_TYPE      = 0xB,
    DRM_BCERTFORMAT_EXTENDED_DATA_CONTAINER_ENTRY_TYPE  = 0xC,
    DRM_BCERTFORMAT_EXT_DATA_SIG_INFO_ENTRY_TYPE        = 0xD,
    DRM_BCERTFORMAT_HWID_ENTRY_TYPE                     = 0xE,
    DRM_BCERTFORMAT_SERVER_TYPE_INFO_ENTRY_TYPE         = 0xF,
    DRM_BCERTFORMAT_SECURITY_VERSION_ENTRY_TYPE         = 0x10,
    DRM_BCERTFORMAT_SECURITY_VERSION2_ENTRY_TYPE        = 0x11,
    DRM_BCERTFORMAT_EXT_DATA_OBJECT_ENTRY_TYPE          = 0xFFFD,
} DRM_BCERTFORMAT_CERT_TYPES;
/* Count Includes XB_OBJECT_GLOBAL_HEADER */
#define DRM_BCERTFORMAT_CERT_TYPE_COUNT       19
#define DRM_BCERTFORMAT_CERT_FORMAT_ID        XB_DEFINE_DWORD_FORMAT_ID( 'C', 'E', 'R', 'T' )

typedef struct __tagDRM_BCERTFORMAT_BASIC_INFO
{
    DRM_BOOL             fValid;
    DRM_ID               certID;
    DRM_DWORD            dwSecurityLevel;
    DRM_DWORD            dwFlags;
    DRM_DWORD            dwType;
    DRM_XB_BYTEARRAY     xbbaDigestValue;
    DRM_DWORD            dwExpirationDate;
    DRM_ID               ClientID;
} DRM_BCERTFORMAT_BASIC_INFO;

typedef struct __tagDRM_BCERTFORMAT_DOMAIN_INFO
{
    DRM_BOOL             fValid;
    DRM_ID               ServiceID;
    DRM_ID               AccountID;
    DRM_DWORD            dwRevision;
    DRM_XB_BYTEARRAY     xbbaDomainUrl;
} DRM_BCERTFORMAT_DOMAIN_INFO;

typedef struct __tagDRM_BCERTFORMAT_PC_INFO
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwSecurityVersion;
} DRM_BCERTFORMAT_PC_INFO;

typedef struct __tagDRM_BCERTFORMAT_DEVICE_INFO
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwMaxLicenseSize;
    DRM_DWORD     dwMaxHeaderSize;
    DRM_DWORD     dwMaxLicenseChainDepth;
} DRM_BCERTFORMAT_DEVICE_INFO;

typedef struct __tagDRM_BCERTFORMAT_SILVERLIGHT_INFO
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwSecurityVersion;
    DRM_DWORD     dwPlatformID;
} DRM_BCERTFORMAT_SILVERLIGHT_INFO;

typedef struct __tagDRM_BCERTFORMAT_SERVER_TYPE_INFO
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwWarningStartDate;
} DRM_BCERTFORMAT_SERVER_TYPE_INFO;

typedef struct __tagDRM_BCERTFORMAT_METERING_INFO
{
    DRM_BOOL             fValid;
    DRM_ID               MeteringID;
    DRM_XB_BYTEARRAY     xbbaMeteringUrl;
} DRM_BCERTFORMAT_METERING_INFO;

typedef struct __tagDRM_BCERTFORMAT_SECURITY_VERSION
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwSecurityVersion;
    DRM_DWORD     dwPlatformID;
} DRM_BCERTFORMAT_SECURITY_VERSION;

typedef struct __tagDRM_BCERTFORMAT_SECURITY_VERSION2
{
    DRM_BOOL      fValid;
    DRM_DWORD     dwSecurityVersion;
    DRM_DWORD     dwPlatformID;
} DRM_BCERTFORMAT_SECURITY_VERSION2;

typedef struct __tagDRM_BCERTFORMAT_FEATURE_INFO
{
    DRM_BOOL             fValid;
    DRM_XB_DWORDLIST     dwlFeatures;
    DRM_DWORD            dwFeatureSet;
} DRM_BCERTFORMAT_FEATURE_INFO;

typedef struct __tagDRM_BCERTFORMAT_KEY_INFO
{
    DRM_BOOL                      fValid;
    DRM_DWORD                     cEntries;
    DRM_BCERTFORMAT_KEY_TYPE*     pHead;
} DRM_BCERTFORMAT_KEY_INFO;

typedef struct __tagDRM_BCERTFORMAT_MANUFACTURER_INFO
{
    DRM_BOOL             fValid;
    DRM_DWORD            dwFlags;
    DRM_XB_BYTEARRAY     xbbaManufacturerName;
    DRM_XB_BYTEARRAY     xbbaModelName;
    DRM_XB_BYTEARRAY     xbbaModelNumber;
} DRM_BCERTFORMAT_MANUFACTURER_INFO;

typedef struct __tagDRM_BCERTFORMAT_EX_DATA_SIGKEY_INFO
{
    DRM_BOOL             fValid;
    DRM_WORD             wType;
    DRM_WORD             wKeyLen;
    DRM_DWORD            dwFlags;
    DRM_XB_BYTEARRAY     xbbKeyValue;
} DRM_BCERTFORMAT_EX_DATA_SIGKEY_INFO;

typedef struct __tagDRM_BCERTFORMAT_SIGNATURE_INFO
{
    DRM_BOOL             fValid;
    DRM_WORD             wSignatureType;
    DRM_XB_BYTEARRAY     xbbaSignature;
    DRM_XB_BYTEARRAY     xbbaIssuerKey;
} DRM_BCERTFORMAT_SIGNATURE_INFO;

typedef struct __tagDRM_BCERTFORMAT_HWID
{
    DRM_BOOL             fValid;
    DRM_XB_BYTEARRAY     xbbaData;
} DRM_BCERTFORMAT_HWID;

typedef struct __tagDRM_BCERTFORMAT_EXT_DATA_SIG_INFO
{
    DRM_BOOL             fValid;
    DRM_WORD             wSignatureType;
    DRM_XB_BYTEARRAY     xbbaSignature;
} DRM_BCERTFORMAT_EXT_DATA_SIG_INFO;

typedef struct __tagDRM_BCERTFORMAT_EXTENDED_DATA_CONTAINER
{
    DRM_BOOL                              fValid;
    DRM_BCERTFORMAT_HWID                  HwidRecord;
    DRM_BCERTFORMAT_EXT_DATA_SIG_INFO     ExDataSignatureInformation;
    DRM_XB_UNKNOWN_OBJECT                *pExtendedData;
    DRM_XB_BYTEARRAY                      xbbaRawData;
} DRM_BCERTFORMAT_EXTENDED_DATA_CONTAINER;

typedef struct __tagDRM_BCERTFORMAT_CERT
{
    DRM_BOOL                                    fValid;
    DRM_BCERTFORMAT_EXTENDED_HEADER             HeaderData;
    DRM_BCERTFORMAT_BASIC_INFO                  BasicInformation;
    DRM_BCERTFORMAT_DOMAIN_INFO                 DomainInformation;
    DRM_BCERTFORMAT_PC_INFO                     PCInfo;
    DRM_BCERTFORMAT_DEVICE_INFO                 DeviceInformation;
    DRM_BCERTFORMAT_SILVERLIGHT_INFO            SilverlightInformation;
    DRM_BCERTFORMAT_SERVER_TYPE_INFO            ServerTypeInformation;
    DRM_BCERTFORMAT_METERING_INFO               MeteringInformation;
    DRM_BCERTFORMAT_SECURITY_VERSION            SecurityVersion;
    DRM_BCERTFORMAT_SECURITY_VERSION2           SecurityVersion2;
    DRM_BCERTFORMAT_FEATURE_INFO                FeatureInformation;
    DRM_BCERTFORMAT_KEY_INFO                    KeyInformation;
    DRM_BCERTFORMAT_MANUFACTURER_INFO           ManufacturerInformation;
    DRM_BCERTFORMAT_EX_DATA_SIGKEY_INFO         ExDataSigKeyInfo;
    DRM_BCERTFORMAT_SIGNATURE_INFO              SignatureInformation;
    DRM_BCERTFORMAT_EXTENDED_DATA_CONTAINER     ExDataContainer;
    DRM_XB_BYTEARRAY                            xbbaRawData;
} DRM_BCERTFORMAT_CERT;

DRM_EXPORT_VAR extern DRM_GLOBAL_CONST DRM_XB_FORMAT_DESCRIPTION s_DRM_BCERTFORMAT_CERT_FormatDescription[1];

typedef enum __tagDRM_BCERTFORMAT_CERT_HEADER_TYPES
{
    DRM_BCERTFORMAT_CHAIN_OFFSET_ENTRY_TYPE  = 0x2,
    DRM_BCERTFORMAT_CHAIN_INDEX_ENTRY_TYPE   = 0x3,
} DRM_BCERTFORMAT_CERT_HEADER_TYPES;
/* Count Includes XB_OBJECT_GLOBAL_HEADER */
#define DRM_BCERTFORMAT_CERT_HEADER_TYPE_COUNT       3
#define DRM_BCERTFORMAT_CERT_HEADER_FORMAT_ID        XB_DEFINE_DWORD_FORMAT_ID( 'C', 'E', 'R', 'T' )

typedef struct __tagDRM_BCERTFORMAT_CERT_HEADER
{
    DRM_BOOL                            fValid;
    DRM_BCERTFORMAT_EXTENDED_HEADER     HeaderData;
    DRM_DWORD                           dwOffset;
    DRM_DWORD                           dwIndex;
    DRM_XB_BYTEARRAY                    xbbaRawData;
} DRM_BCERTFORMAT_CERT_HEADER;

DRM_EXPORT_VAR extern DRM_GLOBAL_CONST DRM_XB_FORMAT_DESCRIPTION s_DRM_BCERTFORMAT_CERT_HEADER_FormatDescription[1];

typedef enum __tagDRM_BCERTFORMAT_CHAIN_TYPES
{
    DRM_BCERTFORMAT_CHAIN_CERT_HEADER_ENTRY_TYPE       = 0x2,
    DRM_BCERTFORMAT_CHIAN_SECURITY_VERSION_ENTRY_TYPE  = 0x3,
    DRM_BCERTFORMAT_CHIAN_PLATFORM_ID_ENTRY_TYPE       = 0x4,
    DRM_BCERTFORMAT_CHAIN_EXPIRATION_ENTRY_TYPE        = 0x5,
} DRM_BCERTFORMAT_CHAIN_TYPES;
/* Count Includes XB_OBJECT_GLOBAL_HEADER */
#define DRM_BCERTFORMAT_CHAIN_TYPE_COUNT       5
#define DRM_BCERTFORMAT_CHAIN_FORMAT_ID        XB_DEFINE_DWORD_FORMAT_ID( 'C', 'H', 'A', 'I' )

typedef struct __tagDRM_BCERTFORMAT_CHAIN_CERT_HEADER
{
    DRM_BOOL                         fValid;
    DRM_DWORD                        cEntries;
    DRM_BCERTFORMAT_CERT_HEADER*     pCertHeaders;
} DRM_BCERTFORMAT_CHAIN_CERT_HEADER;

typedef struct __tagDRM_BCERTFORMAT_CHAIN
{
    DRM_BOOL                                  fValid;
    DRM_BCERTFORMAT_CHAIN_EXTENDED_HEADER     Header;
    DRM_BCERTFORMAT_CHAIN_CERT_HEADER         Certificates;
    DRM_DWORD                                 dwSecurityVersion;
    DRM_DWORD                                 dwPlatformID;
    DRM_DWORD                                 dwExpiration;
    DRM_XB_BYTEARRAY                          xbbaRawData;
} DRM_BCERTFORMAT_CHAIN;

DRM_EXPORT_VAR extern DRM_GLOBAL_CONST DRM_XB_FORMAT_DESCRIPTION s_DRM_BCERTFORMAT_CHAIN_FormatDescription[1];

PREFAST_POP;

EXIT_PK_NAMESPACE;

#endif /* __BINCERT_H__ */
