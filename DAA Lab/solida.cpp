#include <iostream>
#include <string>
using namespace std;

// First version - Single class violating SRP
class User {
public:
    string name;
    string email;

    User(string n, string e) : name(n), email(e) {}

    void saveToDatabase() {
        cout << "Saving " << name << " to the database...\n";
    }

    void sendWelcomeEmail() {
        cout << "Sending welcome email to " << email << "...\n";
    }
};

// Second version - Applies SRP
// Renaming class 'User' to 'UserInfo' to avoid conflict
class UserInfo {
public:
    string name;
    string email;

    UserInfo(string n, string e) : name(n), email(e) {}
};

class UserDatabase {
public:
    void save(UserInfo user) {
        cout << "Saving " << user.name << " to the database...\n";
    }
};

class EmailService {
public:
    void sendWelcomeEmail(UserInfo user) {
        cout << "Sending welcome email to " << user.email << "...\n";
    }
};

int main() {
    // First version usage:
    User user1("Ayushman", "ayushman@example.com");
    user1.saveToDatabase();
    user1.sendWelcomeEmail();

    // Second version usage:
    UserInfo user2("Kartik", "kartik@example.com");
    UserDatabase db;
    EmailService emailService;

    db.save(user2);
    emailService.sendWelcomeEmail(user2);

    return 0;
}
