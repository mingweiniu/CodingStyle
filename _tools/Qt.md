
$ qmake --project

INCLUDEPATH += . "./cwc/include/"

LIBS += -L/usr/local/lib -lGLU -lGL -lglut -lGLEW

$ qmake -o Makefile *.pro && make
