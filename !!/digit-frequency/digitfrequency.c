#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    printf("enter the string: ");
    scanf("%s",s);
    char count[10]={0};
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            count[(s[i]-'0')]++;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",count[i]);
    }
    printf("\n");
}
