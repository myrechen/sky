//判断数据类型长度符的关键字sizeof()

/*用法
sizeof (类型说明符)
sizeof 表达式
*/

#include<stdio.h>
int main()
{
    printf("Data type    Number of bytes\n");
    printf("---------    ----------------\n");
    printf("char         %d\n", sizeof(char));
    printf("int          %d\n", sizeof(int));
    printf("short int    %d\n", sizeof(short));
    printf("long int     %d\n", sizeof(long));
    printf("float        %d\n", sizeof(float));
    printf("double       %d\n", sizeof(double));
}
