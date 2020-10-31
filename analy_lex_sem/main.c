#include "analy_lex_sem_func.h"

int main(int *argv,char *argc[]) {
  if(argv<2) {
    printf("compiler:\033[1;31m fatal error:\033[0m no input files\ncompilation terminated.\n");
    return EXIT_FAILURE ;
  }
  analy_lex_sem_dec(argc[1]);
}
