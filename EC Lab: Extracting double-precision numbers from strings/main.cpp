#include <iostream>
#include <iomanip> // for formatting a double-precision number
#include <string>
using namespace std; // to avoid repeating std::

// returns if string is valid or not
bool is_Valid (const string& str){
    int length = str.length();
    int count = 0;
    bool is_signed = (str[0] == '-' || str[0] == '+');
    bool is_val = true;
    
    for (int i = is_signed; i < length; i++){
        if (str[i] < '.' || str[i] > '9' || str[i] == '/'){ // checks if ASCII value is valid
            is_val = false;
        }
        if (str[i] == '.') count++;
    }

    // outlier cases
    if (count > 1) is_val = false; // checks if a period appears twice
    if (is_signed && length == 1) is_val = false; // checks if only + or - is entered
    if (str[0] == '.' && length == 1) is_val = false; // checks if only . is entered
    if (is_signed && str[1] == '.' && length == 2) is_val = false; // checks if only +. or -. is entered

    return is_val; // returns true if valid, false otherwise
}

// converts string to double-precision floating number
double extractNumeric (const string& str) {
    int length = str.length(); 
    bool is_signed = (str[0] == '-' || str[0] == '+');

    int index = is_signed;
    double result = 0.0;

    // converts and adds whole numbers to result
    while (isdigit(str[index]) && index < length){
        result = result * 10 + (str[index] - '0'); // uses ASCII values to convert string to int and adds to result
        index++;
    }

    // converts ands adds the decimal places to result
    if (index < length && str[index] == '.'){
        index++;
        double dec = 0.1;
        while(isdigit(str[index]) && index < length){
            result += (str[index] - '0') * dec;
            dec /= 10;
            index++;
        }
    }

    if (is_signed) if (str[0] == '-') result = -result; // if it's negative
    return result; // returns the string as a float
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

        if (is_Valid(input)) {
            double number = extractNumeric(input);
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }

    }
    cout << "Goodbye..." << endl;
    return 0;
}
