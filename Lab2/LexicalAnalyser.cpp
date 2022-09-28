#include<bits/stdc++.h>
using namespace std;

// map<string, int> keywords;
vector<char> punctuations = {' ', '+', '-', '*', '/', ',', ';', '>', '<', '=', '(', ')', '[', ']', '{', '}', '&', '|', '\n'};
vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<char> operators = {'+', '-', '*', '/', '>', '<', '=', '|', '&'};
vector<string> keywords = {"abstract","break","case","cast","catch","class","continue","in","import","implements",
							"if","function","for","final","false","extern","extends","enum","else","dynamic","do",
							"default","var","while","using","untyped","typedef","try","true","throw","this","switch",
							"static","return","public","private","package","override","overload","operator","null",
							"new","macro","main","interface","inline"};


map<string, int> Identifiers;
map<string, int> Numbers;
map<string, int> Keywords;
map<string, int> WrongStr;
map<char, int> Operators;

bool isPunctuator(char ch)				
{
    if (find(punctuations.begin(), punctuations.end(), ch) != punctuations.end()){
        return true;
    }
    return false;
}

bool validIdentifier(string str)			
{
    if (find(digits.begin(), digits.end(), str[0]) != digits.end() || isPunctuator(str[0]) == true){
        return false;
    }								
    int i;
	int len = str.size();
    if(len == 1){
        return true;
    }										
    else{
    	for (i = 1 ; i < len ; i++)				
    	{
        	if (isPunctuator(str[i]) == true){
            	return false;
        	}
    	}
    }
    return true;
}

bool isOperator(char ch)							
{
    if (find(operators.begin(), operators.end(), ch) != operators.end()){
       return true;
    }
    return false;
}

bool isKeyword(string str)						
{
    if (find(keywords.begin(), keywords.end(), str) != keywords.end()){
        return true;
    }
    else{
       return false;
    }
}

bool isNumber(string str)							
{
    int i;
	int len = str.size();
	int numOfDecimal = 0;
    if(len == 0){
    	return false;
    }
    for(i = 0 ; i < len ; i++)
    {
        if (numOfDecimal > 1 && str[i] == '.'){
            return false;
        } 
		else if (numOfDecimal <= 1){
            numOfDecimal++;
        }
        if(find(digits.begin(), digits.end(), str[i]) == digits.end() || (str[i] == '-' && i > 0))
            {
                return false;
            }
    }
    return true;
}

string subString(string realStr, int l, int r)		
{
    return realStr.substr(l,r-l+1);
}

void processLexeme(string str)						
{
    int left = 0;
	int right = 0;
    int len = str.size();
    while(right <= len && left <= right) {
        if(isPunctuator(str[right]) == false){
                right++;
        }
        if(isPunctuator(str[right]) == true && left == right){
            if(isOperator(str[right]) == true){
				Operators[str[right]]++;
                // std::cout<<  <<" : is an operator\n";
            }
            right++;
            left = right;
        } 
		else if(isPunctuator(str[right]) == true && left != right || (right == len && left != right)){
            string sub = subString(str, left, right - 1);
			if(isKeyword(sub) == true){
				Keywords[sub]++;
				// cout<< sub <<" : is a keyword\n";
            }
            else if(isNumber(sub) == true){
				Numbers[sub]++;
				// cout<< sub <<" : is a number\n";
			}
            else if(validIdentifier(sub) == true && isPunctuator(str[right - 1]) == false){
				Identifiers[sub]++;
				// cout<< sub <<" : is a valid identifier\n";
			}
            else if(validIdentifier(sub) == false && isPunctuator(str[right - 1]) == false){
				WrongStr[sub]++;
				// cout<< sub <<" : not a valid identifier\n";
			}
            left = right;
        }
    }
    return;
}

int main(int argc, char* argv[]){
	string HaxeString;
	auto ss = ostringstream{};
	ifstream HaxeFile(argv[1]);
	ss << HaxeFile.rdbuf();
	HaxeString = ss.str();
	processLexeme(HaxeString);
	
	cout << "Number of Operators Encountered : " << Operators.size() << "\n";
	cout << "{ ";
	for(auto x : Operators){
		// if(x.second > 1){
			cout << " { "<<  x.first << " : " << x.second << " } " << "		";			
		// }
	}
	cout << "}\n";
	cout << "\n";

	cout << "Number of Keywords Encountered : " << Keywords.size() << "\n";
	cout << "{ ";
	for(auto x : Keywords){
			cout << " { "<<  x.first << " : " << x.second << " } " << "		";			
		// cout << x << "	";
	}
	cout << "}\n";
	cout << "\n";
	
	cout << "Number of numbers Encountered : " << Numbers.size() << "\n";
	cout << "{ ";
	for(auto x : Numbers){
			cout << " { "<<  x.first << " : " << x.second << " } " << "		";			
		// cout << x << "	";
	}
	cout << "}\n";
	cout << "\n";
	
	cout << "Number of Identifiers Encountered : " << Identifiers.size() << "\n";
	cout << "{ ";
	for(auto x : Identifiers){
			cout << " { "<<  x.first << " : " << x.second << " } " << "		";			
		// cout << x << "	";
	}
	cout << "}\n";
	cout << "\n";
	
	cout << "Number of wrong lexemes Encountered : " << WrongStr.size() << "\n";
	cout << "{ ";
	for(auto x : WrongStr){
			cout << " { "<<  x.first << " : " << x.second << " } " << "		";			
		// cout << x << "		";
	}
	cout << "}\n";
	cout << "\n";
	
	cout << "Successfully Parsed \"Game.hx\"";
	cout << "\n";
	return 0;
}
