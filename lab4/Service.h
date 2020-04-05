#pragma once
#include "Repo.h"
#include "GymExercise.h"

class Service {
private:
	Repo r;
public:
	Service();
	Service(const Service& s);
	void addGym(const GymExercise& g);
	void deleteGym(int poz);
	void updateGym(int poz, const char* name, int series, int reps, int weight);
	void gymsByXservice(int X, GymExercise gyms[], int& len);
	void deleteGymsService();
	int getSize();
	Service& operator=(const Service& r);
	GymExercise* getAll();
	~Service();
};