#include<iostream>
#include<string>
#include "publication.h"
using namespace std;

char checkType( char type )			//防呆 : 檢查輸入 type (書本出版類型) 是否是 b/j/m 其中一個 
{
	while( type != 'B' && type != 'b' && type != 'J' && type != 'j' && type != 'M' && type != 'm' )
	{
		cout<<"You have to enter B/b , J/j or M/m ."<<endl;
		cout<<"PLease enter book's type again : ";
		cin>>type;
	}
	
	return type;
}

int checkVolume( int volume )			//防呆 : 檢查 Volume (數量) 是否小於等於 0 
{
	while( volume < 0 )
	{
		cout<<"You have to enter positive nmber ! "<<endl;
		cout<<"PLease enter volume again : ";
		cin>>volume;
	}
	
	return volume;
}

int checkYear( int year )			//防呆 : 檢查 year (年分) 是否超過 2021 或是小於 0 
{
	while( year > 2021 || year <= 0 )
	{
		if( year > 2021 )
		{
			cout<<"You have to enetr the year which smaller than 2022 !"<<endl;
			cout<<"Please enter year again : ";
			cin>>year;
		}
		else if( year <= 0 )
		{
			cout<<"You have to enter positive and nonzero number !"<<endl;
			cout<<"Please enter year again : ";
			cin>>year;
		}
	}
	
	return year;
}

string checkISBN( int lens )			//防呆 : 檢查 ISBN (書號) 是否是 10 位數字 
{
	string isbn;
	while( lens != 10 )
	{
		cout<<"You have to enter 10 numbers !"<<endl;
		cout<<"Please enter ISBN again : ";
		cin>>isbn;
		lens = isbn.size();
	}
	
	return isbn;
}

int checkPrice( int price )			//防呆 : 檢查 price (價錢) 是否小於 0 
{
	while( price < 0 )
	{
		cout<<"You have to enter positive number !"<<endl;
		cout<<"Please enter money again : ";
		cin>>price;
	}
	
	return price;
}

int checkMonth( int month )			//防呆 : 檢查 month (月份) 是否是在 1 到 12 月 
{
	while( month < 1 || month > 12 )
	{
		cout<<"You have to enetr 1 ~ 12 !"<<endl;
		cout<<"Please enter month again : ";
		cin>>month;
	}
	
	return month;
}
string checkISSN( int lens )		//防呆 : 檢查 ISSN (期刊號) 是否 8 位數 
{
	string issn;
	while( lens != 8 )
	{
		cout<<"You have to enter 8 numbers !"<<endl;
		cout<<"Please enter ISSN again : ";
		cin>>issn;
		lens = issn.size();
	}
	
	return issn;
}

double checkImpactFactor( double factor )		//防呆 : ImpactFactor (影響係數) 是否小於 0  
{
	while( factor < 0 )
	{
		cout<<"You have to enter positive and nonzero number !"<<endl;
		cout<<"Please enter ImpactFactor again : ";
		cin>>factor;
	}
	
	return factor;
}

int checkSubscription( int subscription )			//防呆 : 檢查 annualSubscription 是否小於 0  
{
	while( subscription < 0 )
	{
		cout<<"You have to enter positive or zero number !"<<endl;
		cout<<"Please enter AnnualSubscription again : ";
		cin>>subscription;
	 } 
	 
	 return subscription;
}

char checkChoose( char choose )			//防呆 : 檢查 choose (是否繼續輸入的指令) 是否為 y 或 n 其中一個 
{
	while( choose !='Y' && choose != 'y' && choose != 'N' && choose != 'n' )
	{
		cout<<"You have enter Y/y or N/n !"<<endl;
		cout<<"Please enter choose again : ";
		cin>>choose;	
	}	
	
	return choose;
} 


int main()
{
	int i ,lens;			//Declaration
	char type ,choose;
	int year,
		month;
	string title,
		   author,
		   editor,
		   isbn,
		   issn;
	double impactFactor;
	long long int volume,
				  price,
			      annualSubscription;
	Book book;
	Journal journal;
	Magazine magazine; 

	do
	{ 
		cout<<"What type of books you want to enter\n( b -> book / j -> journal / m -> magazine ) : ";		//詢問出版書本類型 
		cin>>type;
		type = checkType( type );		//防呆 
		
		if( type == 'B' || type == 'b' )		//書籍 
		{
			cout<<"Please enter Book's title ( English , Chinese ) : ";			//輸入書本名稱 
			cin>>title;
			book.setTitle( title );			//將書本名稱存入 Book class 裡面
			 
			cout<<"Please enter Book's volume ( volume >= 0 ) : ";			//輸入書本數量 
			cin>>volume;
			volume = checkVolume( volume );			//防呆 
			book.setVolume( volume );		//將數量存入 Book class 裡面 
					
			cout<<"Please enter Book's year ( year <= 2021 && year > 0 ) : ";			//輸入年分 
			cin>>year;
			year = checkYear( year );		//防呆 
			book.setYear( year );			//將年份存入 Book class 裡面 
			
			cout<<"Please enter book's author ( English or Chinese ) : ";		//輸入作者 
			cin>>author;
			book.setAuthor( author );		//將作者存入 Book class 裡面 
			
			cout<<"Please enter book's ISBN ( 共10位數字 ) : ";			//輸入ISBN 
			cin>>isbn;
			lens = isbn.size();			//ISBN長度 (用來檢查是否 10 位數) 
			isbn = checkISBN( lens );		//防呆  
			book.setISBN( isbn );			//將 ISBN 存入 Book class 裡面 
			
			cout<<"Please enter book's price ( price >= 0 ) : ";		//輸入書本價錢 
			cin>>price;
			price = checkPrice( price );		//防呆 
			book.setPrice( price );			//將價錢存入 Book class 裡面 
			
			cout<<endl<<"Book's Title : "<<book.getTitle()<<endl;			//輸出 書本名稱 
			cout<<"       Volume : "<<book.getVolume()<<endl;				//     數量 
			cout<<"       Year : "<<book.getYear()<<endl; 					//     年分 
			cout<<"       Author : "<<book.getAuthor()<<endl;				//	   作者 
			cout<<"       ISBN : ";											//     ISBN  
			for(i=0;i<=2;i++)
				cout<<book.getISBN()[i];
			cout<<"-";
			for(i=3;i<=5;i++)	
				cout<<book.getISBN()[i];
			cout<<"-";
			for(i=6;i<=8;i++)
				cout<<book.getISBN()[i];
			cout<<"-";
			cout<<book.getISBN()[9]<<endl;
			cout<<"       Price : "<<book.getPrice()<<endl;					//     價錢 
			
		}
		else if( type == 'J' || type == 'j' )		//期刊 
		{
			cout<<"Please enter Journal's title ( English or Chinese ) : ";			//輸入期刊名稱 
			cin>>title;
			journal.setTitle( title );			//將期刊名稱存入 Journal class 裡面
			 
			cout<<"Please enter Journal's volume ( volume >= 0 ) : ";			//輸入期刊數量 
			cin>>volume;
			volume = checkVolume( volume );			//防呆 
			journal.setVolume( volume );			//將數量存入 Journal class 裡面
			 
			cout<<"Please enter Journal's year ( year <= 2021 && year > 0 ) : ";		//輸入年分 
			cin>>year;
			year = checkYear( year );		//防呆 
			journal.setYear( year );		//將年份存入 Journal class 裡面
			 
			cout<<"Please enter Journal's month ( 1 ~ 12 ) : ";			//輸入月份 
			cin>>month;
			month = checkMonth( month );		//防呆 
			journal.setMonth( month );			//將月份存入 Journal class 裡面
			 
			cout<<"PLease enter Journal's ISSN ( 共8位數 ) : ";			//輸入ISSN 
			cin>>issn;
			lens = issn.size();				//ISSN 長度 (用來檢查是否 8 位數字)
			issn = checkISSN( lens );			//防呆	 
			journal.setISSN( issn );			//將 ISSN 存入 Journal class 裡面
			 
			cout<<"Please enter Journal's impactFactor ( 小數 ) : ";		//輸入影響係數 
			cin>>impactFactor;
			impactFactor = checkImpactFactor( impactFactor );			//防呆 
			journal.setImpactFactor( impactFactor );				//將影響係數存入 Journal class 裡面
			 
			cout<<"Please enter Journal's annualSubscription ( subscription >= 0 ) : ";			//輸入出版期數 
			cin>>annualSubscription;
			annualSubscription = checkSubscription( annualSubscription );		//防呆 
			journal.setAnnualSubscription( annualSubscription );			//將出版期數存入 Journal class 裡面 
			
			cout<<endl<<"Journal's Title : "<<journal.getTitle()<<endl;				//輸出 期刊名稱 
			cout<<"          Volume : "<<journal.getVolume()<<endl;					//	   數量 
			cout<<"          Year : "<<journal.getYear()<<endl; 					//     年分 
			cout<<"          Month : "<<journal.getMonth()<<endl;					//     月份 
			cout<<"          ISSN : ";												//     ISSN 
			for(i=0;i<=3;i++)
				cout<<journal.getISSN()[i];
			cout<<"-";
			for(i=4;i<=7;i++)
				cout<<journal.getISSN()[i];
			cout<<endl;
			cout<<"          impactFactor　: "<<journal.getImpactFactor()<<endl;	//     影響係數 
			cout<<"          annualSubscription : "<<journal.getAnnualSubscription()<<endl; // 出版騎術 
		}
		else if( type == 'M' || type == 'm' )		//雜誌 
		{
			cout<<"Please enter Magazine's title ( English or Chinese ) : ";			//輸入雜誌名稱 
			cin>>title;
			magazine.setTitle( title );			//將雜誌名稱存入 Magazine class 裡面
			cout<<"Please enter Magazine's volume ( volume >= 0 ) : ";			//輸入數量 
			cin>>volume;
			volume = checkVolume( volume );			//防呆 
			magazine.setVolume( volume );			//將數量存入 Magazine class 裡面
			cout<<"Please enter Magazine's year ( year <= 2021 ) : ";			//輸入年分 
			cin>>year;
			year = checkYear( year );				//防呆 
			magazine.setYear( year );				//將年分存入 Magazine class 裡面
			cout<<"Please enter Magazine's month ( 1 ~ 12 ) : ";			//輸入月份 
			cin>>month;
			month = checkMonth( month );		//防呆 
			magazine.setMonth( month );			//將月份存入 Magazine class 裡面
			cout<<"Please enter Magazine's editor ( English or Chinese ) : ";			//輸入編輯者名稱 
			cin>>editor;
			magazine.setEditor( editor );		//將編輯者名稱存入 Magazine class 裡面 
			cout<<"Please enter Magazine's annualSubscription ( subscription >= 0 ) : ";		//輸入出版期數 
			cin>>annualSubscription;
			annualSubscription = checkSubscription( annualSubscription );		//防呆 
			magazine.setAnnualSubscription( annualSubscription );			//將出版期數存入 Magazine class 裡面
			
			cout<<endl<<"Magazine's Title : "<<magazine.getTitle()<<endl;						//輸出 雜誌名稱 
			cout<<"           Volume : "<<magazine.getVolume()<<endl;							// 	   數量 
			cout<<"           Year : "<<magazine.getYear()<<endl; 								//     年分 
			cout<<"       	  Month : "<<magazine.getMonth()<<endl;								//     月份 
			cout<<"           Editor : "<<magazine.getEditor()<<endl;							//     編輯者 
			cout<<"           AnnualSubscription : "<<magazine.getAnnualSubscription()<<endl;	//     出版期數 
		}
		
		cout<<"Do you want to keep entering book's type ? ";			//詢問是否繼續輸入出版書本類型 
		cin>>choose;
		choose = checkChoose( choose );			//防呆 
		
	}while( choose == 'Y' || choose == 'y' );
	
	
	
	return 0;
}


























