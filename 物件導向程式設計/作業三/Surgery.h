#include <iostream>									//Made by S0954029李永伸
#include<iomanip>
#ifndef SURGERY_H
#define	SURGERY_H
using namespace std;

class Surgery
{
	private : 
			int gastroscopy,		//胃鏡檢查 
				appendectomy,		//闌尾切除 
				ligation,			//結紮
				thyroidectomy,		//甲狀腺切除
				nephrectomy;		//腎切除 		
	public : 
			Surgery(){						//建構函示，設初值 
				gastroscopy = 10000,		//胃鏡檢查花費 
				appendectomy = 150000,		//闌尾切除花費 
				ligation = 8000,			//結紮花費 
				thyroidectomy = 120000,		//甲狀腺切除花費 
				nephrectomy = 200000;		//腎切除花費 
			}
			void checkSurgery(int typeSerial)							//檢查手術種類、並將花費傳給PatientAccount 
			{
					switch(typeSerial){
					case 1:Patient.updateService(gastroscopy);
							break;
					case 2:Patient.updateService(appendectomy);
							break;
					case 3:Patient.updateService(ligation);
							break;
					case 4:Patient.updateService(thyroidectomy);
							break;
					case 5:Patient.updateService(nephrectomy);
							break;
				}
				
			}		
};

#endif
