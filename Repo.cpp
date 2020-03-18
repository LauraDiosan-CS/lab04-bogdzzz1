#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}
void Repo::addGymExercise(GymExercise g) {
	this->gymExercises[this->n++] = g;
}

GymExercise* Repo::getAll() {
	return this->gymExercises;
}