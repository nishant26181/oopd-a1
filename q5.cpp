#include "basicIO.h"

// Custom structure to hold personal details without standard libraries
struct Person {
    char name[50]; // Fixed-size character array for person's name
    int age;       // Integer to hold person's age
};

int main() {
    char ver[10];        // Buffer for user verification inputs ('y'/'n')
    const int max = 100; // Maximum allocation limit to prevent stack overflow

    // Prompt for initial number of personal data entries
    io.outputstring("Enter the number of personal data you need to store :");
    int person_no = io.inputint();

    // Stack-allocated array of structures using the predefined maximum capacity
    Person record[max];

    // Loop to input initial name and age details
    for (int i = 0; i < person_no; i++) {    
        io.outputstring("Enter name :");
        io.inputstring(record[i].name, 50);
        io.outputstring("Enter age :");
        record[i].age = io.inputint();
    }

    // Ask user if additional details need to be added (Question 5 extension)
    io.outputstring("Do you need to save new details (y/n):");
    io.inputstring(ver, 10);

    // Branch 1: User chooses to add extra records
    if (ver[0] == 'y' || ver[0] == 'Y') {
        io.outputstring("How many person's data you want to add:");
        int additional_person = io.inputint();

        // Calculate total number of records after addition
        int new_person_no = person_no + additional_person;

        // Collect details for the newly added records starting from the existing offset
        for (int i = person_no; i < new_person_no; i++) {
            io.outputstring("Enter name :");
            io.inputstring(record[i].name, 50);
            io.outputstring("Enter age :");
            record[i].age = io.inputint();
        }

        // Display all accumulated records (initial + additional) for verification
        io.outputstring("Please verify your age and name :");
        for (int i = 0; i < new_person_no; i++) {
            io.outputstring("\nEntered name :");
            io.outputstring(record[i].name);
            io.outputstring(" Entered age :");
            io.outputint(record[i].age); 
        }

        // Confirm data correctness for the expanded record list
        io.outputstring("\nIf the data is correct enter y otherwise enter n :");
        io.inputstring(ver, 10);

        if (ver[0] == 'y' || ver[0] == 'Y') {
            io.outputstring("The data is Stored correctly\n");
        }
        else if (ver[0] == 'n' || ver[0] == 'N') {
            io.outputstring("The data is not stored correctly\n");
        }

        // Output final summary for all entries (including additional ones)
        io.outputstring("The following data is saved\n");
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
        for (int i = 0; i < person_no; i++) {
            io.outputstring("\nPlease verify your age and name :\n");
            io.outputstring("Entered name :");
            io.outputstring(record[i].name);
            io.outputstring(" Entered age :");
            io.outputint(record[i].age); 
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
    }

    return 0; // Clean program termination
}