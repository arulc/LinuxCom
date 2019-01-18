#include ../env.mk
#/opt/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux/bin$ arm-linux-gnueabi-
#****************************************************************************
# Cross complie path
#****************************************************************************
#GCC_PATH=
#CROSS_COMPILE=$(GCC_PATH)\bin\arm-none-eabi-
# CROSS_COMPILE=/opt/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux/bin/arm-linux-gnueabihf-

# CC     := $(CROSS_COMPILE)gcc
# CXX    := $(CROSS_COMPILE)g++
# AS	   := $(CROSS_COMPILE)as
# AR     := $(CROSS_COMPILE)ar 
# LD     := $(CROSS_COMPILE)ld
# RANLIB := $(CROSS_COMPILE)ranlib
# OBJDUMP:= $(CROSS_COMPILE)objdump
# OBJCOPY:= $(CROSS_COMPILE)objcopy
# STRIP  := $(CROSS_COMPILE)strip

TARGET = testcom
#****************************************************************************
# Include paths
#****************************************************************************
# INCS := -I ./easylogger/inc -I ./NC_COM/NC_COM_Lib/

#****************************************************************************
# Libs
#****************************************************************************
# LIBS          := -LLIBS -LNC_Card/NC_UPCash_Lib -LHW_Driver/LIB

CFLAGS		  :=   -pthread
# -rdynamic -pthread -lrt -lasound -lucgui -lpicc -licc \
# 				-lmenures1  -lNC_FileSys  -lhw_b503 -l sqlite3 -lpcmctl \
# 				-lcurl -libuscloudpos -lposoffline -lm -lsdk -lssl -lcrypto


#****************************************************************************
# Source files
#****************************************************************************
SRC_C=$(shell find . -name "*.c")
SRC_S=$(shell find . -name "*.s")
SRC_H=$(shell find . -name "*.h")

OBJ_C=$(patsubst %.c, %.o, $(SRC_C))
OBJ_S=$(patsubst %.s, %.o, $(SRC_S))


SRCS := $(SRC_C) $(SRC_S)
OBJS := $(OBJ_C) $(OBJ_S)
CC = gcc
#****************************************************************************
# TARGET
#****************************************************************************
.PHONY: all
all:  prebuild $(TARGET)
prebuild:
	@echo Building app...
$(TARGET) : $(OBJS)
	@echo Generating ...
	$(CC) -o $@ $^ $(CFLAGS)
	@echo OK!
	
$(OBJ_DIR)%.o:%.c $(SRC_H)
	$(CC)   -c $< -o $@ $(CFLAGS)

clean:
	@echo The following files:
	rm  -f  $(TARGET) *.o
	find . -name "*.[od]" |xargs rm
	@echo Removed!

