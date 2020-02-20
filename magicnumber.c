/*计算半径为5.3的圆的周长和面积*/
#include<stdio.h>
int main()
{
    double r = 5.3;
    printf("circumference = %f\n",2*3.141592*r);
    printf("area = %f\n",3.141592*r*r);
}
/*程序中用到了圆周率的值,它使用一个常数近似表示的,像这种在程序中直接使用的常数,称为幻数*/