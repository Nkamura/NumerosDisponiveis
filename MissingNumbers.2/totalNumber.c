#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "totalNumber.h"


/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int * v, int size){
    int i;
    for (i = 1; i < size + 1; i++)
        printf("Vetor[%d]=%d\n",i,v[i]);
    printf("\n");
}

int totalNumber(FILE * file){
	int totalNumber = 0;
    	char ch;
    	while((ch=fgetc(file))!=EOF){
        	if(ch == '\n'){
            		totalNumber++;
	    	}
    	}
	rewind(file);
	return(totalNumber);
}

int verificaRepetido(int * v, int size){
    //Como está ordenado, pega o valor e ve se o próximo é igual
   int count = 0;
    int repetiu = 0;    
   for(int i = 1; i < size+1; i++){
          while(v[i] == v[i+1]){
                count ++;
                i++;
                repetiu++;            
            }
          if(count!=0){
             printf("\nValor Repetido %d x %d vezes\n",v[i],count);           
            count = 0;            
            }
    }    
    if(repetiu == 0){
        return(0);    
    }else{
        return(1);
    }
}


int * valoresFaltando(int * v, int size){
    int * vetorSinalizador = (int *) calloc(size + 1,sizeof(int));
    for(int i = 1; i < size + 1; i++){
        vetorSinalizador[v[i]] = 1; 
    }
    //printArray(vetorSinalizador,size);
    /**
    for(int j=0; j < size + 1; j++){
        if(vetorSinalizador[j]==0){
            printf("\nFALTANDO: %d\n",j);
        }
    }
    **/
    return vetorSinalizador;
}

int maiorValor(int * v, int size){
    int maior = 0;
    for(int i = 1; i < size + 1; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return(maior);
}


//___________________________________________



/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int * v, int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
 
        merge(v, l, m, r);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int * v, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void salvarDISPONIVEIS(int * v, int size){
    FILE * farq; 
    if((farq = fopen("USADOS.txt","w")) == NULL){
        printf( "Erro na abertura do arquivo");
        exit(1);
    }
    for(int i = 1; i < size + 1; i++){
        if(v[i] != 0){
            fprintf(farq,"%d\n",i);
        }
    }
    fclose(farq);
}

void salvarUSADOS(int * v, int size){
    FILE * farq;
    if((farq = fopen("DISPONVEIS.txt","w")) == NULL){
        printf( "Erro na abertura do arquivo");
        exit(1);
    }
    for(int i = 1; i < size + 1; i++){
        if(v[i] == 0){
            fprintf(farq,"%d\n",i);
        }
    }
    fclose(farq);
}
