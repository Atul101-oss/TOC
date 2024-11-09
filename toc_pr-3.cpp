// Design a Finite Automata (FA) that accepts language L1, over S={a, b}, comprising of all strings (of
// length 4 or more) having first two characters same as the last two. Write a program to simulate this 
// FA.

#include <iostream>
using namespace std;

int transition(string& word, int& index, int state){
    if (index < word.size()){
        char input = word[index++];
        switch (state)
        {
        case 0:                                             /*Initial State*/
            if (input=='a'){return transition(word, index, 1);}
            else if (input=='b'){return transition(word, index, 8);}
            else {return transition(word, index, -1);}
        
        case 1:                                             /*1st State*/
            if (input=='a'){return transition(word, index, 2);}
            else if (input=='b'){return transition(word, index, 5);}
            else {return transition(word, index, -1);}

        case 2:                                             /*2nd State*/
            if (input=='a'){return transition(word, index, 3);}
            else if (input=='b'){return transition(word, index, 2);}
            else {return transition(word, index, -1);}

        case 3:                                             /*3nd State*/
            if (input=='a'){return transition(word, index, 4);}
            else if (input=='b'){return transition(word, index, 2);}
            else {return transition(word, index, -1);}

        case 4:                                             /*4st State*/
            if (input=='a'){return transition(word, index, 4);}
            else if (input=='b'){return transition(word, index, 2);}
            else {return transition(word, index, -1);}
        
        case 5:                                             /*5st State*/
            if (input=='a'){return transition(word, index, 6);}
            else if (input=='b'){return transition(word, index, 5);}
            else {return transition(word, index, -1);}

        case 6:                                             /*6nd State*/
            if (input=='a'){return transition(word, index, 5);}
            else if (input=='b'){return transition(word, index, 7);}
            else {return transition(word, index, -1);}

        case 7:                                             /*7nd State*/
            if (input=='a'){return transition(word, index, 6);}
            else if (input=='b'){return transition(word, index, 5);}
            else {return transition(word, index, -1);}

        case 8:                                             /*8st State*/
            if (input=='a'){return transition(word, index, 9);}
            else if (input=='b'){return transition(word, index, 12);}
            else {return transition(word, index, -1);}
        
        case 9:                                             /*9st State*/
            if (input=='a'){return transition(word, index, 9);}
            else if (input=='b'){return transition(word, index, 10);}
            else {return transition(word, index, -1);}

        case 10:                                             /*10nd State*/
            if (input=='a'){return transition(word, index, 11);}
            else if (input=='b'){return transition(word, index, 9);}
            else {return transition(word, index, -1);}

        case 11:                                             /*11nd State*/
            if (input=='a'){return transition(word, index, 9);}
            else if (input=='b'){return transition(word, index, 10);}
            else {return transition(word, index, -1);}

        case 12:                                             /*12nd State*/
            if (input=='a'){return transition(word, index, 12);}
            else if (input=='b'){return transition(word, index, 13);}
            else {return transition(word, index, -1);}

        case 13:                                             /*13nd State*/
            if (input=='a'){return transition(word, index, 12);}
            else if (input=='b'){return transition(word, index, 14);}
            else {return transition(word, index, -1);}

        case 14:                                             /*14nd State*/
            if (input=='a'){return transition(word, index, 12);}
            else if (input=='b'){return transition(word, index, 14);}
            else {return transition(word, index, -1);}

        default:                                            /*Dead State*/
            return -1;
        }
    }else{
        return state;
    }
}

bool isValid(string& word){
    int index=0;
    int state = transition(word,index, 0);
    return (state==4 || state==7 || state==11 || state==14);
}

int main(){
    string word;
    cout << "Enter string to check (L => start & last 2 caracters are same): "; cin >> word;

    cout << (isValid(word) ? "Accepted" : "Rejected") << endl;
    return 0;
}