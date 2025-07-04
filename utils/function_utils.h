#ifndef FUNCTION_UTILS_H
#define FUNCTION_UTILS_H
#include "instrument_utils.h"

void listar(Instrumento instrumentos[], int total);
void listarPorNaipe(Instrumento instrumentos[], int total);
void listarPorNome(Instrumento instrumentos[], int total);
void cadastrar(Instrumento instrumentos[], int *total, int *proxId);
void alterar(Instrumento instrumentos[], int total);
void remover(Instrumento instrumentos[], int *total);

#endif