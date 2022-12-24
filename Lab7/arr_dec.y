%{
#include<stdio.h>
int arr[50000];
int res = 0;
int d1,d2,d3;
%}

%token TYPE INTEGER VARIABLE

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
program:
 program statement '\n'
 |
 ;

statement:
| TYPE VARIABLE  { }
| TYPE VARIABLE'['INTEGER']''['INTEGER']''['INTEGER']' {d1=$4;d2=$7;d3=$10; printf("Declaring Array %d-%d-%d\n", d1,d2,d3); }
| VARIABLE'='INTEGER {res = $3;}
| VARIABLE'['INTEGER']''['INTEGER']''['INTEGER']''='INTEGER {arr[$3*d2*d3 + $6*d3 + $9] = $12;}
| VARIABLE'['INTEGER']''['INTEGER']''['INTEGER']''='VARIABLE {arr[$3*d2*d3 + $6*d3 + $9] = res;}
| VARIABLE'='VARIABLE'['INTEGER']''['INTEGER']''['INTEGER']' {res = arr[$5*d2*d3 + $8*d3 + $11];}
| VARIABLE { printf(" value = %d\n", res);}
| VARIABLE'['INTEGER']''['INTEGER']''['INTEGER']' { printf(" value = %d\n", arr[$3*d2*d3 + $6*d3 + $9]);}
%%

//driver code
void main()
{
    printf("\nEnter : \n");
    yyparse();
}

void yyerror()
{
    printf("\nError Occured\n");
}
