#include<iostream>
int main()
{
    long int n;
    std::cout<<"enter the card number: ";
    std::cin>>n;
    //AMERICAN EXPRESS uses 15-digit card number| 378282246310005
    // All American Express numbers start with 34 or 37
    //MASTERCARD uses 16-digit card number| 5553 0422 4198 4105
    //most MasterCard numbers start with 51, 52, 53, 54, or 55
    //Visa uses 13- and 16-digit numbers| 4003600000000014
    //Visa numbers start with 4
    long int temp0=n;
    int s1=0,s2,s3=0,temp1,count=0;
    while(temp0>0)
    {
        //<>LUHN's ALGORITHM
        s1=s1+temp0%10;
        temp0/=10;
        s2=2*(temp0%10);
        temp1=s2;
        while(temp1>0)
        {
            s3=s3+(temp1%10);
            temp1/=10;
        }
        temp0/=10;
    }
    if((s1+s3)%10==0)
    {
        temp0=n;
        while(temp0>0)
        {
            temp0/=10;
            count++;
        //</>LUHN's ALGORITHM
        }
        if(count==15)
        std::cout<<"AMERICAN EXPRESS\n";
        else if(count==16 && (n/100000000000000>=51 && n/100000000000000<=55))
        std::cout<<"MASTERCARD\n";
        else if((count==13||count==16) && (n/1000000000000==4||n/1000000000000000==4))
        std::cout<<"VISA\n";
        else
        std::cout<<"INVALID\n";
    }
    else
    std::cout<<"INVALID\n";
return 0;
}

