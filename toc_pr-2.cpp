//Design a Finite Automata (FA) that accepts all strings over S={0, 1} having either exactly two 1's or 
//exactly three 1's, not more nor less. Write a program to simulate this FA.

#include<iostream>
using namespace std;

class finiteAutomata{
private:
    int index=-1;
    const int n;
    string word;

public:
    finiteAutomata(const string& word) : word(word), n(word.size()-1) {}
    
    int state0(int& index, const int& n);
    int state1(int& index, const int& n);
    int state2(int& index, const int& n);
    int state3(int& index, const int& n);
    int dead(){return -1;}

    bool isValid(){
        int finalState = state0(index,n);
        return (finalState==2 || finalState==3);}

};

int finiteAutomata::state0(int& index, const int& n){
    if(index<n){
        index++;
        if (word[index]=='1'){ return state1(index,n);}
        else if (word[index]=='0'){return state0(index,n);}
        else {return dead();}
    }else{return 0;}
}
        
int finiteAutomata::state1(int& index, const int& n){
    if(index<n){
        index++;
        if (word[index]=='1'){return state2(index,n);}
        else if (word[index]=='0'){return state1(index,n);}
        else {return dead();}
    }else{return 1;}
}
        
int finiteAutomata::state2(int& index, const int& n){
    if(index<n){
        index++;
        if (word[index]=='1'){return state3(index,n);}
        else if (word[index]=='0'){return state2(index,n);}
        else {return dead();}
    }else{return 2;}
}

int finiteAutomata::state3(int& index, const int& n){
    if(index<n){
        index++;
        if (word[index]=='1'){return dead();}
        else if (word[index]=='0'){return state3(index,n);}
        else {return dead();}
    }else{return 3;}
}

    
int main(){
    string word;
    cout << "Enter a string to check: "; cin >> word;
    finiteAutomata FA(word);
    cout << (FA.isValid() ? "Accepted" : "Rejected") << endl;
    }