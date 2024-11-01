#include <stdio.h>
#include "ProjetoEscola.h"

void menuDisciplina(){
    printf("Bem vindo ao menu de Disciplina:\n"
    "[1] - Criar Disciplina\n"
    "[2] - Listar Disciplinas\n"
    "[3] - Remover Disciplina\n"
    "[4] - Listar Disciplina com alunos matriculados\n"
    "[5] - Atualizar Disciplina\n"
    "[0] - Voltar\n ");
};
void criarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[],int temp, int validarDisciplina ){    
    limparBuffer();
    printf("Qual o nome da Disciplina? ");
    gets(listaDisciplinas[qtdDisciplinas].nome);    
    limparBuffer();
    while(validarDisciplina!=1){
        printf("Qual o código da nova Disciplina? \n");
        scanf("%d", &temp);
        limparBuffer();
        int jaExiste = 0;
        for(int i=0; i<qtdDisciplinas; i++){
            if(temp==listaDisciplinas[i].codigo){
                printf("Este código já existe! Insira um código diferente! \n");
                jaExiste = 1;
                break;
            }
        }
        if(jaExiste == 0){
            validarDisciplina = 1;
        }
    }
    listaDisciplinas[qtdDisciplinas].codigo = temp;
    printf("Qual o semestre da Disciplina? ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
    limparBuffer();       
};
void listarDisciplinaCompleto(int qtdDisciplinas, struct Disciplina listaDisciplinas[], int qtdAlunos, struct Aluno listaAlunos[]){
    int temp, i=0, j=0, k=0, verificador=0;
    printf("Qual o código da disciplina que deve ser listada?\n");
    scanf("%d",&temp);
    for(i=0;i<qtdDisciplinas;i++){
        if(temp==listaDisciplinas[i].codigo){
            verificador=1;
            break;
        }
    }
    if(verificador == 1){
        printf("Disciplina: %s\n"
        "Semestre: %d\n"
        "Código: %d\n"
        "Professor de matrícula: %d\n", listaDisciplinas[i].nome, listaDisciplinas[i].semestre, listaDisciplinas[i].codigo, listaDisciplinas[i].matriculaProfessor);
        printf("Os seguintes alunos estão matriculados na disciplina: \n");
        for(j=0; j<qtdAlunos; j++){
            while(listaAlunos[j].disciplinasMatriculadas[k] != 0){
                if(listaAlunos[j].disciplinasMatriculadas[k] == temp){
                    printf("%s\n", listaAlunos[j].nome);
                    break;
                }
                k++;
            }
            k=0;
        } 
    }else{
        printf("Disciplina não registrada!\n");
    }
   
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
void atualizarDisciplina(struct Disciplina listaDisciplinas[], int qtdDisciplinas, struct Professor listaProfessores[], int qtdProfessores){
    int temp, disciplina, verificador = 0, opcaoAlterar = -1, jaExiste;
    printf("Digite o código da disciplina que deseja alterar: \n");
    scanf("%d", &temp);
    limparBuffer();
    for(int i=0; i<qtdDisciplinas; i++){
        if(temp==listaDisciplinas[i].codigo){
            disciplina = i;
            verificador = 1;
            break;
        }
    }
    if(verificador == 1){
        printf("Selecione o dado que deseja alterar:\n"
        "[1] - Codigo da disciplina\n"
        "[2] - Semestre da disciplina\n"
        "[3] - Nome da disciplina\n"
        "[4] - Professor responsável\n"    
        "[0] - Cancelar\n ");
        scanf("%d", &opcaoAlterar);
        limparBuffer();
        switch(opcaoAlterar){
            case 1:{
                do{
                    printf("Insira o novo codigo dessa disciplina: \n");
                    scanf("%d", &temp);
                    limparBuffer();
                    jaExiste = 0;
                    for(int i=0; i<qtdDisciplinas; i++){
                        if(temp == listaDisciplinas[i].codigo){
                            printf("A disciplina já existe! Tente outro código\n");
                            jaExiste=1;
                            break;
                        }
                    }
                }while(jaExiste);
                listaDisciplinas[disciplina].codigo=temp;
                printf("Código alterado com sucesso!\n");
                break;
            }
            case 2:{
                printf("Insira o novo semestre dessa disciplina: \n");
                scanf("%d", &listaDisciplinas[disciplina].semestre);
                limparBuffer();
                break;
            }
            case 3:{
                printf("Insira o novo nome da disciplina: \n");
                fgets(listaDisciplinas[disciplina].nome,128,stdin);
                limparBuffer();
                break;
            }
            case 4:{
                do{
                printf("Qual a matricula do professor novo? \n");
                scanf("%d", &temp);
                limparBuffer();
                jaExiste = 0;
                    for(int i=0; i<qtdProfessores; i++){
                        if(temp == listaProfessores[i].matricula){
                            jaExiste=1;
                            break;
                        }
                    }
                    if(jaExiste == 0){
                        printf("Insira uma matricula válida!\n");
                    }
                }while(!jaExiste);
                listaDisciplinas[disciplina].matriculaProfessor = temp;
                printf("Professor alterado com sucesso!\n");
                break;
            }
            case 0:{
                break;
            }
        }
    }else{
        printf("Disciplina não encontrada\n");
    }
}