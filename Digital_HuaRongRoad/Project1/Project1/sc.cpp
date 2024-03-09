#include"sc.h"//#include<xx.h> 表示直接从编译器自带的函数库中寻找文件,编译器从标准库路径开始搜索.xxh  “”从自定义头文件开始找
#include<graphics.h>
#include<conio.h>//输入输出图形的头文件，不包含就只会输出黑屏
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
    loadimage(&img, "\\paper\\2.jpg", 1276 * 0.5, 1920 * 0.5, true);//true表示等比例缩小 bool bResize = false   是否调整 IMAGE 的大小以适应图片
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
      "\\paper\\sz40.jpg","\\paper\\sz41.jpg","\\paper\\sz42.jpg","\\paper\\sz43.jpg","\\paper\\sz44.jpg","\\paper\\sz45.jpg","\\paper\\sz46.jpg","\\paper\\sz47.jpg","\\paper\\sz48.jpg"};//在VS2019以后的版本 对于直接利用char * 类型声明变量时会产生““const char*”类型的值不能用于初始化“char”类型的实体”
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
                loadimage(&im, p[h.B[k]], 600 / n, 600 / n, true);//loadimage是graphics.h的函数，而LoadImage是Winuser.h的
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