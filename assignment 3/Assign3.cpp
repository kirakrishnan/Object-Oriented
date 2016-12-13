/**********************************************************************
Assignment number : 3
Programmer: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  10/06/2015
Zid: Z1760288
*********************************************************************/
#include "StormHeader.h"
#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::ios;
using namespace std;
int lineCount=0;

//Header Line
void HeaderLine()
{
	cout<<"Storm Indicator - stormclassifier - StormName - sequence number - year - MaxWindSpeed - MinAirPressure"<<endl;
}

//print function
void printLine(vector<Storm> vec)
{
	int i=0;
	HeaderLine();
	for(i=0;i<vec.size();i++)
	{
		cout<<vec.at(i).getStormIndicator()
		<<" - "<<vec.at(i).getStorm()
		<<" - "<<vec.at(i).stormName
		<<" - "<<vec.at(i).getStormSeqNumber()
		<<" / "<<vec.at(i).getYear()
		<<" - "<<vec.at(i).getMaxWindSpeed()
		<<" - "<<vec.at(i).getMinAirPressure()<<endl;		
		lineCount++;
	
		if(lineCount%20==0)
		{
			cout<<endl;
			HeaderLine();
		}
	}	
}

//sorting for wind speed
vector<Storm> WindSpeed(vector<Storm> vec)
{
	int i=0;
	int j=0;
	Storm temp;
	for(i=0;i<vec.size();i++)
	{
		for(j=0;j<vec.size(); j++)
		{
			if(vec.at(i).getMaxWindSpeed()>vec.at(j).getMaxWindSpeed())
			{
				temp = vec.at(i);
				vec.at(i) = vec.at(j);
				vec.at(j) = temp; 
			}
		}
	}
	return vec;
}



/*
//sorting for Air pressure
vector<Storm> AirPressure(vector<Storm> vec)
{
	int i=0;
	int j=0;
	Storm temp;
	for(i=0;i<vec.size();i++)
	{
		for(j=0;j<vec.size();j++)
		{
			 if(vec.at(i).getMinAirPressure()<vec.at(j).getMinAirPressure())
			 {		
				temp = vec.at(i);
                vec.at(i) = vec.at(j);
                vec.at(j) = temp;
             }
		}
	}
	return vec;
}
*/
//sorting for year of the storm
vector<Storm> YearOfStorm(vector<Storm> vec)
{
	int i=0;
	int j=0;
	Storm temp;
	for(i=0;i<vec.size();i++)
	{
		for(j=0;j<vec.size();j++)
		{
			if(vec.at(i).getYear()<vec.at(j).getYear())
			{
            	temp = vec.at(i);
            	vec.at(i) = vec.at(j);
                vec.at(j) = temp;
            }
		}
	}
	return vec;
}




int main(int argc, char * argv[])
{
	
	int TotalRecords=0;
	Storm st;
	vector<Storm> vec; 
		
	ifstream infile;
  	infile.open("storm.dat",ios::in | ios::binary);
  	cout<<sizeof(st)<<endl;
  	
  	while(!infile.eof())
	{
  		infile.read((char *)&st, sizeof(Storm));
	
	// prompts error if the file does not exist	
 	if(!infile)
		{
  			cout<<"error reading a file";
			break;
	  	}	 

  		cout<<st.getStormIndicator()
		  <<" -  "<<st.getStorm()
		  <<" -  "<<st.stormName
		  <<" -  "<<st.getStormSeqNumber()
		  <<" /  "<<st.getYear()
		  <<" - "<<st.getMaxWindSpeed()
		  <<" -  "<<st.getMinAirPressure()<<endl;
		vec.push_back(st);
		TotalRecords++;
  	}
	
	cout<<endl<<endl<<"Total No of records Read: "<<vec.size()<<endl;

	//sorts the windspeed and prints the result
	vec = WindSpeed(vec);
	printLine(vec); 
	//sorts the minimum AIr pressure and prints the result
	/*vec = AirPressure(vec);
	printLine(vec);*/
	//sorts by year and prints the result
	vec = YearOfStorm(vec);
	printLine(vec);

	infile.close();
	return 0;
}

