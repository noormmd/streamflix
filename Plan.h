#ifndef PLAN_H
#define PLAN_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;



class Plan {
private:
    float price;
    vector<string> planOptions;
    bool available;

public:
    Plan(float price, const vector<string>& planOptions, bool available)
        : price(price), planOptions(planOptions), available(available) {}

    void displayPlan(string planName){}

    float totalPrice(int subscriptionDuration) {
        return price * subscriptionDuration;
    }

    bool isAvailable(){
        return available;
    }
};
#endif
