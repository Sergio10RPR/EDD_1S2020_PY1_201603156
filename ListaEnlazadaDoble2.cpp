#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<assert.h>
using namespace std;
template<typename L>
std::string ToStringList(L val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
class NodoLED
{
private:
    string dato;
    NodoLED *previo;
    NodoLED *siguiente;

    friend class ListaEnlazadaDoble;
};
class ListaEnlazadaDoble
{
public:
    ListaEnlazadaDoble(); //Constructor
    ~ListaEnlazadaDoble();//Destructor
    string getFront() const;
    string getBack()  const;
    void addFront(string);
    void addBack(string);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();
    void graphList();
    bool buscarNodo(string);
    void modificarNodo(string,string);
    void eliminarNodo(string);
    int tamanioStockUsuario();
    string retornarFichaPos(int);
    string getNode();
private:
    NodoLED *header;
    NodoLED *trailer;

};
ListaEnlazadaDoble::ListaEnlazadaDoble()
{
    header=new NodoLED();
    trailer=new NodoLED();
    header->siguiente=trailer;
    trailer->previo=header;
    header->previo=NULL;
    trailer->siguiente=NULL;
}
string ListaEnlazadaDoble::getFront()const
{
    return ListaEnlazadaDoble::header->siguiente->dato;
}
string ListaEnlazadaDoble::getBack()const
{
    return trailer->previo->dato;
}
string ListaEnlazadaDoble::getNode(){
    string nodo="";
    NodoLED *newNode = header->siguiente->siguiente;//Guarda el nodo siguiente al head, head que se va a eliminar
    //cout<<"TEORICAMENTE EL NODO ELIMINADO :"<<newNode->previo->dato<<endl;
    nodo=newNode->previo->dato;
    delete header->siguiente;
    header->siguiente=newNode;//Apunta al nodo que se habia guardado
    newNode->previo=header;
    return nodo;
}
void ListaEnlazadaDoble::addFront(string dato_)
{
    NodoLED *newNode = new NodoLED;
    newNode->dato=dato_;
    newNode->previo=header;
    newNode->siguiente=header->siguiente; //Apuntaria al head que este actualmente

    header->siguiente->previo=newNode;
    header->siguiente=newNode;
}
void ListaEnlazadaDoble::addBack(string dato_)
{
    NodoLED *newNode = new NodoLED();
    newNode->dato=dato_;
    newNode->previo=trailer->previo;
    newNode->siguiente=trailer;

    trailer->previo->siguiente=newNode;
    trailer->previo=newNode;
}
void ListaEnlazadaDoble::removeFront()
{
    NodoLED *newNode = header->siguiente->siguiente;//Guarda el nodo siguiente al head, head que se va a eliminar
    //cout<<"TEORICAMENTE EL NODO ELIMINADO :"<<newNode->previo->dato<<endl;
    delete header->siguiente;
    header->siguiente=newNode;//Apunta al nodo que se habia guardado
    newNode->previo=header;
}
void ListaEnlazadaDoble::removeBack()
{
    NodoLED *newNode = trailer->previo->previo;
    delete trailer->siguiente;
    trailer->previo->siguiente=trailer;
}
void ListaEnlazadaDoble::printReverse()
{

    NodoLED *newNode = trailer->previo;
    while(newNode!=header)
    {
        cout<<"["<<newNode->dato<<"]";

        newNode=newNode->previo;

    }
}
void ListaEnlazadaDoble::printForward()
{
    NodoLED *newNode = header->siguiente;
    while(newNode != trailer)
    {
        cout<<newNode->dato<<"->";
        newNode=newNode->siguiente;
    }
}
bool ListaEnlazadaDoble::buscarNodo(string ficha)
{
    NodoLED *newNode = trailer->previo;
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
void ListaEnlazadaDoble::modificarNodo(string buscar,string reemplazar)
{
    NodoLED *newNode = trailer->previo;
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
            cout<<"Nodo no encontrado\n";
        }
}
void ListaEnlazadaDoble::eliminarNodo(string nodoABuscar)
{
    NodoLED *newNode = trailer;
    NodoLED *anterior=new NodoLED();
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
        }

        anterior=newNode; //Aqui podria newNode->trailer->previo
        newNode=newNode->previo;

    }
     if(!encontrado)
        {
            cout<<"Nodo no encontrado\n";
        }
}
void ListaEnlazadaDoble::graphList()
{
    NodoLED *nodo = trailer->previo;
    NodoLED *nodo2=header->siguiente;
    string dot="";
    string edge1="";
    string edge2="";
    int contador=0;
    ofstream archivo;
    archivo.open("ListaDobleEnlazada.dot",ios::out);
    if(archivo.fail())
    {
     cout<<"El archivo no se pudo crear"<<endl;
    }
    while(nodo!=header)
    {
       //El dot me declata los nodos a utilizar
       dot=dot+ToStringList(nodo->dato)+ToStringList(contador)+"[label="+"\""+ToStringList(nodo->dato)+"\""+",style=filled,fillcolor=bisque1];"+"\n";
       edge1=edge1+ToStringList(nodo->dato)+ToStringList(contador)+"->"+"\n";
       //dot=dot+ToString(nodo->dato)+"[label="+"\""+ToString(nodo->dato)+"\""+",style=filled,fillcolor=bisque1];"+"\n";
       //edge1=edge1+ToString(nodo->dato)+"->"+"\n";
       contador++;
       nodo=nodo->previo;
        if(nodo==header->siguiente)
        {
        dot=dot+ToStringList(nodo->dato)+ToStringList(contador)+"[label="+"\""+ToStringList(nodo->dato)+"\""+",style=filled,fillcolor=bisque1];"+"\n";
        edge1=edge1+ToStringList(nodo->dato)+ToStringList(contador)+"\n";
        nodo=nodo->previo;
        }

    }
    while(nodo2!=trailer)
    {
        //edge2=edge2+ToString(nodo2->dato)+"_"+ToString(contador2)+"->"+"\n";
        edge2=edge2+ToStringList(nodo2->dato)+ToStringList(contador)+"->"+"\n";
        contador--;
        nodo2=nodo2->siguiente;
        if(nodo2==trailer->previo)
        {
        edge2=edge2+ToStringList(nodo2->dato)+ToStringList(contador)+"\n";
        nodo2=nodo2->siguiente;
        }

    }
    //Escribiendo el archivo
    archivo<<"digraph G{\n";
    archivo<<"rankdir=LR;\n";
    archivo<<"node[shape=component,fontcolor=brown4,width=1.5,margin=0.2];\n";
    archivo<<dot;
    archivo<<edge1<<endl;
    archivo<<edge2;
    archivo<<"}\n";
    archivo.close();
    system("dot ListaDobleEnlazada.dot -o ListaDobleEnlazada.png -Tpng");
    system("start ListaDobleEnlazada.png");

}
ListaEnlazadaDoble::~ListaEnlazadaDoble()
{
    while(header->siguiente!=NULL)
    {
        removeFront();
        delete header;
        delete trailer;
    }
}
int ListaEnlazadaDoble::tamanioStockUsuario(){
    NodoLED *newNode = trailer->previo;
    int contador=0;
    while(newNode!=header)
    {
        //cout<<"["<<newNode->dato<<"]"<<newNode->punteo;
        contador++;
        newNode=newNode->previo;

    }
    return contador;
}
string ListaEnlazadaDoble::retornarFichaPos(int pos){
    int contador=0;
    NodoLED *newNode=trailer->previo;
    while(newNode!=header){
            if(contador==pos){
                return newNode->dato;
            }
            contador++;
            newNode=newNode->previo;
            }
            assert(0);
}
/*int main()
{
    ListaEnlazadaDoble *lista = new ListaEnlazadaDoble();
    lista->addFront("Sergio");
    lista->addFront("SERGIO");
    lista->addFront("Rivelino");
    lista->addFront("Estudiante1");
    lista->addFront("Fernando");
    lista->addFront("Estudiante2");
    //lista->removeFront();
    //lista->removeFront();
    //cout<<lista->getNode()<<endl;
    lista->printReverse();
    //cout<<endl;
    //lista->buscarNodo();
    cout<<endl;
    //lista->modificarNodo("Estudiante","Gato");
    //cout<<endl;
    //cout<<"Impresion en reversa"<<endl;
    //lista->printReverse();
    lista->graphList();
    return 0;
}*/
