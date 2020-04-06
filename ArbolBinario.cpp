#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;
static int correlativo=1;
string dot1="";
string dot2="";
string dot3="";
template<typename U>
std::string ToStringA(U val)
{
    std::stringstream stream;
    stream<<val;
    return stream.str();
}
class NodoBinario{
    public:
    string dato;
    NodoBinario *izquierdo;
    NodoBinario *derecho;
    int id;
    NodoBinario(string dato_){
        dato=dato_;
        izquierdo=NULL;
        derecho=NULL;
        id=correlativo++;
}
void insertar(string valor){
    if(valor.compare(dato)<0){  //Si el valor a insertar es menor que el nodo actual,entonces deberia insertarse a la izquierda de este
        if(izquierdo==NULL){
            izquierdo=new NodoBinario(valor);
        }
        else{
            izquierdo->insertar(valor);
        }
    }
    else if(valor.compare(dato)>0){
        if(derecho==NULL){
            derecho=new NodoBinario(valor);
        }
        else{
            derecho->insertar(valor);
        }

    }
    else{
        cout<<"DATO YA INGRESADO, INGRESAR OTRO DATO"<<endl;
    }
}
void graficar(){
    ofstream archivo;
    archivo.open("Arbol.dot",ios::out);
    if(archivo.fail()){

    }else{
        archivo<<getCodigoGraphviz();
        archivo.close();
        system("dot arbol.dot -o arbol.png -Tpng");
        system("start arbol.png");
    }
}
string getCodigoGraphviz(){
    return ToStringA("digraph grafica{\n")+
           ToStringA("rankdir=TB;\n")+
           ToStringA("node[shape = record,style=filled,fillcolor=seashell2];\n")+
           getCodigoInterno()+"\n}";
}
string getCodigoInterno(){
    string etiqueta;
    if(izquierdo==NULL && derecho==NULL){
        etiqueta="nodo"+ToStringA(id)+"[label="+"\""+dato+"\""+"];\n";
    }
    else{
        etiqueta="nodo"+ToStringA(id)+"[label="+"\"<C0>|"+dato+"|<C1>"+"\""+"];\n";
    }
    if(izquierdo!=NULL){
        etiqueta=etiqueta+izquierdo->getCodigoInterno()+"nodo"+ToStringA(id)+":C0->nodo"+ToStringA(izquierdo->id)+"\n";
    }
    if(derecho!=NULL){
        etiqueta=etiqueta+derecho->getCodigoInterno()+"nodo"+ToStringA(id)+":C1->nodo"+ToStringA(derecho->id)+"\n";
    }
    return etiqueta;
}

};
class ArbolBB{
    public:
    NodoBinario *raiz;
    ArbolBB(){
        raiz=NULL;
    }
    void insertar(string usuario)
    {

        if(raiz==NULL){
            raiz=new NodoBinario(usuario);
        }
        else{
            raiz->insertar(usuario);
        }
    }
    void graficar(){
        raiz->graficar();
    }
    private:
    void Mostrar_inorden(NodoBinario *nodo){
        if(nodo==NULL){
            return;
        }
        Mostrar_inorden(nodo->izquierdo);

        cout<<nodo->dato<<endl;
        Mostrar_inorden(nodo->derecho);

    }

    void inorden(NodoBinario *nodo){
        if(nodo==NULL){
            return;
        }
        inorden(nodo->izquierdo);
        dot1=dot1+nodo->dato+"->";
        cout<<nodo->dato<<",";
        inorden(nodo->derecho);

    }
    void preOrden(NodoBinario *nodo){
        if(nodo==NULL){
            return;
        }
        dot2=dot2+nodo->dato+"->";
        cout<<nodo->dato<<",";
        preOrden(nodo->izquierdo);
        preOrden(nodo->derecho);
    }
    void postOrden(NodoBinario *nodo){
        if(nodo==NULL){
            return;
        }
        postOrden(nodo->izquierdo);
        postOrden(nodo->derecho);
        cout<<nodo->dato<<",";
        dot3=dot3+nodo->dato+"->";
    }
    public:
    void RecorridoInorden(){
        cout<<"RECORRIDO INORDEN DEL ARBOL BINARIO DE BUSQUEDA"<<endl;
        inorden(raiz);
        cout<<""<<endl;
    }
    void RecorridoPreOrden(){
        cout<<"RECORRIDO PREORDEN DEL ARBOL BINARIO DE BUSQUEDA"<<endl;
        preOrden(raiz);
        cout<<""<<endl;
    }
    void RecorridoPostOrden(){
        cout<<"RECORRIDO POSTORDEN DEL ARBOL BINARIO DE BUSQUEDA"<<endl;
        postOrden(raiz);
        cout<<""<<endl;
    }
    void mostrarInOrden(){
        //cout<<"RECORRIDO INORDEN DEL ARBOL BINARIO DE BUSQUEDA"<<endl;
        Mostrar_inorden(raiz);
        cout<<""<<endl;
    }
    ///////////////////////////////////GRAFICAS DE LOS RECORRIDOS//////////////////////////////////
    void graficaPreOrden(){
        ofstream archivo;
        archivo.open("preorden.dot",ios::out);
        if(archivo.fail()){

        }else{
            archivo<<"digraph{\n";
            archivo<<"rankdir=LR\n";
            archivo<<"subgraph cluster_0{\n";
            archivo<<"label=RECORRIDO_PREORDEN;\n";
            archivo<<dot2<<"NULL;"<<endl;
            archivo<<"}"<<"\n"<<"}";
            archivo.close();
            system("dot preorden.dot -o preorden.png -Tpng");
            system("start preorden.png");
        }
    }
     void graficaPostOrden(){
        ofstream archivo;
        archivo.open("postorden.dot",ios::out);
        if(archivo.fail()){

        }else{
            archivo<<"digraph{\n";
            archivo<<"rankdir=LR\n";
            archivo<<"subgraph cluster_0{\n";
            archivo<<"label=RECORRIDO_POSTORDEN;\n";
            archivo<<dot3<<"NULL;"<<endl;
            archivo<<"}"<<"\n"<<"}";
            archivo.close();
            system("dot postorden.dot -o postorden.png -Tpng");
            system("start postorden.png");
        }
    }
     void graficaInOrden(){
        ofstream archivo;
        archivo.open("inorden.dot",ios::out);
        if(archivo.fail()){

        }else{
            archivo<<"digraph{\n";
            archivo<<"rankdir=LR\n";
            archivo<<"subgraph cluster_0{\n";
            archivo<<"label=RECORRIDO_INORDEN;\n";
            archivo<<dot1<<"NULL;"<<endl;
            archivo<<"}"<<"\n"<<"}";
            archivo.close();
            system("dot inorden.dot -o inorden.png -Tpng");
            system("start inorden.png");
        }
    }


};


/*int main()
{
    ArbolBB *arbol=new ArbolBB();
    arbol->insertar("10");
    arbol->insertar("5");
    arbol->insertar("14");
    arbol->insertar("7");
    arbol->insertar("12");

    arbol->graficar();
    arbol->RecorridoInorden();
    cout<<"";
    arbol->RecorridoPreOrden();
    cout<<"";
    arbol->RecorridoPostOrden();
    cout<<"DOT"<<endl;
    cout<<dot1<<endl;
    cout<<dot2<<endl;
    cout<<dot3<<endl;
    arbol->graficaInOrden();
    arbol->graficaPreOrden();
    arbol->graficaPostOrden();
    return 0;
}*/
