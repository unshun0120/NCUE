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

class Encryption : public Filter			//Encryption �� Filter class ���l���O 
{
	public :
		Encryption( int );			//constructor 
		~Encryption();				//destructor
		void doFilter( ifstream &inFile , ofstream &outFile );			//���ɮװ��ʧ@�� function 
		virtual char transform( char , int ); 			//virtual function : �N�r�����ഫ�� function 
		virtual char replace( char ); 					//virtual function : �N����r��������@�ťժ� function 
};

Encryption::~Encryption()			//destructor
{
	cout<<"The file will be closed !! "<<endl;			//���� input / output �� 
	inFile.close();
	outFile.close();
}

Encryption::Encryption( int n )			//�N�n���ɮװ��ƪ�����r�s�J choose  
{
	choose = n;
}

class lineBreak : public Filter			//abstract class 
{
	public :
		virtual char replace( char ) = 0;			//�N����r���ন��@�ť� 
};

void Encryption::doFilter(ifstream &inFile , ofstream &outFile )			//�n���ɮװ��ƪ�function 
{
	int num;
	char ch;
	char afterTrans;
	if( !inFile )			//�Yinput�ɤ��s�b 
	{
		cout<<"The input file isn't exist !"<<endl;
		exit(1);
	}
	if( !outFile )			//�Youtput�ɤ��s�b 
	{
		cout<<"The output file isn't exist !"<<endl;
		exit(1);
	}
	if( choose == 1 )			//�[�K	
	{	
		inFile.get( ch );			//Ū���ɮפ��Ĥ@�Ӧr�� 
		cout<<"How many position you want to change (�Q���r�������Ω��k���h�� ) "<<endl;		//��J�Q���r�������Ω��k���X�� 
		cout<<"��������J�t�� , ���k����J���� : ";
		cin>>num;
		while( !inFile.fail() )			//Ū���ɮ׳̫� 
		{
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )			//�Y�O�^��r���h�̷ӿ�J���Ʀr�����Ω��k�� 
				afterTrans = transform( ch , num );			// call transform function 
			else 
				afterTrans = ch;			//�Y���O�^��r���h�O����� 
			outFile.put( afterTrans ); 		//�N�ഫ�᪺�r���g�Jouput�� 
			inFile.get( ch );				//�~��Ū���U�@�Ӧr�� 
		}
	}
	else if( choose == 2 )			//��j�g 
	{
		inFile.get( ch );			//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )				//Ū���ɮ׳̫� 
		{
			if( ch >= 97 && ch <= 122 )			//�Y�O�p�g�h�ন�j�g 
				afterTrans = ( ch -32 );
			else 
				afterTrans = ch;				//�Y���O�p�g�^��r���h�O����� 
			outFile.put( afterTrans ); 			//�N�ഫ�᪺�r���g�Jouput�� 	
			inFile.get( ch );					//�~��Ū���U�@�Ӧr�� 
		}
	}
	else if( choose == 3 )		//�ƥ� 
	{
		inFile.get( ch );					//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )				//Ū���ɮ׳̫� 
		{
			afterTrans = ch;				//�����ɮפ����r����������� 
			outFile.put( afterTrans ); 		//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );				//�~��Ū���U�@�Ӧr�� 
		}
	}
	else if( choose == 4 )		//�����ť� 
	{
		inFile.get( ch );				//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )			//Ū���ɮ׳̫� 
		{
			if( ch =='\n' )				//�Y�r��������r���h�ন��@�ť� 
				afterTrans = replace( ch );			//call replace function
			else 
				afterTrans = ch;		//�Y���O����r���h�O����� 
			outFile.put( afterTrans ); 	//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );			//�~��Ū���U�@�Ӧr�� 
		}
	}
	else if( choose == 5 )			//�[�K and ��j�g
	{
		cout<<"How many position you want to change (�Q���r�������Ω��k���h�� ) "<<endl;	//��J�Q���r�������Ω��k���X�� 
		cout<<"��������J�t�� , ���k����J���� : ";
		cin>>num;
		inFile.get( ch );				//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )			//Ū���ɮ׳̫� 
		{
			if( ch >= 97 && ch <= 122 )	//�Y�O�p�g�h�ন�j�g 
				ch -= 32;
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )		//�Y�O�^��r���h�̷ӿ�J���Ʀr�����Ω��k�� 
				afterTrans = transform( ch , num );		// call transform function
			else 
				afterTrans = ch;		//�Y���O�^��r���h�O�����
			outFile.put( afterTrans ); 	//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );		 	//�~��Ū���U�@�Ӧr��  
		}
	}
	else if( choose == 6 )			//�[�K and �N�����ন�ť� 
	{
		cout<<"How many position you want to change (�Q���r�������Ω��k���h�� ) "<<endl;	//��J�Q���r�������Ω��k���X�� 
		cout<<"��������J�t�� , ���k����J���� : ";
		cin>>num;
		inFile.get( ch );				//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )			//Ū���ɮ׳̫�
		{
			if( ch >= 97 && ch <= 122 || ch >=65 && ch <= 90 )		//�Y�O�^��r���h�̷ӿ�J���Ʀr�����Ω��k�� 
				afterTrans = transform( ch , num );		// call transform function
			else if( ch == '\n' )						//�Y�r��������r���h�ন��@�ť� 
				afterTrans = replace( ch );				// call replace function 
			else	
				afterTrans = ch;		//�Y���O����r���άO�^��r���h�O����� 
			outFile.put( afterTrans ); 	//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );			//�~��Ū���U�@�Ӧr��  
		}	
	}
	else if( choose == 7 )			//��j�g and �N�����ন�ť� 
	{
		inFile.get( ch );			//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )		//Ū���ɮ׳̫�
		{
			if( ch >= 97 && ch <= 122 )		//�Y�O�p�g�h�ন�j�g 
				afterTrans = ( ch -32 );
			else if( ch == '\n' )			//�Y�r��������r���h�ন��@�ť� 
				afterTrans = replace( ch );	// call replace function 
			else
				afterTrans = ch; 			//�Y���O����r���άO�^��r���h�O����� 
			outFile.put( afterTrans ); 		//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );				//�~��Ū���U�@�Ӧr��  
		}
	}
	else if( choose == 8 )			//�[�K , ��j�g and �N�����ন�ť� 
	{
		cout<<"How many position you want to change (�Q���r�������Ω��k���h�� ) "<<endl;	//��J�Q���r�������Ω��k���X�� 
		cout<<"��������J�t�� , ���k����J���� : ";
		cin>>num;
		inFile.get( ch );			//Ū���ɮפ��Ĥ@�Ӧr��
		while( !inFile.fail() )		//����Ū���ɮרS���r��
		{
			if( ch >=65 && ch <= 90 )					//�Y�O�j�g�^��r���h�̷ӿ�J���Ʀr�����Ω��k�� 
				afterTrans = transform( ch , num );		//call transform function 
			else if( ch >= 97 && ch <= 122 )			//�Y�O�p�g�r���h���ন�j�g�A�̷ӿ�J���Ʀr�����Ω��k�� 
			{
				ch -= 32;
				afterTrans = transform( ch , num );		//call transform function 
			}			
			else if( ch == '\n' )						//�Y�r��������r���h�ন��@�ť�
				afterTrans = replace( ch );				// call replace function 
			else		
				afterTrans = ch;						//�Y���O����r���άO�^��r���h�O����� 
			outFile.put( afterTrans ); 					//�N�ഫ�᪺�r���g�Jouput��
			inFile.get( ch );							//�~��Ū���U�@�Ӧr��  
		}		
	}
}

char Encryption::transform( char ch , int num ) 		//�ഫ�r�� function 
{
	if( ch >= 97 && ch <= 122 )				//�Y�O�p�g�^��r�� 
	{
		if( ( ch + num ) > 122 )			//�Y���k���W�L�p�g z �h�^�� a �~�򲾰� 
		{
			while( ( ch + num ) > 122 )
				num -= 26;	
		} 
		else if( ( ch + num ) < 97 )		//�Y�������W�L�p�g a �h�^�� z �~�򲾰� 
		{
			while( ( ch + num ) < 97 )
				num += 26;
		}
	}
	else if( ch >= 65 && ch <= 90 )			//�Y�O�j�g�^��r�� 
	{
		if( ( ch + num ) > 90 )				//�Y���k���W�L�j�g Z �h�^�� A �~�򲾰� 
		{
			while( ( ch + num ) > 90 )
				num -= 26;	
		} 
		else if( ( ch + num ) < 65 )		//�Y�������W�L�j�g A �h�|�� Z �~�򲾰� 
		{
			while( ( ch + num ) < 65 )
				num += 26;
		}
	}
	
	return ( ch + num ); 			//return �ഫ�᪺�r�� 
}

char Encryption::replace( char ch )		//�N����r���ন��@�ť� function 
{
	return ( ch + 22 );				//return ��@�r���� ASCII code 
}


#endif





