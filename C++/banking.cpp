#include<iostream>
#include<iomanip>
#include<limits>
void showbalance(double balance);
double deposit();
double withdraw(double balance);
int main()
{
    double balance=0;
    int choice=0;
    do{
        std::cout<<"enter your choice\n";
        std::cout<<"1: show balance\n";
        std::cout<<"2: deposit money\n";
        std::cout<<"3: withdraw money\n";
        std::cout<<"4: exit\n";
        std::cin>>choice;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case 1: showbalance(balance);
                    break;
            case 2: balance += deposit();
                    showbalance(balance);
                    break;
            case 3: balance -= withdraw(balance);
                    showbalance(balance);
                    break;
            case 4: std::cout<<"thanks for visiting\n";
                    break;
            default:std::cout<<"invalid choice\n";
        }
    }while(choice != 4);
    return 0;
}
void showbalance(double balance){
    std::cout<<"your balance is: $"<<std::setprecision(2)<<std::fixed<<balance<<'\n';
}
double deposit(){
    double amount=0;
    std::cout<<"enter amount to be depsited\n";
    std::cin>>amount;
    if(std::cin.fail() || amount<=0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"that's not a valid amount\n";
        return 0;
    }
    return amount;
}
double withdraw(double balance){
    double amount=0;
    std::cout<<"enter amount to be withdrawn: ";
    std::cin>>amount;
    if(std::cin.fail() || amount<=0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"that's not a valid amount\n";
        return 0;
    }
    if(amount>balance){
        std::cout<<"insufficient funds\n";
        return 0;
    }
    return amount;
}
