#pragma once
#include <string>
#include <iostream>
#include "utils.h"
using namespace std;
struct Income_Sources {
	string ID;
	string Name;
	Income_Sources* them(Income_Sources* A, int &n, int &size);
	Income_Sources* xoa(Income_Sources* A, int &n);
	Income_Sources* edit(Income_Sources* A, int &n);
	Income_Sources* move(Income_Sources* A, int &n);
};