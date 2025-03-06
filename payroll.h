// PayrollSystem.h
#ifndef PAYROLLSYSTEM_H
#define PAYROLLSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <mysql/mysql.h>

using namespace std;

struct Employee {
    int id;
    string name;
    double hourlyRate;
    double hoursWorked;
    double salary;
};

class PayrollSystem {
private:
    vector<Employee> employees;
    MYSQL *conn;

public:
    PayrollSystem();
    ~PayrollSystem();
    void addEmployee(int id, string name, double hourlyRate, double hoursWorked);
    void saveToDatabase(int id, string name, double hourlyRate, double hoursWorked, double salary);
    void displayPayroll();
};

#endif // PAYROLLSYSTEM_H



