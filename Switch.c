/*��������Ҫ���۵�����϶�ʱ,ʹ�ÿ�������������������򻯳������*/
/*�������׼�����*/
#include<stdio.h>
int main()
{
    float data1,data2;
    char op;
    printf("input an expression:");         /*����������ʽ*/
    scanf("%f%c%f",&data1,&op,&data2);
    switch (op)                         /*��������������ȷ��ִ�еĳ���*/
    {
        case '+':                       /*������case֮��������һ���ո�,����Ҫ����:,������switch�������е�����һ��*/
            printf("%f+%f=%f\n",data1,data2,data1+data2);
            break;                          /*���û��break���,������ִ�к�������*/
        case '-':
            printf("%f-%f=%f\n",data1,data2,data1-data2);
            break;
        case '*':
            printf("%f*%f=%f\n",data1,data1,data1*data2);
            break;
        case '/':
            if(data2 == 0)                  /*����������*/
            {
                printf("error!division by 0");
            }
            else
            {
                printf("%f/%f=%f\n",data1,data2,data1/data2);
            }
            break;
        default:                             /*default����Ҫ����ð��.����䴦��Ƿ������*/
            printf("invalid operator!\n");
    }
}
