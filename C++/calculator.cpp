#include<iostream>
int main()
{
    char op;
    double num1,num2,result;
    std::cout<<"********CALCULATOR********\n";
    std::cout<<"enter a valid operator: ";
    std::cin>>op;

    std::cout<<"enter num1: ";
    std::cin>>num1;

    std::cout<<"enter num2: ";
    std::cin>>num2;

    switch(op)
    {
        case '+':
        result=num1+num2;
        std::cout<<"result= "<<result<<'\n';
        break;

        case '-':
        result=num1-num2;
        std::cout<<"result= "<<result<<'\n';
        break;

        case '*':
        result=num1*num2;
        std::cout<<"result= "<<result<<'\n';
        break;

        case '/':
        result=num1/num2;
        std::cout<<"result= "<<result<<'\n';
        break;

        default:
        std::cout<<"the operator was not valid!";
    }
    std::cout<<"********CALCULATOR********\n";
    return 0;
}
