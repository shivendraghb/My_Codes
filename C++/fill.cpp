#include<iostream>
int main()
{
    //fill() = fills a range of elements with a specified value
    //         fill(begin,end,value)

    std::string foods[10];

    fill(foods,foods+10/2,"pizza");
    fill(foods+10/2,foods+10,"hamburger");

    for(std::string food:foods){
        std::cout<<food<<'\n';
    }

    return 0;
}
