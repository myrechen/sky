/*宏常量没有数据类型,编译时不进行类型检查,只进行简单替换,易发生错误*/
/*此时用const声明某种类型的常量*/

#include<stdio.h>
int main()
{
    const double PI = 3.141592;             /*标识符与字符串之间加入了等号,且结尾有分号*/
    double r;
    printf("input r:");
    scanf("%lf",&r);
    printf("C = %f\n,S = %f\n",2*PI*r,PI*r*r);
}
