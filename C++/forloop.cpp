#include<iostream>
int main()
{
    int rows;
    int columns;
    char symbol;
    std::cout<<"how many rows?: ";
    std::cin>>rows;
    std::cout<<"how many columns?: ";
    std::cin>>columns;
    std::cout<<"enter a symbol to use: ";
    std::cin>>symbol;
     for(int i=1;i<=rows;i++)
     {
        for(int j=1;j<=columns;j++)
        {
            std::cout<<symbol;
        }
        std::cout<<'\n';
     }
     return 0;
}
