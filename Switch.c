/*当问题需要讨论的情况较多时,使用开关语句代替条件语句来简化程序设计*/
/*制作简易计算器*/
#include<stdio.h>
int main()
{
    float data1,data2;
    char op;
    printf("input an expression:");         /*输入运算表达式*/
    scanf("%f%c%f",&data1,&op,&data2);
    switch (op)                         /*根据输入的运算符确定执行的程序*/
    {
        case '+':                       /*常量与case之间至少有一个空格,后面要带上:,类型与switch后括号中的类型一致*/
            printf("%f+%f=%f\n",data1,data2,data1+data2);
            break;                          /*如果没有break语句,将依次执行后面的语句*/
        case '-':
            printf("%f-%f=%f\n",data1,data2,data1-data2);
            break;
        case '*':
            printf("%f*%f=%f\n",data1,data1,data1*data2);
            break;
        case '/':
            if(data2 == 0)                  /*避免除零错误*/
            {
                printf("error!division by 0");
            }
            else
            {
                printf("%f/%f=%f\n",data1,data2,data1/data2);
            }
            break;
        default:                             /*default后面要带上冒号.此语句处理非法运算符*/
            printf("invalid operator!\n");
    }
}
