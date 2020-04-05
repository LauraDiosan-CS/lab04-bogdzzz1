#include "tests.h"
#include "Aplicatie.h"
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

void testAplicatie()
{
	char* name = new char[10];
	char* status = new char[10];
	int consumMemorieKB;
	strcpy_s(name,8, "windows");
	strcpy_s(status,4, "bun");
	consumMemorieKB = 10;
	Aplicatie a1(name, consumMemorieKB, status);
	assert(a1.getConsumMemorieKb() == 10);
	assert(strcmp(a1.getNume(),"windows")==0);
	assert(strcmp(a1.getStatus(),"bun")==0);
	strcpy_s(name,4, "iOS");
	a1.setNume(name);
	assert(strcmp(a1.getNume(),"iOS")==0);
	Aplicatie a2 = a1;
	assert(a2 == a1);
	cout << "Teste complete!";
}