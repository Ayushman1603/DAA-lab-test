#include <iostream>
#include <string>
using namespace std;

// Violates ISP - a single interface with unrelated methods
// This is just an example, no need to use this in the final implementation
class Machine {
public:
    virtual void print(string document) = 0;
    virtual void scan(string document) = 0;
    virtual void fax(string document) = 0;
};

// Correct implementation with separate interfaces
class Printer {
public:
    virtual void print(string document) = 0;
};

class Scanner {
public:
    virtual void scan(string document) = 0;
};

class Fax {
public:
    virtual void fax(string document) = 0;
};

// Implementing specific functionalities
// Multi-function printer implementing all interfaces
class MultiFunctionPrinter : public Printer, public Scanner, public Fax {
public:
    void print(string document) override {
        cout << "Printing: " << document << endl;
    }

    void scan(string document) override {
        cout << "Scanning: " << document << endl;
    }

    void fax(string document) override {
        cout << "Faxing: " << document << endl;
    }
};

// Simple printer implementing only the Printer interface
class SimplePrinter : public Printer {
public:
    void print(string document) override {
        cout << "Printing: " << document << endl;
    }
};

int main() {
    // Test the classes
    MultiFunctionPrinter mfp;
    mfp.print("Multi-Function Document");
    mfp.scan("Multi-Function Document");
    mfp.fax("Multi-Function Document");

    SimplePrinter sp;
    sp.print("Simple Document");

    return 0;
}
