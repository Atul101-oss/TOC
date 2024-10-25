// Design a PDA and write a program for simulating the machine which accepts the language 
// {anbn  where n>0, S= {a, b}}. 

#include <iostream>
#include <stack>
using namespace std;
stack<char> pda_stack;

bool PDA(const string& word, int index=0){
    while(index<word.size()){
        char input = word[index++];
        if (input=='a'){pda_stack.push(input);}
        else if (input=='b' && !pda_stack.empty()){pda_stack.pop();}
        else return false;
    }
    return pda_stack.empty();
}


bool transition(string& word, int state, int index){
    if (index<word.size()){
        switch(state){
        case 0:                                 /*stack push*/
            if (word[index]=='a'){
                pda_stack.push('a');
                index++;
                return transition(word, 0,index);
            }
            else if (word[index]=='b'){
                return transition(word, 1,index);
            }else{
                return transition(word, -1,index);
            }
        case 1:                                 /*stack pop*/
            if (word[index]=='b'){
                pda_stack.pop();
                index++;
                return transition(word, 1,index);
            }else{
                return transition(word,-1,index);
            }
        default:                                /*Dead*/
            return false;
        }
    }
    return pda_stack.empty();
}


bool isValid_PDA(string& word){
    int state = 0;
    int index = 0;
    return transition(word, state, index);
}


int main(){
    string word;
    cout << "Enter a string to check (over L(G)=> a^n.b^n): ";
    cin >> word;
    cout << (isValid_PDA(word) ? "Accepted" : "Rejected") <<endl;
    return 0;
}