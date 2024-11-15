// Write a program to simulate an FA that accepts  
// a. Union of the languages L1 and L2 
// b. Intersection of the languages L1 and L2 
// c. Language L1 L2 (concatenation)

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Utility to check if a string is accepted by a DFA
bool isAcceptedByDFA(const vector<vector<int>>& transitionTable, 
                     int startState, 
                     const set<int>& finalStates, 
                     const string& input) {
    int currentState = startState;
    for (char c : input) {
        int symbol = c - '0'; // Assuming binary inputs ('0' and '1')
        if (symbol < 0 || symbol >= transitionTable[0].size()) {
            return false; // Invalid symbol
        }
        currentState = transitionTable[currentState][symbol];
    }
    return finalStates.count(currentState) > 0;
}

// Simulate union of L1 and L2
bool unionFA(const vector<vector<int>>& dfa1, int start1, const set<int>& final1,
             const vector<vector<int>>& dfa2, int start2, const set<int>& final2,
             const string& input) {
    return isAcceptedByDFA(dfa1, start1, final1, input) || 
           isAcceptedByDFA(dfa2, start2, final2, input);
}

// Simulate intersection of L1 and L2
bool intersectionFA(const vector<vector<int>>& dfa1, int start1, const set<int>& final1,
                    const vector<vector<int>>& dfa2, int start2, const set<int>& final2,
                    const string& input) {
    return isAcceptedByDFA(dfa1, start1, final1, input) && 
           isAcceptedByDFA(dfa2, start2, final2, input);
}

// Simulate concatenation of L1 and L2
bool concatenationFA(const vector<vector<int>>& dfa1, int start1, const set<int>& final1,
                     const vector<vector<int>>& dfa2, int start2, const set<int>& final2,
                     const string& input) {
    for (size_t i = 0; i <= input.size(); ++i) {
        string prefix = input.substr(0, i);      // First part for DFA1
        string suffix = input.substr(i);        // Second part for DFA2
        
        if (isAcceptedByDFA(dfa1, start1, final1, prefix) &&
            isAcceptedByDFA(dfa2, start2, final2, suffix)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Define DFA1
    vector<vector<int>> dfa1 = {{1, 0}, {1, 2}, {2, 2}}; // Transition table
    int start1 = 0;                                      // Start state
    set<int> final1 = {2};                               // Final states

    // Define DFA2
    vector<vector<int>> dfa2 = {{1, 0}, {0, 2}, {2, 2}};
    int start2 = 0;
    set<int> final2 = {2};

    string input;
    cout << "Enter the input string: ";
    cin >> input;

    // Simulate union
    if (unionFA(dfa1, start1, final1, dfa2, start2, final2, input)) {
        cout << "Input is accepted by the union of L1 and L2.\n";
    } else {
        cout << "Input is not accepted by the union of L1 and L2.\n";
    }

    // Simulate intersection
    if (intersectionFA(dfa1, start1, final1, dfa2, start2, final2, input)) {
        cout << "Input is accepted by the intersection of L1 and L2.\n";
    } else {
        cout << "Input is not accepted by the intersection of L1 and L2.\n";
    }

    // Simulate concatenation
    if (concatenationFA(dfa1, start1, final1, dfa2, start2, final2, input)) {
        cout << "Input is accepted by the concatenation of L1 and L2.\n";
    } else {
        cout << "Input is not accepted by the concatenation of L1 and L2.\n";
    }

    return 0;
}
