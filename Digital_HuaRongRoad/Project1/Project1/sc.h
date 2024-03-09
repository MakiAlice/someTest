#pragma once
#include<iostream>
#include<graphics.h>
using namespace std;

class hrd;

class sc
{
public:
	sc();
	int step;
	int offx; int offy;
	int j0; int i0; int k0; int x0; int y0;
	void beijing();
	void shuchu(hrd h);
	bool jiance(hrd h);
	~sc();
};

#include"hrd.h"
