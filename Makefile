TARGET = TicTacToe
OBJECTS = main.o

LOCAL_INC_PATH = C:\Stuff\School\CSCI400\PPL_ExploreProject\include
LOCAL_LIB_PATH = C:\Stuff\School\CSCI400\PPL_ExploreProject\lib

CXX    = g++
CFLAGS = -Wall -g

INCPATH += -I$(LOCAL_INC_PATH)
LIBPATH += -L$(LOCAL_LIB_PATH)

LIBS += -llua5.1
TARGET := $(TARGET).exe

all: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

build: $(OBJECTS)

new: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

depend:
	rm -f Makefile.bak
	mv Makefile Makefile.bak
	sed '/^# DEPENDENCIES/,$$d' Makefile.bak > Makefile
	echo '# DEPENDENCIES' >> Makefile
	$(CXX) $(INCPATH) -MM *.cpp >> Makefile

.c.o:
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

.cc.o: 	
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

.cpp.o: 	
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

$(TARGET): $(OBJECTS) 
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBPATH) $(LIBS)

# DEPENDENCIES
main.o: main.cpp