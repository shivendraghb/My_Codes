#include<iostream>
int main()
{
    double temp;
    std::string unit;
    std::cout<<"what unit conversion you want: ";
    std::getline(std::cin>>std::ws,unit);

    if(unit == "Fahrenheit" || unit == "fahrenheit")
    {
        std::cout<<"enter the temperatur in celsius: ";
        std::cin>>temp;

        temp=(1.8*temp)+32.0;
        std::cout<<"temperature is: "<<temp<<"F\n";
    }
    else if(unit == "Celsius" || unit == "celsius")
    {
        std::cout<<"enter the temperature in fahrenheit: ";
        std::cin>>temp;

        temp=(temp-32)/1.8;
        std::cout<<"temperature is: "<<temp<<"C\n";
    }
    else
    {
        std::cout<<"enter a valid unit\n";
    }
    return 0;
}
