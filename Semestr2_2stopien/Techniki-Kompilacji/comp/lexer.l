%x alpha
%array
%option nodefault
%option outfile="lexer.c"
%{
  #include "global.h"
  #include "math.h"
  #define YY_DECL int lexan()
  char lexbuf[BSIZE];
  int lineno = 1;
  int tokenval=NONE;
%}

%%
%{
int p;
%}
[ \t]
[\n]  lineno++;
[0-9]+ {
          (void)sscanf(yytext,"%d",&tokenval);
          return NUM;
       }
[A-Za-z][A-Za-z0-9]+  {
                  if (yyleng>BSIZE)
                    error ("compiler error");
                  p=lookup(yytext);
                  if (p==0)
                    p=insert(yytext,ID);
                  tokenval=p;
                  return symtable[p].token;
                }

<<EOF>>  return DONE;
'div' {
          p=lookup(yytext);
          if (p==0)
            p=insert(yytext,DIV);
          tokenval=p;
          return symtable[p].token;
      }
'mod' {
        p=lookup(yytext);
        if (p==0)
          p=insert(yytext,MOD);
        tokenval=p;
        return symtable[p].token;
      }
.     {
    tokenval = NONE;
    return yytext[yyleng-1];
  }
%%
