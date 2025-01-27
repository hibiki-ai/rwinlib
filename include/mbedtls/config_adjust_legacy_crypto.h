/**
 * \file mbedtls/config_adjust_legacy_crypto.h
 * \brief Adjust legacy configuration configuration
 *
 * This is an internal header. Do not include it directly.
 *
 * Automatically enable certain dependencies. Generally, MBEDTLS_xxx
 * configurations need to be explicitly enabled by the user: enabling
 * MBEDTLS_xxx_A but not MBEDTLS_xxx_B when A requires B results in a
 * compilation error. However, we do automatically enable certain options
 * in some circumstances. One case is if MBEDTLS_xxx_B is an internal option
 * used to identify parts of a module that are used by other module, and we
 * don't want to make the symbol MBEDTLS_xxx_B part of the public API.
 * Another case is if A didn't depend on B in earlier versions, and we
 * want to use B in A but we need to preserve backward compatibility with
 * configurations that explicitly activate MBEDTLS_xxx_A but not
 * MBEDTLS_xxx_B.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */
#ifndef MBEDTLS_CONFIG_ADJUST_LEGACY_CRYPTO_H
#define MBEDTLS_CONFIG_ADJUST_LEGACY_CRYPTO_H 
#if !defined(MBEDTLS_CONFIG_FILES_READ)
#error "Do not include mbedtls/config_adjust_*.h manually! This can lead to problems, " \
    "up to and including runtime errors such as buffer overflows. " \
    "If you're trying to fix a complaint from check_config.h, just remove " \
    "it from your configuration file: since Mbed TLS 3.0, it is included " \
    "automatically at the right point."
#endif
#if defined(__MINGW32__) || (defined(_MSC_VER) && _MSC_VER <= 1900)
#if !defined(MBEDTLS_PLATFORM_SNPRINTF_ALT) && \
    !defined(MBEDTLS_PLATFORM_SNPRINTF_MACRO)
#define MBEDTLS_PLATFORM_SNPRINTF_ALT 
#endif
#if !defined(MBEDTLS_PLATFORM_VSNPRINTF_ALT) && \
    !defined(MBEDTLS_PLATFORM_VSNPRINTF_MACRO)
#define MBEDTLS_PLATFORM_VSNPRINTF_ALT 
#endif
#endif
#if defined(MBEDTLS_PSA_CRYPTO_C) && \
    (defined(MBEDTLS_PSA_BUILTIN_ALG_STREAM_CIPHER) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CTR) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CFB) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_OFB) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_ECB_NO_PADDING) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CBC_NO_PADDING) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CBC_PKCS7) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CCM_STAR_NO_TAG) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_CMAC))
#define MBEDTLS_CIPHER_C 
#endif
#if defined(MBEDTLS_MD_C)
#define MBEDTLS_MD_LIGHT 
#endif
#if defined(MBEDTLS_ECJPAKE_C) || \
    defined(MBEDTLS_PEM_PARSE_C) || \
    defined(MBEDTLS_ENTROPY_C) || \
    defined(MBEDTLS_PK_C) || \
    defined(MBEDTLS_PKCS12_C) || \
    defined(MBEDTLS_RSA_C) || \
    defined(MBEDTLS_SSL_TLS_C) || \
    defined(MBEDTLS_X509_USE_C) || \
    defined(MBEDTLS_X509_CREATE_C)
#define MBEDTLS_MD_LIGHT 
#endif
#if defined(MBEDTLS_MD_LIGHT)
#if defined(MBEDTLS_PSA_CRYPTO_C)
#if defined(MBEDTLS_PSA_ACCEL_ALG_MD5)
#define MBEDTLS_MD_CAN_MD5 
#define MBEDTLS_MD_MD5_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA_1)
#define MBEDTLS_MD_CAN_SHA1 
#define MBEDTLS_MD_SHA1_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA_224)
#define MBEDTLS_MD_CAN_SHA224 
#define MBEDTLS_MD_SHA224_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA_256)
#define MBEDTLS_MD_CAN_SHA256 
#define MBEDTLS_MD_SHA256_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA_384)
#define MBEDTLS_MD_CAN_SHA384 
#define MBEDTLS_MD_SHA384_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA_512)
#define MBEDTLS_MD_CAN_SHA512 
#define MBEDTLS_MD_SHA512_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_RIPEMD160)
#define MBEDTLS_MD_CAN_RIPEMD160 
#define MBEDTLS_MD_RIPEMD160_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA3_224)
#define MBEDTLS_MD_CAN_SHA3_224 
#define MBEDTLS_MD_SHA3_224_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA3_256)
#define MBEDTLS_MD_CAN_SHA3_256 
#define MBEDTLS_MD_SHA3_256_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA3_384)
#define MBEDTLS_MD_CAN_SHA3_384 
#define MBEDTLS_MD_SHA3_384_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_ALG_SHA3_512)
#define MBEDTLS_MD_CAN_SHA3_512 
#define MBEDTLS_MD_SHA3_512_VIA_PSA 
#define MBEDTLS_MD_SOME_PSA 
#endif
#endif
#if defined(MBEDTLS_MD5_C)
#define MBEDTLS_MD_CAN_MD5 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA1_C)
#define MBEDTLS_MD_CAN_SHA1 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA224_C)
#define MBEDTLS_MD_CAN_SHA224 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA256_C)
#define MBEDTLS_MD_CAN_SHA256 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA384_C)
#define MBEDTLS_MD_CAN_SHA384 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA512_C)
#define MBEDTLS_MD_CAN_SHA512 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_SHA3_C)
#define MBEDTLS_MD_CAN_SHA3_224 
#define MBEDTLS_MD_CAN_SHA3_256 
#define MBEDTLS_MD_CAN_SHA3_384 
#define MBEDTLS_MD_CAN_SHA3_512 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#define MBEDTLS_MD_CAN_RIPEMD160 
#define MBEDTLS_MD_SOME_LEGACY 
#endif
#endif
#if defined(MBEDTLS_PSA_CRYPTO_C)
#if defined(MBEDTLS_PSA_ACCEL_KEY_TYPE_AES)
#define MBEDTLS_BLOCK_CIPHER_AES_VIA_PSA 
#define MBEDTLS_BLOCK_CIPHER_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_KEY_TYPE_ARIA)
#define MBEDTLS_BLOCK_CIPHER_ARIA_VIA_PSA 
#define MBEDTLS_BLOCK_CIPHER_SOME_PSA 
#endif
#if defined(MBEDTLS_PSA_ACCEL_KEY_TYPE_CAMELLIA)
#define MBEDTLS_BLOCK_CIPHER_CAMELLIA_VIA_PSA 
#define MBEDTLS_BLOCK_CIPHER_SOME_PSA 
#endif
#endif
#if defined(MBEDTLS_AES_C)
#define MBEDTLS_BLOCK_CIPHER_AES_VIA_LEGACY 
#endif
#if defined(MBEDTLS_ARIA_C)
#define MBEDTLS_BLOCK_CIPHER_ARIA_VIA_LEGACY 
#endif
#if defined(MBEDTLS_CAMELLIA_C)
#define MBEDTLS_BLOCK_CIPHER_CAMELLIA_VIA_LEGACY 
#endif
#if defined(MBEDTLS_BLOCK_CIPHER_AES_VIA_PSA) || \
    defined(MBEDTLS_BLOCK_CIPHER_AES_VIA_LEGACY)
#define MBEDTLS_BLOCK_CIPHER_CAN_AES 
#endif
#if defined(MBEDTLS_BLOCK_CIPHER_ARIA_VIA_PSA) || \
    defined(MBEDTLS_BLOCK_CIPHER_ARIA_VIA_LEGACY)
#define MBEDTLS_BLOCK_CIPHER_CAN_ARIA 
#endif
#if defined(MBEDTLS_BLOCK_CIPHER_CAMELLIA_VIA_PSA) || \
    defined(MBEDTLS_BLOCK_CIPHER_CAMELLIA_VIA_LEGACY)
#define MBEDTLS_BLOCK_CIPHER_CAN_CAMELLIA 
#endif
#if (defined(MBEDTLS_GCM_C) || defined(MBEDTLS_CCM_C)) && \
    (!defined(MBEDTLS_CIPHER_C) || defined(MBEDTLS_BLOCK_CIPHER_SOME_PSA))
#define MBEDTLS_BLOCK_CIPHER_C 
#endif
#if (defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_AES_C)) || \
    (defined(MBEDTLS_BLOCK_CIPHER_C) && defined(MBEDTLS_BLOCK_CIPHER_CAN_AES))
#define MBEDTLS_CCM_GCM_CAN_AES 
#endif
#if (defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_ARIA_C)) || \
    (defined(MBEDTLS_BLOCK_CIPHER_C) && defined(MBEDTLS_BLOCK_CIPHER_CAN_ARIA))
#define MBEDTLS_CCM_GCM_CAN_ARIA 
#endif
#if (defined(MBEDTLS_CIPHER_C) && defined(MBEDTLS_CAMELLIA_C)) || \
    (defined(MBEDTLS_BLOCK_CIPHER_C) && defined(MBEDTLS_BLOCK_CIPHER_CAN_CAMELLIA))
#define MBEDTLS_CCM_GCM_CAN_CAMELLIA 
#endif
#if defined(MBEDTLS_ECP_C) || \
    defined(MBEDTLS_PK_PARSE_EC_EXTENDED) || \
    defined(MBEDTLS_PK_PARSE_EC_COMPRESSED) || \
    defined(MBEDTLS_PSA_BUILTIN_KEY_TYPE_ECC_KEY_PAIR_DERIVE)
#define MBEDTLS_ECP_LIGHT 
#endif
#if defined(MBEDTLS_RSA_C)
#define MBEDTLS_ASN1_PARSE_C 
#define MBEDTLS_ASN1_WRITE_C 
#endif
#if defined(MBEDTLS_PK_PARSE_C) && defined(MBEDTLS_ECP_C)
#define MBEDTLS_PK_PARSE_EC_COMPRESSED 
#endif
#if (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_ALG_ECDH)) || \
    (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_ECDH_C))
#define MBEDTLS_CAN_ECDH 
#endif
#if !defined(MBEDTLS_USE_PSA_CRYPTO)
#if defined(MBEDTLS_ECDSA_C)
#define MBEDTLS_PK_CAN_ECDSA_SIGN 
#define MBEDTLS_PK_CAN_ECDSA_VERIFY 
#endif
#else
#if defined(PSA_WANT_ALG_ECDSA)
#if defined(PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_BASIC)
#define MBEDTLS_PK_CAN_ECDSA_SIGN 
#endif
#if defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY)
#define MBEDTLS_PK_CAN_ECDSA_VERIFY 
#endif
#endif
#endif
#if defined(MBEDTLS_PK_CAN_ECDSA_VERIFY) || defined(MBEDTLS_PK_CAN_ECDSA_SIGN)
#define MBEDTLS_PK_CAN_ECDSA_SOME 
#endif
#if defined(MBEDTLS_PSA_CRYPTO_C)
#define MBEDTLS_PSA_CRYPTO_CLIENT 
#endif
#if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED) || defined(PSA_WANT_ECC_SECP_R1_521)
#define MBEDTLS_ECP_HAVE_SECP521R1 
#endif
#if defined(MBEDTLS_ECP_DP_BP512R1_ENABLED) || defined(PSA_WANT_ECC_BRAINPOOL_P_R1_512)
#define MBEDTLS_ECP_HAVE_BP512R1 
#endif
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED) || defined(PSA_WANT_ECC_MONTGOMERY_448)
#define MBEDTLS_ECP_HAVE_CURVE448 
#endif
#if defined(MBEDTLS_ECP_DP_BP384R1_ENABLED) || defined(PSA_WANT_ECC_BRAINPOOL_P_R1_384)
#define MBEDTLS_ECP_HAVE_BP384R1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED) || defined(PSA_WANT_ECC_SECP_R1_384)
#define MBEDTLS_ECP_HAVE_SECP384R1 
#endif
#if defined(MBEDTLS_ECP_DP_BP256R1_ENABLED) || defined(PSA_WANT_ECC_BRAINPOOL_P_R1_256)
#define MBEDTLS_ECP_HAVE_BP256R1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP256K1_ENABLED) || defined(PSA_WANT_ECC_SECP_K1_256)
#define MBEDTLS_ECP_HAVE_SECP256K1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED) || defined(PSA_WANT_ECC_SECP_R1_256)
#define MBEDTLS_ECP_HAVE_SECP256R1 
#endif
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED) || defined(PSA_WANT_ECC_MONTGOMERY_255)
#define MBEDTLS_ECP_HAVE_CURVE25519 
#endif
#if defined(MBEDTLS_ECP_DP_SECP224K1_ENABLED) || defined(PSA_WANT_ECC_SECP_K1_224)
#define MBEDTLS_ECP_HAVE_SECP224K1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP224R1_ENABLED) || defined(PSA_WANT_ECC_SECP_R1_224)
#define MBEDTLS_ECP_HAVE_SECP224R1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP192K1_ENABLED) || defined(PSA_WANT_ECC_SECP_K1_192)
#define MBEDTLS_ECP_HAVE_SECP192K1 
#endif
#if defined(MBEDTLS_ECP_DP_SECP192R1_ENABLED) || defined(PSA_WANT_ECC_SECP_R1_192)
#define MBEDTLS_ECP_HAVE_SECP192R1 
#endif
#if defined(MBEDTLS_ECP_C) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY))
#define MBEDTLS_PK_HAVE_ECC_KEYS 
#endif
#if defined(MBEDTLS_PK_PARSE_C) && defined(MBEDTLS_PKCS5_C) && defined(MBEDTLS_CIPHER_MODE_CBC)
#define MBEDTLS_CIPHER_PADDING_PKCS7 
#endif
#if defined(MBEDTLS_SHA256_USE_A64_CRYPTO_IF_PRESENT) && \
    !defined(MBEDTLS_SHA256_USE_ARMV8_A_CRYPTO_IF_PRESENT)
#define MBEDTLS_SHA256_USE_ARMV8_A_CRYPTO_IF_PRESENT 
#endif
#if defined(MBEDTLS_SHA256_USE_A64_CRYPTO_ONLY) && !defined(MBEDTLS_SHA256_USE_ARMV8_A_CRYPTO_ONLY)
#define MBEDTLS_SHA256_USE_ARMV8_A_CRYPTO_ONLY 
#endif
#if (defined(MBEDTLS_PSA_CRYPTO_CLIENT) && \
    (defined(PSA_WANT_ALG_ECDSA) || defined(PSA_WANT_ALG_DETERMINISTIC_ECDSA)))
#define MBEDTLS_PSA_UTIL_HAVE_ECDSA 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_AES_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_KEY_TYPE_AES))
#define MBEDTLS_SSL_HAVE_AES 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_ARIA_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_KEY_TYPE_ARIA))
#define MBEDTLS_SSL_HAVE_ARIA 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_CAMELLIA_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_KEY_TYPE_CAMELLIA))
#define MBEDTLS_SSL_HAVE_CAMELLIA 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_CIPHER_MODE_CBC)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_ALG_CBC_NO_PADDING))
#define MBEDTLS_SSL_HAVE_CBC 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_GCM_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_ALG_GCM))
#define MBEDTLS_SSL_HAVE_GCM 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_CCM_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_ALG_CCM))
#define MBEDTLS_SSL_HAVE_CCM 
#endif
#if (!defined(MBEDTLS_USE_PSA_CRYPTO) && defined(MBEDTLS_CHACHAPOLY_C)) || \
    (defined(MBEDTLS_USE_PSA_CRYPTO) && defined(PSA_WANT_ALG_CHACHA20_POLY1305))
#define MBEDTLS_SSL_HAVE_CHACHAPOLY 
#endif
#if defined(MBEDTLS_SSL_HAVE_GCM) || defined(MBEDTLS_SSL_HAVE_CCM) || \
    defined(MBEDTLS_SSL_HAVE_CHACHAPOLY)
#define MBEDTLS_SSL_HAVE_AEAD 
#endif
#endif
