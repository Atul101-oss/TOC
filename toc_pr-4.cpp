#include <iostream>
using namespace std;

class finiteAutomata {
private:
    int index = 0;  // Start index at 0
    const int n;
    string word;

public:
    finiteAutomata(const string& word) : word(word), n(word.size()) {}
    
    int dead() { return -1; }

        int state3(int& index, const int& n) {
        if (index < n) {
            if (word[index] == '1') {
                return dead();
            } else if (word[index] == '0') {
                index++;
                return state3(index, n);
            } else {
                return dead();
            }
        }
        return 3;
    }

    int state2(int& index, const int& n) {
        if (index < n) {
            if (word[index] == '1') {
                index++;
                return state3(index, n);
            } else if (word[index] == '0') {
                index++;
                return state2(index, n);
            } else {
                return dead();
            }
        }
        return 2;
    }

    int state1(int& index, const int& n) {
        if (index < n) {
            if (word[index] == '1') {
                index++;
                return state2(index, n);
            } else if (word[index] == '0') {
                index++;
                return state1(index, n);
            } else {
                return dead();
            }
        }
        return 1;
    }

    int state0(int& index, const int& n) {
        if (index < n) {
            if (word[index] == '1') {
                index++;
                return state1(index, n);
            } else if (word[index] == '0') {
                index++;
                return state0(index, n);
            } else {
                return dead();
            }
        }
        return 0;
    }

    bool isValid() {
        int finalState = state0(index, n);
        return (finalState == 2 || finalState == 3);
    }

};

int main() {
    string word;
    cout << "Enter a string to check: ";
    cin >> word;
    finiteAutomata FA(word);
    cout << (FA.isValid() ? "Accepted" : "Rejected") << endl;
    return 0;
}
