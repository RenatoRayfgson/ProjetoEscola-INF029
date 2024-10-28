#include <stdio.h>
#include "ProjetoEscola.h"

void menuDisciplina(){
    printf("Bem vindo ao menu de Disciplina:\n"
    "[1] - Criar Disciplina\n"
    "[2] - Listar Disciplinas\n"
    "[3] - Remover Disciplina\n"
    "[0] - Voltar\n ");
};
void criarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[]){    
    limparBuffer();
    printf("Qual o nome da Disciplina? ");
    gets(listaDisciplinas[qtdDisciplinas].nome);    
    limparBuffer();
    printf("Qual o código da nova Disciplina? ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].codigo);
    limparBuffer();
    printf("Qual o semestre da Disciplina? ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
    limparBuffer();       
};
void listarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[]){
    for(int i=0;i<qtdDisciplinas;i++){
        printf("Disciplina do %d° semestre: %s (%d) ministrada pelo professor de matricula %d\n",listaDisciplinas[i].semestre, listaDisciplinas[i].nome, listaDisciplinas[i].codigo, listaDisciplinas[i].matriculaProfessor);
    }    
};
void removerDisciplina(int temp, int j, int i, int qtdDisciplinas, struct Disciplina listaDisciplinas[]){
    while(temp!=listaDisciplinas[i].codigo){i++;} 
    for(j=i;j<qtdDisciplinas-1;j++){
        listaDisciplinas[j].matriculaProfessor=listaDisciplinas[j+1].matriculaProfessor;
        listaDisciplinas[j].codigo=listaDisciplinas[j+1].codigo;
        listaDisciplinas[j].semestre=listaDisciplinas[j+1].semestre;
        strcpy(listaDisciplinas[j].nome, listaDisciplinas[j+1].nome);
    }    
};
//aaaa