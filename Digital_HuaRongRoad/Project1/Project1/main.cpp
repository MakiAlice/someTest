#include<iostream>
#include"hrd.h"
#include"sc.h"
#include"phb.h"
#include<time.h>
#include <windows.h>
#include<stdio.h>
#include <fstream> 
#include<thread>//���߳�
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//����winmm windows multy media��

using namespace std;

void yidong(hrd* h, sc* s, MOUSEMSG msg)
{
    int n = h->n;
    int offx = s->offx;
    int offy = s->offy;
    IMAGE img1; IMAGE img2; 
    int A[1] = { 0 };
    const char* p[49] =
    { "\\paper\\sz0.jpg","\\paper\\sz1.jpg","\\paper\\sz2.jpg","\\paper\\sz3.jpg","\\paper\\sz4.jpg","\\paper\\sz5.jpg","\\paper\\sz6.jpg","\\paper\\sz7.jpg","\\paper\\sz8.jpg","\\paper\\sz9.jpg",
      "\\paper\\sz10.jpg","\\paper\\sz11.jpg","\\paper\\sz12.jpg","\\paper\\sz13.jpg","\\paper\\sz14.jpg","\\paper\\sz15.jpg","\\paper\\sz16.jpg","\\paper\\sz17.jpg","\\paper\\sz18.jpg","\\paper\\sz19.jpg",
      "\\paper\\sz20.jpg","\\paper\\sz21.jpg","\\paper\\sz22.jpg","\\paper\\sz23.jpg","\\paper\\sz24.jpg","\\paper\\sz25.jpg","\\paper\\sz26.jpg","\\paper\\sz27.jpg","\\paper\\sz28.jpg","\\paper\\sz29.jpg",
      "\\paper\\sz30.jpg","\\paper\\sz31.jpg","\\paper\\sz32.jpg","\\paper\\sz33.jpg","\\paper\\sz34.jpg","\\paper\\sz35.jpg","\\paper\\sz36.jpg","\\paper\\sz37.jpg","\\paper\\sz38.jpg","\\paper\\sz39.jpg",
      "\\paper\\sz40.jpg","\\paper\\sz41.jpg","\\paper\\sz42.jpg","\\paper\\sz43.jpg","\\paper\\sz44.jpg","\\paper\\sz45.jpg","\\paper\\sz46.jpg","\\paper\\sz47.jpg","\\paper\\sz48.jpg" };//VS�����Զ��ӿո� ���¾���·����׼ȷ
    int x = msg.x - offx;
    int y = msg.y - offy;
    int j = int(floor(x * n / 600));//floor���� ����ȡ��
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
        if (i == i0)//����ĸ��ӺͿո�����ͬһ��
        {
            if (j <= j0&&j0 <= j + 1 || j - 1 <= j0&&j0 <= j)//����ĸ����ڿո�����������֮һ
            {
                loadimage(&img1, p[h->B[k0]], 600 / n, 600 / n, true);//��ȡ�ո�
                putimage(x0, y0, &img1, 1);//XOR_PUT   1   ͼ���ԭ���������������
                loadimage(&img2, p[h->B[k]], 600 / n, 600 / n, true);
                putimage(x1, y1, &img2, 1);
                putimage(x0, y0, &img2);//������ĸ����ƶ����ո�λ
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
        if (j == j0)//����ĸ��ӺͿո�����ͬһ��
        {
            if (i <= i0 && i0<= i+1 || i - 1 <= i0 && i0 <= i)//����ĸ����ڿո�����������֮һ  &&�����ȼ�����||
            {
                loadimage(&img1, p[h->B[k0]], 600 / n, 600 / n, true);//��ȡ�ո�
                putimage(x0, y0, &img1, 1);//XOR_PUT   1   ͼ���ԭ���������������
                loadimage(&img2, p[h->B[k]], 600 / n, 600 / n, true);
                putimage(x1, y1, &img2, 1);
                putimage(x0, y0, &img2);//������ĸ����ƶ����ո�λ
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
    loadimage(&img1, "/paper/xdks.jpg", 200, 100, true);
    putimage(200, 200, &img1);
    loadimage(&img2, "/paper/phb.jpg", 200, 100, true);
    putimage(200, 400, &img2);
    loadimage(&img3, "/paper/tc.jpg", 200, 100, true);
    putimage(200, 600, &img3);
}

void xdks()
{
    IMAGE img1, img2, img3,img4,img5;
    loadimage(&img1, "\\paper\\2.jpg", 1276 * 0.5, 1920 * 0.5, true);
    putimage(0, 0, &img1);
    loadimage(&img1, "/paper/n3.jpg", 150, 100, true);
    putimage(240, 100, &img1);
    loadimage(&img2, "/paper/n4.jpg", 150, 100, true);
    putimage(240, 250, &img2);
    loadimage(&img3, "/paper/n5.jpg", 150, 100, true);
    putimage(240, 400, &img3);
    loadimage(&img4, "/paper/n6.jpg", 150, 100, true);
    putimage(240, 550, &img4);
    loadimage(&img5, "/paper/n7.jpg", 150, 100, true);
    putimage(240, 700, &img5);
}

bool chongwan(MOUSEMSG msg)
{
    IMAGE img;
    loadimage(&img, "/paper/cw.jpg", 150, 100, true);
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
    loadimage(&img, "/paper/fh.jpg", 150, 100, true);
    putimage(300, 800, &img);
}

void fanhui1()
{
    IMAGE img;
    loadimage(&img, "/paper/fh.jpg", 150, 100, true);
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
    PlaySound("\\paper\\TOALICE.wav", NULL, SND_FILENAME | SND_ASYNC);
    bool sou = PlaySound("\\paper\\TOALICE.wav", NULL, SND_SYNC);// ͬ�������������ڲ������PlaySound�����ŷ��ء�
    while (sou == true)
    {
        PlaySound("\\paper\\TOALICE.wav", NULL, SND_FILENAME | SND_ASYNC);
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
    FILE *fp=fopen("\\paper\\Project1\\Project1\\phb.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("\\paper\\Project1\\Project1\\phb.txt", "a+");
        ::fclose(fp);
        fp = fopen("\\paper\\Project1\\Project1\\phb.txt", "r");
    }
    while (!feof(fp))//fpû�ж���eof
    {   
        int end = fscanf(fp, "%d %s %d %d", &p.nn, e, &i, &j);//��ȡ�ļ�ʱ��feof�����ļ�����ΪEOF��ʱ�򣬷��ص���0������һ���ַ���ʱ
        if (end == -1) break;                                 //�򣬲Ż᷵��1����ʱ��whileѭ�����˳�,����ֻ��whileѭ���ͻ�����ظ�������
            p.time[p.nn][i0] = i;                             
            p.step[p.nn][i0] = j;
            p.ID[p.nn][i0] = e;
            i0++;
        fscanf(fp, "/n");
    }
    ::fclose(fp);
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
            sprintf(c, "ʱ��%.2f", tt);
            outtextxy(19, 90, c);
            break;
        case WM_LBUTTONDOWN:
            if (chongwan(msg) == true)
            {
                goto label;
            } 
            if (fanhui(msg) == true)
        {
            goto label1;
        }
            yidong(a,b,msg);
            sprintf(d, "����%d", s.step);
            outtextxy(219, 90, d);
            ::time(&time2);
            tt = difftime(time2, time1);
            sprintf(c, "ʱ��%.2f", tt);
            outtextxy(19, 90, c);
            break;
        }
	}
    Sleep(2000);
    closegraph();
    ::printf("���������ID��");
    ::cin >> ID;
    ::printf("�洢�У�����رա�");
    p.ph(h.n,ID, tt, s.step);
    fp = fopen("\\paper\\Project1\\Project1\\phb.txt", "w+");
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