/*在赋值语句中,若目标测变量类型与右侧不同,则赋值时自动发生类型转换*/
/*类型转换的规则:将右侧表达式的值转换成左侧变量*/
/*下面是一个例子*/
#include<stdio.h>
int main()
{
    int     n=256;
    float   f=3.6;          /*此处在VC6.0会有警告,float型常量隐含按double型处理,在后面赋值时可能会出现截断错误*/
    double  d=2.5;
    n=f;                    /*这里类型转换导致f小数部分丢失,因为整型常量只能接收整数部分*/
    f=n;                    /*这里不存在数据丢失问题,但也不会使数据精度增加,只是改变了形式,下一行同*/
    d=f;
    printf("n=%d\n",n);
    printf("f=%f\n",f);
    printf("d=%f\n",d);
}
/*从以上不难看出C语言支持类型自动转换,但更多的是带来错误隐患,在某些情况下会引发数据信息丢失,类型溢出的错误*/
