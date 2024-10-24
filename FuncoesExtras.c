#include <stdio.h>
#include <time.h>
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
void aniversariantesMes(struct Professor listaProfessores[], struct Aluno listaAlunos[], int qtdProfessores, int qtdAlunos){
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int mesAtual = local -> tm_mon+1;

    printf("Os alunos aniversariantes do mês são:\n");
    for(int i=0; i<qtdAlunos; i++){
        if(listaAlunos[i].dataNascimento.mes == mesAtual){
            printf("%s\n", listaAlunos[i].nome);
        }
    }
    printf("\n");
    printf("Os professores aniversariantes do mês são:\n");
    for(int i=0; i<qtdProfessores; i++){
        if(listaProfessores[i].dataNascimento.mes == mesAtual){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
    printf("\n");
};