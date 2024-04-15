#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Movies.h"
#include "TVshows.h"
#include "Users.h"
#include "Plan.h"

using namespace std;

//Function to perform user registration
void registerUser(const string& username, const string& email, const string& password) {
  //Open the users.csv file
  ofstream file("users.csv", ios::app);
  if (file.is_open()) {
    //Write user information to file
    file << username << "," << email << "," << password << endl;
    file.close();
    cout << "User registered successfully!" << endl;
  } else {
    cout << "Error: Unable to open file." << endl;
  }
}

//Function to check if a user exists in the CSV file
bool userExists(const string& username, const string& password) {
  //Open the users.csv file
  ifstream file("users.csv");
  if (file.is_open()) {
    string line;
    //Read each line in the file
    while (getline(file, line)) {
      stringstream ss(line);
      string storedUsername, storedEmail, storedPassword;
      //Parse the lines into username, email and password
      getline(ss, storedUsername, ',');
      getline(ss, storedEmail, ',');
      getline(ss, storedPassword, ',');
      //Check if username and password match
      if (storedUsername == username && storedPassword == password) {
        file.close();
        return true;
      }
    }
    file.close();
}
return false;
}

//Function to perform user login
void loginUser(const string& username, const string& password) {
  if (userExists(username, password)) {
      cout << "Login successful! Welcome, " << username << "!" << endl;
  } else {
      cout << "Invalid username or password. Please try again." << endl;
  }
}

// Function to display plan options and let the user choose
string selectPlan() {
    cout << "\nSelect a plan:" << endl;
    cout << "1. Basic Plan (Limited access to movies and TV shows)" << endl;
    cout << "2. Premium Plan (Full access to movies and TV shows)" << endl;
    cout << "Enter your choice (1 or 2): ";
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2") {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }
    return choice;
}

// Function to display plan details
void displayPlanDetails(const string& plan) {
    if (plan == "1") {
        cout << "\nBasic Plan Details:" << endl;
        cout << "- Limited access to movies and TV shows." << endl;
        cout << "- Access to a handpicked selection of popular titles." << endl;
    } else {
        cout << "\nPremium Plan Details:" << endl;
        cout << "- Full access to all movies and TV shows." << endl;
        cout << "- Access to a wider range of content and all movies and TV shows of choice." << endl;
    }
}

int main() {
  bool running = true;
  while (running) {
    cout << "Menu:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
    int choice;
    cin >> choice;
    string username, email, password;
    switch (choice) {
        case 1:
          cout << "Enter username: ";
          cin >> username;
          cout << "Enter email: ";
          cin >> email;
          cout << "Enter password: ";
          cin >> password;
          registerUser(username, email, password);
          break;
        case 2: 
          cout << "Enter username: ";
          cin >> username;
          cout << "Enter password: ";
          cin >> password;
          loginUser(username, password);
          // If user exists limit access to movies and TV shows based on selected plan function
           if (userExists(username, password)) {
                    string selectedPlan = selectPlan();
                    User user(username, email, password);
                    user.setSelectedPlan(selectedPlan);
                    displayPlanDetails(selectedPlan);
                    if (selectedPlan == "1") {
                        // Limit access to basic plan content
                        // e.g. display only a selection of titles OR limit to only movies/tv shows
                    } else {
                        // Or give full access for premium plan
                    }
                }
          break;
        case 3:
          running = false;
          cout << "Goodbye!" << endl;
          break;
        default:
          cout << "Invalid choice. Please choose again." << endl;
    }
  }
  return 0;
}

      
