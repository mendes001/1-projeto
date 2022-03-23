/**
* Author: Mendes
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc: funções
* ???
*/

#include<stdio.h>
#include"dados.h"
#include <locale.h>

void main() {
	
	
	setlocale(LC_ALL, "Portuguese");

	
	
	Maquina maq1[N];
	for (int i = 0; i < N; i++) {
		printf("id da maquina: ");
		scanf("%d",&maq1[i].cod);
		printf("tempo: ");
		scanf("%d",&maq1[i].tempo);
	}

	
	Operacao* op1 = criarOp(1, maq1);
	
	mostraMaquinas(op1);
	
	


	
	
}