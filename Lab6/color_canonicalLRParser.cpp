#include <bits/stdc++.h>
using namespace std;

//coloring schema
string color7 = "[38;5;197;1m";  
string color5 = "[48;5;85;38;5;000;1m";
string color9 = "[38;5;85;1m";
string color6 = "[38;5;154;1m";
string color8 = "[38;5;055;1m";
string color10 = "[38;5;055m";
string color11 = "[38;2;214;134;94;1m";
string color12 = "[38;5;82;1m";

char escape = 27;
string aum =  "[0m ";  

map<pair<int, char>, string> action;
map<pair<int, char>, int> _goto;

void initialise_grammar(unordered_map<int, pair<char, string>> &grammar) {
  grammar[1] = {'E', "TA"};
  grammar[2] = {'A', "+TA"};
  grammar[3] = {'A', "e"};
  grammar[4] = {'T', "FB"};
  grammar[5] = {'B', "*FB"};
  grammar[6] = {'B', "e"};
  grammar[7] = {'F', "(E)"};
  grammar[8] = {'F', "i"};
  return;
}

void initialise_action_table() {
  action[ {0, '('}] = "s4";
  action[ {0, 'i'}] = "s5";

  action[ {1, '$'}] = "accept";

  action[ {2, '+'}] = "s7";
  action[ {2, '$'}] = "r3";

  action[ {3, '+'}] = "r6";
  action[ {3, '*'}] = "s9";
  action[ {3, '$'}] = "r6";

  action[ {4, '('}] = "s13";
  action[ {4, 'i'}] = "s14";

  action[ {5, '+'}] = "r8";
  action[ {5, '*'}] = "r8";
  action[ {5, '$'}] = "r8";

  action[ {6, '$'}] = "r1";

  action[ {7, '('}] = "s4";
  action[ {7, 'i'}] = "s5";

  action[ {8, '+'}] = "r4";
  action[ {8, '$'}] = "r4";

  action[ {9, '('}] = "s4";
  action[ {9, 'i'}] = "s5";

  action[ {10, ')'}] = "s17";

  action[ {11, '+'}] = "s19";
  action[ {11, ')'}] = "r3";

  action[ {12, '+'}] = "r6";
  action[ {12, '*'}] = "s21";
  action[ {12, ')'}] = "r6";

  action[ {13, '('}] = "s13";
  action[ {13, 'i'}] = "s14";

  action[ {14, '+'}] = "r8";
  action[ {14, '*'}] = "r8";
  action[ {14, ')'}] = "r8";

  action[ {15, '+'}] = "s7";
  action[ {15, '$'}] = "r3";

  action[ {16, '+'}] = "r6";
  action[ {16, '*'}] = "s9";
  action[ {16, '$'}] = "r6";

  action[ {17, '+'}] = "r7";
  action[ {17, '*'}] = "r7";
  action[ {17, '$'}] = "r7";

  action[ {18, ')'}] = "r1";

  action[ {19, '('}] = "s13";
  action[ {19, 'i'}] = "s14";

  action[ {20, '+'}] = "r4";
  action[ {20, ')'}] = "r4";

  action[ {21, '('}] = "s13";
  action[ {21, 'i'}] = "s14";

  action[ {22, ')'}] = "s27";

  action[ {23, '$'}] = "r2";

  action[ {24, '+'}] = "r5";
  action[ {24, '$'}] = "r5";

  action[ {25, '+'}] = "s19";
  action[ {25, ')'}] = "r3";

  action[ {26, '+'}] = "r6";
  action[ {26, '*'}] = "s21";
  action[ {26, ')'}] = "r6";

  action[ {27, '+'}] = "r7";
  action[ {27, '*'}] = "r7";
  action[ {27, ')'}] = "r7";

  action[ {28, ')'}] = "r2";

  action[ {29, '+'}] = "r5";
  action[ {29, ')'}] = "r5";
  return;
}

void initialise_goto_table() {
  _goto[ {0, 'E'}] = 1;
  _goto[ {0, 'T'}] = 2;
  _goto[ {0, 'F'}] = 3;
  _goto[ {2, 'A'}] = 6;
  _goto[ {3, 'B'}] = 8;
  _goto[ {4, 'E'}] = 10;
  _goto[ {4, 'T'}] = 11;
  _goto[ {4, 'F'}] = 12;
  _goto[ {7, 'T'}] = 15;
  _goto[ {7, 'F'}] = 3;
  _goto[ {9, 'F'}] = 16;
  _goto[ {11, 'A'}] = 18;
  _goto[ {12, 'B'}] = 20;
  _goto[ {13, 'E'}] = 22;
  _goto[ {13, 'T'}] = 11;
  _goto[ {13, 'F'}] = 12;
  _goto[ {15, 'A'}] = 23;
  _goto[ {16, 'B'}] = 24;
  _goto[ {19, 'T'}] = 25;
  _goto[ {19, 'F'}] = 12;
  _goto[ {21, 'F'}] = 26;
  _goto[ {25, 'A'}] = 28;
  _goto[ {26, 'B'}] = 29;

  return;
}


void print_current(stack<int> st, stack<char> syt, string s, int ind) {

  //STATE TABLE
  string str = "";
  while (!st.empty()) {
    str += to_string(st.top());
    str += " ";
    st.pop();
  }
  cout << escape << color6 << str << string(20 - str.size(), ' ') << escape << aum;

  //SYMBOL TABLE
  str = "";
  while (!syt.empty()) {
    char ch = syt.top();
    if (ch == 'i')str += "di";
    else {
      str += ch;
    }
    syt.pop();
  }
  reverse(str.begin(), str.end());
  cout << escape << color9 << str << string(10 - str.size(), ' ') << escape << aum;
  str = "";
  for (ind; ind < s.size(); ind++) {
    if (s[ind] == 'i')str += "id";
    else {
      str += s[ind];
    }
  }
  cout << escape << color8 << string(20 - str.size(), ' ') << str << string(20, ' ') << escape << aum;
}


bool canonical_lr_parser(unordered_map<int, pair<char, string>> &grammar, string s, int ind) {
  stack<int> state_table;
  stack<char> symbol_table;
  symbol_table.push('$');
  state_table.push(0);
  while (true) {
    print_current(state_table, symbol_table, s, ind);
    int tp = state_table.top();
    if (!action.count({tp, s[ind]}))return false;

    string act = action[ {tp, s[ind]}];
    if (act[0] == 's') {
      act = act.substr(1);
      state_table.push(stoi(act));
      symbol_table.push(s[ind]);
      ind++;
      cout << escape << color7 << "shift to " << act << escape << aum << endl;
    }

    else if (act[0] == 'r') {
      act = act.substr(1);
      pair<char, string> red = grammar[stoi(act)];
      int len = red.second.size();
      if (red.second == "e")len = 0;
      while (len--) {
        state_table.pop();
        symbol_table.pop();
      }
      int t = state_table.top();
      if (!_goto.count({t, red.first}))return false;
      state_table.push(_goto[ {t, red.first}]);
      symbol_table.push(red.first);
      cout << escape << color7 << "reduce by " << red.first << " --> " << red.second << escape << aum << endl;
    }

    else if (act == "accept") {
      cout << escape << color5 << "Accepted" << escape << aum << endl;
      return true;
    }

    else {
      return false;
    }


  }
  return false;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("19075062_output.txt", "w", stdout);
#endif
  unordered_map<int, pair<char, string>> grammar;

  /*Grammar Used
    E -> TA
    A -> +TA | e (Replacing E' with A)
    T -> FB (Replacing T' with B)
    B -> *FB | e
    F -> (E) | id */
  initialise_grammar(grammar);
  initialise_action_table();
  initialise_goto_table();
  string s;
  ifstream myfile ("19075062_input.txt");

  while (getline(myfile, s)) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout << escape << color12 << "--------------------------------------------------------------------------------------------------------------------" << escape << aum << "\n";    
    cout << escape << color12 << "--------------------------------------------------------------------------------------------------------------------" << escape << aum << "\n";    
    cout << "\n";
    cout << escape << color11 << "Given Input : " << s << endl << endl;
    s.erase(remove(s.begin(), s.end(), 'd'), s.end());
    s.push_back('$');
    int ind = 0;
    cout << escape << color12 << string(90, '-') << endl;
    cout << escape << color11 << "STATE               SYMBOL                  INPUT                      ACTION" << endl;
    cout << escape << color12 << string(90, '-') << endl;
    bool check = canonical_lr_parser(grammar, s, ind);
    if (check == true)cout << endl << escape << color11 << "Input is validated!" << escape << aum << endl;
    else cout << escape << color5 << "Error" << escape << aum << endl << endl << escape << color11 << "Input can't be validated!" << escape << aum << endl;

    // cout << escape << color12 << string(80, '~') << endl << endl;
    // cout << escape << color12<< "--------------------------------------------------------------------------------------------------------------------" << escape << aum << "\n";        
  }
  return 0;
}
