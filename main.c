#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#include "libreriaArboles.h"

int main()
{
    printf("LIBRERIA DE FUNCIONES BASICAS DE ARBOLES\n");
    nodoArbol* arbol;
    arbol=inicArbol();

    //CARGAR ARBOL CON NUMEROS RANDOM
//    srand(time (NULL));
//    for (int i=0; i<10;i++){
//        int num= rand()%100;
//
//        arbol=insertarSinRepetidos(arbol,num);
//    }

    //cargar arbol desde un arreglo desordenado

    int arreglo[8]= {24,15,99,7,21,32,44,26};

    for (int i=0; i<8;i++){

        arbol=insertarSinRepetidos(arbol,arreglo[i]);
    }
//    printf("\nMOSTRAR ARBOL PREORDEN\n");
//    preorder(arbol);
//     printf("\nMOSTRAR ARBOL INORDEN\n");
//     inorder(arbol);
//      printf("\nMOSTRAR ARBOL POSTORDEN\n");
//      postorder(arbol);
      printf("\n");
DibujarArbol(arbol);
    return 0;
}


