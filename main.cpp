#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Movies.h">

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
  //Open the users.xlsx file
  ifstream file("users.csv");
  if (file.is_open()) {
    string line;
    //Read each line in the file
    while (getline(file, line)) {
      stringstream ss(line);
      string storedUsername, storedEmail, storedPassword;
      //Parse the lines into username, email and password
      getLine(ss, storedUsername, ",");
      getLine(ss, storedEmail, ",");
      getLine(ss, storedPassword, ",");
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

// Function to check if the user exist and to make sure the password is correct
bool userExist (const string& username, const string& password){
}
//Function to perform user login
void loginUser(const string& username, const string& password) {
  if (userExists(username, password)) {
      cout << "Login successful! Welcome, " << username << "!" << endl;
  } else {
      cout << "Invalid username or password. Please try again." << endl;
  }
}

int main() {
string inputUsername, inputPassword;
cout << "Enter username: ";
cin >> inputUsername;

cout << "Enter password: ";
cin >> inputPassword;
loginUser(inputUsername, inputPassword);
return 0;
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


      
