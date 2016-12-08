%{
  #include "global.h"
%}
%defines

%%
expr: /* empty */
    | expr ';'      { return DONE; }
    | term '+' term { emit($2, NONE); }
    | term '-' term { emit($2, NONE); }
    | error { error("syntax error (match)"); }
;
term: factor '*' factor { emit($2, NONE); }
    | factor '/' factor { emit($2, NONE); }
    | factor DIV factor { emit($2, NONE); }
    | factor MOD factor { emit($2, NONE); }
    | error { error("syntax error (match)"); }
;
factor: '(' expr ')'  { yychar=lexan(); }
      | NUM           { emit($1, yylval); }
      | ID            { emit ($1, yylval); }
      | error         { error ("syntax error (factor)"); }
;
%%

void parse(){
  yychar=lexan();
  yyparse();
}
