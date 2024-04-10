#include <iostream>					//Made by S0954037莊明憲
#include<iomanip>
#ifndef PHARMACY_H
#define	PHARMACY_H
using namespace std;

class Pharmacy{
	private:
		int painkiller;			//止痛藥
		int antipyretic;		//退燒藥
		int coughsyrup; 		//咳嗽糖漿
		int steroid;			//類固醇
		int antibiotics;		//抗生素 
	public:
		Pharmacy(){						//建構函示，設初值 
			painkiller = 10;		//止痛藥花費 
			antipyretic = 15;		//退燒藥花費 
			coughsyrup = 20; 		//咳嗽糖漿花費 
			steroid = 30;			//類固醇花費 
			antibiotics = 50;		//抗生素花費 
		} 
		void checkMedicine(int typeSerial)					//檢查藥品種類、並將花費傳給PatientAccount
		{
			switch(typeSerial){
				case 1:	Patient.updateService(painkiller);
						break;
				case 2:Patient.updateService(antipyretic);
						break;
				case 3:Patient.updateService(coughsyrup);
						break;
				case 4:Patient.updateService(steroid);
						break;
				case 5:Patient.updateService(antibiotics);
						break;
			}
		}	
} ;

#endif
