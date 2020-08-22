#include <iostream>
#include <list>
#include <stdlib.h>
#include "LaLibreria.h"

using namespace std;

Tlista primeraTorre = NULL;
Tlista segundaTorre = NULL;
Tlista terceraTorre = NULL;

int numDiscos;

void llenarTorre(Tlista l, int n){
	for (int i = n; i >= 1; i--)
    {
        insertarDisco(primeraTorre, i);
    }
}

void torresHanoiAnchura(int discos, Torre *&primeraTorre, Torre *&segundaTorre, Torre *&terceraTorre)
{
		if (discos > 0)
        {
           	 	torresHanoiAnchura(discos - 1, primeraTorre, terceraTorre, segundaTorre);
            	eliminarDisco(primeraTorre, discos);
            	insertarDisco(terceraTorre, discos);
            	torresHanoiAnchura(discos - 1, segundaTorre, primeraTorre, terceraTorre);
        }
}

int main(){
	cout << "Ingresa el numero de discos : ";
    cin >> numDiscos;
    llenarTorre(primeraTorre, numDiscos);
    imprimirLista(primeraTorre);
    
    torresHanoiAnchura(numDiscos, primeraTorre, segundaTorre, terceraTorre);

    imprimirLista(terceraTorre);
    
}
