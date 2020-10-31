#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void Symbole_Suiv(void) {
  List_Token = List_Token->Next ;
  Token_Cour = List_Token->Data ;
}

void Test_Symbole(TOKENS token,ERREURS erreur) {
  if(Token_Cour->TOKEN == token) {
    Symbole_Suiv();
  }
  else {
    Erreur(erreur);
  }
}

void PROGRAM(void) {
  Test_Symbole(PROGRAM_TOKEN,PROGRAM_TOKEN_ERREUR);
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR);
  BLOCK();
  Test_Symbole(PT_TOKEN,PT_TOKEN_ERREUR);
}

void BLOCK(void) {
  CONSTS();
  VARS();
  INSTS();
}
void CONSTS(void) {
  switch (Token_Cour->TOKEN) {
    case CONST_TOKEN : Symbole_Suiv();
                       Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                       Test_Symbole(EGAL_TOKEN,EGAL_TOKEN_ERREUR);
                       Test_Symbole(NUM_TOKEN,NUM_TOKEN_ERREUR);
                       Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR);
                       while(Token_Cour->TOKEN == ID_TOKEN) {
                         Symbole_Suiv();
                         Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                         Test_Symbole(EGAL_TOKEN,EGAL_TOKEN_ERREUR);
                         Test_Symbole(NUM_TOKEN,NUM_TOKEN_ERREUR);
                         Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR);
                       } ; break ;
    case VAR_TOKEN :   break ;
    case BEGIN_TOKEN : break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ; break ;
  }
}
void VARS(void) {
  switch (Token_Cour->TOKEN) {
    case VAR_TOKEN : Symbole_Suiv();
                     Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                     while(Token_Cour->TOKEN == VIR_TOKEN) {
                        Symbole_Suiv();
                        Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                     }
                     Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR); ; break ;
    case BEGIN_TOKEN : break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ; break ;
  }
}
void INSTS(void) {
  Test_Symbole(BEGIN_TOKEN,BEGIN_TOKEN_ERREUR);
  INST();
  while(Token_Cour->TOKEN == PV_TOKEN ) {
    Symbole_Suiv();
    INST();
  }
  Test_Symbole(END_TOKEN,END_TOKEN_ERREUR);
}
void INST(void) {
  switch (Token_Cour->TOKEN) {
    case BEGIN_TOKEN : INSTS() ; break ;
    case ID_TOKEN    : AFFEC() ; break ;
    case IF_TOKEN    : SI()    ; break ;
    case WHILE_TOKEN : TANTQUE();break ;
    case WRITE_TOKEN : ECRIRE(); break ;
    case READ_TOKEN  : LIRE()  ; break ;
    default          : Erreur(INST_ERR) ; break ;
}
void AFFEC(void) {
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  Test_Symbole(AFFEC_TOKEN,AFFEC_TOKEN_ERREUR);
  EXPR();
}
void SI(void) {
  Test_Symbole(IF_TOKEN,IF_TOKEN_ERREUR);
  COND();
  Test_Symbole(THEN_TOKEN,THEN_TOKEN_ERREUR);
  INST();
}
void TANTQUE(void) {
  Test_Symbole(WHILE_TOKEN,WHILE_TOKEN_ERREUR);
  COND();
  Test_Symbole(DO_TOKEN,DO_TOKEN_ERREUR);
  INST();
}
void ECRIRE(void) {
  Test_Symbole(WRITE_TOKEN,WRITE_TOKEN_ERREUR);
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  EXPR();
  while(Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    EXPR();
  }
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
void LIRE(void) {
  Test_Symbole(READ_TOKEN,READ_TOKEN_ERREUR);
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  while(Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  }
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
void COND(void) {
  EXPR();
  switch(Token_Cour->TOKEN) {
    case EGAL_TOKEN: break;
    case DIFF_TOKEN: break;
    case INF_TOKEN:  break;
    case SUP_TOKEN:  break;
    case INFEG_TOKEN:break;
    case SUPEG_TOKEN:break;
    default: Erreur(COND_ERR) ; break ;
  }
  EXPR();
}
void EXPR(void) {
  TERM();
  while(Token_Cour->TOKEN == PLUS_TOKEN || Token_Cour->TOKEN == MOINS_TOKEN) {
    Symbole_Suiv();
    TERM();
  }
}
void TERM(void) {
  FACT();
  while(Token_Cour->TOKEN == MULT_TOKEN || Token_Cour->TOKEN == DIV_TOKEN) {
    Symbole_Suiv();
    FACT();
  }
}
void FACT(void) {
  switch(Token_Cour->TOKEN) {
    case ID_TOKEN : break ;
    case PO_TOKEN : EXPR(); Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR); break ;
  }
}
