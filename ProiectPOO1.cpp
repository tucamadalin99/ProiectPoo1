#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Desktop {
private:
	const int TVA;
	static int nrComputere;
	char* marca;
	float memPartitie[20];
	string marcaPlVideo;
	int vRam;
	int memRam;
	int nrPartitii;
	float pret;


public:
	//Constructor default
	Desktop() :TVA(24) {

		this->marca = NULL;
		for (int i = 0; i < 5; i++) {
			this->memPartitie[i] = 200;
		}
		this->marcaPlVideo = "";
		this->vRam = 0;
		this->memRam = 0;
		this->nrPartitii = 0;
		this->pret = 0;
		this->nrComputere++;
		//cout << "Test constructor default" << endl;
	}

	//Constructor cu un singur param
	Desktop(const char* marca) :TVA(24) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		for (int i = 0; i < 5; i++) {
			this->memPartitie[i] = 200;
		}
		this->marcaPlVideo = "";
		this->vRam = 0;
		this->memRam = 0;
		this->nrPartitii = 0;
		this->pret = 0;
		this->nrComputere++;
		//cout << "Test constructor cu un param" << endl;
	}

	//Constructor cu parametrii
	Desktop(const char* marca, float memPartitie[20], string marcaPlVideo, int vRam, int memRam, int nrPartitii, float pret) :TVA(24) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		for (int i = 0; i < nrPartitii; i++) {
			this->memPartitie[i] = memPartitie[i];
		}
		this->marcaPlVideo = marcaPlVideo;
		this->vRam = vRam;
		this->memRam = memRam;
		this->nrPartitii = nrPartitii;
		this->pret = pret;
		this->nrComputere++;
		//cout << "Test constructor cu param" << endl;
	}

	//Constructor copiere
	//Primeste ca parametru un obiect pe care il vei pune in main si ii va copia valorile intr-un obiect nou instantiat
	Desktop(const Desktop& desktop) :TVA(24) {
		this->marca = new char[strlen(desktop.marca) + 1];
		strcpy(this->marca, desktop.marca);
		for (int i = 0; i < 5; i++) {
			this->memPartitie[i] = desktop.memPartitie[i];
		}
		this->marcaPlVideo = desktop.marcaPlVideo;
		this->vRam = desktop.vRam;
		this->memRam = desktop.memRam;
		this->nrPartitii = desktop.nrPartitii;
		this->pret = desktop.pret;
		this->nrComputere++;
		//cout << "Test constructor copiere" << endl;
	}

	//Functie de afisare
	void afisare() {
		printf("Marca este: %s\n", this->marca);
		cout << "Hard diskul are: " << this->nrPartitii << " partitii" << endl;
		for (int i = 0; i < nrPartitii; i++)
			cout << "Partitia " << i+1 << " contine: " << this->memPartitie[i] << "GB" << endl;
		cout <<"Marca placii video este: " << this->marcaPlVideo << endl;
		cout <<"Placa video are memoria de: " << this->vRam << " GB" << endl;
		cout <<"Desktopul are memoria RAM de: " << this->memRam <<" GB" << endl;
		cout <<"Pretul este de: " << this->pret << " lei" << endl;
		cout <<"Numarul de desktopuri instantiate = " << this->nrComputere << endl;
		cout << "TVA-ul asupra pretului este: " << this->TVA << " %" << endl;
	}


	//Sectiune getteri setteri

	char* getMarca() {
		return this->marca;
	}

	void setMarca(const char* marca) {
		if (marca == "")
			cout << "Nu ati introdus marca " << endl;
		else {
			this->marca = new char[strlen(marca) + 1];
			strcpy(this->marca, marca);
		}
	}
	//Destructoru pulii mele. Asta pui in el ceva decat daca ai variabila de tip pointer cum e in cazu meu char* marca
	//Daca n-ai niciun pointer il declari nu scri nmc in el si il lasi asa.
	~Desktop() {
		if (this->marca != NULL)
			delete[]this->marca;
		//cout << "Test destructor" << endl;
	}
};
//Initializare variabila statica, in afara clasei trebuie.
int Desktop::nrComputere = 0;

class Laptop {
	const int TVA;
	static int nrLaptopuri;
	char* marca;
	float memPartitie[20];
	float dimensiune;
	float greutate;
	float pret;
	string tipPlacaVideo;
};

class Componente {
	const int generatie;
	static int contor;
	string nume;
	char* tip;
	int vitezaCooler[20];

};

int main() {
	//Instantiere obiect cu constructor default(Nu il apelezi ca pe o functie p-asta doar declari obiectu si se apeleaza el singur)
	Desktop d1;
	//d1.afisare();
	//Apel constructor cu un param
	Desktop d2("Asus");
	//Apel constructor de copiere. Din cate vezi, ii dai lu d3 toate atributele lui d2. Practic copiezi obiectu d2 in d3
	Desktop d3 = d2;
	//d2.afisare();
	float memPartitie[] = { 300, 200, 240, 140 };
	//Apel constructor cu toti param
	Desktop d4("Lenovo" , memPartitie, "Nvidia", 16, 3, 4, 2400);
	//Apel functie de afisare a obiectului

	//De aici poti sa ignori ca doar m-am flexat aiurea.
	d4.afisare();
	char* marca = new char[10];
	int memRam, vRam, nrPartitii;
	float pret;
	string marcaPlVideo;
	cout << "Creere obiect..." << endl;
	cout << "Marca: " << endl;
	cin >> marca;
	cout << "Numar partitii harddisk: " << endl;
	cin >> nrPartitii;
	cout << "Alocare memorie hard: " << endl;
	for (int i = 0; i < nrPartitii; i++) {
		cout << "Partitia " << i + 1 << ": " << endl;
		cin >> memPartitie[i];
	}
	cout << "Marca placa video: " << endl;
	cin >> marcaPlVideo;
	cout << "Memorie video: " << endl;
	cin >> vRam;
	cout << "Memorie RAM: " << endl;
	cin >> memRam;
	cout << "Pret: " << endl;
	cin >> pret;
	Desktop d5(marca, memPartitie, marcaPlVideo, vRam, memRam, nrPartitii, pret);
	cout << "----------------------" << endl;
	cout << "Obiectul a fost creat!" << endl;
	cout << "----------------------" << endl;
	d5.afisare();



	 
	//d4.afisare();

}