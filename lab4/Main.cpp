#include <iostream>
using namespace std;
#include "tests.h"
#include "GymExercise.h"
#include "Repo.h"
#include "Console.h"
#include "Operations.h"
#include "Service.h"

int main()
{
    tests();

    Console console;
    console.run();

    return 0;
}