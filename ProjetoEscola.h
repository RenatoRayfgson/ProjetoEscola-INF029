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
void listarAlunoSexo(struct Aluno listaAlunos[], int qtdAlunos);
void listarAlunoIdade(struct Aluno listaAlunos[], int qtdAlunos);
void listarAlunoPoucasDisciplinas(struct Aluno listaAlunos[], int qtdAlunos); //Tirei struct Disciplina listaDisciplinas[]
void listarAlunoAlfabeticamente(struct Aluno listaAlunos[], struct Aluno listaOrdenada[], int qtdAlunos);
void removerAlunoDisciplina(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina listaDisciplinas[], int qtdDisciplinas);
void atualizarAluno(struct Aluno listaAlunos[], int qtdAlunos, struct Disciplina listaDisciplinas[], int qtdDisciplinas);

//Disciplina
void menuDisciplina();
void criarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[], int temp, int validarDisciplina);
void listarDisciplina(int qtdDisciplinas, struct Disciplina listaDisciplinas[]);
void listarDisciplinaCompleto(int qtdDisciplinas, struct Disciplina listaDisciplinas[], int qtdAlunos, struct Aluno listaAlunos[]);
void removerDisciplina(int temp, int j, int i, int qtdDisciplinas, struct Disciplina listaDisciplinas[]);
void atualizarDisciplina(struct Disciplina listaDisciplinas[], int qtdDisciplinas, struct Professor listaProfessores[], int qtdProfessores);

//Professores
void menuProfessor();
void matricularProfessor(struct Professor listaProfessores[], int temp, int qtdProfessores);
void listarProfessor(struct Professor listaProfessores[], int qtdProfessores);
void removerProfessor(struct Professor listaProfessores[], int i, int j, int qtdProfessores, int temp);
void listarProfessorSexo(struct Professor listaProfessores[], int qtdProfessores);
void listarProfessorIdade(struct Professor listaProfessores[], int qtdProfessores);
void listarProfessorAlfabeticamente(struct Professor listaProfessores[], struct Professor listaOrdenada[], int qtdProfessores);
void atualizarProfessor(struct Professor listaProfessores[], int qtdProfessores, struct Disciplina listaDisciplinas[], int qtdDisciplinas);
