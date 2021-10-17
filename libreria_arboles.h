#ifndef LIBRERIA_ARBOLES_H_INCLUDED
#define LIBRERIA_ARBOLES_H_INCLUDED

typedef struct _nodoArbol
{
    int dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;


nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(int);
nodoArbol * buscar(nodoArbol*,int);
nodoArbol * insertarConRepetidos(nodoArbol * , int );
nodoArbol * insertarSinRepetidos(nodoArbol * , int );
void postorder(nodoArbol*);
void inorder(nodoArbol*);
void preorder(nodoArbol*);
//dibujar arbol
//FUNCIONES BÁSICAS DE ARBOLES
//int DibujarArbol( nodoArbol * arbol);
//int DibujarArbolLinea( nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255]);

#endif // LIBRERIA_ARBOLES_H_INCLUDED
