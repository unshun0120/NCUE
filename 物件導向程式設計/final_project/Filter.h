#include<iostream>
#ifndef FILTER_H
#define FILTER_H
using namespace std;

class Filter		// 3�� Encryption function �Ҭ��[�K�禡 
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
			cout<<"�A���b���}�o�Өt�� !!! "<<endl;
			cout<<"�T�T >.o"<<endl; 
		}
		char Encryption( char );	
};

class numFile : public Filter
{
	public :
		numFile()
		{
			cout<<"The file is encrypting !"<<endl;
			cout<<"���b�[�K�� ! "<<endl<<endl;
		}
		numFile( int index )
		{
			cout<<"The "<<index<<" of data have been encrypted !"<<endl;	
			cout<<"�o "<<index<<" ����Ƥw�Q�[�K�o ! "<<endl;
		} 
		char Encryption( char );	
};


#endif
