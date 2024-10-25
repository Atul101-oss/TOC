// Design a Finite Automata (FA) that accepts all strings over S={0, 1} having three consecutive 1's as 
// a substring. Write a program to simulate this FA.

#include <iostream>
using namespace std;

class finiteAutomata{
private:
    string word;
    int index;
    int n;

public:
    finiteAutomata(const string& word) : word(word), n(word.size()), index(0){}

    int dead(){return -1;}

    int transition(int state){
        if (index < n){
            char input = word[index++];
            switch (state){
            case 0:                    /*Initial State*/
                if (input=='1'){return transition(1);}
                else if (input=='0'){return transition(0);}
                else {return dead();}
            case 1:                    /*state1*/
                if (input=='1'){return transition(2);}
                else if (input=='0'){return transition(0);}
                else {return dead();}
            case 2:                    /*state2*/
                if (input=='1'){return transition(3);}
                else if (input=='0'){return transition(0);}
                else {return dead();}
            case 3:                    /*Final State*/
                if (input=='1'){return transition(3);}
                else if (input=='0'){return transition(3);}
                else {return dead();}
            default:
                return dead();
            }
        }else{
            return state;
        }
    }

    bool isValid(){return transition(0)==3;}
};
int main(){
    string word;
    cout << "Enter a string to Check (3 consicutive 1's): "; cin >> word;
    finiteAutomata FA(word);
    cout << (FA.isValid() ? "Accepted" : "Rejected") << endl;

}