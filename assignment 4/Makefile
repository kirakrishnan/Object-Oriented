CC=g++          
CCFLAGS=-Wall  -std=c++11

all: Main

Main: Main.o 
	 $(CC) $(CCFLAGS) -o Main Main.o Amenity.o Amenityprint.o

Main.o: Main.cc Amenity.o Amenityprint.o
	 $(CC) $(CCFLAGS) -c Main.cc

Amenityprint.o: Amenityprint.cc Amenityprint.h
	$(CC) $(CCFLAGS) -c Amenityprint.cc

Amenity.o: Amenity.cc Amenity.h
	 $(CC) $(CCFLAGS) -c Amenity.cc

clean:
	rm *.o Main
