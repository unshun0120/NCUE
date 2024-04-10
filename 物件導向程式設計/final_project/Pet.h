#include<iostream>
#include<string>
#ifndef PET_H
#define PET_H
using namespace std;

class Pet
{
	private :
		string ownerName, 		//Declaration 
		       ownerPhone,
		       petType,
		       petName,
		       mainService,
		       subService,
		       shopNumber,
		       date,
		       staffId,
			   cost;
	public :
		void storeOwnerName( string ownerName )	{ this->ownerName = ownerName; }		//�x�s�D�H�W�r 
		void storeOwnerPhone( string ownerPhone ) {	this->ownerPhone = ownerPhone; }	//	  �D�H�q�� 
		void storePetType( string petType )	{ this->petType = petType; }				// 	  �d������ 
		void storePetName( string petName )	{ this->petName = petName; }				//	  �d���W�r 
		void storeMainService( string mainService )	{ this->mainService = mainService; }//	  �D�n�A�� 
		void storeSubService( string subService ) { this->subService = subService; }	//	  �A�Ȥl���� 
		void storeShopNumber( string shopNumber ) { this->shopNumber = shopNumber; }	//    �������X 
		void storeDate( string date ) { this->date = date; }							//	  �i�J���̤�� 
		void storeStaffId( string staffId )	{ this->staffId = staffId; }				//	  �u�@�H���u�@�� 
		void storeCost( string cost ) { this->cost = cost; }							// 	  �`��O 
		
		string getOwnerName() { return ownerName; }		//�^�ǥD�H�W�r 		
		string getOwnerPhone() { return ownerPhone; }	//	  �D�H�q��
		string getPetType()	{ return petType; }			// 	  �d������ 
		string getPetName()	{ return petName; }			//	  �d���W�r 
		string getMainService() { return mainService; }	//	  �D�n�A�� 
		string getSubService() { return subService; }	//	  �A�Ȥl���� 
		string getShopNumber() { return shopNumber; }	//    �������X 
		string getDate() { return date; }				//	  �i�J���̤�� 
		string getStaffId() { return staffId; }			//	  �u�@�H���u�@�� 
		string getCost() { return cost; }				// 	  �`��O 
	
		void addInformation();			//�s�W��� 
		void searchInformation();		//�M���� 
		void modifyInformation();		//�ק��� 
		void deleteInforamtion( int , bool* , int );	//�R�����(�i�_��) 
		void deleteInformation( int , int* , int );		//�R�����(���i�_��) 
		void recoverInformation( int , bool* , int* );	//�_���� 
		friend string makeUp( string , string ); 		//�A�Ȫ�O 
		bool operator==( Pet& );	 
};



#endif



