#include<iostream>
#include<string>
#ifndef PUBLICATION_H
#define PUBLICATION_H
using namespace std;

class Publication
{
	private :
		string title;			//Declaration 
		long long int volume;
		int year;
	public :	
		void setTitle( string Title )		//�x�s�ѥ��W�� 
		{
			title = Title;	
		} 
		string getTitle()		//�^�Ǯѥ��W�� 
		{
			return title;	
		} 
		
		void setVolume( long long int Volume )		//�x�s�ƶq 
		{
			volume = Volume;
		}
		long long int getVolume()		//�^�Ǽƶq 
		{
			return volume;
		}
	
		void setYear( int Year )		//�x�s�~�� 
		{
			year = Year;	
		}	
		int getYear()			//�^�Ǧ~�� 
		{
			return year;
		}

};

class Book : public Publication			//�N Book class �]�� Publication class ���l���O 
{
	private :						//Declaration
		string author;
		string ISBN;
		long long int price;
	public :
		void setAuthor( string name )		//�x�s�@�̦W�� 
		{
			author = name;
		}
		string getAuthor()			//�^�ǧ@�̦W�� 
		{
			return author;
		}
		
		void setISBN( string isbn )			//�x�s ISBN 
		{
			ISBN = isbn;
		}
		string getISBN()			//�^�� ISBN 
		{
			return ISBN;
		}
		
		void setPrice( long long int money )		//�x�s���� 
		{
			price = money;
		}
		long long int getPrice()		//�^�ǻ��� 
		{
			return price;
		}

	
};

class Journal :public Publication		//�N Journal class �]�� Publication class ���l���O 
{
	private :				//Declaration 
		int month;
		string ISSN;
		double impactFactor;
		long long int annualSubscription;
	public :
		void setMonth( int Month )		//�x�s��� 
		{
			month = Month;
		}
		int getMonth()			//�^�Ǥ�� 
		{
			return month;
		}
		
		void setISSN( string issn )		//�x�s ISSN 
		{
			ISSN = issn;
		}
		string getISSN()	//�^�� ISSN 
		{
			return ISSN;
		}
		
		void setImpactFactor( double factor )			//�x�s�v�T�Y�� 
		{
			impactFactor = factor;
		}
		double getImpactFactor()			//�^�Ǽv�T�Y�� 
		{
			return impactFactor;	
		} 
		
		void setAnnualSubscription( long long int num )			//�x�s�X������ 
		{
			annualSubscription = num;
		}
		long long int getAnnualSubscription()		//�^�ǥX������ 
		{
			return annualSubscription;
		}
	
};

class Magazine : public Publication			//�N Magazine class �]�� Publication class ���l���O 
{	
	private :					//Declaration 
		int month;	
		string editor;
		long long int annualSubscription;
	public :
		void setMonth( int Month )			//�x�s��� 
		{
			month = Month;	
		} 
		int getMonth()			//�^�Ǥ�� 
		{
			return month;
		}
		
		void setEditor( string name )		//�x�s�s��̦W�� 
		{
			editor = name;
		}
		string getEditor()		//�^�ǽs��̦W�� 
		{
			return editor;
		}
		
		void setAnnualSubscription( long long int num )		//�x�s�X������ 
		{
			annualSubscription = num;	
		}	
		long long int getAnnualSubscription()		//�^�ǥX������ 
		{
			return annualSubscription;
		}
};





















#endif
