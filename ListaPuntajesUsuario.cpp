#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "colorwin.hpp"
#include "ListaSorted.cpp"
using namespace std;
using namespace colorwin;
NodoLS* head2=NULL;
template <typename Y>
std::string ToStringPun(Y val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
class NodoLP{
	public:
		string usuario;
		string puntaje;
		NodoLP *siguiente;

		NodoLP(string usuario_,string puntaje_)
		{
			usuario=usuario_;
			puntaje=puntaje_;
		}
		NodoLP(string usuario_,string puntaje_,NodoLP *siguiente_)
		{
			usuario=usuario_;
			puntaje=puntaje_;
			siguiente=siguiente_;
		}
};
//Prototipo  de funcion////////////
void agregarInicioP(string,string);
void buscarCoordenadaP();
void mostrarListaP();
void graficarListaP();
void buscarPuntajeP();
///////////////////////////////////
class ListaPunt{
	public:
		NodoLP *inicio;
		NodoLP *fin;

		ListaPunt(){
			inicio=NULL;
			fin=NULL;
		}
	void agregarAlInicioP(string usuario,string puntaje){
		inicio=new NodoLP(usuario,puntaje,inicio);
		if(fin==NULL){
			fin=inicio;
		}
	}
	void mostrarListaP(){
		NodoLP *recorrer=inicio;
		while(recorrer!=NULL){
			cout<<"|"<<recorrer->usuario<<"-"<<recorrer->puntaje<<"|"<<"->";
			recorrer=recorrer->siguiente;
		}
	}

	void graficarListaP(){
	    int contador=0;
		ofstream archivo;
		NodoLP *recorrer=inicio;
		string dot="";
		string edge="";
		string nulo=ToStringPun("null[label=")+ToStringPun("\"")+ToStringPun("NULL")+ToStringPun("\"")+ToStringPun(",style=filled,fillcolor=bisque1];");
		archivo.open("listaEnlazada.dot",ios::out);
		if(archivo.fail())
		{
			cout<<"No se pudo crear el archivo"<<endl;
		}
		else{


		while(recorrer!=NULL){
			dot=dot+ToStringPun(recorrer->usuario)+"_"+ToStringPun(recorrer->puntaje)+"_"+ToStringPun(contador)+"[label="+"\""+"USUARIO: "+ToStringPun(recorrer->usuario)+"\\l"+"PUNTAJE: "+ToStringPun(recorrer->puntaje)+"\""
			    +",style=filled,fillcolor=bisque1"+"];"+"\n";
			edge=edge+ToStringPun(recorrer->usuario)+"_"+ToStringPun(recorrer->puntaje)+"_"+ToStringPun(contador)+"->"+"\n";
            contador++;
			recorrer=recorrer->siguiente;
				if(fin==NULL)
			{
				cout<<"LLego a null";
			}
		}
		archivo<<"digraph G{\n";
		archivo<<"rankdir=LR;\n";

		archivo<<"node[shape=component,fontcolor=brown4,width=1.5,margin=0.2]";
		archivo<<nulo;
		archivo<<dot;
		archivo<<edge<<"null";
		archivo<<"}\n";
		archivo.close();
		system("dot listaEnlazada.dot -o listaEnlazada.png -Tpng");
        system("start listaEnlazada.png");
		//cout<<dot;
	}
	}
	void buscarPuntajeP(string usuario){
	    NodoLS* head = NULL;
        NodoLP *auxiliar=inicio;
        bool encontrado=false;
        while(auxiliar!=NULL){
            if(auxiliar->usuario==usuario){
                //cout<<auxiliar->puntaje<<"->";
                NodoLS *nodito=nuevoNodo(auxiliar->puntaje,usuario);
                NodoLS *nodito_=nuevoNodo(auxiliar->puntaje,usuario);
                insertarOrdenado(&head,nodito);
                insertarOrdenado(&head2,nodito_);
                encontrado=true;
            }
            auxiliar=auxiliar->siguiente;
        }
         if(!encontrado){
                cout<<color(red)<<"USUARIO NO REGISTRADO\n";

        }
        if(encontrado==true)
        graficarLista(head);
	}


};

/*int main()
{
	ListaPunt *lista=new ListaPunt();
	lista->agregarAlInicioP("sergio","10");
	lista->agregarAlInicioP("fernando","11");
	lista->agregarAlInicioP("sergio","12");
	lista->agregarAlInicioP("pilar","13");
	lista->agregarAlInicioP("pilar","14");
	lista->agregarAlInicioP("pilar","15");
	lista->agregarAlInicioP("pilar","16");
	lista->mostrarListaP();
	cout<<endl;
	lista->buscarPuntajeP("pilar");
	cout<<endl;
	//lista->buscarCoordenada(3,13);
	cout<<endl;
	//lista->graficarLista();
	 //graficarLista(head);

	return 0;
}*/
