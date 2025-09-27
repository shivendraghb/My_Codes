#include<iostream>
#include<string>
using namespace std;

class Shape{// automatically becomes an abstract because of virtual
    virtual void draw()=0;//pure virtual function
};//only gives an idea or blueprint

class Circle:public Shape{
    public:
        void draw(){
            cout<<"drawing a circle\n";
        }
};

int main(){
    Circle c1;
    c1.draw();
    return 0;
}
