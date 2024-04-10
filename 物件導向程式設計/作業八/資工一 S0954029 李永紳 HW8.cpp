/*
	�����ɦW : test.txt 
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

char YesNo_check( char choose )		//���b : �u���J Y/y �� N/n 
{
	while( choose != 'Y' && choose != 'y' && choose != 'N' && choose != 'n' )
	{
		cout<<"You have to enter Y/y or N/n !"<<endl;
		cout<<"Please enter choose again : ";
		cin>>choose;
	}
	
	return choose;	
} 

int activity_check( int choose )	//���b : �u���J 1 �� 2 �� 3
{
	while( choose != 1 && choose != 2 && choose != 3 )
	{
		cout<<"You have to enter 1 , 2 or 3 !"<<endl;
		cout<<"Please enter choose again : ";
		cin>>choose;
	}	
	
  	return choose;
}  

int change_check( int choose )		//���b : �u���J 1 , 2 , 3 , 4 �� 5 
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
	cout<<"Please enter file's name : ";		//��J�ɮצW�� 
	cin>>fileName;
	fstream inventory( fileName , ios::in | ios::out );		//�}�� : ���ɮץiŪ�M�g 
	if( !inventory )		//�Y�ɮפ��s�b 
	{
		cout<<"The file is not exist ! ";
		return 0;
	}
	
	cout<<"Inventory information in the file : "<<endl;			//�L�X�ɮפ��w�s�b���Ĥ@�Ӫ��~��T 
	getline( inventory , item.itemName[0] );					//�N���~�W�٦s�J struct �̭��� itemName[0] 
	cout<<"Item's name => "<<item.itemName[0]<<endl;			//�L�X���~�W�� 
	inventory>>item.itemQuantity[0];							//�N���~�ƶq�s�J struct �̭��� itemQuantity[0] 
	cout<<"Item's quantity on hand => "<<item.itemQuantity[0]<<endl;			//�L�X���~�ƶq 
	inventory>>item.itemWholeSale[0];											//�N���~�`�P���B�s�J struct �̭��� itemWholeSale[0] 
	cout<<"Item's wholeSale cost => "<<item.itemWholeSale[0]<<endl;				//�L�X���~�`�P���B 
	inventory>>item.itemRetail[0];												//�N���~�s���B�s�J struct �̭��� itemRetail[0]	
	cout<<"Item's retail cost => "<<item.itemRetail[0]<<endl;					//�L�X���~�s���B 
	inventory>>item.itemDate[0];												//�N���~�[�J�w�s������s�J struct �̭��� itemDate[0] 
	cout<<"Item's date added to inventory => "<<item.itemDate[0]<<endl<<endl;	//�L�X���~�[�J�w�s����� 
	
	inventory.close();				//�N�ɮ����� 
	
	inventory.open( fileName , ios::out | ios::trunc );		//�N�ɮ׶}�ҨñN�̭����e�M�� 
	do
	{
		cout<<"What do you want to do on the item's information : "<<endl;		//�߰ݭn��w�s�ɮפ������~������ 
		cout<<"1 -> Add new records to the file "<<endl;				//1 -> �W�[�s���~ 
		cout<<"2 -> Display any record in the file "<<endl;				//2 -> �C�X���e�w�[�J���~����T 
		cout<<"3 -> Change any reord in the file : ";					//3 -> �ק磌�~������T 
		cin>>activity_choose;			//��J�n�����ƪ��N�� 
		activity_choose = activity_check( activity_choose );		//���b : �u���J 1 �� 2 �� 3  
		cout<<endl;
		if( activity_choose == 1 )			//Add new records to the file �W�[�s���~ 
		{
			do
			{
				cout<<"Please enter item's name : ";				//��J�s���~�W�� 
				cin>>item.itemName[ index ];						//�N�s���~�W�٦s�J struct ���� itemName 
				cout<<"Please enter item's quantity on hand : ";	//��J�s���~�ƶq 
				cin>>item.itemQuantity[ index ];					//�N�s���~�ƶq�s�J struct ���� itemQuantity 
				cout<<"Please enter item's wholeSale cost : ";		//��J�s���~���`�P���B 
				cin>>item.itemWholeSale[ index ];					//�N�s���~���`�P���B�s�J struct ���� itemWholeSale 
				cout<<"Please enter item's retail cost : ";			//��J�s���~���s���B 
				cin>>item.itemRetail[ index ];						//�N�s���~���s���B�s�J struct ���� itemRetail 
				cout<<"Please enter item's date added to inventory : ";		//��J�s���~�[�J�w�s����� 
				cin>>item.itemDate[ index ];								//�N�s���~�[�J�w�s������s�J struct ���� itemDate 
				index++;
				cout<<"Do you want to keep adding new item in the file ( Y/N ) ? ";		//�߰ݬO�_�~��[�J�s���~ 
				cin>>exit_choose;
				exit_choose = YesNo_check( exit_choose );			//���b : �u���J Y/y �� N/n 
				
			}while( exit_choose == 'Y' || exit_choose == 'y' );		
		} 
		else if( activity_choose == 2 )		//Display any record in the file �C�X���~��T 
		{	
			do
			{
				cout<<"Please enter the item's name to display it's information : ";		//��J���~���W�٨ӦL�X���~��T 
				cin>>name;
				for(i=0;i<index;i++)			//�M����J�����~�W�٬O�_�s�b�b�w�s�� 
				{
					if( item.itemName[i] == name )
					{
						target = i;
						break;
					}
				}
				if( i == index )	//�Y���b�w�s�� 
				{
					cout<<"The item doesn't in the inventory !"<<endl;
				}	
				else				//�Y�s�b�b�w�s�� 
				{
					cout<<endl<<item.itemName[ target ]<<" 's information : "<<endl;		//�L�X���~��T : �ƶq , �`�P���B , �s���B , ��� 
					cout<<"                    Quantity on hand => "<< item.itemQuantity[ target ] <<endl;
					cout<<"                    WoleSale cost => "<< item.itemWholeSale[ target ] <<endl;
					cout<<"                    Retail cost => "<< item.itemRetail[ target ] <<endl;
					cout<<"                    Date added to inventory => "<< item.itemDate[ target ] <<endl;
				}
				cout<<"Do you want to keep displaying item in the file ( Y/N ) ? ";			//�߰ݬO�_�~��L�X���e�����~��T 
				cin>>exit_choose;
				exit_choose = YesNo_check( exit_choose );		//���b : �u���J Y/y �� N/n 
		
			}while( exit_choose == 'Y' || exit_choose == 'y' );
		}
		else if( activity_choose == 3 )		//Change any record in the file	�ק磌�~��T 
		{
			cout<<"Please enter the item's name to change it's information : ";		//��J���~�W�٨ӭק磌�~��T 
			cin>>name;
			for(i=0;i<index;i++)		//�M�䪫�~�O�_�s�b�b�w�s�� 
			{
				if( item.itemName[i] == name )
				{
					target = i;
					break;	
				}	
			} 
			if( i == index )		//�Y���b�w�s�� 
			{
				cout<<"The item doesn't in the inventory !"<<endl;
			}
			else			//�Y�s�b�b�w�s�� 
			{
				do
				{
					cout<<"1 -> name "<<endl;				//��J�Q�ק諸���~��T 
					cout<<"2 -> quantity "<<endl;
					cout<<"3 -> wholeSale cost "<<endl;
					cout<<"4 -> retail cost "<<endl;
					cout<<"5 -> date added to inventory : "<<endl;
					cin>>change_choose;
					change_choose = change_check( change_choose );		//���b : �u���J 1 , 2 , 3 , 4 �� 5 
					
					if( change_choose == 1 )			//�ק磌�~�W�� 
					{
						cout<<"Please enter the new name : ";
						cin>>name;
						item.itemName[ target ] = name;
					}	
					else if( change_choose == 2 )		//�ק磌�~�ƶq 
					{
						cout<<"Please enter the new quantity : ";
						cin>>num;
						item.itemQuantity[ target ] = num;
					}
					else if( change_choose == 3 )		//�ק磌�~�`�P���B 
					{
						cout<<"Please enter the new wholeSale cost : ";
						cin>>money;
						item.itemWholeSale[ target ] = money;
					}
					else if( change_choose == 4 )		//�ק磌�~�s���B 
					{
						cout<<"Please enter the new retail cost : ";
						cin>>money;
						item.itemRetail[ target ] = money;
					}
					else if( change_choose ==  5 )		//�ק磌�~�[�J�w�s����� 
					{
						cout<<"Please enter the new date added to inventory : ";
						cin>>date;
						item.itemDate[ target ] = date;
					}
					
					cout<<"Do you want to keep changing "<<item.itemName[ target ]<<" 's information ( Y/N ) ? ";		//�߰ݬO�_�~��ק惡���~��T 
					cin>>exit_choose;
					exit_choose = YesNo_check( exit_choose );		//���b : �u���J Y/y �� N/n 
					
				}while( exit_choose == 'Y' || exit_choose == 'y' );
			}
		}
		
		cout<<"Do you want to keep doing activity in this file ( Y/N ) ? ";		//�߰ݬO�_�~����ɮ׶i��ק� , �d�� , �s�W 
		cin>>exit_choose; 
		exit_choose = YesNo_check( exit_choose );		//���b : �u���J Y/y �� N/n 
		cout<<endl;
	}while( exit_choose == 'Y' || exit_choose == 'y' );
	
	for(i=0;i<index;i++)						//�N����w�s���s�W,�ק諸�ɮצs�J�ɮפ� 
	{
		inventory<<item.itemName[i]<<'\n';			//�N���~�W�ټg�J�ɮ� 
		inventory<<item.itemQuantity[i]<<'\n';		//�N���~�ƶq�g�J�ɮ� 
		inventory<<item.itemWholeSale[i]<<'\n';		//�N���~�`�P���B�g�J�ɮ� 
		inventory<<item.itemRetail[i]<<'\n';		//�N���~�s���B�g�J�ɮ� 
		inventory<<item.itemDate[i]<<'\n'<<'\n';	//�N���~�[�J�w�s������¤J�ɮ� 
	}
	
	inventory.close();		//�����ɮ� 
	
	return 0;
}




































 
