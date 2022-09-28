/******************************************************
                    _      _    _____  
 _ __  ___ _ __  ___(_) ___| | _|___ / _ __ 
| '__|| _ | '_ / __| |/ __| |/ / |_ || '__|
| |   |  __ |_) __  | (__|   < ___) | | 
|_|   |___| .__/|___/_|___|_|_____/|_|
           |_|       
Author       : repsick3r
Created      : 2022-09-28 20:43
Filename     : 19075062_assignment_5.cpp
******************************************************/
#include<bits/stdc++.h>

using namespace std;

/*
 These below substitutions were used in the code to make coding easier.

 E is E
 E' is e
 T is T
 T' is t
 F is F
 epsilon is n
 id is i
 */

/*
 These are the color schemes used to print the output, i have printed the tree along with the steps tried. 
 */
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

/*
 This below reverseTransform function reverses the substitution to output the original characters. 
 */

string reverseTransform(char c){
    string answer = "";
    if(c == 'E'){
         return "E";
    }
    else if(c == 'e'){
        return "E\'";
    }
    else if(c == 'T'){
        return "T";
    }
    else if(c == 't'){
        return "T\'";
    }
    else if(c == 'F'){
        return "F";
    }
    else if(c == 'n'){
        return "\u03B5";
    }
    else if(c == 'i'){
        return "id";
    }
    else{
        return answer+c;
    }
}

string reverseTransforms(string input){
    string answer = "";
    for(int i=0; i<input.size(); i++){
        answer += reverseTransform(input[i]);
    }
    return answer;
}

/*
 This below transform function transforms the input symbols into our determined characters.
 This returns notvalid if input contains any non terminal or unrecognised symbols.
 */

string transform(string input){
    int inputPtr = 0;
    int nextPtr = inputPtr+1;
    string output = "";
    while(inputPtr < input.size() && output != "notValid"){
        char current = input[inputPtr];
        switch (current){
            case 'i':
                if(nextPtr < input.size() && input[nextPtr] == 'd'){
                     output += 'i';
                     inputPtr += 2;
                     nextPtr = inputPtr;
                     nextPtr += 1;
                     break;
                }
                else{
                    output = "notValid";
                    break;
                }
            case '+':
                    output += '+';
                    inputPtr += 1;
                    nextPtr = inputPtr;
                    nextPtr += 1;
                    break;
            case '(':
                     output += '(';
                     inputPtr += 1;
                     nextPtr = inputPtr;
                     nextPtr += 1;
                     break;
            case ')':
                     output += ')';
                     inputPtr += 1;
                     nextPtr = inputPtr;
                     nextPtr += 1;
                     break;
            case '*':
                     output += '*';
                     inputPtr += 1;
                     nextPtr = inputPtr;
                     nextPtr += 1;
                     break;
            case ' ':
                     inputPtr += 1;
                     nextPtr = inputPtr;
                     nextPtr += 1;
                     break;
            default:
                     output = "notValid";
         } 
    }
    return output;
} 

map<pair<char, char>, string> grammarMap;
vector<vector<string>> finalPrint;
bool isTerminal(char c){
    if(c != 'E' && c != 'e' && c != 'T' && c != 't' && c != 'F' && c != 'n'){
        return true;
    }
    return false;
}

bool stackIt(string input){
    int len = input.size();
    stack<char> s;
    s.push('E');
    int inputPtr = 0; 
    vector<string> temp;
    while(!s.empty()){
        
        temp.clear();
        string matched = "";
        if(inputPtr != 0) matched = reverseTransforms(input.substr(0,inputPtr));
        temp.push_back(matched);
        stack<char> s1 = s;
        string printstack = "";
        while(s1.size()){
            printstack += reverseTransform(s1.top());
            s1.pop();
        }
        printstack += "$";
        temp.push_back(printstack);
        temp.push_back(reverseTransforms(input.substr(inputPtr)));
        
        string action = "";
        
        if(s.top() == input[inputPtr]){
            action = "match ";
            action += reverseTransform(s.top());
            temp.push_back(action);
            s.pop();
            inputPtr++;
        }
        else if(isTerminal(s.top())){
            return false;
        }
        else if(grammarMap.count({s.top(), input[inputPtr]}) == 0){
            return false;
        }
        else{
            action = "output ";
            action += reverseTransform(s.top());
            action += " --> ";
            string rightProd = grammarMap[{s.top(), input[inputPtr]}];
            action += reverseTransforms(rightProd);
            temp.push_back(action);
            s.pop();
            for(int i=rightProd.size()-1; i>=0; i--){
                if(rightProd[i] != 'n'){
                    s.push(rightProd[i]);
                }
            }
        }
        finalPrint.push_back(temp);
    }  
    temp.clear();
    temp.push_back(reverseTransforms(input.substr(0, input.size()-1)));
    temp.push_back("$");
    temp.push_back("$");
    temp.push_back("Success!");
    finalPrint.push_back(temp);
    return true;
}

string beautify(string input){
    string answer = "";
    int total = 15;
    int rem = total - input.size();
    while(rem--){
        answer += " ";
    }
    answer += input;
    return answer;
}

string revbeautify(string input){
    string answer = "";
    int rem = 25 - input.size();
    if(input[0] == 'o' || input[0] == 'm' || input[0] == 'S' || input[0] == 'A'){
        int remi = 10;
        while(remi--){
            answer += " ";
        }
    }
    answer += input;
    while(rem--){
        answer += " ";
    }
    return answer;
}

void printFinal(){
    cout << "--------------------------------------------------------------------------------------------------------------------" << "\n";
    cout << revbeautify("Matched") << "       " << beautify("Stack") << "      " << beautify("Input") << "      " << revbeautify("Action") << "\n";
    cout << "--------------------------------------------------------------------------------------------------------------------" << "\n";
    for(int i=0; i<finalPrint.size(); i++){
        cout << revbeautify(finalPrint[i][0]) << "       " << beautify(finalPrint[i][1]) << "      " <<  beautify(finalPrint[i][2]) << "      " << revbeautify(finalPrint[i][3]) << "\n";
    }
}

int main(int argc, char *argv[]){
    
    grammarMap[{'E', 'i'}] = "Te";
    grammarMap[{'E', '('}] = "Te";
    
    grammarMap[{'e', '+'}] = "+Te";
    grammarMap[{'e', ')'}] = "n";
    grammarMap[{'e', '$'}] = "n";

    grammarMap[{'T', 'i'}] = "Ft";
    grammarMap[{'T', '('}] = "Ft";

    grammarMap[{'t', '+'}] = "n";
    grammarMap[{'t', '*'}] = "*Ft";
    grammarMap[{'t', ')'}] = "n";
    grammarMap[{'t', '$'}] = "n";
    
    grammarMap[{'F', 'i'}] = "i";
    grammarMap[{'F', '('}] = "(E)";
    
   // the input file is given as a argument to the command line which is read for input.
    string filename = argv[1];
    fstream newfile;
    newfile.open(filename, ios::in);
    vector<string> inputs;
    if(newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            inputs.push_back(tp);
        }
        newfile.close();
    }
    cout << inputs.size() << " TestCases" << "\n";
    cout << "Steps are printed whenever we are able to accept the input" << "\n"; 
    for(int tc=0; tc < inputs.size(); tc++){
        string raw_input = inputs[tc];
        string input = transform(raw_input);
        cout <<  "**********************************************************************************************"<< "\n";
        if(input != "notValid"){
            input += '$';
            finalPrint.clear();
            bool globalTruth = stackIt(input);
            if(!globalTruth){
                cout << "This input is not accepted by the grammar : " << raw_input << "\n";
            }
            else{
                printFinal();
                cout << "\n";
                cout << "Input   : " << raw_input << "\n";
                cout << "Matched : " << raw_input << "\n";
            }
        }
        else{
            cout << "Invalid Input\n";
        }
        cout << "**********************************************************************************************"<< "\n";
    }
}
