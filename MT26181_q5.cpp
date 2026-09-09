// Roll No: MT26181
// Name: Nishant Kharwal

#include "basicIO.h"

// Class to handle input validation
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

    // Checks if age is a valid integer within bounds (1 to 99)
    bool checkAge(int age) {
        if (age > 0 && age < 100) {
            return true;
        }
        return false;
    }
};

// Custom structure to hold personal details
struct Person {
    char name[50]; // Fixed-size character array for person's name
    int age;       // Integer to hold person's age
};

int main() {
    char ver[10];        // Buffer for user verification inputs ('y'/'n')
    const int max = 100; // Maximum allocation limit to prevent stack overflow
    Validator valid;     // Instance of Validator class

    // Prompt for initial number of personal data entries
    io.outputstring("Enter the number of personal data you need to store :");
    int person_no = io.inputint();

    // Bounds check to prevent stack array overflow
    if (person_no > max) {
        io.outputstring("Exceeds max capacity! Capping entries to 100.\n");
        person_no = max;
    } else if (person_no < 1) {
        person_no = 1;
    }

    // Stack-allocated array of structures using the predefined maximum capacity
    Person record[max];

    // Loop to input initial name and age details
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

    // Ask user if additional details need to be added
    io.outputstring("\nDo you need to save new details (y/n):");
    io.inputstring(ver, 10);

    // Branch 1: User chooses to add extra records
    if (ver[0] == 'y' || ver[0] == 'Y') {
        io.outputstring("How many person's data you want to add:");
        int additional_person = io.inputint();

        // Calculate total number of records after addition and enforce max bound
        int new_person_no = person_no + additional_person;
        if (new_person_no > max) {
            io.outputstring("Exceeds max capacity! Capping total entries to 100.\n");
            new_person_no = max;
        }

        // Collect details for newly added records
        for (int i = person_no; i < new_person_no; i++) {
            // Name input and validation loop for new entries
            io.outputstring("\nEnter name :");
            io.inputstring(record[i].name, 50);

            while (!valid.checkName(record[i].name)) {
                io.outputstring("Invalid name! Please enter alphabets only.\n");
                io.outputstring("Enter name :");
                io.inputstring(record[i].name, 50);
            }

            // Age input and validation loop for new entries
            io.outputstring("Enter age :");
            record[i].age = io.inputint();

            while (!valid.checkAge(record[i].age)) {
                io.outputstring("Please give your real age \n");
                io.outputstring("Enter age :");
                record[i].age = io.inputint();
            }
        }

        // Display all accumulated records for verification
        io.outputstring("\nPlease verify your age and name :");
        for (int i = 0; i < new_person_no; i++) {
            io.outputstring("\nEntered name :");
            io.outputstring(record[i].name);
            io.outputstring(" Entered age :");
            io.outputint(record[i].age); 
        }

        // Confirm data correctness for the expanded record list
        io.outputstring("\n\nIf the data is correct enter y otherwise enter n :");
        io.inputstring(ver, 10);

        if (ver[0] == 'y' || ver[0] == 'Y') {
            io.outputstring("The data is Stored correctly\n");
        }
        else if (ver[0] == 'n' || ver[0] == 'N') {
            io.outputstring("The data is not stored correctly\n");
        }

        // Output final summary for all entries
        io.outputstring("\nThe following data is saved\n");
        for (int j = 0; j < new_person_no; j++) {
            io.outputstring("Person Number: ");
            io.outputint(j + 1);
            io.outputstring(" Name: ");
            io.outputstring(record[j].name);
            io.outputstring(" Age: ");
            io.outputint(record[j].age);
            io.outputstring("\n");
        }
        return 0;
    }
    // Branch 2: User chooses not to add extra records
    else {
        // Display initial records for verification
        io.outputstring("\nPlease verify your age and name :\n");
        for (int i = 0; i < person_no; i++) {
            io.outputstring("Entered name :");
            io.outputstring(record[i].name);
            io.outputstring(" Entered age :");
            io.outputint(record[i].age); 
            io.outputstring("\n");
        }

        // Confirm data correctness for initial records
        io.outputstring("\nIf the data is correct enter y otherwise enter n :");
        io.inputstring(ver, 10);

        if (ver[0] == 'y' || ver[0] == 'Y') {
            io.outputstring("The data is Stored correctly\n");
        }
        else if (ver[0] == 'n' || ver[0] == 'N') {
            io.outputstring("The data is not stored correctly\n");
        }

        // Output final summary for initial records only
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
    }

    return 0; // Clean program termination
}