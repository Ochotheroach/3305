//Quinton Smith oct 27 2023
#include <iostream>
#include <string>
using namespace std;

enum State {
    q0, q1, q2, q3, q4, q5, q6, q7, q8
};

State transition(State current, char input) {
    switch(current) {
        case q0:
            if (input == '0') return q1;
            else return q0;
        case q1:
            if (input == '0') return q2;
            else return q1;
        case q2:
            if (input == '0') return q3;
            else return q4;
        case q3:
            //dead state
            if (input == '0') return q3;
            else return q3;
        case q4:
            if (input == '0') return q6;
            else return q5;
        case q5:
            if (input == '0') return q7;
            else return q4;
        case q6:
            if (input == '0') return q3;
            else return q5;
        case q7:
            if (input == '0') return q8;
            else return q4;
        case q8:
            if (input == '0') return q3;
            else return q4;
    }
    
}

int main() {
    cout << "Please enter a string, hit enter when you are done entering: ";
    string input;
    cin >> input;

    State current = q0;
    for (char ch : input) {
        current = transition(current, ch);
        cout << "Current state= q" << current << endl;
        cout << "char to read: " << ch << endl;
    }
    
    cout << "Current state: q" << current << endl;
    cout << "Input to read: None" << endl;

    if (current != q3) {
        cout << "The string " << input << " is accepted!" << endl;
    } else {
        cout << "The string " << input << " is not accepted!" << endl;
    }

  
}
