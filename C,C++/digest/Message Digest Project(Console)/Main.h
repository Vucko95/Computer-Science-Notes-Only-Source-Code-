#ifndef _MAIN_H_
#define _MAIN_H_

#define MD_MAX_LENGTH	   2048

// Error Codes for main program
#define INVALID_PARAMETERS	21L
#define NO_ARGS				22L
#define NO_FILE				23L
#define INVALID_FILE		24L
#define NO_MATCH			25L
#define SUCCESS_MATCH		26L
#define NO_MEM				27L

// Function Prototype
VOID Print_Help(VOID);
VOID Format_Arg(PCHAR,PCHAR);
VOID Print_Error(LONG,BOOL = false);
LONG Check_Digest(UCHAR,PCHAR,PCHAR,BOOL = true,BOOL = false);
VOID Print_Heading(UCHAR,PCHAR,PCHAR,PCHAR = NULL,UCHAR = 3);

#endif 