/*�곣��û����������,����ʱ���������ͼ��,ֻ���м��滻,�׷�������*/
/*��ʱ��const����ĳ�����͵ĳ���*/

#include<stdio.h>
int main()
{
    const double PI = 3.141592;             /*��ʶ�����ַ���֮������˵Ⱥ�,�ҽ�β�зֺ�*/
    double r;
    printf("input r:");
    scanf("%lf",&r);
    printf("C = %f\n,S = %f\n",2*PI*r,PI*r*r);
}
