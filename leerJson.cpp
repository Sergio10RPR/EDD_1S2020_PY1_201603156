#include<iostream>
#include "json.hpp"
#include<fstream>
#include<typeinfo>
#include "ListaCircularDoble.cpp"  //Guarda las palabras en el diccionario
#include "MatrizDispersa.cpp"
#include "colorwin.hpp"
static root *r=new root();
using namespace std;
using json=nlohmann::json;
using namespace colorwin;
void LeerJson(string nombre){
    std::ifstream i(nombre);
    json archivo;
    i>>archivo; //Lee linea a linea el archivo json

    //cout<<archivo["casillas"]<<endl;
    /*for(int p=0;p<archivo["casillas"].size()/2;p++){
        cout<<archivo["casillas"]["doble"]<<endl;
        cout<<archivo["casillas"]["triples"]<<endl;
    }*/
    json dobles=(json)archivo["casillas"]["doble"];
    json triples=(json)archivo["casillas"]["triples"];
    json diccionario=(json)archivo["diccionario"];
    //cout<<archivo["casillas"]["doble"]<<endl;
    //cout<<archivo["casillas"]["triples"]<<endl;
    //cout<<archivo["diccionario"]<<endl;
    //cout<<dobles<<endl;
    //cout<<"POSICIONES DOBLES"<<endl;
     for(int i=0;i<dobles.size();i++){
        //cout<<"POSICION X :"<<dobles[i].at("x")<<" "<<"POSICION Y :"<<dobles[i].at("y")<<endl;
        //r->addMatrix2(int(dobles[i].at("x")),int(dobles[i].at("y")),"");
         coorDob->agregarAlInicioXYD(int(dobles[i].at("x")),int(dobles[i].at("y")));
     }
     //cout<<"POSICIONES TRIPLES"<<endl;
     for(int i=0;i<triples.size();i++){
        //cout<<"POSICION X :"<<triples[i].at("x")<<" "<<"POSICION Y :"<<triples[i].at("y")<<endl;
        //r->addMatrix2(int(triples[i].at("x")),int(triples[i].at("y")),"");
        coorTri->agregarAlInicioXYD(int(triples[i].at("x")),int(triples[i].at("y")));

     }
     //cout<<"DICCIONARIOS"<<endl;
     for(int i=0;i<diccionario.size();i++){
        //cout<<"PALABRA :"<<diccionario[i].at("palabra")<<endl;
        string mayusculas=ToStringC(diccionario[i].at("palabra"));
        transform(mayusculas.begin(),mayusculas.end(),mayusculas.begin(),::toupper);
        //cout<<mayusculas<<endl;
        insertarNodo(mayusculas); //Almaceno las palabras del diccionario en la lista circular doble
     }
     cout<<color(yellow)<<"\nDIMENSION DEL TABLERO: "<<archivo["dimension"]<<endl;;

     int dimension=int(archivo["dimension"]);
     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            r->addMatrix2(i,j," ");
        }
     }
        r->graphMatrix();
        //graficar();
        //imprimirAdelante();
        //r->graphMatrix();


    /*for(int j=0;j<archivo.at("triples").size();j++){
        cout<<"POSICION X :"<<archivo.at("triples")[j].at("x")<<endl;
        cout<<"POSICION Y :"<<archivo.at("triples")[j].at("y")<<endl;
    }*/

    /*for(int k=0;k<archivo.at("diccionario").size();k++){
        cout<<"POSICION X :"<<archivo.at("diccionario")[k].at("palabra")<<endl;
    }*/
}

/*int main(){

    LeerJson("entrada.json");
    imprimirAdelante();
    return 0;
}*/

/*int main(){
    LeerJson("entrada.json");
    cout<<endl;
    cout<<"COORDENADAS DOBLES:\n";
    coorDob->mostrarListaXYD();
    cout<<"COORDENADAS TRIPLES:\n";
    coorTri->mostrarListaXYD();
    r->addMatrix2(0,3,"G");
    r->addMatrix2(0,4,"I");
    r->addMatrix2(0,5,"O");
    r->addMatrix2(1,0,"K");
    r->addMatrix2(1,1,"L");
    r->addMatrix2(1,2,"M");
    r->addMatrix2(0,0,"S");
    r->addMatrix2(10,15,"S");
    r->addMatrix2(0,1,"E");
    r->addMatrix2(6,10,"A");
    r->graphMatrix();
    r->obtenerPalabras();
    cout<<"Palabras Verticales\n";
    cout<<r->retornarPalabrasVer().size();
    cout<<endl;
    cout<<"Palabras Horizontales\n";
    cout<<r->retornarPalabrasHor()<<endl;
    cout<<"________________________________\n";
    r->separarPalabras();
    cout<<"TODAS LAS PALABRAS DE LA MATRIZ EN LA LISTA"<<endl;
    listaF->printReverse_F();
    cout<<"\nLetras Horizontales y sus coordenadas\n";
    cout<<palabrasHxy<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<palabrasH;
    cout<<endl;
    cout<<palabrasV;
    return 0;

}*/









