#include<iostream>
#include<ctime>
int main()
{
    srand(time(0));
    int randnum=rand()%5+1;
    switch(randnum)
    {
        case 1: std::cout<<"you won apple\n";
        break;
        case 2: std::cout<<"you won a shirt\n";
        break;
        case 3: std::cout<<"you won a million dollar\n";
        break;
        case 4: std::cout<<"you won a concert ticket\n";
        break;
    }
    return 0;
}
