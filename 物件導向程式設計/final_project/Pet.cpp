#include "Pet.h"
#include<string>
#include<iostream>
using namespace std;

string makeUp( string mService , string sService )	//服務花費 
{	
	if( mService == "美容" )
	{
		if( sService == "洗澡" )
			return "250";
		else if( sService == "修毛" )
			return "150";
		else if( sService == "洗澡+修毛" ) 
			return "400";
	} 
	else if( mService == "醫療" )
	{
		if( sService == "感冒醫療" )
			return "500";
		else if( sService == "外科手術" )
			return "3000";
	}	
}

bool Pet::operator==( Pet& date )		//operator overloading  
{
	return this->getDate() == date.getDate();
}

void Pet::addInformation()		//新增資料 
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
	cout<<"Please enter the owner's name 主人名字 : ";
	cin>>oName;
	cout<<"Please enter the owner's phone 主人電話 : ";
	cin>>phone;
	int phoneLens = phone.size();
	while( phone[0] != '0' && phone[1] != '9' || phoneLens != 10 )		//防呆機制 
	{
		cout<<"Your phone number need to be the 09XXXXXXXX and it has 10 numbers "<<endl;
		cout<<"Please enter again "<<endl;
		cout<<"您輸入的電話號碼必須為 09 開頭 且包括 09 需共 10 位數字"<<endl;
		cout<<"請您在輸入一次 : "<<endl; 
		cin>>phone;
		phoneLens = phone.size();
	}
	cout<<"Please enetr pet's type 寵物種類 : ";
	cin>>type;
	cout<<"Please enter pet's name 寵物名字 : ";
	cin>>pName;
	cout<<"Please enter the main service 主要服務 : ";
	cin>>mService;
	cout<<"Please enter the subservice 服務子項目 : ";
	cin>>sService;
	if( mService == "美容" )		//若主要服務與服務子項目配對不正確 
	{
		while( sService == "感冒醫療" || sService == "外科手術" )
		{
			cout<<"Your main service and your subservice doesn't match"<<endl;
			cout<<"您的主要服務與服務子項目並未配對正確"<<endl;
			cout<<"請選擇您要修改的項目名稱"<<endl;
			cout<<"1 -> main Service 主要服務 "<<endl;
			cout<<"2 -> subService 服務子項目 "<<endl; 
			cin>>service_choose;
			while( service_choose != 1 && service_choose != 2 )
			{
				cout<<"You have to enter 1 or 2"<<endl;
				cout<<"Please enter again ";
				cin>>service_choose;
			}
			if( service_choose == 1 )
			{
				cout<<"Please enter main Service 主要服務 : "<<endl;
				cin>>mService;
				goto exit_service;
			}
			else if( service_choose == 2 )
			{
				cout<<"Please enter subService 服務子項目 : "<<endl;
				cin>>sService;
			}
		}
	}
	else if( mService == "醫療" )
	{
		while( sService == "洗澡" || sService == "修毛" || sService == "洗澡+修毛" )
		{
			cout<<"Your main service and your subservice doesn't match"<<endl;
			cout<<"您的主要服務與服務子項目並未配對正確"<<endl;
			cout<<"請選擇您要修改的項目名稱"<<endl;
			cout<<"1 -> main Service 主要服務 "<<endl;
			cout<<"2 -> subService 服務子項目 "<<endl; 
			cin>>service_choose;
			while( service_choose != 1 && service_choose != 2 )
			{
				cout<<"You have to enter 1 or 2"<<endl;
				cout<<"Please enter again ";
				cin>>service_choose;
			}
			if( service_choose == 1 )
			{
				cout<<"Please enter main Service 主要服務 : "<<endl;
				cin>>mService;
				goto exit_service;
			}
			else if( service_choose == 2 )
			{
				cout<<"Please enter subService 服務子項目 : "<<endl;
				cin>>sService;
			}
		}
	}
	
	exit_service :
	
	cout<<"Please enter the shop's number 分店號碼 ( 5 位數 , 皆數字 ) : ";
	cin>>number;
	int numberLens = number.size();
	while( numberLens != 5 )		//防呆機制 
	{
		cout<<"You have to enter shop number again and it has 5 numbers  "<<endl;
		cout<<"分店號碼必須為 5 位數字"<<endl;
		cin>>number;
		numberLens = number.size();
	}
	cout<<"Please enter the date 來店日期 ( 年( XXXX , 西元 ) / 月 / 日 ) : ";
	cin>>Date;
	cout<<"Please enter the staff's ID 工作人員工作證號碼 ( 6 位數 , 第一碼為大寫英文字母其餘5個皆數字) : ";
	cin>>ID;
	int IDLens = ID.size();
	while( ID[0] < 'A' || ID[0] > 'Z' || IDLens != 6 )		//防呆機制 
	{
		cout<<"You have enter staff's ID again and its first number is english uppercase "<<endl;
		cout<<"and it has 6 number (including first uppercase )"<<endl;
		cout<<"工作人員ID的第一個字須為英文字母大寫且必須是 6 位數 (包括第一個英文字母) : "<<endl;
		cin>>ID;
		IDLens = ID.size(); 
	}
	cout<<"輸入費用有分為 : 自行輸入 與 系統自動計算"<<endl; 
	cout<<"Do you want to enter enter cost by yourself or "<<endl;	//填入費用有分為自行填入與系統自動根據服務項目計算 
	cout<<"let system caculates the cost automatically ? "<<endl;
	cout<<"1 -> enter cost by your self 自行輸入"<<endl;
	cout<<"2 -> caculate by system 系統自動計算 : "<<endl;
	cin>>count_choose;
	while( count_choose != 1 && count_choose != 2 )		//防呆機制 
	{
		cout<<"You have to enter 1 or 2 "<<endl;
		cout<<"Please enter again : ";
		cin>>count_choose;
	}
	if( count_choose == 1 )		//自行填入 
	{
		cout<<"Please enter the cost 費用 : ";
		cin>>money;
	}
	else if( count_choose == 2 )	//系統自動計算 
	{
		while( mService != "美容" && mService != "醫療" )	//若不可被系統自動運篹 
		{
			cout<<"The service that you enter can't be caculated by system "<<endl;
			cout<<"Please enter again "<<endl;
			cout<<"您所輸入的主要服務名稱不可被系統自動運算"<<endl;
			cout<<"請您在輸入一次 您可以選擇修改主要服務名稱或是自行輸入費用 "<<endl;
			cout<<"1 -> enter cost by your self (自行輸入) "<<endl;
			cout<<"2 -> modify the main service and caculated by system"<<endl;
			cout<<"     (修改主要服務名稱並由系統自動運算)"<<endl;
			cin>>cost_choose;
			while( cost_choose != 1 && cost_choose != 2 )
			{
				cout<<"You have enter 1 or 2 "<<endl;
				cout<<"Please enter again "<<endl;
				cin>>cost_choose; 
			}
			if( cost_choose == 1 )
			{
				cout<<"Please enter the cost 費用 : ";
				cin>>money;
				goto assign;
			} 
			else if( cost_choose == 2 )
			{
				cout<<"Please enter the main Service : ";
				cin>>mService;
			}
		} 
		while( sService != "洗澡" && sService != "修毛" && sService != "洗澡+修毛" && sService != "感冒醫療" && sService != "外科手術" )
		{
			cout<<"The subService that you enter can't be caculated by system "<<endl;
			cout<<"Please enter again "<<endl;
			cout<<"您所輸入的服務子項目名稱不可被系統自動運算"<<endl;
			cout<<"請您在輸入一次 您可以選擇修改服務子項目名稱或是自行輸入費用 "<<endl;
			cout<<"1 -> enter cost by your self (自行輸入) "<<endl;
			cout<<"2 -> modify the subService and caculated by system"<<endl;
			cout<<"     (修改服務子項目名稱並由系統自動運算)"<<endl;
			cin>>cost_choose;
			while( cost_choose != 1 && cost_choose != 2 )
			{
				cout<<"You have enter 1 or 2 "<<endl;
				cout<<"Please enter again "<<endl;
				cin>>cost_choose; 
			}
			if( cost_choose == 1 )
			{
				cout<<"Please enter the cost 費用 : ";
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
		cout<<"The cost 費用 : "<<money<<endl;
	}
	
	assign :
	
	ownerName = oName;		//將所有輸入的項目填入該物件的資料 
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

void Pet::searchInformation()	//查詢資料 
{
		cout<<"Owner's name 主人名字 : "<<ownerName<<endl;		//印出資料 
		cout<<"Owner's phone 主人電話 : "<<ownerPhone<<endl;
		cout<<"Pet type 寵物種類 : "<<petType<<endl;
		cout<<"Pet name 寵物名字 : "<<petName<<endl;
		cout<<"MainService 主要服務 : "<<mainService<<endl;
		cout<<"SubService 服務子項目 : "<<subService<<endl;
		cout<<"Shop's number 分店號碼 : "<<shopNumber<<endl;
		cout<<"Date 來店日期: "<<date<<endl;
		cout<<"Staff's ID 工作人員工作證號碼 : "<<staffId<<endl;
		cout<<"Cost 費用 : "<<cost<<endl<<endl;	
}

void Pet::modifyInformation()	//修改資料 
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
	cout<<"Which information you want to modify : "<<endl;	//選擇修改項目 
	cout<<"1 -> Owner's name 主人名字 "<<endl;
	cout<<"2 -> Owner's phone number 主人電話 "<<endl;
	cout<<"3 -> Pet's type 寵物種類"<<endl;
	cout<<"4 -> Pet's name 寵物名字"<<endl;
	cout<<"5 -> MainService 主要服務"<<endl;
	cout<<"6 -> SubService 服務子項目"<<endl;
	cout<<"7 -> Shop's number 分店號碼"<<endl;
	cout<<"8 -> Date 來店日期"<<endl;
	cout<<"9 -> Staff's ID 工作人員工作證號碼"<<endl;
	cout<<"10 -> Cost 費用 : ";                
	cin>>item;
	while( item != 1 && item != 2 && item != 3 && item != 4 && item != 5 &&		//防呆機制 
		   item != 6 && item != 7 && item != 8 && item != 9 && item != 10 )
	{
		cout<<"You have to enter 1 ~ 10  "<<endl;
		cout<<"Please enter again : ";
		cin>>item;
	}
	if( item == 1 )
	{
		cout<<"Please enter the owner's name 主人名字 : ";
		cin>>oName;
		ownerName = oName;
	}
	else if( item == 2 )
	{
		cout<<"Please enter the owner's phone 主人電話 : ";
		cin>>phone;
		ownerPhone = phone;
	}
	else if( item == 3 )
	{
		cout<<"Please enter the pet's type 寵物種類 : ";
		cin>>type;
		petType = type;
	}
	else if( item == 4 )
	{
		cout<<"Please enter the pet's name 寵物名字 : ";
		cin>>pName;
		petName = pName;
	}
	else if( item == 5 )
	{
		cout<<"Please enter the main service 主要服務 : ";
		cin>>mService;
		mainService = mService;
	}
	else if( item == 6 )
	{
		cout<<"Please enter the subService 服務子項目 : ";
		cin>>sService;
		subService = sService;
	}
	else if( item == 7 )
	{
		cout<<"Please enter the shop's number 分店號碼 : ";
		cin>>number;
		shopNumber = number;		
	}
	else if( item == 8 )
	{
		cout<<"Please enter the date 來電日期 : ";
		cin>>Date;
		date = Date;
	}
	else if( item == 9 )
	{
		cout<<"Please enter the staff's ID 工作人員工作證號瑪 : ";
		cin>>ID;
		staffId = ID;
	}
	else if( item == 10 )
	{
		cout<<"Please enter the cost 費用 : ";
		cin>>money;
		cost = money; 
	}
}

void Pet::deleteInforamtion(int target_index , bool* deleteRecover , int recover_choose = 2 )	//刪除資料( 可復原 ) 
{
	deleteRecover[ target_index ] = true;
} 

void Pet::deleteInformation( int target_index , int* whetherDelete , int recover_choose =  1 )	//刪除資料( 不可復原 ) 
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

void Pet::recoverInformation( int target_index , bool* deleteRecover , int* whetherDelete )		//復原資料 
{
	deleteRecover[ target_index ] = false;
	whetherDelete[ target_index ] = 0;
}


