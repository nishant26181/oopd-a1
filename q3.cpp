#include "basicIO.h"

int main() {
    char name[50]; // Buffer to store person's name
    char ver[10];  // Buffer for user confirmation input ('y'/'n')

    // Prompt for and read the user's name
    io.outputstring("Enter your name :");
    io.inputstring(name, 50);

    // Prompt for and read the user's age
    io.outputstring("Enter you age :");
    int age = io.inputint();

    // Input validation: ensure age falls within realistic bounds
    if (age > 0 && age < 100) {
        // Display entered data back to the user for verification
        io.outputstring("\nPlease verify your age and name :\n");
        io.outputstring("Entered name :");
        io.outputstring(name);
        io.outputstring("\nEntered age :");
        io.outputint(age); 

        // Prompt user to confirm if entered information is accurate
        io.outputstring("\nIf the data is correct enter y otherwise enter n :");
        io.inputstring(ver, 10);

        // Check verification response
        if (ver[0] == 'y' || ver[0] == 'Y') {
            io.outputstring("The data is Stored correctly\n");
        }
        else if (ver[0] == 'n' || ver[0] == 'N') {
            io.outputstring("The data is not stored correctly\n");
        }
    }
    else {
        // Output error message for out-of-range age inputs
        io.outputstring("Please give your real age \n");
    }
}