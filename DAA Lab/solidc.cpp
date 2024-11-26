#include <iostream>
using namespace std;

// Base class Bird (abstract class)
class Bird {
public:
    virtual void fly() = 0; // Pure virtual function
};

// Subclass for birds that can fly
class FlyingBird : public Bird {
public:
    void fly() override {
        cout << "I can fly!" << endl;
    }
};

// Subclass for birds that cannot fly
class NonFlyingBird : public Bird {
public:
    void fly() override {
        cout << "I cannot fly!" << endl;
    }
};

// Subclass for Sparrow (which can fly)
class Sparrow : public FlyingBird {
};

// Subclass for Ostrich (which cannot fly)
class Ostrich : public NonFlyingBird {
};

int main() {
    Sparrow sparrow;
    Ostrich ostrich;

    // Using Bird pointers
    Bird* bird1 = &sparrow;
    Bird* bird2 = &ostrich;

    bird1->fly(); // Works fine
    bird2->fly(); // Works fine, no exception

    return 0;
}
