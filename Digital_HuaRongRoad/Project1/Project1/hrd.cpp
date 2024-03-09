#include "hrd.h"
#include<ctime>

hrd::hrd()
{
    in = 0;
    n = 0;
}

void hrd::shengcheng(int n)
{
    this->n = n;
    for (int i = 0; i < n * n - 1; i++)
    {
        this->A[i] = i + 1;
    }
    this->A[n * n - 1] = 0;
}

void hrd::luanxu()
{
    srand((unsigned)time(NULL));
    int n = this->n;
    int max = n * n - 1;
    int m = 0;
    int temp;
    int A[49];
    for (int i = 0; i < n * n; i++)
    {
        A[i] = this->A[i];
    }
    while (max != 0)
    {
        temp = rand() / (int)(RAND_MAX / max);//生成一个0到max的随机数，类型为int
        this->B[m] = A[temp];
        m++;
        if (temp == max)
        {
            max--;
        }
        else
        {
            for (int i = temp; i < max; i++)
            {
                A[i] = A[i + 1];
            }//因为数组的连续性，用后一位覆盖前一位
            max--;
        }
    }
    this->B[n * n - 1] = A[0];
}

bool hrd::jiance()
{
    int in = 0;
    int n = this->n;
    int max = n * n - 1;
    int m=0;
    int f;
    for (int i = 0; i < max; i++)
    {
        for (int j = i + 1; j < max + 1; j++)
        {
            if (this->B[i] > this->B[j] && this->B[j]!=0)
            {
                in++;
            }
        }
    }
    f = in % 2;
    for (int i = 0; i < max + 1; i++)
    {
        if (this->B[i] == 0)
            m = n - 1 - i / n;
    }
    if (n % 2 == 1)
    {
        if (f == 0)
        {
            this->in = in;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (m % 2 == f)
        {
            this->in = in;
            return true;
        }
        else
        {
            return false;
        }
    }
}


hrd::~hrd()
{

}