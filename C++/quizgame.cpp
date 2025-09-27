#include<iostream>
//#include<cctype>
using namespace std;

int main(){

    std::string questions[]={"1. What year was C++ created?: ",
                             "2. Who invented C++?: ",
                             "3. What is the predecessor of C++?: ",
                             "4. Is the earth flat?"};

    std::string options[][4]={{"A. 1969","B. 1975","C. 1985","D. 1989"},
                             {"A. guido van rossum","B. bjarne stroustrap","C. john carmack","D. dennis ritchie"},
                             {"A. C","B. C+","C. C--","D. B++"},
                             {"A. yes","B. no","C. sometimes","D. what's earth?"}};

    char answerkey[]={'C','B','A','B'};

    int size=sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score=0;

    for(int i=0;i<size;i++){
        cout<<"************************\n";
        cout<<questions[i]<<'\n';
        cout<<"************************\n";

        for(int j=0;j<sizeof(options[i])/sizeof(options[i][0]);j++){
            cout<<options[i][j]<<'\n';
        }
            cin>>guess;
            guess=toupper(guess);
            if(guess == answerkey[i]){
                cout<<"CORRECT\n";
                score++;
            }
            else{
                cout<<"INCORRECT\n";
                cout<<"Answer: "<<answerkey[i]<<'\n';
            }
        }
    cout<<"Your score is: "<<score<<'\n';
    cout<<"Number of questions: "<<size<<'\n';
    cout<<"Your percentage is: "<<score/(double)size*100<<"%"<<'\n';

    return 0;
}
