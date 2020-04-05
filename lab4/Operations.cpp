#include "Operations.h"
#include "GymExercise.h"
#include "Repo.h"

void  gymsByX(Repo& rep, int X, GymExercise newGyms[], int& newLen)
{
	GymExercise* gyms = rep.getAll();
	int  n = rep.getSize();
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int p = gyms[i].getReps() * gyms[i].getSeries() * gyms[i].getWeight();
		if (p > X)
			newGyms[newLen++] = gyms[i];
	}
}

void deleteGyms(Repo& rep)
{
	GymExercise* gyms = rep.getAll();
	int  n = rep.getSize();
	int k = 0;
	while (k < n)
	{
		if (gyms[k].getWeight() * gyms[k].getReps() < 5)
		{
			rep.deleteGymExercise(k);
			n = rep.getSize();
			k = 0;
		}
		else
			k++;
	}
}