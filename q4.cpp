#include "basicIO.h"
struct Person{
    char name [50];
    int age;
};

int main(){
    char ver[10];
    io.outputstring("Enter the number of personal data you need to store :");
    int person_no = io.inputint();
    Person record[person_no];
    for (int i =0; i < person_no; i++){    
        io.outputstring("Enter name :");
        io.inputstring(record[i].name,50);
        io.outputstring("Enter age :");
        record[i].age = io.inputint();
        if (record[i].age > 0 && record[i].age < 100){
            io.outputstring("\nPlease verify your age and name :\n");
            io.outputstring("Entered name :");
            io.outputstring(record[i].name);
            io.outputstring("\nEntered age :");
            io.outputint(record[i].age); 
            io.outputstring("\nIf the data is correct enter y otherwise enter n :");
            io.inputstring(ver,10);
            if(ver[0] == 'y' || ver[0] == 'Y'){
                io.outputstring("The data is Stored correctly\n");
            }
            else if(ver[0] == 'n' || ver[0] == 'N'){
                io.outputstring("The data is not stored correctly\n");
            }
        }
        else {
            io.outputstring("Please give your real age \n");
        }
    }
    for(int j=0; j<person_no; j++){
        io.outputstring("The following data is saved\n");
        io.outputstring("Person Number: ");
        io.outputint(j+1);
        io.outputstring("\nPerson's Name: ");
        io.outputstring(record[j].name);
        io.outputstring("\nPerson's Age: ");
        io.outputint(record[j].age);
        io.outputstring("\n");
    }
    return 0;
}
