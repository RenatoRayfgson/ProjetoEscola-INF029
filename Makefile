ALL: 
	
	gcc -w -Wall FuncoesExtras.c FuncoesAluno.c FuncoesProfessor.c FuncoesDisciplina.c ProjetoEscola.c -o ProjetoEscola -lm -std=c99
	./ProjetoEscola
