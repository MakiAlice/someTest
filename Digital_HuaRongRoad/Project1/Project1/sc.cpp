#include"sc.h"//#include<xx.h> ��ʾֱ�Ӵӱ������Դ��ĺ�������Ѱ���ļ�,�������ӱ�׼��·����ʼ����.xxh  �������Զ���ͷ�ļ���ʼ��
#include<graphics.h>
#include<conio.h>//�������ͼ�ε�ͷ�ļ�����������ֻ���������
#include<math.h>
#include<time.h>


sc::sc()
{
   offx = 19;
   offy = 180;
   x0 = 0;
   y0 = 0;
   k0 = 0;
   j0 = 0;
   i0 = 0;
   step = 0;
}

void sc::beijing()
{
    IMAGE img;
    initgraph(1277 * 0.5, 1920 * 0.5);
    loadimage(&img, "/someTest/Digital_HuaRongRoad/2.jpg", 1276 * 0.5, 1920 * 0.5, true);//true��ʾ�ȱ�����С bool bResize = false   �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
    putimage(0, 0, &img);
}



void sc::shuchu(hrd h)
{
    int n = h.n;
    IMAGE im;
    int x, y;
    const char* p[49] =
    { "/someTest/Digital_HuaRongRoad/sz0.jpg","/someTest/Digital_HuaRongRoad/sz1.jpg","/someTest/Digital_HuaRongRoad/sz2.jpg","/someTest/Digital_HuaRongRoad/sz3.jpg","/someTest/Digital_HuaRongRoad/sz4.jpg","/someTest/Digital_HuaRongRoad/sz5.jpg","/someTest/Digital_HuaRongRoad/sz6.jpg","/someTest/Digital_HuaRongRoad/sz7.jpg","/someTest/Digital_HuaRongRoad/sz8.jpg","/someTest/Digital_HuaRongRoad/sz9.jpg",
      "/someTest/Digital_HuaRongRoad/sz10.jpg","/someTest/Digital_HuaRongRoad/sz11.jpg","/someTest/Digital_HuaRongRoad/sz12.jpg","/someTest/Digital_HuaRongRoad/sz13.jpg","/someTest/Digital_HuaRongRoad/sz14.jpg","/someTest/Digital_HuaRongRoad/sz15.jpg","/someTest/Digital_HuaRongRoad/sz16.jpg","/someTest/Digital_HuaRongRoad/sz17.jpg","/someTest/Digital_HuaRongRoad/sz18.jpg","/someTest/Digital_HuaRongRoad/sz19.jpg",
      "/someTest/Digital_HuaRongRoad/sz20.jpg","/someTest/Digital_HuaRongRoad/sz21.jpg","/someTest/Digital_HuaRongRoad/sz22.jpg","/someTest/Digital_HuaRongRoad/sz23.jpg","/someTest/Digital_HuaRongRoad/sz24.jpg","/someTest/Digital_HuaRongRoad/sz25.jpg","/someTest/Digital_HuaRongRoad/sz26.jpg","/someTest/Digital_HuaRongRoad/sz27.jpg","/someTest/Digital_HuaRongRoad/sz28.jpg","/someTest/Digital_HuaRongRoad/sz29.jpg",
      "/someTest/Digital_HuaRongRoad/sz30.jpg","/someTest/Digital_HuaRongRoad/sz31.jpg","/someTest/Digital_HuaRongRoad/sz32.jpg","/someTest/Digital_HuaRongRoad/sz33.jpg","/someTest/Digital_HuaRongRoad/sz34.jpg","/someTest/Digital_HuaRongRoad/sz35.jpg","/someTest/Digital_HuaRongRoad/sz36.jpg","/someTest/Digital_HuaRongRoad/sz37.jpg","/someTest/Digital_HuaRongRoad/sz38.jpg","/someTest/Digital_HuaRongRoad/sz39.jpg",
      "/someTest/Digital_HuaRongRoad/sz40.jpg","/someTest/Digital_HuaRongRoad/sz41.jpg","/someTest/Digital_HuaRongRoad/sz42.jpg","/someTest/Digital_HuaRongRoad/sz43.jpg","/someTest/Digital_HuaRongRoad/sz44.jpg","/someTest/Digital_HuaRongRoad/sz45.jpg","/someTest/Digital_HuaRongRoad/sz46.jpg","/someTest/Digital_HuaRongRoad/sz47.jpg","/someTest/Digital_HuaRongRoad/sz48.jpg"};//��VS2019�Ժ�İ汾 ����ֱ������char * ������������ʱ���������const char*�����͵�ֵ�������ڳ�ʼ����char�����͵�ʵ�塱
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = i * n + j;
            if(h.B[k]==0)
            {
                loadimage(&im, p[h.B[k]], 600 / n, 600 / n, true);
                x = offx + 600 * j / n;
                y = offy + 600 * i / n;
                this->j0 = j;
                this->i0 = i;
                this->k0 = k;
                this->x0 = x;
                this->y0 = y;
                putimage(x, y, &im);
            }
            else
            {
                loadimage(&im, p[h.B[k]], 600 / n, 600 / n, true);//loadimage��graphics.h�ĺ�������LoadImage��Winuser.h��
                x = offx + 600 * j / n;
                y = offy + 600 * i / n;
                putimage(x, y, &im);
            }
        }
    }
}


bool sc::jiance(hrd h)
{
    int n = h.n;
    int max = n * n;
    bool flag=true;
    IMAGE img;
    for (int i = 0; i < max; i++)
    {
        if (h.A[i] != h.B[i]) 
            flag=false;
    }
    if (flag == true)
    {
        loadimage(&img, "/someTest/Digital_HuaRongRoad/tg.jpg", 400, 200, true);
        putimage(100, 330, &img);
        return true;
    }
    return false;
}

sc::~sc()
{

}