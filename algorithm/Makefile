### Application-specific constants

APP_NAME := algorithm

### Environment constants 

LGW_PATH ?= ../data_structure
ARCH ?=
CROSS_COMPILE ?=

### External constant definitions
# must get library build option to know if mpsse must be linked or not

# include $(LGW_PATH)/library.cfg

### Constant symbols

CC := $(CROSS_COMPILE)gcc
AR := $(CROSS_COMPILE)ar

CFLAGS = -O0 -Wextra -g  -std=c99 -I$(INC)
LIBS := -lDataStructures -lrt -lm
#  CFLAGS = -g -std=gnu++0x   -I$(INC) # 输出error信息
#  CFLAGS = -O1 -Wall -Wextra -g  -std=c99 -I$(INC) # 输出warning和error信息

BIN = .
SRC = ./src
INC = ./inc  #../data_structure/inc
OBJ = ./obj
TARGET = $(APP_NAME)
BIN_TARGET = $(BIN)/$(TARGET)

### 寻找所有源文件(即：*.c文件)和所有中间文件(即：*.o)
SOURCE = $(wildcard ${SRC}/*.c \
		$(wildcard ./*.c) )
OBJECT = $(patsubst %.c,${OBJ}/%.o,$(notdir ${SOURCE}))

### General build targets
all: $(APP_NAME)

.PHONY:clean
clean:
	find $(OBJ) -name *.o  -exec rm -rf {} \; 
	rm -rf $(BIN_TARGET)
	rm -rf *.dot

### Main program compilation and assembly

$(shell   mkdir -p $(OBJ))

$(OBJ)/%.o :$(SRC)/%.c 
	$(CC) $(CFLAGS)  -c $< -o $@ 

$(OBJ)/$(APP_NAME).o: ./$(APP_NAME).c 
	$(CC) $(CFLAGS) -o $@ -c $(APP_NAME).c

$(BIN_TARGET):$(OBJECT)
	$(CC) -L$(LGW_PATH) -o $@ $(OBJECT) $(LIBS)
### 另外一种写法
### $(CC) -o $@ $(OBJECT) ../data_structure/libDataStructure.a


### EOF