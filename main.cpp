#include <iostream>
#include <fstream>
#include <sstream>
#include <regex> // Regex library for email validation
#include <string>
#include <vector>
#include "Movies.h"
#include "TVshows.h"
#include "Users.h"
#include "Plan.h"
#include "Movies.cpp"

using namespace std;

// Forward declaration of TVShow structure
struct TVShow;

struct Movies;

// Function prototype for readMoviesFromCSV
std::vector<Movie> readMoviesFromCSV(const std::string &moviesfilename);

// Function to display movies from CSV file
void displayMoviesFromCSV(const std::string &moviesfilename)
{
    // Call the function to read movies from the CSV file
    std::vector<Movie> movies = readMoviesFromCSV(moviesfilename);

    // Display the movies
    for (const auto &movie : movies)
    {
        movie.printDetails();
        cout << endl;
    }
}

// Function to display TV shows from CSV file
void displayTVShowsFromCSV(const std::string& showsfilename) {
    // Call the function to read TV shows from the CSV file
    std::vector<TVShow> shows = readShowsFromCSV(showsfilename);

    // Display the TV shows
    for (const auto& show : shows) {
        std::cout << "Name: " << show.name << std::endl;
        std::cout << "Genres: " << show.genres << std::endl;
        std::cout << "Language: " << show.language << std::endl;
        std::cout << "Release Year: " << show.releaseYear << std::endl;
        std::cout << "Season: " << show.season << std::endl << std::endl;
    }
}

// Function to validate email format
bool isValidEmail(const string &email)
{
  // Regular expression for basic email validation
  const regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
  return regex_match(email, pattern);
}

// Function to perform user registration
void registerUser(const string &username, const string &email, const string &password)
{
  if (!isValidEmail(email))
  {
    cout << "Invalid email address. Please enter a valid email address." << endl;
    return; // Exit the function without registering user in
  }
  
  // Open the users.csv file
  ofstream file("users.csv", ios::app);
  if (file.is_open())
  {
    // Write user information to file
    file << username << "," << email << "," << password << endl;
    file.close();
    cout << "User registered successfully!" << endl;
  }
  else
  {
    cout << "Error: Unable to open file." << endl;
  }
}

// Function to check if a user exists in the CSV file
bool userExists(const string &username, const string &password)
{
  // Open the users.csv file
  ifstream file("users.csv");
  if (file.is_open())
  {
    string line;
    // Read each line in the file
    while (getline(file, line))
    {
      stringstream ss(line);
      string storedUsername, storedEmail, storedPassword;
      // Parse the lines into username, email and password
      getline(ss, storedUsername, ',');
      getline(ss, storedEmail, ',');
      getline(ss, storedPassword, ',');
      // Check if username and password match
      if (storedUsername == username && storedPassword == password)
      {
        file.close();
        return true;
      }
    }
    file.close();
  }
  return false;
}

// Function to perform user login
void loginUser(const string &username, const string &password)
{
  if (userExists(username, password))
  {
    cout << "Login successful! Welcome, " << username << "!" << endl;
  }
  else
  {
    cout << "Invalid username or password. Please try again." << endl;
  }
}

// Function to display plan options and let the user choose
string selectPlan()
{
  cout << "------------------------------------" << endl;
  cout << "\nSelect a plan:" << endl;
  cout << "------------------------------------" << endl;
  cout << "1. Basic Plan (Limited access to movies and TV shows)" << endl;
  cout << "2. Premium Plan (Full access to movies and TV shows)" << endl;
  cout << "Enter your choice (1 or 2): ";
  string choice;
  cin >> choice;
  while (choice != "1" && choice != "2")
  {
    cout << "Invalid choice. Please enter 1 or 2: ";
    cin >> choice;
  }
  return choice;
}

// Function to display plan details
void displayPlanDetails(const string &plan)
{
  if (plan == "1")
  {
    cout << "------------------------------------" << endl;
    cout << "\nBasic Plan Details:" << endl;
    cout << "------------------------------------" << endl;
    cout << "- Limited access to movies and TV shows." << endl;
    cout << "- Access to a handpicked selection of popular titles." << endl;
  }
  else
  {
    cout << "------------------------------------" << endl;
    cout << "\nPremium Plan Details:" << endl;
    cout << "------------------------------------" << endl;
    cout << "- Full access to all movies and TV shows." << endl;
    cout << "- Access to a wider range of content and all movies and TV shows of choice." << endl;
  }
}



int main() {
string moviesfilename = "Movies.csv";
string showsfilename = "tv-shows.csv";

  bool running = true;
  while (running)
  {
    /**
    cout << "What file will you be using for movies? Default is Movies.csv" << endl;
    cin >> moviesfilename;
    cout << "What file will you be using for shows? Default is tv-shows.csv" << endl;
    cin >> showsfilename;
*/
    cout << "      WELCOME TO STREAMFLIX" << endl;
    cout << "************************************" << endl;
    cout << "*           MAIN MENU              *" << endl;
    cout << "************************************" << endl;
    cout << "| 1. Register                     |" << endl;
    cout << "| 2. Login                        |" << endl;
    cout << "| 3. Exit                         |" << endl;
    cout << "************************************" << endl;
    cout << "Choose an option from the above\nby typing the corresponding number." << endl;
    int choice;
    cin >> choice;
    string username, email, password;
    switch (choice)
    {
    case 1:
      cout << "------------------------------------" << endl;
      cout << "Enter username: ";
      cin >> username;
      cout << "Enter email: ";
      cin >> email;
      cout << "Enter password: ";
      cin >> password;
      registerUser(username, email, password);
      break;
    case 2:
      cout << "------------------------------------" << endl;
      cout << "Enter username: ";
      cin >> username;
      cout << "Enter password: ";
      cin >> password;
      loginUser(username, password);
      // If user exists limit access to movies and TV shows based on selected plan function
      if (userExists(username, password))
      {
        string selectedPlan = selectPlan();
        User user(username, email, password);
        user.setSelectedPlan(selectedPlan);
        displayPlanDetails(selectedPlan);
        if (selectedPlan == "1")
        {
          // Limit access to basic plan content
          // e.g. display only a selection of titles OR limit to only movies
          cout << "You have chosen Plan 1 (Basic Plan), for limited access to movies and TV shows" << endl;

          // Functionality to choose a movie from only movies
          cout << "------------------------------------" << endl;
          cout << "Select a movie from the following to watch:" << endl;
          cout << "------------------------------------" << endl;
          // FUNCTIONALITY TO DISPLAY MOVIES
          displayMoviesFromCSV(moviesfilename);
           // After displaying ask whether user would like to search for a movie
          cout << "Looking for a particular movie? Search:" << endl;
          cout << "Type the category you'd like to search for " << endl;

        }
        else
        {
          // Or give full access for premium plan
          cout << "You have chosen Plan 2 (Premium Plan), for access to all movies and TV shows" << endl;

          // Functionality to choose any movie or TV show from wider range
          cout << "------------------------------------" << endl;
          cout << "Select a movie or TV show from the following to watch:" << endl;
          cout << "------------------------------------" << endl;
          // FUNCTIONALITY TO DISPLAY TV SHOWS
          displayTVShowsFromCSV(showsfilename);

          // After displaying ask whether user would like to search for a TV show
          cout << "Looking for a particular show? Search:" << endl;
          cout << "Type the category you'd like to search for " << endl;


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
  running = false;
  return 0;
}
