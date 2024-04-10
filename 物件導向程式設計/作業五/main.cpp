#include<iostream>
#include "length.h"
#include "rectangle.h"
using namespace std;

bool check1( char );		//防呆機制 
bool check2( char );		//防呆機制 

int main()
{

	Length len;					//宣告 
	Rectangle rec;
	char unit;					//宣告 單位 
	bool ans;					//宣告 回傳是否為正方形的答案
	double Area,Perimeter;		//宣告 面積/周長
	char choose;				//宣告 是否要繼續輸入的答案 
	do
	{
		//詢問輸入長度單位是 cm 還是 mm 
		cout<<"Enter two sides of rectangle's unit (c -> centimeter / m -> millimeter) : ";		
		cin>>unit;	
		while( !check1( unit ) )		//防呆 : 只可輸入 C/c 或是 M/m 
		{
			cout<<"You have to enter C/c or M/m "<<endl;
			cout<<"Please enter two sides of rectangle's unit again : ";
			cin>>unit;
		}
		rec.setSides( unit );	
		
		//判斷正方形or長方形	 
		ans = rec.answer;
		if(ans)		//若是正方形 
			cout<<endl<<"The rectangle is square !!"<<endl;
		else		//若不是 
			cout<<endl<<"The rectangle is not square !!"<<endl;
		
		//Area && Perimeter  
		Area = rec.area;	
		Perimeter = rec.perimeter;
		if( unit == 'C' || unit == 'c' )		//若單位為 cm 
		{
			cout<<endl<<"The rectangle's area is "<< Area <<"cm^2 ( "<< Area*100 <<"mm^2 )"<<endl;		//輸出面積 
			cout<<"The rectangle's perimeter is "<< Perimeter <<"cm ( "<< Perimeter*10 <<"mm )"<<endl;		//輸出周長 
		}	
		else if( unit == 'M' || unit == 'm' )		//若單位為 mm 
		{
			cout<<endl<<"The rectangle's area is "<< Area <<"mm^2 ( "<< Area/100 <<"cm^2 )"<<endl;		//輸出面積 
			cout<<"The rectangle's perimeter is "<< Perimeter <<"mm ( "<< Perimeter/10 <<"cm )"<<endl;		//輸出周長 
		}	
		
		//詢問是否繼續輸入新的長方形邊長 
		cout<<endl<<"If you want to input another values of rectangle's adjacent sides"<<endl;	 
		cout<<"please input y "<<endl;
		cout<<"If you want to exit this program"<<endl<<"please input n : ";
		cin>>choose;
		while( !check2( choose ) )		//防呆 : 只可輸入 Y/y 或是 N/n 
		{
			cout<<"You have to enter Y/y or N/n "<<endl;
			cout<<"Do you want to keep entering values ? : ";
			cin>>choose;
		}
	}while( choose == 'Y' || choose == 'y' );
		
	return 0;
}

bool check1( char unit )		//防呆 : 只可輸入 C/c 或是 M/m
{
	if( unit == 'C' || unit == 'c' || unit == 'M' || unit == 'm' )
		return true;
	else
		false;
}

bool check2( char unit )		//防呆 : 只可輸入 Y/y 或是 N/n 
{
	if( unit == 'Y' || unit == 'y' || unit == 'N' || unit == 'n' )
		return true;
	else
		false;
}





















