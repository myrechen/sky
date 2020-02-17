/*使用强制类型转换运算符,这是一个一元运算符*/
/*形式:(类型) 表达式*/
/*强转有助于消除隐式自转导致的程序隐患*/
#include<stdio.h>
int main()
{
    int m=5;
    printf("m/2=%d\n",m/2);
    printf("(float)(m/2)=%f\n",(float)(m/2));
    printf("(float)m/2=%f\n",(float)m/2);
    printf("m=%d\n",m);
}
