// Design and simulate a Turing Machine that accepts the language a^n+b^n+c^n where n >0.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TuringMachine {
private:
    string tape;
    int head;

public:
    TuringMachine(){
        cout << "\n-------------------------------------------------";
        cout << "\nturning machine for language {a^n_b^n_c^n | n>=1}";
        cout << "\n-------------------------------------------------";
        cout << endl;
    }

    bool isValid(string input){
        tape = input + "#"; // mark final position
        head = 0;
        return state0(tape,head);
    }

    bool startState(string& tape, int& head){
        while (head>0){
            head--;
        }
        return state0(tape,head);
    }

    bool state2(string& tape, int& head){
        if (tape[head]=='c'){
            tape[head]='X';
            head++;
            return startState(tape,head);
        }
        else if (tape[head]=='X' || tape[head]=='b'){
            head++;
            return state2(tape,head);
        }
        else{
            return false;
        }
    }

    bool state1(string& tape, int& head){
        if (tape[head]=='b'){
            tape[head]='X';
            head++;
            return state2(tape,head);
        }
        else if (tape[head]=='X' || tape[head]=='a'){
            head++;
            return state1(tape,head);
        }
        else{
            return false;
        }
    }

    bool state0(string& tape, int& head){
        if (tape[head]=='a'){
            tape[head]='X';
            head++;
            return state1(tape,head);
        }
        else if (tape[head]=='X'){
            head++;
            return state0(tape,head);
        }
        else if (tape[head]=='#'){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    string input;

    // Initialize Turing Machine with the input
    TuringMachine tm;

    // Run the Turing Machine
    cout << "Enter the input string(-1 for exit): ";
    cin >> input;
    if (input != "-1"){
    cout << (tm.isValid(input)? "Accepted\n":"Rejected\n");
    return main();
    }

    return 0;
}
