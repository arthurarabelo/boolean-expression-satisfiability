CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pilhaBoolArranjo.o $(OBJ)/pilhaCharArranjo.o $(OBJ)/ArvoreBinariaString.o $(OBJ)/TipoNoString.o
HDRS = $(INC)/pilhaBoolArranjo.h $(INC)/pilhaCharArranjo.h $(INC)/ArvoreBinariaString.h $(INC)/TipoNoString.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/tp1.out

all: $(EXE) 
	$(EXE) -a "0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" 0000000001	

$(BIN)/tp1.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	 
$(OBJ)/pilhaBoolArranjo.o: $(HDRS) $(SRC)/pilhaBoolArranjo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaBoolArranjo.o $(SRC)/pilhaBoolArranjo.cpp

$(OBJ)/pilhaCharArranjo.o: $(HDRS) $(SRC)/pilhaCharArranjo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaCharArranjo.o $(SRC)/pilhaCharArranjo.cpp

$(OBJ)/TipoNoString.o: $(HDRS) $(SRC)/TipoNoString.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoNoString.o $(SRC)/TipoNoString.cpp

$(OBJ)/ArvoreBinariaString.o: $(HDRS) $(SRC)/ArvoreBinariaString.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ArvoreBinariaString.o $(SRC)/ArvoreBinariaString.cpp   
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out