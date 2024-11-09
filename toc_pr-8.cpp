// Design a PDA and write a program for simulating the machine which accepts the language {wXwr| w 
// is any string over S={a, b} and wr is reverse of that string and X is a special symbol }.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class PDA{
    stack<char> PDAstack;
    public:

    bool state1(string& str, int index, int& n){
        while (index<n){
            if (PDAstack.top() == str[index]){
                PDAstack.pop();
                index++;
            }else{
                return false;
            }
        }
        return (PDAstack.empty() ? true : false);
    }

    bool state0(string& str, int index, int& n){
        while (str[index] != '|' && index<n){
            PDAstack.push(str[index]);
            index++;
        }
        return state1(str,++index,n);
    }
    bool isValid(string str){
        int index = 0;
        int n = str.length();
        return state0(str,index,n);
    }

};

int main(){
    string w;
    cout << "Enter a string to check for L={wXw^r | w=(a,b)*, X=|}:  "; cin >> w;

    PDA pda;
    cout <<endl<< (pda.isValid(w) ? w+" is a valid string" : w+" is not a valid string ") << endl;

    return 0;
}