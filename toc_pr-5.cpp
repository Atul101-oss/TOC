// Design a Finite Automata (FA) that accepts language EVEN-EVEN over S={a, b}. Write a program 
// to simulate this FA.

#include <iostream>
using namespace std;

class finiteAutomata{
private:
    int index;
    string word;

public:
    finiteAutomata(const string& word) : word(word), index(0){}/*constructur*/

    int transition(int state){
        if (index < word.size()){
            char input = word[index++];
            switch (state)
            {
            case 0:                                             /*Initial State*/
                if (input=='a'){return transition(1);}
                else if (input=='b'){return transition(3);}
                else {return transition(-1);}
            
            case 1:                                             /*1st State*/
                if (input=='a'){return transition(0);}
                else if (input=='b'){return transition(2);}
                else {return transition(-1);}

            case 2:                                             /*2nd State*/
                if (input=='a'){return transition(3);}
                else if (input=='b'){return transition(1);}
                else {return transition(-1);}

            case 3:                                             /*3nd State*/
                if (input=='a'){return transition(2);}
                else if (input=='b'){return transition(0);}
                else {return transition(-1);}

            default:                                            /*Dead State*/
                return -1;
            }
        }else{
            return state;
        }
    }

    bool isValid(){return transition(0)==0;}
};

int main(){
    string word;
    cout << "Enter string to check (L => even a's and b's): ";
    cin >> word;
    finiteAutomata FA(word);
    cout << (FA.isValid() ? "Accepted" : "Rejected") << endl;
    return 0;
}