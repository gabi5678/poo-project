#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <list>
using namespace std;


class Restaurant {
private:
	char* numeRestaurant;
	bool program;
public:
	//constructor cu toti parametrii
	Restaurant(const char* numeRestaurant, bool program) {
		if (numeRestaurant != nullptr) {
			this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
			strcpy(this->numeRestaurant, numeRestaurant);
		}
		this->program = program;
	}

	//constructor doar cu un parametru
	Restaurant(const char* numeRestaurant) {
		if (numeRestaurant != nullptr) {
			this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
			strcpy(this->numeRestaurant, numeRestaurant);
		}
		this->program = true;
	}

	//afisare
	void afisare() {
		cout << "\Nume: " << this->numeRestaurant;
		cout << "\nProgram: ";
		if (this->program == true) {
			cout << "DESCHIS";
		}
		else {
			cout << "INCHIS";
			throw exception("Deoarece restaurantul este inchis, nu se poate accesa nimic");
		}
		cout << endl;
	}

	//getnume
	const char* getNumeRestaurant()
	{
		return this->numeRestaurant;
	}

	//setnume
	void setNumeRestaurant(const char* numeRestaurant) {
		if (numeRestaurant != nullptr && strlen(numeRestaurant) >= 2) {
			delete[] this->numeRestaurant;
			this->numeRestaurant = nullptr;
			this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
			strcpy(this->numeRestaurant, numeRestaurant);
		}
	}

	//getprogram
	bool getProgram() {
		return this->program;
	}

	//setprogram
	void setProgram(bool program)
	{
		this->program = program;
	}

	//constructor copy
	Restaurant(const Restaurant& r) {
		if (r.numeRestaurant != nullptr) {
			this->numeRestaurant = new char[strlen(r.numeRestaurant) + 1];
			strcpy(this->numeRestaurant, r.numeRestaurant);
		}
		this->program = r.program;
	}

	//operator de citire
	friend ostream& operator << (ostream& out, const Restaurant& r) {
		out << "\Nume: " << r.numeRestaurant;
		out << "\nProgram: ";
		if (r.program == true) {
			cout << "DESCHIS";
		}
		else {
			cout << "INCHIS";
			throw exception("Deoarece restaurantul este inchis, nu se poate accesa nimic");
		}
		cout << endl;

		return out;
	}

	//operator de scriere
	friend istream& operator >> (istream& in, Restaurant& r) {
		if (r.numeRestaurant != nullptr) {
			delete[] r.numeRestaurant;
			r.numeRestaurant = nullptr;
		}

		cout << "\nIntroduceti denumirea: ";
		char buffer[100];
		in >> buffer;
		r.numeRestaurant = new char[strlen(buffer) + 1];
		strcpy(r.numeRestaurant, buffer);

		cout << "\nIntroduceti programul:";
		in >> r.program;

		return in;
	}

	//operator =
	Restaurant& operator=(Restaurant r) {
		if (this != &r) {
			if (this->numeRestaurant != nullptr) {
				delete[] this->numeRestaurant;
				this->numeRestaurant = nullptr;
			}
			if (r.numeRestaurant != nullptr) {
				this->numeRestaurant = new char[strlen(r.numeRestaurant) + 1];
				strcpy(this->numeRestaurant, r.numeRestaurant);
			}
			this->program = r.program;
		}
		return *this;
	}

	//destructor
	~Restaurant() {
		if (this->numeRestaurant != nullptr) {
			delete[] this->numeRestaurant;
			this->numeRestaurant = nullptr;
		}
	}
};

class Ingrediente {
private:
	char* denumireIngredient;
	int cantitatea;
public:


	Ingrediente* getIngrediente() {
		return this;
	}
	//constructor implicit
	Ingrediente() {
		this->denumireIngredient = nullptr;
		this->cantitatea = 0;
	}

	//constructor cu toti parametrii
	Ingrediente(const char* denumireIngredient, int cantitatea) {
		if (denumireIngredient != nullptr) {
			this->denumireIngredient = new char[strlen(denumireIngredient) + 1];
			strcpy(this->denumireIngredient, denumireIngredient);
		}
		this->cantitatea = cantitatea;
	}

	//constrcutor doar cu un parametru
	Ingrediente(const char* denumireIngredient)
	{
		if (denumireIngredient != nullptr) {
			this->denumireIngredient = new char[strlen(denumireIngredient) + 1];
			strcpy(this->denumireIngredient, denumireIngredient);
		}
		this->cantitatea = 0;
	}

	//afisare
	void afisare() {
		cout << "\n---------------------------------";
		cout << "\nDenumire Ingredient: " << this->denumireIngredient;
		cout << "\nCantitate: ";
		if (this->cantitatea == 0) {
			throw exception("Ingredientul nu mai este");
		}
		else {
			cout << this->cantitatea;
		}
	}

	//getDenumireIngredient
	const char* getDenumireIngredient()
	{
		return this->denumireIngredient;
	}

	//setDenumireIngredient
	void setDenumireIngredient(const char* denumireIngredient) {
		if (denumireIngredient != nullptr && strlen(denumireIngredient) >= 2) {
			delete[] this->denumireIngredient;
			this->denumireIngredient = nullptr;
			this->denumireIngredient = new char[strlen(denumireIngredient) + 1];
			strcpy(this->denumireIngredient, denumireIngredient);
		}
	}

	//getcantitate
	int getCantitate() {
		return this->cantitatea;
	}

	//setcantitate
	void setCantitate(int cantitate)
	{
		this->cantitatea = cantitate;
	}

	//constructor copy
	Ingrediente(const Ingrediente& i) {
		if (i.denumireIngredient != nullptr) {
			this->denumireIngredient = new char[strlen(i.denumireIngredient) + 1];
			strcpy(this->denumireIngredient, i.denumireIngredient);
		}
		this->cantitatea = i.cantitatea;
	}

	//operator =
	Ingrediente& operator = (const Ingrediente& i)
	{
		if (this != &i) {
			if (this->denumireIngredient != nullptr) {
				delete[] this->denumireIngredient;
				this->denumireIngredient = nullptr;
			}
			if (i.denumireIngredient != nullptr) {
				this->denumireIngredient = new char[strlen(i.denumireIngredient) + 1];
				strcpy(this->denumireIngredient, i.denumireIngredient);
			}
			this->cantitatea = i.cantitatea;
		}
		return *this;

	}

	//operator <<
	friend ostream& operator << (ostream& out, const Ingrediente& i)
	{
		out << "\nDenumire Ingredient: " << i.denumireIngredient;
		out << "\nCantitate: ";
		if (i.cantitatea == 0) {
			cout << "Ingredientul nu mai este, deci automat nici produsul nu mai e in stoc";
		}
		else {
			out << i.cantitatea;
		}
		cout << endl;
		return out;
	}

	//operator >>
	friend istream& operator >> (istream& in, Ingrediente& i)
	{
		if (i.denumireIngredient != nullptr) {
			delete[] i.denumireIngredient;
			i.denumireIngredient = nullptr;
		}

		cout << "\nIntroduceti denumirea ingredientului: ";
		char buffer[100];
		in >> buffer;
		i.denumireIngredient = new char[strlen(buffer) + 1];
		strcpy(i.denumireIngredient, buffer);

		cout << "\nIntroduceti cantitatea: ";
		in >> i.cantitatea;

		return in;
	}

	//operatorul --
	Ingrediente& operator--() {
		--cantitatea;
		return *this;
	}

	//friend ofstream& operator<<(ofstream& outf, const Ingrediente& i) {
	//	outf.open("ingrediente.txt", ios::app);

	//	if (outf.is_open()) {
	//		outf << "\nDenumire Ingredient: " << i.denumireIngredient;
	//		outf << "\nCantitate: " << i.cantitatea << endl;
	//		outf.close();
	//	}
	//	else {
	//		cout << "Nu s-a putut deschide raportcomenziul pentru scriere!" << endl;
	//	}

	//	return outf;

	//}
	//friend ifstream& operator>>(ifstream& in, Ingrediente& i) {
	//	cout << "Ingredintul: ";
	//	in >> i.denumireIngredient;
	//	cout << "Cantitatea: ";
	//	in >> i.cantitatea;
	//	return in;
	//}


	void scrieBinar(const char* numeraportcomenziBinar) {
		ofstream binFile(numeraportcomenziBinar, ios::binary | ios::app);

		if (binFile.is_open()) {
			int lungimeDenumire = strlen(this->denumireIngredient);
			binFile.write((char*)&lungimeDenumire, sizeof(int));
			binFile.write(this->denumireIngredient, lungimeDenumire);

			binFile.write((char*)&this->cantitatea, sizeof(int));

			binFile.close();
		}
		else {
			cout << "Nu s-a putut deschide raportcomenziul binar pentru scriere!" << endl;
		}
	}
	void scadeCantitateIngrediente() {
		if (this->cantitatea > 0) {
			(this->cantitatea)--;
		}
	}

	//destructor
	~Ingrediente() {
		if (this->denumireIngredient != nullptr) {
			delete[] this->denumireIngredient;
			this->denumireIngredient = nullptr;
		}
	}
};

class FisierCSV {
private:
	char delimitator;
	int nrIngrediente;

public:
	FisierCSV(const char delimitator) {
		this->delimitator = delimitator;
		this->nrIngrediente = 0;
	}

	int incarcaDate(Ingrediente ingrediente[], const char* numeFisier, int maxIngrediente) {
		ifstream file(numeFisier); //se deschide fisierul in mod citire

		if (!file.is_open()) {
			cout << "Nu s-a putut deschide fisierul: " << numeFisier << endl;
			return nrIngrediente;
		}

		string linie;
		while (getline(file, linie) && nrIngrediente < maxIngrediente) { //se citeste rand cu rand pana cand nu mai sunt, si in variabila linie se salveaza linia respectiva
			istringstream linieStream(linie); //un fel de cin dar pentru obiectul d etip idtringstream-> citeste linia respectiva, si ne permite folosirea getline-ului 
			string denumire;
			string cantitateStr; //pentru a stoca ce am gasit pe linii

			if (getline(linieStream, denumire, delimitator) && getline(linieStream, cantitateStr, delimitator)) { // pe linieSTream citeste pana la delimitator si salveaza in denumire caracterele analog...
				int cantitate = stoi(cantitateStr);
				ingrediente[nrIngrediente++] = Ingrediente(denumire.c_str(), cantitate); // se creaza un obiect, iar c.str() e pt pointerul catre sirul de carcatere
			}
			else
			{
				cout << "Eroare la conversia cantitatii: " << endl;
			}
		}

		file.close();

		return nrIngrediente;
	}
};

class MeniuProduse {
private:
	char* denumireProdus;
	int pret;
	int nrIngrediente;
	Ingrediente** listaIngrediente;
public:

	MeniuProduse* getMeniuProduse() {
		return this;
	}

	MeniuProduse() {
		this->denumireProdus = nullptr;
		this->pret = 0;
		this->nrIngrediente = 0;
		this->listaIngrediente = nullptr;
	}

	//constructor cu toti parametrii
	MeniuProduse(const char* denumireProdus, int pret, int nrIngrediente, Ingrediente** listaIngrediente)
	{
		if (denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(denumireProdus) + 1];
			strcpy(this->denumireProdus, denumireProdus);
		}

		this->pret = pret;



		if (nrIngrediente > 0 && listaIngrediente != nullptr)
		{
			this->nrIngrediente = nrIngrediente;

			this->listaIngrediente = new Ingrediente * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->listaIngrediente[i] = new Ingrediente(*listaIngrediente[i]);
			}
		}

	}

	//afisare
	void afisare() {
		cout << "\n---------------------------------";
		cout << "\nDenumire Produs: " << this->denumireProdus;
		cout << "\nPret: " << this->pret;

		cout << "\nAvem " << this->nrIngrediente << " ingredient/-e: " << endl;
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			cout << *this->listaIngrediente[i];
		}
	}

	//get denumire produs
	const char* getDenumireProdus()
	{
		return this->denumireProdus;
	}



	//set denumire produs
	void setDenumireProdus(const char* denumireNouaProdus) {
		if (denumireNouaProdus != nullptr && strlen(denumireNouaProdus) >= 2) {
			delete[] this->denumireProdus;
			this->denumireProdus = nullptr;
			this->denumireProdus = new char[strlen(denumireNouaProdus) + 1];
			strcpy(this->denumireProdus, denumireNouaProdus);
		}
	}

	//get pret
	int getPret() {
		return this->pret;
	}

	//set pret
	void setPret(int pretNou)
	{
		this->pret = pretNou;
	}


	//set lista ingrediente
	void setListaIngrediente(int nrIngrediente, Ingrediente** listaIngrediente)
	{
		if (listaIngrediente != nullptr && nrIngrediente > 0) {
			delete[] this->listaIngrediente;
			this->listaIngrediente = nullptr;
			this->nrIngrediente = nrIngrediente;

			this->listaIngrediente = new Ingrediente * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->listaIngrediente[i] = new Ingrediente(*listaIngrediente[i]);
			}

		}
	}

	//get lista ingrediente
	Ingrediente** getListaIngrediente()
	{
		return this->listaIngrediente;
	}

	int getNrIngrediente() const {
		return nrIngrediente;
	}

	//constructor copy
	MeniuProduse(const MeniuProduse& m) {
		if (m.denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(m.denumireProdus) + 1];
			strcpy(this->denumireProdus, m.denumireProdus);
		}

		this->pret = m.pret;

		if (m.nrIngrediente > 0 && m.listaIngrediente != nullptr)
		{
			this->nrIngrediente = m.nrIngrediente;

			this->listaIngrediente = new Ingrediente * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->listaIngrediente[i] = new Ingrediente(*m.listaIngrediente[i]);
			}
		}
	}

	//operator =
	MeniuProduse& operator = (const MeniuProduse& m)
	{
		if (this->denumireProdus != nullptr) {
			delete[] this->denumireProdus;
			this->denumireProdus = nullptr;
		}

		if (m.denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(m.denumireProdus) + 1];
			strcpy(this->denumireProdus, m.denumireProdus);
		}

		if (this->listaIngrediente != nullptr) {
			delete[] this->listaIngrediente;
			this->listaIngrediente = nullptr;
		}

		if (this != &m) {
			this->pret = m.pret;

			if (m.nrIngrediente > 0 && m.listaIngrediente != nullptr)
			{
				this->nrIngrediente = m.nrIngrediente;

				this->listaIngrediente = new Ingrediente * [this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++)
				{
					this->listaIngrediente[i] = new Ingrediente(*m.listaIngrediente[i]);
				}
			}
		}
		return *this;
	}

	//operator <<
	friend ostream& operator << (ostream& out, const MeniuProduse& m)
	{
		out << "\nDenumire Produs: " << m.denumireProdus;
		out << "\nPret: " << m.pret;
		out << "\nAvem " << m.nrIngrediente << " ingredient/-e: " << endl;

		for (int i = 0; i < m.nrIngrediente; i++)
		{
			out << *m.listaIngrediente[i];
		}
		out << "\n..................................................";
		return out;
	}

	//operator >>
	friend istream& operator >> (istream& in, MeniuProduse& m)
	{

		if (m.denumireProdus != nullptr) {
			delete[] m.denumireProdus;
			m.denumireProdus = nullptr;
		}

		if (m.listaIngrediente != nullptr) {
			delete[] m.listaIngrediente;
			m.listaIngrediente = nullptr;
		}

		cout << "\nIntroduceti denumire produs: ";
		char buffer[100];
		in >> buffer;
		m.denumireProdus = new char[strlen(buffer) + 1];
		strcpy(m.denumireProdus, buffer);

		cout << "\nNrIngrediente: ";
		in >> m.nrIngrediente;


		m.listaIngrediente = new Ingrediente * [m.nrIngrediente];
		cout << "\nIntroduceti ingredientele: ";
		for (int i = 0; i < m.nrIngrediente; i++)
		{
			Ingrediente* ingredient = new Ingrediente("", 0);
			in >> *ingredient;
			m.listaIngrediente[i] = ingredient;
		}

		cout << "\nIntroduceti pretul: ";
		in >> m.pret;

		return in;
	}

	//operator de indexare []
	Ingrediente* operator[](int index) const {
		if (index >= 0 && index < this->nrIngrediente) {
			if (this->listaIngrediente != nullptr) {
				return this->listaIngrediente[index];
			}
		}
		else {
			throw exception("Eroare: Index invalid!");
		}
	}

	//operator cast
	operator int() const {
		return this->pret;
	}

	//operator >
	bool operator>(const MeniuProduse& m) {
		return this->pret > m.pret;
	}

	//operator ==
	bool operator==(const MeniuProduse& m) {
		return strcmp(this->denumireProdus, m.denumireProdus) == 0;
	}

	void scadeCantitatea() {
		for (int i = 0; i < nrIngrediente; i++)\
		{
			listaIngrediente[i]->scadeCantitateIngrediente();
		}
	}


	//friend ofstream& operator<<(ofstream& outf, const MeniuProduse& m) {
	//	outf.open("meniu.txt");

	//	if (outf.is_open()) {
	//		outf << "\nDenumire Produs: " << m.denumireProdus << endl;
	//		outf << "\nPret: " << m.pret << endl;
	//		outf << "\nAvem " << m.nrIngrediente << " ingredient/-e: " << endl;
	//		for (int i = 0; i < m.nrIngrediente; i++)
	//		{
	//			outf << *m.listaIngrediente[i];
	//		}
	//		outf << "\n..................................................";

	//		outf.close();
	//	}
	//	else {
	//		cout << "Nu s-a putut deschide raportcomenziul pentru scriere!" << endl;
	//	}
	//	return outf;
	//}
	//friend ifstream& operator>>(ifstream& in, MeniuProduse& m) {


	//	cout << "Produs: ";
	//	in >> m.denumireProdus;
	//	cout << "Pret: ";
	//	in >> m.pret;
	//	cout << "\nNr Ingrediente: ";
	//	in >> m.nrIngrediente;

	//	cout << "\nIngrediente: ";
	//	m.listaIngrediente = new Ingrediente * [m.nrIngrediente];
	//	for (int i = 0; i < m.nrIngrediente; ++i) {
	//		m.listaIngrediente[i] = new Ingrediente();
	//		in >> *(m.listaIngrediente[i]);
	//	}

	//	return in;
	//}

	void scrieBinar(const char* fNumeBinar) {
		ofstream binFile(fNumeBinar, ios::binary | ios::app);
		if (binFile.is_open()) {
			int lungimeDenumire = strlen(this->denumireProdus);
			binFile.write((char*)&lungimeDenumire, sizeof(int));
			binFile.write(this->denumireProdus, lungimeDenumire);

			binFile.write((char*)&this->pret, sizeof(int));
			binFile.write((char*)&this->nrIngrediente, sizeof(int));
			for (int i = 0; i < this->nrIngrediente; ++i) {
				int lungimeDenumireIngredient = strlen(this->listaIngrediente[i]->getDenumireIngredient());
				binFile.write((char*)&lungimeDenumireIngredient, sizeof(int));
				binFile.write(this->listaIngrediente[i]->getDenumireIngredient(), lungimeDenumireIngredient);

				int cantitateIngrediente = this->listaIngrediente[i]->getCantitate();
				binFile.write((char*)&cantitateIngrediente, sizeof(int));
			}

			binFile.close();
		}
		else {
			cout << "Nu s-a putut deschide raportcomenziul binar pentru scriere!" << endl;
		}
	}


	//destructor
	~MeniuProduse() {
		if (this->denumireProdus != nullptr) {
			delete[] this->denumireProdus;
			this->denumireProdus = nullptr;
		}

		if (this->listaIngrediente != nullptr) {
			delete[] this->listaIngrediente;
			this->listaIngrediente = nullptr;
		}
	}

};

class ComandaClientului {
private:
	const int idComanda;
	int nrListeMeniuProduse;
	MeniuProduse** listaMeniuProduse;
public:


	ComandaClientului* getComandaClient() {
		return this;
	}

	ComandaClientului() : idComanda(0) {
		this->nrListeMeniuProduse = 0;
		this->listaMeniuProduse = nullptr;
	}

	//constructor cu toti parametrii
	ComandaClientului(int idComanda, int nrListeMeniuProduse, MeniuProduse** listaMeniuProduse) :idComanda(idComanda) {
		if (nrListeMeniuProduse > 0 && listaMeniuProduse != nullptr) {

			this->nrListeMeniuProduse = nrListeMeniuProduse;
			this->listaMeniuProduse = new MeniuProduse * [nrListeMeniuProduse];
			for (int i = 0; i < nrListeMeniuProduse; i++)
			{
				this->listaMeniuProduse[i] = new MeniuProduse(*listaMeniuProduse[i]);
			}
		}
	}

	//constructor doar cu un parametru
	ComandaClientului(int idComanda) :idComanda(idComanda) {
		this->nrListeMeniuProduse = 0;
		this->listaMeniuProduse = nullptr;
	}

	ComandaClientului(int idComanda, int nrListeMeniuProduse, MeniuProduse* produs1, MeniuProduse* produs2) : idComanda(idComanda) {
		this->nrListeMeniuProduse = nrListeMeniuProduse;
		this->listaMeniuProduse = new MeniuProduse * [nrListeMeniuProduse];
		this->listaMeniuProduse[0] = produs1;
		this->listaMeniuProduse[1] = produs2;
	}

	//afisare
	void afisare() {
		cout << "\n---------------------------------";
		cout << "\nID Comanda: " << this->idComanda;
		cout << "\nNr Liste Meniu Produse: " << this->nrListeMeniuProduse;
		cout << "\nLista meniu produse: " << endl;
		if (this->nrListeMeniuProduse > 0) {
			for (int i = 0; i < this->nrListeMeniuProduse; i++) {
				cout << *this->listaMeniuProduse[i];
			}
		}
		else {
			throw exception("Nr liste este negativ sau egal cu 0");
		}
	}

	//set nrListeMeniuProduse
	void setNrListeMeniuProduse(int nrListeMeniuProduse) {
		this->nrListeMeniuProduse = nrListeMeniuProduse;
	}

	//get nrListeMeniuProduse
	int getNrListeMeniuProduse() {
		return this->nrListeMeniuProduse;
	}


	//set listaMeniuProduse
	void setListaMeniuProduse(int nrListeMeniuProduse, MeniuProduse** listaMeniuProduse)
	{
		if (listaMeniuProduse != nullptr && nrListeMeniuProduse > 0)
		{
			delete[] this->listaMeniuProduse;
			this->listaMeniuProduse = nullptr;
			this->nrListeMeniuProduse = nrListeMeniuProduse;

			this->listaMeniuProduse = new MeniuProduse * [this->nrListeMeniuProduse];
			for (int i = 0; i < this->nrListeMeniuProduse; i++)
			{
				this->listaMeniuProduse[i] = new MeniuProduse(*listaMeniuProduse[i]);
			}
		}
	}

	//get listaMeniuProdus
	MeniuProduse** getListaMeniuProduse() {
		return this->listaMeniuProduse;
	}

	//get id
	const int getID() {
		return this->idComanda;
	}

	//constructor copy
	ComandaClientului(const ComandaClientului& c) :idComanda(c.idComanda) {
		if (c.nrListeMeniuProduse > 0 && c.listaMeniuProduse != nullptr) {

			this->nrListeMeniuProduse = c.nrListeMeniuProduse;
			this->listaMeniuProduse = new MeniuProduse * [this->nrListeMeniuProduse];
			for (int i = 0; i < this->nrListeMeniuProduse; i++)
			{
				this->listaMeniuProduse[i] = c.listaMeniuProduse[i];
			}
		}
	}

	//operator =
	ComandaClientului& operator = (const ComandaClientului& c) {
		if (this != &c) {

			if (this->listaMeniuProduse != nullptr)
			{
				delete[] this->listaMeniuProduse;
				this->listaMeniuProduse = nullptr;
			}

			if (c.nrListeMeniuProduse > 0 && c.listaMeniuProduse != nullptr) {

				this->nrListeMeniuProduse = c.nrListeMeniuProduse;
				this->listaMeniuProduse = new MeniuProduse * [this->nrListeMeniuProduse];
				for (int i = 0; i < this->nrListeMeniuProduse; i++)
				{
					this->listaMeniuProduse[i] = c.listaMeniuProduse[i];
				}
			}
		}
		return *this;
	}

	//operator <<
	friend ostream& operator << (ostream& out, const ComandaClientului& c) {
		cout << "\nID Comanda: " << c.idComanda;
		cout << "\nClientul ar dori " << c.nrListeMeniuProduse << " produs\-e, mai exact:" << endl;
		for (int i = 0; i < c.nrListeMeniuProduse; i++) {
			cout << *c.listaMeniuProduse[i];
		}

		return out;
	}

	//operator >>
	friend istream& operator >> (istream& in, ComandaClientului& c) {
		if (c.listaMeniuProduse != nullptr)
		{
			delete[] c.listaMeniuProduse;
			c.listaMeniuProduse = nullptr;
		}

		cout << "\nNr Liste Meniu Produse: ";
		in >> c.nrListeMeniuProduse;

		c.listaMeniuProduse = new MeniuProduse * [c.nrListeMeniuProduse];
		cout << "\nLista meniu produse: " << endl;
		if (c.nrListeMeniuProduse > 0) {
			for (int i = 0; i < c.nrListeMeniuProduse; i++) {
				MeniuProduse* meniuProdus = new MeniuProduse(nullptr, 0, 0, nullptr);
				in >> *meniuProdus;
				c.listaMeniuProduse[i] = meniuProdus;
			}
		}
		else {
			cout << "Nr liste este negaitv sau egal cu 0";
		}



		return in;
	}

	void scadeCantitateaComanda() {
		for (int i = 0; i < nrListeMeniuProduse; i++)
		{
			listaMeniuProduse[i]->scadeCantitatea();
		}
	}

	~ComandaClientului() {
		if (this->listaMeniuProduse != nullptr)
		{
			delete[] this->listaMeniuProduse;
			this->listaMeniuProduse = nullptr;
		}
	}
};

class Livrare
{
private:
	char* numeClient;
	int nrListaComenzi;
	ComandaClientului** listaComenzi;
	bool bacsis;
	int valBacsis;

public:
	//constructor cu toti parametrii
	Livrare(const char* numeClient, int nrListaComenzi, ComandaClientului** listaComenzi, bool bacsis, int valBacsis) {
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}

		if (nrListaComenzi > 0 && listaComenzi != nullptr)
		{
			this->nrListaComenzi = nrListaComenzi;

			this->listaComenzi = new ComandaClientului * [this->nrListaComenzi];
			for (int i = 0; i < this->nrListaComenzi; i++)
			{
				this->listaComenzi[i] = new ComandaClientului(*listaComenzi[i]);
			}
		}

		this->bacsis = bacsis;
		this->valBacsis = valBacsis;

	}

	//constructor cu 3 parametrii
	Livrare(const char* numeClient, int nrListaComenzi, ComandaClientului** listaComenzi) {
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}

		if (nrListaComenzi > 0 && listaComenzi != nullptr)
		{
			this->nrListaComenzi = nrListaComenzi;

			this->listaComenzi = new ComandaClientului * [this->nrListaComenzi];
			for (int i = 0; i < this->nrListaComenzi; i++)
			{
				this->listaComenzi[i] = new ComandaClientului(*listaComenzi[i]);
			}
		}
		this->bacsis = false;
		this->valBacsis = 0;
	}

	Livrare(const char* numeClient, int nrListaComenzi, ComandaClientului* comanda, bool bacsis, int valBacsis) {
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}
		this->nrListaComenzi = nrListaComenzi;
		this->listaComenzi = new ComandaClientului * [nrListaComenzi];
		this->listaComenzi[0] = comanda;
	}

	//afisare
	void afisare() {
		cout << "\n---------------------------------";
		cout << "\nNume Client: " << this->numeClient;
		cout << "\nNr liste Comenzi: " << this->nrListaComenzi;
		if (this->nrListaComenzi > 0) {
			for (int i = 0; i < this->nrListaComenzi; i++) {
				cout << *this->listaComenzi[i];
			}
		}
		else {
			throw exception("Nr liste este negativ sau egal cu 0");
		}
		cout << "\nBacsis (0-nu, 1-da): " << this->bacsis;
		cout << "\nValoarea bacsisului: " << this->valBacsis;

	}

	//set numeClient
	void setNumeClient(const char* numeClient)
	{
		if (numeClient != nullptr && strlen(numeClient) >= 2) {
			delete[] this->numeClient;
			this->numeClient = nullptr;
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}
	}

	//get numeClient
	const char* getNumeClient() {
		return this->numeClient;
	}

	//set nrListaComenzi
	void setNrListaComenzi(int nrListaComenzi) {
		this->nrListaComenzi = nrListaComenzi;
	}

	//get nrListaComenzi
	int getNrListaComenzi() {
		return this->nrListaComenzi;
	}

	//set listaComenzi
	void setListaComenzi(int nrComenzi, ComandaClientului** listaComenzi)
	{
		if (listaComenzi != nullptr && nrComenzi > 0) {
			delete[] this->listaComenzi;
			this->listaComenzi = nullptr;
			this->nrListaComenzi = nrListaComenzi;

			this->listaComenzi = new ComandaClientului * [this->nrListaComenzi];
			for (int i = 0; i < this->nrListaComenzi; i++)
			{
				this->listaComenzi[i] = new ComandaClientului(*listaComenzi[i]);
			}

		}
	}

	//get lista ingrediente
	ComandaClientului** getListaComenzi()
	{
		return this->listaComenzi;
	}

	//set bacsis
	void setBacsis(bool bacsis)
	{
		this->bacsis = bacsis;
	}

	//get bacsis
	bool getBacsis() {
		return this->bacsis = bacsis;
	}

	//set valoarea bacsis
	void setValBacsis(int valBacsis)
	{
		this->valBacsis = valBacsis;
	}

	//get valoarea bacsis
	int getValBacsis() {
		return this->valBacsis = valBacsis;
	}

	//constructor copy
	Livrare(const Livrare& l) {
		if (l.numeClient != nullptr) {
			this->numeClient = new char[strlen(l.numeClient) + 1];
			strcpy(this->numeClient, l.numeClient);
		}

		if (l.nrListaComenzi > 0 && l.listaComenzi != nullptr)
		{
			this->nrListaComenzi = l.nrListaComenzi;

			this->listaComenzi = new ComandaClientului * [this->nrListaComenzi];
			for (int i = 0; i < this->nrListaComenzi; i++)
			{
				this->listaComenzi[i] = new ComandaClientului(*l.listaComenzi[i]);
			}
		}

		this->bacsis = l.bacsis;
		this->valBacsis = l.valBacsis;
	}

	//operator =
	Livrare& operator = (const Livrare& l) {
		if (this != &l) {
			if (this->numeClient != nullptr)
			{
				delete[] this->numeClient;
				this->numeClient = nullptr;
			}

			if (this->listaComenzi != nullptr)
			{
				delete[] this->listaComenzi;
				this->listaComenzi = nullptr;
			}

			if (l.numeClient != nullptr) {
				this->numeClient = new char[strlen(l.numeClient) + 1];
				strcpy(this->numeClient, l.numeClient);
			}

			if (l.nrListaComenzi > 0 && l.listaComenzi != nullptr)
			{
				this->nrListaComenzi = l.nrListaComenzi;

				this->listaComenzi = new ComandaClientului * [this->nrListaComenzi];
				for (int i = 0; i < this->nrListaComenzi; i++)
				{
					this->listaComenzi[i] = new ComandaClientului(*l.listaComenzi[i]);
				}
			}

			this->bacsis = l.bacsis;
			this->valBacsis = l.valBacsis;
		}
		return *this;
	}

	//operator <<
	friend ostream& operator << (ostream& out, const Livrare& l) {
		cout << "\n---------------------------------";
		cout << "\nNume Client: " << l.numeClient;
		cout << "\nNr liste Comenzi: " << l.nrListaComenzi;
		if (l.nrListaComenzi > 0) {
			for (int i = 0; i < l.nrListaComenzi; i++) {
				cout << *l.listaComenzi[i];
			}
		}
		else {
			throw exception("Nr liste este negativ sau egal cu 0");
		}
		cout << "\nBacsis (0-nu, 1-da): " << l.bacsis;
		cout << "\nValoarea bacsisului: " << l.valBacsis;

		return out;
	}

	//operator >>
	friend istream& operator >> (istream& in, Livrare& l) {

		cout << "\nIntroduceti nume clientului: ";
		char buffer[100];
		in >> buffer;
		l.numeClient = new char[strlen(buffer) + 1];
		strcpy(l.numeClient, buffer);

		cout << "\nIntroduceti nr liste comenzi: ";
		in >> l.nrListaComenzi;

		l.listaComenzi = new ComandaClientului * [l.nrListaComenzi];
		cout << "\nIntroduceti lista comenzi: ";
		for (int i = 0; i < l.nrListaComenzi; i++)
		{
			ComandaClientului* comandaClientului = new ComandaClientului(0, 0, nullptr);
			in >> *comandaClientului;
			l.listaComenzi[i] = comandaClientului;
		}

		cout << "\nIntroduceti daca doriti sa acordati bacsis (0-nu, 1-da): ";
		in >> l.bacsis;
		cout << "\nIntroduceti valoarea bacsisului: ";
		in >> l.bacsis;

		return in;

	}

	//operator + (aduna bacsisul)
	Livrare operator+(const Livrare& l) {
		Livrare copie = *this;
		copie.valBacsis += l.valBacsis;
		return copie;
	}

	//operator !
	bool operator!() {
		return !bacsis;
	}


	int calculeazaPretTotal() const {
		int pretTotal = 0;

		for (int i = 0; i < nrListaComenzi; ++i) {
			ComandaClientului* comanda = listaComenzi[i];

			for (int j = 0; j < comanda->getNrListeMeniuProduse(); ++j) {
				MeniuProduse* meniu = comanda->getListaMeniuProduse()[j];
				pretTotal += meniu->getPret();
			}
		}

		if (bacsis) {
			pretTotal += valBacsis;
		}

		return pretTotal;
	}


	//destructor
	~Livrare() {
		if (this->numeClient != nullptr)
		{
			delete[] this->numeClient;
			this->numeClient = nullptr;
		}

		if (this->listaComenzi != nullptr)
		{
			delete[] this->listaComenzi;
			this->listaComenzi = nullptr;
		}
	}
};


class IUtilizator {
public:
	virtual void citeste(ifstream& fisier) = 0;
	virtual void scrie(ofstream& fisier) = 0;
	virtual void afiseazaDetalii() = 0;
	virtual void scrieInFisier(const string& numeFisier) {
		ofstream fisier(numeFisier, ios::binary);
		if (fisier.is_open()) {
			scrie(fisier);
			fisier.close();
		}
		else {
			cerr << "Eroare la deschiderea fisierului: " << numeFisier << endl;
		}
	}
};

class UtilizatorClient : public IUtilizator {
private:
	string nume;

public:
	UtilizatorClient() {
		this->nume = "Anonim";
	}

	UtilizatorClient(string nume) {
		this->nume = nume;
	}

	void citeste(ifstream& fisier) {
		int size;
		fisier.read((char*)&size, sizeof(size));
		char* buffer;
		buffer = new char[size];
		fisier.read(buffer, size);
		this->nume = buffer;
		delete[] buffer;
		buffer = nullptr;
	}

	void scrie(ofstream& fisier) {
		int size = nume.size() + 1;
		fisier.write((const char*)&size, sizeof(size));
		fisier.write(nume.data(), size);
	}
	void afiseazaDetalii() {
		cout << "Nume Client: " << nume << endl;
	}
};


int main() {

	Restaurant r("Modelier", 1);
	Ingrediente i1("carne", 2);
	Ingrediente i2("chifle", 5);
	Ingrediente i3("cascaval", 3);
	Ingrediente i4("cartofi", 4);
	Ingrediente i5("ulei", 3);
	Ingrediente i6("rosii", 5);
	Ingrediente i7("ceapa", 2);
	Ingrediente i8("bacon", 3);
	Ingrediente i9("apa", 4);
	Ingrediente i10("lamaie", 5);
	Ingrediente i11("portocale", 2);
	Ingrediente i12("capsuni", 3);
	Ingrediente i13("zahar", 4);
	Ingrediente i14("aluat", 3);
	Ingrediente i15("boabe de cafea", 5);
	Ingrediente i16("lapte", 1);
	Ingrediente* listaIngrediente[] = { &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12, &i13, &i14, &i15, &i16 };
	Ingrediente* listaIngrediente1[] = { &i1, &i2, &i3, &i6, &i7, &i8 };
	Ingrediente* listaIngrediente2[] = { &i9,&i10, &i11, &i12 };
	Ingrediente* listaIngrediente3[] = { &i12,&i13,&i14 };
	Ingrediente* listaIngrediente4[] = { &i13,&i15,&i16 };
	MeniuProduse m1("Hamburger", 45, 3, listaIngrediente1);
	MeniuProduse m2("Cheeseburger", 50, 5, listaIngrediente1);
	MeniuProduse m3("Wooper", 60, 6, listaIngrediente1);
	MeniuProduse m4("Apa", 7, 1, listaIngrediente2);
	MeniuProduse m5("Limonada", 14, 2, listaIngrediente2);
	MeniuProduse m6("Suc-de-fructe", 16, 4, listaIngrediente2);
	MeniuProduse m7("Prajitura", 20, 3, listaIngrediente3);
	MeniuProduse m8("Espresso", 12, 2, listaIngrediente4);
	MeniuProduse m9("Latte", 14, 3, listaIngrediente4);
	MeniuProduse* listaM[] = { &m9, &m2 };
	MeniuProduse* listaTotala[] = { &m1, &m2, &m3, &m4, &m5,&m6,&m7, &m8,&m9 };
	ComandaClientului c1(1, 2, listaTotala);
	ComandaClientului c2(2, 2, listaTotala[6], listaTotala[7]);
	ComandaClientului c3(3, 2, listaTotala[7], listaTotala[8]);
	ComandaClientului* comandaClientului[] = { &c1, &c2, &c3 };
	Livrare l1("Andrei", 1, comandaClientului, true, 10);
	Livrare l2("Matei", 1, comandaClientului[1], false, 0);
	Livrare l3("Mara", 1, comandaClientului[2], false, 0);
	Livrare* listaLivrare[] = { &l1, &l2, &l3 };


	ofstream raportInput("raportInput.txt");
	if (raportInput.is_open()) {
		int optiune;
		do {
			cout << "\nMeniu de navigare:" << endl << endl;
			cout << "Introduceti 0 pentru a se finaliza activitatea meniului" << endl;
			cout << "Introduceti 1 pentru a se crea fisierele binare pentru ingrediente, meniu" << endl;
			cout << "Introduceti 2 pentru a se crea rapoartele" << endl;
			cout << "Introduceti 3 pentru a prelua datele dintr-un fisier csv" << endl;
			cout << "Introduceti 4 pentru vizualiza STL-urile" << endl;
			cout << "Introduceti 5 pentru virtualizare" << endl << endl;

			cout << "OPTIUNE:";
			cin >> optiune;
			raportInput << "Utilizatorul a selectat optiunea: " << optiune << endl;

			switch (optiune) {
			case 0:
				raportInput << "Utilizatorul a selectat sa fie finalizata activitatea meniului." << endl;
				cout << "Activitatea meniului a fost finalizata." << endl;
				break;
			case 1:
				raportInput << "Utilizatorul a selectat crearea fisierelor binare pentru ingrediente, meniu." << endl;
				if (optiune == 1) {
					ofstream ingrediente("ingrediente.txt", ios::trunc);
					if (ingrediente.is_open()) {
						ingrediente << ">>>>>>>>>>>> INGREDIENTE <<<<<<<<<<<<" << endl << endl;
						cout << endl << ">>>>>>>>>>>> INGREDIENTE <<<<<<<<<<<<" << endl;
						for (int i = 0; i < sizeof(listaIngrediente) / sizeof(listaIngrediente[0]); ++i) {
							ingrediente << *listaIngrediente[i] << endl;
							cout << *listaIngrediente[i] << endl;
						}

						ingrediente.close();

						for (int i = 0; i < sizeof(listaIngrediente) / sizeof(listaIngrediente[0]); ++i) {
							Ingrediente* ingredient = listaIngrediente[i]->getIngrediente();
							ingredient->scrieBinar("ingrediente.bin");
						}
					}
					else {
						cout << "Nu s-a putut deschide raportcomenziul pentru scriere!" << endl;
					}

					ofstream meniu("meniu.txt", ios::trunc);
					if (meniu.is_open()) {
						meniu << ">>>>>>>>>>>> MENIU <<<<<<<<<<<<" << endl << endl;
						cout << endl << ">>>>>>>>>>>> MENIU <<<<<<<<<<<<" << endl;
						for (int i = 0; i < sizeof(listaTotala) / sizeof(listaTotala[0]); ++i) {
							meniu << *listaTotala[i] << endl;
							cout << *listaTotala[i] << endl;
						}
						meniu.close();

						for (int i = 0; i < sizeof(listaTotala) / sizeof(listaTotala[0]); ++i) {
							MeniuProduse* meniu = listaTotala[i]->getMeniuProduse();
							meniu->scrieBinar("meniu.bin");
						}
					}
					else {
						cout << "Nu s-a putut deschide raportcomenziul pentru scriere!" << endl;
					}

				}
				break;
			case 2:
				raportInput << "Utilizatorul a selectat crearea rapoartelor." << endl;
				if (optiune == 2) {
					int subOption;
					do {
						cout << "\nSubmeniu pentru fisierele binare:" << endl << endl;
						cout << "Introduceti 0 pentru a reveni la meniul principal" << endl;
						cout << "Introduceti 1 pentru a crea raportul pentru Comenzi" << endl;
						cout << "Introduceti 2 pentru a crea raportul pentru Livrari" << endl;
						cout << "Introduceti 3 pentru a crea raportul pentru Stoc" << endl;


						cout << "SUB-OPTIUNE: ";
						cin >> subOption;

						switch (subOption) {
						case 0:
							raportInput << "Utilizatorul a selectat sa fie finalizata activitatea sub meniului." << endl;
							cout << "Revenire la meniul principal..." << endl;
							break;
						case 1:
							raportInput << "Utilizatorul a selectat sa fie creat raportul Comenzi." << endl;
							cout << "Creare raport Comenzi..." << endl;
							if (subOption == 1) {
								ofstream raportcomenzi("raportComenzi.txt");
								if (raportcomenzi.is_open()) {
									raportcomenzi << "********** RAPORT COMENZI ***********" << endl << endl;

									for (int i = 0; i < sizeof(comandaClientului) / sizeof(comandaClientului[0]); ++i) {

										raportcomenzi << "ID Comanda: " << comandaClientului[i]->getID() << "\n";

										for (int j = 0; j < comandaClientului[i]->getNrListeMeniuProduse(); ++j) {
											raportcomenzi << "    \nDenumire Produs: " << comandaClientului[i]->getListaMeniuProduse()[j]->getDenumireProdus() << endl;

											for (int k = 0; k < comandaClientului[i]->getListaMeniuProduse()[j]->getNrIngrediente(); ++k) {
												raportcomenzi << "        Denumire Ingredient: " << comandaClientului[i]->getListaMeniuProduse()[j]->getListaIngrediente()[k]->getDenumireIngredient() << endl;
												raportcomenzi << "        Cantitate: " << comandaClientului[i]->getListaMeniuProduse()[j]->getListaIngrediente()[k]->getCantitate() << endl;

											}

										}

										raportcomenzi << "\n------------------------------------------------------------------------" << endl << endl;
									}

									raportcomenzi.close();
								}
								else {
									cout << "Nu s-a putut crea raportul pentru comenzi!" << endl;

								}
							}
							break;

						case 2:
							raportInput << "Utilizatorul a selectat sa fie creat raportul Livrari." << endl;
							cout << "Creare raport Livrari..." << endl;
							if (subOption == 2) {
								ofstream raportlivrari("raportlivrari.txt");
								if (raportlivrari.is_open()) {
									raportlivrari << "********** RAPORT LIVRARI ***********" << endl << endl;

									for (int i = 0; i < sizeof(listaLivrare) / sizeof(listaLivrare[0]); ++i) {
										for (int j = 0; j < listaLivrare[i]->getNrListaComenzi(); ++j) {
											raportlivrari << "ID-ul Comenzi: " << listaLivrare[i]->getListaComenzi()[j]->getID() << endl << endl;

											raportlivrari << "Numele Clientului: " << listaLivrare[i]->getNumeClient() << endl;
											raportlivrari << "Bacsisul: " << listaLivrare[i]->getValBacsis() << endl;
											raportlivrari << "NOTA (PRET TOTAL): " << listaLivrare[i]->calculeazaPretTotal() << endl;
											raportlivrari << "-----------------------------------------------" << endl << endl;
										}
									}
									raportlivrari.close();
								}
								else {
									cout << "Nu s-a putut crea raportul pentru livrari!" << endl;

								}
							}
							break;
						case 3:
							raportInput << "Utilizatorul a selectat sa fie creat raportul Stocuri." << endl;
							cout << "Creare raport Stocuri..." << endl;
							if (subOption == 3) {
								ofstream raportstocuri("raportstocuri.txt");
								if (raportstocuri.is_open()) {
									raportstocuri << "********** raport stocuri ***********" << endl << endl;

									for (int i = 0; i < sizeof(comandaClientului) / sizeof(comandaClientului[0]); ++i) {
										raportstocuri << "id-ul comenzi: " << comandaClientului[i]->getID() << endl;
										comandaClientului[i]->scadeCantitateaComanda();

										for (int j = 0; j < comandaClientului[i]->getNrListeMeniuProduse(); ++j) {

											raportstocuri << "produs: " << comandaClientului[i]->getListaMeniuProduse()[j]->getDenumireProdus() << "\n";
											raportstocuri << "pret: " << comandaClientului[i]->getListaMeniuProduse()[j]->getPret() << "\n";
											raportstocuri << "ingrediente:\n";

											for (int k = 0; k < comandaClientului[i]->getListaMeniuProduse()[j]->getNrIngrediente(); ++k) {
												raportstocuri << "cantitate:  " << comandaClientului[i]->getListaMeniuProduse()[j]->getListaIngrediente()[k]->getDenumireIngredient() << ": " << comandaClientului[i]->getListaMeniuProduse()[j]->getListaIngrediente()[k]->getCantitate() << "\n";
											}
											raportstocuri << "\n";

										}
										raportstocuri << "\n--------------------------------------------------------" << endl << endl;

									}
								}
							}
							break;
						default:
							raportInput << "Utilizatorul a introdus o optiune invalida in cadrul submeniului." << endl;
							cout << "Optiune invalida. Va rugam introduceti o optiune valida." << endl;
						}

					} while (subOption != 0);
				}
				break;
			case 3:
				raportInput << "Utilizatorul a selectat preluarea datelor dintr-un fisier csv." << endl;
				if (optiune == 3) {
					FisierCSV fisierCsv(';');
					Ingrediente ingrediente[100];
					int numarIngrediente = fisierCsv.incarcaDate(ingrediente, "fisier.csv", 100);

					for (int i = 0; i < numarIngrediente; ++i) {
						ingrediente[i].afisare();
					}
				}
				break;
			case 4:
				raportInput << "Utilizatorul a selectat vizualizarea STL-urilor." << endl;
				if (optiune == 4) {
					int subOption2;
					do {
						cout << "\nSubmeniu pentru STL:" << endl;
						cout << "Introduceti 0 pentru a reveni la meniul principal" << endl;
						cout << "Introduceti 1 pentru a vizualiza STL VECTOR" << endl;
						cout << "Introduceti 2 pentru a vizualiza STL LISTA" << endl;
						cout << "Introduceti 3 pentru a vizualiza STL MAP" << endl;
						cout << "Introduceti 4 pentru a vizualiza STL SET" << endl;

						cout << "Introduceti optiunea: ";
						cin >> subOption2;

						switch (subOption2) {
						case 0:
							cout << "Revenire la meniul principal..." << endl;
							break;

						case 1:
							if (subOption2 == 1)
							{
								raportInput << "Utilizatorul a selectat afisarea STL-ului de Vectori." << endl;
								cout << "-----------------------------STL VECTOR INGREDIENTE--------------------------------------" << endl;
								vector<Ingrediente> vListaIngrediente;

								vListaIngrediente.push_back(Ingrediente("Mazare", 100));
								vListaIngrediente.push_back(Ingrediente("Fasole", 200));
								vListaIngrediente.push_back(Ingrediente("Sos de rosii", 20));


								cout << "Dimensiunea vectorului: " << vListaIngrediente.size() << endl;
								cout << "............" << endl << endl;

								vListaIngrediente.reserve(200);
								cout << "Capacitatea vectorului: " << vListaIngrediente.capacity() << endl;
								cout << "............" << endl << endl;

								cout << "Accesarea elementelor prin indice []: " << endl;
								for (int i = 0; i < vListaIngrediente.size(); i++) {
									cout << vListaIngrediente[i] << endl;
								}
								cout << "............" << endl << endl;

								cout << "Parcurgerea elementelor cu iterator: " << endl;
								vector<Ingrediente>::iterator it;
								for (it = vListaIngrediente.begin(); it != vListaIngrediente.end(); it++)
								{
									cout << *it << endl;
								}
								cout << "............" << endl << endl;


								cout << "Verificarea vectorului daca e gol: " << endl;
								if (vListaIngrediente.empty() == false) {
									cout << "\nVectorul NU e gol" << endl;
								}
								else {
									cout << "\nVectorul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;


								cout << "Afisarea primului element din vector: " << endl;
								cout << vListaIngrediente.front() << endl;
								cout << "............" << endl << endl;


								cout << "Afiseaza elementul de pe pozitia 2: " << endl;
								cout << vListaIngrediente.at(1);
								cout << "............" << endl << endl;


								cout << "Afisarea ulimului element din vector: " << endl;
								cout << vListaIngrediente.back() << endl;
								cout << "............" << endl << endl;


								cout << "Inserarea unui element pe pozitia 2: " << endl;
								vListaIngrediente.insert(vListaIngrediente.begin() + 1, Ingrediente("Ciocolata", 50));
								for (it = vListaIngrediente.begin(); it != vListaIngrediente.end(); it++)
								{
									cout << *it << endl;
								}
								cout << "............" << endl << endl;

								vector<Ingrediente> vListaIngrediente2;

								vListaIngrediente2.push_back(Ingrediente("Cola", 30));
								vListaIngrediente2.push_back(Ingrediente("Sprite", 20));
								vListaIngrediente2.push_back(Ingrediente("Fanta", 10));
								cout << "Afisarea primului vector: " << endl;
								for (it = vListaIngrediente.begin(); it != vListaIngrediente.end(); it++)
								{
									cout << *it << endl;
								}

								cout << "\nAfisarea celui de al doilea vector: " << endl;
								vector<Ingrediente>::iterator it3;
								for (it3 = vListaIngrediente2.begin(); it3 != vListaIngrediente2.end(); it3++)
								{
									cout << *it3 << endl;
								}

								cout << "Interschimbarea lor: " << endl << endl;
								vListaIngrediente.swap(vListaIngrediente2);
								cout << "\nAfisarea primului vector: " << endl;
								for (it = vListaIngrediente.begin(); it != vListaIngrediente.end(); it++)
								{
									cout << *it << endl;
								}

								cout << "\nAfisarea celui de al doilea vector: " << endl;
								for (it3 = vListaIngrediente2.begin(); it3 != vListaIngrediente2.end(); it3++)
								{
									cout << *it3 << endl;
								}



								cout << "............" << endl << endl;

								cout << "Eliminarea ultimul element din vector: " << endl;
								vListaIngrediente.pop_back();
								for (it = vListaIngrediente.begin(); it != vListaIngrediente.end(); it++)
								{
									cout << *it << endl;
								}
								cout << "............" << endl << endl;

								cout << "Eliminarea tuturor elementelor din vector: " << endl << endl;
								vListaIngrediente.clear();
								cout << "Dimensiunea vectorului: " << vListaIngrediente.size() << endl << endl;
								cout << "Verificarea vectorului daca e gol: " << endl;
								if (vListaIngrediente.empty() == false) {
									cout << "\nVectorul NU e gol" << endl;
								}
								else {
									cout << "\nVectorul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;
							}
							break;

						case 2:
							if (subOption2 == 2) {
								raportInput << "Utilizatorul a selectat afisarea STL-ului de Liste." << endl;

								cout << "-----------------------------STL LISTA BACSIS--------------------------------------" << endl;

								list<string>lProduse;
								string produs1 = m1.getDenumireProdus();
								string produs2 = m2.getDenumireProdus();
								string produs3 = m3.getDenumireProdus();
								lProduse.push_back(produs1);
								lProduse.push_back(produs2);
								lProduse.push_back(produs3);

								cout << "Dimensiunea listei: " << lProduse.size() << endl;
								cout << "............" << endl << endl;

								cout << "Parcurgerea elementelor cu iterator: " << endl;
								list<string>::iterator it1;
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "............" << endl << endl;

								cout << "Verificarea listei daca e goala: " << endl;
								if (lProduse.empty() == false) {
									cout << "\nLista NU e goala" << endl;
								}
								else {
									cout << "\nLista ESTE goala" << endl;
								}
								cout << "............" << endl << endl;


								cout << "Afisarea primului element din lista: " << endl;
								cout << lProduse.front() << endl;
								cout << "............" << endl << endl;


								cout << "Afisarea ulimului element din lista: " << endl;
								cout << lProduse.back() << endl;
								cout << "............" << endl << endl;


								cout << "Inserarea unui element: " << endl;
								string wrapper = "Wrapper";
								lProduse.insert(lProduse.begin(), wrapper);
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "............" << endl << endl;

								cout << "Sortarea listei: " << endl;
								lProduse.sort();
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}cout << "............" << endl << endl;


								list<string>lProduse2;
								string produs4 = m4.getDenumireProdus();
								string produs5 = m5.getDenumireProdus();
								string produs6 = m6.getDenumireProdus();

								lProduse2.push_back(produs4);
								lProduse2.push_back(produs5);
								lProduse2.push_back(produs6);
								cout << "Afisarea primei liste: " << endl;
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "\nAfisarea celei de a doua liste: " << endl;

								for (it1 = lProduse2.begin(); it1 != lProduse2.end(); it1++)
								{
									cout << *it1 << endl;
								}

								cout << "\nInterschimbarea elementelor celor doua liste: " << endl;
								lProduse.swap(lProduse2);
								cout << "\nAfisarea primei liste: " << endl;
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "\nAfisarea celei de a doua liste: " << endl;

								for (it1 = lProduse2.begin(); it1 != lProduse2.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "............" << endl << endl;

								cout << "Eliminarea ultimul element din lista: " << endl;
								lProduse.pop_back();
								for (it1 = lProduse.begin(); it1 != lProduse.end(); it1++)
								{
									cout << *it1 << endl;
								}
								cout << "............" << endl << endl;

								cout << "Eliminarea tuturor elementelor din lista: " << endl << endl;
								lProduse.clear();
								cout << "Dimensiunea listei: " << lProduse.size() << endl << endl;
								cout << "Verificarea listei daca e goala: " << endl;
								if (lProduse.empty() == false) {
									cout << "\nLista NU e goala" << endl;
								}
								else {
									cout << "\nLista ESTE goala" << endl;
								}
								cout << "............" << endl << endl;
							}
							break;

						case 3:
							if (subOption2 == 3) {
								raportInput << "Utilizatorul a selectat afisarea STL-ului de Map-uri." << endl;

								cout << "-----------------------------STL MAP MENIU--------------------------------------" << endl;
								map<int, MeniuProduse> meniu;
								meniu[1] = m1;
								meniu[2] = m2;
								meniu[3] = m3;

								cout << "Dimensiunea map-ului: " << meniu.size() << endl;
								cout << "............" << endl << endl;

								cout << "Parcurgerea elementelor cu iterator: " << endl;
								map<int, MeniuProduse>::iterator it4;
								for (it4 = meniu.begin(); it4 != meniu.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}
								cout << "............" << endl << endl;

								cout << "Verificarea map-ului daca e gol: " << endl;
								if (meniu.empty() == false) {
									cout << "\nMap-ul NU e gol" << endl;
								}
								else {
									cout << "\nMap-ul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;


								cout << "Inserarea unui element: " << endl;
								meniu.insert({ 1,m4 });
								for (it4 = meniu.begin(); it4 != meniu.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}
								cout << "............" << endl << endl;

								cout << "Afiseaza elementul de pe pozitia 2: " << endl;
								cout << meniu.at(2);
								cout << "............" << endl << endl;

								map<int, MeniuProduse> meniu2;
								meniu2[1] = m4;
								meniu2[2] = m5;
								meniu2[3] = m6;
								cout << "Afisarea primului map: " << endl;
								for (it4 = meniu.begin(); it4 != meniu.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}
								cout << "\nAfisarea celui de al doilea map: " << endl;

								for (it4 = meniu2.begin(); it4 != meniu2.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}

								cout << "\nInterschimbarea elementelor din cele doua map-uri: " << endl;
								meniu.swap(meniu2);
								cout << "Afisarea primului map: " << endl;
								for (it4 = meniu.begin(); it4 != meniu.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}
								cout << "\nAfisarea celui de al doilea map: " << endl;

								for (it4 = meniu2.begin(); it4 != meniu2.end(); it4++)
								{
									cout << endl << it4->first << " " << it4->second;
								}

								cout << "............" << endl << endl;


								cout << "\nGasirea elementului 2 in map: " << endl;

								auto iterator = meniu.find(2);

								if (iterator != meniu.end()) {
									cout << "Elementul a fost gasit." << endl;
								}
								else {
									cout << "Elementul NU a fost gasit." << endl;
								}
								cout << "............" << endl << endl;


								cout << "Eliminarea tuturor elementelor din map: " << endl << endl;
								meniu.clear();
								cout << "Dimensiunea map-ului: " << meniu.size() << endl << endl;
								cout << "Verificarea map-ului daca e gol: " << endl;
								if (meniu.empty() == false) {
									cout << "\nMap-ul NU e gol" << endl;
								}
								else {
									cout << "\nMap-ul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;
							}
							break;

						case 4:
							if (subOption2 == 4) {
								raportInput << "Utilizatorul a selectat afisarea STL-ului de Meniu." << endl;
								cout << "-----------------------------STL SET MENIU--------------------------------------" << endl;

								set<int> preturi;
								preturi.insert(m1.getPret());
								preturi.insert(m2.getPret());
								preturi.insert(m3.getPret());

								cout << "Dimensiunea set-ului: " << preturi.size() << endl;
								cout << "............" << endl << endl;

								cout << "Parcurgerea elementelor cu iterator: " << endl;
								set<int>::iterator it5;
								for (it5 = preturi.begin(); it5 != preturi.end(); it5++)
								{
									cout << *it5 << endl;
								}
								cout << "............" << endl << endl;

								cout << "Verificarea set-ului daca e gol: " << endl;
								if (preturi.empty() == false) {
									cout << "\nSet-ul NU e gol" << endl;
								}
								else {
									cout << "\nSet-ul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;

								set<int> preturi2;
								preturi2.insert(m4.getPret());
								preturi2.insert(m5.getPret());
								preturi2.insert(m6.getPret());

								cout << "Afisarea primului set: " << endl;
								for (it5 = preturi.begin(); it5 != preturi.end(); it5++)
								{
									cout << *it5 << endl;
								}
								cout << "\nAfisarea celui de al doilea set: " << endl;

								for (it5 = preturi2.begin(); it5 != preturi2.end(); it5++)
								{
									cout << *it5 << endl;
								}

								cout << "\nInterschimbarea elementelor din cele doua set-uri: " << endl;
								preturi.swap(preturi2);
								cout << "Afisarea primului set: " << endl;
								for (it5 = preturi.begin(); it5 != preturi.end(); it5++)
								{
									cout << *it5 << endl;
								}
								cout << "\nAfisarea celui de al doilea set: " << endl;

								for (it5 = preturi2.begin(); it5 != preturi2.end(); it5++)
								{
									cout << *it5 << endl;
								}

								cout << "............" << endl << endl;


								cout << "Eliminarea tuturor elementelor din set: " << endl << endl;
								preturi.clear();
								cout << "Dimensiunea set-ului: " << preturi.size() << endl << endl;
								cout << "Verificarea set-ului daca e gol: " << endl;
								if (preturi.empty() == false) {
									cout << "\nSet-ul NU e gol" << endl;
								}
								else {
									cout << "\nSet-ul ESTE gol" << endl;
								}
								cout << "............" << endl << endl;
							}
							break;

						default:
							raportInput << "Utilizatorul a introdus o optiune invalida in cadrul submeniului." << endl;
							cout << "Optiune invalida. Va rugam introduceti o optiune valida." << endl;
						}
					}

					while (subOption2 != 0);
				}
				break;
			case 5:
				raportInput << "Utilizatorul a selectat virtualizarea" << endl;
				if (optiune == 5) {
					UtilizatorClient client("Marcus");

					client.scrieInFisier("utilizatorClient.bin");

					ifstream fisierCitire("utilizatorClient.bin", ios::binary);
					UtilizatorClient clientCitit;
					clientCitit.citeste(fisierCitire);

					clientCitit.afiseazaDetalii();

					fisierCitire.close();
				}
				break;
			default:
				raportInput << "Utilizatorul a introdus o optiune invalida." << endl;
				cout << "Optiune invalida. Va rugam sa reintroduceti." << endl;
				break;
			}
		} while (optiune != 0);

		raportInput.close();
	}
	else {
		cout << "Nu s-a putut deschide fisierul pentru scriere." << endl;

	}



	return 0;
}