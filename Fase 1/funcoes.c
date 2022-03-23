/**
* Author: Mendes
* Email: a23490@alunos.ipca.pt
* Date: 14-03-2022
* Desc: funções
* ???
*/
#include "dados.h"
#include <stdio.h>
#include<malloc.h>

//Operacao* criarOp(int id,int cod, int tempo) {
//
//	Operacao* newOp = (Operacao*)malloc(sizeof(Operacao));
//	
//	if (newOp == NULL) return NULL;
//		newOp->id = id;
//		newOp->maq->cod = cod;
//		newOp->maq->tempo = tempo;
//		newOp->next = NULL;
//		newOp->maq->nxt = NULL;
//		return newOp;
//	
//
//}

Operacao* criarOp(int id, Maquina* machines[N]) {

	Operacao* newOp = (Operacao*)malloc(sizeof(Operacao));

	newOp->id = id;
	for (int i = 0; i < N; i++) {
		newOp->maquinas[i] = machines[i];
	}
	newOp->next = NULL;
	return newOp;


}

Operacao* inserirId(Operacao* h, Operacao* novo) {

	if (existeOp(h, novo->id)) return h;	

	if (h == NULL)		
	{
		h = novo;
	}
	else
	{
		Operacao* aux = h;
		Operacao* auxAnt = NULL;
		while (aux && aux->id < novo->id) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {
			novo->next = h;
			h = novo;
		}
		else
		{
			auxAnt->next = novo;
			novo->next = aux;
		}
	}
	return h;
}

bool existeOp(Operacao* h, int id) {
	if (h == NULL) return false;
	Operacao* aux = h;
	while (aux != NULL) {
		if (aux->id != id) {
			aux = aux->next;
		}
		else {
			return true;
		}
	}
	return false;
}

Operacao* removerOp(Operacao* h, int id) {

	if (h == NULL) return NULL;

	if (h->id == id) {
		Operacao* aux = h;
		h = h->next;
		free(aux);
	}
	else {
		Operacao* aux = h;
		Operacao* auxAnt = aux;
		while (aux && aux->id != id) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;

}

Operacao* alterarMaqOp(Operacao* h,int id, Maquina* machines[N]) {
	Operacao* aux = h;

	if (h == NULL) return NULL;

	while (aux->id != id) {
		aux = aux->next;
		if (aux->next == NULL) return NULL;
	}
	for (int i = 0; i < N; i++) {
		aux->maquinas[i] = machines[i];
		return h;
	}
	
}

bool gravarOp(char* nomeFicheiro, Operacao* h) {
	
	FILE* fp;
	
	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;

	Operacao* aux = h;
	while (aux) {
		fwrite(aux, sizeof(Operacao), 1, fp);
	}
	fclose(fp);
	return true;
}

//Operacao* lerFicheiro(char* nomeFicheiro) {
//	FILE* fp;
//	Operacao* h = NULL;
//	Operacao* aux;
//
//	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
//
//	aux = (Operacao*)malloc(sizeof(Operacao));
//	while (fread(aux, sizeof(Operacao), 1, fp)) {
//		h = inserirId(h, aux);
//		aux = (Operacao*)malloc(sizeof(Operacao));
//
//	}
//	fclose(fp);
//	return h;
//}

void mostraMaquinas(Operacao* opera) {
	if (opera != NULL)
	{
		{
		Operacao* aux = opera;
		printf("operacao %d: ", aux->id);
			for (int i = 0; i < N; i++){
				
				    //if (&aux->maquinas[i]->cod && &aux->maquinas[i]->tempo > 0)
					printf("(%d,%d);", &aux->maquinas[i]->cod, &aux->maquinas[i]->tempo);
				}
			
		}
	}
}

int miniTempo(Operacao* h) {
	int time = 0;
	if (h == NULL) return 0;
	Operacao* aux = h;
	time = &aux->maquinas[0]->tempo;
	for (int i = 1; i < N; i++) {
		if (&aux->maquinas[i]->tempo > 0) {
			if (&aux->maquinas[i]->tempo < time) time = &aux->maquinas[i]->tempo;
		}
	} return time;
}

int miniTempoJob(Operacao* h) {

	int tempo = 0;
	Operacao* aux = h;
	while (aux != NULL) {
		tempo += miniTempo(h);
		aux = aux->next;
	}
	return tempo;
}

int maxTempo(Operacao* h) {
	int time = 0;
	if (h == NULL) return 0;
	Operacao* aux = h;
	time = &aux->maquinas[0]->tempo;
	for (int i = 1; i < N; i++) {
		if (&aux->maquinas[i]->tempo > 0) {
			if (&aux->maquinas[i]->tempo > time) time = &aux->maquinas[i]->tempo;
		}
	} return time;
}

int maxTempoJob(Operacao* h) {

	int tempo = 0;
	Operacao* aux = h;
	while (aux != NULL) {
		tempo += maxTempo(h);
		aux = aux->next;
	}
	return tempo;
}

int mediaTempo(Operacao* h) {

	int x = 0;
	int time = 0;
	if (h == NULL) return 0;
	Operacao* aux = h;
	time = &aux->maquinas[0]->tempo;
	for (int i = 1; i < N; i++) {
		if (&aux->maquinas[i]->tempo > 0) {
			++x;
			time += aux->maquinas[0]->tempo;

		}
	} time = time / x; return time;
}

int mediaTempoJob(Operacao* h) {

	int tempo = 0;
	Operacao* aux = h;
	while (aux != NULL) {
		tempo += mediaTempo(aux);
		aux = aux->next;
	}
	return tempo;
}

