#include <stdio.h>
#include <stdlib.h>


#include "libreriaArboles.h"




nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol *) malloc( sizeof( nodoArbol ) );
    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

nodoArbol * buscar (nodoArbol * arbol, int dato)
{

    nodoArbol* rta= NULL; //primera solucion trivial el arbol está vacio y retorna null
    if (arbol != NULL)   //si el arbol no esta vcio comienza  iterar
    {

        if (dato == arbol->dato)   //segunda solucion trivial el dato es encontrado y retorno el dato;
        {
            rta= arbol;
        }
        else  if (dato > arbol->dato)   //no es igual entonces pregunto si es mayor y me voy por derecha
        {
            rta= buscar (arbol->der,dato);

        }
        else                             //si es menor me voy por izquierda
        {

            rta= buscar(arbol->izq,dato);
        }


    }

    return rta; // retorna null si no encuentra


}

nodoArbol * insertarConRepetidos(nodoArbol * arbol, int dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }

    else
    {
        if(dato>arbol->dato)
        {
            arbol->der = insertarConRepetidos(arbol->der, dato);

        }
        else
        {
            arbol->izq = insertarConRepetidos(arbol->izq, dato);
        }

    }
    return arbol;
}

    nodoArbol * insertarSinRepetidos(nodoArbol * arbol, int dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }

    else
    {
        if(dato>arbol->dato)
        {
            arbol->der = insertarSinRepetidos(arbol->der, dato);

        }
        else if (dato<arbol->dato) //agrego if con condicion menor, si es igual no hace nada y retorna el arbol, es decir no agrega numeros repetidos
        {
            arbol->izq = insertarSinRepetidos(arbol->izq, dato);
        }

    }
    return arbol;
}
void preorder(nodoArbol * arbol) //RID
{
if(arbol != NULL)
{
 printf("%d ", arbol->dato);
 preorder(arbol->izq);
 preorder(arbol->der);
}

}
void inorder(nodoArbol * arbol) //IRD
{
if(arbol != NULL)
{
 inorder(arbol->izq);
 printf("%d ", arbol->dato);
 inorder(arbol->der);
}

}

void postorder(nodoArbol * arbol) //IDR
{
if(arbol != NULL)
{
 postorder(arbol->izq);
 postorder(arbol->der);
 printf("%d ", arbol->dato);
}

}


//dibujar arbol

int DibujarArbolLinea( nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255])
{
    char b[10];
    int ancho = 4; //es el ancho del nodo que dibujo
    int i;

    if (!arbol) return 0;

    sprintf(b, "(%d)", arbol->dato); // agrego valor de nodo a la matriz

    int izq  = DibujarArbolLinea(arbol->izq,  1, inicia,                nivel + 1, s);
    int der = DibujarArbolLinea(arbol->der, 0, inicia + izq + ancho, nivel + 1, s);

    //dibujo nodo
    for (i = 0; i < ancho; i++)
        s[2 * nivel][inicia + izq + i] = b[i];

    //dibujo lineas .----+----.
    if (nivel && esIzq) {

        for (i = 0; i < ancho + der; i++)
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';

    } else if (nivel && !esIzq) {

        for (i = 0; i < izq + ancho; i++)
            s[2 * nivel - 1][inicia - ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia - ancho/2 - 1] = '+';
    }

    //Cerebros quemados everywere!!
    return izq + ancho + der;
}

int DibujarArbol(nodoArbol * arbol)
{
    char s[10][255];
    int i;
    //creo una matriz de char para hacer mi "dibujo"
    for (i = 0; i < 10; i++)
        sprintf(s[i], "%80s", " ");

    //Hago magia
    DibujarArbolLinea(arbol, 0, 0, 0, s);

    //Imprimo matris
    for (i = 0; i < 10; i++)
        printf("%s\n", s[i]);
}
