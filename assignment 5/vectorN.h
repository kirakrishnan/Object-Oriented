/**
Assignment: 5
Name: Aravinda Krishnan V
course/Section:   CSCI 689/0001
Date Due:  12/03/2015
Zid: Z1760288
**/
#include <iostream>
#include <string>

using namespace std;

bool f = false;
bool t = true;

template<class T>
class VectorN
{
	T * data;
	int l;
	
	public :
		//default constructor
		VectorN(){
			data= new T[0];
			l = 0;
		}
		
		//constructor takes arguments
		VectorN(const T * arr , int n){
			data = new T[n];
			l = n;
			for(int i = 0; i < n; i++)
			{
				data[i] = arr[i];
			}
		}
		//copy constructor
		VectorN(const VectorN & v){
			l = v.size();
			data = new T[v.size()];
			for(int i = 0; i < v.size(); i++)
			{
				data[i] = v[i];
			}
		}
		
		//destructor
		~VectorN(){
			delete []data;
		}
		
		//Returns the size of vector
		int size() const{
			return l;
		}
		
		
		void clear(){
			l = 0;
			delete []data;
		}
		
		
		T& operator[] ( const int& pos ) const{
			return data[pos];
		}
	
		T& operator[] ( const int& pos ) {
			return data[pos];
		}
		
		//Assignment operator
		VectorN<T>& operator = (const VectorN<T> & v)
		{
    		delete[] data;
    		if(&(v.data)==&(this->data))
    		return *this;
    		
			l = v.size();
    		//cout << l << "**********************************";
			data = new T [l];
    		
   			for (int i = 0; i < l; i++)
        	data[i] = v[i];
        	
    		return *this;
		}	
		
		//Equality Operator
		bool operator == (const VectorN<T> &v1 ) const{
			if(l != v1.size())
			{
				return f;
			}
			for(int i = 0; i < v1.size(); i++)
			{
				if(data[i] != v1[i])
				return f;
			}
			return t;
}  	
};

//output operator
template <class V>
ostream& operator<<(ostream& os, const VectorN<V>& v)
{
    os << "[";
    int n = v.size();
	for(int i = 0; i < n; i++)
	{
		os << v[i];
		if(i != n - 1)
		os << ',';
	}
	os << "]";    
    return os;
}

