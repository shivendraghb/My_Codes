#include<iostream>
using namespace std;
struct student{
    std::string name;
    double gpa;
    bool enrolled;//bool enrolled=true can set a default value
};
int main()
{
    student student1;
    student1.name="spongebob";
    student1.gpa=3.2;
    student1.enrolled=true;

    student student2;
    student2.name="patrick";
    student2.gpa=2.1;
    student2.enrolled=true;

    student student3;
    student3.name="squidward";
    student3.gpa=4.0;
    student3.enrolled=false;

    std::cout<< student1.name <<'\n';
    std::cout<< student1.gpa <<'\n';
    std::cout<< student1.enrolled <<'\n';

    std::cout<< student2.name <<'\n';
    std::cout<< student2.gpa <<'\n';
    std::cout<< student2.enrolled <<'\n';

    std::cout<< student3.name <<'\n';
    std::cout<< student3.gpa <<'\n';
    std::cout<< student3.enrolled <<'\n';

    return 0;
}
