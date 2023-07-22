SRCS = main.c foxfs.c foxgfx.c

COMPILER_DIR=../../Compiler
SGLDIR = $(COMPILER_DIR)/COMMON/SGL_302j
SGLIDR = $(SGLDIR)/INC
SGLLDR = $(SGLDIR)/LIB_ELF

OBJS = $(SRCS:.c=.o)

LIBS +=  $(SGLLDR)/SEGA_SYS.A $(SGLLDR)/LIBCD.A $(SGLLDR)/LIBSGL.A
	SYSOBJS += $(SGLLDR)/SGLAREA.O


ifeq ($(OS), Windows_NT)
	CC=$(COMPILER_DIR)/WINDOWS/bin/sh-elf-gcc.exe
	CONV=$(COMPILER_DIR)/WINDOWS/bin/sh-elf-objcopy.exe
	CUE_MAKER=JoEngineCueMaker.exe
else
	CC=$(COMPILER_DIR)/LINUX/bin/sh-none-elf-gcc-8.2.0
	CONV=$(COMPILER_DIR)/LINUX/bin/sh-none-elf-objcopy
	CUE_MAKER="$(COMPILER_DIR)/LINUX/Other Utilities/CueMaker"
endif

ASSETS_DIR=./cd
MKISOFS=mkisofs
RM = rm -rf

CMNDIR = $(COMPILER_DIR)/COMMON

CCFLAGS += -fkeep-inline-functions -W -Wall -Wshadow -Wbad-function-cast -Winline -Wcomment \
-Winline -Wlong-long -Wsign-compare -Wextra -Wno-strict-aliasing \
-fno-common -ffast-math \
--param max-inline-insns-single=50 -fms-extensions -std=gnu99 \
-fmerge-all-constants -fno-ident -fno-unwind-tables -fno-asynchronous-unwind-tables \
-fomit-frame-pointer -fstrength-reduce -frerun-loop-opt -O2 -nodefaultlibs -nostdlib -fno-builtin \
-m2 -c

ifneq ($(OS), Windows_NT)
	CCFLAGS += -flto
endif

CCFLAGS += -I$(SGLIDR)

LDFLAGS = -m2
LDFLAGS += -L$(SGLLDR)
LDFLAGS +=-Xlinker --format=elf32-sh -Xlinker -T$(LDFILE) -Xlinker -Map \
          -Xlinker $(MPFILE) -Xlinker -e -Xlinker ___Start -nostartfiles
ifneq ($(OS), Windows_NT)
	LIBS += -L.$(COMPILER_DIR)/LINUX/sh-elf/sh-elf/lib/ -Wl,--format=elf32-sh -Wl,--relax -lgcc
endif
DFLAGS =

TARGET_ELF = game.elf
TARGET_BIN = cd/0.bin
TARGET_ISO = $(TARGET_ELF:.elf=.iso)
TARGET_CUE = $(TARGET_ELF:.elf=.cue)
CDDA     = $(wildcard *.wav)
MPFILE   = $(TARGET_ELF:.elf=.map)
IPFILE   = $(CMNDIR)/IP.BIN
LDFILE   = $(CMNDIR)/sgl.linker

MAKEFILE = makefile

.PHONY : all clean re

all: $(TARGET_ELF) $(TARGET_BIN) $(TARGET_ISO) $(TARGET_CUE)

%.o: %.c
	$(CC) $< $(DFLAGS) $(CCFLAGS) $(_CCFLAGS) -o $@

$(TARGET_ELF) : $(SYSOBJS) $(OBJS) $(MAKEFILE) $(LDFILE)
	$(CC) $(LDFLAGS) $(SYSOBJS) $(OBJS) $(LIBS) -o $@

$(TARGET_BIN): $(TARGET_ELF)
	$(CONV) -O binary $(TARGET_ELF) $@

$(TARGET_ISO): $(TARGET_BIN) $(ASSETS_DIR)
	$(MKISOFS) -quiet -sysid "SEGA SATURN" -volid "SaturnApp" -volset "SaturnApp" -sectype 2352 \
		-publisher "SEGA ENTERPRISES, LTD." -preparer "SEGA ENTERPRISES, LTD." -appid "SaturnApp" \
		-abstract "$(ASSETS_DIR)/ABS.TXT" -copyright "$(ASSETS_DIR)/CPY.TXT" -biblio "$(ASSETS_DIR)/BIB.TXT" -generic-boot $(IPFILE) \
		-full-iso9660-filenames -o $@ $(ASSETS_DIR)

$(TARGET_CUE): $(TARGET_ISO) $(CDDA)
	$(CUE_MAKER)

clean:
	$(RM) $(OBJS) $(TARGET_ELF) $(TARGET_BIN) $(TARGET_ISO) $(TARGET_CUE) $(MPFILE)

re: clean all
