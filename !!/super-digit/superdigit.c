#include<stdio.h>
#include<string.h>
int superdigit(char *n,long long k)
{
    long long num=0;
    for(int i=0;n[i]!='\0';i++)
    {
        num+=n[i]-'0';
    }
    long long sum=0;
    while(num>0)
    {
        sum=sum+num%10;
        num/=10;
    }
    long long superdigit=k*sum;
    long long sum1=0;
    if(superdigit>9)
    {
        while(superdigit>9)
        {
            sum1=0;
            while(superdigit>0)
            {
                sum1=sum1+superdigit%10;
                superdigit/=10;
            }
           superdigit=sum1;
        }
        return sum1;
    }
    else
        return superdigit;
}

int main()
{
    char n[100001];
    long long k;
    scanf("%s %lld",n,&k);
    int answer=superdigit(n,k);
    printf("super digit=%d\n",answer);
    return 0;
}
