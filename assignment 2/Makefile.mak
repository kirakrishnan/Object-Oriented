CC=g++
CCFLAGS= -c -g -O -Wall -std=c++11

output: output2 output1

output1: thresh
        ./thresh

thresh: thresh.o
        $(CC) -o thresh thresh.o

thresh.o: thresh.cc
        $(CC) $(CCFLAGS) thresh.cc

output2: generate
        ./generate 10 20 30 gb

generate: generate.o
        $(CC) -o generate generate.o

generate.o: generate.cc
        $(CC) $(CCFLAGS) generate.cc

clean:
        rm -rf *o
