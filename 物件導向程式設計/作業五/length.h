#include<iostream>
#ifndef LENGTH_H
#define LENGTH_H
using namespace std;
 
class Length
{
	private :
		double side;		//宣告 
	public :	
		Length()		//constructor
		{
			side = 1;		//side的預設值為1 
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


void Length::set( double lens )		//將傳入的數字存入side內 ,
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
