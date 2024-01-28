#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
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

	//scaderea cantitatii
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

enum CategorieProduse {
	MicDejun, Pranz, Cina
};

class MeniuProduse {
private:
	char* denumireProdus;
	int nrCategorieProduse;
	CategorieProduse* categorieProduse;
	int pret;
	int nrIngrediente;
	Ingrediente** listaIngrediente;
public:
	//constructor cu toti parametrii
	MeniuProduse(const char* denumireProdus, int nrCategorieProduse, CategorieProduse* categorieProduse, int pret, int nrIngrediente, Ingrediente** listaIngrediente)
	{
		if (denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(denumireProdus) + 1];
			strcpy(this->denumireProdus, denumireProdus);
		}

		if (nrCategorieProduse > 0 && categorieProduse != nullptr)
		{
			this->nrCategorieProduse = nrCategorieProduse;

			this->categorieProduse = new CategorieProduse[this->nrCategorieProduse];
			for (int i = 0; i < this->nrCategorieProduse; i++)
				this->categorieProduse[i] = categorieProduse[i];
		}
		else {
			this->nrCategorieProduse = 0;
			this->categorieProduse = nullptr;
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

	//constructor doar cu 4 parametrii
	MeniuProduse(int idProdus, const char* denumireProdus, int nrIngrediente, Ingrediente** listaIngrediente)
	{
		if (denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(denumireProdus) + 1];
			strcpy(this->denumireProdus, denumireProdus);
		}

		if (nrIngrediente > 0 && listaIngrediente != nullptr)
		{
			this->nrIngrediente = nrIngrediente;

			this->listaIngrediente = new Ingrediente * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				this->listaIngrediente[i] = new Ingrediente(*listaIngrediente[i]);
			}
		}

		this->nrCategorieProduse = 0;
		this->categorieProduse = nullptr;
		this->pret = 0;
	}

	//afisare
	void afisare() {
		cout << "\n---------------------------------";
		cout << "\nDenumire Produs: " << this->denumireProdus;
		cout << "\nCategorie de " << this->nrCategorieProduse << " produse (0 - MicDejun, 1 - Pranz, 2 - Cina): ";
		if (this->categorieProduse != nullptr) {
			for (int i = 0; i < this->nrCategorieProduse; i++)
				cout << this->categorieProduse[i] << " ";
		}
		else {
			cout << "-";
		}
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

	//get NrCategorieProduse
	const int getNrCategorieProduse() {
		return this->nrCategorieProduse;
	}

	//set NrCategorieProduse
	void setNrCategorieProduse(int nrCategorieProduseNou)
	{
		this->nrCategorieProduse = nrCategorieProduseNou;
	}

	//set categorie produse
	void setCategorieProduse(CategorieProduse* categorieProduse) {
		if (categorieProduse != nullptr) {
			delete[] this->categorieProduse;
			this->categorieProduse = nullptr;
			this->categorieProduse = new CategorieProduse[this->nrCategorieProduse];
			for (int i = 0; i < this->nrCategorieProduse; i++) {
				this->categorieProduse[i] = categorieProduse[i];
			}
		}
	}

	//get categorie produse
	CategorieProduse* getCategorieProduse()
	{
		return this->categorieProduse;
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

	//constructor copy
	MeniuProduse(const MeniuProduse& m) {
		if (m.denumireProdus != nullptr) {
			this->denumireProdus = new char[strlen(m.denumireProdus) + 1];
			strcpy(this->denumireProdus, m.denumireProdus);
		}

		this->pret = m.pret;

		if (m.nrCategorieProduse > 0 && m.categorieProduse != nullptr)
		{
			this->nrCategorieProduse = m.nrCategorieProduse;
			this->categorieProduse = new CategorieProduse[this->nrCategorieProduse];
			for (int i = 0; i < this->nrCategorieProduse; i++)
				this->categorieProduse[i] = m.categorieProduse[i];
		}
		else {
			this->nrCategorieProduse = 0;
			this->categorieProduse = nullptr;
		}

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

		if (this->categorieProduse != nullptr) {
			delete[] this->categorieProduse;
			this->categorieProduse = nullptr;
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

			if (m.nrCategorieProduse > 0 && m.categorieProduse != nullptr)
			{
				this->nrCategorieProduse = m.nrCategorieProduse;
				this->categorieProduse = new CategorieProduse[this->nrCategorieProduse];
				for (int i = 0; i < this->nrCategorieProduse; i++)
					this->categorieProduse[i] = m.categorieProduse[i];
			}
			else {
				this->nrCategorieProduse = 0;
				this->categorieProduse = nullptr;
			}

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
		out << "\nCategorie de " << m.nrCategorieProduse << " produse (0 - MicDejun, 1 - Pranz, 2 - Cina): ";
		if (m.categorieProduse != nullptr) {
			for (int i = 0; i < m.nrCategorieProduse; i++)
				out << m.categorieProduse[i] << " ";
		}
		else {
			out << "-";
		}
		out << "\nPret: " << m.pret;
		out << "\nAvem " << m.nrIngrediente << " ingredient/-e: " << endl;

		for (int i = 0; i < m.nrIngrediente; i++)
		{
			out << *m.listaIngrediente[i];
		}
		out << "..................................................";
		return out;
	}

	//operator >>
	friend istream& operator >> (istream& in, MeniuProduse& m)
	{

		if (m.denumireProdus != nullptr) {
			delete[] m.denumireProdus;
			m.denumireProdus = nullptr;
		}

		if (m.categorieProduse != nullptr) {
			delete[] m.categorieProduse;
			m.categorieProduse = nullptr;
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

		cout << "\nIntroduceti nr categorie produse: ";
		in >> m.nrCategorieProduse;


		if (m.nrCategorieProduse <= 0)
		{
			m.nrCategorieProduse = 0;
			m.categorieProduse = nullptr;
			cout << "Numarul de categorii este egal cu 0";
		}
		else {
			m.categorieProduse = new CategorieProduse[m.nrCategorieProduse];
			for (int i = 0; i < m.nrCategorieProduse; i++)
			{
				int ctg;
				cout << "\nIntroduceti categorie produse ( 0 - MicDejun, 1 - Pranz, 2 - Cina ) pentru categoria de produse: " << (i + 1) << ": ";
				in >> ctg;

				if (ctg < 0 || ctg>2)
				{
					cout << "Categorie produse invalida!" << endl;
				}
				else
				{
					m.categorieProduse[i] = static_cast<CategorieProduse>(ctg);
				}
			}
		}
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

	void afiseazaStoc() {
		cout << "Stoc pentru " << this->denumireProdus << ":\n";
		for (int i = 0; i < this->nrIngrediente; ++i) {
			cout << " - " << this->listaIngrediente[i]->getCantitate() << " " << this->listaIngrediente[i]->getDenumireIngredient() << "\n";
		}
	}

	bool verificaStocuri() {
		for (int i = 0; i < nrIngrediente; i++) {
			if (listaIngrediente[i]->getCantitate() == 0) {
				cout << "Stocuri insuficiente pentru ingredientul " << listaIngrediente[i]->getDenumireIngredient() << "." << endl;
				return false;
			}
		}
		return true;
	}

	void scadeCantitatea()
	{
		for (int i = 0; i < this->nrIngrediente; i++) {
			listaIngrediente[i]->scadeCantitateIngrediente();
		}

	}

	//destructor
	~MeniuProduse() {
		if (this->denumireProdus != nullptr) {
			delete[] this->denumireProdus;
			this->denumireProdus = nullptr;
		}

		if (this->categorieProduse != nullptr) {
			delete[] this->categorieProduse;
			this->categorieProduse = nullptr;
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
	int nrRestaurant;
	Restaurant** listaRestaurant;
public:

	//constructor cu toti parametrii
	ComandaClientului(int idComanda, int nrListeMeniuProduse, MeniuProduse** listaMeniuProduse, int nrRestaurant, Restaurant** listaRestaurant) :idComanda(idComanda) {
		if (nrListeMeniuProduse > 0 && listaMeniuProduse != nullptr) {

			this->nrListeMeniuProduse = nrListeMeniuProduse;
			this->listaMeniuProduse = new MeniuProduse * [this->nrListeMeniuProduse];
			for (int i = 0; i < this->nrListeMeniuProduse; i++)
			{
				this->listaMeniuProduse[i] = new MeniuProduse(*listaMeniuProduse[i]);
			}
		}

		if (nrRestaurant > 0 && listaRestaurant != nullptr) {

			this->nrRestaurant = nrRestaurant;
			this->listaRestaurant = new Restaurant * [this->nrRestaurant];
			for (int i = 0; i < this->nrRestaurant; i++)
			{
				this->listaRestaurant[i] = new Restaurant(*listaRestaurant[i]);
			}
		}
	}

	//constructor doar cu un parametru
	ComandaClientului(int idComanda) :idComanda(idComanda) {
		this->nrListeMeniuProduse = 0;
		this->listaMeniuProduse = nullptr;
		this->nrRestaurant = 0;
		this->listaRestaurant = nullptr;

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

		cout << "\nLista Restaurant: " << endl;
		if (this->nrRestaurant > 0) {
			for (int i = 0; i < this->nrRestaurant; i++) {
				cout << *this->listaRestaurant[i];
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

	//set nrRestaurant
	void setNrRestaurant(int nrRestaurant) {
		this->nrRestaurant = nrRestaurant;
	}

	//get nrRestaurant
	int getNrRestaurant() {
		return this->nrRestaurant;
	}

	//set lista restaurant
	void setListaRestaurant(int nrRestaurant, Restaurant** listaRestaurant)
	{
		if (listaRestaurant != nullptr && nrRestaurant > 0)
		{
			delete[] this->listaRestaurant;
			this->listaRestaurant = nullptr;
			this->nrRestaurant = nrRestaurant;

			this->listaRestaurant = new Restaurant * [this->nrRestaurant];
			for (int i = 0; i < this->nrRestaurant; i++)
			{
				this->listaRestaurant[i] = new Restaurant(*listaRestaurant[i]);
			}
		}
	}

	//get listaRestaurant
	Restaurant** getListaRestaurant() {
		return this->listaRestaurant;
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

		if (c.nrRestaurant > 0 && c.listaRestaurant != nullptr) {

			this->nrRestaurant = c.nrRestaurant;
			this->listaRestaurant = new Restaurant * [this->nrRestaurant];
			for (int i = 0; i < this->nrRestaurant; i++)
			{
				this->listaRestaurant[i] = new Restaurant(*c.listaRestaurant[i]);
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

			if (this->listaRestaurant != nullptr)
			{
				delete[] this->listaRestaurant;
				this->listaRestaurant = nullptr;
			}

			if (c.nrListeMeniuProduse > 0 && c.listaMeniuProduse != nullptr) {

				this->nrListeMeniuProduse = c.nrListeMeniuProduse;
				this->listaMeniuProduse = new MeniuProduse * [this->nrListeMeniuProduse];
				for (int i = 0; i < this->nrListeMeniuProduse; i++)
				{
					this->listaMeniuProduse[i] = c.listaMeniuProduse[i];
				}
			}

			if (c.nrRestaurant > 0 && c.listaRestaurant != nullptr) {

				this->nrRestaurant = c.nrRestaurant;
				this->listaRestaurant = new Restaurant * [this->nrRestaurant];
				for (int i = 0; i < this->nrRestaurant; i++)
				{
					this->listaRestaurant[i] = new Restaurant(*c.listaRestaurant[i]);
				}
			}
		}
		return *this;
	}

	//operator <<
	friend ostream& operator << (ostream& out, const ComandaClientului& c) {
		cout << "\nID Comanda: " << c.idComanda;
		cout << "\nClientul ar dori " << c.nrListeMeniuProduse << " produs\-e, mai exact:" << endl;
		if (c.nrListeMeniuProduse > 0) {
			for (int i = 0; i < c.nrListeMeniuProduse; i++) {
				cout << *c.listaMeniuProduse[i];
			}
		}
		else {
			throw exception("Nr liste este negativ sau egal cu 0");
		}

		cout << "\nClientul ar dori " << c.nrRestaurant << " produs\-e, mai exact:" << endl;
		if (c.nrRestaurant > 0) {
			for (int i = 0; i < c.nrRestaurant; i++) {
				cout << *c.listaRestaurant[i];
			}
		}
		else {
			throw exception("Nr liste este negativ sau egal cu 0");
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

		if (c.listaRestaurant != nullptr)
		{
			delete[] c.listaRestaurant;
			c.listaRestaurant = nullptr;
		}

		cout << "\nNr Liste Meniu Produse: ";
		in >> c.nrListeMeniuProduse;

		c.listaMeniuProduse = new MeniuProduse * [c.nrListeMeniuProduse];
		cout << "\nLista meniu produse: " << endl;
		if (c.nrListeMeniuProduse > 0) {
			for (int i = 0; i < c.nrListeMeniuProduse; i++) {
				MeniuProduse* meniuProdus = new MeniuProduse(nullptr, 0, nullptr, 0, 0, nullptr);
				in >> *meniuProdus;
				c.listaMeniuProduse[i] = meniuProdus;
			}
		}
		else {
			cout << "Nr liste este negaitv sau egal cu 0";
		}

		cout << "\nNr Liste Restaurante: ";
		in >> c.nrRestaurant;

		c.listaRestaurant = new Restaurant * [c.nrRestaurant];
		cout << "\nLista restaurante: " << endl;
		if (c.nrRestaurant > 0) {
			for (int i = 0; i < c.nrRestaurant; i++) {
				Restaurant* restaurant = new Restaurant(nullptr, 0);
				in >> *restaurant;
				c.listaRestaurant[i] = restaurant;
			}
		}
		else {
			cout << "Nr liste este negaitv sau egal cu 0";
		}



		return in;
	}

	~ComandaClientului() {
		if (this->listaMeniuProduse != nullptr)
		{
			delete[] this->listaMeniuProduse;
			this->listaMeniuProduse = nullptr;
		}

		if (this->listaRestaurant != nullptr)
		{
			delete[] this->listaRestaurant;
			this->listaRestaurant = nullptr;
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
			ComandaClientului* comandaClientului = new ComandaClientului(0, 0, nullptr, 0, nullptr);
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


int main()
{
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
	Ingrediente* listaIngrediente1[] = { &i1, &i2, &i3, &i6, &i7, &i8 };
	Ingrediente* listaIngrediente2[] = { &i9,&i10, &i11, &i12 };
	Ingrediente* listaIngrediente3[] = { &i12,&i13,&i14 };
	Ingrediente* listaIngrediente4[] = { &i13,&i15,&i16 };
	CategorieProduse categorieProduse[] = { CategorieProduse::MicDejun, CategorieProduse::Pranz, CategorieProduse::Cina };
	MeniuProduse m1("Hamburger", 3, categorieProduse, 45, 3, listaIngrediente1);
	MeniuProduse m2("Cheeseburger", 3, categorieProduse, 50, 5, listaIngrediente1);
	MeniuProduse m3("Wooper", 3, categorieProduse, 60, 6, listaIngrediente1);
	MeniuProduse m4("Apa", 3, categorieProduse, 7, 1, listaIngrediente2);
	MeniuProduse m5("Limonada", 3, categorieProduse, 14, 2, listaIngrediente2);
	MeniuProduse m6("Suc-de-fructe", 3, categorieProduse, 16, 4, listaIngrediente2);
	MeniuProduse m7("Prajitura", 3, categorieProduse, 20, 3, listaIngrediente3);
	MeniuProduse m8("Espresso", 2, categorieProduse, 12, 2, listaIngrediente4);
	MeniuProduse m9("Latte", 2, categorieProduse, 14, 3, listaIngrediente4);
	MeniuProduse* listaM[] = { &m9, &m2 };
	MeniuProduse* listaTotala[] = { &m1, &m2, &m3, &m4, &m5,&m6,&m7, &m8,&m9 };
	Restaurant* listaRestaurante[] = { &r };
	ComandaClientului c(1, 2, listaM, 1, listaRestaurante);
	ComandaClientului* comandaClientului[] = { &c };
	Livrare l("Andrei", 1, comandaClientului, true, 10);


	cout << "***********************************************************" << endl;
	cout << "Bine ati venit la " << r.getNumeRestaurant() << "!";
	cout << "\nPentru a accesa meniul, apasati tasta 1 si apoi enter: ";

	char key;
	cin >> key;

	if (key == '1') {
		cout << endl << "***********************<< MENIU >>*************************" << endl;
		cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl << m5 << endl << m6 << endl << m7 << endl << m8 << endl << m9 << endl;
	}
	else {
		cout << "\nAti apasat o tasta diferita de 1 si meniu nu a fost accesat" << endl << endl;
	}


	int nrComenzi;
	cout << "Introduceti cate comenzi veti realiza: ";
	cin >> nrComenzi;

	for (int k = 0; k < nrComenzi; k++) {
		int pretTotalComanda = 0;
		int nrProduse;
		cout << "Introduceti cate produse doriti sa achizitionati: ";
		cin >> nrProduse;

		for (int i = 0; i < nrProduse; i++) {
			string numeProdus;
			cout << "Introduceti numele produsului " << i + 1 << ": ";
			cin >> numeProdus;

			MeniuProduse* produsSelectat = nullptr;
			for (int j = 0; j < sizeof(listaTotala) / sizeof(listaTotala[0]); j++) {
				if (listaTotala[j]->getDenumireProdus() == numeProdus) {
					produsSelectat = listaTotala[j];
					break;
				}
			}
			if (produsSelectat != nullptr) {
				cout << "Ati selectat produsul:\n" << *produsSelectat << endl;

				char adaugaComanda;
				cout << "Doriti sa adaugati acest produs la comanda? (y/n): ";
				cin >> adaugaComanda;

				if (adaugaComanda == 'y' || adaugaComanda == 'Y') {
					if (produsSelectat->verificaStocuri()) {
						produsSelectat->scadeCantitatea();
						cout << "Produsul a fost adaugat la comanda!" << endl;
						int pretProdus = produsSelectat->getPret();
						pretTotalComanda += pretProdus;
					}
					else {
						cout << "Nu putem adauga produsul la comanda din cauza stocurilor insuficiente" << endl << endl;
					}

					char afisare;
					cout << "Doriti sa vedeti stocul produselor odata ce a fost realizata comanda? (y/n): ";
					cin >> afisare;
					if (afisare == 'y' || afisare == 'Y')
						produsSelectat->afiseazaStoc();
				}
				else {
					cout << "Produsul nu a fost adaugat la comanda." << endl;
				}
			}
			else {
				cout << "Produsul cu numele " << numeProdus << " nu a fost gasit. Verificati caps-ul si cum l-ati scris" << endl;
			}

			cout << "Doriti sa continuati cu urmatorul produs? (y/n): ";
			char continuare;
			cin >> continuare;

			if (continuare != 'y' && continuare != 'Y') {
				break;
			}
		}

		cout << "\n--- Nota de plata pentru comanda " << k + 1 << " ---" << endl;
		cout << "\nPretul total al comenzii: " << pretTotalComanda << " RON" << endl;


	}





	// TESTARI -> NEIMPORTANT

	////Restaurant
	////constuctor cu toti parametrii
	//Restaurant r("KFC",0);
	//r.afisare();

	////set get nume restaurant
	//r.setNumeRestaurant("K.F.C.");
	//cout << "--------------------------";
	//cout << endl << r.getNumeRestaurant();

	////set get program
	//r.setProgram(true);
	//cout << endl<< "--------------------------";
	//cout << endl << r.getProgram();

	////Operator <<
	//Restaurant r1("MC");
	//r1.afisare();
	//cout << r1 << endl;

	////Constructor de copiere
	//Restaurant r2(r);
	//cout << r2;


	////Operator =
	//r = r1;
	//cout << r;

	////Operator >>
	//cin >> r1;
	//cout << r1;


	////Ingrediente

	////constructor cu toti parametrii
	//Ingrediente i("Mere", 3);
	//i.afisare();

	////constructor doar cu un parametru
	//Ingrediente i1("Ardei");
	//i1.afisare();

	////set get DenumireIngredient
	//i.setDenumireIngredient("Pere");
	//cout << endl << "---------------------------------";
	//cout << endl << i.getDenumireIngredient();

	////set get cantitate
	//i1.setCantitate(30);
	//cout << endl << "---------------------------------";
	//cout << endl << i1.getCantitate();

	////constructor copy
	//Ingrediente i2(i1);
	//i2.afisare();

	////operator <<
	//Ingrediente i3("Zahar");
	//cout << i3;

	////operator =
	//Ingrediente i4("Sare", 200);
	//cout << i4;
	//i4 = i3;
	//cout << i4;

	////operator >>
	///*cin >> i;
	//cout << i;*/

	////operator --
	//--i;
	//cout << i.getCantitate();

	////MeniuProduse
	//CategorieProduse categorieProduse[] = { CategorieProduse::MicDejun, CategorieProduse::Pranz, CategorieProduse::Cina };
	//Ingrediente i4("Zahar", 3);
	//Ingrediente i5("Lapte", 2);
	//Ingrediente i6("Boabe de cafea", 4);
	//Ingrediente* listaIngrediente[3] = { &i6,&i4,&i5 };

	////constructor cu toti parametrii
	//MeniuProduse m("Cafea", 3, categorieProduse, 12, 3, listaIngrediente);
	//m.afisare();

	////constructor cu 3 parametrii
	//MeniuProduse m1("Expresso", 2, listaIngrediente);
	////m1.afisare();

	////set get denumire produs
	//m.setDenumireProdus("Ceai");
	//cout << m.getDenumireProdus()<<endl;

	////set get pret
	//m.setPret(10);
	//cout << m.getPret() << endl;

	////set get NrCategorieProduse
	//m.setNrCategorieProduse(2);
	//cout << m.getNrCategorieProduse() << endl;

	////set categorie produse
	//CategorieProduse categorieProduse1[] = { CategorieProduse::MicDejun, CategorieProduse::Pranz};
	//m.setCategorieProduse(categorieProduse1);
	//for (int i = 0; i < 2; i++) {
	//	cout << m.getCategorieProduse()[i] << " ";
	//}

	////set get lista ingrediente
	//Ingrediente i7("Plic de ceai", 5);
	//Ingrediente i8("Miere", 3);
	//Ingrediente* listaIngredienteCeai[2] = { &i7,&i8 };
	//m.setListaIngrediente(2,listaIngredienteCeai);
	//for (int i = 0; i < 2; i++) {
	//	cout << endl << *m.getListaIngrediente()[i];
	//}

	////constructor copy
	///*MeniuProduse m4(m);
	//m.afisare();
	//m4.afisare();*/

	////operator = si operator <<
	///*m1 = m;
	//m1.afisare();
	//cout << m1;*/
	//
	////operator >>
	//cin >> m;
	//cout << m;

	////operator []
	//cout << ">>>>>>>>>>>>>>>>>>>INDEXAREA<<<<<<<<<<<<<<<<<<<<" << endl;
	//cout << *m[1];

	////operator cast
	//int pret = m;
	//cout << pret;

	////operator >
	//if (m > m1) {
	//	cout << "m mai mare decat m1" << endl;
	//}
	//else {
	//	cout << "m mai mic decat m1" << endl;
	//}
	//
	////operator ==
	//MeniuProduse m2("Expresso", 2, listaIngrediente);
	//if (m1 == m2)
	//{
	//	cout << "m1 e egal cu m2" << endl;
	//}
	//else {
	//	cout << "m1 NU e egal cu m2" << endl;
	//}



	////Comanda Clientului
	//Restaurant r("Modelier", 1);
	//Restaurant* listaRestaurante[] = { &r };
	//CategorieProduse categorieProduse[] = { CategorieProduse::MicDejun, CategorieProduse::Pranz, CategorieProduse::Cina };
	//Ingrediente i4("Zahar", 3);
	//Ingrediente i5("Lapte", 2);
	//Ingrediente i6("Boabe de cafea", 4);
	//Ingrediente* listaIngredienteCafea[3] = { &i6,&i4,&i5 };
	//MeniuProduse m1("Cafea", 3, categorieProduse, 12, 3, listaIngredienteCafea);

	//Ingrediente i7("Plic de ceai", 5);
	//Ingrediente i8("Miere", 3);
	//Ingrediente* listaIngredienteCeai[2] = { &i7,&i8 };
	//MeniuProduse m2("Ceai", 3, categorieProduse, 10, 2, listaIngredienteCeai);

	//MeniuProduse* meniuProduse[2] = { &m1, &m2 };

	////constructor cu toti parametrii
	//ComandaClientului c(1, 1, meniuProduse, 1, listaRestaurante);
	////c.afisare();

	////constructor doar cu un parametru
	//ComandaClientului c1(2, 2, meniuProduse, 1, listaRestaurante);
	///*c1.afisare();*/

	////set get nrListeMeniuProduse
	///*c1.setNrListeMeniuProduse(0);
	//cout << c1.getNrListeMeniuProduse();*/

	//////set get listaMeniuProduse
	////MeniuProduse* meniuProduse1[1] = { &m1 };
	////c1.setListaMeniuProduse(1, meniuProduse);
	////for (int i = 0; i < 1; i++) {
	////	cout << *c.getListaMeniuProduse()[i]<<" ";
	////}

	//////constructor copy
	////ComandaClientului c2(c1);
	////c1.afisare();
	////c2.afisare();

	////operator = si <<
	////cout << c;
	//
	////operator >>
	///*cin >> c;
	//cout << c;*/


	////Livrare
	//ComandaClientului* comandaClientului[2] = {&c,&c1};
	////constructor cu toti parametrii
	//Livrare l("Gabi", 1, comandaClientului, true, 2);
	////l.afisare();

	////constructor cu 3 parametrii
	//Livrare l1("Matei", 2, comandaClientului);
	////l1.afisare();

	////get set nume
	//l1.setNumeClient("Andrei");
	//cout << l1.getNumeClient() << endl;

	////get set nr liste comenzi
	//l1.setNrListaComenzi(1);
	//cout << l1.getNrListaComenzi() << endl;

	////get set liste comenzi
	///*l1.setListaComenzi(1,comandaClientului);
	//for (int i = 0; i < 1; i++)
	//{
	//	cout << *l1.getListaComenzi()[i];
	//}*/

	////set get bacsis
	//l1.setBacsis(true);
	//cout << l1.getBacsis() << endl;

	////set get valoare bacsis
	//l1.setValBacsis(10);
	//cout << l1.getValBacsis() << endl;

	////constructor copy
	///*Livrare l2(l1);
	//l1.afisare();
	//l2.afisare();*/

	////operator =
	///*l = l1;
	//cout << l1 << endl;
	//cout << l << endl;*/

	////operator <<
	///*cin >> l;
	//cout << l;*/

	////operator +
	//Livrare l2("Ioana", 1, comandaClientului, true, 7);
	//Livrare bacsis = l + l2;
	//cout << bacsis.getValBacsis();

	////operator !
	//if (!l) {
	//	cout << "Livrarea nu are bacsis." <<endl;
	//}
	//else {
	//	cout << "Livrarea are bacsis." << endl;
	//}
	return 0;
}

