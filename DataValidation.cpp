#include<iostream>
#include<string> // Required to use the string type
#include<cstdlib> // Required to use system and other functions

using namespace std;

int loginandregister() {
    system("cls"); // Clean the screen
    system("color f0"); // Change the color of the text and background

    string user, password, A, B;
    int attempts = 0; // Variable to track the number of incorrect attempts

    cout << "\t\t\tRegistration\n";
    cout << "__________________________________\n";

    cout << "\nEnter your username: ";
    getline(cin, user);
    cout << "\nEnter your password: ";
    getline(cin, password);

    // Save the username (A) and password (B) values
    A = user;
    B = password;

    cout << "\nSaving data......";
    cout << "\nPress Enter to continue";
    cin.get(); // Wait for the user to press Enter

    system("cls"); // Clean the screen

    cout << "\t\t\tLogin\n";
    cout << "___________________________________\n";

    do {
        cout << "\nEnter your username: ";
        getline(cin, user);
        cout << "Enter your password: ";
        getline(cin, password);

        // Condition to validate the entered data
        if (A == user && B == password) {
            cout << "\nSuccessful login!\n";
            break; // Exit the loop if login is successful
        } else {
            cout << "\nIncorrect username and/or password.\n";
            attempts++; // Increment the number of attempts
            if (attempts <3) {
                cout << "Please! check your password and try again.\n";
            } else {
                cout << "You have exceeded the maximum number of attempts.\n";
                cout << "Press Enter to exit";
                cin.ignore(); // Ignore the Enter key pressed after the password
                cin.get(); // Wait for the user to press Enter before exiting
                return 0; // Exit the program
            }
        }
    } while (true);

    cout << "Press Enter to exit";
    cin.ignore(); // Ignore the Enter key pressed after the password
    cin.get(); // Wait for the user to press Enter before exiting
    return 0;
}
