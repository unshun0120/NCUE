/*
	測試檔名 : test.txt
	輸出檔名 : out.txt 
*/
#include<iostream>
#include<fstream> 
#include<string>
#include "Pet.h"
#include "Filter.h"
#include "Print.h"
#include "Index.h"
using namespace std;		//namespace

enum Sign					//enumeration 
{
	NO0 , NO1 , NO2 , NO3 , NO4 , NO5 , NO6
};

void printIndex( Index );
Index convert( int );		

char YesNoChoose( char ch )		//防呆機制 
{
	while( ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n' )
	{
		cout<<"You have to enter Y/y or N/n "<<endl;
		cout<<"Please enter again : ";
		cin>>ch;	
	} 
	
	return ch;
}

int check_activity( int n , int flag )	//防呆機制 
{
	if( !flag )
	{
		while( n != 1 && n != 2 && n != 3 && n != 4 && n != 6 && n != 7 )
		{
			cout<<"Yu have to enter 1 , 2 , 3 , 4 , 6 or 7 !"<<endl;
			cout<<"Please enter again : ";
			cin>>n;
		}
	}
	else if( flag )
	{
		while( n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 )
		{
			cout<<"Yu have to enter 1 ~ 7 !"<<endl;
			cout<<"Please enter again : ";
			cin>>n;
		}
	}
	
	return n;
}

int main()
{
	Sign N0 = NO0,			//Enumeration Declaration
		 N1 = NO1,
		 N2 = NO2,
		 N3 = NO3,
		 N4 = NO4,
		 N5 = NO5,
		 N6 = NO6;
	int i;					//Declaration	
	char YNchoose;
	ifstream inFile;
	char inFileName[1000];
	char outFileName[1000];
	bool deleteRecover[10000];		
	int* whetherDelete = new int[10000];		//dynamic memory allocation
	Print* printArray[] = { new addPrint() , new modifyPrint() , new deletePrint() , new recoverPrint() };
	
	cout<<"Please enter inputFile's name ( 輸入 input檔 檔名 ): ";			//open inputFile , outputFile
	cin>>inFileName;
	inFile.open( inFileName );
	Index check_index;
	while( !inFile )
	{
		cout<<"The inputFile doesn't exist ! "<<endl;
		cout<<"Do you want to enter intputFile's name again ( Y/N ) ? ";
		cin>>YNchoose;
		YNchoose = YesNoChoose( YNchoose );
		if( YNchoose == 'N' || YNchoose == 'n' )
			exit(1);
		else if( YNchoose == 'Y' || YNchoose == 'y' )
		{
			cout<<"Please enter inputFile's name : ";
			cin>>inFileName;
			inFile.open( inFileName );
		}
	}
	cout<<"Please enter outputFile's name ( 輸入 output檔 檔名 ): ";
	cin>>outFileName;
	fstream outFile( outFileName , ios::out | ios::trunc );
	while( !outFile )
	{
		cout<<"The outputFile doesn't exist ! "<<endl;
		cout<<"Do you want to enter outputFile's name again ( Y/N ) ? ";
		cin>>YNchoose;
		YNchoose = YesNoChoose( YNchoose );
		if( YNchoose == 'N' || YNchoose == 'n' )
			exit(1);
		else if( YNchoose == 'Y' || YNchoose == 'y' )
		{
			cout<<"Please enter outputFile's name : ";
			cin>>outFileName;
			fstream outFile( outFileName , ios::out | ios::trunc );
		}
	}
	
	string oName,				//Declaration
		   phone,
		   type,
		   pName,
		   mService,
		   sService,
		   number,
		   date,
		   ID,
		   money;
	int index=0;
	char num;
	Pet pet[10000];
	
	while( !inFile.fail() )					//讀 input檔直到沒資料 
	{
		getline( inFile , oName );				
		pet[ index ].storeOwnerName( oName );
		
		getline( inFile , phone );
		pet[ index ].storeOwnerPhone( phone );
		
		getline( inFile , type );
		pet[ index ].storePetType( type );
		
		getline( inFile , pName );
		pet[ index ].storePetName( pName );
		
		getline( inFile , mService );
		pet[ index ].storeMainService( mService );
		
		getline( inFile , sService );
		pet[ index ].storeSubService( sService );
		
		getline( inFile , number );
		pet[ index ].storeShopNumber( number );
		
		getline( inFile , date );
		pet[ index ].storeDate( date );
		
		getline( inFile , ID );
		pet[ index ].storeStaffId( ID );
		
		getline( inFile , money);
		pet[ index ].storeCost( money );
		
		deleteRecover[ index ] = false;			//預設為 不可復原 
		whetherDelete[ index ] = 0;				//預設為 未被刪除 
		index++; 
	}
	
	int activity_choose;
	int flag=0;		//標註這是第一次問要對檔案做哪些動作 ( 因為第一次輸入的選項與不是第一次的選項有不同 ) 
	cout<<"What do you want to do in the file : "<<endl;			//詢問要對檔案做的動作 
	cout<<"1 -> Add new information in the file ( 新增資料到檔案中 )"<<endl; 
	cout<<"2 -> Search the information in the file ( 查詢檔案中的資料 )"<<endl;
	cout<<"3 -> Modify the information in the file ( 修改檔案中的資料 )"<<endl;
	cout<<"4 -> Delete the information in the file ( 刪除檔案中的資料 )"<<endl;
	cout<<"6 -> Check the guest's number in the data ( 查看客人為第幾筆資料 )"<<endl;
	cout<<"7 -> Copy the information to the output file ( 將檔案中資料備份至輸出檔 ) : "; 
	cin>>activity_choose;
	activity_choose = check_activity( activity_choose , flag );
	if( activity_choose == 7 )		//若要備份則直接跳當做加密的地方 
	{
		goto end;
	}
	do
	{ 
		if( activity_choose == N1 )				//新增資料到檔案中 
		{
			pet[ index-1 ].addInformation();
			deleteRecover[ index ] = false;
			whetherDelete[ index ] = 0;
			index++;	
			printArray[0]->print();
		} 
		else if( activity_choose == N2 )			//查詢檔案中的資料 
		{ 
			cout<<endl<<"Please enter owner's phone number to search information "<<endl;
			cout<<"輸入主人電話號碼以查詢主人寵物的來店資訊 : ";
			cin>>phone;
			int target_index;
			for( i = 0 ; i < index-1 ; i++ )		//尋找該電話是否存在於檔案中 
			{
				if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
				{
					target_index = i;
					break;
				}
			}
			if( i == ( index - 1 ) )		//若找不到 
			{
				cout<<"The phone number doesn't exist in the file "<<endl;
				do
				{
					cout<<"Do you want to enter the phone number to search the information (Y/N) ? ";
					cin>>YNchoose;
					YNchoose = YesNoChoose( YNchoose );
					if( YNchoose == 'N' || YNchoose == 'n' )	//若輸入 N/n 則直接跳到詢問對檔案做動作的部分 
						goto exit;
					cout<<"Please enter owner's phone number to search information : ";
					cin>>phone;
					for(  i = 0 ; i < index-1 ; i++ )
					{
						if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )  		 
						{
							target_index = i;			//若找到則跳出迴圈到 search 的地方繼續進行動作
							goto search;
						}
					}
					if( i == ( index - 1 ) )
					{
						cout<<"The phone number doesn't exist in the file "<<endl;
						continue;
					}
				}while( YNchoose == 'Y' || YNchoose == 'y' );
			}
			
			search : 
			
			pet[ target_index ].searchInformation();
				
			int same = 0;
			int same_day[10000];
			int same_index = 0;		
			for( i = 0 ; i < index-1 ; i ++ )				//尋找是否有在同 一天帶寵物到店裡的人 
			{
				same_day[i] = -1;
				if( pet[ target_index ] == pet[i] && target_index != i && whetherDelete[i] == 0 )			//先印出有誰跟該客人同一天 
				{
					cout<<pet[i].getOwnerName()<<" also came to the shop on the same day !"<<endl;
					cout<<pet[i].getOwnerName()<<" 也在同一天來店裡 !"<<endl; 
					same = 1;
					same_day[ same_index ] = i;
					same_index++;
				}
			}
			if( same == 1 )				//詢問是否要查看同一天到店裡的客人的資料 
			{
				char sameDayChoose;
				cout<<endl<<"Do you want to search the guest's information "<<endl;
				cout<<"which came to shop on the same day (Y/N) ? "<<endl;
				cout<<"請問要查詢與 "<<pet[ target_index ].getOwnerName()<<" 同一天來店裡的客人的資訊嗎 (Y/N) ? "; 
				cin>>sameDayChoose;
				sameDayChoose = YesNoChoose( sameDayChoose );
				if( sameDayChoose == 'Y' || sameDayChoose == 'y' )
				{
					cout<<endl;
					for( int i = 0 ; i < same_index ; i++ )		//印出資料 
					{
						pet[ same_day[i] ].searchInformation();
						cout<<endl;
					}
				}
			}
			
		}	
		else if( activity_choose == N3 )			//修改檔案中的資料 
		{
			cout<<endl<<"Please enter owner's phone number to modify information : ";
			cin>>phone;
			int target_index;
			for( i = 0 ; i < index-1 ; i++ )		//尋找該電話是否存在於檔案中 
			{
				if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
				{
					target_index = i;
					break;
				}
			}
			if( i == ( index - 1 ) )		//若找不到	
			{
				cout<<"The phone number doesn't exist in the file "<<endl;
				do
				{
					cout<<"Do you want to enter the phone number to modify the information (Y/N) ? ";
					cin>>YNchoose;
					YNchoose = YesNoChoose( YNchoose ); 
					if( YNchoose == 'N' || YNchoose == 'n' )		//若輸入 N/n 則直接跳到詢問對檔案做動作的部分
						goto exit;
					cout<<"Please enter owner's phone number to modify information : ";
					cin>>phone;
					for(  i = 0 ; i < index-1 ; i++ )
					{
						if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )		
						{
							target_index = i;			//若找到則跳出迴圈到 modify的地方繼續進行動作
							goto modify;
						}
					}
					if( i == ( index - 1 ) )
					{
						cout<<"The phone number doesn't exist in the file "<<endl;
						continue;
					}
				}while( YNchoose == 'Y' ||YNchoose == 'y' );
			}
			
			modify :  
			
			cout<<endl<<"This is the guest "<<pet[ target_index ].getOwnerName()<<"'s information : "<<endl;		
			cout<<"Owner's name 主人名字 : "<<pet[ target_index ].getOwnerName()<<endl;				//先印出該客人與寵物的相關資料 
			cout<<"Owner's phone 主人電話 : "<<pet[ target_index ].getOwnerPhone()<<endl;			
			cout<<"Pet type 寵物種類 : "<<pet[ target_index ].getPetType()<<endl;
			cout<<"Pet name 寵物名字 : "<<pet[ target_index ].getPetName()<<endl;
			cout<<"MainService 主要服務 : "<<pet[ target_index ].getMainService()<<endl;
			cout<<"SubService 服務子項目: "<<pet[ target_index ].getSubService()<<endl;
			cout<<"Shop's number 分店號碼 : "<<pet[ target_index ].getShopNumber()<<endl;
			cout<<"Date 來店日期 : "<<pet[ target_index ].getDate()<<endl;
			cout<<"Staff's ID 工作人員工作證號碼 : "<<pet[ target_index ].getStaffId()<<endl;
			cout<<"Cost 費用 : "<<pet[ target_index ].getCost()<<endl<<endl;
			
			pet[ target_index ].modifyInformation();		//再去選擇要修改的項目 
			printArray[1]->print();
		}
		
		else if( activity_choose == N4 )				//刪除檔案中的資料 
		{
			int recover_choose;					//刪除檔案有分為 : 不可復原 / 可復原
			cout<<endl<<"刪除檔案有分為 : 不可復原 與 可復原"<<endl;				
			cout<<"1 -> Delete the information and they can not be recovered ( 不可復原 )"<<endl;
			cout<<"2 -> Delete the information but they can be recovered ( 可復原 )"<<endl;
			cin>>recover_choose;
			while( recover_choose != 1 && recover_choose != 2 )
			{
				cout<<"You have to enter 1 or 2 "<<endl;
				cout<<"Please enter again : ";
				cin>>recover_choose;
			}
			cout<<"Please enter owner's phone number to delete information "<<endl;
			cout<<"請輸入主人電話以刪除其資料 : "; 
			cin>>phone;
			int target_index;
			for( i = 0 ; i < index-1 ; i++ )		//尋找該電話是否存在於檔案中 
			{
				if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
				{
					target_index = i;
					break;
				}
			}
			if( i == ( index -1 ) )			//若找不到 
			{
				cout<<"The phone number doesn't exist in the file "<<endl;
				do
				{
					cout<<"Do you want to enter phone number again (Y/N) ? ";
					cin>>YNchoose;
					YNchoose  = YesNoChoose( YNchoose ); 
					if( YNchoose == 'N' || YNchoose == 'n' )	//若輸入 N/n 則直接跳到詢問對檔案做動作的部分
						goto exit;
					else if( YNchoose == 'Y' || YNchoose == 'y' )
					{
						cout<<"Please enter owner's phone number to delete information : ";
						cin>>phone;
						for( i = 0 ; i < index-1 ; i++ )
						{
							if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
							{
								target_index = i;		//若找到則跳出迴圈到 Delete 的地方繼續進行動作
								goto Delete;
							}
						}
						if( i == ( index - 1 ) )
						{
							cout<<"The phone number doesn't exist in the file "<<endl;
							continue;
						}
					}
				}while( YNchoose == 'Y' || YNchoose == 'y' );
			}
			
			Delete :  	
			
			cout<<endl<<"This is the guest "<<pet[ target_index ].getOwnerName()<<"'s information : "<<endl;
			cout<<"Owner's name 主人名字 : "<<pet[ target_index ].getOwnerName()<<endl;				//先印出該客人與寵物的相關資料 
			cout<<"Owner's phone 主人電話: "<<pet[ target_index ].getOwnerPhone()<<endl;
			cout<<"Pet type 寵物種類 : "<<pet[ target_index ].getPetType()<<endl;
			cout<<"Pet name 寵物名字 : "<<pet[ target_index ].getPetName()<<endl;
			cout<<"MainService 主要服務 : "<<pet[ target_index ].getMainService()<<endl;
			cout<<"SubService 服務子項目 : "<<pet[ target_index ].getSubService()<<endl;
			cout<<"Shop's number 分店號碼: "<<pet[ target_index ].getShopNumber()<<endl;
			cout<<"Date 來店日期 : "<<pet[ target_index ].getDate()<<endl;
			cout<<"Staff's ID 工作人員工作證號碼 : "<<pet[ target_index ].getStaffId()<<endl;
			cout<<"Cost 費用 : "<<pet[ target_index ].getCost()<<endl<<endl;
			if( recover_choose == 1 )		//若不可復原 
			{
				pet[ target_index ].deleteInformation( target_index , whetherDelete ,  recover_choose );
				deleteRecover[ target_index ] = false;	
			} 
			else if( recover_choose == 2 )	//若可復原 
			{
				pet[ target_index ].deleteInforamtion( target_index , deleteRecover ,  recover_choose );
				whetherDelete[ target_index ] = 1;
			}
			
			printArray[2]->print();
		}
		else if( activity_choose == N5 )					//復原檔案中的資料 
		{
			int target_index;
			cout<<endl<<"Please enter owner's phone number to recover information "<<endl;
			cout<<"請輸入主人電話以復原其資料 : ";
			cin>>phone;
			for( i = 0 ; i < index-1 ; i++ )		//尋找該電話是否可復原 
			{
				if( pet[i].getOwnerPhone() == phone )
				{
					if( deleteRecover[i] == true && whetherDelete[i] == 1 )		//若該檔案可復原 
					{
						target_index = i;
						break;
					}
					else if( deleteRecover[i] == false && whetherDelete[i] == 0 )	//若該檔案未被刪除 
					{
						cout<<"This information exist in the file "<<endl;
						cout<<"They don't need to be recovered "<<endl;
						cout<<"該資料存在於檔案中 , 沒有被刪掉喔 ~ "<<endl<<endl; 
						goto exit;
					 } 
				}
			}
			if( i == ( index -1 ) )		//若找不到 
			{
				cout<<"The phone number doesn't exist in the file "<<endl;
				do
				{
					cout<<"Do you want to enter phone number again (Y/N) ? ";
					cin>>YNchoose;
					YNchoose == YesNoChoose( YNchoose ); 
					if( YNchoose == 'N' || YNchoose == 'n' )		//若輸入 N/n 則直接跳到詢問對檔案做動作的部分
						goto exit;
					else if( YNchoose == 'Y' || YNchoose == 'y' )	
					{
						cout<<"Please enter owner's phone number to recover information : ";
						cin>>phone;
						for( i = 0 ; i < index-1 ; i++ )
						{ 
							if( pet[i].getOwnerPhone() == phone )
							{
								if( deleteRecover[i] == true && whetherDelete[i] == 1 )		
								{
									target_index = i;		//若該檔可復原則跳出迴圈到 Delete 的地方繼續進行動作
									goto recover;
								}
								else if( deleteRecover[i] == false && whetherDelete[i] == 0 )	
								{
									cout<<"This information exist in the file "<<endl;
									cout<<"They don't need to be recovered "<<endl;
									cout<<"該資料存在於檔案中 , 沒有被刪掉喔 ~ "<<endl<<endl; 
									goto exit;				//若該檔案未被刪除則直接跳到詢問對檔案做動作的部分 
								} 
							}
						} 
						if( i == ( index - 1 ) )
						{
							cout<<"The phone number doesn't exist in the file "<<endl;
							continue;
						}
					}
				}while( YNchoose == 'Y' || YNchoose == 'y' );
			}
			
			recover :
				
			pet[ target_index ].recoverInformation( target_index , deleteRecover , whetherDelete );
			printArray[3]->print();
			
		}
		else if( activity_choose == N6 )	//查看客人為檔案中的第幾筆資料 
		{
			int target_index;
			cout<<endl<<"Please enter owner's phone number to check guest's number "<<endl;
			cout<<"請輸入主人電話以查詢該客人在檔案中是第幾筆資料 : ";
			cin>>phone;
			for( i = 0 ; i < index-1 ; i++ )		//尋找該客人是否存在於檔案中 
			{
				if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
				{
					target_index = i;
					break;
				}
			}
			if( i == ( index -1 ) )		//若找不到 
			{
				cout<<"The phone number doesn't exist in the file "<<endl;
				do
				{
					cout<<"Do you want to enter phone number again (Y/N) ? ";
					cin>>YNchoose;
					YNchoose = YesNoChoose( YNchoose );
					if( YNchoose == 'N' || YNchoose == 'n' )	//若輸入 N/n 則直接跳到詢問對檔案做動作的部分
						goto exit;
					else if( YNchoose == 'Y' || YNchoose == 'y' )
					{
						cout<<"Please enter owner's phone number to check information : ";
						cin>>phone;
						for( i = 0 ; i < index-1 ; i++ )
						{
							if( pet[i].getOwnerPhone() == phone && deleteRecover[i] == false && whetherDelete[i] == 0 )
							{
								target_index = i;		//若找到則跳出迴圈到 check 的地方繼續進行動作
								goto check;
							}
						}
						if( i == ( index - 1 ) )
						{
							cout<<"The phone number doesn't exist in the file "<<endl;
							continue;
						}
					}
				}while( YNchoose == 'Y' || YNchoose == 'y' );
			}
			check :
				
			check_index = ( target_index + 1 );				//印出該客人為第幾個客人 
			check_index = convert( target_index + 1 );
			cout<<endl<<pet[ target_index ].getOwnerName()<<" is the ";
			printIndex( check_index ); 
			cout<<"th guest in the file ~"<<endl<<endl;
		}
		
		exit:
			
		flag = 1;	//標註這一次不是第一次問要對檔案做哪些動作 ( 因為第一次輸入的選項與不是第一次的選項有不同 )	
		cout<<endl<<"What do you want to do next : "<<endl;			//詢問要對檔案做的動作 
		cout<<"1 -> Add new information in the file ( 新增資料到檔案中 ) "<<endl;
		cout<<"2 -> Search the infromation in the file ( 查詢在檔案中的資料 ) "<<endl;
		cout<<"3 -> Modify the information in the file ( 修改在檔案中的資料 ) "<<endl;
		cout<<"4 -> Delete the information in the file ( 刪除檔案中的資料 )"<<endl;
		cout<<"5 -> Recover the information ( 復原被刪除且可被復原的資料 )"<<endl;
		cout<<"6 -> Check the number of guest in the data ( 查詢該客人是第幾筆資料 )"<<endl;
		cout<<"7 -> exit the system ( 離開本系統 )"<<endl;
		cin>>activity_choose;
		activity_choose = check_activity( activity_choose , flag );
		
	}while( activity_choose == N1 || activity_choose == N2 || activity_choose == N3 ||
		    activity_choose == N4 || activity_choose == N5 || activity_choose == N6 ); 
 	
 	end : 
 	
	Filter pnum;
	File file;
	numFile change_num;
	int j,lens;
	for( i = 0 ; i < index-1 ; i++ )		//將所有客人的資料寫入檔案 
	{
		char ch;
		char num;
		char pNum;
		if( whetherDelete[i] == 1 ) 		//被刪除的不寫進去 
			continue;
			
		outFile<<pet[i].getOwnerName()<<'\n';	//主人名字	
		
		lens = pet[i].getOwnerPhone().size();	//主人電話( 加密 : 電話號碼最後一碼寫入檔案時 + 2 ) 
		for( j = 0 ; j < lens-1 ; j++ )
		{
			outFile<<pet[i].getOwnerPhone()[j];	
		} 
		pNum = pnum.Encryption( pet[i].getOwnerPhone()[ lens - 1 ] );
		outFile<<pNum<<'\n';
		
		outFile<<pet[i].getPetType()<<'\n';		//寵物種類 
		outFile<<pet[i].getPetName()<<'\n';		//寵物名字 
		outFile<<pet[i].getMainService()<<'\n';	//主要服務 
		outFile<<pet[i].getSubService()<<'\n';	//服務子項目 
		outFile<<pet[i].getShopNumber()<<'\n';	//分店號碼 
		outFile<<pet[i].getDate()<<'\n';		//進店裡的日期 
		
		ch = file.Encryption( pet[i].getStaffId()[0] );	//工作人員的工作證( 加密 : 工作證第一碼英文字母往後兩個字母 , 共作證最後一碼數字 + 2 ) 
		outFile<<ch;
		lens = pet[i].getStaffId().size();
		for( j = 1 ; j < lens - 1 ; j++ )
			outFile<<pet[i].getStaffId()[j];
		num = change_num.Encryption( pet[i].getStaffId()[ lens - 1 ] );
		outFile<<num;
		outFile<<'\n'; 
		
		outFile<<pet[i].getCost()<<'\n'<<'\n';	//總花費 
	}
	
	numFile endFile( index - 1 );	//準備離開本系統 
	
	delete []whetherDelete;		//delete dynamic memory allocation 
		
	outFile.close();
	
	return 0;
}



