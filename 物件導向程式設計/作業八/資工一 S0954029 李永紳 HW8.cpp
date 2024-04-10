/*
	測試檔名 : test.txt 
*/ 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Inventory				//Create structure to store inventory information 
{
	string itemName[1000];		//Declaration
	int itemQuantity[1000];
	int itemWholeSale[1000];
	int itemRetail[1000];
	string itemDate[1000]; 
};

char YesNo_check( char choose )		//防呆 : 只能輸入 Y/y 或 N/n 
{
	while( choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n' )
	{
		cout<<"You have to enter Y/y or N/n !"<<endl;
		cout<<"Please enter choose again : ";
		cin>>choose;
	}
	
	return choose;	
} 

int activity_check( int choose )	//防呆 : 只能輸入 1 或 2 或 3
{
	while( choose != 1 && choose != 2 && choose != 3 )
	{
		cout<<"You have to enter 1 , 2 or 3 !"<<endl;
		cout<<"Please enter choose again : ";
		cin>>choose;
	}	
	
  	return choose;
}  

int change_check( int choose )		//防呆 : 只能輸入 1 , 2 , 3 , 4 或 5 
{
	while( choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 )
	{
		cout<<"You have to enter 1 , 2 , 3 , 4 or 5 !"<<endl;	
		cout<<"Please enter choose again : ";
		cin>>choose;
	}	
	
  	return choose;
}

int main()
{
	char fileName[100],exit_choose;									//Declaration
	Inventory item;
	int num,activity_choose,index=1,target,i,change_choose,money;
	string name,date;
	cout<<"Please enter file's name : ";		//輸入檔案名稱 
	cin>>fileName;
	fstream inventory( fileName , ios::in | ios::out );		//開檔 : 此檔案可讀和寫 
	if( !inventory )		//若檔案不存在 
	{
		cout<<"The file is not exist ! ";
		return 0;
	}
	
	cout<<"Inventory information in the file : "<<endl;			//印出檔案中已存在的第一個物品資訊 
	getline( inventory , item.itemName[0] );					//將物品名稱存入 struct 裡面的 itemName[0] 
	cout<<"Item's name => "<<item.itemName[0]<<endl;			//印出物品名稱 
	inventory>>item.itemQuantity[0];							//將物品數量存入 struct 裡面的 itemQuantity[0] 
	cout<<"Item's quantity on hand => "<<item.itemQuantity[0]<<endl;			//印出物品數量 
	inventory>>item.itemWholeSale[0];											//將物品總銷售額存入 struct 裡面的 itemWholeSale[0] 
	cout<<"Item's wholeSale cost => "<<item.itemWholeSale[0]<<endl;				//印出物品總銷售額 
	inventory>>item.itemRetail[0];												//將物品零售額存入 struct 裡面的 itemRetail[0]	
	cout<<"Item's retail cost => "<<item.itemRetail[0]<<endl;					//印出物品零售額 
	inventory>>item.itemDate[0];												//將物品加入庫存的日期存入 struct 裡面的 itemDate[0] 
	cout<<"Item's date added to inventory => "<<item.itemDate[0]<<endl<<endl;	//印出物品加入庫存的日期 
	
	inventory.close();				//將檔案關閉 
	
	inventory.open( fileName , ios::out | ios::trunc );		//將檔案開啟並將裡面內容清空 
	do
	{
		cout<<"What do you want to do on the item's information : "<<endl;		//詢問要對庫存檔案中的物品做的事 
		cout<<"1 -> Add new records to the file "<<endl;				//1 -> 增加新物品 
		cout<<"2 -> Display any record in the file "<<endl;				//2 -> 列出先前已加入物品的資訊 
		cout<<"3 -> Change any reord in the file : ";					//3 -> 修改物品中的資訊 
		cin>>activity_choose;			//輸入要做的事的代號 
		activity_choose = activity_check( activity_choose );		//防呆 : 只能輸入 1 或 2 或 3  
		cout<<endl;
		if( activity_choose == 1 )			//Add new records to the file 增加新物品 
		{
			do
			{
				cout<<"Please enter item's name : ";				//輸入新物品名稱 
				cin>>item.itemName[ index ];						//將新物品名稱存入 struct 內的 itemName 
				cout<<"Please enter item's quantity on hand : ";	//輸入新物品數量 
				cin>>item.itemQuantity[ index ];					//將新物品數量存入 struct 內的 itemQuantity 
				cout<<"Please enter item's wholeSale cost : ";		//輸入新物品的總銷售額 
				cin>>item.itemWholeSale[ index ];					//將新物品的總銷售額存入 struct 內的 itemWholeSale 
				cout<<"Please enter item's retail cost : ";			//輸入新物品的零售額 
				cin>>item.itemRetail[ index ];						//將新物品的零售額存入 struct 內的 itemRetail 
				cout<<"Please enter item's date added to inventory : ";		//輸入新物品加入庫存的日期 
				cin>>item.itemDate[ index ];								//將新物品加入庫存的日期存入 struct 內的 itemDate 
				index++;
				cout<<"Do you want to keep adding new item in the file ( Y/N ) ? ";		//詢問是否繼續加入新物品 
				cin>>exit_choose;
				exit_choose = YesNo_check( exit_choose );			//防呆 : 只能輸入 Y/y 或 N/n 
				
			}while( exit_choose == 'Y' || exit_choose == 'y' );		
		} 
		else if( activity_choose == 2 )		//Display any record in the file 列出物品資訊 
		{	
			do
			{
				cout<<"Please enter the item's name to display it's information : ";		//輸入物品的名稱來印出物品資訊 
				cin>>name;
				for(i=0;i<index;i++)			//尋長輸入的物品名稱是否存在在庫存中 
				{
					if( item.itemName[i] == name )
					{
						target = i;
						break;
					}
				}
				if( i == index )	//若不在庫存內 
				{
					cout<<"The item doesn't in the inventory !"<<endl;
				}	
				else				//若存在在庫存內 
				{
					cout<<endl<<item.itemName[ target ]<<" 's information : "<<endl;		//印出物品資訊 : 數量 , 總銷售額 , 零售額 , 日期 
					cout<<"                    Quantity on hand => "<< item.itemQuantity[ target ] <<endl;
					cout<<"                    WoleSale cost => "<< item.itemWholeSale[ target ] <<endl;
					cout<<"                    Retail cost => "<< item.itemRetail[ target ] <<endl;
					cout<<"                    Date added to inventory => "<< item.itemDate[ target ] <<endl;
				}
				cout<<"Do you want to keep displaying item in the file ( Y/N ) ? ";			//詢問是否繼續印出先前的物品資訊 
				cin>>exit_choose;
				exit_choose = YesNo_check( exit_choose );		//防呆 : 只能輸入 Y/y 或 N/n 
		
			}while( exit_choose == 'Y' || exit_choose == 'y' );
		}
		else if( activity_choose == 3 )		//Change any record in the file	修改物品資訊 
		{
			cout<<"Please enter the item's name to change it's information : ";		//輸入物品名稱來修改物品資訊 
			cin>>name;
			for(i=0;i<index;i++)		//尋找物品是否存在在庫存中 
			{
				if( item.itemName[i] == name )
				{
					target = i;
					break;	
				}	
			} 
			if( i == index )		//若不在庫存內 
			{
				cout<<"The item doesn't in the inventory !"<<endl;
			}
			else			//若存在在庫存內 
			{
				do
				{
					cout<<"1 -> name "<<endl;				//輸入想修改的物品資訊 
					cout<<"2 -> quantity "<<endl;
					cout<<"3 -> wholeSale cost "<<endl;
					cout<<"4 -> retail cost "<<endl;
					cout<<"5 -> date added to inventory : "<<endl;
					cin>>change_choose;
					change_choose = change_check( change_choose );		//防呆 : 只能輸入 1 , 2 , 3 , 4 或 5 
					
					if( change_choose == 1 )			//修改物品名稱 
					{
						cout<<"Please enter the new name : ";
						cin>>name;
						item.itemName[ target ] = name;
					}	
					else if( change_choose == 2 )		//修改物品數量 
					{
						cout<<"Please enter the new quantity : ";
						cin>>num;
						item.itemQuantity[ target ] = num;
					}
					else if( change_choose == 3 )		//修改物品總銷售額 
					{
						cout<<"Please enter the new wholeSale cost : ";
						cin>>money;
						item.itemWholeSale[ target ] = money;
					}
					else if( change_choose == 4 )		//修改物品零售額 
					{
						cout<<"Please enter the new retail cost : ";
						cin>>money;
						item.itemRetail[ target ] = money;
					}
					else if( change_choose ==  5 )		//修改物品加入庫存的日期 
					{
						cout<<"Please enter the new date added to inventory : ";
						cin>>date;
						item.itemDate[ target ] = date;
					}
					
					cout<<"Do you want to keep changing "<<item.itemName[ target ]<<" 's information ( Y/N ) ? ";		//詢問是否繼續修改此物品資訊 
					cin>>exit_choose;
					exit_choose = YesNo_check( exit_choose );		//防呆 : 只能輸入 Y/y 或 N/n 
					
				}while( exit_choose == 'Y' || exit_choose == 'y' );
			}
		}
		
		cout<<"Do you want to keep doing activity in this file ( Y/N ) ? ";		//詢問是否繼續對檔案進行修改 , 查看 , 新增 
		cin>>exit_choose; 
		exit_choose = YesNo_check( exit_choose );		//防呆 : 只能輸入 Y/y 或 N/n 
		cout<<endl;
	}while( exit_choose == 'Y' || exit_choose == 'y' );
	
	for(i=0;i<index;i++)						//將剛剛對庫存中新增,修改的檔案存入檔案中 
	{
		inventory<<item.itemName[i]<<'\n';			//將物品名稱寫入檔案 
		inventory<<item.itemQuantity[i]<<'\n';		//將物品數量寫入檔案 
		inventory<<item.itemWholeSale[i]<<'\n';		//將物品總銷售額寫入檔案 
		inventory<<item.itemRetail[i]<<'\n';		//將物品零售額寫入檔案 
		inventory<<item.itemDate[i]<<'\n'<<'\n';	//將物品加入庫存的日期謝入檔案 
	}
	
	inventory.close();		//關閉檔案 
	
	return 0;
}




































 
