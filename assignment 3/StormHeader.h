/**********************************************************************
Assignment number : 3
Programmer: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  10/06/2015
Zid: Z1760288
*********************************************************************/

#ifndef A_H      
#define A_H 

#include<cstring>
#include<iostream>

using std::cout;
using std::endl;

class Storm
{
	
	public:
	
	char storm;
	
	char stormName[10];
	
	int SeqNumber;
	
	int year;
	
	int maxWind;
	
	int minAir;
	
	char stormClassifier;
	
		Storm()
		{
			storm = 'N';
			strcpy(stormName, "None");
			maxWind = 0;
			minAir = 0;
			SeqNumber = 0;
			year = 0;
			stormClassifier = 'N';
		}
		
		void print()
		{
			if(minAir!= 10000)
			{
				if(stormClassifier != 'N')
				{
					cout <<storm<<" "<<stormName <<"  "<< SeqNumber << "/" << year << minAir << stormClassifier;
				}
				else
				{
					cout <<storm<<" "<<stormName <<"  "<< SeqNumber << "/" << year << minAir;	
				}
			}
			else
			{
				if(stormClassifier != 'N')
				{
					cout <<storm<<" "<<stormName <<"  "<< SeqNumber << "/" << year << stormClassifier;
				}
				else
				{
					cout <<storm<<" "<<stormName <<"  "<< SeqNumber << "/" << year << minAir;	
				}
			}
		}
		
		int getYear()
		{
			return year;
		}
		
		void setYear(int yy)
		{
			year= yy;			
		}
		
		void setStorm(char sc)
		{
			stormClassifier = sc;
		}
		
		char getStorm()
		{
			return stormClassifier;
		}
		
		int getStormSeqNumber()
		{
			return SeqNumber;
		}
		
		void setStormSeqNumber(int seq)
		{
			SeqNumber = seq;
		}
		
		int getMinAirPressure()
		{
			return minAir;
		}
		
		int setMinAirPressure(int air)
		{
			minAir = air;
		}
		
		int getMaxWindSpeed()
		{
			return maxWind;
		}
		
		void setMaxWindSpeed(int wind)
		{
			maxWind = wind;
		}
		char getStormIndicator()
		{
			return storm;
		}
		
		void setStormIndicator(char c)
		{
			storm = c;
		}
};

#endif
