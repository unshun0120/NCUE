#include<iostream>
#include "length.h"
#include "rectangle.h"
using namespace std;

bool check1( char );		//���b���� 
bool check2( char );		//���b���� 

int main()
{

	Length len;					//�ŧi 
	Rectangle rec;
	char unit;					//�ŧi ��� 
	bool ans;					//�ŧi �^�ǬO�_������Ϊ�����
	double Area,Perimeter;		//�ŧi ���n/�P��
	char choose;				//�ŧi �O�_�n�~���J������ 
	do
	{
		//�߰ݿ�J���׳��O cm �٬O mm 
		cout<<"Enter two sides of rectangle's unit (c -> centimeter / m -> millimeter) : ";		
		cin>>unit;	
		while( !check1( unit ) )		//���b : �u�i��J C/c �άO M/m 
		{
			cout<<"You have to enter C/c or M/m "<<endl;
			cout<<"Please enter two sides of rectangle's unit again : ";
			cin>>unit;
		}
		rec.setSides( unit );	
		
		//�P�_�����or�����	 
		ans = rec.answer;
		if(ans)		//�Y�O����� 
			cout<<endl<<"The rectangle is square !!"<<endl;
		else		//�Y���O 
			cout<<endl<<"The rectangle is not square !!"<<endl;
		
		//Area && Perimeter  
		Area = rec.area;	
		Perimeter = rec.perimeter;
		if( unit == 'C' || unit == 'c' )		//�Y��쬰 cm 
		{
			cout<<endl<<"The rectangle's area is "<< Area <<"cm^2 ( "<< Area*100 <<"mm^2 )"<<endl;		//��X���n 
			cout<<"The rectangle's perimeter is "<< Perimeter <<"cm ( "<< Perimeter*10 <<"mm )"<<endl;		//��X�P�� 
		}	
		else if( unit == 'M' || unit == 'm' )		//�Y��쬰 mm 
		{
			cout<<endl<<"The rectangle's area is "<< Area <<"mm^2 ( "<< Area/100 <<"cm^2 )"<<endl;		//��X���n 
			cout<<"The rectangle's perimeter is "<< Perimeter <<"mm ( "<< Perimeter/10 <<"cm )"<<endl;		//��X�P�� 
		}	
		
		//�߰ݬO�_�~���J�s���������� 
		cout<<endl<<"If you want to input another values of rectangle's adjacent sides"<<endl;	 
		cout<<"please input y "<<endl;
		cout<<"If you want to exit this program"<<endl<<"please input n : ";
		cin>>choose;
		while( !check2( choose ) )		//���b : �u�i��J Y/y �άO N/n 
		{
			cout<<"You have to enter Y/y or N/n "<<endl;
			cout<<"Do you want to keep entering values ? : ";
			cin>>choose;
		}
	}while( choose == 'Y' || choose == 'y' );
		
	return 0;
}

bool check1( char unit )		//���b : �u�i��J C/c �άO M/m
{
	if( unit == 'C' || unit == 'c' || unit == 'M' || unit == 'm' )
		return true;
	else
		false;
}

bool check2( char unit )		//���b : �u�i��J Y/y �άO N/n 
{
	if( unit == 'Y' || unit == 'y' || unit == 'N' || unit == 'n' )
		return true;
	else
		false;
}





















