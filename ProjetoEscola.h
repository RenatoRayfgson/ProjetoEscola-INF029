#define maxAlunos 5 
#define maxProfessores 5 
#define maxDisciplinas 5
struct Data{
    int dia,mes,ano;
};

struct Aluno{
    int matricula;
    char nome[128];
    char sexo[2]; 
    struct Data dataNascimento;
    char cpf[12];
    int idade; //Em dias
    int disciplinasMatriculadas[maxDisciplinas];
};

struct Professor{
    int matricula;
    char nome[128];
    char sexo[2]; 
    struct Data dataNascimento;
    char cpf[12];
    int idade; //Em dias
};

struct Disciplina{
    int codigo;
    int semestre;
    char nome[128];
    int matriculaProfessor;
};

//Extras
void menuPrincipal();
void limparBuffer();
void aniversariantesMes(struct Professor listaProfessores[], struct Aluno listaAlunos[], int qtdProfessores, int qtdAlunos);
void buscaPessoas(struct Professor listaProfessores[], struct Aluno listaAlunos[], int qtdProfessores, int qtdAlunos);

//Aluno
void menuAluno();
void matricularAluno(struct Aluno listaAlunos[], int temp, int qtdAlunos);
void listarAluno(struct Aluno listaAlunos[], int qtdAlunos);
void removerAluno(int temp, struct Aluno listaAlunos[], int j, int i, int qtdAlunos);
void listaAlunoSexo(struct Aluno listaAlunos[], int qtdAlunos);
void listarAlunoIdade(struct Aluno listaAlunos[], int qtdAlunos);
void listarAlunoPoucasDisciplinas(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina ListaDisciplinas[]);

//Disciplina
void menuDisciplina();
void criarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[]);
void listarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[]);
void removerDisciplina(int temp, int j, int i, int qtdDisciplinas, struct Disciplina listaDisciplinas[]);

//Professores
void menuProfessor();
void matricularProfessor(struct Professor listaProfessores[], int temp, int qtdProfessores);
void listarProfessor(struct Professor listaProfessores[], int qtdProfessores);
void removerProfessor(struct Professor listaProfessores[], int i, int j, int qtdProfessores, int temp);
void listaProfessorSexo(struct Professor listaProfessores[], int qtdProfessores);
void listarProfessorIdade(struct Professor listaProfessores[], int qtdProfessores);
