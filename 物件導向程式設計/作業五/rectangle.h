#include<iostream>
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
 
class Rectangle
{
	private :
		Length lens1,lens2;		//�ŧi 
		Length lens;
		double side1,side2;
		char unit;
	public :
		bool answer;				//�]���ݦ^�� answer , area , perimeter �ҥH�N�o�T���ܼƫŧi�b public  
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
	cout<<"Enter the values of rectangle 's two adjacent sides ( value > 0 )"<<endl;	//��J����Ϊ���� 
	cout<<"Side1 = ";		//side1 
	cin>>side1;
	while( side1 <= 0)		//���b : ������i�p�󵥩�0 
	{
		cout<<"You have to enter positive and nonzero value "<<endl;
		cout<<"Please enter value of side1 again "<<endl;
		cout<<"Side1 = ";
		cin>>side1;
	}
	cout<<"Side2 = ";		//side2 
	cin>>side2;
	while( side2 <= 0)		//���b : ������i�p�󵥩�0 
	{
		cout<<"You have to enter positive and nonzero value "<<endl;
		cout<<"Please enter value of side2 again "<<endl;
		cout<<"Side2 = ";
		cin>>side2;
	}
	lens1.set( side1 );		//�N side1 �ǤJ Length class ���� set function 
	lens2.set( side2 );		//�N side2 �ǤJ Length class ���� set function 
	getSides( unit );		//�I�s Rectangle class ���� getSides function 
	answer = isSquare();	 //�I�s Rectangle class ���� getisSquare function 
	area = getArea();		//�I�s Rectangle class ���� getArea function 
	perimeter = getPerimeter();		//�I�s Rectangle class ���� getPerimeter function 
}

void Rectangle::getSides( char unit )		//�n�N�����X�ҥH�ݭn���D�ϥΪ̿�J�����,�ҥH�N unit �ǤJ 
{
	if( unit == 'C' || unit == 'c' )		//�Y��쬰 cm 
	{
		cout<<endl;
		cout<<"Side1 = "<< lens1.get() <<"cm ( "<< lens1.get()*10 <<"mm )"<<endl;		//��X side1 �� ���� �]�A cm �M mm  
		cout<<"Side2 = "<< lens2.get() <<"cm ( "<< lens2.get()*10 <<"mm )"<<endl;;		//��X side2 �� ���� �]�A cm �M mm  
	}	
	else 		//�Y��쬰 mm 
	{
		cout<<endl;
		cout<<"Side1 = "<< lens1.get() <<"mm ( "<< lens1.get()/10 <<"cm )"<<endl;		//��X side1 �� ���� �]�A mm �M cm  
		cout<<"Side2 = "<< lens2.get() <<"mm ( "<< lens2.get()/10 <<"cm )"<<endl;;		//��X side1 �� ���� �]�A mm �M cm  
	}
}

bool Rectangle::isSquare()		//�P�_�O�_������� 
{
	if( lens1 == lens2 )		//overloaded operator ==
		return true;			//�Y���׬۵��^�� true 
	else
		return false;			//�Y���פ��۵��^�� false  
}

double Rectangle::getArea()		//�p�����έ��n 
{
	Length sum;
	sum = ( lens1 * lens2 );		//overloaded operator * 
	return sum.get();			//�^�ǭ��n 
}

double Rectangle::getPerimeter()		//�p�����ΩP�� 
{
	Length sum;
	sum = ( lens1 + lens1 + lens2 + lens2 );		//overloaded operator + 
	return sum.get();			//�^�ǩP�� 
}

#endif
















