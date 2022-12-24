%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}


%%
(int|float) {
    yylval =*yytext;
    return TYPE;
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval =*yytext;
    return VARIABLE;
}

[0-9]+ {
    yylval=atoi(yytext);
    return INTEGER;
}

[-+()=/*\n\[\]] { return *yytext; }

[\t\n];
%%

int yywrap()
{
    return 1;
}

