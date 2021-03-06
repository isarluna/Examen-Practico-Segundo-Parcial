#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
//prototipos
int flip (void);

void mostrarArbol(Nodo *, int );
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
Nodo *arbol=NULL;
int main(){
	
	menu();
	
		
	system("pause");
	return 0;
}

void menu(){
	int value, cruz = 0, cara = 0;//variables de moneda random
	int contador=0,dato, opcion=0;
	
	do {
		
		cout<<" \t Menu  "<<"\n";
		cout<<"1. Moneda  "<<"\n";
		cout<<"2. mostrar el arbol completo\n";
		cout<<"3. Salir   "<<"\n";
		cout<<"opcio--->   "<<"\n";
		cin>>opcion;
		switch(opcion){
			case 1: //inicio moneda
			srand (time (NULL));
  cout <<endl<<"Simulacion del lanzamiento de una moneda." << endl;
  for (int n =1; n<=100; ++n){
    value = flip();
    if (0 == value){
      cout <<"Cruz\n";
      ++cruz;
     }
     else{
      cout <<"Cara"<<endl;
      cara++;
     }
    }

  cout << endl<<"Numero de caras: " << cara << endl;
  cout << "Numero de cruces: "<<cruz<<endl;
			
			//fin moneda
			system("pause");
			break;
			
		case 2:cout<<"Mostrando arbol\n";
		mostrarArbol (arbol,contador);
		cout<<"\n";
		system("pause");
		break;
		}
		system("cls");
	}while(opcion!=3);
}
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo= new Nodo();

	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq==NULL;
  return nuevo_nodo;
}
void insertar (Nodo *&arbol, int n){
	if (arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertar(arbol->izq,n);
		}
		else if (n>valorRaiz){
			insertar(arbol->der,n);
		}
	 else if (n==valorRaiz){
		
			cout<<"Numero invalido";
		
	}
}
}
/////////////////////////////////////////////////////////
void insertarNodo(Nodo *&arbol,int n){
	if (arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n);
		arbol=nuevo_nodo;
	}else{
		int valorRaiz=arbol->dato;
		if (n<valorRaiz){
			insertarNodo(arbol->izq,n);
		}else{
			if (n>valorRaiz){
				insertarNodo(arbol->der,n);
			}
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if (arbol==NULL){
		return ;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for (int i=0; i<cont; i++ ){
			cout<<"   ";
		}
		cout<<arbol->dato<<"\n";
		mostrarArbol(arbol->izq,cont+1);
	}
	
}

//funcion moneda

 int flip (void){
 return rand() % 2;
 }
