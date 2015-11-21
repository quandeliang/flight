#modify in ril
xx= x
CC = gcc
WALL= -Wall -g -O0
SUBDIRS:= kernellist main file obj

OBJS=kernellist.o main.o file.o
BIN=file_flight_app
OBJS_DIR=obj
BIN_DIR=bin
 export CC OBJS BIN OBJS_DIR BIN_DIR WALL

all:CHECK_DIR $(SUBDIRS)
CHECK_DIR:
		  mkdir -p $(BIN_DIR)
$(SUBDIRS):ECHO
		   make -C  $@
ECHO:
		  @echo $(SUBDIRS)
		  @echo begin to compile
		  @echo I love YangJing
clean:
		  $(RM) $(OBJS_DIR)/*.o
		  rm -rf $(BIN_DIR)

