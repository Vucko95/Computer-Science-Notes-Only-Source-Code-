#ifndef _DATATYPE_H_
#define _DATATYPE_H_

#define CALLBACK    __stdcall

#ifndef VOID
#define VOID void
// Basic Datatypes
typedef int         INT;
typedef char		CHAR;
typedef short		SHORT;
typedef long		LONG;
#endif

// Unsigned Datatypes
typedef unsigned int        UINT;
typedef unsigned char		UCHAR;
typedef unsigned short		USHORT;
typedef unsigned long		ULONG;

typedef double DOUBLE;

/* If the Platform Is WINDOWS */
//
// __int64 is only supported by 2.0 and later midl.
// __midl is set by the 2.0 midl and not by 1.0 midl.
//

#if (MD_TARGET_SYSTEM == MD_TARGET_SYSTEM_WINDOWS)
#define _ULONGLONG_
#if (!defined (_MAC) && (!defined(MIDL_PASS) || defined(__midl)) && (!defined(_M_IX86) || (defined(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 64)))
typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;
#endif 
/* If the Platform Is LINUX */
#else
typedef long long LONGLONG
typedef unsigned long long ULONGULONG
#endif

typedef LONGLONG  *PLONGLONG;
typedef ULONGLONG *PULONGLONG;

// Basic Pointers Datatypes
typedef CHAR      *PCHAR;
typedef SHORT     *PSHORT;  
typedef LONG      *PLONG;    

// Unsigned Basic Pionters Datatypes
typedef UCHAR     *PUCHAR;
typedef USHORT    *PUSHORT;  
typedef ULONG     *PULONG;

typedef int BOOL;
#endif
