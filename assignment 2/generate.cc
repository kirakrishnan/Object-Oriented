#include<iostream>
#include<cstdlib>
#include <ctime>
#include<fstream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
main()
{
int nog,max,random;
string filename;
ofstream myfile;
cout<<"enter the no of values to be generated:";
cin>>nog;
cout<<"enter the maximum value:";
cin>>max;
cout<<"enter the random number seed:";
cin>>random;
cout<<"enter filename"<<endl;
cin>>filename;
myfile.open( filename.c_str() );
myfile<<"writing to this file"<<endl;
srand(random);
for(int i=0;i<nog;i++)
{
int x=rand()%max;
//cout<<x<<endl;
myfile<<x<<endl;
}

myfile.close();
cout<<"file generated"<<endl;
}
