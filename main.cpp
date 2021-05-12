#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int option, userPhone, accountNumber, accountType, cardType;
string username, userLastname, userAddress, userEmail, password, bankName, cardNumber;


string accountTypeIntToString(int type) {
	switch (type) {
		case 1:
			return "Ahorro";
			break;
		case 2:
			return "Monetaria";
			break;
	}
}

string cardTypeIntToString(int type) {
	switch (type) {
		case 1:
			return "Debito";
			break;
		case 2:
			return "Credito";
			break;
	}
}

int searchLastDigit(int file){
    int counter = 1, code;
	if(file == 1){
    	ifstream openFile1("Informacion-Personal.txt");
        while (openFile1 != NULL){
            openFile1>>code;
			counter++;
			cout<<"Codigo: "<<code;
        }
    	openFile1.close();
    	return counter = counter + 1;
	}else if(file == 2){
		ifstream openFile2("Informacion-Financiera.txt");
        while (openFile2 != NULL){
            openFile2>>code;
			counter++;
			cout<<"Codigo: "<<code;
        }
    	openFile2.close();
		return counter = counter + 1;
	}else{
		ifstream openFile3("Cuentas-Virtuales.txt");
        while (openFile3 != NULL){
            openFile3>>code;
			counter++;
			cout<<"Codigo: "<<code;
        }
    	openFile3.close();
		return counter = counter + 1;
	}
}

void dataEntryProcedure() {
	cout<<searchLastDigit(3)<<endl;
	system("Pause");
	system("cls");
	ofstream createRecordInPersonalInformation("Informacion-Personal.txt", ios::app);
    ofstream createRecordInFinancialData("Informacion-Financiera.txt", ios::app);
    ofstream createRecordInVirtualAccounts("Cuentas-Virtuales.txt", ios::app);
    cout<<endl<<"------------------ Ingreso de informacion personal ------------------"<<endl;
	cout<<"Nombre: ";
	cin>>username;
	cout<<"Apellido: ";
	cin>>userLastname;
	cout<<"Direccion: ";
	cin>>userAddress;
	cout<<"Correo electronico: ";
	cin>>userEmail;
	cout<<"Contrasenia de ingreso: ";
	cin>>password;
    cout<<"Telefono/Celular: ";
	cin>>userPhone; 
	cout<<endl<<"----------------- Ingreso de informacion financiera -----------------"<<endl;
	cout<<"Nombre banco: ";
	cin>>bankName;
	cout<<"Numero de cuenta: ";
	cin>>accountNumber;
	do {
		cout<<"Ingrese el número correspondiente al tipo de cuenta: \n\t 1. Ahorro\n\t 2. Monetaria"<<endl;
		cin>>accountType;
		if (accountType >= 3 || accountType <= 0) {
			cout<<"No es un tipo valido de cuenta, ingrese otro. ";
		}
	} while (accountType > 3 || accountType < 0);
    cout<<"Numero de tarjeta(XXXX-XXXX-XXXX-XXXX): ";
	cin>>cardNumber;
    do {
		cout<<"Ingrese el número correspondiente al tipo de tarjeta: \n\t 1. Debito\n\t 2. Credito"<<endl;
		cin>>cardType;
		if (cardType >= 3 || cardType <= 0) {
			cout<<"No es un tipo valido de tarjeta, ingrese otro. ";
		}
	} while (cardType > 3 || cardType < 0);

	
	// createRecord<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
	// createRecord.close();
}

main() {
	do {
		system("cls");
		cout<<"-------- Proyecto final --------"<<endl;;
		cout<<"----- Informacion personal -----"<<endl;
        cout<<"--------------------------------"<<endl;
		cout<<"1. Ingreso de informacion"<<endl;
		cout<<"2. Visualizacion de informacion"<<endl;
		cout<<"3. Modificacion de informacion"<<endl;
		cout<<"4. Salir"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>option;
		switch (option) {
			case 1:
				dataEntryProcedure();
				break;
			case 2:
				//dataDisplayProcedure();
				break;
			case 3:
				//dataModifyProcedure();
				break;
			case 4:
				cout<<endl<<"Gracias por utilizar nuestro servicio de informacion."<<endl;
                cout<<"Estudiantes: \n\tJulio Estuardo Teleguario Canu --- 1990 - 20 - 4006\n\tEdson Oseas Nimajuan Soloman ----- 1990 - 20 - 4003";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
	} while (option != 4);
}
