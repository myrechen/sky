/*���㼶��e^x = 1+x/1!+x^2/2!+������+x*n/n!��ֵ*/
/*Ҫ��:���ú�������
  һ��ʵ��n!
  һ��ʵ��x*n
*/
#include<stdio.h>
#include<math.h>

long Fact(int m)            //����ݹ麯����n!��ֵ
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
    if(n < 0)                           //�Բ��������ݵĴ���
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
