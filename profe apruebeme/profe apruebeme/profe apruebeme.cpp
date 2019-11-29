#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <clocale>

using namespace std;

struct regist {
	int leg = 0;
	char nom[20] = "";
	char ape[40] = "";
	char dni[10] = "";
	struct regist* sig = NULL;// apunta al nodo siguiente
	struct regist* ant = NULL;// apunta al nodo anterior
	int tur = 0;
};

typedef struct regist* node;

string namedat = "databin.bin";
string nametxt = "datatxt.txt";
int program = 0;
const int c = 9999;
node start;

void wait() {
	Sleep(2000);
};
void pause() {
	system("pause");
};
void cls() {
	system("cls");
};
void borrar() {// borra toda la lista
	node z = start;
	node p = z;
	while (z != NULL) {
		delete z;
		z = p;
		if (p != NULL) p->sig;
	}
};
void read(node &dat, int &i) {// lee un archivo binario y lo ingresa en memoria dinamica
	fstream file;// sirve para abrir el archivo
	node p = NULL;// donde voy a guardar lo leido
	node z = NULL;
	file.open(namedat,ios::binary | ios::in) ;
	if (file.fail()) {
		
	}
	else {
		while (file.is_open()) {
			p = new(struct regist);
			//file.read((char *) &p, sizeof(&p));
			while (!file.eof()) {
				file.read(reinterpret_cast<char*>(&p->leg), sizeof(&p->leg));
				file.read(reinterpret_cast<char*>(&p->nom), sizeof(&p->nom));
				file.read(reinterpret_cast<char*>(&p->ape), sizeof(&p->ape));
				file.read(reinterpret_cast<char*>(&p->dni), sizeof(&p->dni));
				file.read(reinterpret_cast<char*>(&p->tur), sizeof(&p->tur));
				cout << p;
				pause();
				if (p->leg != 0) {
					z = p;
					i += p->leg;
					if (start != NULL) {
						dat->sig = z;
						z->ant = dat;
						z->sig = NULL;
					}
					else {
						start = z;
					}
					dat = z;
				}
			}
			file.close();
		}
	}
	
};
void write(node &p) {// escribe el archivo con lo ultimo ingresado
	fstream file;// sirve para abrir el archivo
	file.open(namedat, ios::binary | ios::app | ios::out);
	if (file.is_open()){
		file.write(reinterpret_cast<char*>(&p->leg), sizeof(&p->leg));
		file.write(reinterpret_cast<char*>(&p->nom), sizeof(&p->nom));
		file.write(reinterpret_cast<char*>(&p->ape), sizeof(&p->ape));
		file.write(reinterpret_cast<char*>(&p->dni), sizeof(&p->dni));
		file.write(reinterpret_cast<char*>(&p->tur), sizeof(&p->tur));
	}
	file.close();
};
void mostrar() {// muestra una lista
	node z = start;// cabezal para mostrar la lista
	cls();
	while (z != NULL) {
		cout << "legajo: "<<z->leg << "|_____________________ \n";
		cout << " nombre: ";
		cout << z->nom << "\n";
		cout << " apellido: ";
		cout << z->ape << "\n";
		cout << " dni: ";
		cout << z->dni << "\n";
		switch (z->tur){
		case 1:
			cout << " turno: mañana  \n";
				break;
		case 2:
			cout << " turno: tarde \n";
			break;
		case 3:
			cout << " turno: Noche (the best) \n";
			break;
		}
		z = z->sig;
	}
};
int turno(int &i, node dat) {// permite selecionar el turno del alumno 
	int tur = 0;// guarda la decision del usuario
	do {
		cls();
		cout << i + 1 << "|_____________________ \n";
		cout << "nombre: ";
		cout << dat->nom << "\n";
		cout << "apellido: ";
		cout << dat->ape << "\n";
		cout << "dni: ";
		cout << dat->dni<<"\n";
		cout << "pulse 1 para ingresar turno mañana \n";
		cout << "pulse 2 para ingresar turno tarde \n";
		cout << "pulse 3 para ingresar turno noche (el mejor) \n";
		cin >> tur;
	} while (tur != 1 && tur != 2 && tur != 3);
	return tur;
};
void ingresaral(node &dat, int &i) {// el usuario ingresa un alumno para el programa de archvos binarios
	node z = new(struct regist);
	cout << i + 1 << "|_____________________ \n";
	z->leg = i + 1;
	cout << "nombre: ";
	cin >> z->nom;
	cout << "apellido: ";
	cin >> z->ape;
	cout << "dni: ";
	cin >> z->dni;
	z->tur = turno(i,z);
	write(z);
	if (start==NULL) {
		start = z;// si es el primer nodo
		z->sig = NULL;
	}
	else {
		dat->sig = z;
		z->ant = dat;
		z->sig = NULL;
	}
	dat = z;
	i += 1;
};
void control1a() {// programa 1 de archivos de texto

};
void control1b() {// programa 1 de archivos binarios 
	int valor = 0;// valor del ultimo nodo ingresado o del que se esta ingresando
	int i = 0;// contador de alumnos ingresados
	int q = 0;// decision del usuario
	node dat;
	read(dat,i);// lee lo que hay dentro del archivo 
	while (q != 3) {
		cout << " Programa: " << "1 y 2 " << "\n";
		cout << " pulse 1 para ingresar un nuevo alumno \n";
		cout << " pulse 2 para ver los alumnos ingresados \n";
		cout << " pulse 3 para salir \n";
		cin >> q;
		system("cls");
		switch (q) {
		case 1:
			ingresaral(dat, i);
			system("cls");
			break;
		case 2:
			mostrar();
			pause();
			system("cls");
			break;
		case 3:
			break;
		default:
			cout << "ingrese un numero valido \n";
			system("pause");
			break;
		}
	}
};
void control3b() { //programa 3 de archivos binarios

};
void control4b() {// programa 4 de archivos binarios

};
void archbin() {// menu de los programas de archivos binarios
	bool tru = true;
	while (tru) {
		start = NULL;
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
void archtxt() {
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
			break;
		case 2:
			program = 2;
			pause();
			cls();

			break;
		case 3:
			program = 3;
			pause();
			cls();

			break;
		case 4:
			tru = false;
			pause();
			cls();
			break;
		default:
			cls();
			cout << "ingrese un valor valido";
			pause();
			break;
		}
	}
};
void selection() {// menu para seleccionar entre archivos binarios y de texto
	int selecction=0;
	while (selecction != 3) {
		cls();
		cout << "pulse 1 para entrar a los programas de archivos de texto \n";
		cout << "pulse 2 para entrar a los programas de archivos binarios \n";
		cout << "pulse 3 para salir \n";
		cin >> selecction;
		switch (selecction)
		{
		case 1:
			cls();
			archtxt();
			break;
		case 2:
			cls();
			archbin();
			break;
		default:
			break;
		}
	}
};
int main() {
	setlocale(LC_CTYPE, "Spanish");// cambia el formato del texto a español
	selection();
};
