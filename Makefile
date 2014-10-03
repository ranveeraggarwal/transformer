OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
GLULIB = -lGLU
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLULIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformer
SRCS=transformer.cpp gl_framework.cpp basics.cpp body_draw.cpp body_manip.cpp control.cpp SOIL/*.c SOIL/SOIL.cpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ -Wno-write-strings $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)
