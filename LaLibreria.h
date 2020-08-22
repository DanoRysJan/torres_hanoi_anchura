#ifndef _MiLibreria_
#define _MiLibreria_



struct Torre{
	int disco;
	struct Torre *siguiente;
};

typedef struct Torre *Tlista;

Tlista lista = NULL;


void insertarDisco(Tlista &lista, int nDisco){
	Tlista tlista;
	tlista = new (struct Torre);
	tlista->disco = nDisco;
	tlista->siguiente = lista;
	lista = tlista;
}

void eliminarDisco(Tlista &lista, int nDisco){
	if(lista != NULL){
		Torre *aux_borrar;
		Torre *anterior = NULL;
		
		aux_borrar = lista;
		
		while ((aux_borrar != NULL) && (aux_borrar->disco!=nDisco)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			std::cout<<"No se encontro el disco";
			
		}else{
			if(anterior == NULL){
				lista = lista->siguiente;
				delete aux_borrar;
			}else{
				anterior->siguiente = aux_borrar->siguiente;
				delete aux_borrar;
			}
		}
	}
	
}

void imprimirLista(Tlista lista){
	while (lista != NULL){
		std::cout << "Disco:  "  << lista->disco << " " << std::endl;
		lista = lista->siguiente;
	}
	std::cout<<std::endl;
}

#endif
