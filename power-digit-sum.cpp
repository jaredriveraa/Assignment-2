#include <iostream>
#include <string>
#include <vector>
#include <cmath> // using this inclusion for Task 2
#include <cstdlib>  // https://www.geeksforgeeks.org/cpp/convert-string-to-int-in-cpp/ : I read that you can't simply convert a string by attaching int to it
                    // you need this inclusion to use stoi which will allow for the conversion in C++

using namespace std; 

vector<int> vectorize_digits(unsigned long long n) {
    vector<int> digits;
        if (n == 0) { //base case which returns a vector with the digit 0 rather than a completely empty vector
            digits.push_back(0);
            return digits;
        }
        while (n > 0) { //essentially what I had before for retrieving digits before except now I'm forcing them into a vector
            
            int digit = n % 10; //allows me to extract each digit from the long given by the user
            digits.insert(digits.begin(), digit); // allows the digits to be inserted at the front of the vector
            n /= 10;
    }
    return digits;
}

int sum_vector(vector<int> v) {
    int sum = 0; 
    for (size_t i = 0; i < v.size(); i++) { //a simple for loop that takes all the elements of the vector and adds them to the existing sum
        sum = sum + v[i]; //size_t refers to the number of elements within an array/vector. i previously used int i, but the complier gave warnings referring to signed ints being compared to unsigned ints

    }
    return sum;

}

string vec_to_string(vector<int> vec) {
    string vecstring = "["; //begin building the string using open bracket
    for (size_t i = 0; i < vec.size(); i++) { //loops through the contents of the vector, adding them each to the string
        vecstring = vecstring + to_string(vec[i]);
        if (i < vec.size() - 1) { //as long as we're not to the end of the vector, we place commas in between each of the digits
            vecstring = vecstring + ",";
        }
    }
    vecstring = vecstring + "]"; //complete the string by using a closed bracket and then returning the string to main().
    return vecstring;
}

unsigned long long int power(unsigned int a , unsigned int b) { //loop is responsible for calculating the power. the loop essentially uses b as the limiter and multiplies a against itself until it reaches b number of times
    unsigned long long sum = 1;
    for (unsigned int i = 0; i < b; i++) {
        sum = sum * a;
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
    
    cout << "a:" <<endl;
    cin >> a_string; //taking in user input as strings
    cout << "b:" <<endl;
    cin >> b_string;


    if (!isNumber(a_string) || !isNumber(b_string)) { //uses the boolean isNumber to check both inputs using same loop to see if they are anything other than numbers
        cout << "The inputs must be integers. Please try again and enter an integer" <<endl;
        return 1; //1 of 3 input checks (inputs must be integers)
    }

    if (a_string[0] == '-' || b_string[0] == '-') { //2 of 3 input checks to ensure nonnegative integers are being given
    cout << "The inputs must be nonnegative integers. Please try again and enter a nonnegative integer." << endl; 
    return 1; // returning 1 stops the program immediately 
}


    unsigned int a = stoi(a_string); //converting a and b into integers using stoi() to compute the power manually
    unsigned int b = stoi(b_string); //must create new int variables

    double projected_size = b * log(a); //meant to anticipate the size of a^b before being stored as an unsigned long long
    double limit = 64 * log(2); //essentially the limit for the memory that can be stored as an unsigned long long

    if (projected_size >= limit) { //the actual check which prevents overflow by throwing error message (3 of 3 input checks)
        cout << "a^b is too large and will overflow an unsigned long long" <<endl;
        return 1; //this line stops the program
    }


    unsigned long long answer = power(a,b); //call the function power to retrieve the answer
    cout << answer << endl;

    // int sum = 0; //calculating the sum of the digits using modulus division since I classified the answer as an int already
    // while (answer > 0) {
    //     sum += answer % 10;  //gives me the last digit using modulus
    //     answer /= 10;        //removes the last digit using division
    // }
    vector<int> digits = vectorize_digits(answer);
    int sum = sum_vector(digits);
    cout << "Sum of digits:" << sum <<endl;
    return 0; //allows the program to run as long as there are no errors 

    }
    
