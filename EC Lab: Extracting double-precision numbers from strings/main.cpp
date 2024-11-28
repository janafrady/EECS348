#include <iostream>
#include <iomanip> // for formatting a double-precision number
using namespace std; // to avoid repeating std::

// checks if string is valid and returns either the float of the string or -999999.99 if invalid
double extractNumeric (const string& str) {
    int length = str.length(); 
    bool is_signed = (str[0] == '-' || str[0] == '+');
    for (int i = is_signed; i < length; i++){
        int temp = str[i];
        if (temp < 46 || temp > 57 || temp == 47){ // checks if ASCII value is valid
            return -999999.99; // returns if the value is invalid
        }
    }
    return stod(str); // returns the string as a float
}

// launching point of program
int main(){
    string input;
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        if (input == "END") { // breaks if input is "END"
            break;
        }
        double number = extractNumeric(input);
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    cout << "Goodbye..." << endl;
    return 0;
}
