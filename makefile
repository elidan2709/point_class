COMPILER=g++
FLAGS=-O2 -ftrapv -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wmissing-field-initializers -Wcast-qual -Wwrite-strings
LINK_COMPILER_FLAGS= -fsanitize=address,undefined -lm -o
MAC_NOT_WORKING_FLAGS= -Wlogical-op

test: test.o point.o
	$(COMPILER) $(LINK_COMPILER_FLAGS) $@ $^
	
test.o: test.cpp
	$(COMPILER) $(FLAGS) -c test.cpp
point.o: point.hpp point.cpp
	$(COMPILER) $(FLAGS) -c point.cpp
	
clear:
	rm *.o test
