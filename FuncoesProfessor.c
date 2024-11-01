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
    "[7] - Atualizar professor\n"
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
void atualizarProfessor(struct Professor listaProfessores[], int qtdProfessores, struct Disciplina listaDisciplinas[], int qtdDisciplinas){
    int temp, professor=0, verificador=0, validarMatricula = 1;
    int opcaoAlterar = -1;
    char CPF[12];
    printf("Digite a matrícula do aluno que deseja alterar: \n");
    scanf("%d", &temp);
    for(int i=0; i<qtdProfessores; i++){
        if(temp==listaProfessores[i].matricula){
            professor = i;
            verificador = 1;
            break;
        }
    }
    if(verificador == 1){
        printf("Selecione o dado que deseja alterar:\n"
        "[1] - Matricula do professor\n"
        "[2] - Sexo do professor\n"
        "[3] - Dia de nascimento\n"
        "[4] - Mês de nascimento\n"
        "[5] - Ano de nascimento\n"
        "[6] - CPF\n"            
        "[0] - Cancelar\n ");
        scanf("%d", &opcaoAlterar);
        switch(opcaoAlterar){
            case 1:{
                int jaExiste;
                do{
                    printf("Qual a nova matrícula deste professor? \n");
                    scanf("%d", &temp);
                    limparBuffer();
                    jaExiste = 0;
                    for(int i=0; i<qtdProfessores; i++){
                        if(temp == listaProfessores[i].matricula){
                            printf("Matrícula já existe! Tente uma diferente!\n");
                            jaExiste = 1;
                            break;
                        }
                    }
                }while(jaExiste);
                listaProfessores[professor].matricula = temp;
                printf("Matrícula alterada com sucesso!\n");
                break;
            }
            case 2:{
                if(strcmp(listaProfessores[professor].sexo, "M") == 0){
                    strcpy(listaProfessores[professor].sexo, "F");
                }else{
                    strcpy(listaProfessores[professor].sexo, "M");
                }
                printf("Sexo alterado com sucesso!\n");
                break;
            }
            case 3:{
                printf("Qual o novo dia de nascimento do professor? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 31 || temp < 1){
                    printf("Insira um dia de nascimento válido pro professor: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaProfessores[professor].dataNascimento.dia = temp;
                listaProfessores[professor].idade = listaProfessores[professor].dataNascimento.ano * 365 + listaProfessores[professor].dataNascimento.mes * 30 + listaProfessores[professor].dataNascimento.dia;
                printf("Ano alterado com sucesso!");
                break;
            }
            case 4:{
                printf("Qual o novo mês de nascimento do professor? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 12 || temp < 1){
                    printf("Insira um mês de nascimento válido pro professor: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaProfessores[professor].dataNascimento.mes = temp;
                listaProfessores[professor].idade = listaProfessores[professor].dataNascimento.ano * 365 + listaProfessores[professor].dataNascimento.mes * 30 + listaProfessores[professor].dataNascimento.dia;
                printf("Mes alterado com sucesso!");
                break;
            }
            case 5:{
                printf("Qual o novo ano de nascimento do professor? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 2024 || temp < 1900){
                    printf("Insira um ano de nascimento válido pro professor: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaProfessores[professor].dataNascimento.ano = temp;
                listaProfessores[professor].idade = listaProfessores[professor].dataNascimento.ano * 365 + listaProfessores[professor].dataNascimento.mes * 30 + listaProfessores[professor].dataNascimento.dia;
                printf("Dia alterado com sucesso!");
                break;
            }
            case 6:{
                printf("Insira o novo CPF do professor, sem pontos ou traços: \n");
                fgets(CPF, 12, stdin);
                limparBuffer();
                size_t tam = strlen(CPF);
                if(CPF[tam-1] == '\n'){
                    CPF[tam-1] = '\0';
                }
                while(strlen(CPF)!= 11){
                    printf("Insira um CPF válido pro professor, sem pontos ou traços: \n");
                    fgets(CPF, 12, stdin);
                    limparBuffer();
                    tam = strlen(CPF);
                    if(CPF[tam-1] == '\n'){
                        CPF[tam-1] = '\0';
                    }
                }
                strcpy(listaProfessores[professor].cpf, CPF);
                break;
            }            
            case 0:{
                opcaoAlterar = -1;
                break;
            }
        }
    }else{
        printf("Professor não encontrado!");
    }
};

