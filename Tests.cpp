#include "Tests.h"
#include <assert.h>
#include <string.h>
#include "GymExercise.h"
#include "Repo.h"
#include <iostream>

void tests()
{
	GymExercise gymExercises[3];
	char* name1 = new char[10];
	char* name2 = new char[10];
	char* name3 = new char[10];

	strcpy_s(name1, sizeof "gantere", "gantere");
	GymExercise g1(name1, 2, 10, 20);

	strcpy_s(name2, sizeof "haltera", "haltera");
	GymExercise g2(name2, 2, 10, 40);

	strcpy_s(name1, sizeof "discuri", "discuri");
	GymExercise g3(name1, 3, 15, 15);

	gymExercises[0] = g1;
	gymExercises[1] = g2;
	gymExercises[2] = g3;

	assert(gymExercises[0] == g1);
	assert(gymExercises[1] == g2);
	assert(gymExercises[2] == g3);
	cout << "Teste complete!" << '\n';
}
