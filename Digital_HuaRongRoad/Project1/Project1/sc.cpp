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
    loadimage(&img, "\\paper\\2.jpg", 1276 * 0.5, 1920 * 0.5, true);//true��ʾ�ȱ�����С bool bResize = false   �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
    putimage(0, 0, &img);
}



void sc::shuchu(hrd h)
{
    int n = h.n;
    IMAGE im;
    int x, y;
    const char* p[49] =
    { "\\paper\\sz0.jpg","\\paper\\sz1.jpg","\\paper\\sz2.jpg","\\paper\\sz3.jpg","\\paper\\sz4.jpg","\\paper\\sz5.jpg","\\paper\\sz6.jpg","\\paper\\sz7.jpg","\\paper\\sz8.jpg","\\paper\\sz9.jpg",
      "\\paper\\sz10.jpg","\\paper\\sz11.jpg","\\paper\\sz12.jpg","\\paper\\sz13.jpg","\\paper\\sz14.jpg","\\paper\\sz15.jpg","\\paper\\sz16.jpg","\\paper\\sz17.jpg","\\paper\\sz18.jpg","\\paper\\sz19.jpg",
      "\\paper\\sz20.jpg","\\paper\\sz21.jpg","\\paper\\sz22.jpg","\\paper\\sz23.jpg","\\paper\\sz24.jpg","\\paper\\sz25.jpg","\\paper\\sz26.jpg","\\paper\\sz27.jpg","\\paper\\sz28.jpg","\\paper\\sz29.jpg",
      "\\paper\\sz30.jpg","\\paper\\sz31.jpg","\\paper\\sz32.jpg","\\paper\\sz33.jpg","\\paper\\sz34.jpg","\\paper\\sz35.jpg","\\paper\\sz36.jpg","\\paper\\sz37.jpg","\\paper\\sz38.jpg","\\paper\\sz39.jpg",
      "\\paper\\sz40.jpg","\\paper\\sz41.jpg","\\paper\\sz42.jpg","\\paper\\sz43.jpg","\\paper\\sz44.jpg","\\paper\\sz45.jpg","\\paper\\sz46.jpg","\\paper\\sz47.jpg","\\paper\\sz48.jpg"};//��VS2019�Ժ�İ汾 ����ֱ������char * ������������ʱ���������const char*�����͵�ֵ�������ڳ�ʼ����char�����͵�ʵ�塱
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
        loadimage(&img, "\\paper\\tg.jpg", 400, 200, true);
        putimage(100, 330, &img);
        return true;
    }
    return false;
}

sc::~sc()
{

}