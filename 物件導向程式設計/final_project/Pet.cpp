#include "Pet.h"
#include<string>
#include<iostream>
using namespace std;

string makeUp( string mService , string sService )	//�A�Ȫ�O 
{	
	if( mService == "���e" )
	{
		if( sService == "�~��" )
			return "250";
		else if( sService == "�פ�" )
			return "150";
		else if( sService == "�~��+�פ�" ) 
			return "400";
	} 
	else if( mService == "����" )
	{
		if( sService == "�P�_����" )
			return "500";
		else if( sService == "�~���N" )
			return "3000";
	}	
}

bool Pet::operator==( Pet& date )		//operator overloading  
{
	return this->getDate() == date.getDate();
}

void Pet::addInformation()		//�s�W��� 
{
	string oName,
	  	   phone,
	       type,
	       pName,
	       mService,
	       sService,
	       number,
	       Date,
	       ID,
		   money;
	int count_choose , cost_choose , service_choose;
	cout<<endl<<"You want to add new information in the file "<<endl;
	cout<<"Please enter the owner's name �D�H�W�r : ";
	cin>>oName;
	cout<<"Please enter the owner's phone �D�H�q�� : ";
	cin>>phone;
	int phoneLens = phone.size();
	while( phone[0] != '0' && phone[1] != '9' || phoneLens != 10 )		//���b���� 
	{
		cout<<"Your phone number need to be the 09XXXXXXXX and it has 10 numbers "<<endl;
		cout<<"Please enter again "<<endl;
		cout<<"�z��J���q�ܸ��X������ 09 �}�Y �B�]�A 09 �ݦ@ 10 ��Ʀr"<<endl;
		cout<<"�бz�b��J�@�� : "<<endl; 
		cin>>phone;
		phoneLens = phone.size();
	}
	cout<<"Please enetr pet's type �d������ : ";
	cin>>type;
	cout<<"Please enter pet's name �d���W�r : ";
	cin>>pName;
	cout<<"Please enter the main service �D�n�A�� : ";
	cin>>mService;
	cout<<"Please enter the subservice �A�Ȥl���� : ";
	cin>>sService;
	if( mService == "���e" )		//�Y�D�n�A�ȻP�A�Ȥl���ذt�藍���T 
	{
		while( sService == "�P�_����" || sService == "�~���N" )
		{
			cout<<"Your main service and your subservice doesn't match"<<endl;
			cout<<"�z���D�n�A�ȻP�A�Ȥl���بå��t�勵�T"<<endl;
			cout<<"�п�ܱz�n�ק諸���ئW��"<<endl;
			cout<<"1 -> main Service �D�n�A�� "<<endl;
			cout<<"2 -> subService �A�Ȥl���� "<<endl; 
			cin>>service_choose;
			while( service_choose != 1 && service_choose != 2 )
			{
				cout<<"You have to enter 1 or 2"<<endl;
				cout<<"Please enter again ";
				cin>>service_choose;
			}
			if( service_choose == 1 )
			{
				cout<<"Please enter main Service �D�n�A�� : "<<endl;
				cin>>mService;
				goto exit_service;
			}
			else if( service_choose == 2 )
			{
				cout<<"Please enter subService �A�Ȥl���� : "<<endl;
				cin>>sService;
			}
		}
	}
	else if( mService == "����" )
	{
		while( sService == "�~��" || sService == "�פ�" || sService == "�~��+�פ�" )
		{
			cout<<"Your main service and your subservice doesn't match"<<endl;
			cout<<"�z���D�n�A�ȻP�A�Ȥl���بå��t�勵�T"<<endl;
			cout<<"�п�ܱz�n�ק諸���ئW��"<<endl;
			cout<<"1 -> main Service �D�n�A�� "<<endl;
			cout<<"2 -> subService �A�Ȥl���� "<<endl; 
			cin>>service_choose;
			while( service_choose != 1 && service_choose != 2 )
			{
				cout<<"You have to enter 1 or 2"<<endl;
				cout<<"Please enter again ";
				cin>>service_choose;
			}
			if( service_choose == 1 )
			{
				cout<<"Please enter main Service �D�n�A�� : "<<endl;
				cin>>mService;
				goto exit_service;
			}
			else if( service_choose == 2 )
			{
				cout<<"Please enter subService �A�Ȥl���� : "<<endl;
				cin>>sService;
			}
		}
	}
	
	exit_service :
	
	cout<<"Please enter the shop's number �������X ( 5 ��� , �ҼƦr ) : ";
	cin>>number;
	int numberLens = number.size();
	while( numberLens != 5 )		//���b���� 
	{
		cout<<"You have to enter shop number again and it has 5 numbers  "<<endl;
		cout<<"�������X������ 5 ��Ʀr"<<endl;
		cin>>number;
		numberLens = number.size();
	}
	cout<<"Please enter the date �ө���� ( �~( XXXX , �褸 ) / �� / �� ) : ";
	cin>>Date;
	cout<<"Please enter the staff's ID �u�@�H���u�@�Ҹ��X ( 6 ��� , �Ĥ@�X���j�g�^��r����l5�ӬҼƦr) : ";
	cin>>ID;
	int IDLens = ID.size();
	while( ID[0] < 'A' || ID[0] > 'Z' || IDLens != 6 )		//���b���� 
	{
		cout<<"You have enter staff's ID again and its first number is english uppercase "<<endl;
		cout<<"and it has 6 number (including first uppercase )"<<endl;
		cout<<"�u�@�H��ID���Ĥ@�Ӧr�����^��r���j�g�B�����O 6 ��� (�]�A�Ĥ@�ӭ^��r��) : "<<endl;
		cin>>ID;
		IDLens = ID.size(); 
	}
	cout<<"��J�O�Φ����� : �ۦ��J �P �t�Φ۰ʭp��"<<endl; 
	cout<<"Do you want to enter enter cost by yourself or "<<endl;	//��J�O�Φ������ۦ��J�P�t�Φ۰ʮھڪA�ȶ��حp�� 
	cout<<"let system caculates the cost automatically ? "<<endl;
	cout<<"1 -> enter cost by your self �ۦ��J"<<endl;
	cout<<"2 -> caculate by system �t�Φ۰ʭp�� : "<<endl;
	cin>>count_choose;
	while( count_choose != 1 && count_choose != 2 )		//���b���� 
	{
		cout<<"You have to enter 1 or 2 "<<endl;
		cout<<"Please enter again : ";
		cin>>count_choose;
	}
	if( count_choose == 1 )		//�ۦ��J 
	{
		cout<<"Please enter the cost �O�� : ";
		cin>>money;
	}
	else if( count_choose == 2 )	//�t�Φ۰ʭp�� 
	{
		while( mService != "���e" && mService != "����" )	//�Y���i�Q�t�Φ۰ʹB� 
		{
			cout<<"The service that you enter can't be caculated by system "<<endl;
			cout<<"Please enter again "<<endl;
			cout<<"�z�ҿ�J���D�n�A�ȦW�٤��i�Q�t�Φ۰ʹB��"<<endl;
			cout<<"�бz�b��J�@�� �z�i�H��ܭק�D�n�A�ȦW�٩άO�ۦ��J�O�� "<<endl;
			cout<<"1 -> enter cost by your self (�ۦ��J) "<<endl;
			cout<<"2 -> modify the main service and caculated by system"<<endl;
			cout<<"     (�ק�D�n�A�ȦW�٨åѨt�Φ۰ʹB��)"<<endl;
			cin>>cost_choose;
			while( cost_choose != 1 && cost_choose != 2 )
			{
				cout<<"You have enter 1 or 2 "<<endl;
				cout<<"Please enter again "<<endl;
				cin>>cost_choose; 
			}
			if( cost_choose == 1 )
			{
				cout<<"Please enter the cost �O�� : ";
				cin>>money;
				goto assign;
			} 
			else if( cost_choose == 2 )
			{
				cout<<"Please enter the main Service : ";
				cin>>mService;
			}
		} 
		while( sService != "�~��" && sService != "�פ�" && sService != "�~��+�פ�" && sService != "�P�_����" && sService != "�~���N" )
		{
			cout<<"The subService that you enter can't be caculated by system "<<endl;
			cout<<"Please enter again "<<endl;
			cout<<"�z�ҿ�J���A�Ȥl���ئW�٤��i�Q�t�Φ۰ʹB��"<<endl;
			cout<<"�бz�b��J�@�� �z�i�H��ܭק�A�Ȥl���ئW�٩άO�ۦ��J�O�� "<<endl;
			cout<<"1 -> enter cost by your self (�ۦ��J) "<<endl;
			cout<<"2 -> modify the subService and caculated by system"<<endl;
			cout<<"     (�ק�A�Ȥl���ئW�٨åѨt�Φ۰ʹB��)"<<endl;
			cin>>cost_choose;
			while( cost_choose != 1 && cost_choose != 2 )
			{
				cout<<"You have enter 1 or 2 "<<endl;
				cout<<"Please enter again "<<endl;
				cin>>cost_choose; 
			}
			if( cost_choose == 1 )
			{
				cout<<"Please enter the cost �O�� : ";
				cin>>money;
				goto assign;
			} 
			else if( cost_choose == 2 )
			{
				cout<<"Please enter the subService : ";
				cin>>sService;
			}
		}  
		
		money = makeUp( mService , sService ); 
		cout<<"The cost �O�� : "<<money<<endl;
	}
	
	assign :
	
	ownerName = oName;		//�N�Ҧ���J�����ض�J�Ӫ��󪺸�� 
	ownerPhone = phone;
	petType = type;
	petName = pName;
	mainService = mService;
	subService = sService;
	shopNumber = number;
	date = Date;
	staffId = ID;
	cost = money;

}

void Pet::searchInformation()	//�d�߸�� 
{
		cout<<"Owner's name �D�H�W�r : "<<ownerName<<endl;		//�L�X��� 
		cout<<"Owner's phone �D�H�q�� : "<<ownerPhone<<endl;
		cout<<"Pet type �d������ : "<<petType<<endl;
		cout<<"Pet name �d���W�r : "<<petName<<endl;
		cout<<"MainService �D�n�A�� : "<<mainService<<endl;
		cout<<"SubService �A�Ȥl���� : "<<subService<<endl;
		cout<<"Shop's number �������X : "<<shopNumber<<endl;
		cout<<"Date �ө����: "<<date<<endl;
		cout<<"Staff's ID �u�@�H���u�@�Ҹ��X : "<<staffId<<endl;
		cout<<"Cost �O�� : "<<cost<<endl<<endl;	
}

void Pet::modifyInformation()	//�ק��� 
{
	string oName,
	  	   phone,
	       type,
	       pName,
	       mService,
	       sService,
	       number,
	       Date,
	       ID,
		   money;
	int item;
	cout<<"Which information you want to modify : "<<endl;	//��ܭקﶵ�� 
	cout<<"1 -> Owner's name �D�H�W�r "<<endl;
	cout<<"2 -> Owner's phone number �D�H�q�� "<<endl;
	cout<<"3 -> Pet's type �d������"<<endl;
	cout<<"4 -> Pet's name �d���W�r"<<endl;
	cout<<"5 -> MainService �D�n�A��"<<endl;
	cout<<"6 -> SubService �A�Ȥl����"<<endl;
	cout<<"7 -> Shop's number �������X"<<endl;
	cout<<"8 -> Date �ө����"<<endl;
	cout<<"9 -> Staff's ID �u�@�H���u�@�Ҹ��X"<<endl;
	cout<<"10 -> Cost �O�� : ";                
	cin>>item;
	while( item != 1 && item != 2 && item != 3 && item != 4 && item != 5 &&		//���b���� 
		   item != 6 && item != 7 && item != 8 && item != 9 && item != 10 )
	{
		cout<<"You have to enter 1 ~ 10  "<<endl;
		cout<<"Please enter again : ";
		cin>>item;
	}
	if( item == 1 )
	{
		cout<<"Please enter the owner's name �D�H�W�r : ";
		cin>>oName;
		ownerName = oName;
	}
	else if( item == 2 )
	{
		cout<<"Please enter the owner's phone �D�H�q�� : ";
		cin>>phone;
		ownerPhone = phone;
	}
	else if( item == 3 )
	{
		cout<<"Please enter the pet's type �d������ : ";
		cin>>type;
		petType = type;
	}
	else if( item == 4 )
	{
		cout<<"Please enter the pet's name �d���W�r : ";
		cin>>pName;
		petName = pName;
	}
	else if( item == 5 )
	{
		cout<<"Please enter the main service �D�n�A�� : ";
		cin>>mService;
		mainService = mService;
	}
	else if( item == 6 )
	{
		cout<<"Please enter the subService �A�Ȥl���� : ";
		cin>>sService;
		subService = sService;
	}
	else if( item == 7 )
	{
		cout<<"Please enter the shop's number �������X : ";
		cin>>number;
		shopNumber = number;		
	}
	else if( item == 8 )
	{
		cout<<"Please enter the date �ӹq��� : ";
		cin>>Date;
		date = Date;
	}
	else if( item == 9 )
	{
		cout<<"Please enter the staff's ID �u�@�H���u�@�Ҹ��� : ";
		cin>>ID;
		staffId = ID;
	}
	else if( item == 10 )
	{
		cout<<"Please enter the cost �O�� : ";
		cin>>money;
		cost = money; 
	}
}

void Pet::deleteInforamtion(int target_index , bool* deleteRecover , int recover_choose = 2 )	//�R�����( �i�_�� ) 
{
	deleteRecover[ target_index ] = true;
} 

void Pet::deleteInformation( int target_index , int* whetherDelete , int recover_choose =  1 )	//�R�����( ���i�_�� ) 
{
	ownerName = "";
	ownerPhone = "";
	petType = "";		
	petType = "";
	petName = "";
	mainService = "";
	subService = "";
	shopNumber = "";
	date = "";
	staffId = "";
	cost = "";
	whetherDelete[ target_index ] = 1;
}

void Pet::recoverInformation( int target_index , bool* deleteRecover , int* whetherDelete )		//�_���� 
{
	deleteRecover[ target_index ] = false;
	whetherDelete[ target_index ] = 0;
}


