#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;
int tamanio=0;
template<typename T>
std::string ToString(T val)
{
    std::stringstream stream;
    stream<<val;
    return stream.str();
}
template<class T>
class ColaGenerica
{
public:
    class NodoCola
    {
    public:
        NodoCola* siguiente;
        T elemento;
        NodoCola(T x)
        {
            elemento=x;
            siguiente = NULL;

        }
        };
    NodoCola* frente;
    NodoCola* final_;
    public:
    ColaGenerica()
    {
    frente=final_=NULL;
    }
    //Prototipos de funcion
    void insertar(T elemento);
    T quitar();
    void borrarCola();
    T frenteCola();
    bool colaVacia();
    void recorrerCola();
    void graficarCola();
    int tamanioCola();
    int  colaSize();
    void buscarElemento(string);
    ~ColaGenerica()
    {
        borrarCola();
    }

};
//Implementacion de las funciones declaradas
template<class T>
void ColaGenerica<T>::insertar(T elemento)
{
    NodoCola* nuevo;
    nuevo= new NodoCola(elemento);
    if(colaVacia())
    {
        frente=nuevo;
        tamanio++;
    }
    else
        {
            final_->siguiente=nuevo;
            tamanio++;
        }
        final_=nuevo;
}
template<class T>
T ColaGenerica<T>::quitar()
{
    if(colaVacia())
        throw "Cola Vacia, no se puede extraer";
    T aux=frente->elemento;
    NodoCola* a=frente;
    frente=frente->siguiente;
    delete a;
    tamanio--;
    return aux;
}
template<class T>
T ColaGenerica<T>::frenteCola()
{
    if(colaVacia())
    {
        throw "Cola Vacia";

    }
    return frente->elemento;
}
template<class T>
void ColaGenerica<T>::borrarCola()
{
    for(;frente!=NULL;)
    {
        NodoCola* a;
        a=frente;
        frente=frente->siguiente;
        delete a;
    }
    final_=NULL;
}
template<class T>
bool ColaGenerica<T>::colaVacia()
{
    return frente==NULL;
}
template<class T>
void ColaGenerica<T>::recorrerCola()
{
    NodoCola *aux=frente;
    while(aux!=NULL)
    {
        cout<<aux->elemento<<"->";
        aux=aux->siguiente;
    }
}

template<class T>
void ColaGenerica<T>::graficarCola()
{
    string dot="";
    string edge="";
    ofstream archivo;
    archivo.open("ColaGenerica.dot",ios::out);
    string sintaxis="<table border="+ToString("\"")+ToString("1")+ToString("\"")+" "+"cellborder="+ToString("\"")+ToString("1")+
    ToString("\"")+" "+"cellspacing="+ToString("\"")+ToString("0")+ToString("\"")+ToString(">");
    if(archivo.fail())
    {
        cout<<"EL ARCHIVO NO SE PUDO CREAR"<<endl;
    }
    else
        {
        NodoCola *aux=frente;
        archivo<<"digraph G{\n";
        archivo<<"node[shape=plaintext]";
        archivo<<"some_node [\n";
        archivo<<"label=<\n";
        archivo<<sintaxis<<endl;
        while(aux!=NULL)
        {
        archivo<<ToString("<tr><td bgcolor=")+"\""+"lightblue"+"\""+" "+"width="+"\""+"75"+"\""+
        " "+"height="+"\""+"50"+"\""+ToString(">")+ToString(aux->elemento)+ToString("</td></tr>")<<endl;
        aux=aux->siguiente;
        }
        archivo<<"</table>>\n";
        archivo<<"];\n";
        archivo<<"}\n";
        archivo.close();
        system("dot ColaGenerica.dot -o ColaGenerica.png -Tpng");
        system("start ColaGenerica.png");
        }
}
template<class T>
int ColaGenerica<T>::colaSize(){
    return tamanio;

}
template<class T>
int ColaGenerica<T>::tamanioCola(){
    int tamanio_=0;
    NodoCola *aux=frente;
    while(aux!=NULL)
    {
        tamanio_++;
        aux=aux->siguiente;
    }
    return tamanio_;

}
template<class T>
void ColaGenerica<T>::buscarElemento(string elemento){
    NodoCola *aux=frente;
    bool encontrado=false;
    while(aux!=NULL && encontrado!=true)
    {
        if(aux->elemento==elemento){

            encontrado=true;
            cout<<"\nEL ELEMENTO SI SE ENCUENTRA";
            //quitar();

        }

        //cout<<aux->elemento<<"->";
        aux=aux->siguiente;

    }
      if(!encontrado){
            cout<<"\nEl ELEMENTO NO SE ENCUENTRA \n";
        }
}
/*int main()
{
    ColaGenerica<string> cola; //Instancia 1
    ColaGenerica<string> cola2;//Instancia 2
    cola.insertar("sergio");
    cola.insertar("rivelino");
    cola.insertar("perez");
    cola.insertar("rivera");
    cola.insertar("Dios es amor");
    cola.insertar("gelina");
    cola.buscarElemento("rivelino");
    cola.recorrerCola();
    cout<<endl;
    cout<<"TAMANIO COLA:"<<cola.colaSize();
    cout<<"Frente de la cola :";
    cout<<cola.frenteCola();
    cout<<"\nElementos en la cola\n";
    cola.recorrerCola();
    cola.quitar();
    cout<<"\nTAMANIO COLA:"<<cola.colaSize();
    cout<<endl;
    cola2.insertar("1");
    cola2.insertar("2");
    cola2.insertar("3");
    cola2.insertar("4");
    cola2.insertar("5");
    cola2.recorrerCola();
    cout<<endl;
    cout<<cola2.tamanioCola();
    //cola.graficarCola();
    return 0;
}*/

