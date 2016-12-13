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
int main(int argc,char *argv[])
{
int nog,random,max;
string filename;
std::ofstream myfile;
if(argc<4)
{
cerr<<"Error! enter the valid input for all variables"<<endl;
return -1;
}
random=atoi(argv[1]);
max=atoi(argv[2]);
nog=atoi(argv[3]);
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
myfile.open(filename.c_str());
if(!myfile)
{
cout<<"unable to open file"<<endl;
exit(1);
}
srand(random);
for(int i=0;i<nog;i++)
{
float x=rand()%max;
myfile<<x<<endl;
}

myfile.close();
cout<<"file generated"<<endl;

return 0;
}