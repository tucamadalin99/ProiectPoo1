#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>

using namespace std;

class Desktop {
private:
	const float TVA;
	static int nrComputere;
	char* marca;
	float hdd;
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
		this->hdd = 0;
		this->memPartitie[this->nrPartitii] = memPartitie[this->nrPartitii];
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
	Desktop(const char* marca, int hdd, float memPartitie[20], string marcaPlVideo, int vRam, int memRam, int nrPartitii, float pret) :TVA(24) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->hdd = hdd;
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
	Desktop(const Desktop& desktop) :TVA(24) {
		this->marca = new char[strlen(desktop.marca) + 1];
		strcpy(this->marca, desktop.marca);
		this->nrPartitii = desktop.nrPartitii;
		for (int i = 0; i < desktop.nrPartitii; i++) {
			this->memPartitie[i] = desktop.memPartitie[i];
		}
		this->hdd = desktop.hdd;
		this->marcaPlVideo = desktop.marcaPlVideo;
		this->vRam = desktop.vRam;
		this->memRam = desktop.memRam;
		this->pret = desktop.pret;
		this->nrComputere++;
		//cout << "Test constructor copiere" << endl;
	}

	//Supraincarcare =
	Desktop& operator=(const Desktop& desktop) {
		this->marca = new char[strlen(desktop.marca) + 1];
		strcpy(this->marca, desktop.marca);
		this->hdd = desktop.hdd;
		this->nrPartitii = desktop.nrPartitii;
		for (int i = 0; i < desktop.nrPartitii; i++) {
			this->memPartitie[i] = desktop.memPartitie[i];
		}
		this->marcaPlVideo = desktop.marcaPlVideo;
		this->vRam = desktop.vRam;
		this->memRam = desktop.memRam;
		this->pret = desktop.pret;
		return *this;
	}

	//Supraincarare <<


	friend ostream& operator<<(ostream& out, Desktop& desktop) {
		out << "Marca: " << desktop.marca << endl;
		out << "Harddisk: " << desktop.hdd << endl;
		for (int i = 0; i < desktop.nrPartitii; i++)
			out << "Partitie " << i << ": " << desktop.memPartitie[i] << endl;
		out << "Placa video: " << desktop.marcaPlVideo << endl;
		out << "Memorie Video: " << desktop.memRam << endl;
		out << "Memorie RAM: " << desktop.memRam << endl;
		out << "Numar partitii: " << desktop.nrPartitii << endl;
		out << "Pret: " << desktop.pret << endl;
		return out;

	}

	//Supraincarcare >>

	friend istream& operator>>(istream& in, Desktop& desktop) {
		if (desktop.marca != NULL) {
			delete[] desktop.marca;
		}
		desktop.marca = new char[1024];
		cout << "Marca: " << endl;
		in >> desktop.marca;
		cout << "HardDisk: " << endl;
		in >> desktop.hdd;
		cout << "Numar partiti: " << endl;
		in >> desktop.nrPartitii;
		for (int i = 0; i < desktop.nrPartitii; i++) {
			cout << "Partitie " << i << " :" << endl;
			in >> desktop.memPartitie[i];
		}
		cout << "Placa video: " << endl;
		in >> desktop.marcaPlVideo;
		cout << "Memorie Video: " << endl;
		in >> desktop.memRam;
		cout << "Pret: " << endl;
		in >> desktop.pret;

		return in;
	}

	//Supraincarcare operator[] indexare
	float& operator[](int index) {
		if (index < 0 || index > this->nrPartitii) {
			cout << "Usor coae ca ai intrecut limita!" << endl;
			throw new exception("Exception caught");
		}
		else {
			return this->memPartitie[index];
		}
	}

	//Supraincarcare == 

	bool operator ==(Desktop desktop) {
		if (this->marca == desktop.marca && this->pret == desktop.pret) {
			return true;
		}
		else
			return false;
	}

	Desktop operator+(int nr) {
		Desktop copie = *this;
		copie.memRam += nr;
		return copie;
	}

	Desktop operator-(int nr) {
		Desktop copie = *this;
		copie.memRam -= nr;
		return copie;
	}

	Desktop operator++() {
		float memPartitiiNou[20];
		for (int i = 0; i < this->nrPartitii; i++) {
			memPartitiiNou[i] = this->memPartitie[i];
		}
		memPartitiiNou[this->nrPartitii] = 30;
		this->nrPartitii++;

		this->memPartitie[20] = memPartitie[20];

		return *this;
	}
	//Postfixat
	Desktop& operator++(int) {
		Desktop copie = *this;
		float memPartitiiNoi[20];
		for (int i = 0; i < this->nrPartitii; i++) {
			memPartitiiNoi[i] = this->memPartitie[i];
		}

		this->memPartitie[20] = memPartitie[20];
		this->nrPartitii++;
		return copie;
	}
	// Explicit 
	explicit operator float() {
		return this->pret;
	}
	
	//Operator !
	bool operator!() {
		if (this->marca != NULL)
			return false;
		else
			return true;
	}

	//Operator >=

	bool operator<=(Desktop d) {
		if (this->pret == d.pret)
			return true;
		else
			return false;
	}

	//Functie de afisare
	void afisare() {
		printf("Marca este: %s\n", this->marca);
		cout << "Hard diskul are: " << this->nrPartitii << " partitii" << endl;
		for (int i = 0; i < nrPartitii; i++)
			cout << "Partitia " << i + 1 << " contine: " << this->memPartitie[i] << "GB" << endl;
		cout << "Marca placii video este: " << this->marcaPlVideo << endl;
		cout << "Placa video are memoria de: " << this->vRam << " GB" << endl;
		cout << "Desktopul are memoria RAM de: " << this->memRam << " GB" << endl;
		cout << "Pretul este de: " << this->pret << " lei" << endl;
		cout << "Numarul de desktopuri instantiate = " << this->nrComputere << endl;
		cout << "TVA-ul asupra pretului este: " << this->TVA << " %" << endl;
	}


	//Functie verificare valoare numerica
	bool isNumeric(const char* s) {
		for (int i = 0; i < strlen(s); i++)
			if (isdigit(s[i]) == false)
				return false;
		return true;
	}

	//Sectiune getteri setteri

	char* getMarca() {
		return this->marca;
	}

	void setMarca(const char* marca) {
		while (isNumeric(marca)) {
			cout << "Nu puteti folosi valori numerice pentru marca!" << endl;
			cout << "Introduceti din nou marca: " << endl;
			scanf("%s", marca);
		}
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

	}

	void setHdd(float hdd) {
		while (hdd < 150) {
			cout << "Nu exista harddisk cu mai putin de 150 GB! " << endl << "Introdu din nou capacitate: ";
			cin >> hdd;
		}
		this->hdd = hdd;
	}

	float getHdd() {
		return this->hdd;
	}

	void setNrPartitii(int nrPartitii) {
		while (nrPartitii >= 10 || nrPartitii < 1) {
			cout << "Numarul de partitii poate fi intre 1-10" << endl << "Numar partitii: " << endl;
			cin >> nrPartitii;
		}
		this->nrPartitii = nrPartitii;
	}
	//Cel mai nenecesar flex aiurea
	void setMemPartitie(float memPartitie[]) {
		float auxHdd;
		auxHdd = this->hdd;
		bool ok = false;
		for (int i = 0; i < this->nrPartitii; i++) {
			this->hdd = this->hdd - memPartitie[i];
			this->memPartitie[i] = memPartitie[i];
		}
		if (this->hdd < 0) {
			this->hdd = auxHdd;
			cout << "Ati epuizat memoria harddiskului!" << endl;
			cout << "Aloca din nou memorie: " << endl;

			int i = 0;
			do {
				if (i < this->nrPartitii && auxHdd >= 0) {
					printf("Partitie %d: ", i + 1);
					cin >> memPartitie[i];
					auxHdd = auxHdd - memPartitie[i];
					this->memPartitie[i] = memPartitie[i];
					i++;
					ok = true;
				}
				if (i == this->nrPartitii && auxHdd < 0) {
					cout << "Memorie HDD epuizata, introduceti din nou: " << endl;
					i = 0;
					auxHdd = this->hdd;
					ok = true;
				}
				if (i == this->nrPartitii && auxHdd >= 0) {
					ok = false;
				}
			} while (ok);
		}
	}

	float* getMemPartitie() {
		return this->memPartitie;
	}

	void setPlacaVideo(string marcaPlVideo) {
		if (marcaPlVideo == "Nvidia")
			this->marcaPlVideo = marcaPlVideo;
		if (marcaPlVideo == "Radeon")
			this->marcaPlVideo = marcaPlVideo;
		else
			cout << "Nu exista alt tip de placa video!" << endl;
	}

	string getPlacaVideo() {
		return this->marcaPlVideo;
	}

	void setVRam(int vRam) {
		while (vRam < 1) {
			cout << "Memorie prea mica, try again: " << endl;
			cin >> vRam;
		}
		this->vRam = vRam;
	}

	int getVRam() {
		return this->vRam;
	}

	void setRam(int memRam) {
		while (vRam < 1) {
			cout << "Memorie RAM prea mica, try again: " << endl;
			cin >> memRam;
		}
		this->memRam = memRam;
	}

	int getRam() {
		return this->memRam;
	}

	void setPret(float pret) {
		this->pret = pret;
		if (this->memRam > 8 && this->memRam <= 16)
			this->pret += pret / 2;
		if (this->hdd > 500)
			this->pret += pret / 3;
		if (this->vRam > 2)
			this->pret += pret / 2;
		//Aplicare TVA
		float valTva = (this->TVA / 100) * pret;
		this->pret = this->pret + valTva;
	}

	float getPret() {
		return this->pret;
	}

	~Desktop() {
		if (this->marca != NULL)
			delete[]this->marca;
		//cout << "Test destructor" << endl;
	}
};
//Initializare variabila statica
int Desktop::nrComputere = 0;

class Laptop {
private:
	const int TVA;
	static int nrLaptopuri;
	char* marca;
	int nrDim;
	float dimensiuni[10];
	float greutate;
	float pret;
	string tipPlacaVideo;

public:
	Laptop() :TVA(24) {
		this->marca = NULL;
		this->nrDim = 0;
		for (int i = 0; i < this->nrDim; i++) {
			this->dimensiuni[i] = 0;
		}
		this->greutate = 0;
		this->pret = 0;
		this->tipPlacaVideo = "Default";
		this->nrLaptopuri++;
		cout << "Constructor default apelat" << endl;
	}

	Laptop(const char* marca) :TVA(24) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->nrDim = 0;
		for (int i = 0; i < 3; i++) {
			this->dimensiuni[i] = 0;
		}
		this->greutate = 0;
		this->pret = 0;
		this->tipPlacaVideo = "Default";
		this->nrLaptopuri++;
		cout << "Constructor cu un param apelat" << endl;
	}

	Laptop(const char* marca,int nrDim, float dimensiuni[], float greutate, float pret, string tipPlacaVideo) :TVA(24) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->nrDim = nrDim;
		for (int i = 0; i < this->nrDim; i++) {
			this->dimensiuni[i] = dimensiuni[i];
		}
		this->greutate = greutate;
		this->pret = pret;
		this->tipPlacaVideo = tipPlacaVideo;
		this->nrLaptopuri++;
		cout << "Constructor cu toti param apelat" << endl;
	}

	//Constructor copiere
	Laptop(const Laptop& l) :TVA(24) {
		//this->marca = new char[strlen(l.marca) + 1];
		//strcpy(this->marca, l.marca);
		this->nrDim = l.nrDim;
		for (int i = 0; i < this->nrDim; i++) {
			this->dimensiuni[i] = l.dimensiuni[i];
		}
		this->greutate = l.greutate;
		this->pret = l.pret;
		this->tipPlacaVideo = l.tipPlacaVideo;
		this->nrLaptopuri++;
		cout << "S-a supt informatia prin constructoru de copiere" << endl;
	}

	//Supraincarcare operator = 
	Laptop& operator=(const Laptop& l) {
		this->marca = new char[strlen(l.marca) + 1];
		strcpy(this->marca, l.marca);
		this->nrDim = l.nrDim;
		for (int i = 0; i < this->nrDim; i++)
			this->dimensiuni[i] = l.dimensiuni[i];
		this->greutate = l.greutate;
		this->pret = l.pret;
		this->tipPlacaVideo = l.tipPlacaVideo;
		cout << "Atribuit cu operator egal!" << endl;
		return *this;
	}

	friend ostream& operator <<(ostream& out, Laptop& l) {
		out << "Marca laptopului este: " << l.marca << endl;
		cout << "Nr. de dimensiuni este: " << l.nrDim << endl;
		out << "Dimensiuni: ";
		for (int i = 0; i < l.nrDim; i++) {
			if (i == 2) {
				out << l.dimensiuni[i];
				break;
			}
			out << l.dimensiuni[i] << " X ";
		}
		out << endl;
		out << "Greutate: " << l.greutate << endl;
		out << "Pret: " << l.pret << endl;
		out << "Tip placa video: " << l.tipPlacaVideo << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Laptop& l) {
		cout << "Introduceti marca laptop: " << endl;
		if (l.marca != NULL)
			delete[] l.marca;
		l.marca = new char[1024];
		in >> l.marca;
		cout << "Introdu dimensiuni: " << endl;
		for (int i = 0; i < 3; i++) {
			in >> l.dimensiuni[i];
		}
		cout << "Introduceti greutate(in kg): " << endl;
		in >> l.greutate;
		cout << "Introduceti pret: " << endl;
		in >> l.pret;
		cout << "Introduceti tip placa video(integrata/dedicata): " << endl;
		in >> l.tipPlacaVideo;
		return in;
	}

	float& operator[](int index) {
		if (index < 0 || index > 3) {
			cout << "Index in afara limitelor!" << endl;
			throw new exception("Exceptie!");
		}
		else
			return this->dimensiuni[index];
	}

	bool operator==(Laptop l) {
		if (this->marca == l.marca && this->pret == l.pret)
			return true;
		else
			return false;
	}

	Laptop operator+(int nr) {
		Laptop copie = *this;
		copie.greutate += nr;
		return copie;
	}

	Laptop operator-(int nr) {
		Laptop copie = *this;
		copie.greutate -= nr;
		return copie;
	}

	Laptop& operator++(int) {
		Laptop copie = *this;
		float dimNoi[10];
		for (int i = 0; i < this->nrDim; i++) {
			dimNoi[i] = this->dimensiuni[i];
		}

		this->dimensiuni[10] = dimNoi[10];
		this->nrDim++;
		cout << this->nrDim;
		return copie;
	}
	
};

int Laptop::nrLaptopuri = 0;
class Componente {
	const int generatie;
	static int contor;
	string nume;
	char* tip;
	int vitezaCooler[20];

};

int main() {
	
	Laptop l1;
	Laptop l2("Lenovo");
	float dimensiuni[] = { 50, 40, 20 };
	Laptop l3("Asus", 3, dimensiuni, 2, 4000, "Dedicata");
	Laptop l4 = l3;
	l2 = l3;
	cin >> l3;
	cout << l3;
	cout << "Prima pozitie: " << l3[0] << endl;
	try {
		cout << "Test indexare: " << l3[2] << endl;
	}
	catch (exception* e) {
		cout << "Prima exceptie prinsa" << endl;
	}
	catch (...) {
		cout << "A doua exceptie prinsa" << endl;
	}
	if (l1 == l2) {
		cout << "Au aceleasi atribute" << endl;
	}
	else {
		cout << "Nu sunt egale!" << endl;
	}

	l1++;

	
	float memPartitie[] = { 200, 300, 100 };
	Desktop d4("Lenovo", 600, memPartitie, "Nvidia", 8, 16, 3, 2500 );
	cout << d4;
	d4++;
	cout << d4;
	++d4;
	cout << d4;
	
	/*
	Desktop d1;
	cin >> d1;
	cout << d1;

	//Apel supraincarcare[]
	cout << endl << endl;
	cout << "Partitia de pe prima pozitie este: " << d1[0];
	try {
		cout << d1[10] << endl;
	}
	catch (exception* e) {
		cout << "First exception caught" << endl;
	}
	catch (...) {
		cout << "Second exception caught" << endl;
	}
	//d1.afisare();
	//Apel constructor cu un param
	Desktop d2("Asus");
	float memPartitie[50];
	//Apel constructor cu toti param
	Desktop d4("Lenovo", memPartitie, "Nvidia", 16, 3, 4, 2400);
	//Apel functie de afisare a obiectului
	//d4.afisare();
	char* marca = new char[10];
	int memRam, vRam, nrPartitii;
	float pret;
	string marcaPlVideo;
	float hdd;

		cout << "Creere obiect..." << endl;
	cout << "Marca: " << endl;
	cin >> marca;
	d1.setMarca(marca);
	cout << "----->Configurare Desktop: " << endl;
	cout << "Capacitate Harddisk GB: ";
	cin >> hdd;
	d1.setHdd(hdd);
	cout << "Numar partitii harddisk: " << endl;
	cin >> nrPartitii;
	d1.setNrPartitii(nrPartitii);
	cout << "Alocare memorie hard: " << endl;
	for (int i = 0; i < nrPartitii; i++) {
		cout << "Partitia " << i + 1 << ": " << endl;
		cin >> memPartitie[i];
	}
	cout << "Se aloca memorie" << endl;
	cout << "Va rugam asteptati";
	for (int i = 0; i < 4; i++) {
		Sleep(1000);
		cout << ". ";
	}
	d1.setMemPartitie(memPartitie);
	cout << endl << "Memorie HDD alocata!" << endl;
	//d1.afisare();
	cout << "Marca placa video: " << endl;
	cin >> marcaPlVideo;
	d1.setPlacaVideo(marcaPlVideo);
	cout << "Memorie video: " << endl;
	cin >> vRam;
	d1.setVRam(vRam);
	cout << "Memorie RAM: " << endl;
	cin >> memRam;
	d1.setRam(memRam);
	cout << "Pret: " << endl;
	cin >> pret;
	d1.setPret(pret);
	cout << "Calculare pret final + TVA..." << endl;
	Sleep(3000);
	cout << d1.getPret() << " LEI" << endl;
	cout << "--------Procesare";
	for (int i = 0; i < 4; i++) {
		Sleep(1000);
		cout << ". ";
	}
	cout << endl << "<---------------------->" << endl;
	cout << " Obiectul a fost creat! " << endl;
	cout << "<---------------------->" << endl << endl;
	d1.afisare();
	Desktop d5(marca, memPartitie, marcaPlVideo, vRam, memRam, nrPartitii, pret);
	//Apel operator supraincarcat =
	d1 = d5;
	cout << endl << endl;
	d1.afisare();
	Desktop d3 = d5;
	d3.afisare();
	//Apel operator +
	d3 = d3 + 5;
	cout << d3.getRam() << endl;
	//Apel operator -
	d3 = d3 - 3;
	cout << d3.getRam() << endl;
	//d4.afisare();
	++d3;
	cout << *d3.getMemPartitie() << endl;
	d3++;
	cout << *d3.getMemPartitie() << endl;
	*/
}