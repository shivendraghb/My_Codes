#include<iostream>
int main()
{
    //double x=(int)3.14;
    //std::cout<<(char)100<<'\n';
    int correct =8;
    int questions=10;
    double score=(double)correct/questions*100;
    //or double score=(double)correct/(double)questions*100;
    //or double score=correct/(double)questions*100;
    std::cout<<score<<"%"<<'\n';
    return 0;
}
