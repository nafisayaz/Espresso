

%{

#include<stdio.h>
#include<string.h>


typedef struct lexer
{
	char* text;
	int len;
}lexer;

typedef struct grammar{} grammar;

int yylex (struct lexer * l);

#define LOG do{ printf("\e[0;33m%s, %d, %s, %d  \e[0m\n", __FILE__, __LINE__, l->text, l->len); }while(0)

#define COPY(x, y)  do{ x = malloc(strlen(y)); strcpy(x,y); }while(0) 


void yyerror(lexer* l, grammar * p, char const *s){ printf("\e[1;31m%s\n\n\n\n", s); } 

%}


%token AUTO
%token VARIABLE
%token ASSIGNMENT
%token ESPRESSO
%token STRING
%token DOT
%token USE


%lex-param		{ lexer * l }
%parse-param	{ lexer * l }
%parse-param	{ grammar * p }


%union
{
	char* s;
}



%type<s> value


%%


program      : %empty                                      	{  } 
		     | stmts                                       	{  }

stmts        : stmt                                        	{  }
             | stmts stmt                                  	{  printf("%s", l->text); }
stmt		 : module_expr ';'
module_expr  : AUTO VARIABLE '=' ESPRESSO'()'     			{ LOG; printf("%s", l->text); } 


value        : STRING                                      	{ LOG; printf("%s", l->text); }

%%


int main()
{
	lexer l;
	grammar p;

	//printf("%s", l->text);

	yyparse(&l, &p);
}


