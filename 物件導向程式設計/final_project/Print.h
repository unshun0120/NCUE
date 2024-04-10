#include<iostream>
#ifndef PRINT_H
#define PRINT_H

class Print		// 4 個 print function 皆為印出功能 
{
	public :
		virtual void print() const =0;	
};

class addPrint : public Print
{
	public :
		virtual void print() const;
};

class modifyPrint : public Print
{
	public :
		virtual void print() const;	
};

class deletePrint : public Print
{
	public :
		virtual void print() const;		
};

class recoverPrint : public Print
{
	public :
		virtual void print() const;			
};


#endif
