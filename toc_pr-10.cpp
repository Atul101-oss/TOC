// Design and simulate a Turing Machine which will increment the given binary number by 1.

#include <iostream>
using namespace std;

void increment(string& tape){
    tape = '0'+tape;
    int head = size(tape)-1;
    while (tape[head]=='1'){
        tape[head]='0';
        head--;
    }
    if (tape[head]=='0'){tape[head]='1';}
    else{cout << "wrong input\n";}
}

int main() {
    string input;
    cout << "Enter the input string(-1 for exit): ";
    
    cin >> input;
    if (input != "-1"){
    increment(input);
    cout << input<<"\n\n";
    return main();
    }
    return 0;
}
