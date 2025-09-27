#include<iostream>
int main(){
    //foreach loop = loop that eases the traversal over
    //               an iterable data set

    //std::string students[]={"ram","manohar","lohiya"};
    int grade[]={54,26,94,61,6};

    for(int x:grade){
        std::cout<<x<<'\n';
    }
    return 0;
}

