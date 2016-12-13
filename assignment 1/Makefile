all: fr gq vw clean output

output: output1 output2 output3

output1: fr
        ./fr

output2: gq
        ./gq

output3: vw
        ./vw

fr: fr.o pg.o
        g++ -o fr fr.o pg.o

fr.o:fr.cc pg.h
        g++ -c fr.cc

pg.o:pg.cc
        g++ -c pg.cc

gq:gq.o ac.o pg.o
        g++ -o gq gq.o ac.o pg.o

ac.o:ac.cc pg.h
        g++ -c ac.cc

gq.o:gq.cc ac.h includes/bb.h
        g++ -c -Iincludes gq.cc

vw:vw.o ac.o pg.o
        g++ -o vw vw.o ac.o pg.o

vw.o:vw.cc ac.h
        g++ -c vw.cc

clean:
        rm -rf *o
