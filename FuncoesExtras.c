#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include "ProjetoEscola.h"

void menuPrincipal(){
    printf("Escolha uma opção:\n"
    "[1] - Aluno\n"
    "[2] - Professor\n"
    "[3] - Disciplina\n"
    "[4] - Aniversariantes do mês\n"
    "[5] - Buscar nomes\n"
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
void buscaPessoas(struct Professor listaProfessores[], struct Aluno listaAlunos[], int qtdProfessores, int qtdAlunos){
    char buscaPessoa[3];
    int i,j;
    printf("Insira as 3 letras que você pretende buscar: \n");
    gets(buscaPessoa);
    printf("Os alunos cujas iniciais são essas 3 letras são: \n");
    for(i=0; i<qtdAlunos; i++){
        for(j=0; j<3; j++){
            if(listaAlunos[i].nome[j]!= buscaPessoa[j]){
                break;
            }
        }
        if(j==3){
            printf("%s\n", listaAlunos[i].nome);
        }
    }
    printf("Os professores cujas iniciais são essas 3 letras são: \n");
    for(i=0; i<qtdProfessores; i++){
        for(j=0; j<3; j++){
            if(listaProfessores[i].nome[j] != buscaPessoa[j]){
                break;
            }
        }
        if(j==3){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
};