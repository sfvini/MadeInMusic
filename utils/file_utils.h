#ifndef FILE_UTILS_H
#define FILE_UTILS_H
    
#include "instrument_utils.h"

void salvar(Instrumento instrumentos[], int total);
void carregar(Instrumento instrumentos[], int *total, int *proxId);

#endif