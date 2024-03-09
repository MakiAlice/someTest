#include"phb.h"
#include <string>
#include<graphics.h>

phb::phb()
{
	string str = "noname";
	nn = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			time[i][j] = 0;
			step[i][j] = 0;
			ID[i][j] = str;
		}
	}
}

void phb::ph(int n,string c, double t, int s)
{
	int temp1[1] = { 0 };
	int temp = 0;
	string temp2 = "noname";
	bool flag = false;
	for (int i = 0; i < 10; i++)
	{
		if (time[n-3][i]== 0)
		{
			ID[n-3][i] = c;
			time[n-3][i] = t;
			step[n-3][i] = s;
			flag = true;
			break;
	    }//如果有空位就塞入 后面要对比
	}
	for (int i = 0; i < 9; i++)
	{   
		temp = i;
		for (int j = i+1; j < 10; j++)
		{
			if (time[n-3][temp]>time[n-3][j] && time[n-3][j]!=0)
			{
				temp = j;
			}
		}
		temp1[0] = time[n - 3][i];
		time[n - 3][i] = time[n - 3][temp];
		time[n - 3][temp] = temp1[0];
		temp1[0] = step[n - 3][i];
		step[n - 3][i] = step[n - 3][temp];
		step[n - 3][temp] = temp1[0];
		temp2 = ID[n - 3][i]; 
		ID[n - 3][i] = ID[n - 3][temp]; 
		ID[n - 3][temp] = temp2;
	}
	if (flag == false)//说明没有空位
	{
		for (int i = 0; i < 10; i++)
		{
			if (time[n - 3][i] > t)
			{
				for (int j = 9; j > i; j--)
				{
					time[n - 3][j] = time[n - 3][j - 1];
					step[n - 3][j] = step[n - 3][j - 1];
					ID[n - 3][j] = ID[n - 3][j - 1];
				}
				time[n - 3][i] = t;
				step[n - 3][i] = s;
				ID[n - 3][i] = c;
			}
		}
	}
}

void phb::show(int n)
{   
	closegraph();
	printf("%d×%d难度排行榜\n", n, n);
	printf("ID             时间           步数\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%-15s%-15d%-15d\n", ID[n-3][i].c_str(), time[n-3][i], step[n-3][i]);//printf输出的字符串是char*  string中c_str()成员方法返回当前字符串的首字符地址
	}
	system("pause");
}

phb::~phb()
{

}