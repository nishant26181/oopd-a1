#include "basicIO.h"
int main(){
char name[50];
char ver[10];
io.outputstring("Enter your name :");
io.inputstring(name,50);
io.outputstring("Enter you age :");
int age = io.inputint();
if (age > 0 && age < 100){
	io.outputstring("\nPlease verify your age and name :\n");
    io.outputstring("Entered name :");
    io.outputstring(name);
    io.outputstring("\nEntered age :");
    io.outputint(age); 
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
