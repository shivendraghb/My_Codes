#include<iostream>
enum Day{sunday=0,monday=1,tuesday=2,wednesday=3,thursday=4};
    //or enums can be declared without any integer associated with them
    //in that case it will automatically take the corrsponding integer value
    //associated with enum element
int main()
{
    //enums=a user defined data type that consists
    //      of paired named-integers constants.
    //      GREAT if you have a set of potential options

    Day today=sunday;
    switch(today){
        case 0/*sunday*/: std::cout<<"it is sunday\n";
                       break;
        case 1/*monday*/: std::cout<<"it is monday\n";
                       break;
        case 2/*tuesday*/: std::cout<<"it is tuesday\n";
                       break;
        case 3/*wednesday*/: std::cout<<"it is wednesday\n";
                       break;
        case 4/*thursday*/: std::cout<<"it is thursday\n";
                       break;
    }
    return 0;
}
