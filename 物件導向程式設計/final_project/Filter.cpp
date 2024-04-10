#include<iostream>
#include "Filter.h"

char Filter::Encryption( char finalPhoneNumber) 	//手機號碼最後一碼 + 2  
{
	if( finalPhoneNumber + 2  == 58 )	//若最後一碼為 8 則變 0 ( 8 + 2 = 10 ) 
		finalPhoneNumber = '0';
	else  if( finalPhoneNumber + 2 == 59 )	//若最後一碼為 9 則變 1 ( 9 + 2 = 11 ) 
		finalPhoneNumber = '1';
	else
		finalPhoneNumber += 2;	
	return finalPhoneNumber;	
}

char File::Encryption( char ch )	//工作證第一碼英文字母往後 2 個字母 
{
	if( ch + 2 == 91 )	//若英文字母為 Y 則變 A  
		ch = 'A';
	else if( ch + 2 == 92 )	//若英文字母為 Z 則變 B 
		ch = 'B';
	else 
		ch += 2;
	
	return ch;
}

char numFile::Encryption( char num )	//工作證最後一碼數字 + 2 
{
	if( num + 2  == 58 )	//若最後一碼為 8 則變 0 ( 8 + 2 = 10 )  
		num = '0';
	else  if( num + 2 == 59 )	//若最後一碼為 9 則變 1 ( 9 + 2 = 11 )  
		num = '1';
	else
		num += 2;	
	return num;	
} 
