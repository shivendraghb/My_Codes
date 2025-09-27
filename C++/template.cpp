/*include<iostream>
template <typename T>
T max(T x,T y){
    return (x>y)?x:y;
}
int main()
{
    std::cout<<max("1","-2")<<'\n';
    return 0;
}*/
#include<iostream>
template <typename T,typename U>
auto max(T x,U y){//function template=describes what a function looks like
    return (x>y)?x:y;//can be used to generate as many overloaded functions as needed
}
int main()
{
    std::cout<<max(1,2.1)<<'\n';
    return 0;
}
