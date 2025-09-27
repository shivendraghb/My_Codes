#include<iostream>
int main()
{
    std::string name;
    int age;
    std::cout<<"enter your age: ";
    std::cin>>age;

    std::cout<<"enter your full name: ";
    std::getline(std::cin>>std::ws,name); //std::ws eliminates whitespaces after any user input

    if(name.length()>12)//lenght of string
    {
        std::cout<<"your name can't be over 12 characters long!\n";
    }
    else if(name.empty())
    {
        std::cout<<"you didn't enter your name!\n";
    }
    else
    {
        std::cout<<"hello, "<<name<<'\n';
        std::cout<<"you are "<<age<<" years old"<<'\n';
    }
    return 0;
}
