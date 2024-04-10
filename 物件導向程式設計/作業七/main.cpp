/*  
	Input檔 : in.txt
	Output檔 : out.txt 
	t1.txt : 文章 
*/
#include<iostream>
#include<fstream>
#include "filter.h"
using namespace std;

int check( int n )			//檢查要對檔案進行動作的指令是否輸入的是 1~8 
{
	while( n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 && n != 8 )
	{
		cout<<"You have to input 1 ~ 8 "<<endl;
		cout<<"Please enter the number again : ";
		cin>>n;
	}
	
	return n;
}

int main()
{
	int choose;						//Declaration 
	char option;
	ifstream inFile;
	ofstream outFile;
	char inFileName[100] , outFileName[100];
	
	cout<<"Enter the input File's name : ";			//輸入 input檔 
	cin>>inFileName;
	inFile.open( inFileName );						//打開 input檔 
	cout<<"Enter the output File's name : ";		//輸入 output檔 
	cin>>outFileName;
	outFile.open( outFileName );					//打開 output檔 
	
	cout<<"What do you want to do on the file : "<<endl;			//選擇要對 input檔的動作 
	cout<<"1 -> Encryption( 加密 ) "<<endl;													//加密 
	cout<<"2 -> transform to uppercase ( 轉大寫 )"<<endl;									//轉大寫	
	cout<<"3 -> copy to output file ( 將原檔案備份至輸出檔 ) "<<endl;						//備份至輸出檔 
	cout<<"4 -> replace line-break with a single space (將換行改成空白) "<<endl;			//將換行字元轉成單一空白 
	cout<<"5 -> Encryption and Transform to uppercase "<<endl;								//加密,轉大寫 
	cout<<"6 -> Encryption and Replace line-break with a single space "<<endl;				//加密,將換行字元轉成單一空白 
	cout<<"7 -> Transform to uppercase and Replace line-break with a single space "<<endl;	//轉大寫,將換行字元轉成單一空白 
	cout<<"8 -> Encryption,Transfrom to uppercase,Replace line-break with single space : ";	//加密,轉大寫,將換行字元轉成單一空白 
	cin>>choose;
	choose = check( choose );			//防呆 
	Encryption instruct( choose );
	instruct.doFilter( inFile , outFile );
	

	return 0;
}













