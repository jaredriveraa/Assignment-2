#include <iostream>
#include <string>
#include <cstdlib>  // https://www.geeksforgeeks.org/cpp/convert-string-to-int-in-cpp/ : I read that you can't simply convert a string by attaching int to it
                    // you need this inclusion to use stoi which will allow for the conversion in C++

using namespace std; 
int pow(int base ,int power) { //loop is responsible for calculating the power. the loop essentially uses b as the limiter and multiplies a against itself until it reaches b number of times
    int sum = 1;
    for (int i = 0; i < power; i++) {
        sum *= base;
    }
    return sum; 
    }

//another function to initialize a check on the inputs given for a_string and b_string
bool isNumber(string& s){//takes the string using pass by reference which we learned in lecture to avoid making unnecessary copies
        for (char c : s) { //loops through all the characters in the string to ensure only digits are allowed
            if (!isdigit(c)) {
                return false;
        }
    }
    return true;
}


int main() { //chose ints for a,b,n because realistically the user will not input numbers larger than what an int is capable of storing
    string a_string; // initalizing a and b as string variables
    string b_string;
    
    cout << "a:";
    cin >> a_string; //taking in user input as strings
    cout << "b:";
    cin >> b_string;


    if (!isNumber(a_string) || !isNumber(b_string)) { //uses the boolean isNumber to check both inputs using same loop to see if they are anything other than numbers
        cout << "The inputs must be numbers. Please try again and enter a number" <<endl;
    }

    int a = stoi(a_string); //converting a and b into integers using stoi() to compute the power manually
    int b = stoi(b_string); //must create new int variables

    if (a < 0 || b < 0) {
        cout << "Both inputs must be positive numbers. Please try again and enter numbers greater than 0" <<endl;
    }
    int answer = pow(a,b); //call the function pow to retrieve the answer
    cout << answer << endl;

    int sum = 0; //calculating the sum of the digits using modulus division since I classified the answer as an int already
    while (answer > 0) {
        sum += answer % 10;  //gives me the last digit using modulus
        answer /= 10;        //removes the last digit using division
    }
    cout << "Sum of digits:" << sum <<endl;
    return 0;

    }
    
