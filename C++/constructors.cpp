#include<iostream>

/*class student{
    public:
        std::string name;
        int age;
        double gpa;

    //if parameter names are different from the attribute names then
    //we may not use this->. Example x,y,z >> name=x;age=y;gpa=z;
    student(std::string name,int age,double gpa){
        this->name=name;
        this->age=age;
        this->gpa=gpa;
    }
};*/

class Cars{
    public:
        std::string make;
        std::string model;
        int year;
        std::string color;

    Cars(std::string make,std::string model,int year,std::string color){
            this->make = make;
            this->model = model;
            this->year = year;
            this->color = color;
    }
};

int main()
{
    //constructor=special method within a class that is automatically called when an object is
    //            instantiated.
    //            useful for assigning values to attributes as arguments

    /*student student1("spongebob",25,3.2);
    student student2("patrick",40,1.5);

    std::cout<<student1.name<<'\n';
    std::cout<<student1.age<<'\n';
    std::cout<<student1.gpa<<'\n';*/

    Cars car1("bugatti","chiron",2023,"blue");
    Cars car2("lamborghini","revuelto",2024,"orange");

    std::cout<<car2.make<<'\n';
    std::cout<<car2.model<<'\n';
    std::cout<<car2.year<<'\n';
    std::cout<<car2.color<<'\n';

    return 0;
}
