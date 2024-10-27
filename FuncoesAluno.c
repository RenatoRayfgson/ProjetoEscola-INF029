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
void adicionarAlunoDisciplina(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina listaDisciplinas[], int qtdDisciplinas){
    int i, j=0, qtdMatriculas=0;
    int temp = -1;
    //Loop que define todas as matrículas do aluno como 0 pra ajudar na busca
    for(int i=0; i<maxDisciplinas; i++){
    listaAlunos[qtdAlunos].disciplinasMatriculadas[i] = 0;
    }
    //Isso aqui teoricamente tem que matricular o aluno na disciplina, poderia ter usado o do while, mas meh
    while(temp != 0){
        int verificador=0;
        printf("Qual codigo da disciplina que o aluno deve ser matriculado? (Insira 0 para encerrar)\n");
        scanf("%d", &temp);
        if(temp == 0){
            break;
        }else{
            for(int i=0; i<qtdDisciplinas; i++){ //Valida se a disciplina existe
                if(temp==listaDisciplinas[i].codigo){
                    verificador = 1;
                    break;
                }
            }
            if(verificador == 1){                
                if(qtdMatriculas<maxDisciplinas){
                    int jaMatriculado=0;
                    for(i=0; i<qtdMatriculas; i++){
                        if(temp == listaAlunos[qtdAlunos].disciplinasMatriculadas[i]){
                            jaMatriculado = 1;
                            break;
                        }
                    }
                    if(jaMatriculado == 1){
                        printf("Aluno já matriculado na disciplina!\n");
                    }else{
                    listaAlunos[qtdAlunos].disciplinasMatriculadas[qtdMatriculas] = temp;
                    qtdMatriculas++;
                    }
                }else{
                    printf("Limite de disciplinas atingido\n");
                }
            }else{
                printf("A disciplina não existe!\n");
            }
        }
    }
    printf("Aluno matriculado nas seguintes disciplinas: ");
    for(i=0; i<qtdMatriculas; i++){
        printf("%d ",listaAlunos[qtdAlunos].disciplinasMatriculadas[i]);
    }
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
void listarAlunoPoucasDisciplinas(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina ListaDisciplinas[]){
    printf("Os alunos matriculados em menos de 3 disciplinas são: \n");
    for(int i=0; i<qtdAlunos; i++){
        int qtdMatriculas=0, j=0;
        while(listaAlunos[i].disciplinasMatriculadas[j] != 0){
            qtdMatriculas++;
            j++;
        }
        if(qtdMatriculas<3){
            printf("%s\n", listaAlunos[i].nome);
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

//A função adicionarAlunoDisciplina precisa de testes