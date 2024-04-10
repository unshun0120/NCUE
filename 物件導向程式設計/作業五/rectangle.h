#include<iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
 
class Rectangle
{
	private :
		Length lens1,lens2;		//宣告 
		Length lens;
		double side1,side2;
		char unit;
	public :
		bool answer;				//因為需回傳 answer , area , perimeter 所以將這三個變數宣告在 public  
		double area,perimeter;
		void setSides( char );		//setSides function 
		void getSides( char );		//getSides function
		bool isSquare();			//isSquare function
		double getArea();			//getArea function
		double getPerimeter();		//getPerimeter function
};

void Rectangle::setSides( char measure )		//setSides function
{
	unit = measure;
	cout<<"Enter the values of rectangle 's two adjacent sides ( value > 0 )"<<endl;	//輸入長方形的邊長 
	cout<<"Side1 = ";		//side1 
	cin>>side1;
	while( side1 <= 0)		//防呆 : 邊長不可小於等於0 
	{
		cout<<"You have to enter positive and nonzero value "<<endl;
		cout<<"Please enter value of side1 again "<<endl;
		cout<<"Side1 = ";
		cin>>side1;
	}
	cout<<"Side2 = ";		//side2 
	cin>>side2;
	while( side2 <= 0)		//防呆 : 邊長不可小於等於0 
	{
		cout<<"You have to enter positive and nonzero value "<<endl;
		cout<<"Please enter value of side2 again "<<endl;
		cout<<"Side2 = ";
		cin>>side2;
	}
	lens1.set( side1 );		//將 side1 傳入 Length class 內的 set function 
	lens2.set( side2 );		//將 side2 傳入 Length class 內的 set function 
	getSides( unit );		//呼叫 Rectangle class 內的 getSides function 
	answer = isSquare();	 //呼叫 Rectangle class 內的 getisSquare function 
	area = getArea();		//呼叫 Rectangle class 內的 getArea function 
	perimeter = getPerimeter();		//呼叫 Rectangle class 內的 getPerimeter function 
}

void Rectangle::getSides( char unit )		//要將邊長輸出所以需要知道使用者輸入的單位,所以將 unit 傳入 
{
	if( unit == 'C' || unit == 'c' )		//若單位為 cm 
	{
		cout<<endl;
		cout<<"Side1 = "<< lens1.get() <<"cm ( "<< lens1.get()*10 <<"mm )"<<endl;		//輸出 side1 的 長度 包括 cm 和 mm  
		cout<<"Side2 = "<< lens2.get() <<"cm ( "<< lens2.get()*10 <<"mm )"<<endl;;		//輸出 side2 的 長度 包括 cm 和 mm  
	}	
	else 		//若單位為 mm 
	{
		cout<<endl;
		cout<<"Side1 = "<< lens1.get() <<"mm ( "<< lens1.get()/10 <<"cm )"<<endl;		//輸出 side1 的 長度 包括 mm 和 cm  
		cout<<"Side2 = "<< lens2.get() <<"mm ( "<< lens2.get()/10 <<"cm )"<<endl;;		//輸出 side1 的 長度 包括 mm 和 cm  
	}
}

bool Rectangle::isSquare()		//判斷是否為正方形 
{
	if( lens1 == lens2 )		//overloaded operator ==
		return true;			//若長度相等回傳 true 
	else
		return false;			//若長度不相等回傳 false  
}

double Rectangle::getArea()		//計算長方形面積 
{
	Length sum;
	sum = ( lens1 * lens2 );		//overloaded operator * 
	return sum.get();			//回傳面積 
}

double Rectangle::getPerimeter()		//計算長方形周長 
{
	Length sum;
	sum = ( lens1 + lens1 + lens2 + lens2 );		//overloaded operator + 
	return sum.get();			//回傳周長 
}

#endif
















