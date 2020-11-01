#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifndef __cplusplus
#error You need a C++ Complier to compile the Message Digest Project
#endif 

#define MD_TARGET_SYSTEM_NULL		0
#define MD_TARGET_SYSTEM_WINDOWS	1
#define MD_TARGET_SYSTEM_LINUX		2

#if defined(WIN32)
#define MD_TARGET_SYSTEM MD_TARGET_SYSTEM_WINDOWS
#elif defined(_WIN32)
#define MD_TARGET_SYSTEM MD_TARGET_SYSTEM_WINDOWS
#elif defined(MSC_VER)
#define MD_TARGET_SYSTEM MD_TARGET_SYSTEM_WINDOWS
#elif defined(_MSC_VER)
#define MD_TARGET_SYSTEM MD_TARGET_SYSTEM_WINDOWS
#else
#define MD_TARGET_SYSTEM MD_TARGET_SYSTEM_LINUX
#endif // MD_TARGET_SYSTEM is now defined

#endif