#include <stdio.h>
#include "ProjetoEscola.h"

void menuProfessor(){
    printf("Bem vindo ao menu do professor!:\n"
    "[1] - Matricular professor\n"
    "[2] - Listar professor\n"
    "[3] - Remover professor\n"
    "[4] - Listar professor por sexo\n"
    "[5] - Listar professor por idade\n"
    "[6] - Listar professor por ordem alfabetica\n"
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
    while(strcmp(listaProfessores[qtdProfessores].sexo, "M")!=0 && strcmp(listaProfessores[qtdProfessores].sexo, "F")!=0){
        printf("Insira um sexo válido pro professor (M ou F): \n");
        fgets(listaProfessores[qtdProfessores].sexo, 2, stdin);
        limparBuffer();
    }
    printf("Insira o ano de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.ano);
    limparBuffer();
    while(listaProfessores[qtdProfessores].dataNascimento.ano > 2024 || listaProfessores[qtdProfessores].dataNascimento.ano < 1900){
        printf("Insira um ano de nascimento válido pro professor: \n");
        scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.ano);
        limparBuffer();
    }
    printf("Insira o mes de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.mes);
    limparBuffer();
    while(listaProfessores[qtdProfessores].dataNascimento.mes > 12 || listaProfessores[qtdProfessores].dataNascimento.mes < 1){
        printf("Insira um mês de nascimento válido pro professor: \n");
        scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.mes);
        limparBuffer();
    }
    printf("Insira o dia de nascimento do professor: \n");
    scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.dia);
    limparBuffer();
    while(listaProfessores[qtdProfessores].dataNascimento.dia > 31 || listaProfessores[qtdProfessores].dataNascimento.dia < 1){
        printf("Insira um mês de nascimento válido pro professor: \n");
        scanf("%d", &listaProfessores[qtdProfessores].dataNascimento.dia);
        limparBuffer();
    }
    printf("Insira o CPF do professor, sem pontos ou traços: \n");
    fgets(listaProfessores[qtdProfessores].cpf, 12, stdin);
    limparBuffer();
    size_t tam = strlen(listaProfessores[qtdProfessores].cpf);
    if(listaProfessores[qtdProfessores].cpf[tam-1] == '\n'){
        listaProfessores[qtdProfessores].cpf[tam-1] = '\0';
    }
    while(strlen(listaProfessores[qtdProfessores].cpf)!= 11){
        printf("Insira um CPF válido pro professor, sem pontos ou traços: \n");
        fgets(listaProfessores[qtdProfessores].cpf, 12, stdin);
        limparBuffer();
        tam = strlen(listaProfessores[qtdProfessores].cpf);
        if(listaProfessores[qtdProfessores].cpf[tam-1] == '\n'){
            listaProfessores[qtdProfessores].cpf[tam-1] = '\0';
        }
    }
    listaProfessores[qtdProfessores].idade = listaProfessores[qtdProfessores].dataNascimento.ano*365+listaProfessores[qtdProfessores].dataNascimento.mes*30+listaProfessores[qtdProfessores].dataNascimento.dia;
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
void listarProfessorSexo(struct Professor listaProfessores[], int qtdProfessores){
    printf("Os professores masculinos são: \n");
    for(int i=0;i<qtdProfessores;i++){
        if (listaProfessores[i].sexo[0] == 'M'){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
    printf("\n");
    printf("As professoras femininas são: \n");
    for(int i=0;i<qtdProfessores;i++){
        if (listaProfessores[i].sexo[0] == 'F'){
            printf("%s\n", listaProfessores[i].nome);
        }
    }
};
void listarProfessorIdade(struct Professor listaProfessores[], int qtdProfessores){
    int professoresIdade[qtdProfessores];
    int temp;    
    printf("A lista do professor mais velho ao mais novo é:\n ");
    printf("\n");
    for(int i=0; i<qtdProfessores; i++){
        professoresIdade[i]=listaProfessores[i].idade;
    }
    for(int i=0; i<qtdProfessores-1; i++){
        for (int j=0; j<qtdProfessores-i-1; j++){
            if(professoresIdade[j]>professoresIdade[j+1]){
                temp=professoresIdade[j];
                professoresIdade[j]=professoresIdade[j+1];
                professoresIdade[j+1]=temp;                
            }
        }
    }
    for(int i=0; i<qtdProfessores; i++){
        for(int j=0; j<qtdProfessores; j++){
            if(professoresIdade[i]==listaProfessores[j].idade){
                printf("%s\n", listaProfessores[j].nome);
            }
        }
    }

};
void listarProfessorAlfabeticamente(struct Professor listaProfessores[], struct Professor listaOrdenada[], int qtdProfessores){
    int i=0, j=0;
    char temp[128];
    for(i=0; i<qtdProfessores; i++){
        strcpy(listaOrdenada[i].nome, listaProfessores[i].nome);
    }
    for(i=0; i<qtdProfessores-1; i++){
        for(j=i+1; j<qtdProfessores; j++){
            if(strcmp(listaOrdenada[i].nome, listaProfessores[j].nome) > 0){
                strcpy(temp, listaOrdenada[i].nome);
                strcpy(listaOrdenada[i].nome, listaOrdenada[j].nome);
                strcpy(listaOrdenada[j].nome, temp);
            }
        }
    }
    printf("Os professores em ordem alfabética são:\n");
    for(i=0; i<qtdProfessores; i++){
        printf("%s\n", listaOrdenada[i].nome);
    }
};

