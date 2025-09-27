#include<iostream>
std::string concatstrings(std::string string1,std::string string2)
{
    return string1 + " " + string2;
}
int main()
{
    std::string firstname="shivendra";
    std::string lastname="srivastava";
    std::string fullname=concatstrings(firstname,lastname);
    std::cout<<"hello "<<fullname<<'\n';
    return 0;
}
