/**
* Author: Mendes
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc: Dados
* ???
*/

#pragma warning( disable : 4996 )
#include<stdbool.h>


#ifndef DADOS
#define DADOS
#define N 8
#define M 2





#pragma region structs

//typedef struct Job {
//	
//	int nr;
//	struct Operacao* o;
//	struct Job* aseguir;
//
//}Job;

//typedef struct Operacao {
//
//	int id;
//	struct Maquina* maq;
//	struct Operacao* next;
//
//}Operacao,*Operacaoptr;


typedef struct Operacao {

	int id;
	struct Maquina* maquinas[N];
	struct Operacao* next;

}Operacao, * Operacaoptr;


typedef struct Maquina {

	int cod;
	int tempo;

}Maquina;



#pragma endregion

extern Operacao* iniciop;

#pragma region funcoes

Operacao* criarOp(int id,Maquina* machines[N]); //
Operacao* inserirId(Operacao* h, Operacao* novo); //
Operacao* removerOp(Operacao* h,int id); //
Operacao* alterarMaqOp(Operacao* h, Maquina* machines[N]);
bool existeOp(Operacao* h, int id); //
bool gravarOp(char* nomeFicheiro, Operacao* h);
Operacao* lerFicherio(char* nomeFicheiro);
int miniTempo(Operacao* h);
int miniTempoJob(Operacao* h);
int maxTempo(Operacao* h);
int maxTempoJob(Operacao* h);
int mediaTempo(Operacao* h);
int mediaTempoJob(Operacao* h);
void mostraMaquinas(Operacao* opera);

#pragma endregion

#endif



