#include<iostream>
#include<fstream>
#ifndef FILTER_H
#define FILTER_H
using namespace std;

static int choose;

class Filter			//abstract class
{
	protected :				//Declaration 
		ifstream inFile;
		ofstream outFile;
	public :
		Filter()			//constructor
		{
		}
		virtual char transform( char , int ) = 0;			//virtual function
};

class Encryption : public Filter			//Encryption 為 Filter class 的子類別 
{
	public :
		Encryption( int );			//constructor 
		~Encryption();				//destructor
		void doFilter( ifstream &inFile , ofstream &outFile );			//對檔案做動作的 function 
		virtual char transform( char , int ); 			//virtual function : 將字元做轉換的 function 
		virtual char replace( char ); 					//virtual function : 將換行字元換成單一空白的 function 
};

Encryption::~Encryption()			//destructor
{
	cout<<"The file will be closed !! "<<endl;			//關閉 input / output 檔 
	inFile.close();
	outFile.close();
}

Encryption::Encryption( int n )			//將要對檔案做事的關鍵字存入 choose  
{
	choose = n;
}

class lineBreak : public Filter			//abstract class 
{
	public :
		virtual char replace( char ) = 0;			//將換行字元轉成單一空白 
};

void Encryption::doFilter(ifstream &inFile , ofstream &outFile )			//要對檔案做事的function 
{
	int num;
	char ch;
	char afterTrans;
	if( !inFile )			//若input檔不存在 
	{
		cout<<"The input file isn't exist !"<<endl;
		exit(1);
	}
	if( !outFile )			//若output檔不存在 
	{
		cout<<"The output file isn't exist !"<<endl;
		exit(1);
	}
	if( choose == 1 )			//加密	
	{	
		inFile.get( ch );			//讀取檔案中第一個字元 
		cout<<"How many position you want to change (想讓字母往左或往右移多少 ) "<<endl;		//輸入想讓字元往左或往右移幾個 
		cout<<"往左移輸入負的 , 往右移輸入正的 : ";
		cin>>num;
		while( !inFile.fail() )			//讀到檔案最後 
		{
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )			//若是英文字母則依照輸入的數字往左或往右移 
				afterTrans = transform( ch , num );			// call transform function 
			else 
				afterTrans = ch;			//若不是英文字母則保持原樣 
			outFile.put( afterTrans ); 		//將轉換後的字元寫入ouput檔 
			inFile.get( ch );				//繼續讀取下一個字元 
		}
	}
	else if( choose == 2 )			//轉大寫 
	{
		inFile.get( ch );			//讀取檔案中第一個字元
		while( !inFile.fail() )				//讀到檔案最後 
		{
			if( ch >= 97 && ch <= 122 )			//若是小寫則轉成大寫 
				afterTrans = ( ch -32 );
			else 
				afterTrans = ch;				//若不是小寫英文字母則保持原樣 
			outFile.put( afterTrans ); 			//將轉換後的字元寫入ouput檔 	
			inFile.get( ch );					//繼續讀取下一個字元 
		}
	}
	else if( choose == 3 )		//備份 
	{
		inFile.get( ch );					//讀取檔案中第一個字元
		while( !inFile.fail() )				//讀到檔案最後 
		{
			afterTrans = ch;				//不對檔案中的字元做任何改變 
			outFile.put( afterTrans ); 		//將轉換後的字元寫入ouput檔
			inFile.get( ch );				//繼續讀取下一個字元 
		}
	}
	else if( choose == 4 )		//換行改空白 
	{
		inFile.get( ch );				//讀取檔案中第一個字元
		while( !inFile.fail() )			//讀到檔案最後 
		{
			if( ch =='\n' )				//若字元為換行字元則轉成單一空白 
				afterTrans = replace( ch );			//call replace function
			else 
				afterTrans = ch;		//若不是換行字元則保持原樣 
			outFile.put( afterTrans ); 	//將轉換後的字元寫入ouput檔
			inFile.get( ch );			//繼續讀取下一個字元 
		}
	}
	else if( choose == 5 )			//加密 and 轉大寫
	{
		cout<<"How many position you want to change (想讓字母往左或往右移多少 ) "<<endl;	//輸入想讓字元往左或往右移幾個 
		cout<<"往左移輸入負的 , 往右移輸入正的 : ";
		cin>>num;
		inFile.get( ch );				//讀取檔案中第一個字元
		while( !inFile.fail() )			//讀到檔案最後 
		{
			if( ch >= 97 && ch <= 122 )	//若是小寫則轉成大寫 
				ch -= 32;
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )		//若是英文字母則依照輸入的數字往左或往右移 
				afterTrans = transform( ch , num );		// call transform function
			else 
				afterTrans = ch;		//若不是英文字母則保持原樣
			outFile.put( afterTrans ); 	//將轉換後的字元寫入ouput檔
			inFile.get( ch );		 	//繼續讀取下一個字元  
		}
	}
	else if( choose == 6 )			//加密 and 將換行轉成空白 
	{
		cout<<"How many position you want to change (想讓字母往左或往右移多少 ) "<<endl;	//輸入想讓字元往左或往右移幾個 
		cout<<"往左移輸入負的 , 往右移輸入正的 : ";
		cin>>num;
		inFile.get( ch );				//讀取檔案中第一個字元
		while( !inFile.fail() )			//讀到檔案最後
		{
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )		//若是英文字母則依照輸入的數字往左或往右移 
				afterTrans = transform( ch , num );		// call transform function
			else if( ch == '\n' )						//若字元為換行字元則轉成單一空白 
				afterTrans = replace( ch );				// call replace function 
			else	
				afterTrans = ch;		//若不是換行字元或是英文字母則保持原樣 
			outFile.put( afterTrans ); 	//將轉換後的字元寫入ouput檔
			inFile.get( ch );			//繼續讀取下一個字元  
		}	
	}
	else if( choose == 7 )			//轉大寫 and 將換行轉成空白 
	{
		inFile.get( ch );			//讀取檔案中第一個字元
		while( !inFile.fail() )		//讀到檔案最後
		{
			if( ch >= 97 && ch <= 122 )		//若是小寫則轉成大寫 
				afterTrans = ( ch -32 );
			else if( ch == '\n' )			//若字元為換行字元則轉成單一空白 
				afterTrans = replace( ch );	// call replace function 
			else
				afterTrans = ch; 			//若不是換行字元或是英文字母則保持原樣 
			outFile.put( afterTrans ); 		//將轉換後的字元寫入ouput檔
			inFile.get( ch );				//繼續讀取下一個字元  
		}
	}
	else if( choose == 8 )			//加密 , 轉大寫 and 將換行轉成空白 
	{
		cout<<"How many position you want to change (想讓字母往左或往右移多少 ) "<<endl;	//輸入想讓字元往左或往右移幾個 
		cout<<"往左移輸入負的 , 往右移輸入正的 : ";
		cin>>num;
		inFile.get( ch );			//讀取檔案中第一個字元
		while( !inFile.fail() )		//持續讀到檔案沒有字元
		{
			if( ch >=65 && ch <= 90 )					//若是大寫英文字母則依照輸入的數字往左或往右移 
				afterTrans = transform( ch , num );		//call transform function 
			else if( ch >= 97 && ch <= 122 )			//若是小寫字母則先轉成大寫再依照輸入的數字往左或往右移 
			{
				ch -= 32;
				afterTrans = transform( ch , num );		//call transform function 
			}			
			else if( ch == '\n' )						//若字元為換行字元則轉成單一空白
				afterTrans = replace( ch );				// call replace function 
			else		
				afterTrans = ch;						//若不是換行字元或是英文字母則保持原樣 
			outFile.put( afterTrans ); 					//將轉換後的字元寫入ouput檔
			inFile.get( ch );							//繼續讀取下一個字元  
		}		
	}
}

char Encryption::transform( char ch , int num ) 		//轉換字元 function 
{
	if( ch >= 97 && ch <= 122 )				//若是小寫英文字母 
	{
		if( ( ch + num ) > 122 )			//若往右移超過小寫 z 則回到 a 繼續移動 
		{
			while( ( ch + num ) > 122 )
				num -= 26;	
		} 
		else if( ( ch + num ) < 97 )		//若往左移超過小寫 a 則回到 z 繼續移動 
		{
			while( ( ch + num ) < 97 )
				num += 26;
		}
	}
	else if( ch >= 65 && ch <= 90 )			//若是大寫英文字母 
	{
		if( ( ch + num ) > 90 )				//若往右移超過大寫 Z 則回到 A 繼續移動 
		{
			while( ( ch + num ) > 90 )
				num -= 26;	
		} 
		else if( ( ch + num ) < 65 )		//若往左移超過大寫 A 則會到 Z 繼續移動 
		{
			while( ( ch + num ) < 65 )
				num += 26;
		}
	}
	
	return ( ch + num ); 			//return 轉換後的字元 
}

char Encryption::replace( char ch )		//將換行字元轉成單一空白 function 
{
	return ( ch + 22 );				//return 單一字元的 ASCII code 
}


#endif





