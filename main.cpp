#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int codePerson, financialCode, option, userPhone, accountType, cardType, searchCodePerson = 1, optionMenu;
string username, userLastname, userAddress, userEmail, passwordEmail, user, password, bankName, accountNumber = "a", accountTypeStr, cardNumber, cardTypeStr;
bool exist = false;

bool is_empty(ifstream& pFile) 
{ 
    return pFile.peek() == ifstream::traits_type::eof(); 
} 

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

bool verifyExistInPersonal(int code){
	bool returnValue;
	ifstream searchInFile("Informacion-Personal.txt");
	if(is_empty(searchInFile)){
		returnValue = false;
	}else{	
		while (searchInFile != NULL) {
			searchInFile>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
			if (codePerson == code) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
	codePerson = code;
	searchInFile.close();
	return returnValue;
}

bool verifyExistInFinancial(int code){
	bool returnValue;
	ifstream searchInFile("Informacion-Financiera.txt");
	if(is_empty(searchInFile)){
		returnValue = false;
	}else{	
		while (searchInFile != NULL) {
			searchInFile>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
			if (financialCode == code) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
	financialCode = code;
	searchInFile.close();
	return returnValue;
}

bool verifyExistAccount(string account){
	bool returnValue;
	ifstream searchInFile("Informacion-Financiera.txt");	
	if(is_empty(searchInFile)){
		returnValue = false;
	}else{
		while (searchInFile != NULL) {
			searchInFile>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
			if (accountNumber == account) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
	accountNumber = account;
	searchInFile.close();
	return returnValue;
}

bool verifyExistInVirtualAcounts(int code){
	bool returnValue;
	ifstream searchInFile("Cuentas-Virtuales.txt");	
	if(is_empty(searchInFile)){
		returnValue = false;
	}else{
		while (searchInFile != NULL) {
			searchInFile>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
			if (codePerson == code) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
	codePerson = code;
	searchInFile.close();
	return returnValue;
}

void dataEntryProcedure() {
	do {
		system("cls");
		cout<<"----- Ingreso de informacion -----"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Ingreso de datos personales"<<endl;
		cout<<"2. Ingreso de datos financieros"<<endl;
		cout<<"3. Ingreso de datos para cuentas virtuales"<<endl;
		cout<<"4. Salir"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				system("cls");
				ofstream createRecordInPersonalInformation("Informacion-Personal.txt", ios::app);
				cout<<endl<<"------------------ Ingreso de informacion personal ------------------"<<endl;
				do{
					cout<<"Codigo: ";
					cin>>codePerson;
					exist = verifyExistInPersonal(codePerson);
				} while (exist);
				cout<<"Nombre: ";
				cin>>username;
				cout<<"Apellido: ";
				cin>>userLastname;
				cout<<"Direccion: ";
				cin>>userAddress;
				cout<<"Correo electronico: ";
				cin>>userEmail;
				cout<<"Contrasenia de correo: ";
				cin>>passwordEmail;
				cout<<"Telefono/Celular: ";
				cin>>userPhone;
				createRecordInPersonalInformation<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<" "<<endl;
				createRecordInPersonalInformation.close();
			}
			break;
			case 2:{
				system("cls");
				ofstream createRecordInFinancialData("Informacion-Financiera.txt", ios::app);
				cout<<endl<<"----------------- Ingreso de informacion financiera -----------------"<<endl;
				do{
					cout<<"Codigo financiero: ";
					cin>>financialCode;
					exist = verifyExistInFinancial(financialCode);
				} while (exist);
				do{
					cout<<"Codigo Persona: ";
					cin>>codePerson;
					exist = verifyExistInPersonal(codePerson);
				} while (exist == false);
				cout<<"Nombre banco: ";
				cin>>bankName;
				//do{
				//	cout<<"Numero de cuenta: ";
				//	cin>>accountNumber;
				//	exist = verifyExistAccount(accountNumber);
				//} while (exist);
				do {
					cout<<"Ingrese el numero correspondiente al tipo de cuenta: \n\t 1. Ahorro\n\t 2. Monetaria"<<endl;
					cin>>accountType;
					if (accountType >= 3 || accountType <= 0) {
						cout<<"No es un tipo valido de cuenta, ingrese otro. ";
					}
				} while (accountType >= 3 || accountType <= 0);
				cout<<"Numero de tarjeta(XXXX-XXXX-XXXX-XXXX): ";
				cin>>cardNumber;
				do {
					cout<<"Ingrese el numero correspondiente al tipo de tarjeta: \n\t 1. Debito\n\t 2. Credito"<<endl;
					cin>>cardType;
					if (cardType >= 3 || cardType <= 0) {
						cout<<"No es un tipo valido de tarjeta, ingrese otro. ";
					}
				} while (cardType >= 3 || cardType <= 0);
				cout<<financialCode;
				cout<<codePerson;
				cout<<bankName;
				system("Pause");
				createRecordInFinancialData<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<accountTypeIntToString(accountType)<<" "<<cardNumber<<" "<<cardTypeIntToString(cardType)<<endl;
				createRecordInFinancialData.close();
			}
			break;
			case 3:{
				system("cls");
				ofstream createRecordInVirtualAccounts("Cuentas-Virtuales.txt", ios::app);
				cout<<endl<<"------------------ Ingreso de informacion personal ------------------"<<endl;
				cout<<"Codigo cuenta virtual: ";
				cin>>financialCode;
				do{
					cout<<"Codigo Pesona: ";
					cin>>codePerson;
					exist = verifyExistInPersonal(codePerson);
				} while (exist);
				cout<<"Usuario: ";
				cin>>user;
				cout<<"Contrasenia de usuario: ";
				cin>>password;
				createRecordInVirtualAccounts<<financialCode<<" "<<user<<" "<<password<<endl;
				createRecordInVirtualAccounts.close();
			}
			break;
			case 4:
				cout<<endl<<"Volviendo... ";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
	} while (optionMenu != 4);
}

main() {
	do {
		system("cls");
		cout<<"-------- Proyecto final --------"<<endl;
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
