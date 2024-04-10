/*  
	Input�� : in.txt
	Output�� : out.txt 
	t1.txt : �峹 
*/
#include<iostream>
#include<fstream>
#include "filter.h"
using namespace std;

int check( int n )			//�ˬd�n���ɮ׶i��ʧ@�����O�O�_��J���O 1~8 
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
	
	cout<<"Enter the input File's name : ";			//��J input�� 
	cin>>inFileName;
	inFile.open( inFileName );						//���} input�� 
	cout<<"Enter the output File's name : ";		//��J output�� 
	cin>>outFileName;
	outFile.open( outFileName );					//���} output�� 
	
	cout<<"What do you want to do on the file : "<<endl;			//��ܭn�� input�ɪ��ʧ@ 
	cout<<"1 -> Encryption( �[�K ) "<<endl;													//�[�K 
	cout<<"2 -> transform to uppercase ( ��j�g )"<<endl;									//��j�g	
	cout<<"3 -> copy to output file ( �N���ɮ׳ƥ��ܿ�X�� ) "<<endl;						//�ƥ��ܿ�X�� 
	cout<<"4 -> replace line-break with a single space (�N����令�ť�) "<<endl;			//�N����r���ন��@�ť� 
	cout<<"5 -> Encryption and Transform to uppercase "<<endl;								//�[�K,��j�g 
	cout<<"6 -> Encryption and Replace line-break with a single space "<<endl;				//�[�K,�N����r���ন��@�ť� 
	cout<<"7 -> Transform to uppercase and Replace line-break with a single space "<<endl;	//��j�g,�N����r���ন��@�ť� 
	cout<<"8 -> Encryption,Transfrom to uppercase,Replace line-break with single space : ";	//�[�K,��j�g,�N����r���ন��@�ť� 
	cin>>choose;
	choose = check( choose );			//���b 
	Encryption instruct( choose );
	instruct.doFilter( inFile , outFile );
	

	return 0;
}













