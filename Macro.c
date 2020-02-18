/*使用宏常量定义PI*/

#include<stdio.h>
#define PI 3.141592         /*定义宏常量PI*/
int main()
{
    double r;
    printf("input r:");
    scanf("%lf\n",&r);
    printf("C = %f\n",2*PI*r);
    printf("S = %f\n",PI*r*r);              /*编译时PI被替换成3.141592,注意:只是替换*/
}
/*宏定义中字符串后一般不以分号结尾,因为宏定义不是c语句,而是一种编译预处理*/
