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
		void setTitle( string Title )		//儲存書本名稱 
		{
			title = Title;	
		} 
		string getTitle()		//回傳書本名稱 
		{
			return title;	
		} 
		
		void setVolume( long long int Volume )		//儲存數量 
		{
			volume = Volume;
		}
		long long int getVolume()		//回傳數量 
		{
			return volume;
		}
	
		void setYear( int Year )		//儲存年分 
		{
			year = Year;	
		}	
		int getYear()			//回傳年分 
		{
			return year;
		}

};

class Book : public Publication			//將 Book class 設為 Publication class 的子類別 
{
	private :						//Declaration
		string author;
		string ISBN;
		long long int price;
	public :
		void setAuthor( string name )		//儲存作者名稱 
		{
			author = name;
		}
		string getAuthor()			//回傳作者名稱 
		{
			return author;
		}
		
		void setISBN( string isbn )			//儲存 ISBN 
		{
			ISBN = isbn;
		}
		string getISBN()			//回傳 ISBN 
		{
			return ISBN;
		}
		
		void setPrice( long long int money )		//儲存價錢 
		{
			price = money;
		}
		long long int getPrice()		//回傳價錢 
		{
			return price;
		}

	
};

class Journal :public Publication		//將 Journal class 設為 Publication class 的子類別 
{
	private :				//Declaration 
		int month;
		string ISSN;
		double impactFactor;
		long long int annualSubscription;
	public :
		void setMonth( int Month )		//儲存月份 
		{
			month = Month;
		}
		int getMonth()			//回傳月份 
		{
			return month;
		}
		
		void setISSN( string issn )		//儲存 ISSN 
		{
			ISSN = issn;
		}
		string getISSN()	//回傳 ISSN 
		{
			return ISSN;
		}
		
		void setImpactFactor( double factor )			//儲存影響係數 
		{
			impactFactor = factor;
		}
		double getImpactFactor()			//回傳影響係數 
		{
			return impactFactor;	
		} 
		
		void setAnnualSubscription( long long int num )			//儲存出版期數 
		{
			annualSubscription = num;
		}
		long long int getAnnualSubscription()		//回傳出版期數 
		{
			return annualSubscription;
		}
	
};

class Magazine : public Publication			//將 Magazine class 設為 Publication class 的子類別 
{	
	private :					//Declaration 
		int month;	
		string editor;
		long long int annualSubscription;
	public :
		void setMonth( int Month )			//儲存月份 
		{
			month = Month;	
		} 
		int getMonth()			//回傳月份 
		{
			return month;
		}
		
		void setEditor( string name )		//儲存編輯者名稱 
		{
			editor = name;
		}
		string getEditor()		//回傳編輯者名稱 
		{
			return editor;
		}
		
		void setAnnualSubscription( long long int num )		//儲存出版期數 
		{
			annualSubscription = num;	
		}	
		long long int getAnnualSubscription()		//回傳出版期數 
		{
			return annualSubscription;
		}
};





















#endif
