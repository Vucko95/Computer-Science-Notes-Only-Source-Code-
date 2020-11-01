# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C10
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe
.cpp.$(OBJEXT) :
	$(CPP) $(CPPFLAGS) $(OFLAGS) $<


Borland:  \
	SingletonPattern.exe \
	LogFile.$(OBJEXT) \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	SingletonPattern2.exe \
	FunctionStaticSingleton.exe \
	CuriousSingleton.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	AbstractFactory.exe \
	VirtualConstructor.exe \
	InnerClassIdiom.exe \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	BeeAndFlowers.exe

Microsoft:  \
	SingletonPattern.exe \
	LogFile.$(OBJEXT) \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	SingletonPattern2.exe \
	FunctionStaticSingleton.exe \
	CuriousSingleton.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	AbstractFactory.exe \
	VirtualConstructor.exe \
	InnerClassIdiom.exe \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	BeeAndFlowers.exe

g++:  \
	SingletonPattern.exe \
	LogFile.$(OBJEXT) \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	SingletonPattern2.exe \
	FunctionStaticSingleton.exe \
	CuriousSingleton.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	AbstractFactory.exe \
	VirtualConstructor.exe \
	InnerClassIdiom.exe \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	BeeAndFlowers.exe

edg:  \
	SingletonPattern.exe \
	LogFile.$(OBJEXT) \
	UseLog1.$(OBJEXT) \
	UseLog2.exe \
	SingletonPattern2.exe \
	FunctionStaticSingleton.exe \
	CuriousSingleton.exe \
	Bicycle.$(OBJEXT) \
	BuildBicycles.exe \
	ShapeFactory1.exe \
	ShapeFactory2.exe \
	AbstractFactory.exe \
	VirtualConstructor.exe \
	InnerClassIdiom.exe \
	ObservedFlower.exe \
	PaperScissorsRock.exe \
	BeeAndFlowers.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.obj
	del *.exe
	del *.tds
	del *.o
else
	rm -f *.o *.obj *.exe *.tds
endif


SingletonPattern.exe: SingletonPattern.cpp

LogFile.$(OBJEXT): LogFile.cpp

UseLog1.$(OBJEXT): UseLog1.cpp

UseLog2.exe: LogFile.$(OBJEXT) UseLog1.$(OBJEXT) UseLog2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)UseLog2.exe UseLog2.$(OBJEXT) LogFile.$(OBJEXT) UseLog1.$(OBJEXT)

UseLog2.$(OBJEXT): UseLog2.cpp
SingletonPattern2.exe: SingletonPattern2.cpp

FunctionStaticSingleton.exe: FunctionStaticSingleton.cpp

CuriousSingleton.exe: CuriousSingleton.cpp

Bicycle.$(OBJEXT): Bicycle.cpp

BuildBicycles.exe: Bicycle.$(OBJEXT) BuildBicycles.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)BuildBicycles.exe BuildBicycles.$(OBJEXT) Bicycle.$(OBJEXT)

BuildBicycles.$(OBJEXT): BuildBicycles.cpp
ShapeFactory1.exe: ShapeFactory1.cpp

ShapeFactory2.exe: ShapeFactory2.cpp

AbstractFactory.exe: AbstractFactory.cpp

VirtualConstructor.exe: VirtualConstructor.cpp

InnerClassIdiom.exe: InnerClassIdiom.cpp

ObservedFlower.exe: ObservedFlower.cpp

PaperScissorsRock.exe: PaperScissorsRock.cpp

BeeAndFlowers.exe: BeeAndFlowers.cpp

