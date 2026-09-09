// Roll No: MT26181
// Name: Nishant Kharwal

#include "basicIO.h"

class Validator {
public:
    // Checks if the name array contains only alphabets and spaces
    bool checkName(char name[]) {
        if (name[0] == '\0' || name[0] == '\n') {
            return false;
        }

        for (int i = 0; name[i] != '\0' && name[i] != '\n'; i++) {
            char ch = name[i];
            
            bool isSmallLetter = (ch >= 'a' && ch <= 'z');
            bool isCapitalLetter = (ch >= 'A' && ch <= 'Z');
            bool isSpace = (ch == ' ');

            if (!isSmallLetter && !isCapitalLetter && !isSpace) {
                return false;
            }
        }
        return true;
    }

    // Checks if age is a valid integer within bounds
    bool checkAge(int age) {
        if (age > 0 && age < 100) {
            return true;
        }
        return false;
    }
};

int main() {
    char name[50];
    char ver[10];
    Validator valid; // Simple class object for validation

    // Prompt for and read the user's name
    io.outputstring("Enter your name :");
    io.inputstring(name, 50);

    // Validate name input
    if (!valid.checkName(name)) {
        io.outputstring("Invalid name! Please enter alphabets only.\n");
        return 0;
    }

    // Prompt for and read the user's age
    io.outputstring("Enter you age :");
    int age = io.inputint();

    // Validate age input
    if (!valid.checkAge(age)) {
        io.outputstring("Please give your real age \n");
        return 0;
    }

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

    return 0;
}