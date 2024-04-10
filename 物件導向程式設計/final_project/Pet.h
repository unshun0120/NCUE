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
		void storeOwnerName( string ownerName )	{ this->ownerName = ownerName; }		//儲存主人名字 
		void storeOwnerPhone( string ownerPhone ) {	this->ownerPhone = ownerPhone; }	//	  主人電話 
		void storePetType( string petType )	{ this->petType = petType; }				// 	  寵物種類 
		void storePetName( string petName )	{ this->petName = petName; }				//	  寵物名字 
		void storeMainService( string mainService )	{ this->mainService = mainService; }//	  主要服務 
		void storeSubService( string subService ) { this->subService = subService; }	//	  服務子項目 
		void storeShopNumber( string shopNumber ) { this->shopNumber = shopNumber; }	//    分店號碼 
		void storeDate( string date ) { this->date = date; }							//	  進入店裡日期 
		void storeStaffId( string staffId )	{ this->staffId = staffId; }				//	  工作人員工作證 
		void storeCost( string cost ) { this->cost = cost; }							// 	  總花費 
		
		string getOwnerName() { return ownerName; }		//回傳主人名字 		
		string getOwnerPhone() { return ownerPhone; }	//	  主人電話
		string getPetType()	{ return petType; }			// 	  寵物種類 
		string getPetName()	{ return petName; }			//	  寵物名字 
		string getMainService() { return mainService; }	//	  主要服務 
		string getSubService() { return subService; }	//	  服務子項目 
		string getShopNumber() { return shopNumber; }	//    分店號碼 
		string getDate() { return date; }				//	  進入店裡日期 
		string getStaffId() { return staffId; }			//	  工作人員工作證 
		string getCost() { return cost; }				// 	  總花費 
	
		void addInformation();			//新增資料 
		void searchInformation();		//尋找資料 
		void modifyInformation();		//修改資料 
		void deleteInforamtion( int , bool* , int );	//刪除資料(可復原) 
		void deleteInformation( int , int* , int );		//刪除資料(不可復原) 
		void recoverInformation( int , bool* , int* );	//復原資料 
		friend string makeUp( string , string ); 		//服務花費 
		bool operator==( Pet& );	 
};



#endif



