#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <cstdlib>
#include <assert.h>
using namespace std;
int tamanioListaFichas_=0;
template<typename E>
std::string ToStringListF(E val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
class NodoLED_F
{
private:
    string dato;
    string punteo;
    NodoLED_F *previo;
    NodoLED_F *siguiente;

    friend class ListaEnlazadaDoble_F;
};
class ListaEnlazadaDoble_F
{
public:
    ListaEnlazadaDoble_F(); //Constructor
    ~ListaEnlazadaDoble_F();//Destructor
    string getFront_F() const;
    string getBack_F()  const;
    void addFront_F(string,string);
    void addBack_F(string);
    void removeFront_F();
    void removeBack_F();
    void printReverse_F();
    void printForward_F();
    void graphList_F();
    bool buscarNodo_F(string);
    void modificarNodo_F(string,string);
    void eliminarNodo_F(string);
    string getNode_F();
    int tamanioListaFichas();
    string retornarNodoPos(int);
    string retornarPunteo(int);
    int tamanioStockUsuario();

private:
    NodoLED_F *header;
    NodoLED_F *trailer;

};
ListaEnlazadaDoble_F::ListaEnlazadaDoble_F()
{
    header=new NodoLED_F();
    trailer=new NodoLED_F();
    header->siguiente=trailer;
    trailer->previo=header;
    header->previo=NULL;
    trailer->siguiente=NULL;
}
string ListaEnlazadaDoble_F::getFront_F()const
{
    return ListaEnlazadaDoble_F::header->siguiente->dato;
}
string ListaEnlazadaDoble_F::getBack_F()const
{
    return trailer->previo->dato;
}
string ListaEnlazadaDoble_F::getNode_F(){
    string nodo="";
    NodoLED_F *newNode = header->siguiente->siguiente;//Guarda el nodo siguiente al head, head que se va a eliminar
    //cout<<"TEORICAMENTE EL NODO ELIMINADO :"<<newNode->previo->dato<<endl;
    nodo=newNode->previo->dato;
    delete header->siguiente;
    header->siguiente=newNode;//Apunta al nodo que se habia guardado
    newNode->previo=header;
    return nodo;
}
void ListaEnlazadaDoble_F::addFront_F(string dato_,string punteo_)
{
    NodoLED_F *newNode = new NodoLED_F;
    newNode->dato=dato_;
    newNode->punteo=punteo_;
    newNode->previo=header;
    newNode->siguiente=header->siguiente; //Apuntaria al head que este actualmente

    header->siguiente->previo=newNode;
    header->siguiente=newNode;
    tamanioListaFichas_++;
}
/*void ListaEnlazadaDoble_F::addBack_F(string dato_)
{
    NodoLED_F *newNode = new NodoLED_F();
    newNode->dato=dato_;
    newNode->previo=trailer->previo;
    newNode->siguiente=trailer;

    trailer->previo->siguiente=newNode;
    trailer->previo=newNode;
}*/
void ListaEnlazadaDoble_F::removeFront_F()
{
    NodoLED_F *newNode = header->siguiente->siguiente;//Guarda el nodo siguiente al head, head que se va a eliminar
    //cout<<"TEORICAMENTE EL NODO ELIMINADO :"<<newNode->previo->dato<<endl;
    delete header->siguiente;
    header->siguiente=newNode;//Apunta al nodo que se habia guardado
    newNode->previo=header;
    tamanioListaFichas_--;
}
void ListaEnlazadaDoble_F::removeBack_F()
{
    NodoLED_F *newNode = trailer->previo->previo;
    delete trailer->siguiente;
    trailer->previo->siguiente=trailer;
}
void ListaEnlazadaDoble_F::printReverse_F()
{

    NodoLED_F *newNode = trailer->previo;
    while(newNode!=header)
    {
        cout<<"["<<newNode->dato<<"]"<<newNode->punteo;

        newNode=newNode->previo;

    }
}
void ListaEnlazadaDoble_F::printForward_F()
{
    NodoLED_F *newNode = header->siguiente;
    while(newNode != trailer)
    {
        cout<<newNode->dato<<"->";
        newNode=newNode->siguiente;
    }
}
bool ListaEnlazadaDoble_F::buscarNodo_F(string ficha)
{
    NodoLED_F *newNode = trailer->previo;
    bool encontrado=false;
    //string nodoABuscar="";
    //cout<<"Ingrese el nodo a buscar:"<<endl;
    //cin>>nodoABuscar;
    while(newNode!=header && encontrado!=true)
    {
        if(newNode->dato==ficha)
        {
             //cout<<"El nodo si existe :"<<newNode->dato<<endl;
             return true;
             encontrado=true;

        }


        newNode=newNode->previo;

    }
     if(!encontrado)
        {
            //cout<<"FICHA NO ENCONTRADA\n";
            return false;
        }
}
void ListaEnlazadaDoble_F::modificarNodo_F(string buscar,string reemplazar)
{
    NodoLED_F *newNode = trailer->previo;
    bool encontrado=false;
    //string nodoABuscar="";
    //cout<<"Ingrese el nodo a buscar para Modificar:"<<endl;
    //cin>>nodoABuscar;
    while(newNode!=header && encontrado!=true)
    {
        if(newNode->dato==buscar)
        {
             cout<<"El nodo si existe :"<<newNode->dato<<endl;
             //cout<<"Ingrese el nuevo nodo: ";
             //cin>>newNode->dato;
             newNode->dato=reemplazar;
             cout<<" Nodo modificado\n";
             encontrado=true;
        }


        newNode=newNode->previo;

    }
     if(!encontrado)
        {
            cout<<"NO SE PUDO OBTENER EL PUNTAJE TOTAL\n";
        }
}
void ListaEnlazadaDoble_F::eliminarNodo_F(string nodoABuscar)
{
    NodoLED_F *newNode = trailer;
    NodoLED_F *anterior=new NodoLED_F();
    anterior=NULL;
    bool encontrado=false;
    //string nodoABuscar="";
    //cout<<"Ingrese el nodo a buscar para eliminar:"<<endl;
    //cin>>nodoABuscar;
    while(newNode!=header && encontrado!=true)
    {
        if(newNode->dato==nodoABuscar)
        {
             //cout<<"El nodo si existe :"<<newNode->dato<<endl;
             if(newNode==header)
             {
                header=header->previo;
                header->siguiente=NULL;
             }else if(newNode==trailer)
             {
                anterior->previo=NULL;
                trailer=anterior;
             }
             else{
                anterior->previo=newNode->previo;
                newNode->previo->siguiente=anterior;
             }
             //cout<<"\nNodo Eliminado";
             encontrado=true;
             tamanioListaFichas_--;
        }

        anterior=newNode; //Aqui podria newNode->trailer->previo
        newNode=newNode->previo;

    }
     if(!encontrado)
        {
            cout<<"LA PALABRA FORMADA NO SE PUDO ELIMINAR\n";
        }
}
int ListaEnlazadaDoble_F::tamanioListaFichas(){
    return tamanioListaFichas_;
}
int ListaEnlazadaDoble_F::tamanioStockUsuario(){
    NodoLED_F *newNode = trailer->previo;
    int contador=0;
    while(newNode!=header)
    {
        //cout<<"["<<newNode->dato<<"]"<<newNode->punteo;
        contador++;
        newNode=newNode->previo;

    }
    return contador;
}
string ListaEnlazadaDoble_F::retornarNodoPos(int pos){
    int contador=0;
    NodoLED_F *newNode=trailer->previo;
    while(newNode!=header){
            if(contador==pos){
                return newNode->dato;
            }
            contador++;
            newNode=newNode->previo;
            }
            assert(0);
}
string ListaEnlazadaDoble_F::retornarPunteo(int pos){
    int contador=0;
    NodoLED_F *newNode=trailer->previo;
    while(newNode!=header){
            if(contador==pos){
                return newNode->punteo;
            }
            contador++;
            newNode=newNode->previo;
            }
            assert(0);
}

ListaEnlazadaDoble_F::~ListaEnlazadaDoble_F()
{
    while(header->siguiente!=NULL)
    {
        removeFront_F();
        delete header;
        delete trailer;
    }
}
/*int main()
{
    ListaEnlazadaDoble_F *lista = new ListaEnlazadaDoble_F();
    lista->addFront_F("Sergio","1");
    lista->addFront_F("SERGIO","2");
    lista->addFront_F("Rivelino","3");
    lista->addFront_F("Estudiante1","4");
    lista->addFront_F("Fernando","5");
    lista->addFront_F("Estudiante2","6");
    //lista->removeFront();
    //lista->removeFront();
    //cout<<lista->getNode_F()<<endl;
    lista->printReverse_F();
    //cout<<endl;
    //lista->buscarNodo();
    cout<<endl;
    //lista->modificarNodo("Estudiante","Gato");
    //cout<<endl;
    //cout<<"Impresion en reversa"<<endl;
    //lista->printReverse();
    //lista->graphList();
    cout<<"TAMANIO "<<lista->tamanioListaFichas();
    cout<<"\n______________________________\n";
    cout<<lista->retornarNodoPos(0);
    cout<<lista->retornarPunteo(0);
    lista->eliminarNodo_F("SERGIO");
    lista->printReverse_F();
    cout<<"\nTAMANIO "<<lista->tamanioListaFichas();

    return 0;
}*/
