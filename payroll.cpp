// PayrollSystem.cpp
#include "PayrollSystem.h"

PayrollSystem::PayrollSystem() {
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "password", "payroll_db", 3306, NULL, 0);
    if (!conn) {
        cerr << "Database Connection Failed!" << endl;
    }
}

PayrollSystem::~PayrollSystem() {
    if (conn) mysql_close(conn);
}

void PayrollSystem::addEmployee(int id, string name, double hourlyRate, double hoursWorked) {
    double salary = hourlyRate * hoursWorked;
    employees.push_back({id, name, hourlyRate, hoursWorked, salary});
    saveToDatabase(id, name, hourlyRate, hoursWorked, salary);
}

void PayrollSystem::saveToDatabase(int id, string name, double hourlyRate, double hoursWorked, double salary) {
    if (conn) {
        string query = "INSERT INTO employees (id, name, hourlyRate, hoursWorked, salary) VALUES (" +
                       to_string(id) + ", '" + name + "', " + to_string(hourlyRate) + ", " + to_string(hoursWorked) + ", " + to_string(salary) + ")";
        if (mysql_query(conn, query.c_str())) {
            cerr << "Insert Failed: " << mysql_error(conn) << endl;
        }
    }
}

void PayrollSystem::displayPayroll() {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Hourly Rate" << setw(15) << "Hours Worked" << setw(15) << "Salary" << endl;
    cout << string(75, '-') << endl;
    for (const auto &emp : employees) {
        cout << left << setw(10) << emp.id << setw(20) << emp.name << setw(15) << emp.hourlyRate << setw(15) << emp.hoursWorked << setw(15) << emp.salary << endl;
    }
}