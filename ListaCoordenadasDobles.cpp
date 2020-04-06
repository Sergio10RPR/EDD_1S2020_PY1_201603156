#include<iostream>
using namespace std;
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <assert.h>
using namespace std;

class NodoXYD{
	public:
		int x;
		int y;
		NodoXYD *siguiente;

		NodoXYD(int x_,int y_)
		{
			x=x_;
			y=y_;
		}
		NodoXYD(int x_,int y_,NodoXYD *siguiente_)
		{
			x=x_;
			y=y_;
			siguiente=siguiente_;
		}
};
//Prototipo  de funcion////////////
void agregarInicioXYD(int,int);
bool buscarCoordenadaXYD();
void mostrarListaXYD();
int retornarX(int);
int retornarY(int);
//void graficarLista();
///////////////////////////////////
class ListaXYD{
	public:
		NodoXYD *inicio;
		NodoXYD *fin;

		ListaXYD(){
			inicio=NULL;
			fin=NULL;
		}
	void agregarAlInicioXYD(int x,int y){
		inicio=new NodoXYD(x,y,inicio);
		if(fin==NULL){
			fin=inicio;
		}
	}
	void mostrarListaXYD(){
		NodoXYD *recorrer=inicio;
		while(recorrer!=NULL){
			cout<<"|"<<recorrer->x<<"-"<<recorrer->y<<"|"<<"->";
			recorrer=recorrer->siguiente;
		}
	}
	bool buscarCoordenadaXYD(int x,int y){
        NodoXYD *auxiliar=inicio;
        bool encontrado=false;

        while(auxiliar!=NULL && encontrado!=true){
                if(auxiliar->x==x && auxiliar->y==y){
                    //cout<<"COORDENADA ENCONTRADA\n";
                    encontrado=true;
                     return true;
                }
                auxiliar=auxiliar->siguiente;


        }
        if(!encontrado){
                //cout<<"COORDENADA NO ENCONTRADA\n";
                return false;

        }
	}
	int retornarX(int pos){
        int contador=0;
        NodoXYD *auxiliar=inicio;
        while(auxiliar!=NULL){
            if(contador==pos){
                return auxiliar->x;
            }
            contador++;
            auxiliar=auxiliar->siguiente;
        }
        assert(0);
	}
	int retornarY(int pos){
        int contador=0;
        NodoXYD *auxiliar=inicio;
        while(auxiliar!=NULL){
            if(contador==pos){
                return auxiliar->y;
            }
            contador++;
            auxiliar=auxiliar->siguiente;
        }
        assert(0);
	}


};

/*int main()
{
	ListaXYD *lista=new ListaXYD();
	lista->agregarAlInicioXYD(1,10);
	lista->agregarAlInicioXYD(2,11);
	lista->agregarAlInicioXYD(3,12);
	lista->agregarAlInicioXYD(3,13);
	lista->mostrarListaXYD();
	cout<<endl;
	//cout<<lista->buscarCoordenadaXYD(6,13);
	if(lista->buscarCoordenadaXYD(1,10)){
        cout<<"Coordenada Encontrada\n";
	}else{
	    cout<<"Coordenada no encontrada\n";
	}
	cout<<"X:"<<lista->retornarX(0);
	cout<<"X:"<<lista->retornarX(1);
	cout<<"X:"<<lista->retornarX(2);
	cout<<"X:"<<lista->retornarX(3);
	cout<<endl;
	cout<<"Y:"<<lista->retornarY(0);
	cout<<"Y:"<<lista->retornarY(1);
	cout<<"Y:"<<lista->retornarY(2);
	cout<<"Y:"<<lista->retornarY(3);
	//lista->graficarLista();
	return 0;
}*/

