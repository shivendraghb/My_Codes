#include<iostream>
int main()
{
    std::string name;
    while(name.empty()){
        std::cout<<"enter you name: ";
        std::getline(std::cin,name);
    }
    std::cout<<"hello, "<<name<<'\n';
}
