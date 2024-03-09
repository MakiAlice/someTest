#pragma once
#include<iostream>
#include <string>
#include<stdio.h>

using namespace std;

struct phb
{
public:
	phb();
	int nn;
	string ID[5][10];
	int time[5][10];
	int step[5][10];
	void ph(int n,string c,double t,int s);
	void show(int n);
	~phb();
};