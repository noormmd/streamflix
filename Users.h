#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class User {
private:
    string username;
    string email;
    string password;
    string selectedPlan;

public:
    User(string username, string email, string password)
        : username(username), email(email), password(password){}

    string getUsername() const {
        return username;
    }

    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    void setSelectedPlan(string plan) {
        selectedPlan = plan;
    }
   string getSelectedPlan() const {
        return selectedPlan;
    }
vector<User> readUsersFromCSV(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, email, password, plan;
        if (getline(ss, username, ',') &&
            getline(ss, email, ',') &&
            getline(ss, password, ',') &&
            getline(ss, plan, ',')) {
            users.emplace_back(username, email, password);
            users.back().setSelectedPlan(plan);
        }
    }
    return users;
}

void writeUsersToCSV(const string& filename, const vector<User>& users) {
    ofstream file(filename);
    for (const auto& user : users) {
        file << user.getUsername() << ','
             << user.getEmail() << ','
             << user.getPassword() << ','
             << user.getSelectedPlan() << '\n';
    }
}


};

#endif
