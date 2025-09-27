#include<iostream>
int main()
{
    int n;

    do{
        std::cout<<"enter a positive number\n";
        std::cin>>n;
    }while(n<0);
    std::cout<<"the number is "<<n<<"\n";
    return 0;
}
