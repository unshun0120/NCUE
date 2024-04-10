#include<iostream>
#include<string>
#include "publication.h"
using namespace std;

char checkType( char type )			//���b : �ˬd��J type (�ѥ��X������) �O�_�O b/j/m �䤤�@�� 
{
	while( type != 'B' && type != 'b' && type != 'J' && type != 'j' && type != 'M' && type != 'm' )
	{
		cout<<"You have to enter B/b , J/j or M/m ."<<endl;
		cout<<"PLease enter book's type again : ";
		cin>>type;
	}
	
	return type;
}

int checkVolume( int volume )			//���b : �ˬd Volume (�ƶq) �O�_�p�󵥩� 0 
{
	while( volume < 0 )
	{
		cout<<"You have to enter positive nmber ! "<<endl;
		cout<<"PLease enter volume again : ";
		cin>>volume;
	}
	
	return volume;
}

int checkYear( int year )			//���b : �ˬd year (�~��) �O�_�W�L 2021 �άO�p�� 0 
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

string checkISBN( int lens )			//���b : �ˬd ISBN (�Ѹ�) �O�_�O 10 ��Ʀr 
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

int checkPrice( int price )			//���b : �ˬd price (����) �O�_�p�� 0 
{
	while( price < 0 )
	{
		cout<<"You have to enter positive number !"<<endl;
		cout<<"Please enter money again : ";
		cin>>price;
	}
	
	return price;
}

int checkMonth( int month )			//���b : �ˬd month (���) �O�_�O�b 1 �� 12 �� 
{
	while( month < 1 || month > 12 )
	{
		cout<<"You have to enetr 1 ~ 12 !"<<endl;
		cout<<"Please enter month again : ";
		cin>>month;
	}
	
	return month;
}
string checkISSN( int lens )		//���b : �ˬd ISSN (���Z��) �O�_ 8 ��� 
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

double checkImpactFactor( double factor )		//���b : ImpactFactor (�v�T�Y��) �O�_�p�� 0  
{
	while( factor < 0 )
	{
		cout<<"You have to enter positive and nonzero number !"<<endl;
		cout<<"Please enter ImpactFactor again : ";
		cin>>factor;
	}
	
	return factor;
}

int checkSubscription( int subscription )			//���b : �ˬd annualSubscription �O�_�p�� 0  
{
	while( subscription < 0 )
	{
		cout<<"You have to enter positive or zero number !"<<endl;
		cout<<"Please enter AnnualSubscription again : ";
		cin>>subscription;
	 } 
	 
	 return subscription;
}

char checkChoose( char choose )			//���b : �ˬd choose (�O�_�~���J�����O) �O�_�� y �� n �䤤�@�� 
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
		cout<<"What type of books you want to enter\n( b -> book / j -> journal / m -> magazine ) : ";		//�߰ݥX���ѥ����� 
		cin>>type;
		type = checkType( type );		//���b 
		
		if( type == 'B' || type == 'b' )		//���y 
		{
			cout<<"Please enter Book's title ( English , Chinese ) : ";			//��J�ѥ��W�� 
			cin>>title;
			book.setTitle( title );			//�N�ѥ��W�٦s�J Book class �̭�
			 
			cout<<"Please enter Book's volume ( volume >= 0 ) : ";			//��J�ѥ��ƶq 
			cin>>volume;
			volume = checkVolume( volume );			//���b 
			book.setVolume( volume );		//�N�ƶq�s�J Book class �̭� 
					
			cout<<"Please enter Book's year ( year <= 2021 && year > 0 ) : ";			//��J�~�� 
			cin>>year;
			year = checkYear( year );		//���b 
			book.setYear( year );			//�N�~���s�J Book class �̭� 
			
			cout<<"Please enter book's author ( English or Chinese ) : ";		//��J�@�� 
			cin>>author;
			book.setAuthor( author );		//�N�@�̦s�J Book class �̭� 
			
			cout<<"Please enter book's ISBN ( �@10��Ʀr ) : ";			//��JISBN 
			cin>>isbn;
			lens = isbn.size();			//ISBN���� (�Ψ��ˬd�O�_ 10 ���) 
			isbn = checkISBN( lens );		//���b  
			book.setISBN( isbn );			//�N ISBN �s�J Book class �̭� 
			
			cout<<"Please enter book's price ( price >= 0 ) : ";		//��J�ѥ����� 
			cin>>price;
			price = checkPrice( price );		//���b 
			book.setPrice( price );			//�N�����s�J Book class �̭� 
			
			cout<<endl<<"Book's Title : "<<book.getTitle()<<endl;			//��X �ѥ��W�� 
			cout<<"       Volume : "<<book.getVolume()<<endl;				//     �ƶq 
			cout<<"       Year : "<<book.getYear()<<endl; 					//     �~�� 
			cout<<"       Author : "<<book.getAuthor()<<endl;				//	   �@�� 
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
			cout<<"       Price : "<<book.getPrice()<<endl;					//     ���� 
			
		}
		else if( type == 'J' || type == 'j' )		//���Z 
		{
			cout<<"Please enter Journal's title ( English or Chinese ) : ";			//��J���Z�W�� 
			cin>>title;
			journal.setTitle( title );			//�N���Z�W�٦s�J Journal class �̭�
			 
			cout<<"Please enter Journal's volume ( volume >= 0 ) : ";			//��J���Z�ƶq 
			cin>>volume;
			volume = checkVolume( volume );			//���b 
			journal.setVolume( volume );			//�N�ƶq�s�J Journal class �̭�
			 
			cout<<"Please enter Journal's year ( year <= 2021 && year > 0 ) : ";		//��J�~�� 
			cin>>year;
			year = checkYear( year );		//���b 
			journal.setYear( year );		//�N�~���s�J Journal class �̭�
			 
			cout<<"Please enter Journal's month ( 1 ~ 12 ) : ";			//��J��� 
			cin>>month;
			month = checkMonth( month );		//���b 
			journal.setMonth( month );			//�N����s�J Journal class �̭�
			 
			cout<<"PLease enter Journal's ISSN ( �@8��� ) : ";			//��JISSN 
			cin>>issn;
			lens = issn.size();				//ISSN ���� (�Ψ��ˬd�O�_ 8 ��Ʀr)
			issn = checkISSN( lens );			//���b	 
			journal.setISSN( issn );			//�N ISSN �s�J Journal class �̭�
			 
			cout<<"Please enter Journal's impactFactor ( �p�� ) : ";		//��J�v�T�Y�� 
			cin>>impactFactor;
			impactFactor = checkImpactFactor( impactFactor );			//���b 
			journal.setImpactFactor( impactFactor );				//�N�v�T�Y�Ʀs�J Journal class �̭�
			 
			cout<<"Please enter Journal's annualSubscription ( subscription >= 0 ) : ";			//��J�X������ 
			cin>>annualSubscription;
			annualSubscription = checkSubscription( annualSubscription );		//���b 
			journal.setAnnualSubscription( annualSubscription );			//�N�X�����Ʀs�J Journal class �̭� 
			
			cout<<endl<<"Journal's Title : "<<journal.getTitle()<<endl;				//��X ���Z�W�� 
			cout<<"          Volume : "<<journal.getVolume()<<endl;					//	   �ƶq 
			cout<<"          Year : "<<journal.getYear()<<endl; 					//     �~�� 
			cout<<"          Month : "<<journal.getMonth()<<endl;					//     ��� 
			cout<<"          ISSN : ";												//     ISSN 
			for(i=0;i<=3;i++)
				cout<<journal.getISSN()[i];
			cout<<"-";
			for(i=4;i<=7;i++)
				cout<<journal.getISSN()[i];
			cout<<endl;
			cout<<"          impactFactor�@: "<<journal.getImpactFactor()<<endl;	//     �v�T�Y�� 
			cout<<"          annualSubscription : "<<journal.getAnnualSubscription()<<endl; // �X���M�N 
		}
		else if( type == 'M' || type == 'm' )		//���x 
		{
			cout<<"Please enter Magazine's title ( English or Chinese ) : ";			//��J���x�W�� 
			cin>>title;
			magazine.setTitle( title );			//�N���x�W�٦s�J Magazine class �̭�
			cout<<"Please enter Magazine's volume ( volume >= 0 ) : ";			//��J�ƶq 
			cin>>volume;
			volume = checkVolume( volume );			//���b 
			magazine.setVolume( volume );			//�N�ƶq�s�J Magazine class �̭�
			cout<<"Please enter Magazine's year ( year <= 2021 ) : ";			//��J�~�� 
			cin>>year;
			year = checkYear( year );				//���b 
			magazine.setYear( year );				//�N�~���s�J Magazine class �̭�
			cout<<"Please enter Magazine's month ( 1 ~ 12 ) : ";			//��J��� 
			cin>>month;
			month = checkMonth( month );		//���b 
			magazine.setMonth( month );			//�N����s�J Magazine class �̭�
			cout<<"Please enter Magazine's editor ( English or Chinese ) : ";			//��J�s��̦W�� 
			cin>>editor;
			magazine.setEditor( editor );		//�N�s��̦W�٦s�J Magazine class �̭� 
			cout<<"Please enter Magazine's annualSubscription ( subscription >= 0 ) : ";		//��J�X������ 
			cin>>annualSubscription;
			annualSubscription = checkSubscription( annualSubscription );		//���b 
			magazine.setAnnualSubscription( annualSubscription );			//�N�X�����Ʀs�J Magazine class �̭�
			
			cout<<endl<<"Magazine's Title : "<<magazine.getTitle()<<endl;						//��X ���x�W�� 
			cout<<"           Volume : "<<magazine.getVolume()<<endl;							// 	   �ƶq 
			cout<<"           Year : "<<magazine.getYear()<<endl; 								//     �~�� 
			cout<<"       	  Month : "<<magazine.getMonth()<<endl;								//     ��� 
			cout<<"           Editor : "<<magazine.getEditor()<<endl;							//     �s��� 
			cout<<"           AnnualSubscription : "<<magazine.getAnnualSubscription()<<endl;	//     �X������ 
		}
		
		cout<<"Do you want to keep entering book's type ? ";			//�߰ݬO�_�~���J�X���ѥ����� 
		cin>>choose;
		choose = checkChoose( choose );			//���b 
		
	}while( choose == 'Y' || choose == 'y' );
	
	
	
	return 0;
}


























