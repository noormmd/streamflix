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

    void registerUser() {
        //function to register user
    }

    void login() {
        //function to log user in streamflix
    }

    void choosePlan(string plan) {
        selectedPlan = plan;
    }
};

end if
