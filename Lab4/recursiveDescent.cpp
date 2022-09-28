/******************************************************
                    _      _    _____  
 _ __  ___ _ __  ___(_) ___| | _|___ / _ __ 
| '__|| _ | '_ / __| |/ __| |/ / |_ || '__|
| |   |  __ |_) __  | (__|   < ___) | | 
|_|   |___| .__/|___/_|___|_|_____/|_|
           |_|       
Author       : repala sudhamsh
Created      : 2022-09-07 16:51
Filename     : recDes.cpp
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

char escape = 27;
int inputPtr;
int globalTruth;
int printedTimes;
int inputSize;
string inputString;
string origString;

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

map<char, vector<string>> grammarMap;

bool isTerminal(char c){
    if(grammarMap.count(c) == 0 && c != 'n'){
        return true;
    }
    return false;
}

struct treeNode {
  char treeChar;
  int space;
  int currentOption = -1;
  vector<treeNode*> child;
};

map<treeNode*, treeNode*> parentNodes;

treeNode* root; 

/*
 This takes care of finding the next right node to which expansion is applied , considering the top down approach. 
 Similar to FOLLOW function.
 */

treeNode* getNexts(treeNode* currentNode){
    treeNode* node = currentNode;
    while(node != root){
        if(parentNodes[node]->child[parentNodes[node]->child.size()-1] != node){
            return parentNodes[node]->child[parentNodes[node]->child.size()-1];
        }
        node = parentNodes[node];
    }
    return root;
}

/*
 This function printNTree is used to print the tree beautifully.
*/

string finalPrint = "";
void printNTree(treeNode* x, vector<bool> flag, int depth = 0, bool isLast = false)
{
    if (x == NULL)
        return;

    for (int i = 1; i < depth; ++i) {
        if(flag[i] == true){
            cout <<  "| " << " " << " " << " ";
        }
        else{
            cout <<  " "  << " " << " " << " ";
        }
    }

    if(depth == 0){
         cout << reverseTransform(x->treeChar) << '\n';
    }
    else if(isLast){
        string  str =  reverseTransform(x->treeChar);
        if(isTerminal(x->treeChar) || x->treeChar == 'n'){
             finalPrint += str; 
             //cout <<  str << "\n";
             cout << "+--- " << str << '\n';
        }
        else{
             cout << "+--- " << str << '\n';
        }
        flag[depth] = false;
    }
    else{
        string str = reverseTransform(x->treeChar);
        if(isTerminal(x->treeChar) || x->treeChar == 'n'){
            finalPrint += str;
           // cout <<  str << "\n";
            cout << "+--- " << str << '\n';
        }
        else{
             cout << "+--- " << str << '\n';
        }
    }

    int it = 0;
    for (auto i = 0; i < x->child.size(); ++i, ++it){
        printNTree(x->child[i], flag, depth + 1, it == (x->child.size()) - 1);
    }
    //cout << finalPrint << "\n";
    flag[depth] = true;
}

void printTree(){
    treeNode* te = root;
    queue<treeNode*> q;
    q.push(te);
    te->space = 12;
    int total = 0;
    while(!q.empty()){
        int len = q.size();
        while(len--){
            total++;
            //if(q.front()->child.size() == 0) finalPrint += reverseTransform(q.front()->treeChar);
            for(int i=0; i<q.front()->child.size(); i++){
                q.push(q.front()->child[i]);
            }
            q.pop();
        }
    }
    
    vector<bool> flag(total, true);
    finalPrint = "";
    cout << "\n";
    printNTree(te, flag);
    cout << "\n";
    cout << "input  : " << origString << "\n";
    cout << "output : " << finalPrint << "\n";
    cout << "\n";
}

bool buildTree(treeNode* currentNode){
    treeNode* nextn = getNexts(currentNode);
    int thisPtr = inputPtr;
    int tempi = 0;
    // use a new option or a new transform grammar rule for the same expression as previous one failed to accept the grammar.
    currentNode->currentOption += 1; 
    // These following if else are for printing intermediate steps
    if(isTerminal(currentNode->treeChar)){
        cout << reverseTransform(currentNode->treeChar) << " " << "matching with : " << reverseTransform(inputString[inputPtr]) << "\n";
    }
    else if(currentNode->treeChar == 'n'){
        cout << reverseTransform('n') << "\n";
    }
    else{
         if(currentNode->currentOption >= grammarMap[currentNode->treeChar].size()){
             cout << reverseTransform(currentNode->treeChar) << " " << "all options exhausted!" << "\n";
         }
         else{
             string tempPrint = "";
             string grmm = grammarMap[currentNode->treeChar][currentNode->currentOption];
             for(char c : grmm){
                tempPrint += reverseTransform(c);
             }
    cout << reverseTransform(currentNode->treeChar) << " " << "checking for this rule : " << reverseTransform(currentNode->treeChar) << " -> " << tempPrint << "\n";
         }
    }

    if(isTerminal(currentNode->treeChar)){
        if(inputString[inputPtr] == currentNode->treeChar){
            // it means we have got a terminal symbol which also matches with the input string.
            inputPtr++;
            return buildTree(nextn);
        }
        else{
            // our non terminal doesnt match with the given input symbol.
            return false;
        }
    }
    else if(currentNode->treeChar == 'n'){
        // if the current produced symbol is epsilon we simply ignore it and move forward.
        return buildTree(nextn);
    }
    //check for the condition if the options or grammar transformation are all exhausted , then we return false.
    if(currentNode->currentOption >= grammarMap[currentNode->treeChar].size()) return false;
    string currentStr = grammarMap[currentNode->treeChar][currentNode->currentOption];
  
    // we delete previously added children which are a result of using some other grammar rule.
    for(auto kid : currentNode->child){
        delete kid;
    }
    currentNode->child.clear();
    
    // we generate child for the current node which are based upon the grammar rule selected.
    for(auto c : currentStr){
        treeNode* kid = new treeNode();
        kid->treeChar = c;
        currentNode->child.push_back(kid);
        parentNodes[kid] = currentNode;
    }
    // if the input string is exhausted we now check if all the remaining non terminals are able to produce epsilon , in which case we can accept the input.
    if(inputPtr >= inputSize){
        int flag = 1;
        for(auto childrens : currentNode->child){
            if(childrens->treeChar != 'n'){
                flag = 0;
                break;
            } 
        }
        if(flag){
            if(getNexts(currentNode) != root){ 
                return buildTree(getNexts(currentNode));
            }
            else{
                if(printedTimes == 0){
                // we have not printed previously and both the input and the parse tree are completely formed matching each other.
                printTree();
                printedTimes = 1;
                }
                globalTruth = 1;
                return true;
            }
        }
        else{
            inputPtr = thisPtr;
            return buildTree(currentNode);
        }
    }

    bool bol = true;
    int teflag = 0;

    for(auto childrens : currentNode->child){
        if(bol && inputPtr < inputString.size()){
              if(isTerminal(childrens->treeChar)){
                 if(childrens->treeChar == inputString[inputPtr]){
                    inputPtr++;
                    continue;    
                 }
                 else{
                    inputPtr = thisPtr;
                    return buildTree(currentNode);
                 }
              }
              else if(childrens->treeChar == 'n'){
                  teflag = 1; 
                  continue;
              }
              else{
                    bol &=  buildTree(childrens);
              }
        }
        else{
            inputPtr = thisPtr;
            return buildTree(currentNode);
        }
    }
    if(bol == false) return false;
    if(getNexts(currentNode) == root){
        return inputPtr == inputString.size();
    }
    return buildTree(getNexts(currentNode));
}


int main(int argc, char *argv[]){
    
    // making a map to store all the grammar rules based on transformed symbols. 
    grammarMap['E'].push_back("Te");
    grammarMap['e'].push_back("+Te");
    grammarMap['e'].push_back("n");
    grammarMap['T'].push_back("Ft");
    grammarMap['t'].push_back("*Ft");
    grammarMap['t'].push_back("n");
    grammarMap['F'].push_back("(E)");
    grammarMap['F'].push_back("i");
  
   // string ginput = "id*(id+id)+id";
   // string ginput = "id+id*id";
   // string input = transform(ginput); 
   
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
    cout << "Parse Trees are printed whenever we are able to accept the input" << "\n"; 
    for(int tc=0; tc < inputs.size(); tc++){
        string ginput = inputs[tc];
        //cout << ginput << "\n";
        string input = transform(ginput);
        cout << "**********************************************************************************************"<< "\n";
        if(input != "notValid"){
            origString = ginput;
            //cout << "input : " << escape << "[94;1m" << ginput << escape << "[0m" << "\n";
            inputSize = input.size();
            globalTruth = 0;
            printedTimes = 0;
            inputPtr = 0;
            parentNodes.clear();
            inputString = input;
            root = new treeNode();
            root->treeChar = 'E';
            bool temp = buildTree(root);
            if(!globalTruth){
                cout << "This input is not accepted by the grammar : " << ginput << "\n";
            }
        }
        else{
            cout << "Invalid Input\n";
        }
        cout << "**********************************************************************************************"<< "\n";
    }
}
