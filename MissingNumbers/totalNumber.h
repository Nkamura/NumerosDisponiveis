#ifndef TOTALNUMBER_H
#define TOTALNUMBER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//_________Utilidade__________

int totalNumber(FILE * file);
int verificaRepetido(int * v, int size);
int * valoresFaltando(int * v, int size);
int maiorValor(int * v, int size);
void printArray(int * v, int size);


//__________SALVA_NO_TXT_______________
void salvarDISPONIVEIS(int * v, int size);
void salvarUSADOS(int * v, int size);

//___________Merge_Sort________________

void merge(int * v, int l, int m, int r);
void mergeSort(int * v, int l, int r);


#endif
