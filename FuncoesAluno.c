#include <stdio.h>
#include "ProjetoEscola.h"

void menuAluno(){
    printf("Bem vindo ao menu do aluno:\n"
    "[1] - Matricular aluno\n"
    "[2] - Listar aluno\n"
    "[3] - Remover aluno\n"
    "[0] - Voltar\n ");
};
void matricularAluno(struct Aluno listaAlunos[],int temp, int qtdAlunos){
    listaAlunos[qtdAlunos].matricula=temp;
    printf("Insira o nome do aluno: \n");
    gets(listaAlunos[qtdAlunos].nome);
    fflush(stdin);
    printf("Insira o sexo do aluno: \n");
    fgets(listaAlunos[qtdAlunos].sexo, 2, stdin);
    limparBuffer();
    printf("Insira o ano de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.ano);
    limparBuffer();
    printf("Insira o mes de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.mes);
    limparBuffer();
    printf("Insira o dia de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.dia);
    limparBuffer();
    printf("Insira o CPF do aluno, sem pontos ou traços: \n");
    fgets(listaAlunos[qtdAlunos].cpf, 12, stdin);
    limparBuffer();
    listaAlunos[qtdAlunos].idade = listaAlunos[qtdAlunos].dataNascimento.ano * 365 + listaAlunos[qtdAlunos].dataNascimento.mes * 30 + listaAlunos[qtdAlunos].dataNascimento.dia;
};
void listarAluno(struct Aluno listaAlunos[], int qtdAlunos){
    if(qtdAlunos==0){
        printf("Nenhum aluno matriculado!\n");
    }else{
        for(int i=0; i<qtdAlunos; i++){
            printf("Aluno %s de matricula %d",listaAlunos[i].nome,listaAlunos[i].matricula);
            printf("\n");
        }
    }
};
void removerAluno(int temp, struct Aluno listaAlunos[], int j, int i, int qtdAlunos){
    while(temp!=listaAlunos[i].matricula){i++;} 
    for(j=i;j<qtdAlunos-1;j++){
        listaAlunos[j].matricula=listaAlunos[j+1].matricula;
        strcpy(listaAlunos[j].nome, listaAlunos[j+1].nome);                           
        strcpy(listaAlunos[j].sexo, listaAlunos[j+1].sexo);                          
        strcpy(listaAlunos[j].cpf, listaAlunos[j+1].cpf);                         
        listaAlunos[j].dataNascimento.ano=listaAlunos[j+1].dataNascimento.ano;
        listaAlunos[j].dataNascimento.mes=listaAlunos[j+1].dataNascimento.mes;
        listaAlunos[j].dataNascimento.dia=listaAlunos[j+1].dataNascimento.dia;
        listaAlunos[j].idade=listaAlunos[j+1].idade;
    }    
};
void listaAlunoSexo(struct Aluno listaAlunos[], int qtdAlunos){
    printf("Os alunos masculinos são: \n");
    for(int i=0;i<qtdAlunos;i++){
        if (listaAlunos[i].sexo == 'M'){
            printf("%s\n", listaAlunos[i].nome);
        }
    }
    printf("\n");
    printf("As alunas femininas são: \n");
    for(int i=0;i<qtdAlunos;i++){
        if (listaAlunos[i].sexo == 'F'){
            printf("%s\n", listaAlunos[i].nome);
        }
    }
};
void listarAlunoIdade(struct Aluno listaAlunos[], int qtdAlunos){
    int alunosIdade[qtdAlunos];
    int temp;    
    printf("A lista do aluno mais velho ao mais novo é:\n ");
    printf("\n");
    for(int i=0; i<qtdAlunos; i++){
        alunosIdade[i]=listaAlunos[i].idade;
    }
    for(int i=0; i<qtdAlunos-1; i++){
        for (int j=0; j<qtdAlunos-i-1; j++){
            if(alunosIdade[j]>alunosIdade[j+1]){
                temp=alunosIdade[j];
                alunosIdade[j]=alunosIdade[j+1];
                alunosIdade[j+1]=temp;                
            }
        }
    }
    for(int i=0; i<qtdAlunos; i++){
        for(int j=0; j<qtdAlunos; j++){
            if(alunosIdade[i]==listaAlunos[j].idade){
                printf("%s\n", listaAlunos[j].nome);
            }
        }
    }

};
//aaa bruno é viado