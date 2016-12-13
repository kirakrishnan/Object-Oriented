/**
Assignment: 4
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  11/17/2015
Zid: Z1760288
**/
//header guards
#ifndef AMENITY_H
#define AMENITY_H
#include<string>
using std::string;
class Amenity
{

  int id;
  string state;
  string city;
  float avg_JANTEMPERATURE;
  float avg_JANSUNSHINE;
  float avg_JULYTEMPERATURE;
  float avg_JULYHUMIDITY;
  int ELEVEVATIONVAR;
  float TERRAIN;
  float comp_value;

 public:
  int getid()const;
  string  getstate()const;
  string  getcity()const;
  float getJANTEMPERATURE()const;
  float getJANSUNSHINE()const;
  float getJULYTEMPERATURE()const;
  float getJULYHUMIDITY()const;
  int getELEVEVATIONVAR()const;
  float getTERRAIN()const;
  float get_comp_value() const;

  void setid(int);
  void setstate(string);
  void setcity(string);
  void setJANTEMPERATURE(float);
  void setJANSUNSHINE(float);
  void setJULYTEMPERATURE(float);
  void setJULYHUMIDITY(float);
  void setELEVEVATIONVAR(int);
  void setTERRAIN(float);
  void set_comp_value(float);
  
};
bool compare_JANTEMPERATURE(Amenity,Amenity);
bool compare_JANSUNSHINE(Amenity,Amenity);
bool compare_JULYTEMPERATURE(Amenity,Amenity);
bool compare_JULYHUMIDITY(Amenity,Amenity);
bool compare_ELEVEVATIONVAR(Amenity,Amenity);
bool compare_TERRAIN(Amenity,Amenity);

#endif
//end of header guard
