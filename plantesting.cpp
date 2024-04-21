#include <iostream>
#include <string>

using namespace std;

// Function to select a plan
string selectPlan() {
    cout << "------------------------------------" << endl;
    cout << "Select a plan:" << endl;
    cout << "------------------------------------" << endl;
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
        cout << "------------------------------------" << endl;
        cout << "\nBasic Plan Details:" << endl;
        cout << "------------------------------------" << endl;
        cout << "- Limited access to movies and TV shows." << endl;
        cout << "- Access to a handpicked selection of popular titles." << endl;
    } else {
        cout << "------------------------------------" << endl;
        cout << "\nPremium Plan Details:" << endl;
        cout << "------------------------------------" << endl;
        cout << "- Full access to all movies and TV shows." << endl;
        cout << "- Access to a wider range of content and all movies and TV shows of choice." << endl;
    }
}

int main() {
    cout << "Welcome to StreamFlix!" << endl;
    string selectedPlan = selectPlan();
    displayPlanDetails(selectedPlan);
    return 0;
}
