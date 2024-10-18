#include <stdio.h>
#include "ProjetoEscola.h"

void menuProfessor(){
    printf("Bem vindo ao menu do professor!:\n"
    "[1] - Matricular professor\n"
    "[2] - Listar professor\n"
    "[3] - Remover professor\n"
    "[0] - Voltar\n ");    
};
void matricularProfessor(struct Professor listaProfessores[], int temp, int qtdProfessores){
    listaProfessores[qtdProfessores].matricula=temp;
    printf("Insira o nome do professor: \n");
    gets(listaProfessores[qtdProfessores].nome);
    fflush(stdin);
    printf("Insira o sexo do professor: \n");
    fgets(listaProfessores[qtdProfessores].sexo, 2, stdin);
    limparBuffer();
    printf("Insira o ano de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.ano);
    limparBuffer();
    printf("Insira o mes de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.mes);
    limparBuffer();
    printf("Insira o dia de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.dia);
    limparBuffer();
    printf("Insira o CPF do professor, sem pontos ou traços: \n");
    fgets(listaProfessores[qtdProfessores].cpf, 12, stdin);
    limparBuffer();
};
void listarProfessor(struct Professor listaProfessores[], int qtdProfessores){
    for(int i=0; i<qtdProfessores; i++){
        printf("Professor %s de matricula %d",listaProfessores[i].nome,listaProfessores[i].matricula);
        printf("\n");
    }   
};
void removerProfessor(struct Professor listaProfessores[], int i, int j, int qtdProfessores, int temp){
    while(temp!=listaProfessores[i].matricula){i++;} 
    for(j=i;j<qtdProfessores-1;j++){
        listaProfessores[j].matricula=listaProfessores[j+1].matricula;
        strcpy(listaProfessores[j].nome, listaProfessores[j+1].nome);                           
        strcpy(listaProfessores[j].sexo, listaProfessores[j+1].sexo);                          
        strcpy(listaProfessores[j].cpf, listaProfessores[j+1].cpf);                         
        listaProfessores[j].dataNascimento.ano=listaProfessores[j+1].dataNascimento.ano;
        listaProfessores[j].dataNascimento.mes=listaProfessores[j+1].dataNascimento.mes;
        listaProfessores[j].dataNascimento.dia=listaProfessores[j+1].dataNascimento.dia;
    }    
};
void listaProfessorSexo(struct Professor listaProfessores[], int qtdProfessores){
    printf("Os professores são: \n");
    for(int i=0;i<qtdProfessores;i++){
        if (listaProfessores[i].sexo == 'M'){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
    printf("\n");
    printf("As professoras são: \n");
    for(int i=0;i<qtdProfessores;i++){
        if (listaProfessores[i].sexo == 'F'){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
};
//aa
