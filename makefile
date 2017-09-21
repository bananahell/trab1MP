# Consts:
# IncludeDIR = *.hpp DIR
# CC = gcc or g++
# DB = gdb
# CFLAGS = comp line flags (-ansi = ansi law; -Wall, -Wextra = warnings; -I./ = *.h DIR)
# ObjDIR = *.o DIR
# LibDIR = lib DIR
# LibDIR -> enable when using, put $(LIBS) at end of gogo's command
LibDIREC =./lib/
LibDIR =./lib/
IncludeDIR =./include/
CppDIR=./src/
ObjDIR=./src/obj/
CC=g++
DB=gdb
CFLAGS=-ansi -Wall -Wextra -I$(IncludeDIR) -pthread -ftest-coverage -fprofile-arcs
LIBS=-lgtest


#
# Vars:
# -- ADAPT THIS IN YOUR PROGRAM --
headers = string_soma.hpp
# Main test object
 mainObject = testa_string_soma
# Main use object
# mainObject = testa_soma_string_stdin
objects = string_soma
#


# Set of *.hpp on which the *.cpp depend
_DEPS = $(headers)
DEPS = $(patsubst %,$(IncludeDIR)%,$(_DEPS))

# Set of *.o
_OBJ = $(mainObject).o $(objects).o
OBJ = $(patsubst %,$(ObjDIR)%,$(_OBJ))

# Gathers *.o
$(ObjDIR)%.o: $(CppDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Creates executable (Linux)
$(mainObject): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

# Gets the files and organize in the lib include src/obj structure
.PHONY: prepareDIR
prepareDIR:
	mkdir -p $(LibDIREC)
	mkdir -p $(IncludeDIR)
	mkdir -p $(CppDIR)
	mkdir -p $(ObjDIR)
	mv *.hpp $(IncludeDIR); true
	mv *.cpp $(CppDIR); true

# Call for execution
.PHONY: execute
execute:
	./$(mainObject)

# Call for debugging
.PHONY: debug
debug:
	$(DB) ./$(mainObject)

# Call for cppcheck
.PHONY: cppcheck
cppcheck:
	cppcheck --enable=all . -I./include --suppress=missingIncludeSystem

# Call for *.o and gcov filess clean up
.PHONY: clean
clean:
	rm $(ObjDIR)*; true

# Call for gcov coverage
.PHONY: gcov
gcov:
	gcov $(ObjDIR)$(objects)*.gcno; true

# Call for valgrind coverage
.PHONY: valgrind
valgrind:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --dsymutil=yes ./$(mainObject)

# Call for help with this makefile's commands
.PHONY: help
help:
	@echo "\n     Makefile\n"
	@echo " make............= compiles program"
	@echo " make prepareDIR.= prepares project in the -lib include src/obj-"
	@echo "                   structure (use this if all files are with this"
	@echo "                   makefile)"
	@echo " make execute....= executes succesfully compiled program"
	@echo " make gcov ......= checks test coverage of succesfully executed program"
	@echo " make debug......= (gdb) debugs succesfully compiled program"
	@echo " make cppcheck...= invokes cppcheck on all .cpp files in the directory,"
	@echo "                   checking for all types of messages *(except"
	@echo "                   missingIncludeSystem - cppceck can't find the gtest"
	@echo "                   library)"
	@echo " make clean......= removes objects from obj directory\n"
	@echo " make valgrind...= uses valgrind on the project already compiled\n"
	@echo " For use with program, change variables"
	@echo " -headers- and -objects- inside makefile\n\n"
