#include <iostream>							//Made by S0954029李永伸
#include<iomanip>
#ifndef PATIENTACCOUNT_H
#define	PATIENTACCOUNT_H
using namespace std;

class PatientAccount							//病人class，可設置醫藥費、住院天數、總花費，並顯示出總花費 、住院天數  
{
	private :
			int serviceCharges;			//醫藥費 
			double totalCharges;		//總花費
			int totalDays;				//住院天數 
			double dailyRate; 			//日利率 
				
	public : 
			PatientAccount()				//建構函示，設初值 
			{
				serviceCharges = 0;	
				totalCharges = 0;			
				totalDays = 0;				 
				dailyRate = 870.69; 
				
			}
			void updateService(int money)		//更新醫藥費(手術費+藥費)		
			{
				serviceCharges += money;
			}
			
			void setDays(int day)				//追蹤住院天數 
			{
				totalDays += day;
			}
			int getDays(){						//顯示住院天數 
				return totalDays;
			}
			void showCharges(){																//顯示總花費 
				cout<<"總花費為 "<<fixed<<setprecision(2)<<totalCharges<<" 元"<<endl; 
			}			
			void updateCharges(){				//更新總花費 
				totalCharges = dailyRate*totalDays+serviceCharges;
			}
			
};
PatientAccount Patient;			//宣告PatientAccount,要用全域變數才可以被Surgery和Pharmacy使用且不會被歸零 

#endif
