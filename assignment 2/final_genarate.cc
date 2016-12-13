#include<iostream>
#include<cstdlib>
#include <ctime>
#include<fstream>
#include<cstring>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using namespace std;
main(int argc,char *argv[])
{
int nog,random,max;
string filename;
std::ofstream myfile;
if(argc<5)
{
cerr<<"Error!"<<endl;
return -1;
}
/*
cout<<"enter the no of values to be generated:";
cin>>nog;
cout<<"enter the maximum value:";
cin>>max;
cout<<"enter the random number seed:";
cin>>random;
cout<<"enter filename"<<endl;
cin>>filename;*/
nog=atoi(argv[1]);
max=atoi(argv[2]);
random=atoi(argv[3]);
filename=argv[4];
if(nog<0)
{
cout<<"enter a positive value for no of values to be generated"<<endl;
exit(1);
}
if(max<0)
{
cout<<"enter a positive value for the maximum value"<<endl;
exit(1);
}
if(random<0)
{
cout<<"enter a positive value for the random number seed"<<endl;
exit(1);
}

//ofstream outfile( filename.c_str(),ios::in|ios::out);
//myfile.open("a.txt");
myfile.open(filename.c_str());
if(!myfile)
{
cout<<"unable to open file"<<endl;
exit(1);
}
myfile<<"writing to this file"<<endl;
srand(random);
for(int i=0;i<nog;i++)
{
float x=rand()%max;
//cout<<x<<endl;
myfile<<x<<endl;
}

myfile.close();
cout<<"file generated"<<endl;
}