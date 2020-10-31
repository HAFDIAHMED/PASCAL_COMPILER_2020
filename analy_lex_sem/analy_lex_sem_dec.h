typedef enum {
  PROGRAM_TOKEN,CONST_TOKEN,VAR_TOKEN,BEGIN_TOKEN,END_TOKEN,IF_TOKEN,THEN_TOKEN,WHILE_TOKEN,
  DO_TOKEN,READ_TOKEN,WRITE_TOKEN,PV_TOKEN,PT_TOKEN,PLUS_TOKEN,MOINS_TOKEN,MULT_TOKEN,
  DIV_TOKEN,VIR_TOKEN,AFF_TOKEN,EG_TOKEN,INF_TOKEN,INFEG_TOKEN,SUP_TOKEN,SUPEG_TOKEN,DIFF_TOKEN,
  PO_TOKEN,PF_TOKEN,FIN_TOKEN,ID_TOKEN,NUM_TOKEN,ERREUR_TOKEN,NULL_TOKEN
} TOKENS ;
typedef struct {
  TOKENS TOKEN ; char* WORD ;
} Sym_Struct ;
Sym_Struct *Token_Cour;
typedef struct sym_arr{
  Sym_Struct *Data ;
  struct sym_arr *next;
} Sym_Arr_Struct ;
Sym_Arr_Struct *Head_Arr_Symb;
//
typedef struct {
  TOKENS TOKEN ; char TOKENS[30] ;
} TokenS_Struct ;
TokenS_Struct ARR_TOK[32] = {{PROGRAM_TOKEN,"PROGRAM_TOKEN"},
                             {CONST_TOKEN,"CONST_TOKEN"},
                             {VAR_TOKEN,"VAR_TOKEN"},
                             {BEGIN_TOKEN,"BEGIN_TOKEN"},
                             {END_TOKEN,"END_TOKEN"},
                             {IF_TOKEN,"IF_TOKEN"},
                             {THEN_TOKEN,"THEN_TOKEN"},
                             {WHILE_TOKEN,"WHILE_TOKEN"},
                             {DO_TOKEN,"DO_TOKEN"},
                             {READ_TOKEN,"READ_TOKEN"},
                             {WRITE_TOKEN,"WRITE_TOKEN"},
                             {PV_TOKEN,"PV_TOKEN"},
                             {PT_TOKEN,"PT_TOKEN"},
                             {PLUS_TOKEN,"PLUS_TOKEN"},
                             {MOINS_TOKEN,"MOINS_TOKEN"},
                             {MULT_TOKEN,"MULT_TOKEN"},
                             {DIV_TOKEN,"DIV_TOKEN"},
                             {VIR_TOKEN,"VIR_TOKEN"},
                             {AFF_TOKEN,"AFF_TOKEN"},
                             {EG_TOKEN,"EG_TOKEN"},
                             {INF_TOKEN,"INF_TOKEN"},
                             {INFEG_TOKEN,"INFEG_TOKEN"},
                             {SUP_TOKEN,"SUP_TOKEN"},
                             {SUPEG_TOKEN,"SUPEG_TOKEN"},
                             {DIFF_TOKEN,"DIFF_TOKEN"},
                             {PO_TOKEN,"PO_TOKEN"},
                             {PF_TOKEN,"PF_TOKEN"},
                             {FIN_TOKEN,"FIN_TOKEN"},
                             {ID_TOKEN,"ID_TOKEN"},
                             {NUM_TOKEN,"NUM_TOKEN"},
                             {ERREUR_TOKEN,"ERREUR_TOKEN"},
                             {NULL_TOKEN,"NULL_TOKEN"}};
//
char Car_Cour;
FILE *file;
