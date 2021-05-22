#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int codePerson, financialCode, virtualCodeAccount, option, userPhone, accountType, cardType, optionMenu, financialCodeTempForFile, codePersonTempForFile;
string accountNumberTempForFile, username, userLastname, userAddress, userEmail, passwordEmail, user, password, bankName, accountNumber = "a", accountTypeStr, cardNumber, cardTypeStr;
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
			searchInFile>>financialCode>>codePersonTempForFile>>bankName>>accountNumberTempForFile>>accountTypeStr>>cardNumber>>cardTypeStr;
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

bool verifyExistInVirtualAcounts(int code){
	bool returnValue;
	ifstream searchInFile("Cuentas-Virtuales.txt");
	if(is_empty(searchInFile)){
		returnValue = false;
	}else{	
		while (searchInFile != NULL) {
			searchInFile>>virtualCodeAccount>>codePersonTempForFile>>financialCodeTempForFile>>user>>password;
			if (codePerson == code) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
	virtualCodeAccount = code;
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
			searchInFile>>financialCode>>codePerson>>bankName>>accountNumberTempForFile>>accountTypeStr>>cardNumber>>cardTypeStr;
			if (accountNumberTempForFile == account) {
				returnValue = true;
			}else if(returnValue != true){
				returnValue = false;
			}
		}
	}
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
				system("Pause");
				createRecordInPersonalInformation<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<" "<<endl;
				createRecordInPersonalInformation.close();
			}
			break;
			case 2:{
				system("cls");
				ofstream createRecordInFinancialData("Informacion-Financiera.txt", ios::app);
				cout<<endl<<"----------------- Ingreso de informacion financiera -----------------"<<endl;
				do{
					cout<<"Numero de cuenta: ";
					cin>>accountNumber;
					exist = verifyExistAccount(accountNumber);
				} while (exist);
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
				system("Pause");
				createRecordInFinancialData<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<accountTypeIntToString(accountType)<<" "<<cardNumber<<" "<<cardTypeIntToString(cardType)<<endl;
				createRecordInFinancialData.close();
			}
			break;
			case 3:{
				system("cls");
				ofstream createRecordInVirtualAccounts("Cuentas-Virtuales.txt", ios::app);
				cout<<endl<<"------------ Ingreso de informacion de cuentas virtuales ------------"<<endl;
				do{
					cout<<"Codigo cuenta virtual: ";
					cin>>virtualCodeAccount;
					exist = verifyExistInVirtualAcounts(virtualCodeAccount);
				} while (exist);
				do{
					cout<<"Codigo Persona: ";
					cin>>codePerson;
					exist = verifyExistInPersonal(codePerson);
				} while (exist == false);
				do{
					cout<<"Codigo financiero: ";
					cin>>financialCode;
					exist = verifyExistInFinancial(financialCode);
				} while (exist == false);
				cout<<"Usuario: ";
				cin>>user;
				cout<<"Contrasenia de usuario: ";
				cin>>password;
				system("Pause");
				createRecordInVirtualAccounts<<virtualCodeAccount<<" "<<codePerson<<" "<<financialCode<<" "<<user<<" "<<password<<endl;
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

void dataDisplayProcedureFromPersonalData(){
	int findInt, TMPInt = 0;
	string findString, TMPString = "";
	do{
		ifstream searchData("Informacion-Personal.txt");
		system("cls");
		cout<<"------ Mostrar informacion -------"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Todos los datos"<<endl;
		cout<<"2. Codigo"<<endl;
		cout<<"3. Nombre"<<endl;
		cout<<"4. Apellido"<<endl;
		cout<<"5. Direccion"<<endl;
		cout<<"6. Correo electronico"<<endl;
		cout<<"7. Telefono"<<endl;
		cout<<"8. Regresar"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				system("cls");
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 2:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (codePerson ==  findInt && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 3:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Nombre: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (username ==  findString && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 4:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Apellido: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (userLastname ==  findString && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 5:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Direccion: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (userAddress ==  findString && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 6:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"email: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (userEmail ==  findString && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 7:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Telefono: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
					if (userPhone ==  findInt && codePerson != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo: "<<codePerson<<endl;
						cout<<"Nombre: "<<username<<endl;
						cout<<"Apellido: "<<userLastname<<endl;
						cout<<"Direccion: "<<userAddress<<endl;
						cout<<"Correo electronico: "<<userEmail<<endl;
						cout<<"Telefono: "<<userPhone<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = codePerson;
				}
				system("pause");
			}
			break;
			case 8:
				cout<<endl<<"Volviendo... ";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
		searchData.close();
	} while (optionMenu != 8);
}

void dataDisplayProcedureFromFinancialData(){
	int findInt, TMPInt = 0;
	string findString, TMPString = "";
	do{
		ifstream searchData("Informacion-Financiera.txt");
		system("cls");
		cout<<"------ Mostrar informacion -------"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Todos los datos"<<endl;
		cout<<"2. Codigo financiero"<<endl;
		cout<<"3. Codigo Persona"<<endl;
		cout<<"4. Nombre banco"<<endl;
		cout<<"5. Numero de cuenta"<<endl;
		cout<<"6. Tipo de cuenta"<<endl;
		cout<<"7. Tarjeta"<<endl;
		cout<<"8. Tipo de tarjeta"<<endl;
		cout<<"9. Regresar"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				system("cls");
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 2:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo financiero: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (financialCode == findInt && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 3:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo Persona: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (codePerson == findInt && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 4:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Nombre banco: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (bankName == findString && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 5:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Numero de cuenta: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (accountNumber == findString && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 6:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				do {
					cout<<"Ingrese el numero correspondiente al tipo de cuenta: \n\t 1. Ahorro\n\t 2. Monetaria"<<endl;
					cin>>accountType;
					if (accountType >= 3 || accountType <= 0) {
						cout<<"No es un tipo valido de cuenta, ingrese otro. ";
					}
				} while (accountType >= 3 || accountType <= 0);
				findString = accountTypeIntToString(accountType);
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (accountTypeStr == findString && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 7:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Tarjeta: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (cardNumber == findString && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 8:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				do {
					cout<<"Ingrese el numero correspondiente al tipo de tarjeta: \n\t 1. Debito\n\t 2. Credito"<<endl;
					cin>>cardType;
					if (cardType >= 3 || cardType <= 0) {
						cout<<"No es un tipo valido de tarjeta, ingrese otro. ";
					}
				} while (cardType >= 3 || cardType <= 0);
				findString = cardTypeIntToString(cardType);
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
					if (cardTypeStr == findString && financialCode != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Nombre banco: "<<bankName<<endl;
						cout<<"Numero de cuenta: "<<accountNumber<<endl;
						cout<<"Tipo de cuenta: "<<accountTypeStr<<endl;
						cout<<"Tarjeta: "<<cardNumber<<endl;
						cout<<"Tipo de tarjeta: "<<cardTypeStr<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = financialCode;
				}
				system("pause");
			}
			break;
			case 9:
				cout<<endl<<"Volviendo... ";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
		searchData.close();
	} while (optionMenu != 9);
}

void dataDisplayProcedureFromVirtualAccounts(){
	int findInt, TMPInt = 0;
	string findString, TMPString = "";
	do{
		ifstream searchData("Cuentas-Virtuales.txt");
		system("cls");
		cout<<"------ Mostrar informacion -------"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Todos los datos"<<endl;
		cout<<"2. Codigo cuenta virtual"<<endl;
		cout<<"3. Codigo Persona"<<endl;
		cout<<"4. Codigo financiero"<<endl;
		cout<<"5. Usuario"<<endl;
		cout<<"6. Regresar"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				system("cls");
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
					if (virtualCodeAccount != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo cuenta virtual: "<<virtualCodeAccount<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Usuario: "<<user<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = virtualCodeAccount;
				}
				system("pause");
			}
			break;
			case 2:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo cuenta virtual: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
					if (virtualCodeAccount == findInt && virtualCodeAccount != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo cuenta virtual: "<<virtualCodeAccount<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Usuario: "<<user<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = virtualCodeAccount;
				}
				system("pause");
			}
			break;
			case 3:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo Persona: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
					if (codePerson == findInt && virtualCodeAccount != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo cuenta virtual: "<<virtualCodeAccount<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Usuario: "<<user<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = virtualCodeAccount;
				}
				system("pause");
			}
			break;
			case 4:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Codigo financiero: ";
				cin>>findInt;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
					if (financialCode == findInt && virtualCodeAccount != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo cuenta virtual: "<<virtualCodeAccount<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Usuario: "<<user<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = virtualCodeAccount;
				}
				system("pause");
			}
			break;
			case 5:{
				system("cls");
				cout<<"Ingrese el criterio de busqueda"<<endl;
				cout<<"Usuario: ";
				cin>>findString;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchData != NULL) {
					searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
					if (user == findString && virtualCodeAccount != TMPInt) {
						cout<<"---------------------------------------"<<endl;
						cout<<"Codigo cuenta virtual: "<<virtualCodeAccount<<endl;
						cout<<"Codigo Persona: "<<codePerson<<endl;
						cout<<"Codigo financiero: "<<financialCode<<endl;
						cout<<"Usuario: "<<user<<endl;
						cout<<"---------------------------------------"<<endl;
					}
					TMPInt = virtualCodeAccount;
				}
				system("pause");
			}
			break;
			case 6:
				cout<<endl<<"Volviendo... ";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
		searchData.close();
	} while (optionMenu != 6);
}

void dataDisplayProcedure(){
	do{
		system("cls");
		cout<<"------ Mostrar informacion -------"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Datos personales"<<endl;
		cout<<"2. Datos financieros"<<endl;
		cout<<"3. Datos de cuentas virtuales"<<endl;
		cout<<"4. Salir"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				dataDisplayProcedureFromPersonalData();
			}
			break;
			case 2:{
				dataDisplayProcedureFromFinancialData();
			}
			break;
			case 3:{
				dataDisplayProcedureFromVirtualAccounts();
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

void dataModifyProcedureFromPersonalData(){
	int codeSelected, otherOption, newValueInt, TMPInt = 0;
	string newValueString;
	ifstream searchData("Informacion-Personal.txt");
	ofstream saveTemporaly("temporal.txt");
	system("cls");
	cout<<"------ Modificar informacion -------"<<endl;
    cout<<"----------------------------------"<<endl;
	cout<<"Ingrese codigo de registro a modificar: "<<endl;
	cin>>codeSelected;
	while (searchData != NULL){
		searchData>>codePerson>>username>>userLastname>>userAddress>>userEmail>>passwordEmail>>userPhone;
		if (codePerson == codeSelected && codePerson != TMPInt) {
			do{
				cout<<"Coincidencia de busqueda con el codigo: "<<codePerson<<endl;
				cout<<"1. Nombre: "<<username<<endl;
				cout<<"2. Apellido: "<<userLastname<<endl;
				cout<<"3. Direccion: "<<userAddress<<endl;
				cout<<"4. Correo electronico: "<<userEmail<<endl;
				cout<<"5. Contrasena: "<<passwordEmail<<endl;
				cout<<"6. Telefono: "<<userPhone<<endl;
				cout<<"Que dato desea modificar? "<<endl;
				cin>>otherOption;
				switch (otherOption){
					case 1:{
						cout<<"Ingrese nuevo nombre: "<<endl;
						cin>>newValueString;
						saveTemporaly<<codePerson<<" "<<newValueString<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<endl;
						otherOption = 7;
					}
					break;
					case 2:{
						cout<<"Ingrese nuevo apellido: "<<endl;
						cin>>newValueString;
						saveTemporaly<<codePerson<<" "<<username<<" "<<newValueString<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<endl;
						otherOption = 7;
					}
					break;
					case 3:{
						cout<<"Ingrese nueva direccion: "<<endl;
						cin>>newValueString;
						saveTemporaly<<codePerson<<" "<<username<<" "<<userLastname<<" "<<newValueString<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<endl;
						otherOption = 7;
					}
					break;
					case 4:{
						cout<<"Ingrese nuevo email: "<<endl;
						cin>>newValueString;
						saveTemporaly<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<newValueString<<" "<<passwordEmail<<" "<<userPhone<<endl;
						otherOption = 7;
					}
					break;
					case 5:{
						cout<<"Ingrese nueva contrasena: "<<endl;
						cin>>newValueString;
						saveTemporaly<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<newValueString<<" "<<userPhone<<endl;
						otherOption = 7;
					}
					break;
					case 6:{
						cout<<"Ingrese nuevo telefono: "<<endl;
						cin>>newValueInt;
						saveTemporaly<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<newValueInt<<endl;
						otherOption = 7;
					}
					break;
					case 7:
						cout<<"Saliendo..."<<endl;
						break;
					default:
						cout<<"option no disponible"<<endl;
						break;
				}
			}while(otherOption != 7);
		}else if(codePerson != TMPInt){
			saveTemporaly<<codePerson<<" "<<username<<" "<<userLastname<<" "<<userAddress<<" "<<userEmail<<" "<<passwordEmail<<" "<<userPhone<<endl;
		}
		TMPInt = codePerson;
	}
	searchData.close();
	saveTemporaly.close();
	remove("Informacion-Personal.txt");
	rename("temporal.txt", "Informacion-Personal.txt");
}

void dataModifyProcedureFromFinancialData(){
	int codeSelected, accountType1, otherOption, newValueInt, TMPInt = 0;
	string newValueString;
	ifstream searchData("Informacion-Financiera.txt");
	ofstream saveTemporaly("temporal.txt");
	system("cls");
	cout<<"------ Modificar informacion -------"<<endl;
    cout<<"----------------------------------"<<endl;
	cout<<"Ingrese codigo de registro a modificar: "<<endl;
	cin>>codeSelected;
	while (searchData != NULL){
		searchData>>financialCode>>codePerson>>bankName>>accountNumber>>accountTypeStr>>cardNumber>>cardTypeStr;
		if (financialCode == codeSelected && financialCode != TMPInt) {
			do{
				cout<<"Coincidencia de busqueda con el codigo: "<<financialCode<<endl;
				cout<<"1. Nombre de banco: "<<bankName<<endl;
				cout<<"2. Numero de cuenta: "<<accountNumber<<endl;
				cout<<"3. Tipo de cuenta: "<<accountTypeStr<<endl;
				cout<<"4. Numero de tarjeta: "<<cardNumber<<endl;
				cout<<"5. Tipo de tarjeta: "<<cardTypeStr<<endl;
				cout<<"Que dato desea modificar? "<<endl;
				cin>>otherOption;
				switch (otherOption){
					case 1:{
						cout<<"Ingrese nuevo nombre de banco: "<<endl;
						cin>>newValueString;
						saveTemporaly<<financialCode<<" "<<codePerson<<" "<<newValueString<<" "<<accountNumber<<" "<<accountTypeStr<<" "<<cardNumber<<" "<<cardTypeStr<<endl;
						otherOption = 6;
					}
					break;
					case 2:{
						cout<<"Ingrese nuevo numero de cuenta: "<<endl;
						cin>>newValueString;
						saveTemporaly<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<newValueString<<" "<<accountTypeStr<<" "<<cardNumber<<" "<<cardTypeStr<<endl;
						otherOption = 6;
					}
					break;
					case 3:{
						do {
							cout<<"Ingrese el numero correspondiente al tipo de cuenta: \n\t 1. Ahorro\n\t 2. Monetaria"<<endl;
							cin>>accountType1;
							if (accountType1 >= 3 || accountType1 <= 0) {
								cout<<"No es un tipo valido de cuenta, ingrese otro. ";
							}
						} while (accountType1 >= 3 || accountType1 <= 0);
						newValueString = accountTypeIntToString(accountType1);
						saveTemporaly<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<newValueString<<" "<<cardNumber<<" "<<cardTypeStr<<endl;
						otherOption = 6;
					}
					break;
					case 4:{
						cout<<"Ingrese nuevo numero de tarjeta: "<<endl;
						cin>>newValueString;
						saveTemporaly<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<accountTypeStr<<" "<<newValueString<<" "<<cardTypeStr<<endl;
						otherOption = 6;
					}
					break;
					case 5:{
						do {
							cout<<"Ingrese el numero correspondiente al tipo de tarjeta: \n\t 1. Debito\n\t 2. Credito"<<endl;
							cin>>accountType1;
							if (accountType1 >= 3 || accountType1 <= 0) {
								cout<<"No es un tipo valido de cuenta, ingrese otro. ";
							}
						} while (accountType1 >= 3 || accountType1 <= 0);
						newValueString = cardTypeIntToString(accountType1);
						saveTemporaly<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<accountTypeStr<<" "<<cardNumber<<" "<<newValueString<<endl;
						otherOption = 6;
					}
					break;
					case 6:
						cout<<"Saliendo..."<<endl;
						break;
					default:
						cout<<"option no disponible"<<endl;
						break;
				}
			}while(otherOption != 6);
		}else if(financialCode != TMPInt){
			saveTemporaly<<financialCode<<" "<<codePerson<<" "<<bankName<<" "<<accountNumber<<" "<<accountTypeStr<<" "<<cardNumber<<" "<<cardTypeStr<<endl;
		}
		TMPInt = financialCode;
	}
	searchData.close();
	saveTemporaly.close();
	remove("Informacion-Financiera.txt");
	rename("temporal.txt", "Informacion-Financiera.txt");
}

void dataModifyProcedureFromVirtualAccounts(){
	int codeSelected, otherOption, TMPInt = 0;
	string newValueString;
	ifstream searchData("Cuentas-Virtuales.txt");
	ofstream saveTemporaly("temporal.txt");
	system("cls");
	cout<<"------ Modificar informacion -------"<<endl;
    cout<<"----------------------------------"<<endl;
	cout<<"Ingrese codigo de registro a modificar: "<<endl;
	cin>>codeSelected;
	while (searchData != NULL){
		searchData>>virtualCodeAccount>>codePerson>>financialCode>>user>>password;
		if (virtualCodeAccount == codeSelected && financialCode != TMPInt) {
			do{
				cout<<"Coincidencia de busqueda con el codigo: "<<financialCode<<endl;
				cout<<"1. Usuario: "<<user<<endl;
				cout<<"2. Contrasena: "<<password<<endl;
				cout<<"Que dato desea modificar? "<<endl;
				cin>>otherOption;
				switch (otherOption){
					case 1:{
						cout<<"Ingrese nuevo nombre de banco: "<<endl;
						cin>>newValueString;
						saveTemporaly<<virtualCodeAccount<<" "<<codePerson<<" "<<financialCode<<" "<<newValueString<<" "<<password<<endl;
						otherOption = 3;
					}
					break;
					case 2:{
						cout<<"Ingrese nuevo numero de cuenta: "<<endl;
						cin>>newValueString;
						saveTemporaly<<virtualCodeAccount<<" "<<codePerson<<" "<<financialCode<<" "<<user<<" "<<newValueString<<endl;
						otherOption = 3;
					}
					break;
					case 3:
						cout<<"Saliendo..."<<endl;
						break;
					default:
						cout<<"option no disponible"<<endl;
						break;
				}
			}while(otherOption != 3);
		}else if(virtualCodeAccount != TMPInt){
			saveTemporaly<<virtualCodeAccount<<" "<<codePerson<<" "<<financialCode<<" "<<user<<" "<<password<<endl;
		}
		TMPInt = virtualCodeAccount;
	}
	searchData.close();
	saveTemporaly.close();
	remove("Cuentas-Virtuales.txt");
	rename("temporal.txt", "Cuentas-Virtuales.txt");
}

void dataModifyProcedure(){
	do{
		system("cls");
		cout<<"------ Modificar informacion -------"<<endl;
        cout<<"----------------------------------"<<endl;
		cout<<"1. Datos personales"<<endl;
		cout<<"2. Datos financieros"<<endl;
		cout<<"3. Datos de cuentas virtuales"<<endl;
		cout<<"4. Salir"<<endl;
        cout<<"--------------------------------"<<endl;
		cin>>optionMenu;
		switch (optionMenu) {
			case 1:{
				dataModifyProcedureFromPersonalData();
			}
			break;
			case 2:{
				dataModifyProcedureFromFinancialData();
			}
			break;
			case 3:{
				dataModifyProcedureFromVirtualAccounts();
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
				dataDisplayProcedure();
				break;
			case 3:
				dataModifyProcedure();
				break;
			case 4:
				cout<<endl<<"Gracias por utilizar nuestro servicio de informacion."<<endl;
                cout<<"Estudiantes: \n\tJulio Estuardo Teleguario Canu --- 1990 - 20 - 4006\n\tEdson Oseas Nimajuan Soloman ----- 1990 - 20 - 4003\n\tEliu Rosales Santos ------------- 1990 - 20 - 11745";
				break;
			default:
				cout<<endl<<"Opcion no valida, por favor ingrese otra"<<endl;
				system("pause");
				break;
		}
	} while (option != 4);
}
