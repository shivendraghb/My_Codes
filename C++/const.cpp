#include<iostream>
int main()
{
    const double pi=3.14159265;
    //pi=123; incorrect assignment of read only variable
    std::cout<<pi<<'\n';
}
