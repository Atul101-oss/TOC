// Design a Finite Automata (FA) that accepts language L1, over S={a, b}, comprising of all strings (of
// length 4 or more) having first two characters same as the last two. Write a program to simulate this 
// FA.

// there wiil bw atleast 4 states;
#include <iostream>;
using namespace std;

class finiteAutomata{
private:
    string word;
    int state;
    int index;

public:
    finiteAutomata(){
        cout << "Enter a String to Check: ";
        cin >> word;
    }

    bool isValid(){
        if (transition(0)==)
    }
}

int main(){

    finiteAutomata FA();
    cout << (FA.isValid() ? "Accepted" : "Rejected");
    return 0;
}