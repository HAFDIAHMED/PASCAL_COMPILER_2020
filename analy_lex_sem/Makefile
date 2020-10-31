CC = gcc
FLAGS_C = -c
FLAGS_L = -o


main : main.o analy_lex_sem_func.o
	${CC} main.o analy_lex_sem_func.o ${FLAGS_L} main

main.o : main.c analy_lex_sem_func.h 
	${CC} ${FLAGS_C} main.c
analy_lex_sem_func.o : analy_lex_sem_func.c	analy_lex_sem_func.h analy_lex_sem_dec.h
	${CC} ${FLAGS_C} analy_lex_sem_func.c
