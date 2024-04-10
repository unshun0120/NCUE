#include<iostream>
#ifndef FILTER_H
#define FILTER_H
using namespace std;

class Filter		// 3個 Encryption function 皆為加密函式 
{
	public :
		char Encryption( char );		
};

class File : public Filter
{
	public :
		~File()
		{
			cout<<"You are leaving the shop system !!!"<<endl;
			cout<<"GoodBye >.o "<<endl;
			cout<<"你正在離開這個系統 !!! "<<endl;
			cout<<"掰掰 >.o"<<endl; 
		}
		char Encryption( char );	
};

class numFile : public Filter
{
	public :
		numFile()
		{
			cout<<"The file is encrypting !"<<endl;
			cout<<"正在加密中 ! "<<endl<<endl;
		}
		numFile( int index )
		{
			cout<<"The "<<index<<" of data have been encrypted !"<<endl;	
			cout<<"這 "<<index<<" 筆資料已被加密囉 ! "<<endl;
		} 
		char Encryption( char );	
};


#endif
