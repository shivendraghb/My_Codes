#include<iostream>
int main()
{
    int month;
    std::cout<<"enter the value of month(1-12): ";
    std::cin>>month;

    switch(month)
    {
        case 1:
        std::cout<<"it is january\n";
        break;
        case 2:
        std::cout<<"it is february\n";
        break;
        default:
        std::cout<<"invalid month number\n";
    }
    return 0;
}
