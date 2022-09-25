#include <stdio.h>
#include <stdlib.h>
#include "totalNumber.h"
   
int main(int argc, char** argv) {
    if(argc != 2){
        printf("Wrong number of arguments! Please, provide input file name\n");
	exit(1);
    }
	
    //Open the .txt file
    //Using fopen() function and "r" just to read
    FILE * file = fopen(argv[1], "r");
	
    if (file == NULL){
	    printf("Error: could not open file %s", argv[1]);
	    return (1);
    }

    int tNumber = totalNumber(file);

    //printf("TOTAL=%d\n",tNumber);

    //Alocando memória para o vetor      
    int * v = (int *) calloc (tNumber+1,sizeof(int));
    
    //Atribuir os valores para o vetor
    int number, i = 1;
    while(fscanf(file, "%d", &number) != EOF){       
        v[i] = number;
	    i++;
    }
    //__________DE 1 ATÉ N ->>>>> Mas o v[0] tá valendo 0 (alocado junto)
    //Então analisar separado
    //Função para ordenar em ordem crescente e verificar os faltantes
    // MERGE-SORT começando com 1
    mergeSort(v,1,tNumber);
    //printArray(v,tNumber);

    //Aproveitar que está ordenado -> verificar se tem valor repetido
    if(verificaRepetido(v,tNumber)){
        printf("\n\n********************************************");
        printf("\n\n******* DELETE OS REPETIDOS PRIMEIRO *******\n\n");
        printf("********************************************\n\n");
        return(1);
    }
    
    
    //Imprimir em um .txt os valores que estao livres
    int mValor = maiorValor(v, tNumber);

    //Criar e salvar em um txt os numeros que estao disponiveis
    int * res = (int *) malloc (mValor+1);
    res = valoresFaltando(v,mValor);
    salvarUSADOS(res,mValor);
    salvarDISPONIVEIS(res,mValor);

    free(v);
    fclose(file);	
    return 0;
}
