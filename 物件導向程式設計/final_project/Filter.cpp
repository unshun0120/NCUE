#include<iostream>
#include "Filter.h"

char Filter::Encryption( char finalPhoneNumber) 	//������X�̫�@�X + 2  
{
	if( finalPhoneNumber + 2  == 58 )	//�Y�̫�@�X�� 8 �h�� 0 ( 8 + 2 = 10 ) 
		finalPhoneNumber = '0';
	else  if( finalPhoneNumber + 2 == 59 )	//�Y�̫�@�X�� 9 �h�� 1 ( 9 + 2 = 11 ) 
		finalPhoneNumber = '1';
	else
		finalPhoneNumber += 2;	
	return finalPhoneNumber;	
}

char File::Encryption( char ch )	//�u�@�ҲĤ@�X�^��r������ 2 �Ӧr�� 
{
	if( ch + 2 == 91 )	//�Y�^��r���� Y �h�� A  
		ch = 'A';
	else if( ch + 2 == 92 )	//�Y�^��r���� Z �h�� B 
		ch = 'B';
	else 
		ch += 2;
	
	return ch;
}

char numFile::Encryption( char num )	//�u�@�ҳ̫�@�X�Ʀr + 2 
{
	if( num + 2  == 58 )	//�Y�̫�@�X�� 8 �h�� 0 ( 8 + 2 = 10 )  
		num = '0';
	else  if( num + 2 == 59 )	//�Y�̫�@�X�� 9 �h�� 1 ( 9 + 2 = 11 )  
		num = '1';
	else
		num += 2;	
	return num;	
} 
