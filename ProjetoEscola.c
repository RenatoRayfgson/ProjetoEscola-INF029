#include <stdio.h>
#include "ProjetoEscola.h"
#include <string.h>
#include <locale.h> //Tentei fazer essa porcaria escrever em PTBR no Vscode, por algum motivo não funcionou aqui
int main(){    
    setlocale(LC_ALL,"Portuguese"); 
    int opcao=-1, opcaoAluno=-1, opcaoProfessor=-1, opcaoDisciplina=-1;
    int i=0,j=0,qtdAlunos=0,temp,verificador=0,qtdProfessores=0, qtdDisciplinas=0, aux;
    struct Aluno listaAlunos[maxAlunos];   
    struct Professor listaProfessores[maxProfessores]; 
    struct Disciplina listaMatriculados[maxAlunos];
    struct Disciplina listaDisciplinas[maxDisciplinas];
    while(opcao != 0){
        opcaoProfessor = -1; opcaoAluno = -1; opcaoDisciplina = -1;
        menuPrincipal();
        scanf("%d", &opcao);
        limparBuffer();
        switch(opcao){     //Caso o erro de assumir o anterior continue acontecendo, colocar opcao=-1; apos cada case, mas, teoricamente, nao tem que acontecer
            case 0:{
                break;
            }
            case 1:{    //Aluno                
                while(opcaoAluno != 0){
                    menuAluno();
                    scanf("%d", &opcaoAluno);
                    limparBuffer();  
                    switch(opcaoAluno){
                        case 0:{    //Voltar                                
                            break;
                        }
                        case 1:{    //Matricular aluno
                            opcaoAluno = -1;
                            if(qtdAlunos>=maxAlunos){
                                printf("Quantidade máxima de alunos atingida!\n");
                            }else{
                                printf("Insira a matrícula do novo aluno: \n");
                                scanf("%d", &temp);
                                limparBuffer();
                                for(i=0;i<qtdAlunos;i++){
                                    if(temp==listaAlunos[i].matricula){
                                        printf("Matrícula já registrada!\n");
                                        break;
                                    }
                                }
                                listaAlunos[qtdAlunos].matricula=temp;
                                matricularAluno(listaAlunos, temp, qtdAlunos); 
                                adicionarAlunoDisciplina(listaAlunos, qtdAlunos, listaDisciplinas, qtdDisciplinas);                             
                                qtdAlunos++;
                                break;
                            }
                        }
                        case 2:{    //Listar alunos
                            opcaoAluno = -1;
                            listarAluno(listaAlunos,qtdAlunos);
                            break;
                        }
                        case 3:{    //Remover aluno
                            opcaoAluno = -1;
                            printf("Qual a matricula do aluno que deve ser removido?\n");
                            scanf("%d",&temp);
                            for(i=0;i<qtdAlunos;i++){
                                if(temp==listaAlunos[i].matricula){
                                    verificador=1;
                                    break;
                                }
                            }
                            i=0;
                            if(verificador==1){
                                removerAluno(temp, listaAlunos, j, i, qtdAlunos);
                                qtdAlunos--;                                
                                break;
                            }else{
                                verificador=0;
                                printf("Aluno não matriculado");
                                break;
                            }
                        }
                        case 4:{
                            opcaoAluno = -1;
                            listarAlunoSexo(listaAlunos, qtdAlunos);
                            break;
                        }
                        case 5:{
                            opcaoAluno = -1;
                            listarAlunoIdade(listaAlunos, qtdAlunos);
                            break;
                        }
                        case 6:{
                            opcaoAluno = -1;
                            listarAlunoPoucasDisciplinas(listaAlunos, qtdAlunos);
                            break;
                        }
                        default:{    //Caso o usuário seja incapaz de ler
                            printf("Opção invalida!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{    //Professor                
                while(opcaoProfessor != 0){
                    menuProfessor();
                    scanf("%d", &opcaoProfessor);
                    limparBuffer();
                    switch(opcaoProfessor){
                        case 0:{    //Voltar                            
                            break;
                        }
                        case 1:{    //Matricular professor
                            opcaoProfessor = -1;                            
                            if(qtdProfessores>=maxProfessores){
                                printf("Quantidade máxima de professores atingida!\n");
                            }else{
                                printf("Insira a matrícula do novo professor: \n");
                                scanf("%d", &temp);
                                limparBuffer();
                                for(i=0;i<qtdProfessores;i++){
                                    if(temp==listaProfessores[i].matricula){
                                        printf("Matrícula já registrada!\n");
                                        break;
                                    }
                                }
                                matricularProfessor(listaProfessores, temp, qtdProfessores);
                                qtdProfessores++;
                                break;
                            }
                        }
                        case 2:{    //Listar professores
                            opcaoProfessor = -1;
                            if(qtdProfessores==0){
                                printf("Nenhum professor matriculado!\n");
                            }else{
                                listarProfessor(listaProfessores, qtdProfessores);
                            }break;
                        }
                        case 3:{    //Remover professor
                            opcaoProfessor = -1;
                            printf("Qual a matricula do professor que deve ser removido?\n");
                            scanf("%d",&temp);
                            for(i=0;i<qtdProfessores;i++){
                                if(temp==listaProfessores[i].matricula){
                                    verificador=1;
                                    break;
                                }
                            }
                            i=0;
                            if(verificador==1){
                                removerProfessor(listaProfessores, i, j, qtdProfessores, temp);
                                qtdProfessores--;
                                verificador=0;                                
                                break;
                            }else{
                                verificador=0;
                                printf("Professor não matriculado\n");
                                break;
                            }
                        }
                        case 4:{
                            opcaoProfessor = -1;
                            listarProfessorSexo(listaProfessores, qtdProfessores);
                            break;
                        }
                        case 5:{
                            opcaoProfessor = -1;
                            listarProfessorIdade(listaProfessores, qtdProfessores);
                            break;
                        }
                        default:{
                            printf("Opção invalida!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{    //Disciplina                
                while(opcaoDisciplina != 0){
                    menuDisciplina();
                    scanf("%d", &opcaoDisciplina);
                    limparBuffer();  
                    switch(opcaoDisciplina){
                        case 0:{     //Voltar                              
                            break;
                        }
                        case 1:{     //Criar disciplina 
                            opcaoDisciplina = -1;
                            if(qtdDisciplinas<maxDisciplinas){
                                printf("Qual a matricula do professor da Disciplina?\n");
                                scanf("%d", &temp);
                                for(i=0;i<qtdProfessores;i++){
                                    if(temp==listaProfessores[i].matricula){
                                        verificador=1;
                                        break;
                                    }
                                }
                                if(verificador==1){
                                    listaDisciplinas[qtdDisciplinas].matriculaProfessor=temp;
                                    verificador=0;
                                }else{
                                    printf("Professor não matriculado");
                                    break;
                                }
                                i=0;                                
                                criarDisciplina(qtdDisciplinas, listaDisciplinas);                                                           
                                qtdDisciplinas++;
                                break;
                            }else{
                                printf("Número máximo de disciplinas atingido");
                            }                            
                        }
                        case 2:{     //Listar disciplina
                            opcaoDisciplina = -1;
                            if(qtdDisciplinas==0){
                                printf("Não há disciplinas existentes");
                            }else{
                                listarDisciplina(qtdDisciplinas, listaDisciplinas);
                            }                            
                            break;
                        }
                        case 3:{     //Remover disciplina
                            opcaoDisciplina = -1;
                            printf("Qual o código da disciplina que deve ser removida?\n");
                            scanf("%d",&temp);
                            for(i=0;i<qtdDisciplinas;i++){
                                if(temp==listaDisciplinas[i].codigo){
                                    verificador=1;
                                    break;
                                }
                            }
                            i=0;
                            if(verificador==1){
                                removerDisciplina(temp, j, i, qtdDisciplinas, listaDisciplinas);
                                qtdDisciplinas--;
                                verificador=0;                                
                                break;
                            }else{
                                verificador=0;
                                printf("Nenhuma Disciplina com esse código foi encontrada!");
                                break;
                            }
                        }
                        default:{     //Caso o usuário seja incapaz de ler
                            printf("Opção inválida");
                        }
                    }
                }
                break;
            }
            case 4:{ //Aniversariantes do mês
                aniversariantesMes(listaProfessores, listaAlunos, qtdProfessores, qtdAlunos);
                break;
            }
            case 5:{ //Busca por nome
                buscaPessoas(listaProfessores, listaAlunos, qtdProfessores, qtdAlunos);
                break;
            }
            default:{    //Caso o usuário seja incapaz de ler
                printf("Opção inválida!\n");
            }
        }
    }
    return 0;
}
