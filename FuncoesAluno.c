#include <stdio.h>
#include <string.h>
#include "ProjetoEscola.h"

void menuAluno(){
    printf("Bem vindo ao menu do aluno:\n"
    "[1] - Matricular aluno\n"
    "[2] - Listar aluno\n"
    "[3] - Remover aluno\n"
    "[4] - Listar aluno por sexo\n"
    "[5] - Listar aluno por idade\n"
    "[6] - Listar aluno matriculado em menos de 3 disciplinas\n"
    "[7] - Listar aluno por ordem alfabetica\n"
    "[8] - Remover aluno de disciplina\n"
    "[9] - Atualizar aluno\n"
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
    while(strcmp(listaAlunos[qtdAlunos].sexo, "M")!=0 && strcmp(listaAlunos[qtdAlunos].sexo, "F")!=0){
        printf("Insira um sexo válido pro aluno (M ou F): \n");
        fgets(listaAlunos[qtdAlunos].sexo, 2, stdin);
        limparBuffer();
    }
    printf("Insira o ano de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.ano);
    limparBuffer();
    while(listaAlunos[qtdAlunos].dataNascimento.ano > 2024 || listaAlunos[qtdAlunos].dataNascimento.ano < 1900){
        printf("Insira um ano de nascimento válido pro aluno: \n");
        scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.ano);
        limparBuffer();
    }    
    printf("Insira o mes de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.mes);
    limparBuffer();
    while(listaAlunos[qtdAlunos].dataNascimento.mes > 12 || listaAlunos[qtdAlunos].dataNascimento.mes < 1){
        printf("Insira um mes de nascimento válido pro aluno: \n");
        scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.mes);
        limparBuffer();
    }    
    printf("Insira o dia de nascimento do aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.dia);
    limparBuffer();
    while(listaAlunos[qtdAlunos].dataNascimento.dia > 31 || listaAlunos[qtdAlunos].dataNascimento.dia < 1){
    printf("Insira um dia de nascimento válido pro aluno: \n");
    scanf("%d", &listaAlunos[qtdAlunos].dataNascimento.dia);
    limparBuffer();
    }
    printf("Insira o CPF do aluno, sem pontos ou traços: \n");
    fgets(listaAlunos[qtdAlunos].cpf, 12, stdin);
    limparBuffer();
    size_t tam = strlen(listaAlunos[qtdAlunos].cpf);
    if(listaAlunos[qtdAlunos].cpf[tam-1] == '\n'){
        listaAlunos[qtdAlunos].cpf[tam-1] = '\0';
    }
    while(strlen(listaAlunos[qtdAlunos].cpf)!= 11){
        printf("Insira um CPF válido pro aluno, sem pontos ou traços: \n");
        fgets(listaAlunos[qtdAlunos].cpf, 12, stdin);
        limparBuffer();
        tam = strlen(listaAlunos[qtdAlunos].cpf);
        if(listaAlunos[qtdAlunos].cpf[tam-1] == '\n'){
            listaAlunos[qtdAlunos].cpf[tam-1] = '\0';
        }
    }
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
void listarAlunoPoucasDisciplinas(struct Aluno listaAlunos[], int qtdAlunos){
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
void listarAlunoSexo(struct Aluno listaAlunos[], int qtdAlunos){
    int i;
    printf("Os alunos masculinos são: \n");
    for(i=0;i<qtdAlunos;i++){
        if (listaAlunos[i].sexo[0] == 'M'){
            printf("%s\n", listaAlunos[i].nome);
        }
    }
    printf("\n");
    printf("As alunas femininas são: \n");
    for(i=0;i<qtdAlunos;i++){
        if (listaAlunos[i].sexo[0] == 'F'){
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
void listarAlunoAlfabeticamente(struct Aluno listaAlunos[], struct Aluno listaOrdenada[], int qtdAlunos){
    int i=0, j=0;
    char temp[128];
    for(i=0; i<qtdAlunos; i++){
        strcpy(listaOrdenada[i].nome, listaAlunos[i].nome);
    }
    for(i=0; i<qtdAlunos-1; i++){
        for(j=i+1; j<qtdAlunos; j++){
            if(strcmp(listaOrdenada[i].nome, listaAlunos[j].nome) > 0){
                strcpy(temp, listaOrdenada[i].nome);
                strcpy(listaOrdenada[i].nome, listaOrdenada[j].nome);
                strcpy(listaOrdenada[j].nome, temp);
            }
        }
    }
    printf("Os alunos em ordem alfabética são:\n");
    for(i=0; i<qtdAlunos; i++){
        printf("%s\n", listaOrdenada[i].nome);
    }
};
void removerAlunoDisciplina(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina listaDisciplinas[], int qtdDisciplinas){
    int i=0,j=0,idAluno=0, temp=0, verificador=0, k=0, qtdMatriculas=0;
    printf("Qual a matricula do aluno que deseja remover da disciplina? \n");
    scanf("%d", &temp);
    for(i=0; i<qtdAlunos; i++){
        if(temp==listaAlunos[i].matricula){
            idAluno=i;
            verificador = 1;
            break;
        }
    }
    if(verificador == 1){
        verificador = 0;
        printf("Qual o codigo da Disciplina que deve ser removida? \n");
        scanf("%d", &temp);
        for(i=0; i<qtdDisciplinas; i++){
            if(temp==listaDisciplinas[i].codigo){                
                verificador = 1;
                break;
            }
        }
        if(verificador == 1){
            while(listaAlunos[idAluno].disciplinasMatriculadas[k]!=0){
                qtdMatriculas++;
                k++;
            }            
            for(i=0; i<qtdMatriculas; i++){
                if(listaAlunos[idAluno].disciplinasMatriculadas[i]==temp){ 
                    listaAlunos[idAluno].disciplinasMatriculadas[i]=listaAlunos[idAluno].disciplinasMatriculadas[qtdMatriculas-1];
                    listaAlunos[idAluno].disciplinasMatriculadas[qtdMatriculas-1]=0;
                    return;
                }
            }
        }else{
            printf("Disciplina não encontrada.\n");
        }
    }else{
        printf("Aluno não encontrado.\n");
    }

}
void atualizarAluno(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina listaDisciplinas[], int qtdDisciplinas){
    int temp, aluno=0, verificador=0, validarMatricula = 1;
    int opcaoAlterar = -1;
    char CPF[12];
    printf("Digite a matrícula do aluno que deseja alterar: \n");
    scanf("%d", &temp);
    for(int i=0; i<qtdAlunos; i++){
        if(temp==listaAlunos[i].matricula){
            aluno = i;
            verificador = 1;
            break;
        }
    }
    if(verificador == 1){
        printf("Selecione o dado que deseja alterar:\n"
        "[1] - Matricula do aluno\n"
        "[2] - Sexo do aluno\n"
        "[3] - Dia de nascimento\n"
        "[4] - Mês de nascimento\n"
        "[5] - Ano de nascimento\n"
        "[6] - CPF\n"
        "[7] - Adicionar aluno em mais uma disciplina\n"    
        "[0] - Cancelar\n ");
        scanf("%d", &opcaoAlterar);
        switch(opcaoAlterar){
            case 1:{
                int jaExiste;
                do{
                    printf("Qual a nova matrícula deste aluno? \n");
                    scanf("%d", &temp);
                    limparBuffer();
                    jaExiste = 0;
                    for(int i=0; i<qtdAlunos; i++){
                        if(temp == listaAlunos[i].matricula){
                            printf("Matrícula já existe! Tente uma diferente!\n");
                            jaExiste = 1;
                            break;
                        }
                    }
                }while(jaExiste);
                listaAlunos[aluno].matricula = temp;
                printf("Matrícula alterada com sucesso!\n");
                break;
            }
            case 2:{
                if(strcmp(listaAlunos[aluno].sexo, "M") == 0){
                    strcpy(listaAlunos[aluno].sexo, "F");
                }else{
                    strcpy(listaAlunos[aluno].sexo, "M");
                }
                printf("Sexo alterado com sucesso!\n");
                break;
            }
            case 3:{
                printf("Qual o novo dia de nascimento do aluno? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 31 || temp < 1){
                    printf("Insira um dia de nascimento válido pro aluno: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaAlunos[aluno].dataNascimento.dia = temp;
                listaAlunos[aluno].idade = listaAlunos[aluno].dataNascimento.ano * 365 + listaAlunos[aluno].dataNascimento.mes * 30 + listaAlunos[aluno].dataNascimento.dia;
                printf("Ano alterado com sucesso!");
                break;
            }
            case 4:{
                printf("Qual o novo mês de nascimento do aluno? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 12 || temp < 1){
                    printf("Insira um mês de nascimento válido pro aluno: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaAlunos[aluno].dataNascimento.mes = temp;
                listaAlunos[aluno].idade = listaAlunos[aluno].dataNascimento.ano * 365 + listaAlunos[aluno].dataNascimento.mes * 30 + listaAlunos[aluno].dataNascimento.dia;
                printf("Mes alterado com sucesso!");
                break;
            }
            case 5:{
                printf("Qual o novo ano de nascimento do aluno? \n");
                scanf("%d", &temp);
                limparBuffer();
                while(temp > 2024 || temp < 1900){
                    printf("Insira um ano de nascimento válido pro aluno: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                }
                listaAlunos[aluno].dataNascimento.ano = temp;
                listaAlunos[aluno].idade = listaAlunos[aluno].dataNascimento.ano * 365 + listaAlunos[aluno].dataNascimento.mes * 30 + listaAlunos[aluno].dataNascimento.dia;
                printf("Dia alterado com sucesso!");
                break;
            }
            case 6:{
                printf("Insira o novo CPF do aluno, sem pontos ou traços: \n");
                fgets(CPF, 12, stdin);
                limparBuffer();
                size_t tam = strlen(CPF);
                if(CPF[tam-1] == '\n'){
                    CPF[tam-1] = '\0';
                }
                while(strlen(CPF)!= 11){
                    printf("Insira um CPF válido pro aluno, sem pontos ou traços: \n");
                    fgets(CPF, 12, stdin);
                    limparBuffer();
                    tam = strlen(CPF);
                    if(CPF[tam-1] == '\n'){
                        CPF[tam-1] = '\0';
                    }
                }
                strcpy(listaAlunos[aluno].cpf, CPF);
                break;
            }
            case 7:{
                printf("Qual o código da disciplina que o aluno deve ser adicionado? \n");
                scanf("%d", &temp);
                int qtdMatriculas=0; int j=0; int disciplinaExiste=0;
                verificador = 0;
                while(listaAlunos[aluno].disciplinasMatriculadas[j] != 0){
                    if(temp == listaAlunos[aluno].disciplinasMatriculadas[j]){
                        printf("Aluno já matriculado na disciplina!\n");
                        verificador = 1;
                        break;
                    }
                    j++;
                }
                if(verificador == 0){
                    for(int i=0; i<qtdDisciplinas; i++){
                        if(listaDisciplinas[i].codigo == temp){
                            disciplinaExiste = 1;
                            break;
                        }
                    }
                    if(disciplinaExiste == 1){
                        listaAlunos[aluno].disciplinasMatriculadas[j] = temp;
                        printf("Aluno matriculado na disciplina com sucesso!\n");
                    }                
                }
                break;            
            }
            case 0:{
                opcaoAlterar = -1;
                break;
            }
        }
    }else{
        printf("Aluno não encontrado!");
    }
};
