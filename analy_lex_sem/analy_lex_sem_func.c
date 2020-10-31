#include "analy_lex_sem_func.h"
#include "analy_lex_sem_dec.h"

void push() {
  Sym_Arr_Struct *current = Head_Arr_Symb;
  if(Head_Arr_Symb == NULL) {
    Head_Arr_Symb->Data = Token_Cour ;
    Head_Arr_Symb->next = NULL ;
 }
  else {
    while(current->next != NULL) {
      current=current->next;
    }
    current->next=(Sym_Arr_Struct*)malloc(sizeof(Sym_Arr_Struct));
    current->next->Data = (Sym_Struct*)malloc(sizeof(Sym_Struct));
    current->next->Data->WORD = (char*)malloc(21);
    current->next->Data->TOKEN = Token_Cour->TOKEN ;
    memcpy(current->next->Data->WORD,Token_Cour->WORD,sizeof(Token_Cour->WORD));
    current->next->next = NULL ;
 }
}
void show() {
  Sym_Arr_Struct *current = Head_Arr_Symb;
  while(current->next != NULL) {
    printf("%s ----> %s\n",ARR_TOK[current->next->Data->TOKEN].TOKENS,current->next->Data->WORD);
    current=current->next;
  }

}
void Next_Car() {
  Car_Cour = fgetc(file);
}
void Next_Word() {
  int count_car = 0 ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  count_car++;
  Next_Car();
  while(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')||('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(count_car>=20) {}
  //printf("%s\n",Token_Cour->WORD);
  Check_Token();
}
void Next_Number() {
  int count_car = 0 ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  Next_Car();
  while(('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(count_car>=11) {}
  Token_Cour->TOKEN = NUM_TOKEN ;
}
void Check_Token() {
  if((strcmp("program",Token_Cour->WORD)==0)||(strcmp("PROGRAM",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = PROGRAM_TOKEN ;
  }
  else if((strcmp("const",Token_Cour->WORD)==0)||(strcmp("CONST",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = CONST_TOKEN ;
  }
  else if((strcmp("var",Token_Cour->WORD)==0)||(strcmp("VAR",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = VAR_TOKEN ;
  }
  else if((strcmp("begin",Token_Cour->WORD)==0)||(strcmp("BEGIN",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = BEGIN_TOKEN ;
  }
  else if((strcmp("end",Token_Cour->WORD)==0)||(strcmp("END",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = END_TOKEN ;
  }
  else if((strcmp("if",Token_Cour->WORD)==0)||(strcmp("IF",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IF_TOKEN ;
  }
  else if((strcmp("then",Token_Cour->WORD)==0)||(strcmp("THEN",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = THEN_TOKEN ;
  }
  else if((strcmp("while",Token_Cour->WORD)==0)||(strcmp("WHILE",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = WHILE_TOKEN ;
  }
  else if((strcmp("do",Token_Cour->WORD)==0)||(strcmp("DO",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = DO_TOKEN ;
  }
  else if((strcmp("read",Token_Cour->WORD)==0)||(strcmp("READ",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = READ_TOKEN ;
  }
  else if((strcmp("write",Token_Cour->WORD)==0)||(strcmp("write",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = WRITE_TOKEN ;
  }
  else {
    Token_Cour->TOKEN = ID_TOKEN ;
  }
}
void Break_Comment() {
  Next_Car();
  while(1) {
    if(Car_Cour == 42) {
      Next_Car();
      if(Car_Cour == 125) {
        break;
      }
    }
    else {
      Next_Car();
    }
  }
}
void Next_Sym() {
  Token_Cour->TOKEN = NULL_TOKEN ;
  Token_Cour->WORD=memset(Token_Cour->WORD,'\0',sizeof(Token_Cour->WORD));
  if((Car_Cour==10)||(Car_Cour==32)) {
    Next_Car();
  }
  else if(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')) {
    Next_Word();
  }
  else if('0'<=Car_Cour && Car_Cour<='9') {
    Next_Number();
  }
  else if(Car_Cour == 59) {
    Token_Cour->TOKEN = PV_TOKEN ;
    *Token_Cour->WORD = ';' ;
    Next_Car();
  }
  else if(Car_Cour == 46) {
    Token_Cour->TOKEN = PT_TOKEN ;
    *Token_Cour->WORD = '.' ;
    Next_Car();
  }
  else if(Car_Cour == 43) {
    Token_Cour->TOKEN = PLUS_TOKEN ;
    *Token_Cour->WORD = '+' ;
    Next_Car();
  }
  else if(Car_Cour == 45) {
    Token_Cour->TOKEN = MOINS_TOKEN ;
    *Token_Cour->WORD = '-' ;
    Next_Car();
  }
  else if(Car_Cour == 42) {
    Token_Cour->TOKEN = MULT_TOKEN ;
    *Token_Cour->WORD = '*' ;
    Next_Car();
  }
  else if(Car_Cour == 47) {
    Token_Cour->TOKEN = DIV_TOKEN ;
    *Token_Cour->WORD = '/' ;
    Next_Car();
  }
  else if(Car_Cour == 44) {
    Token_Cour->TOKEN = VIR_TOKEN ;
    *Token_Cour->WORD = ',' ;
    Next_Car();
  }
  else if(Car_Cour == 40) {
    Token_Cour->TOKEN = PO_TOKEN ;
    *Token_Cour->WORD = '(' ;
    Next_Car();
  }
  else if(Car_Cour == 41) {
    Token_Cour->TOKEN = PF_TOKEN ;
    *Token_Cour->WORD = ')' ;
    Next_Car();
  }
  else if(Car_Cour == 61) {
    Token_Cour->TOKEN = EG_TOKEN ;
    *Token_Cour->WORD = '=' ;
    Next_Car();
  }
  else if(Car_Cour == 58) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = AFF_TOKEN ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,":=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = INFEG_TOKEN ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"<=");
      Next_Car();
    }
    else if(Car_Cour == 62) {
      Token_Cour->TOKEN = DIFF_TOKEN ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"<>");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = INF_TOKEN ;
      *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 62) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = SUPEG_TOKEN ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,">=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='>';
    }
  }
  else if(Car_Cour == 123) {
    Next_Car();
    if(Car_Cour == 42) {
      Break_Comment();
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else {
    Next_Car();
  }
}
int analy_lex_sem_dec(char *filename) {
  file=fopen(filename,"a+");
  Head_Arr_Symb = (Sym_Arr_Struct*)malloc(sizeof(Sym_Arr_Struct));
  Token_Cour = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  Token_Cour->WORD = (char*)malloc(21);
  Next_Car();
  while(Car_Cour != EOF) {
    Next_Sym();
    if(Token_Cour->TOKEN != NULL_TOKEN) {
      push();
    }
  }
  show();
  return 0;
}
