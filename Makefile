OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
GLULIB = -lGLU
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLULIB)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=transformer
SRCS=transformer.cpp gl_framework.cpp basics.cpp body.cpp control.cpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)
