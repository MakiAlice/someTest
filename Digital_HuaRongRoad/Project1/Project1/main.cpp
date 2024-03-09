#include<iostream>
#include"hrd.h"
#include"sc.h"
#include"phb.h"
#include<time.h>
#include <windows.h>
#include<stdio.h>
#include <fstream> 
#include<thread>//多线程
#include<mmsystem.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")//导入winmm windows multy media库

using namespace std;

void yidong(hrd* h, sc* s, MOUSEMSG msg)
{
    int n = h->n;
    int offx = s->offx;
    int offy = s->offy;
    IMAGE img1; IMAGE img2; 
    int A[1] = { 0 };
    const char* p[49] =
    { "/someTest/Digital_HuaRongRoad/sz0.jpg","/someTest/Digital_HuaRongRoad/sz1.jpg","/someTest/Digital_HuaRongRoad/sz2.jpg","/someTest/Digital_HuaRongRoad/sz3.jpg","/someTest/Digital_HuaRongRoad/sz4.jpg","/someTest/Digital_HuaRongRoad/sz5.jpg","/someTest/Digital_HuaRongRoad/sz6.jpg","/someTest/Digital_HuaRongRoad/sz7.jpg","/someTest/Digital_HuaRongRoad/sz8.jpg","/someTest/Digital_HuaRongRoad/sz9.jpg",
      "/someTest/Digital_HuaRongRoad/sz10.jpg","/someTest/Digital_HuaRongRoad/sz11.jpg","/someTest/Digital_HuaRongRoad/sz12.jpg","/someTest/Digital_HuaRongRoad/sz13.jpg","/someTest/Digital_HuaRongRoad/sz14.jpg","/someTest/Digital_HuaRongRoad/sz15.jpg","/someTest/Digital_HuaRongRoad/sz16.jpg","/someTest/Digital_HuaRongRoad/sz17.jpg","/someTest/Digital_HuaRongRoad/sz18.jpg","/someTest/Digital_HuaRongRoad/sz19.jpg",
      "/someTest/Digital_HuaRongRoad/sz20.jpg","/someTest/Digital_HuaRongRoad/sz21.jpg","/someTest/Digital_HuaRongRoad/sz22.jpg","/someTest/Digital_HuaRongRoad/sz23.jpg","/someTest/Digital_HuaRongRoad/sz24.jpg","/someTest/Digital_HuaRongRoad/sz25.jpg","/someTest/Digital_HuaRongRoad/sz26.jpg","/someTest/Digital_HuaRongRoad/sz27.jpg","/someTest/Digital_HuaRongRoad/sz28.jpg","/someTest/Digital_HuaRongRoad/sz29.jpg",
      "/someTest/Digital_HuaRongRoad/sz30.jpg","/someTest/Digital_HuaRongRoad/sz31.jpg","/someTest/Digital_HuaRongRoad/sz32.jpg","/someTest/Digital_HuaRongRoad/sz33.jpg","/someTest/Digital_HuaRongRoad/sz34.jpg","/someTest/Digital_HuaRongRoad/sz35.jpg","/someTest/Digital_HuaRongRoad/sz36.jpg","/someTest/Digital_HuaRongRoad/sz37.jpg","/someTest/Digital_HuaRongRoad/sz38.jpg","/someTest/Digital_HuaRongRoad/sz39.jpg",
      "/someTest/Digital_HuaRongRoad/sz40.jpg","/someTest/Digital_HuaRongRoad/sz41.jpg","/someTest/Digital_HuaRongRoad/sz42.jpg","/someTest/Digital_HuaRongRoad/sz43.jpg","/someTest/Digital_HuaRongRoad/sz44.jpg","/someTest/Digital_HuaRongRoad/sz45.jpg","/someTest/Digital_HuaRongRoad/sz46.jpg","/someTest/Digital_HuaRongRoad/sz47.jpg","/someTest/Digital_HuaRongRoad/sz48.jpg" };//VS换行自动加空格 导致绝对路径不准确
    int x = msg.x - offx;
    int y = msg.y - offy;
    int j = int(floor(x * n / 600));//floor函数 向下取整
    int i = int(floor(y * n / 600));
    int x1 = offx + 600 * j / n;
    int y1 = offy + 600 * i / n;
    int k = i * n + j;
    int i0 = s->i0;
    int j0 = s->j0;
    int x0 = s->x0;
    int y0 = s->y0;
    int k0 = s->k0;
    if (0<x&&x<600&&0<y&&y<600)
    {
        if (i == i0)//点击的格子和空格子在同一行
        {
            if (j <= j0&&j0 <= j + 1 || j - 1 <= j0&&j0 <= j)//点击的格子在空格子左右两边之一
            {
                loadimage(&img1, p[h->B[k0]], 600 / n, 600 / n, true);//提取空格
                putimage(x0, y0, &img1, 1);//XOR_PUT   1   图像和原有像素作异或运算
                loadimage(&img2, p[h->B[k]], 600 / n, 600 / n, true);
                putimage(x1, y1, &img2, 1);
                putimage(x0, y0, &img2);//将点击的格子移动到空格位
                putimage(x1, y1, &img1);
                s->x0 = x1;
                s->y0 = y1;
                s->k0 = k;
                s->j0 = j;
                A[0] = h->B[k0];
                h->B[k0] = h->B[k];
                h->B[k] = A[0];
                s->step++;
            }
        }
        if (j == j0)//点击的格子和空格子在同一列
        {
            if (i <= i0 && i0<= i+1 || i - 1 <= i0 && i0 <= i)//点击的格子在空格子上下两边之一  &&的优先级大于||
            {
                loadimage(&img1, p[h->B[k0]], 600 / n, 600 / n, true);//提取空格
                putimage(x0, y0, &img1, 1);//XOR_PUT   1   图像和原有像素作异或运算
                loadimage(&img2, p[h->B[k]], 600 / n, 600 / n, true);
                putimage(x1, y1, &img2, 1);
                putimage(x0, y0, &img2);//将点击的格子移动到空格位
                putimage(x1, y1, &img1);
                s->x0 = x1;
                s->y0 = y1;
                s->k0 = k;
                s->i0 = i;
                A[0] = h->B[k0];
                h->B[k0] = h->B[k];
                h->B[k] = A[0];
                s->step++;
            }
        }
        if (i == i0 && j == j0)
        {
            s->step = s->step - 2;
        }

    }
}

void shengcheng()
{
    IMAGE img1, img2, img3;
    loadimage(&img1, "/someTest/Digital_HuaRongRoad/xdks.jpg", 200, 100, true);
    putimage(200, 200, &img1);
    loadimage(&img2, "/someTest/Digital_HuaRongRoad/phb.jpg", 200, 100, true);
    putimage(200, 400, &img2);
    loadimage(&img3, "/someTest/Digital_HuaRongRoad/tc.jpg", 200, 100, true);
    putimage(200, 600, &img3);
}

void xdks()
{
    IMAGE img1, img2, img3,img4,img5;
    loadimage(&img1, "/someTest/Digital_HuaRongRoad/2.jpg", 1276 * 0.5, 1920 * 0.5, true);
    putimage(0, 0, &img1);
    loadimage(&img1, "/someTest/Digital_HuaRongRoad/n3.jpg", 150, 100, true);
    putimage(240, 100, &img1);
    loadimage(&img2, "/someTest/Digital_HuaRongRoad/n4.jpg", 150, 100, true);
    putimage(240, 250, &img2);
    loadimage(&img3, "/someTest/Digital_HuaRongRoad/n5.jpg", 150, 100, true);
    putimage(240, 400, &img3);
    loadimage(&img4, "/someTest/Digital_HuaRongRoad/n6.jpg", 150, 100, true);
    putimage(240, 550, &img4);
    loadimage(&img5, "/someTest/Digital_HuaRongRoad/n7.jpg", 150, 100, true);
    putimage(240, 700, &img5);
}

bool chongwan(MOUSEMSG msg)
{
    IMAGE img;
    loadimage(&img, "/someTest/Digital_HuaRongRoad/cw.jpg", 150, 100, true);
    putimage(19, 800, &img);
    int x = msg.x; int y = msg.y;
    if (19 < x && x < 169 && 800 < y && y<900)
    {
        return true;
    }
    return false;
}

bool fanhui(MOUSEMSG msg)
{
    int x = msg.x; int y = msg.y;
    if (300 < x && x < 450 && 800 < y && y < 900)
    {
        return true;
    }
    return false;
}

void fanhui()
{
    IMAGE img;
    loadimage(&img, "/someTest/Digital_HuaRongRoad/fh.jpg", 150, 100, true);
    putimage(300, 800, &img);
}

void fanhui1()
{
    IMAGE img;
    loadimage(&img, "/someTest/Digital_HuaRongRoad/fh.jpg", 150, 100, true);
    putimage(240, 850, &img);
}

int dianji(MOUSEMSG msg)
{
    int x = msg.x; int y = msg.y;
    if (200 <= x && x <= 400)
    {
        if (200 <= y && y <= 300) return 1;
        if (400 <= y && y <= 500) return 2;
        if (600 <= y && y <= 700) return 3;
    }
    return 0;
}

int ndianji(MOUSEMSG msg)
{
    int x = msg.x; int y = msg.y;
    if (240 <= x && x <= 390)
    {
        if (100 <= y && y <= 200) return 3;
        if (250 <= y && y <= 350) return 4;
        if (400 <= y && y <= 500) return 5;
        if (550 <= y && y <= 650) return 6;
        if (700 <= y && y <= 800) return 7;
    }
    return 0;
}

void music()
{
    PlaySound("/someTest/Digital_HuaRongRoad/TOALICE.wav", NULL, SND_FILENAME | SND_ASYNC);
    bool sou = PlaySound("/someTest/Digital_HuaRongRoad/TOALICE.wav", NULL, SND_SYNC);// 同步播放声音，在播放完后PlaySound函数才返回。
    while (sou == true)
    {
        PlaySound("/someTest/Digital_HuaRongRoad/TOALICE.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
}

int main()
{
    hrd h; sc s; phb p; string ID; time_t time1, time2; 
    char c[10] = { '0' };
    char d[10]={ '0' };
    char e[10] = { '0' };
    string f = { "0" };
    double tt = 0; int i = 0; int j = 0; int i0 = 0; 
    hrd* a = &h;
    sc* b = &s;
    int t; int n;
    FILE *fp=fopen("/someTest/Digital_HuaRongRoad/Project1/Project1/phb.txt", "r");
    if (fp == nullptr)
    {
        fp = fopen("/someTest/Digital_HuaRongRoad/Project1/Project1/phb.txt", "a+");
    }
    while (fp!=nullptr && !feof(fp))//fp没有读到eof
    {   
        int end = fscanf(fp, "%d %s %d %d", &p.nn, e, &i, &j);//读取文件时，feof遇到文件结束为EOF的时候，返回的是0，到下一个字符的时
        if (end == -1) break;                                 //候，才会返回1，这时候while循环才退出,所以只用while循环就会出现重复的现象
            p.time[p.nn][i0] = i;                             
            p.step[p.nn][i0] = j;
            p.ID[p.nn][i0] = e;
            i0++;
        fscanf(fp, "/n");
    }
    if(fp!=nullptr)fclose(fp);
    label0:s.beijing();
    t = 0;
    shengcheng();
    while (t==0)
    {
        MOUSEMSG msg = GetMouseMsg();
        switch (msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            t=dianji(msg);
            break;
        }
    }
label1:n = 0;
    switch (t) 
    {
    case 1:
        xdks();
        fanhui1();
        break;
    case 2:
        xdks();
        fanhui1();
        break;
    case 3:
        return 0;
    }
    while (n == 0 && t==1)
    {
        MOUSEMSG msg = GetMouseMsg();
        switch (msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            if (fanhui(msg) == true)
            {
                goto label0;
            }
            n = ndianji(msg);
            break;
        }
    }
    while (n == 0 && t == 2)
    {
        MOUSEMSG msg = GetMouseMsg();
        switch (msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            if (fanhui(msg) == true)
            {
                goto label0;
            }
            n = ndianji(msg);
            if (n != 0)
            {
                p.show(n);
                return 0;
            }
        }
    }
    label:s.beijing();
	h.shengcheng(n);
	h.luanxu();
	while(h.jiance()!=true)
	{
		h.luanxu();
	}
	s.shuchu(h);
    thread mu(music);
    mu.detach();
    ::time(&time1);
	while (s.jiance(h) != true)
    {
        MOUSEMSG msg = GetMouseMsg();
        fanhui();
        switch (msg.uMsg)
        {
        case WM_MOUSEMOVE:
            ::time(&time2);
            tt = difftime(time2, time1);
            sprintf(c, "时间%.2f", tt);
            outtextxy(19, 90, c);
            break;
        case WM_LBUTTONDOWN:
            if (chongwan(msg) == true)
            {
                s.step = 0;
                goto label;
            } 
            if (fanhui(msg) == true)
        {
                s.step = 0;
            goto label1;
        }
            yidong(a,b,msg);
            sprintf(d, "步数%d", s.step);
            outtextxy(219, 90, d);
            ::time(&time2);
            tt = difftime(time2, time1);
            sprintf(c, "时间%.2f", tt);
            outtextxy(19, 90, c);
            break;
        }
	}
    Sleep(2000);
    closegraph();
    ::printf("请输入你的ID：");
    ::cin >> ID;
    ::printf("存储中，请勿关闭。");
    p.ph(h.n,ID, tt, s.step);
    fp = fopen("/someTest/Digital_HuaRongRoad/Project1/Project1/phb.txt", "w+");
    for(int i1 = 0;i1 < 5;i1++)
    {
       for (int j1 = 0; j1 < 10; j1++)
          {     
            f = p.ID[i1][j1];
                if (p.time[i1][j1] != 0)
                {
                    fprintf(fp, "%d %s %d %d\n", i1, f.c_str(), p.time[i1][j1], p.step[i1][j1]);
                }
          }
    }
    ::fclose(fp);
    return 0;
}