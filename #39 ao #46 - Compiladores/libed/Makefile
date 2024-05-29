APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall
LIBS = -lm -led -L $(LIB)


all: start libed myapps

start:
	mkdir -p obj	lib	bin

libed: \
	$(OBJ)/float_vector.o \
	$(OBJ)/mytime.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: clean_apps \
	$(BIN)/test_float_vector

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/test_float_vector

clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*

clean_all: clean clean_apps
	rmdir obj	lib	bin