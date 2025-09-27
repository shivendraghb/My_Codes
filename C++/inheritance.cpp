#include<iostream>
using namespace std;

/*class Animal{
    public:
        bool alive = true;
    void eat(){
        cout<<"this animal is eating:\n";
    }
};
class Dog : public Animal{
    public:

    void bark(){
        cout<<"woof woof!"<<'\n';
    }
};
class Cat : public Animal{
    public:

    void meow(){
        cout<<"meow,meow\n";
    }
};

int main()
{
    //inheritance = A class can receive attributes and methods from another class
    //              children classes inherit form a parent class
    //              helps to reuse similar code found within multiple classes

    Dog dog;
    Cat cat;

    cout<<cat.alive<<'\n';
    cat.eat();
    cat.meow();

    return 0;
}*/
class Shape{
    public:
        double area;
        double volume;
};
class Cube : public Shape{
    public:
        double side;
    Cube(double side){
        this->side = side;
        this->area = side*side*6;
        this->volume = side*side*side;
    }
};
class Sphere : public Shape{
    public:
        double radius;
    Sphere(double radius){
        this->radius = radius;
        this->area = 4*3.1415926535897932384626*radius*radius;
        this->volume = (4/3.0)*3.1415926535897932384626*(radius*radius*radius);
    }
};

int main()
{
    Cube cube(10);
    Sphere sphere(5);

    cout<<"area: "<<sphere.area<<" cm^2\n";
    cout<<"volume: "<<sphere.volume<<" cm^3\n";

    return 0;
}
