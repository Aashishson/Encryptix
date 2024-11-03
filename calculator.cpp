#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the calculator" << endl;
    int x;
    cout << "Enter \n 1. for addition (+) \n 2. for subtraction (-) \n 3. for division (/) \n 4. for multiplication (*) \n" << endl;
    cin >> x;
    
    int a, b;
    cout << "Enter the value of a: " << endl;
    cin >> a;
    cout << "Enter the value of b: " << endl;
    cin >> b;

    switch (x) {
        case 1:
            cout << "Result: " << a + b << endl;
            break;
        case 2:
            cout << "Result: " << a - b << endl;
            break;
        case 3:
            if (b != 0) {
                cout << "Result: " << a / b << endl;
            } else {
                cout << "Error: Division by zero is undefined!" << endl;
            }
            break;
        case 4:
            cout << "Result: " << a * b << endl;
            break;
        default:
            cout << "Invalid number, try again!" << endl;
    }
    return 0;
}
