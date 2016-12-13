/**
Assignment: 4
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  11/17/2015
Zid: Z1760288
**/

#include"Amenity.h"
//gets id
int Amenity::getid()const
{
  return id;
 }
 //gets state value  
string  Amenity::getstate()const
{
  return state;
} 
//gets city value
string  Amenity::getcity()const
{
  return city;
}
//gets january temperature
float Amenity::getJANTEMPERATURE() const
{
  return avg_JANTEMPERATURE;
}
//gets january sunshine
float Amenity::getJANSUNSHINE() const
{
  return avg_JANSUNSHINE;
}
//gets july temperature
float Amenity::getJULYTEMPERATURE() const
{
  return avg_JULYTEMPERATURE;
}
//gets july humidity
float Amenity::getJULYHUMIDITY() const
{
  return avg_JULYHUMIDITY;
}
//gets elevation variation
int  Amenity::getELEVEVATIONVAR() const
{
  return ELEVEVATIONVAR;
}
//gets terrain
float Amenity::getTERRAIN() const
{
  return TERRAIN;
}
//sets id
void Amenity::setid(int a)
{
  id=a;  
}
//sets state
void Amenity::setstate(string st)
{
  state=st;
}
//sets city
void Amenity::setcity(string c)
{
  city=c;
}
//sets january temperature
void Amenity::setJANTEMPERATURE(float JT)
{
  avg_JANTEMPERATURE=JT;
}
//sets sunshine
void Amenity::setJANSUNSHINE(float JS)
{
  avg_JANSUNSHINE=JS;
}
//sets july temperature
void Amenity::setJULYTEMPERATURE(float JT)
{
  avg_JULYTEMPERATURE=JT;  
}
//sets july humidity
void Amenity::setJULYHUMIDITY(float JH)
{
  avg_JULYHUMIDITY=JH;
}
//sets elevation variation
void Amenity::setELEVEVATIONVAR(int EV)
{
  ELEVEVATIONVAR=EV;
}
//sets terrain
void Amenity::setTERRAIN(float T)
{
  TERRAIN=T;
}

//compares january temperature
bool compare_JANTEMPERATURE(Amenity A1,Amenity A2)
{
  return A1.getJANTEMPERATURE()>A2.getJANTEMPERATURE();
 
}
//compares january sunshine
bool compare_JANSUNSHINE(Amenity A1,Amenity A2)
{
  return A1.getJANSUNSHINE()>A2.getJANSUNSHINE();

}
//compares july temperature
bool compare_JULYTEMPERATURE(Amenity A1,Amenity A2)
{
  return A1.getJULYTEMPERATURE()>A2.getJULYTEMPERATURE();
}
//compares july humidity
bool compare_JULYHUMIDITY(Amenity A1,Amenity A2)
{
  return A1.getJULYHUMIDITY()>A2.getJULYHUMIDITY();
}
//compares elevation variation
bool compare_ELEVEVATIONVAR(Amenity A1,Amenity A2)
{
  return A1.getELEVEVATIONVAR()>A2.getELEVEVATIONVAR();
}
//compares terrain
bool compare_TERRAIN(Amenity A1,Amenity A2)
{
  return A1.getTERRAIN()>A2.getTERRAIN();
}

float Amenity::get_comp_value() const
{
  return comp_value;
}

void Amenity::set_comp_value(float value)
{
  comp_value=value; 
}












