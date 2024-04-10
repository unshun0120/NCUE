#include "Print.h"
#include<iostream>
using namespace std;

void addPrint::print() const		//當新增資料結束 
{
	cout<<"The information has been added to the file !"<<endl;
	cout<<"資料已被新增至檔案中了 ! "<<endl<<endl;	
}

void modifyPrint::print() const		//當修改資料結束 
{
	cout<<"The information has been modified !"<<endl;
	cout<<"資料已被修改了 ! "<<endl<<endl;
}

void deletePrint::print() const	    //當刪除資料結束 
{
	cout<<"The information has been deleted !"<<endl;
	cout<<"資料已被刪除了 ! "<<endl<<endl;
}

void recoverPrint::print() const	//當復原資料結束 
{
	cout<<"The information has been recovered !"<<endl;
	cout<<"資料已經復原至檔案中了 ! "<<endl<<endl;	
}

