# Makefile for main
# Y. Liow
#------------------------------------------------------------------------------
# Macros
#------------------------------------------------------------------------------
CXX       = g++
CXXFLAGS  = -g -Wall -fmax-errors=3
LINK      = g++
LINKFLAGS = 
OBJS      = main.o IntArray.o
EXE       = main.exe

#------------------------------------------------------------------------------
# Executable
#------------------------------------------------------------------------------
$(EXE):	$(OBJS)
	$(LINK) $(OBJS) -o $(EXE) $(LINKFLAGS)

asan: $(OBJS)
	$(LINK) $(OBJS) -o $(EXE) $(LINKFLAGS) -g -fsanitize=address
#------------------------------------------------------------------------------
# Object files
#------------------------------------------------------------------------------
main.o:	main.cpp IntArray.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

IntArray.o:	IntArray.cpp IntArray.h
	$(CXX) $(CXXFLAGS) IntArray.cpp -c -o IntArray.o

#------------------------------------------------------------------------------
# Utilities
#------------------------------------------------------------------------------
clean:
	rm -rf $(OBJS) $(EXE)
c:
	rm -rf $(OBJS) $(EXE)

run:
	./$(EXE)
r:
	./$(EXE)
