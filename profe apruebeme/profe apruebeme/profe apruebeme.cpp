#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <clocale>

using namespace std;

string namedat = "databin.dat";
string nametxt = "datatxt.txt";
int program = 0;
const int c = 9999;

struct regist {
	int leg = 0;
	char nom[20];
	char ape[40];
	char dni[10];
	string tur;
};

void wait() {
	Sleep(2000);
};
void pause() {
	system("pause");
};
void cls() {
	system("cls");
};
void read(struct regist dat[], int& i) {// lee un archivo binario y lo ingr
	fstream file;
	file.open(namedat, ios::out | ios::binary);
	if (file.fail()) cout << "hubo un error de lectura del archivo \n";
	else {
		while (!file.eof()) {
			file.read(reinterpret_cast<char*>(&dat[i]), sizeof(regist));
			i += 1;
		}
	}
};
void write(struct regist dat[],int i) {// escribe el archivo con lo ultimo ingresado
	fstream file;
	file.open(namedat, ios::in | ios::binary | ios::ate);
	if (file.fail()) cout << "hubo un error al abrir el archivo \n";
	else {
			file.write(reinterpret_cast<char*>(&dat[i]), sizeof(regist));
	}
};
void mostrar(struct regist  dat[]) {// muestra un vector
	int i = 0;
	system("cls");
	cout << " nº" << "    |    " << "nombre    " << " \n";
	while (dat->leg != 0) {
		cout << " " << i + 1 << "    |    " << dat->nom << "\n";
	}
};
string turno( int i, struct regist dat[]) {// permite selecionar el turno del alumno 
	int tur = 0;
	do {
		cls();
		cout << i << "_____________________";
		cout << "nombre: ";
		cout << dat[i].nom << "\n";
		cout << "apellido: ";
		cout << dat[i].ape << "\n";
		cout << "dni: ";
		cout << dat[i].dni<<"\n";
		cout << "pulse 1 para ingresar turno maniana \n";
		cout << "pulse 2 para ingresar turno tarde \n";
		cout << "pulse 3 para ingresar turno noche (el mejor) \n";
		cin >> tur;
	} while (tur != 1 && tur != 2 && tur != 3);
	switch (tur){
	case 1:
		return "mañana";
		break;
	case 2:
		return "tarde";
		break;
	case 3: 
		return "noche";
		break;
	}

};
void ingresaral(struct regist dat[], int& i) {// el usuario ingresa un alumno para el programa de archvos binarios
	int tur = 0;
	cout << i << "_____________________";
	dat[i].leg = i + 1;
	cout << "nombre: ";
	cin >> dat[i].nom;
	cout << "apellido: ";
	cin >> dat[i].ape;
	cout << "dni: ";
	cin >> dat[i].dni;
	dat[i].tur = turno(i,dat);
	write(dat,i);
	i += 1;

};
void control1b() {// programa 1 de archivos binarios 
	regist dat[c];
	int i = 0;// contador de alumnos ingresados
	read(dat, i);
	int w = 0;// decision del usuario
	int valor = 0;// valor del ultimo nodo ingresado o del que se esta ingresando
	while (w != 3) {
		cout << " Programa: " << "1 y 2 " << "\n";
		cout << " pulse 1 para ingresar un nuevo alumno \n";
		cout << " pulse 2 para ver los alumnos ingresados \n";
		cout << " pulse 3 para salir \n";
		cin >> w;
		system("cls");
		switch (w) {
		case 1:
			ingresaral(dat, i);
			system("cls");
			break;
		case 2:
			system("pause");
			system("cls");
			break;
		case 3:
			wait();
			break;
		default:
			cout << "ingrese un numero valido \n";
			system("pause");
			break;
		}
	}
};
void control2b() {

};
void control3b() {

};
void archbin() {// 
	bool tru = true;
	while (tru) {
		system("cls");
		cout << " pulse 1 para ingresar al programa 1 \n";
		cout << " pulse 2 para ingresar al programa 2 \n";
		cout << " pulse 3 para ingresar al programa 3 \n";
		cout << " pulse 4 para salir \n";
		cin >> program;
		cls();
		switch (program) {
		case 1:
			program = 1;
			pause();
			cls();
			control1b();
			break;
		case 2:
			program = 2;
			pause();
			cls();
			control2b();
			break;
		case 3:
			program = 3;
			pause();
			cls();
			control3b();
			break;
		case 4:
			tru = false;
			pause();
			cls();
			break;
		default:
			cls();
			cout << "ingrese un numero valido";
			pause();
			break;
		}
	}
};
void selection() {// menu para seleccionar entre archivos binarios y de texto
	cls();

	cout << "pulse 1 para entrar a los programas de archivos de texto \n";
	cout << "pulse 2 para entrar a los programas de archivos binarios \n";
};
int main() {
	setlocale(LC_CTYPE, "Spanish");// cambia el formato del texto a español
	cout << " puto el que lee" << "\n";
	cout << " que haces viendo mi codigo? " << "\n";
	selection();

};
