#include <iostream>
#include <string>
using namespace std;

// Base class for Notification
class Notification {
public:
    virtual void send(string message) = 0; // Pure virtual function
};

// Derived class for Email Notification
class EmailNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Email with message: " << message << endl;
    }
};

// Derived class for SMS Notification
class SMSNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending SMS with message: " << message << endl;
    }
};

// Client code function that uses Notification
void notify(Notification* notification, string message) {
    notification->send(message);  // Call the appropriate send function
}

int main() {
    EmailNotification email;
    SMSNotification sms;

    // Notify via email and SMS
    notify(&email, "Hello via Email!");  // Passing email notification
    notify(&sms, "Hello via SMS!");      // Passing SMS notification

    return 0;
}
