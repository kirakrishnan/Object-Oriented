/**
Assignment: 4
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  11/17/2015
Zid: Z1760288
**/

#include"Amenityprint.h"
#include<algorithm>
#include<iostream>

//print top and bottom values
void print_top_bottom_n(vector<Amenity> v,int n,Amenityprint p)
{
  switch(p.get_field())
    {
    case JANTEMPERATURE:
      cout<<"RANKING by JANUARY TEMPERATURE "<<endl;
      break;
    case JANSUNSHINE:
      cout<<"RANKING by SUNLIGHT HOURS "<<endl;
      break;
    case JULYTEMPERATURE:
      cout<<"RANKING by JULY TEMPERATURE "<<endl;
      break;
    case JULYHUMIDITY:
      cout<<"RANKING by JULY HUMIDITY "<<endl;
      break;
    case ELEVEVATIONVAR:
      cout<<"RANKING by LANDFORM TOPOGRAPHY CODE "<<endl;
      break;
    case TERRAIN:
      cout<<"RANKING by WATER PERCENT "<<endl;
      break;
    case COMPOSITE:
      cout<<"RANKING by COMPOSITE VALUE "<<endl;
      break;
    }
  
   cout<<"......................................."<<endl;
    for_each(v.begin(),v.begin()+n,p);
    cout<<endl;
   for_each(v.end()-n,v.end(),p);
  cout<<endl;
}

void Amenityprint::set_field(int sf)
{
  data_field=sf;
}

int Amenityprint::get_field() const
{
  return data_field;
}


void Amenityprint::operator()(const Amenity &a)
{
  cout<<setw(20)<<left<<a.getcity()<<setw(10)<<left<<a.getstate()<<setw(5); 
  
  switch (data_field)
    {
    case JANTEMPERATURE:
      cout<<a.getJANTEMPERATURE()<<endl;
      break;
    case JANSUNSHINE:
      cout<<a.getJANSUNSHINE()<<endl;
      break;
    case JULYTEMPERATURE:
      cout<<a.getJULYTEMPERATURE()<<endl;
      break;
    case JULYHUMIDITY:
      cout<<a.getJULYHUMIDITY()<<endl;
      break;
    case ELEVEVATIONVAR:
      cout<<a.getELEVEVATIONVAR()<<endl;
      break;
    case TERRAIN:
      cout<<a.getTERRAIN()<<endl;
      break;
     case COMPOSITE:
       cout<<a.get_comp_value()<<endl; 
     break;
    }
}


bool Amenityprint::operator()(const Amenity &a,const Amenity &b)
{

  return a.get_comp_value()>b.get_comp_value();

}

 

       
