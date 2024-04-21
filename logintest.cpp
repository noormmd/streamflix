#include <iostream>
#include "Users.h"

int main() {
    // Read users from CSV
    std::vector<User> users = readUsersFromCSV("users.csv");

    // If there are no users in the CSV, display a message and exit
    if (users.empty()) {
        std::cout << "No users found. Please register first." << std::endl;
        return 0;
    }

    // Prompt user for login credentials
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Check if the entered credentials match any user in the vector
    bool loggedIn = false;
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            loggedIn = true;
            break;
        }
    }

    // Display login status
    if (loggedIn) {
        std::cout << "Login successful! Welcome, " << username << "!" << std::endl;
    } else {
        std::cout << "Invalid username or password. Please try again." << std::endl;
    }

    return 0;
}
