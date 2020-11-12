

%{

#include "test.h"

#include<stdio.h>	


typedef struct lexer
{
	char* text;
	int len;
}lexer;


typedef struct grammar grammar;

#include "parser.h"

#define YY_DECL int yylex (lexer * l)

#define SAVE do{ l->text = yytext; l->len = yyleng; }while(0)

#define PRINTF(...)  do{}while(0)


%}


AUTO						"auto"
ASSIGNMENT					"="
ESPRESSO					"espresso"
VARIABLE					[a-zA-Z]+
CHAR						[a-zA-Z]+
STRING						\"{CHAR}+\"
DOT							"."
USE							"use"




%%


{AUTO}						{ SAVE; PRINTF("string_type: %s\n", yytext); return AUTO; }
{ASSIGNMENT}				{ SAVE; PRINTF("string_type: %s\n", yytext); return ASSIGNMENT; }
{ESPRESSO}					{ SAVE; PRINTF("string_type: %s\n", yytext); return ESPRESSO; }
{STRING}					{ SAVE; PRINTF("string_type: %s\n", yytext); return STRING; }

{DOT}						{ SAVE; PRINTF("string_type: %s\n", yytext); return DOT; }
{USE}						{ SAVE; PRINTF("string_type: %s\n", yytext); return USE; }
{VARIABLE}					{ SAVE; PRINTF("string_type: %s\n", yytext); return VARIABLE; }

.							{}


%%


int yywrap() { return 1; }



