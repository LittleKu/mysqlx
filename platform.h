#ifndef _INCLUDE_PLATFORM_H_
#define _INCLUDE_PLATFORM_H_

#if defined WIN32 || defined WIN64
#ifndef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS		1
#endif
#if !defined WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#if !defined snprintf
#define snprintf _snprintf
#endif
#if !defined stat
#define stat _stat
#endif
#define strcasecmp strcmpi
#define strncasecmp strnicmp
#include <windows.h>
#include <direct.h>
#define PLATFORM_LIB_EXT		"dll"
#define PLATFORM_MAX_PATH		MAX_PATH
#define PLATFORM_SEP_CHAR		'\\'
#define PLATFORM_SEP_ALTCHAR	'/'
#define PLATFORM_EXTERN_C		extern "C" __declspec(dllexport)
#if defined _MSC_VER && _MSC_VER >= 1400
#define SUBPLATFORM_SECURECRT
#endif
#elif defined __linux__ || defined __APPLE__
#if defined __linux__
# define PLATFORM_LINUX			1
# define PLATFORM_LIB_EXT		"so"
#elif defined __APPLE__
# define PLATFORM_APPLE			1
# define PLATFORM_LIB_EXT		"dylib"
#endif
#ifndef PLATFORM_POSIX
# define PLATFORM_POSIX			1
#endif
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <dlfcn.h>
#include <sys/stat.h>
#if defined PLATFORM_APPLE
#include <sys/syslimits.h>
#endif
#define PLATFORM_MAX_PATH		PATH_MAX
#define PLATFORM_SEP_CHAR		'/'
#define PLATFORM_SEP_ALTCHAR	'\\'
#define PLATFORM_EXTERN_C		extern "C" __attribute__((visibility("default")))
#endif

#if !defined SOURCEMOD_BUILD
#define SOURCEMOD_BUILD
#endif

#if !defined SM_ARRAYSIZE
#define SM_ARRAYSIZE(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

#endif

