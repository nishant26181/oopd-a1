// Roll No: MT26181
// Name: Nishant Kharwal

#include "basicIO.h"

// Simple class to handle input validation
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

    // Checks if age is a valid integer within realistic bounds (1 to 99)
    bool checkAge(int age) {
        if (age > 0 && age < 100) {
            return true;
        }
        return false;
    }
};

// Custom structure to represent an individual person
struct Person {
    char name[50];
    int age;
};

int main() {
    char ver[10];
    Validator valid; // Instance of Validator class
    
    // Fixed maximum stack allocation limit to prevent memory buffer overflow
    const int max = 100; 

    io.outputstring("Enter the number of personal data you need to store :");
    int person_no = io.inputint();

    // Bounds check to prevent stack array overflow
    if (person_no > max) {
        io.outputstring("Exceeds max capacity! Capping entries to 100.\n");
        person_no = max;
    } else if (person_no < 1) {
        person_no = 1;
    }

    // Stack-allocated array of structures for record storage
    Person record[max]; 

    // Collect name and age details for each entry
    for (int i = 0; i < person_no; i++) {
        // Name input and validation loop
        io.outputstring("\nEnter name :");
        io.inputstring(record[i].name, 50);

        while (!valid.checkName(record[i].name)) {
            io.outputstring("Invalid name! Please enter alphabets only.\n");
            io.outputstring("Enter name :");
            io.inputstring(record[i].name, 50);
        }

        // Age input and validation loop
        io.outputstring("Enter age :");
        record[i].age = io.inputint();

        while (!valid.checkAge(record[i].age)) {
            io.outputstring("Please give your real age \n");
            io.outputstring("Enter age :");
            record[i].age = io.inputint();
        }
    }

    // Output all collected records for initial user review
    io.outputstring("\nPlease verify your age and name :\n");
    for (int i = 0; i < person_no; i++) {  
        io.outputstring("\nEntered name :");
        io.outputstring(record[i].name);
        io.outputstring(" Entered age :");
        io.outputint(record[i].age); 
    }

    // Prompt user for explicit data verification
    io.outputstring("\n\nIf the data is correct enter y otherwise enter n :");
    io.inputstring(ver, 10);

    // Validate confirmation choice
    if (ver[0] == 'y' || ver[0] == 'Y') {
        io.outputstring("The data is Stored correctly\n");
    }
    else if (ver[0] == 'n' || ver[0] == 'N') {
        io.outputstring("The data is not stored correctly\n");
    }

    // Output final summary list of all stored records
    io.outputstring("\nThe following data is saved\n");
    for (int j = 0; j < person_no; j++) {
        io.outputstring("Person Number: ");
        io.outputint(j + 1);
        io.outputstring(" Name: ");
        io.outputstring(record[j].name);
        io.outputstring(" Age: ");
        io.outputint(record[j].age);
        io.outputstring("\n");
    }

    return 0; // Clean exit code for freestanding execution
}