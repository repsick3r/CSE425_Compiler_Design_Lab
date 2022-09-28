%{ 
    #include <iostream>      
    #include <string>        
    #include <bits/stdc++.h>
    using namespace std;
    int flag = 0;
%}
   
keyword [^a-zA-Z]function[^a-zA-Z]|[^a-zA-Z]abstract[^a-zA-Z]|[^a-zA-Z]break[^a-zA-Z]|[^a-zA-Z]case[^a-zA-Z]|[^a-zA-Z]cast[^a-zA-Z]|[^a-zA-Z]catch[^a-zA-Z]|[^a-zA-Z]class[^a-zA-Z]|[^a-zA-Z]continue[^a-zA-Z]|[^a-zA-Z]in[^a-zA-Z]|import[^a-zA-Z]|[^a-zA-Z]implements[^a-zA-Z]|[^a-zA-Z]if[^a-zA-Z]|[^a-zA-Z]function[^a-zA-Z]|[^a-zA-Z]for[^a-zA-Z]|[^a-zA-Z]final[^a-zA-Z]|[^a-zA-Z]false[^a-zA-Z]|[^a-zA-Z]extern[^a-zA-Z]|[^a-zA-Z]extends[^a-zA-Z]|[^a-zA-Z]enum[^a-zA-Z]|[^a-zA-Z]else[^a-zA-Z]|[^a-zA-Z]dynamic[^a-zA-Z]|[^a-zA-Z]do[^a-zA-Z]|[^a-zA-Z]default[^a-zA-Z]|[^a-zA-Z]var[^a-zA-Z]|[^a-zA-Z]while[^a-zA-Z]|[^a-zA-Z]using[^a-zA-Z]|[^a-zA-Z]untyped[^a-zA-Z]|[^a-zA-Z]typedef[^a-zA-Z]|[^a-zA-Z]try[^a-zA-Z]|[^a-zA-Z]true[^a-zA-Z]|[^a-zA-Z]throw[^a-zA-Z]|[^a-zA-Z]this[^a-zA-Z]|[^a-zA-Z]switch[^a-zA-Z]|[^a-zA-Z]static[^a-zA-Z]|[^a-zA-Z]return[^a-zA-Z]|[^a-zA-Z]public[^a-zA-Z]|[^a-zA-Z]private[^a-zA-Z]|[^a-zA-Z]package[^a-zA-Z]|[^a-zA-Z]override[^a-zA-Z]|[^a-zA-Z]overload[^a-zA-Z]|[^a-zA-Z]operator[^a-zA-Z]|[^a-zA-Z]null[^a-zA-Z]|[^a-zA-Z]new[^a-zA-Z]|[^a-zA-Z]macro[^a-zA-Z]|[^a-zA-Z]main[^a-zA-Z]|[^a-zA-Z]interface[^a-zA-Z]|[^a-zA-Z]inline[^a-zA-Z]
operators [&&]|[<]|[>]|[<=]|[>=]|[=]|[+]|[-]|[*]|[%]|[&]|[{]|[}]|[[]|[]]|[(]|[)]|[#]|[']|[].]|[\\]|[];]|[],] 

%%

{keyword} {cout << "\n" << yytext << " is a Keyword\n";}

[-+]?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {cout << "\n" << yytext << " is an integer.\n";} 

["_"a-zA-Z]*([a-zA-Z]*|[0-9]*)* { cout << "\n" << yytext << " is an identifier\n";}


\"([^\\\"]|\\.)*\"        { cout <<"\n" <<  yytext << " is a string literal\n";}

\/\/(.*) {cout << yytext << " is a comment";} 

{operators} {cout << "\n" << yytext << " is a operator\n";}
   
(" "|"	"|""|"\n") {cout << yytext;}

  
%%
   
int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  yylex();                                 
  fclose(yyin);
  return 0;
}

