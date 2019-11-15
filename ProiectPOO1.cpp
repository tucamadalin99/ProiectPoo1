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
	Desktop(const Desktop& desktop) :TVA(24) {
		this->marca = new char[strlen(desktop.marca) + 1];
		strcpy(this->marca, desktop.marca);
		for (int i = 0; i < 5; i++) {
			this->memPartitie[i] = desktop.memPartitie[i];
		}
		this->hdd = desktop.hdd;
		this->marcaPlVideo = desktop.marcaPlVideo;
		this->vRam = desktop.vRam;
		this->memRam = desktop.memRam;
		this->nrPartitii = desktop.nrPartitii;
		this->pret = desktop.pret;
		this->nrComputere++;
		//cout << "Test constructor copiere" << endl;
	}

	//Supraincarcare =
	Desktop& operator=(const Desktop& desktop) {
		this->marca = new char[strlen(desktop.marca) + 1];
		this->hdd = desktop.hdd;
		this->memPartitie[this->nrPartitii] = desktop.memPartitie[this->nrPartitii];
		this->marcaPlVideo = desktop.marcaPlVideo;
		this->vRam = desktop.vRam;
		this->memRam = desktop.memRam;
		this->nrPartitii = desktop.nrPartitii;
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
		cin >> desktop.pret;

		return in;
	}

	//Supraincarcare operator[] indexare
	float& operator[](int index) {
		if (index < 0 || index > this->nrPartitii) {
			cout << "Indexul se afla in afara limitelor!" << endl;
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
		cout << "Second exception caght" << endl;
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
	v
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
	Desktop d3 = d5;
	d3.afisare();
	//d4.afisare();

}