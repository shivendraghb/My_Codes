#include<iostream>
#include<ctime>
int main()
{
    int num;
    int guess;
    int tries=0;
    srand(time(NULL));
    num=(rand()%100)+1;

    do{
        std::cout<<"enter a guess bw (1-100): ";
        std::cin>>guess;
        tries++;
        if(guess > num)
        {
            std::cout<<"too high:\n";
        }
        else if(guess<num)
        {
            std::cout<<"too low\n";
        }
        else
        {
            std::cout<<"correct! tries required: "<<tries<<'\n';
        }
    }while(guess!=num);
    return 0;
}

