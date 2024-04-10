#include<iostream>
#ifndef LENGTH_H
#define LENGTH_H
using namespace std;
 
class Length
{
	private :
		double side;		//�ŧi 
	public :	
		Length()		//constructor
		{
			side = 1;		//side���w�]�Ȭ�1 
		}
		bool operator==( Length & );		//overloaded operator ==
		Length operator+( Length &);		//overloaded operator +
		Length operator*( Length );			//overloaded operator *
		void set( double );			//set function
		double get()		//get function
		{
			return side;
		}
};


void Length::set( double lens )		//�N�ǤJ���Ʀr�s�Jside�� ,
{
	side = lens;
}

bool Length::operator==( Length &len )		//ovevloaded operator == 
{
	return ( this->get() == len.get() ); 
}

Length Length::operator*( Length len )		//overloaded operator *
{
	Length sum;
	sum.side = this->side * len.side;
	return sum;
}

Length Length::operator+( Length &len )		//overloaded operator +
{
	Length sum;
	sum.side = this->side + len.side;
	return sum ;
}

#endif
