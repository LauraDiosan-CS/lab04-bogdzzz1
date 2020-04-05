#include <iostream>
#include <cstring>
using namespace std;
#include "Service.h"
#include "GymExercise.h"
#include "Repo.h"
#include "Operations.h"
#include "Console.h"

Console::Console() {}
Console::~Console() {}

void printMenu()
{
	cout << "1. Adaugare \n";
	cout << "2. Stergere \n";
	cout << "3. Actualizare \n";
	cout << "4. Identificarea exercitiilor in functie de X\n";
	cout << "5. Eliminarea exercitiilor care au weightKg * noOfReps < 5\n";
	cout << "6. Undo\n";
	cout << "7. Afisare \n";
	cout << "x. Exit\n";
	cout << "\n";
}

void Console::add()
{
	cout << "Numele: ";
	char* name = new char[20];
	cin >> name;

	cout << "Serii: ";
	int series = 0;
	cin >> series;

	cout << "Repetari: ";
	int reps = 0;
	cin >> reps;

	cout << "Greutate: ";
	int weight;
	cin >> weight;

	GymExercise g(name, series, reps, weight);

	this->s.addGym(g);
	cout << "\n";
}


void Console::remove()
{
	int id;
	cout << "ID de sters: ";
	cin >> id;
	cout << "\n";
	this->s.deleteGym(id);
}

void Console::update()
{
	cout << "Introduceti id(numaratoare de la 0): ";
	int index = 0;
	cin >> index;
	cout << "\n";
	cout << "Nume nou: ";
	char* name = new char[20];
	cin >> name;
	cout << "Serii noi: ";
	int series = 0;
	cin >> series;
	cout << "Repetari noi: ";
	int reps = 0;
	cin >> reps;
	cout << "Greutate noua: ";
	int weight;
	cin >> weight;
	this->s.updateGym(index, name, series, reps, weight);
}

void Console::print()
{
	GymExercise* gyms = this->s.getAll();
	int n = this->s.getSize();
	for (int i = 0; i < n; i++)
		cout << gyms[i];
	cout << "\n";
}


void Console::run()
{
	int undo = 0;
	Service copyService[101];
	char op;
	int ok = 1;
	int X;
	while (ok == 1)
	{
		printMenu();
		cout << "Introduceti optiunea: ";
		cin >> op;
		cout << "\n";
		if (op == '1')
			copyService[undo++] = this->s, this->add();
		if (op == '2')
			copyService[undo++] = this->s, this->remove();
		if (op == '3')
			copyService[undo++] = this->s, this->update();
		if (op == '4')
		{
			GymExercise newGyms[101];
			int newLen = 0;
			int X = 0;
			cout << "X = ";
			cin >> X;
			this->s.gymsByXservice(X, newGyms, newLen);
			for (int i = 0; i < newLen; i++)
				cout << newGyms[i];
			cout << "\n";
		}
		if (op == '5')
		{
			copyService[undo++] = this->s;
			this->s.deleteGymsService();
		}
		if (op == '6')
		{
			if (undo >= 0)
			{
				this->s = copyService[undo - 1];
				undo--;
				cout << "Undo realizat\n";
				cout << "\n";
			}
			else
				cout << "Undo nu se poate realiza\n";
		}
		if (op == 'p')
			this->print();
		if (op == 'x')
			break;
	}
}