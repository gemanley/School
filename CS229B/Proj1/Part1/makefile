# All Target
all: gensin

# Tool invocations
gensine: gensine.o SoundIO.o
	gcc gensine.o SoundIO.o -o gensin

gensin.o: gensine.c
	gcc -c gensine.c

SoundIO.o: SoundIO.c SoundIO.h
	gcc -c SoundIO.c
