#include<iostream>

/*class human{
    public:
        std::string name="ram";
        std::string occupation="scientist";
        int age=70;

        void eat(){
            std::cout<<"this person is eating\n";
        }
        void drink(){
            std::cout<<"this person is drinking\n";
        }
        void sleep(){
            std::cout<<"this person is sleeping\n";
        }
};

int main()
{
    //obejct=A collection of attributes and methods
    //       they can have characteristics and could perform
    //       can be used to mimic real world items(ex. phone,book,car,etc.)
    //       created from class which acts as a "blue print"
    human human1;
    human human2;

    std::cout<<human1.name<<'\n';
    std::cout<<human1.occupation<<'\n';
    std::cout<<human1.age<<'\n';

    std::cout<<human2.name<<'\n';
    std::cout<<human2.occupation<<'\n';
    std::cout<<human2.age<<'\n';

    human2.eat();
    human2.drink();
    human2.sleep();

    return 0;
}*/
class Cars{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

        void accelerate(){
            std::cout<<"you stepped on the gas\n";
        }
        void brake(){
            std::cout<<"you stepped on thr gas\n";
        }
};

int main()
{
    Cars car1;

    car1.make ="ford";
    car1.model="mustang";
    car1.year=2023;
    car1.color="silver";

    std::cout<<car1.make<<'\n';
    std::cout<<car1.model<<'\n';
    std::cout<<car1.year<<'\n';
    std::cout<<car1.color<<'\n';

    car1.accelerate();
    car1.brake();

    return 0;
}
