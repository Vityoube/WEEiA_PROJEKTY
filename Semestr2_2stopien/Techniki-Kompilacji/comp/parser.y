%{
  #include "global.h"
%}
%union{
	char  * str_type;
	int int_type;
}
%token <str_type> T_DIV "div"
%token <str_type>T_MOD "mod"
%token <int_type> T_NUM
%token <str_type> T_ID
%token E_O_F 0
%token <int_type> '+' '-' '/' '*'
%left '+' '-'
%left '/' '*' T_DIV T_MOD
%left '(' ')'
%%
sequ:  expr ';'      { YYACCEPT; }
      | E_O_F          { YYACCEPT; }
      | error { yyerror("syntax error (match)"); }
expr: /* empty */
    | term '+' term {
                        yychar=yylex();
                        emit($2, NONE);
                     }
    | term '-' term {
                      yychar=yylex();
                      emit($2, NONE);
                    }
    | error { yyerror("syntax error (match)"); }
;
term: factor '*' factor {
                          yychar=yylex();
                          emit($2, NONE);
                         }
    | factor '/' factor {
                              yychar=yylex();
                              emit($2, NONE);
                         }
    | factor T_DIV factor {
                              yychar=yylex();
                              emit($2, NONE);
                             }
    | factor T_MOD factor {
                              yychar=yylex();
                              emit($2, NONE);
                           }
    | error { yyerror("syntax error (match)"); }
;
factor: '(' expr ')'  { yychar=yylex(); }
      | T_NUM           { emit(NUM, yylval.int_type); }
      | T_ID            { emit (ID, yylval.int_type); }
      | error         { yyerror ("syntax error (factor)"); }
;
%%

void parse(){
  yychar=yylex();
  yyparse();
}

int yylex(void){
	return lexan();
}

void yyerror(char const *s){
	error(s);
}
