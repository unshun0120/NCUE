#include "Print.h"
#include<iostream>
using namespace std;

void addPrint::print() const		//��s�W��Ƶ��� 
{
	cout<<"The information has been added to the file !"<<endl;
	cout<<"��Ƥw�Q�s�W���ɮפ��F ! "<<endl<<endl;	
}

void modifyPrint::print() const		//��ק��Ƶ��� 
{
	cout<<"The information has been modified !"<<endl;
	cout<<"��Ƥw�Q�ק�F ! "<<endl<<endl;
}

void deletePrint::print() const	    //��R����Ƶ��� 
{
	cout<<"The information has been deleted !"<<endl;
	cout<<"��Ƥw�Q�R���F ! "<<endl<<endl;
}

void recoverPrint::print() const	//��_���Ƶ��� 
{
	cout<<"The information has been recovered !"<<endl;
	cout<<"��Ƥw�g�_����ɮפ��F ! "<<endl<<endl;	
}

