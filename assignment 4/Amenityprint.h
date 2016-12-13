/**
Assignment: 4
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  11/17/2015
Zid: Z1760288
**/
//header guard
#ifndef AMENITYPRINT
#define AMENITYPRINT
#include"Amenity.h"
#define JANTEMPERATURE 1
#define JANSUNSHINE 2
#define JULYTEMPERATURE 3
#define JULYHUMIDITY 4
#define ELEVEVATIONVAR 5
#define TERRAIN 6
#define COMPOSITE 7
#include<iostream>
#include<vector>
#include<iomanip>
using std::setw;
using std::left;
using std::right;
using std::cout;
using std::endl;
using std::vector;
class Amenityprint
{
int data_field;

public:
void set_field(int);
 int get_field() const; 

 void operator()(const Amenity &);
 bool operator() (const Amenity &,const Amenity &);


};

void print_top_bottom_n(vector<Amenity>,int,Amenityprint);

#endif
//header guard ends
