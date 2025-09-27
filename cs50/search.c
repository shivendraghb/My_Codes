#include<stdio.h>
#include<cs50.h>
#include<string.h>
typedef struct
{
    string name;
    string number;
}person;

int main()
{
    person people[3];

    people[0].name="mom";
    people[0].number="7985254183";

    people[1].name="dad";
    people[1].number="7007051968";

    people[2].name="shivendra";
    people[2].number="9250208636";

    string name=get_string("Name: ");
    for(int i=0;i<3;i++)
    {
        if(strcmp(people[i].name,name)==0)
        {
            printf("Found %s\n",people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
