/**
Assignment: 4
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  11/17/2015
Zid: Z1760288
**/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include"Amenity.h"
#include"Amenityprint.h"
#include<cstdlib>

using std::vector;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::strtol;
using std::endl;
using std::for_each;
using std::transform;

vector<Amenity> readData(string);
float average(vector<float>);
float deviation(vector<float>);
void calculate_COMPOSITE_value(vector<Amenity> &);
vector<float> z_scores(vector<float>,float,float);


int main(int argc,char * argv[])
{
  vector<Amenity> v;
  if(argc!=2)
    {
    cout<<"please sepecify the data file"<<endl;
    exit(0);
    }
 
  v=readData(argv[1]);
  cout<<v.size()<<" records are read from file"<<endl;
  calculate_COMPOSITE_value(v);

  int n=12;
  Amenityprint printer;    

  printer.set_field(JANTEMPERATURE);  
  sort(v.begin(),v.end(),compare_JANTEMPERATURE);                    
  print_top_bottom_n(v,n,printer);                          

  printer.set_field(JANSUNSHINE);
  sort(v.begin(),v.end(),compare_JANSUNSHINE);
  print_top_bottom_n(v,n,printer);

  printer.set_field(JULYTEMPERATURE);
  sort(v.begin(),v.end(),compare_JULYTEMPERATURE);
  print_top_bottom_n(v,n,printer);
  
  printer.set_field(JULYHUMIDITY);
  sort(v.begin(),v.end(),compare_JULYHUMIDITY);
  print_top_bottom_n(v,n,printer);

  printer.set_field(ELEVEVATIONVAR);
  sort(v.begin(),v.end(),compare_ELEVEVATIONVAR);
  print_top_bottom_n(v,n,printer);

  printer.set_field(TERRAIN);
  sort(v.begin(),v.end(),compare_TERRAIN);
  print_top_bottom_n(v,n,printer);
  
   
  printer.set_field(COMPOSITE);     
  sort(v.begin(),v.end(),printer);
  print_top_bottom_n(v,10,printer);                            
}

//reads data
vector<Amenity>  readData(string file)
{
  ifstream input;
  vector<Amenity> v;  
  input.open(file.c_str());
  if(!input)
    {
    cout<<"file not opened succussfully";
    exit(1);
    }
     string line;
     while(getline(input,line))
	{
      string value;
       int start=0,end=0;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      int a=strtol(value.c_str(),NULL,10);
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      string s1=value;
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      string s2=value;
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      float f1=strtof(value.c_str(),NULL);
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      float f2=strtof(value.c_str(),NULL);
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      float f3=strtof(value.c_str(),NULL);
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      float f4=strtof(value.c_str(),NULL);
      start=end+1;
      end=line.find(',',start);
      value=line.substr(start,end-start);
      int b=strtol(value.c_str(),NULL,10);
      start=end+1;
      end=line.length();
      value=line.substr(start,end-start);
      float f5=strtof(value.c_str(),NULL);
      Amenity am;
      am.setid(a);
      am.setstate(s1);
      am.setcity(s2);
      am.setJANTEMPERATURE(f1);
      am.setJANSUNSHINE(f2);
      am.setJULYTEMPERATURE(f3);
      am.setJULYHUMIDITY(f4);
      am.setELEVEVATIONVAR(b);
      am.setTERRAIN(f5);
      v.push_back(am);
	}
     
	return v;
}

//calculates the average value
float average(vector<float> v)
{
  float  sum=0;
  for_each(v.begin(),v.end(),[& sum](float f){sum=sum+f;});
  return sum/v.size();
}

//calculates the deviation
float deviation(vector<float> v)
 {
   float avg=average(v);
   float variance=0;
   for_each(v.begin(),v.end(),[&variance,&avg,&v](float f){
       variance= variance+(pow((avg-f),2)/(v.size()-1));});
   return sqrt(variance);
 }

//calculates the composite value
void calculate_COMPOSITE_value(vector<Amenity> &amenities)
{
  vector<vector<float>> columns(6);    
  vector<float> stdv(6);
  vector<float> avg(6);          
  float value=0;
  
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[0].push_back(a.getJANTEMPERATURE());});
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[1].push_back(a.getJANSUNSHINE());});
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[2].push_back(a.getJULYTEMPERATURE());});
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[3].push_back(a.getJULYHUMIDITY());});
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[4].push_back(a.getELEVEVATIONVAR());});
  for_each(amenities.begin(),amenities.end(),[&columns](Amenity a){columns[5].push_back(log(a.getTERRAIN()*100));});
  transform(columns.begin(),columns.end(),stdv.begin(),deviation);
  transform(columns.begin(),columns.end(),avg.begin(),average);

  for(unsigned  i1=0;i1<amenities.size();i1++)
    {
      for(unsigned i2=0;i2<6;i2++)
	{

	  float f1=z_scores(columns[i2],avg[i2],stdv[i2])[i1];
	  if(i2==JULYTEMPERATURE-1 || i2==JULYHUMIDITY-1)           
	    f1=-1*f1;
	  value+=f1;                                         
	}
      amenities[i1].set_comp_value(value);         
      value=0;                                              
    }
}

vector<float> z_scores(vector<float> v,float avg,float sd)
{
  vector<float> z;
  for(unsigned i=0;i<v.size();i++)
    {
      float f=v[i];
      float comp=(f-avg)/sd;          
      z.push_back(comp);            
    }
  return z;


}



  
