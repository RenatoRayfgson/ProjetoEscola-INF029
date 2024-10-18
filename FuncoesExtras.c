#include <stdio.h>
#include "ProjetoEscola.h"

void menuPrincipal(){
    printf("Escolha uma opção:\n"
    "[1] - Aluno\n"
    "[2] - Professor\n"
    "[3] - Disciplina\n"
    "[0] - Encerrar\n ");    
};
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF); //Lê até encontrar quebra de linha ou caractere de fim de arquivo, so pra limpar a bosta do buffer
};