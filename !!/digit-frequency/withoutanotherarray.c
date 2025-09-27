#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    printf("enter the string: ");
    scanf("%s",s);
    int count;
    for(char digit='0';digit<='9';digit++)
    {
        count=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==digit)
            {
                count++;
            }
        }
        printf("%d ",count);
    }
    printf("\n");
    return 0;
}
