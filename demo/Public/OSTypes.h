/*********************************************************************************
 *Author:	Yongjun Zhao
 *Description:
 *History:
 Date:	2014.01.01/Yongjun Zhao
 Action: Create
 **********************************************************************************/
#pragma once
#ifndef __OSTYPES_H
#define __OSTYPES_H

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#if (defined(TARGET_OS_IOS) || defined(TARGET_OS_IPHONE))
#define OS_IOS
#define OS_MAC_OR_IOS
#endif

#if (defined(TARGET_OS_MAC) || defined(TARGET_OS_IPHONE))
#define OS_MAC
#define OS_MAC_OR_IOS
#endif

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WINDOWS) || defined(_WIN64))
#define OS_WINDOWS
#else
#define OS_LINUX
#endif

#ifdef OS_WINDOWS
//#define _WIN32_WINNT  0x0600

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#define localtime_r(pTime_t, pTMResult) localtime_s(pTMResult, pTime_t)
#define gmtime_r(pTime_t, pTMResult) gmtime_s(pTMResult, pTime_t)

#define FORMAT_INT64 "%I64d"
#define CHAR_PATH_SPLIT '\\'
#else
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>

#define FORMAT_INT64 "%lld"
#define CHAR_PATH_SPLIT '/'
#define _access access
#endif

#ifdef OS_ANDROID
#include <jni.h>
#include <android/log.h>
#endif

#ifndef pid_t
#define pid_t unsigned long
#endif

#ifndef uint64
#ifdef OS_WINDOWS
typedef unsigned __int64 uint64;
#else
typedef unsigned long long uint64;
#endif
#endif

#ifndef int64
#ifdef OS_WINDOWS
typedef __int64 int64;
#else
typedef long long int64;
#endif
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef uint
typedef unsigned int uint;
#endif

#ifndef Bool
typedef int Bool;
#endif

#define OS_NS_BEGIN(Name)                                                                                              \
    namespace Name                                                                                                     \
    {
#define OS_NS_END_AND_USE(Name)                                                                                        \
    }                                                                                                                  \
    using namespace Name;
#define OS_NS_USE(Name) using namespace Name;
#define OS_NS_END }

#define DELETE_OBJECT(x)                                                                                               \
    if (x) {                                                                                                           \
        delete x;                                                                                                      \
        x = NULL;                                                                                                      \
    }
#define DELETE_ARRAY(x)                                                                                                \
    if (x) {                                                                                                           \
        delete[] x;                                                                                                    \
        x = NULL;                                                                                                      \
    }
#define FREE_ARRAY(x)                                                                                                  \
    if (x) {                                                                                                           \
        free(x);                                                                                                       \
        x = NULL;                                                                                                      \
    }

#define STRLEN(x) ((x) == NULL ? 0 : (int)strlen(x))
#define STRCMP(x, y) (((x) == NULL || (y) == NULL) ? -1 : strcmp(x, y))
#define STREQUAL(x, y) (((x) == NULL || (y) == NULL) ? false : 0 == strcmp(x, y))
#define STRIEQUAL(x, y) (((x) == NULL || (y) == NULL) ? false : 0 == stricmp(x, y))

#define STR_IS_EMPTY(s) (s == NULL || s[0] == '\0')
#define STR_NOT_EMPTY(s) (s != NULL && s[0] != '\0')

#endif // defined OSTYPES_H
