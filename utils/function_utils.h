#ifndef FUNCTION_UTILS_H
#define FUNCTION_UTILS_H

#include "instrument_utils.h"

void salvar(Instrumento instrumentos[], int total);
void carregar(Instrumento instrumentos[], int *total, int *proxId);
int cadastrar(Instrumento instrumentos[], int *total, int *proxId, char *nome, char *naipe, float preco);
int alterar(Instrumento instrumentos[], int total, int id, float novoPreco);
int remover(Instrumento instrumentos[], int *total, int id);

#endif