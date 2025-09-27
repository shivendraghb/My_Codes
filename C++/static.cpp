#include<iostream>
#include<string>
using namespace std;

class ABC{
    public:
        ABC(){
            cout<<"constructor\n";
        }

        ~ABC(){
            cout<<"destructor\n";
        }
};
/*class A{
    public:
    int x;

    void incX(){
        x=x+1;
    }
};*/

/*void fun(){
    static int x=0;
    cout<<"x: "<<x<<endl;
    x++;
}*/
int main(){
    /*A obj1;
    A obj2;
    obj1.x=100;
    obj2.x=200;
    cout<<obj2.x<<endl;*/

    if(true){
        static ABC obj;
    }
    cout<<"end of main function\n";

    return 0;
}
