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
int main()
{
int th;
string filename2;
int data[100],count=0,high=0;
ifstream myfile;
cout<<"enter a valid file name: ";
cin>>filename2;
myfile.open(filename2.c_str());
thr:
cout<<"enter a valid threshold value: ";
cin>>th;

if(!myfile)
{
cout<<"unable to open file"<<endl;
exit(1);
}
if(th<0)
{
cout<<"enter a positive value for the threshold"<<endl;
goto thr;
}
while(myfile.good())
{
myfile>>data[count];
count++;
}
/*cout<<"reading from this file"<<endl;
cout<<"There are "<<count-1<<" integers"<<endl;
for(int j=0;j<count-1;j++)
{
myfile>>data[j];
cout<<data[j]<<endl;
}*/
for(int i=0;i<count-1;i++)
{
if(data[i]<th)
{
high++;
}
}
cout<< high <<" of "<< count-1 <<" values in "<< filename2 <<" are less than "<<th<<endl;
myfile.close();

return 0;
}