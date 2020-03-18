#pragma once
#include "GymExercise.h"

class Repo
{
private:
	GymExercise gymExercises[101];
	int n;
public:
	Repo();
	~Repo();
	void addGymExercise(GymExercise g);
	GymExercise* getAll();
};