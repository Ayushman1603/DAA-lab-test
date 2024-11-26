#include <iostream>
using namespace std;

// Abstraction
class Database
{
public:
    virtual void connect() = 0; // Pure virtual function
};

// Low-level module
class MySQLDatabase : public Database
{
public:
    void connect() override
    {
        cout << "Connecting to MySQL Database" << endl;
    }
};

class PostgreSQLDatabase : public Database
{
public:
    void connect() override
    {
        cout << "Connecting to PostgreSQL Database" << endl;
    }
};

// High-level module
class DataAccess
{
private:
    Database *database; // Dependency injection of Database type
public:
    // Constructor accepts any Database type (MySQL or PostgreSQL)
    DataAccess(Database *db) : database(db) {}
    
    // Fetch data using the connected database
    void getData()
    {
        database->connect(); // Connect to the database
        cout << "Fetching data" << endl;
    }
};

int main()
{
    // Creating instances of concrete database types
    MySQLDatabase mysqlDb;
    PostgreSQLDatabase postgresDb;
    
    // Passing concrete database instances to the DataAccess class
    DataAccess dataAccess1(&mysqlDb);
    DataAccess dataAccess2(&postgresDb);
    
    // Fetch data using different database types
    dataAccess1.getData();
    dataAccess2.getData();
    
    return 0;
}
