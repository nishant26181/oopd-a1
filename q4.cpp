#include "basicIO.h"

// Custom structure to represent an individual person without standard libraries
struct Person {
    char name[50]; // Bounded character array to prevent buffer overflow
    int age;
};

int main() {
    char ver[10]; // Buffer to hold user confirmation input ('y'/'n')
    
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
        io.outputstring("Enter name :");
        io.inputstring(record[i].name, 50);

        io.outputstring("Enter age :");
        record[i].age = io.inputint();

        // Compulsory Input Validation Loop: Force realistic age (1-99)
        while (record[i].age <= 0 || record[i].age >= 100) {
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
    io.outputstring("\nIf the data is correct enter y otherwise enter n :");
    io.inputstring(ver, 10);

    // Validate confirmation choice
    if (ver[0] == 'y' || ver[0] == 'Y') {
        io.outputstring("The data is Stored correctly\n");
    }
    else if (ver[0] == 'n' || ver[0] == 'N') {
        io.outputstring("The data is not stored correctly\n");
    }

    // Output final summary list of all stored records
    io.outputstring("The following data is saved\n");
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
