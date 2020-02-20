/*计算级数e^x = 1+x/1!+x^2/2!+···+x*n/n!的值*/
/*要求:采用函数调用
  一个实现n!
  一个实现x*n
*/
#include<stdio.h>
#include<math.h>

long Fact(int m)            //定义递归函数求n!的值
{
    if(m == 0)
    {
        return 1;
    }
    else
    {
        return m * Fact(m-1);
    }
}

int main()
{
    int x,n,i;
    double y = 0;
    printf("input the value of x:");
    scanf("%d",&x);
    printf("input the value of n:");
    scanf("%d",&n);
    if(n < 0)                           //对不合理数据的处理
    {
        printf("input data error!");
    }
    else
    {
        for(i = 0; i <= n; i++)
        {
            y += pow(x,i)/Fact(i);
        }
    }
    printf("e^x = %lf",y);
}
