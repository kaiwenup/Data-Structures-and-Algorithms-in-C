#把所有的目录做成变量，方便修改和移植 
BIN = .
SRC = ./src
INC = ./inc
OBJ = ./obj
 
#提前所有源文件(即：*.c文件)和所有中间文件(即：*.o)
SOURCE = $(wildcard ${SRC}/*.cc \
		$(wildcard ./*.cc) )
OBJECT = $(patsubst %.cc,${OBJ}/%.o,$(notdir ${SOURCE}))
OBJECTS = test


# 设置最后目标文件
 TARGET = $(OBJECTS)
 BIN_TARGET = $(BIN)/$(TARGET)
 
 CC = g++ 
 CFLAGS = -g -std=gnu++0x   -I$(INC)
 
# 生成最后的可执行文件
$(BIN_TARGET):$(OBJECT)
	$(CC)  -o $@ $(OBJECT)

# 各文件单独编译
$(OBJ)/%.o :$(SRC)/%.cc 
	$(CC) $(CFLAGS)  -c $< -o $@ 
$(OBJ)/$(OBJECTS).o: ./$(OBJECTS).cc 
	$(CC) $(CFLAGS) -o $@ -c $(OBJECTS).cc 

 .PHONY:clean
 clean:
	find $(OBJ) -name *.o -exec rm -rf {} \; 
	rm -rf $(BIN_TARGET)