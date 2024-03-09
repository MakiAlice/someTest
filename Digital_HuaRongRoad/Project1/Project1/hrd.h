#pragma once
#include<stdbool.h>
#include<iostream>
using namespace std;

class hrd
{
public:
    int n;
    int in;//INÊÇÄÚÖÃº¯Êı
    int A[49];
    int B[49];
    hrd();
    void shengcheng(int n);
    void luanxu();
    bool jiance();
    ~hrd();
};