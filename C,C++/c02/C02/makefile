# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C02
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT)

Microsoft:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT)

g++:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT)

edg:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT)

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


HiLo.exe: HiLo.cpp

SimpleDateTest.exe: Date.$(OBJEXT) SimpleDateTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)SimpleDateTest.exe SimpleDateTest.$(OBJEXT) Date.$(OBJEXT)

SimpleDateTest.$(OBJEXT): SimpleDateTest.cpp
SimpleDateTest2.exe: Date.$(OBJEXT) SimpleDateTest2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)SimpleDateTest2.exe SimpleDateTest2.$(OBJEXT) Date.$(OBJEXT)

SimpleDateTest2.$(OBJEXT): SimpleDateTest2.cpp
DateTest.exe: Date.$(OBJEXT) ../TestSuite/Test.$(OBJEXT) DateTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)DateTest.exe DateTest.$(OBJEXT) Date.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	DateTest.exe
endif

DateTest.$(OBJEXT): DateTest.cpp
MemCheck.$(OBJEXT): MemCheck.cpp

MemTest.exe: MemCheck.$(OBJEXT) MemTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)MemTest.exe MemTest.$(OBJEXT) MemCheck.$(OBJEXT)

MemTest.$(OBJEXT): MemTest.cpp
Date.$(OBJEXT): Date.cpp

