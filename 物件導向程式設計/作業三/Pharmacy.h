#include <iostream>					//Made by S0954037������
#include<iomanip>
#ifndef PHARMACY_H
#define	PHARMACY_H
using namespace std;

class Pharmacy{
	private:
		int painkiller;			//��h��
		int antipyretic;		//�h�N��
		int coughsyrup; 		//�y�¿}��
		int steroid;			//���T�J
		int antibiotics;		//�ܥͯ� 
	public:
		Pharmacy(){						//�غc��ܡA�]��� 
			painkiller = 10;		//��h�Ī�O 
			antipyretic = 15;		//�h�N�Ī�O 
			coughsyrup = 20; 		//�y�¿}�ߪ�O 
			steroid = 30;			//���T�J��O 
			antibiotics = 50;		//�ܥͯ���O 
		} 
		void checkMedicine(int typeSerial)					//�ˬd�ī~�����B�ñN��O�ǵ�PatientAccount
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
