#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "ListaEnlazadaDobleFichas.cpp"
#include "ListaCoordenadasDobles.cpp"
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
static string palabrasH;
static string palabrasV;
static string palabrasHxy;
static string palabrasVxy;
static int puntajesH=0;
static int puntajesV=0;
ListaXYD *coorDob = new ListaXYD();
ListaXYD *coorTri = new ListaXYD();
ListaEnlazadaDoble_F *listaF=new ListaEnlazadaDoble_F();
char arrH;
char arrV;
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
int analizarPuntaje(char ficha,int coorX,int coorY){
int puntaje=0;
 switch(ficha){
    case 'A': //Que pasa si ingreso una A
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }

        break;
    case 'B':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+3;
              return puntaje;
        }

        break;
    case 'C':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+3;
              return puntaje;
        }
        break;
    case 'D':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+2;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+2;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+2;
              return puntaje;
        }
        break;
    case 'E':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'F':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+4;
              return puntaje;
        }
        break;
    case 'G':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+2;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+2;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+2;
              return puntaje;
        }
        break;
    case 'H':
      if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+4;
              return puntaje;
        }
        break;
    case 'I':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'J':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+8;
              return puntaje;
        }
        break;
    case 'K':  //Quitar si no esta permitida;/////////Va actuar como la Ñ
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+10;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'L':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'M':
      if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+3;
              return puntaje;
        }
        break;
    case 'N':
      if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'Ñ':
     if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+8;
              return puntaje;
        }
        break;
    case 'O':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        return puntaje;
        break;
    case 'P':
      if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+3;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+3;
              return puntaje;
        }
        break;
    case 'Q':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+5;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+5;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+5;
              return puntaje;
        }
        break;
    case 'R':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'S':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'T':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'U':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'V':
        if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+4;
              return puntaje;
        }
        break;
    case 'W':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+1;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+1;
              return puntaje;
        }
        break;
    case 'X':
      if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+8;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+8;
              return puntaje;
        }
        break;
    case 'Y':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+4;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+4;
              return puntaje;
        }
        break;
    case 'Z':
       if(coorDob->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+10;
              return puntaje*2;
        }
        else if(coorTri->buscarCoordenadaXYD(coorX,coorY)){
              puntaje=puntaje+10;
              return puntaje*3;
        }
        else{
              puntaje=puntaje+10;
              return puntaje;
        }
        break;
    case ' ':
        puntaje=puntaje+0;
        return puntaje;
        break;
    default:
        cout<<"\nCARACTER NO VALIDO\n";

    }
}

class splitstring : public string {
    vector<string> flds;
public:
    splitstring(char *s) : string(s) { };
    vector<string>& split(char delim, int rep=0);
};
template<typename J>
std::string ToStringMD(J val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
class NodeOrthogonal{
    public:
        int x;
        int y;
        NodeOrthogonal *next;
        NodeOrthogonal *prev;
        NodeOrthogonal *up;
        NodeOrthogonal *down;
        string letters;

};
class HorizontalList{
    public:
        HorizontalList *next;
        HorizontalList *prev;
        NodeOrthogonal *first;
        NodeOrthogonal *last;
        int num;

};

class root{
    public:
        HorizontalList *firstCol;
        HorizontalList *lastCol;
        HorizontalList *firstRow;
        HorizontalList *lastRow;
        void addMatrix(int x,int y,string date);
        void addMatrix2(int x,int y,string date);
        void existX(int x);
        void existY(int y);
        int sizeCol();
        int sizeRow();
        void graphMatrix();
        void graphDispers();
        NodeOrthogonal *search_(int x,int y);
        void edit(int,int,string);
        ///////////////////Metodos para Formar y obtener las palabras
        string retornarPalabrasHor();
        string retornarPalabrasVer();
        void obtenerPalabras();
        void separarPalabras();
        root();
        ~root();

};
root::root(){
    firstCol=NULL;
    firstRow=NULL;
    lastCol=NULL;
    lastRow=NULL;
}
void root::addMatrix2(int x,int y,string letters){
    existX(x);
    existY(y);
    addMatrix(x,y,letters);
}
void root::addMatrix(int x,int y,string letters){
    HorizontalList *auxCol=firstCol;
    HorizontalList *auxRow=firstRow;
    bool flag;
    bool flagsave=false;
    if(auxCol!=NULL){
        while(auxCol->num!=x){
            auxCol=auxCol->next;

        }
        while(auxRow->num!=y){
            auxRow=auxRow->next;
        }
        NodeOrthogonal *tempMatrix=new NodeOrthogonal(); //MatrizTemporal
        NodeOrthogonal *tempM;                           //TemporalMatriz
        tempMatrix->x=x;
        tempMatrix->y=y;
        tempMatrix->letters=letters;
        NodeOrthogonal *matrixTemp=search_(x,y);         //temporalMatrizMatriz
        if(matrixTemp!=NULL){
            matrixTemp->letters=letters;
        }
        else{
            if(auxCol->first==NULL){
                tempMatrix->next=NULL;
                auxCol->first=tempMatrix;
                auxCol->last=tempMatrix;
            }else{
                NodeOrthogonal *auxMatrix=auxCol->first;
                flag=true;
                while(flag==true){
                    if(auxMatrix!=NULL){
                        if(auxMatrix->y==y){
                            flag=false;
                            flagsave=true;
                            break;
                        }else{
                            auxMatrix=auxMatrix->next;
                        }
                    }else{
                            flag=false;
                            flagsave=false;
                        }
                }
                if(flagsave==false){
                    if(y<auxCol->first->y){
                    tempMatrix->prev=NULL;
                    tempMatrix->next=auxCol->first;
                    auxCol->first->prev=tempMatrix;
                    auxCol->first=tempMatrix;
                    }else if(y>auxCol->last->y){
                        tempMatrix->next=NULL;
                        tempMatrix->prev=auxCol->last;
                        auxCol->last->next=tempMatrix;
                        auxCol->last=tempMatrix;
                    }
                    else{
                        tempM=auxCol->first;
                        flag=true;
                        while(flag){
                            if(tempM->next!=NULL){
                                if(y<tempM->next->y){
                                        flag=false;

                                }else{
                                    tempM=tempM->next;
                                }
                            }else{
                                flag=false;
                            }
                        }
                        NodeOrthogonal *auxNode=tempM->next;
                        tempM->next=tempMatrix;
                        tempMatrix->next=auxNode;
                    }
                }
            }
            if(auxRow->first==NULL){
                tempMatrix->up=NULL;
                auxRow->first=tempMatrix;
                auxRow->last=tempMatrix;
            }else{
                NodeOrthogonal *auxMatrix=auxRow->first;
                flag=true;
                flagsave=false;
                while(flag==true){
                        if(auxMatrix!=NULL){
                        if(auxMatrix->x==x){
                            flag=false;
                            flagsave=true;
                        }else{
                            auxMatrix=auxMatrix->up;
                        }
                        }
                        else{
                            flag=false;
                            flagsave=false;
                        }
                      }
                      if(flagsave==false){
                            if(x<auxRow->first->x){
                                    tempMatrix->down=NULL;
                                    tempMatrix->up=auxRow->first;
                                    auxRow->first->down=tempMatrix;
                                    auxRow->first=tempMatrix;
                        }
                        else if(x>auxRow->last->x){
                               tempMatrix->up=NULL;
                               tempMatrix->down=auxRow->last;
                               auxRow->last->up=tempMatrix;
                               auxRow->last=tempMatrix;
                        }
                        else{
                            tempM=auxRow->first;
                            flag=true;
                            while(flag){
                                    if(tempM->up!=NULL){
                                        if(x<tempM->up->x){
                                            flag=false;
                                        }else{
                                            tempM=tempM->up;
                                        }
                                    }else{
                                        flag=false;
                                    }

                            }
                            NodeOrthogonal *auxNode=tempM->up;
                            tempM->up=tempMatrix;
                            tempMatrix->up=auxNode;
                        }

                      }
            }

        }
    }
}
void root::existX(int x){
    bool flag=true;
    bool flagsave=false;
    HorizontalList *temp=firstCol;
    if(firstCol==NULL){
            HorizontalList *head=new  HorizontalList();
            head->num=x;
            head->first=NULL;
            head->next=NULL;
            firstCol=head;
            lastCol=head;
    }else{
        while(flag==true){
            if(temp!=NULL){
                    if(temp->num==x){
                        flag=false;
                        flagsave=true;
                    }
                    else{
                        temp=temp->next;
                    }
                }else{
                    flag=false;
                    flagsave=false;
                }
        }
        if(flagsave==false){
                HorizontalList *head=new HorizontalList();
                head->num=x;
                head->first=NULL;
                if(x<firstCol->num){
                       head->next=firstCol;
                       firstCol=head;
                }else if(x>lastCol->num){
                    lastCol->next=head;
                    head->next=NULL;
                    lastCol=head;
                }
                else{
                    temp=firstCol;
                    flag=true;
                    while(flag){
                          if(temp->next!=NULL){
                             if(x<temp->next->num){
                                flag=false;

                             }else{
                                 temp=temp->next;
                             }

                          }else{
                              flag=false;
                          }
                    }
                    HorizontalList *auxX=temp->next;
                    temp->next=head;
                    head->next=auxX;
                }

        }
    }
}
void root::existY(int y){
     bool flag=true;
    bool flagsave=false;
    HorizontalList *temp=firstRow;
    if(firstRow==NULL){
            HorizontalList *head=new  HorizontalList();
            head->num=y;
            head->first=NULL;
            head->next=NULL;
            firstRow=head;
            lastRow=head;
    }else{
        while(flag==true){
            if(temp!=NULL){
                    if(temp->num==y){
                        flag=false;
                        flagsave=true;
                    }
                    else{
                        temp=temp->next;
                    }
                }else{
                    flag=false;
                    flagsave=false;
                }
        }
        if(flagsave==false){
                HorizontalList *head=new HorizontalList();
                head->num=y;
                head->first=NULL;
                if(y<firstRow->num){
                       head->next=firstRow;
                       firstRow=head;
                }else if(y>lastRow->num){
                    lastRow->next=head;
                    head->next=NULL;
                    lastRow=head;
                }
                else{
                    temp=firstRow;
                    flag=true;
                    while(flag){
                          if(temp->next!=NULL){
                             if(y<temp->next->num){
                                flag=false;

                             }else{
                                 temp=temp->next;
                             }

                          }else{
                              flag=false;
                          }
                    }
                    HorizontalList *auxY=temp->next;
                    temp->next=head;
                    head->next=auxY;
                }

        }
    }

}
NodeOrthogonal *root::search_(int x,int y){
    int found=0;
    HorizontalList *aux=firstCol;
    while(aux!=NULL){
            if(aux->num==x){
                found=1;
                break;
            }
            aux=aux->next;
        }
        if(found){
            NodeOrthogonal *aux2= aux->first;
            while(aux2!=NULL){
                    if(aux2->y==y){
                        return aux2;
                    }
                    aux2=aux2->next;

            }
        }
        return NULL;

}
void root::graphMatrix(){
    std::ofstream afile("Matriz.dot",std::ios::out);
    HorizontalList *aux2=firstCol;
    HorizontalList *aux=firstRow;
    afile << "digraph G{\n";
    afile << "node [shape = box] \n";
    afile << "raiz[label=\"HEADER\"  group=1];\n";
    if(aux != NULL){
        while(aux != NULL){
            long int point = reinterpret_cast<long int>(aux);
            afile << point << " [label=\"Y" << aux->num << "\" group = 1]; \n";
            aux = aux->next;
        }
        aux=firstRow;
        while(aux != NULL){
            long int point = reinterpret_cast<long int>(aux);
            if(aux->next != NULL){
                long int point2 = reinterpret_cast<long int>(aux->next);
                afile << point << "->" << point2 << "[dir=both];\n";
            }
             aux = aux->next;
        }
        while(aux2 != NULL){
            long int point = reinterpret_cast<long int>(aux2);
            int level = aux2->num + 2;
            afile << point << " [label=\"X" << aux2->num << "\" group = " << level << "]; \n";
            aux2 = aux2->next;
        }
        aux2=firstCol;
        while(aux2 != NULL){
            long int point = reinterpret_cast<long int>(aux2);
            if(aux2->next != NULL){
                long int point2 = reinterpret_cast<long int>(aux2->next);
                afile << point << "->" << point2 << "[dir=both];\n";

            }
             aux2 = aux2->next;
        }
//----------------------------------------------------------------------------------------------------
        aux=firstRow;
        aux2=firstCol;
        long int a = reinterpret_cast<long int>(aux);
        long int b = reinterpret_cast<long int>(aux2);
        afile << "raiz -> " << a << ";\n";
        afile << "raiz -> " << b << ";\n";
        afile << "{ rank  = same; raiz ";

        while(aux2 != NULL){
            long int a = reinterpret_cast<long int>(aux2);
            afile << a << "; ";
            aux2 = aux2->next;
        }
        afile << "}\n";
        aux2=firstCol;
        while(aux2 != NULL){
            int level = aux2->num + 2;
            NodeOrthogonal *temp = aux2->first;
            if(temp!=NULL){
                while(temp!=NULL){
                    long int point = reinterpret_cast<long int>(temp);
                    if(coorDob->buscarCoordenadaXYD(temp->x,temp->y)){
                        afile << point << " [style=filled,fillcolor=green,label= \""<<temp->letters<<"\" group = " << level << " ]; \n";
                    }
                    else if(coorTri->buscarCoordenadaXYD(temp->x,temp->y)){
                        afile << point << " [style=filled,fillcolor=red,label= \""<<temp->letters<<"\" group = " << level << " ]; \n";
                    }
                    else{
                        afile << point << " [style=filled,fillcolor=seashell2,label= \""<<temp->letters<<"\" group = " << level << " ]; \n";
                    }

                    temp = temp->next;
                }
            }
            aux2 = aux2->next;
        }
         aux=firstRow;
        while(aux != NULL){
            long int fi = reinterpret_cast<long int>(aux);
            NodeOrthogonal *temp=aux->first;
            if(temp != NULL){
                long int nod = reinterpret_cast<long int>(temp);
                afile << fi << "->" << nod << ";\n";
                while(temp->up != NULL){
                    nod= reinterpret_cast<long int>(temp);
                    long int nextNode = reinterpret_cast<long int>(temp->up);
                    afile << nod << "->" << nextNode << "[dir=both];\n";
                    //afile << nextNode << "->" << nod << ";\n";
                    temp = temp->up;
                }
                afile << "{ rank = same; " << fi << "; ";
                temp = aux->first;
                while(temp!=NULL){
                    long int rankFi = reinterpret_cast<long int>(temp);
                    afile << rankFi << "; ";
                    temp = temp->up;
                }
                afile << "}\n";
            }
            aux = aux->next;
        }

/*------------------------------------------------------------------------------------*/
        aux2=firstCol;
        while(aux2 != NULL){
            long int col = reinterpret_cast<long int>(aux2);
            NodeOrthogonal *temp=aux2->first;
            if(temp != NULL){
                long int nod = reinterpret_cast<long int>(temp);
                afile << col << "->" << nod << "[dir=both];\n";
                while(temp->next != NULL){
                    nod= reinterpret_cast<long int>(temp);
                    long int nextNode = reinterpret_cast<long int>(temp->next);
                    afile << nod << "->" << nextNode << "[dir=both];\n";
                    temp=temp->next;
                }
            }
            aux2=aux2->next;
        }
    }
    afile<<"}\n";
    afile.close();
    system("dot -Tpng Matriz.dot -o Matriz.png");
    system("start Matriz.png");

}
void root::edit(int x,int y,string l){
    HorizontalList *temp=firstCol;
    NodeOrthogonal *temp2=search_(x,y);
    if(temp2!=NULL){
            temp2->letters=l;
    }else{

    }
}
void root::obtenerPalabras(){
    HorizontalList *aux2=firstCol;
    HorizontalList *aux=firstRow;
    if(aux != NULL){
        while(aux != NULL){
            aux = aux->next;
        }
        aux=firstRow;
        while(aux != NULL){
            if(aux->next != NULL){
            }
             aux = aux->next;
        }
        while(aux2 != NULL){
            aux2 = aux2->next;
        }
        aux2=firstCol;
        while(aux2 != NULL){
            if(aux2->next != NULL){

            }
             aux2 = aux2->next;
        }
//----------------------------------------------------------------------------------------------------
        aux=firstRow;
        aux2=firstCol;
        while(aux2 != NULL){
            aux2 = aux2->next;
        }
        aux2=firstCol;
        while(aux2 != NULL){
            int level = aux2->num + 2;
            NodeOrthogonal *temp = aux2->first;
            if(temp!=NULL){
                while(temp!=NULL){
                    arrV=temp->letters[0]; //letters[0] es un caracter
                    puntajesV=puntajesV+analizarPuntaje(arrV,temp->x,temp->y); //Paso el caracter a un metodo que me devuelve el valor(punteo) de esa letra
                    if(temp->letters==" "){
                        palabrasV=palabrasV+temp->letters+","+ToStringMD(puntajesV)+"\n";
                    }
                    else{
                        palabrasV=palabrasV+temp->letters;
                    }
                    //Aqui voy concatenando  la palabra vertical
                    //cout<<temp->letters<<"->"<<temp->x<<endl;
                    //cout<<temp->letters<<"->"<<temp->y<<endl;
                    if(temp->next==NULL){
                    //cout<<temp->letters<<"->"<<temp->x<<endl;
                    //cout<<temp->letters<<"->"<<temp->y<<endl;
                    //palabrasV=palabrasV+"\n";
                    //palabrasV=palabrasV+"Puntajes: "+ToStringMD(puntajesV)+"\n";
                    palabrasV=palabrasV+","+ToStringMD(puntajesV)+"\n"; //Letra completa y su correspondiente puntaje
                    puntajesV=0;
                    }
                    temp = temp->next;
                }
            }
            aux2 = aux2->next;
        }
         aux=firstRow;
        while(aux != NULL){
            NodeOrthogonal *temp=aux->first;
            if(temp != NULL){
                while(temp->up != NULL){
                    temp = temp->up;
                }
//
                temp = aux->first;
                while(temp!=NULL){

                    arrH=temp->letters[0];
                    puntajesH=puntajesH+analizarPuntaje(arrH,temp->x,temp->y);
                    palabrasHxy=palabrasHxy+temp->letters+ToStringMD(temp->x)+ToStringMD(temp->y);
                    //palabrasH=palabrasH+temp->letters;
                    if(temp->letters==" "){
                        palabrasH=palabrasH+temp->letters+","+ToStringMD(puntajesH)+"\n";
                    }else{
                        palabrasH=palabrasH+temp->letters;
                    }
                    //cout<<"Puntaje:->"+ToStringMD(puntajes)+"->";
                    //cout<<temp->letters<<"->"<<temp->x<<endl;
                    if(temp->up==NULL){
                    //cout<<temp->letters<<"->"<<temp->x<<endl;
                    //cout<<temp->y<<endl;
                    //palabrasH=palabrasH+"Puntajes: "+ToStringMD(puntajesH)+"\n";
                    palabrasH=palabrasH+","+ToStringMD(puntajesH)+"\n";
                    palabrasHxy=palabrasHxy+"\n";
                    puntajesH=0;

                    }
                    temp = temp->up;
                }
            }
            aux = aux->next;
        }

/*------------------------------------------------------------------------------------*/
        aux2=firstCol;
        while(aux2 != NULL){
            NodeOrthogonal *temp=aux2->first;
            if(temp != NULL){
                while(temp->next != NULL){
                    temp=temp->next;
                }
            }
            aux2=aux2->next;
        }
    }


}
string root::retornarPalabrasHor(){
    return palabrasH;
}
string root::retornarPalabrasVer(){
    return palabrasV;
}
vector<string>& splitstring::split(char delim, int rep) {
    if (!flds.empty()) flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

void root::separarPalabras(){
    int tamanio=0;
    int n=retornarPalabrasVer().size(); //Variable que almacena la longitud de la cadena
    char arr[n+1]; //Creo un array char
    strcpy(arr,retornarPalabrasVer().c_str());
    splitstring s(arr); //Lo paso de parametro al metodo split
    vector<string> palabrasVer=s.split('\n');  //Me separa el texto en saltos de linea
    for(int i=0;i<palabrasVer.size();i++){
        //string palabraMayuscula=palabrasVer[i];
        //transform(palabraMayuscula.begin(),palabraMayuscula.end(),palabraMayuscula.begin(),::toupper);
        //cout<<"Palabras Verticales "<<palabraMayuscula<<endl;
        //listaF->addFront_F(palabraMayuscula);
        int n=palabrasVer[i].length();
        char palSep[n+1];
        strcpy(palSep,palabrasVer[i].c_str());
        /////SEGUNDO SPLIT/////////
        splitstring s2(palSep);
        vector<string> palabrasVer_2=s2.split(',');
        for(int j=0;j<palabrasVer_2.size()/2;j++){
            string palabraMayuscula=palabrasVer_2[0]; //Palabra formada
            string punteoVer=palabrasVer_2[1];//Punteo de la palabra
            transform(palabraMayuscula.begin(),palabraMayuscula.end(),palabraMayuscula.begin(),::toupper);
            if(palabraMayuscula==" " || palabraMayuscula.length()<=1){

            } else if(palabraMayuscula.length()==1){
            }
            else{
                 listaF->addFront_F(removeSpaces(palabraMayuscula),punteoVer);
            }

        }


    }

    int n2=retornarPalabrasHor().size(); //Variable que almacena la longitud de la cadena
    char arr2[n2+1]; //Creo un array char
    strcpy(arr2,retornarPalabrasHor().c_str());
    splitstring s2(arr2); //Lo paso de parametro al metodo split
    vector<string> palabrasHor=s2.split('\n');
    for(int i=0;i<palabrasHor.size();i++){
         //string palabraMayuscula=palabrasHor[i];
         //transform(palabraMayuscula.begin(),palabraMayuscula.end(),palabraMayuscula.begin(),::toupper);
         //cout<<"Palabras Horizontales   "<<palabraMayuscula<<endl;
         //listaF->addFront_F(palabraMayuscula);
        int n=palabrasHor[i].length();
        char palSep[n+1];
        strcpy(palSep,palabrasHor[i].c_str());
        /////SEGUNDO SPLIT/////////
        splitstring s2(palSep);
        vector<string> palabrasHor_2=s2.split(',');
        for(int j=0;j<palabrasHor_2.size()/2;j++){
            string palabraMayuscula=palabrasHor_2[0];
            string punteoHor=palabrasHor_2[1];
            transform(palabraMayuscula.begin(),palabraMayuscula.end(),palabraMayuscula.begin(),::toupper);
            if(palabraMayuscula==" " || palabraMayuscula.length()<=1){

            }else if(palabraMayuscula.length()==1){
            }
            else{
                listaF->addFront_F(removeSpaces(palabraMayuscula),punteoHor);//almaceno palabra formada y punteo a la lista de fichas
            }

        }
        ///////Tercer split por espacios



    }
}
/*int main(){

    root *r=new root();
    r->addMatrix2(0,0,"S");
    r->addMatrix2(0,1,"E");
    r->addMatrix2(0,2,"R");
    r->addMatrix2(0,3,"G");
    r->addMatrix2(0,4,"I");
    r->addMatrix2(0,5,"O");
    r->addMatrix2(1,0,"K");
    r->addMatrix2(1,1,"L");
    r->addMatrix2(1,2,"M");
    r->addMatrix2(1,3,"L");
    r->addMatrix2(1,4,"A");
    r->addMatrix2(1,5,"O");
    r->addMatrix2(1,5,"O");
    r->addMatrix2(3,0,"H");
    r->addMatrix2(3,2,"G");
    r->addMatrix2(3,3,"A");
    r->addMatrix2(3,4,"T");
    r->addMatrix2(3,5,"O");
    r->addMatrix2(6,10,"A");
    r->addMatrix2(3,1," ");
    r->addMatrix2(7,7," ");
    r->addMatrix2(6,1,"Y");
    r->addMatrix2(7,1,"O");
    r->graphMatrix();
    //r->edit(0,2," ");
    //r->graphMatrix();
    //r->addMatrix2(0,2,"Y");
    //r->graphMatrix();
    r->obtenerPalabras();
    cout<<"Palabras Verticales\n";
    cout<<r->retornarPalabrasVer()<<endl;
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

















