#include "Aplicatie.h"
#include <string.h>
#include <ostream>

using namespace std;

Aplicatie::Aplicatie()
{
	this->nume = NULL;
	this->consumMemorieKb = 0;
	this->status = NULL;
}

Aplicatie::Aplicatie(char* nume, int consumMemorieKb, char* status)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Aplicatie::Aplicatie(const Aplicatie& g)
{
	this->nume = new char[strlen(g.nume) + 1];
	strcpy_s(this->nume, strlen(g.nume) + 1, g.nume);
	this->consumMemorieKb = g.consumMemorieKb;
	this->status = new char[strlen(g.status) + 1];
	strcpy_s(this->status, strlen(g.status) + 1, g.status);
}

Aplicatie::~Aplicatie()
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
}

char* Aplicatie::getNume()
{
	return this->nume;
}

int Aplicatie::getConsumMemorieKb()
{
	return this->consumMemorieKb;
}

char* Aplicatie::getStatus()
{
	return this->status;
}

void Aplicatie::setNume(char* nume)
{
	if (this->nume)
		delete[] this->nume;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Aplicatie::setConsumMemorieKb(int consumMemorieKb)
{
	this->consumMemorieKb = consumMemorieKb;
}

void Aplicatie::setStatus(char* status)
{
	if (this->status)
		delete[] this->status;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Aplicatie& Aplicatie::operator=(const Aplicatie& g)
{
	this->setNume(g.nume);
	this->setConsumMemorieKb(g.consumMemorieKb);
	this->setStatus(g.status);
	return *this;
}

bool Aplicatie::operator==(const Aplicatie& g)
{
	return strcmp(this->nume, g.nume) == 0 && this->consumMemorieKb == g.consumMemorieKb && strcmp(this->status, g.status) == 0;
}

ostream& operator<<(ostream& os, const Aplicatie& g)
{
	os << "Nume: " << g.nume << " " << "Consum memorie KB: " << g.consumMemorieKb << " " << "Status: " << g.status;
	return os;
}
