# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C09
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	Interfaces.exe \
	Interfaces2.exe \
	UseDatabase.exe \
	UseDatabase2.exe \
	UseDatabase3.exe \
	Offset.exe \
	Duplicate.exe \
	VirtualBase.exe \
	VirtualBase2.exe \
	VirtualBase3.exe \
	VirtInit.exe \
	BreakTie.exe \
	Dominance.exe \
	Dominance2.exe \
	Vendor.$(OBJEXT) \
	Paste.exe

Microsoft:  \
	Interfaces.exe \
	Interfaces2.exe \
	UseDatabase.exe \
	UseDatabase2.exe \
	UseDatabase3.exe \
	Offset.exe \
	Duplicate.exe \
	VirtualBase.exe \
	VirtualBase2.exe \
	VirtualBase3.exe \
	VirtInit.exe \
	BreakTie.exe \
	Dominance.exe \
	Dominance2.exe \
	Vendor.$(OBJEXT) \
	Paste.exe

g++:  \
	Interfaces.exe \
	Interfaces2.exe \
	UseDatabase.exe \
	UseDatabase2.exe \
	UseDatabase3.exe \
	Offset.exe \
	Duplicate.exe \
	VirtualBase.exe \
	VirtualBase2.exe \
	VirtualBase3.exe \
	VirtInit.exe \
	BreakTie.exe \
	Dominance.exe \
	Dominance2.exe \
	Vendor.$(OBJEXT) \
	Paste.exe

edg:  \
	Interfaces.exe \
	Interfaces2.exe \
	UseDatabase.exe \
	UseDatabase2.exe \
	UseDatabase3.exe \
	Offset.exe \
	Duplicate.exe \
	VirtualBase.exe \
	VirtualBase2.exe \
	VirtualBase3.exe \
	VirtInit.exe \
	BreakTie.exe \
	Dominance.exe \
	Dominance2.exe \
	Vendor.$(OBJEXT) \
	Paste.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


Interfaces.exe: Interfaces.cpp

Interfaces2.exe: Interfaces2.cpp

UseDatabase.exe: UseDatabase.cpp

UseDatabase2.exe: UseDatabase2.cpp

UseDatabase3.exe: UseDatabase3.cpp

Offset.exe: Offset.cpp

Duplicate.exe: Duplicate.cpp

VirtualBase.exe: VirtualBase.cpp

VirtualBase2.exe: VirtualBase2.cpp

VirtualBase3.exe: VirtualBase3.cpp

VirtInit.exe: VirtInit.cpp

BreakTie.exe: BreakTie.cpp

Dominance.exe: Dominance.cpp

Dominance2.exe: Dominance2.cpp

Vendor.$(OBJEXT): Vendor.cpp

Paste.exe: Vendor.$(OBJEXT) Paste.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)Paste.exe Paste.$(OBJEXT) Vendor.$(OBJEXT)

Paste.$(OBJEXT): Paste.cpp
