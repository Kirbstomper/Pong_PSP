TARGET = pong
OBJS = main.o common/callback.o common/ui.o game/pong.o 

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LIBS = -losl -lpng -lz -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspaudiolib -lpspaudio -lm -lpsphprm
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Pong

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak