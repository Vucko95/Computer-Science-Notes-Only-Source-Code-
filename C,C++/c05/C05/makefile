# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C05
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	TypenamedID.exe \
	UsingTypename.exe \
	stringConvTest.exe \
	Getmem.exe \
	TemplateFunctionAddress.exe \
	applyGromit.exe \
	applyGromit2.exe \
	Sorted.exe \
	NobloatTest.exe \
	ExplicitInstantiation.exe \
	DelayedInstantiation.exe

Microsoft:  \
	TypenamedID.exe \
	UsingTypename.exe \
	stringConvTest.exe \
	Getmem.exe \
	TemplateFunctionAddress.exe \
	applyGromit.exe \
	NobloatTest.exe \
	DelayedInstantiation.exe

g++:  \
	TypenamedID.exe \
	UsingTypename.exe \
	stringConvTest.exe \
	Getmem.exe \
	ArraySize.exe \
	TemplateFunctionAddress.exe \
	applyGromit.exe \
	Sorted.exe \
	NobloatTest.exe \
	ExplicitInstantiation.exe \
	DelayedInstantiation.exe

edg:  \
	TypenamedID.exe \
	UsingTypename.exe \
	stringConvTest.exe \
	Getmem.exe \
	ArraySize.exe \
	TemplateFunctionAddress.exe \
	applyGromit.exe \
	TemplateTemplate.exe \
	applyGromit2.exe \
	Sorted.exe \
	NobloatTest.exe \
	ExplicitInstantiation.exe \
	DelayedInstantiation.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


TypenamedID.exe: TypenamedID.cpp

UsingTypename.exe: UsingTypename.cpp

stringConvTest.exe: stringConvTest.cpp

Getmem.exe: Getmem.cpp

ArraySize.exe: ArraySize.cpp

TemplateFunctionAddress.exe: ../TestSuite/Test.$(OBJEXT) TemplateFunctionAddress.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)TemplateFunctionAddress.exe TemplateFunctionAddress.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	TemplateFunctionAddress.exe
endif

TemplateFunctionAddress.$(OBJEXT): TemplateFunctionAddress.cpp
applyGromit.exe: ../TestSuite/Test.$(OBJEXT) applyGromit.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)applyGromit.exe applyGromit.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	applyGromit.exe
endif

applyGromit.$(OBJEXT): applyGromit.cpp
TemplateTemplate.exe: TemplateTemplate.cpp

applyGromit2.exe: ../TestSuite/Test.$(OBJEXT) applyGromit2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)applyGromit2.exe applyGromit2.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	applyGromit2.exe
endif

applyGromit2.$(OBJEXT): applyGromit2.cpp
Sorted.exe: ../TestSuite/Test.$(OBJEXT) Sorted.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)Sorted.exe Sorted.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	Sorted.exe
endif

Sorted.$(OBJEXT): Sorted.cpp
NobloatTest.exe: ../TestSuite/Test.$(OBJEXT) NobloatTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)NobloatTest.exe NobloatTest.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	NobloatTest.exe
endif

NobloatTest.$(OBJEXT): NobloatTest.cpp
ExplicitInstantiation.exe: ../TestSuite/Test.$(OBJEXT) ExplicitInstantiation.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)ExplicitInstantiation.exe ExplicitInstantiation.$(OBJEXT) ../TestSuite/Test.$(OBJEXT)
ifneq ($(MAKECMDGOALS),Microsoft)
	ExplicitInstantiation.exe
endif

ExplicitInstantiation.$(OBJEXT): ExplicitInstantiation.cpp
DelayedInstantiation.exe: DelayedInstantiation.cpp

