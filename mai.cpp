// main.cpp
#include "PayrollSystem.h"

int main() {
    PayrollSystem ps;
    ps.addEmployee(1, "John Doe", 20.5, 40);
    ps.addEmployee(2, "Jane Smith", 22.0, 35);
    ps.displayPayroll();
    return 0;
}