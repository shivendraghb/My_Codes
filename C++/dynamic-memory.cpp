#include<iostream>
int main()
{
    char *pgrades=NULL;
    int size;
    std::cout<<"how many grades to enter in?: ";
    std::cin>>size;
    pgrades=new char[size];
    for(int i=0;i<size;i++)
    {
        std::cout<<"enter grade number "<<i+1<<": ";
        std::cin>>pgrades[i];
    }
    for(int i=0;i<size;i++)
    {
        std::cout<<pgrades[i]<<" ";
    }
    std::cout<<'\n';
    delete[] pgrades;
    return 0;
}
