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


};

#endif