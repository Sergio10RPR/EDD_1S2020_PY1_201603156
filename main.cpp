#include<iostream>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include<string>
#include "ArbolBinario.cpp"
#include "leerJson.cpp"
#include "ColaGenerica.cpp"
#include "ListaEnlazadaDoble2.cpp" //Almacena las fichas de cada usuario
#include "ListaPuntajesUsuario.cpp"
#include "colorwin.hpp"
ArbolBB *arbol=new ArbolBB();  //Instancia arbol
ColaGenerica<string>  cola;
ColaGenerica<string>  cola2;
ListaEnlazadaDoble static *listaFichas=new ListaEnlazadaDoble(); //Instancia del archivo LED2.cpp
ListaEnlazadaDoble static *listaFichas2=new ListaEnlazadaDoble();
ListaEnlazadaDoble static *listaFichas3=new ListaEnlazadaDoble();
ListaXYD *coorU1=new ListaXYD();
ListaXYD *coorU2=new ListaXYD();
ListaPunt *listaPunteos=new ListaPunt();
bool bandera=false;
static int puntaje=0;
static int puntajeU1=0;
static int puntajeU2=0;
static string idUsuario1="";
static string idUsuario2="";
static int contadorFichas=0;
bool terminarTurno=false;
bool regresarMenuPrincipal=false;
bool salir=false;
using namespace std;
using namespace colorwin;
template<typename G>
std::string ToStringG(G val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}
//prototipos de funcion
void jugador1(ListaEnlazadaDoble *);
void jugador2(ListaEnlazadaDoble *);
bool verificarFicha();
void run(ListaEnlazadaDoble *,ListaXYD *);
void menuPrincipal();
void borrar();
////////////////////LLENAR LA PILA CON DATOS ALEATORIAMENTE/////////////////////
void intercambiar(string *a,string *b){
    string temporal=*a;
    *a=*b;
    *b=temporal;
}
void llenarCola(string arr[],int n){
    for(int i=0;i<n;i++){
        //Instancia de la cola
        cola.insertar(arr[i]);
        listaFichas3->addFront(arr[i]);//Llena la lista de fichas
    }

}
void random(string arr[],int n){
    srand(time(NULL));
    for(int i=n-1;i>0;i--){
        int j=rand()%(i+1);
        intercambiar(&arr[i],&arr[j]);
    }
}
void obtenerFichas(){
    //Fichas quemadas para ingresarlas a la pila, 95 fichas
    string fichas[] = {"Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ax1","Ex1","Ex1","Ex1","Ex1","Ex1","Ex1","Ex1","Ex1",
                       "Ex1","Ex1","Ex1","Ex1","Ox1","Ox1","Ox1","Ox1","Ox1","Ox1","Ox1","Ox1","Ox1","Ix1","Ix1","Ix1","Ix1","Ix1","Ix1",
                       "Sx1","Sx1","Sx1","Sx1","Sx1","Sx1","Nx1","Nx1","Nx1","Nx1","Nx1","Nx1","Lx1","Lx1","Lx1","Lx1","Rx1","Rx1","Rx1","Rx1","Rx1",
                       "Ux1","Ux1","Ux1","Ux1","Ux1","Tx1","Tx1","Tx1","Tx1","Dx2","Dx2","Dx2","Dx2","Dx2","Gx2","Gx2","Cx3","Cx3","Cx3",
                       "Bx3","Bx3","Mx3","Mx3","Px3","Px3","Hx4","Hx4","Fx4","Vx4","Yx4","Qx5","Jx8","Kx8","Xx8","Zx10"};
    int n = sizeof(fichas) / sizeof(fichas[0]);
    random(fichas, n);
    llenarCola(fichas, n);
    //cola.graficarCola();

}
////////////////////////////////////////////////////////////////////////////////
void jugar(){

   do{
        //jugador1();
        //jugador2();

    }while(cola.colaSize()==0); //para terminar el juego, o la pila se queda vacia u otra opcion que esta en veremos
    if(cola.colaSize()==0){
            cout<<"YA NO HAY FICHAS DISPONIBLES EN LA COLA\n";
    }
}
/////////////////////////BORRAR DATOS DESPUES DE TERMINAR UN TURNO////////////////////////////////
void borrar(){

    int n1=listaFichas->tamanioStockUsuario();
    int n2=listaFichas2->tamanioStockUsuario();
    int n3=listaFichas3->tamanioStockUsuario();

    //system("pause");
    cola.borrarCola();
    idUsuario1="";
    idUsuario2="";
    puntajeU1=0;
    puntajeU2=0;
    for(int i=0;i<n1;i++){
        listaFichas->removeFront();
    }
    for(int i=0;i<n2;i++){
        listaFichas2->removeFront();
    }
    for(int i=0;i<n3;i++){
          listaFichas3->removeFront();
    }
    cola2.borrarCola();
    /*cout<<"\nTAMANIO LISTAFICHAS"<<listaFichas->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO LISTAFICHAS_2"<<listaFichas2->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO LISTAFICHAS_3"<<listaFichas3->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO COLA"<<cola.colaSize()<<endl;
    cout<<"TAMANIO COLA"<<cola.tamanioCola()<<endl;
    system("Pause");*/

}
string retornarFicha(char temp){
    char temp2;
    string auxiliar="";
    temp2=char(toupper(temp));
    switch(temp2){
    case 'A': //Que pasa si ingreso una A
        auxiliar="Ax1"; //Se manda a un metodo para ver si existe en el dock del usuario
        return auxiliar;
        break;
    case 'B':
        auxiliar="Bx3";
        return auxiliar;
        break;
    case 'C':
        auxiliar="Cx3";
        return auxiliar;
        break;
    case 'D':
        auxiliar="Dx2";
        return auxiliar;
        break;
    case 'E':
        auxiliar="Ex1";
        return auxiliar;
        break;
    case 'F':
        auxiliar="Fx4";
        return auxiliar;
        break;
    case 'G':
        auxiliar="Gx2";
        return auxiliar;
        break;
    case 'H':
        auxiliar="Hx4";
        return auxiliar;
        break;
    case 'I':
        auxiliar="Ix1";
        return auxiliar;
        break;
    case 'J':
        auxiliar="Jx8";
        return auxiliar;
        break;
    case 'K':  //Quitar si no esta permitida
        auxiliar="Kx1";
        return auxiliar;
        break;
    case 'L':
        auxiliar="Lx1";
        return auxiliar;
        break;
    case 'M':
        auxiliar="Mx3";
        return auxiliar;;
        break;
    case 'N':
        auxiliar="Nx1";
        return auxiliar;
        break;
    /*case 'Ñ':
        auxiliar="NIUx8";
        return auxiliar;
        break;*/
    case 'O':
        auxiliar="Ox1";
        return auxiliar;
        break;
    case 'P':
        auxiliar="Px3";
        return auxiliar;
        break;
    case 'Q':
        auxiliar="Qx5";
        return auxiliar;
        break;
    case 'R':
        auxiliar="Rx1";
        return auxiliar;
        break;
    case 'S':
        auxiliar="Sx1";
        return auxiliar;
        break;
    case 'T':
        auxiliar="Tx1";
        return auxiliar;
        break;
    case 'U':
        auxiliar="Ux1";
        return auxiliar;
        break;
    case 'V':
        auxiliar="Vx4";
        return auxiliar;
        break;
    case 'W':
        auxiliar="Wx1"; //Quitar si no esta permitida
        return auxiliar;
        break;
    case 'X':
        auxiliar="Xx8";
        return auxiliar;
        break;
    case 'Y':
        auxiliar="Yx4";
        return auxiliar;
        break;
    case 'Z':
        auxiliar="Zx10";
        return auxiliar;
        break;
    default:
        cout<<"\nCARACTER NO VALIDO\n";


    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////AGREGAR FICHAS A LOS JUGADORES//////////////
void run(ListaEnlazadaDoble *jugador,ListaXYD *coorUsu){
    terminarTurno=false;
    int x,y; //Coordenadas donde se va a ingresar la ficha
    int tempX,tempY;
    string ficha;  //Guarda la variable auxiliar
    char temp;
    char temp2;
    char opcion;
    //int puntaje=0; //Acumla el puntaje de el jugador
    string auxiliar="";
    string palabra;
    string letraIngresada;
    char letra;


    do{
    //cout<<color(green)<<"\nTERMINAR EL TURNO?,presionar SI=X, \n INSERTAR FICHA?,presionar NO=Z,\nINTERCAMBIAR FICHAS?,presionar F, \nSALIR?,presionar S :"; //x me saca del metodo jugador2()
    cout<<color(green)<<"\nZ. INSERTAR FICHA?"<<endl;
    cout<<color(green)<<"X. TERMINAR TURNO?"<<endl;
    cout<<color(green)<<"F. INTERCAMBIAR FICHAS?"<<endl;
      cout<<color(red)<<"S. SALIR"<<endl;
    cout<<color(green)<<" : ";
    cin>>opcion;
    if(opcion==122){
    cout<<"FICHAS DISPONIBLES\n";
    jugador->printReverse(); //Muestra las fichas disponibles del jugador
    cout<<endl;
    cout<<"\nX: ";cin>>x; //ingresa la coordenada x
    cout<<"Y: ";cin>>y; //ingresa la coordenada y
    coorUsu->agregarAlInicioXYD(x,y);
    cout<<"Ficha: ";cin>>temp; ///Ingresa la ficha
    temp2=char(toupper(temp)); //Guardo en otra variable la letra ingresada en mayuscula
    letraIngresada="";
    switch(temp2){
    case 'A': //Que pasa si ingreso una A
        auxiliar="Ax1"; //Se manda a un metodo para ver si existe en el dock del usuario
        letraIngresada="A";
        puntaje=puntaje+1;
        break;
    case 'B':
        auxiliar="Bx3";
        letraIngresada="B";
        puntaje=puntaje+3;
        break;
    case 'C':
        auxiliar="Cx3";
        letraIngresada="C";
        puntaje=puntaje+3;
        break;
    case 'D':
        auxiliar="Dx2";
        letraIngresada="D";
        puntaje=puntaje+2;
        break;
    case 'E':
        auxiliar="Ex1";
        letraIngresada="E";
        puntaje=puntaje+1;
        break;
    case 'F':
        auxiliar="Fx4";
        letraIngresada="F";
        puntaje=puntaje+4;
        break;
    case 'G':
        auxiliar="Gx2";
        letraIngresada="G";
        puntaje=puntaje+2;
        break;
    case 'H':
        auxiliar="Hx4";
        letraIngresada="H";
        puntaje=puntaje+4;
        break;
    case 'I':
        auxiliar="Ix1";
        letraIngresada="I";
        puntaje=puntaje+1;
        break;
    case 'J':
        auxiliar="Jx8";
        letraIngresada="J";
        puntaje=puntaje+8;
        break;
    case 'K':  //Quitar si no esta permitida,va actuar como la Ñ
        auxiliar="Kx1";
        letraIngresada="K";
        puntaje=puntaje+10;
        break;
    case 'L':
        auxiliar="Lx1";
        letraIngresada="L";
        puntaje=puntaje+1;
        break;
    case 'M':
        auxiliar="Mx3";
        letraIngresada="M";
        puntaje=puntaje+3;
        break;
    case 'N':
        auxiliar="Nx1";
        letraIngresada="N";
        puntaje=puntaje+1;
        break;
    /*case 'Ñ':
        auxiliar="NIUx8";
        letraIngresada="Ñ";
        puntaje=puntaje+8;
        break;*/
    case 'O':
        auxiliar="Ox1";
        letraIngresada="O";
        puntaje=puntaje+1;
        break;
    case 'P':
        auxiliar="Px3";
        letraIngresada="P";
        puntaje=puntaje+3;
        break;
    case 'Q':
        auxiliar="Qx5";
        letraIngresada="Q";
        puntaje=puntaje+5;
        break;
    case 'R':
        auxiliar="Rx1";
        letraIngresada="R";
        puntaje=puntaje+1;
        break;
    case 'S':
        auxiliar="Sx1";
        letraIngresada="S";
        puntaje=puntaje+1;
        break;
    case 'T':
        auxiliar="Tx1";
        letraIngresada="T";
        puntaje=puntaje+1;
        break;
    case 'U':
        auxiliar="Ux1";
        letraIngresada="U";
        puntaje=puntaje+1;
        break;
    case 'V':
        auxiliar="Vx4";
        letraIngresada="V";
        puntaje=puntaje+4;
        break;
    case 'W':
        auxiliar="Wx1"; //Quitar si no esta permitida
        letraIngresada="W";
        puntaje=puntaje+1;
        break;
    case 'X':
        auxiliar="Xx8";
        letraIngresada="X";
        puntaje=puntaje+8;
        break;
    case 'Y':
        auxiliar="Yx4";
        letraIngresada="Y";
        puntaje=puntaje+4;
        break;
    case 'Z':
        auxiliar="Zx10";
        letraIngresada="Y";
        puntaje=puntaje+10;
        break;
    default:
        cout<<"\nCARACTER NO VALIDO\n";

    } //El break en teoria va a terminar el switch y mandara auxiliar con el valor dado
    if(jugador->buscarNodo(auxiliar)){ //Si existe la ficha la almacenamos en otra variable, Case para verificar el punteo
        ficha=auxiliar;
        letra=char(toupper(temp2)); //Letra que ingrese
        palabra=palabra+letraIngresada; //Se va ir formando la letra, siempre y cuando exista la ficha
        r->addMatrix2(x,y,ToString(letra)); //La inserto a la matrix
        r->graphMatrix();
        jugador->eliminarNodo(ficha); /////////////////////////Elimino la ficha del dock del jugador si ya la uitlizo en el tablero/////////////
        cola2.insertar(ficha);/////////////////////////Almacenara las fichas que vaya utilizando el jugador
        //cout<<"SI ESTA INSERTANDOSE A LA COLA\n";
        cola2.recorrerCola();
        //cout<<"Tamanio de la cola en el metodo Run() "<<cola2.tamanioCola();
        contadorFichas++;
        //cout<<"CONTADOR FICHAS:"<<contadorFichas<<endl;

    }
    else{
        cout<<"LA FICHA NO SE ENCUENTRA EN SU LISTA\n"; //Si no existe
        contadorFichas++;
    }
    //////////////////////////AQUI TERMINA DE INGRESAR FICHAS///////////////////////////
    //Tengo que ver la forma de terminar el juego
    /*Segun el enunciado el jugador termina su turno si asi lo indica, se tiene que validar el turno */
    }
    else if(opcion==102){///////////////////////////////presiono f,Intercambiar Fichas/////////////////////////////////////
            int n;
            char ficha;
            char fichaInt;
            jugador->printReverse();
            do{

                cout<<color(blue)<<"\n1.INTERCAMBIAR FICHA\n";
                cout<<color(blue)<<"2.SALIR\n";
                cin>>n;
                switch(n){
                case 1:
                    //cout<<"Tamanio de la LISTA antes de intercambiar"<<listaFichas3->tamanioStockUsuario()<<endl; //Cantidad que hay en el stock
                    //cout<<"Tamanio de la COLA antes de intercambiar"<<cola.tamanioCola()<<endl;//Cantidad que hay en el stock
                    cout<<color(blue)<<"FICHA: ";
                    cin>>ficha;  /////////////////////////////////Ingreso la ficha que voy a volver a el stock general/////////////////////////////////////////////////
                    //cola.insertar(retornarFicha(ficha));/////////Inserto(la regreso) a la cola la ficha que voy a cambiar
                    listaFichas3->addFront(retornarFicha(ficha));//La agrego a la lista
                    //cout<<"Tamanio de la LISTA antes de intercambiar2 "<<listaFichas3->tamanioStockUsuario()<<endl; //El tamanio sera mas grande
                    jugador->eliminarNodo(retornarFicha(ficha));//////La elimino de mis fichas
/////////////////////////////////////////////////////DESPUES DE INTERCAMBIAR///////////////////////////////////////////////////////
                    cout<<color(blue)<<"INTERCAMBIAR POR: "; /////////////////Ingreso la ficha por la cual voy a intercambiar///////////////////
                    cin>>fichaInt;
                    jugador->addFront(retornarFicha(fichaInt)); //Agrego la nueva ficha a mi mano
                    listaFichas3->eliminarNodo(retornarFicha(fichaInt));///La elimino del stock de fichas
                    //cout<<"Tamanio de la LISTA despues de intercambiar"<<listaFichas3->tamanioStockUsuario()<<endl; //El tamanio sera como al inicio
                    //cola.quitar();//Por el momento
                    cola.borrarCola();////////////////////Borrar toda la cola
                    ////////Vuelvo a llenar la oola
                    //cout<<"TAMANIO COLA "<<cola.tamanioCola()<<endl; //Sera cero
                    //cout<<"TAMANIO LISTA despues de intercambiar "<<listaFichas3->tamanioStockUsuario()<<endl;
                    cout<<""<<endl;
                    for(int i=0;i<listaFichas3->tamanioStockUsuario();i++){
                         cola.insertar(listaFichas3->retornarFichaPos(i));
                    }
                     //cout<<"TAMANIO COLA "<<cola.tamanioCola()<<endl; //Sera cero
                     cout<<"NUEVA MANO:"<<endl;
                     jugador->printReverse();
                    ///////////Ver la manera de quitar esa ficha especificamente de mi la cola y agregarla a mi lista
                    system("pause");
                    break;
                default:
                    cout<<"\nNo existe esta opcion\n";
                    break;
                }
                 //cout<<"\nTamanio de la Cola de Fichas :"<<cola.colaSize()<<endl;
            }while(n!=2);
            opcion=120;
            terminarTurno=true;
            regresarMenuPrincipal=false;

    }
    else if(opcion==115){ ///////////////Si presiono s//////////////////////////////
            if(puntajeU1>puntajeU2){
                cout<<color(cyan)<<"**********EL GANADOR ES EL JUGADOR 1: "<<idUsuario1<<" PUNTAJE : "<<puntajeU1<<"**********"<<endl;
        }
            else if(puntajeU2>puntajeU1){
                cout<<color(dark_gray)<<"**********EL GANADOR ES EL JUGADOR 2: "<<idUsuario2<<" PUNTAJE : "<<puntajeU2<<"**********"<<endl;
        }
            else{
                  cout<<color(blue)<<"**********EL JUEGO TERMINO EN EMPATE***********"<<endl;
        }
            regresarMenuPrincipal=true;
            salir=true;

            system("pause");
            opcion=120;



}
    }while(opcion!=120);  //Si presiona X se termina el turno del jugador
    //cout<<color(yellow)<<"TAMANIO GENERAL DE LA LISTA DE FICHAS "<<listaF->tamanioListaFichas()<<endl;


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////JUGADOR 1///////////////////////////////////////////////////////////////////////
void jugador1(ListaEnlazadaDoble *jugador_1){
    /*cout<<"\nTAMANIO LISTAFICHAS"<<listaFichas->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO LISTAFICHAS_2"<<listaFichas2->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO LISTAFICHAS_3"<<listaFichas3->tamanioStockUsuario()<<endl;
    cout<<"TAMANIO COLA"<<cola.colaSize()<<endl;
    cout<<"TAMANIO COLA"<<cola.tamanioCola()<<endl;*/
    bool condicion=false;
    string ficha="";
    cout<<endl;
    cout<<color(cyan)<<"\n############## JUGADOR 1 "<<" ["<<idUsuario1<<"]"<<"###############"<<endl;
    //Llenar las listas de fichas jugador1
    if(jugador_1->tamanioStockUsuario()>0){ //Si tiene al menos una ficha
        if(jugador_1->tamanioStockUsuario()==1){ //si solo tiene una ficha
            for(int i=0;i<6;i++){  //Se me vuelve a llenar la lista despues de cada turno
            ficha=cola.quitar();
            jugador_1->addFront(ficha); //Llena el dock de fichas del jugador 1 //Disminiyue la cola
            listaFichas3->eliminarNodo(ficha); //Disminuye la lista
        }

    }

    }
    else{
         for(int i=0;i<7;i++){  //Se me vuelve a llenar la lista despues de cada turno
         ficha=cola.quitar();
         jugador_1->addFront(ficha); //Llena el dock de fichas del jugador 1 //Disminiyue la cola
         listaFichas3->eliminarNodo(ficha); //Disminuye la lista
        }
    }
    cout<<color(cyan)<<"\nCANTIDAD DE FICHAS:"<<jugador_1->tamanioStockUsuario()<<endl;
    jugador_1->printReverse();
    //cout<<"\nTamanio de la Cola de Fichas :"<<cola.tamanioCola()<<endl;
    //cout<<"\nTamanio de la Lista de Fichas :"<<listaFichas3->tamanioStockUsuario()<<endl;
    run(jugador_1,coorU1);  //Cuando se termina el run viene lo siguiente
    cout<<terminarTurno<<endl;
    if(terminarTurno){
        //cout<<"ME LA ESTA TOMANDO COMO VERDADERA"<<endl;
    }
    if(terminarTurno==false){
     //////////Verificaciones para ver si la palabra coincide con las palabras del diccionario
    //cout<<"Palabra Formada:"<<palabra<<endl;
    //cout<<color(cyan)<<"PUNTAJES:"<<puntaje<<endl;
    r->obtenerPalabras();
    r->separarPalabras();
    //cout<<"Palabras formadas en teoria\n";
    //listaF->printReverse_F();//Me muestra las palabras de la matriz, en este punto la lista de fichas ya esta llena
    //cout<<"Lista despues de terminar un turno ya se por x o por s"<<endl;///#####################################
    //listaFichas->printReverse();
    int longitud=listaF->tamanioListaFichas(); //ListaEnladaDobleFichas
    //cout<<"\nLongitud "<<longitud<<endl;
    int longitud2=tamanioLCD(); //Lista circular doble, almacena las palabras obtenidas del archivo json
    //cout<<endl;
    string arr[longitud];
    string arr2[longitud2];
    /////////////Palabras obtenidas de la matriz//////////////
    for(int i=0;i<longitud;i++){
        arr[i]=listaF->retornarNodoPos(i);//Guarda las palabras obtenidas de la matriz
    }
    //Mostrar datos del array
    int limite = (sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < limite; i++)
    {
            //cout<<"PALABRAS DE LA MATRIZ:"<<arr[i]<<endl;
    }
     //cout<<"\nBANDERA1"<<endl;
    ///////////////Palabras del diccionario//////////////////////////
    for(int i=0;i<longitud2;i++){
        arr2[i]=retornarPalabraPos(i);//Guarda las palabras obtenidas de la matriz
    }
    //Mostrar datos del array
    int limite2 = (sizeof(arr2)/sizeof(arr2[0]));
    for (int i = 0; i < limite2; i++)
    {
            //cout<<"PALABRAS DE DICCIONARIO:"<<arr2[i]<<endl;
    }
    if(limite<limite2){//C1
      for(int i=0;i<limite;i++){
        for(int j=0;j<limite2;j++){
                if("\""+arr[i]+"\""==arr2[j]){//////////Condicion que compara si alguna palabra que forme en la matriz coincide con las del diccionario
                    cout<<color(cyan)<<"\nPALABRA FORMADA C1->"<<arr2[j]<<" PUNTEO:"<<listaF->retornarPunteo(i)<<endl;
                    //listaF->printReverse_F(); //quitar
                    //cout<<"\n"<<j<<endl; //quitar
                    //cout<<i<<endl; //quitar
                    //cout<<arr[i];
                    string punteo=listaF->retornarPunteo(i);
                    //listaF->eliminarNodo_F(arr[i]);
                    listaF->printReverse_F();
                    borrarLCD(arr2[j]);
                    int n=stoi(punteo,nullptr,10);
                    puntajeU1=puntajeU1+n;
                    //listaPunteos->agregarAlInicioP(idUsuario1,ToString(puntajeU1)); //Almaceno el punteo
                    condicion=true;


                }else{
                         //condicion=false;
                } } }
                 if(condicion==false){
                        if(!salir){
                                  cout<<color(cyan)<<"NO FORMO NINGUNA PALABRA JUGADOR 1"<<idUsuario1<<endl;
                     //cola2.recorrerCola();
                     //cout<<"\nTAMANIO COLA EN ESTE PUNTO:"<<cola2.tamanioCola()<<endl;

                       if(cola2.tamanioCola()==1){
                                //cout<<"El tamanio si es uno\n";
                                jugador_1->addBack(cola2.quitar());

                        }else{
                             for(int i=0;i<cola2.tamanioCola();i++){
                             //cout<<"sergio->";
                             jugador_1->addBack(cola2.quitar());
                        }
                            //jugador_1->addBack(cola2.quitar());
                        }
                        /////////////////////////////Regresar las fichas de la matriz al usuario///////////////////////////////////////

                            for(int i=0;i<contadorFichas;i++){
                                r->edit(coorU1->retornarX(i),coorU1->retornarY(i)," ");
                            }
                              r->graphMatrix();



                        }




                }
                }


    else{//C2
       for(int i=0;i<limite2;i++){
        for(int j=0;j<limite;j++){
                if(arr2[i]=="\""+arr[j]+"\""){//////////Condicion que compara si alguna palabra que forme en la matriz coincide con las del diccionario
                    cout<<color(cyan)<<"\nPALABRA FORMADA C2->"<<arr2[i]<<" PUNTEO:"<<listaF->retornarPunteo(j)<<endl;
                    string punteo=listaF->retornarPunteo(j);
                    //cout<<arr2[i]<<endl;
                    //cout<<arr[j]<<endl;
                    //cout<<i<<endl;
                    //cout<<j<<endl;
                    //listaF->eliminarNodo_F(arr[j]);
                    listaF->printReverse_F();
                    borrarLCD(arr2[i]);
                    int n=stoi(punteo,nullptr,10);
                    puntajeU1=puntajeU1+n;
                    //listaPunteos->agregarAlInicioP(idUsuario1,ToString(puntajeU1)); //Almaceno el punteo
                    condicion=true;
                }
                else{
                     //condicion=false;
                }
                }
                }
                ///////Si no formo ninguna palabra
                if(condicion==false){
                        if(!salir){
                                cout<<color(cyan)<<"\nNO FORMO NINGUNA PALABRA JUGADOR 1"<<idUsuario1<<endl;
                    //cola2.recorrerCola();
                    //cout<<"\nTAMANIO COLA EN ESTE PUNTO:"<<cola2.tamanioCola()<<endl;

                      if(cola2.tamanioCola()==1){
                                //cout<<"El tamanio si es uno\n";
                                jugador_1->addBack(cola2.quitar());

                     }else{
                             for(int i=0;i<cola2.tamanioCola();i++){
                             //cout<<"sergio->";
                             jugador_1->addBack(cola2.quitar());
                             }
                             //jugador_1->addBack(cola2.quitar());
                             }
                /////////////////////////////Regresar las fichas de la matriz al usuario///////////////////////////////////////

                            for(int i=0;i<contadorFichas;i++){
                                r->edit(coorU1->retornarX(i),coorU1->retornarY(i)," ");
                            }
                              r->graphMatrix();

                        }



                }

            }

    }
    if(puntajeU1==0 || condicion==false || regresarMenuPrincipal==true){

    }
    else{
        listaPunteos->agregarAlInicioP(idUsuario1,ToString(puntajeU1));
    }
 contadorFichas=0;
 if(regresarMenuPrincipal==true){


     //menuPrincipal();
 }else{
     //cout<<"APURARSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
     //system("pause");
     jugador2(listaFichas2);

 }
 //listaFichas->printReverse();
 //system("pause");

}
///////////////////////////////////////////////////JUGADOR 2 /////////////////////////////////////////////////////////////
void jugador2(ListaEnlazadaDoble *jugador_2){
    bool condicion=false;
    string ficha="";
    cout<<endl;
    cout<<color(dark_gray)<<"\n############## JUGADOR 2 "<<" ["<<idUsuario2<<"]"<<"###############"<<endl;
    //Llenar las listas de fichas jugador2
    if(jugador_2->tamanioStockUsuario()>0){
        if(jugador_2->tamanioStockUsuario()==1){
            for(int i=0;i<6;i++){  //Se me vuelve a llenar la lista despues de cada turno
            ficha=cola.quitar();
            jugador_2->addFront(ficha); //Llena el dock de fichas del jugador 1 //Disminiyue la cola
            listaFichas3->eliminarNodo(ficha); //Disminuye la lista
        }
    }

     }
    else{
         for(int i=0;i<7;i++){
        //listaFichas2->addFront(cola.quitar());
        //jugador_2->addFront(cola.quitar());
        ficha=cola.quitar();
        jugador_2->addFront(ficha);
        listaFichas3->eliminarNodo(ficha);

    }
    }
   //Otro do while
    cout<<color(dark_gray)<<"\nCANTIDAD DE FICHAS:"<<jugador_2->tamanioStockUsuario()<<endl; //Indica el tamanio de la cola
    jugador_2->printReverse(); //Me muestra las fichas que tengo
    run(jugador_2,coorU2);
    //////////Verificaciones para ver si la palabra coincide con las palabras del diccionario
    //cout<<"Palabra Formada:"<<palabra<<endl;
    //cout<<color(blue)<<"PUNTAJES:"<<puntaje<<endl;
    if(terminarTurno==false){
    r->obtenerPalabras();
    r->separarPalabras();
    //cout<<"Palabras formadas en teoria\n";
    //listaF->printReverse_F();//Me muestra las palabras de la matriz, en este punto la lista de fichas ya esta llena
    //cout<<"Lista despues de terminar un turno ya se por x o por s"<<endl;///#####################################
    //listaFichas2->printReverse();
    int longitud =listaF->tamanioListaFichas(); //ListaEnladaDobleFichas
    int longitud2=tamanioLCD();
    //cout<<"\nTamanio longitud"<<longitud<<endl;
    //cout<<"\nTamanio longitud2"<<longitud2<<endl;
    //cout<<endl;
    string arr[longitud];
    string arr2[longitud2];
    /////////////Palabras obtenidas de la matriz//////////////
    for(int i=0;i<longitud;i++){
        arr[i]=listaF->retornarNodoPos(i);//Guarda las palabras obtenidas de la matriz
    }
    //Mostrar datos del array
    int limite = (sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < limite; i++)
    {
            //cout<<"PALABRAS DE LA MATRIZ:"<<arr[i]<<endl;  //Me muestra las palabras que he formado en la matriz
    }
    ///////////////Palabras del diccionario//////////////////////////
    for(int i=0;i<longitud2;i++){
        arr2[i]=retornarPalabraPos(i);//Guarda las palabras obtenidas de la matriz
    }
    //Mostrar datos del array
    int limite2 = (sizeof(arr2)/sizeof(arr2[0]));
    for (int i = 0; i < limite2; i++)
    {
            //cout<<"PALABRAS DE DICCIONARIO:"<<arr2[i]<<endl;
    }
    if(limite<limite2){//C1
      for(int i=0;i<limite;i++){
        for(int j=0;j<limite2;j++){
                if("\""+arr[i]+"\""==arr2[j]){
                      cout<<color(blue)<<"\nPALABRA FORMADA C1->"<<arr2[j]<<" PUNTEO:"<<listaF->retornarPunteo(i)<<endl;
                      string punteo=listaF->retornarPunteo(i);
                      //cout<<arr[i]<<endl;
                      //cout<<arr2[i]<<endl;
                      //listaF->eliminarNodo_F(arr[i]);  //
                      //listaF->printReverse_F();
                      borrarLCD(arr2[j]);
                      int n=stoi(punteo,nullptr,10);
                      puntajeU2=puntajeU2+n;
                      //listaPunteos->agregarAlInicioP(idUsuario2,ToString(puntajeU2)); //Almaceno el punteo
                      condicion=true;
                   }
                   else{
                        //condicion=false;
                   } } }
                   if(condicion==false){
                        if(!salir){
                        cout<<color(blue)<<"\nNO FORMO NINGUNA PALABRA JUGADOR 2"<<idUsuario2<<endl;
                        //cola2.recorrerCola();
                        //cout<<"\nTAMANIO COLA EN ESTE PUNTO:"<<cola2.tamanioCola()<<endl;

                        if(cola2.tamanioCola()==1){
                           //cout<<"El tamanio si es uno\n";
                           jugador_2->addBack(cola2.quitar());

                        }else{
                             for(int i=0;i<cola2.tamanioCola();i++){
                             //cout<<"sergio2->";
                             jugador_2->addBack(cola2.quitar()); //Aqui se devuelven las fichas de nuevo al dock del jugador

                        }
                            //jugador_2->addBack(cola2.quitar());
                        }
                          /////////////////////////////Regresar las fichas de la matriz al usuario///////////////////////////////////////

                            for(int i=0;i<contadorFichas;i++){
                                r->edit(coorU2->retornarX(i),coorU2->retornarY(i)," ");
                            }
                              r->graphMatrix();





                   }

                        }


                   }

    else{ //C2
       for(int i=0;i<limite2;i++){
        for(int j=0;j<limite;j++){
                if(arr2[i]=="\""+arr[j]+"\""){
                     cout<<color(blue)<<"\nPALABRA FORMADA C2->"<<arr2[i]<<" PUNTEO:"<<listaF->retornarPunteo(j)<<endl;
                     string punteo=listaF->retornarPunteo(j);
                     //cout<<arr2[i]<<endl;
                     //cout<<arr[j]<<endl;
                     //cout<<i<<endl;
                     //cout<<j<<endl;
                     //listaF->eliminarNodo_F(arr[j]);
                      listaF->printReverse_F();
                      borrarLCD(arr2[i]);
                      int n=stoi(punteo,nullptr,10);
                      puntajeU2=puntajeU2+n;
                      //listaPunteos->agregarAlInicioP(idUsuario2,ToString(puntajeU2)); //Almaceno el punteo
                      condicion=true;

                }
                else{
                     //condicion=false;
                }
            }
       }
         if(condicion==false){

                if(!salir){
                         cout<<color(blue)<<"NO FORMO NINGUNA PALABRA JUGADOR 2"<<idUsuario2<<endl;
                        //cola2.recorrerCola();
                        //cout<<"\nTAMANIO COLA EN ESTE PUNTO:"<<cola2.tamanioCola()<<endl;
                        cout<<cola2.tamanioCola();

                        if(cola2.tamanioCola()==1){
                                //cout<<"El tamanio si es uno\n";
                                jugador_2->addBack(cola2.quitar());

                        }else{
                             for(int i=0;i<cola2.tamanioCola();i++){

                             jugador_2->addBack(cola2.quitar()); //Aqui se devuelven las fichas de nuevo al dock del jugador

                             }
                            //jugador_2->addBack(cola2.quitar());
                        }
                        /////////////////////////////Regresar las fichas de la matriz al usuario///////////////////////////////////////

                            for(int i=0;i<contadorFichas;i++){
                                r->edit(coorU2->retornarX(i),coorU2->retornarY(i)," ");
                            }
                            r->graphMatrix();

                }




         }
                   }




    }
     if(puntajeU2==0 || condicion==false || regresarMenuPrincipal==true){

    }
    else{
        listaPunteos->agregarAlInicioP(idUsuario2,ToString(puntajeU2));
    }
    contadorFichas=0;
    if(regresarMenuPrincipal==true){

        //menuPrincipal();
    }else{
        //cout<<"APURARSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
        //system("pause");
        jugador1(listaFichas);
    }
    //listaFichas2->printReverse();


    }

    //string palabraFinal=ToString("\""+palabra+"\"");
    //cout<<"Palabra Final :"<<palabraFinal<<endl;
    //

////////////////////////////////////////////////////////////////////////////////
void cargarArchivo(){
    string archivo="";
    cout<<color(blue)<<"INGRESE EL NOMBRE DEL ARCHIVO JSON : ";
    cin>>archivo;
    LeerJson(archivo);
    cout<<"\nARCHIVO CARGADO CORRECTAMENTE";

}
void submenu2(){ ///Opcion 2 del menu principal, registra y permite escoger juegadores para empezar el juego
    char opcion;
    string jugador="";
    if(cola.tamanioCola()>0 && listaFichas->tamanioStockUsuario()>0 && listaFichas2->tamanioStockUsuario()>0){
            borrar();
            obtenerFichas();
            cout<<endl;
            regresarMenuPrincipal=false;
            //cout<<"\nTAMANIO DE LA COLA DESPUES DE OBTENER FICHAS NUEVAMENTE :"<<cola.tamanioCola();
            //jugador1(listaFichas);
    }
    else{
        obtenerFichas();
    }
    do{
    cout<<color(blue)<<"##########################AREA DE JUEGO########################"<<endl;
    cout<<color(blue)<<"###############################################################"<<endl;
    cout<<color(blue)<<"# 1.REGISTRAR JUGADORES                                       #"<<endl;
    cout<<color(blue)<<"# 2.MOSTRAR JUGADORES                                         #"<<endl;
    cout<<color(blue)<<"# 3.EMPEZAR EL JUEGO                                          #"<<endl;
    cout<<color(blue)<<"# 4.SALIR                                                     #"<<endl;
    cout<<color(blue)<<"###############################################################"<<endl;
    cout<<" : ";
    cin>>opcion;
    if(opcion>=48&&opcion<=57){
        switch(opcion){
    case 49:  /////////////////////////////////////////////////////1.OPCION REGISTRAR JUGADORES//////////////////////////////////////////////
        cout<<"REGISTRO DE JUGADORES"<<endl;
        cout<<"NOMBRE USUARIO: ";
        cin>>jugador; //Se ingresa el nombre del jugador,
        arbol->insertar(jugador);//Se inserta al arbol
        system("pause");
        break;
    case 50://////////////////////////////////Ingreso del id con el que van a jugar los usuarios
        cout<<"JUGADORES REGISTRADOS"<<endl;
        arbol->mostrarInOrden(); //Muestra los jugadores agregados
        cout<<"INGRESE EL NOMBRE DEL JUGADOR 1 :";
        cin>>idUsuario1;
        cout<<"INGRESE EL NOMBRE DEL JUGADOR 2 :";
        cin>>idUsuario2;
        system("pause");
        break;
    case 51:
        cout<<color(blue)<<"##########################JUAGANDO#######################"<<endl;
        if(idUsuario1=="" || idUsuario2==""){
            cout<<color(red)<<"\nNO HA INGRESADO LOS JUGADORES"<<endl;
        }
        else{
            jugador1(listaFichas); /////Empieza con jugador 1
        }

        if(regresarMenuPrincipal==true){

            opcion=52;
        }
        break;
    default:
        cout<<"OPCION NO VALIDA"<<endl;

    }
    system("cls");
    }
    else{
        cout<<"No se permiten letras\n";
        system("cls");
    }

    }while(opcion!=52);
}

void reportes(){
    int n=0;
    int n2=0;
    string id;
    int jugador;
    do{
        //cout<<color(blue)<< "###############################################################"<<endl;
        cout<<color(green)<<"######################AREA DE REPORTES#########################"<<endl;
        cout<<endl;
        cout<<color(green)<<"1.DICCIONARIO\n";
        cout<<color(green)<<"2.FICHAS DISPONIBLES\n";
        cout<<color(green)<<"3.USUARIOS REGISTRADOS\n";
        cout<<color(green)<<"4.HISTORIAL DE PUNTAJE POR JUGADOR\n";
        cout<<color(green)<<"5.SCOREBOARD\n";
        cout<<color(green)<<"6.FICHAS POR JUGADOR\n";
        cout<<color(green)<<"7.RECORRIDOS\n";
        cout<<color(red)<<  "8.SALIR\n";
        cout<<color(green)<<"INGRESAR LA OPCION :";
        cin>>n;

        switch(n){
        case 1:
            graficar();
            break;
        case 2:
            if(cola.colaVacia()){
                cout<<color(red)<<"COLA VACIA"<<endl;
            }else{
                cola.graficarCola();
            }
            break;
        case 3:
            arbol->graficar();
            break;
        case 4:

            cout<<color(green)<<"INGRESE EL NOMBRE DEL USUARIO: "<<endl;
            cin>>id;
            listaPunteos->buscarPuntajeP(id);
            //graficarLista(head);
            /////////////////////////Implementar/////////////////////
            break;
        case 5:
            graficarLista(head2);
            break;
        case 6:
            cout<<color(green)<<"JUGADOR :";
            cin>>jugador;
            if(jugador==1){
                listaFichas->graphList();
                listaFichas->printReverse();
            }
            else{
                listaFichas2->graphList();
                listaFichas2->printReverse();
            }
            break;


        case 7:
            do{
            cout<<color(green)<<"1.INORDEN"<<endl;
            cout<<color(green)<<"2.PREORDEN"<<endl;
            cout<<color(green)<<"3.POSTORDEN"<<endl;
            cout<<color(green)<<"4.SALIR"<<endl;
            cout<<color(green)<<" : ";
            cin>>n2;
            switch(n2){
            case 1:
                arbol->RecorridoInorden();
                arbol->graficaInOrden();
                break;
            case 2:
                arbol->RecorridoPreOrden();
                arbol->graficaPreOrden();
                break;
            case 3:
                arbol->RecorridoPostOrden();
                arbol->graficaPostOrden();
                break;
            default:
                break;
            }

            }while(n2!=4);
            break;
        }
            system("cls");

    }while(n!=8);

}

void ganador(){

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void menuPrincipal(){
    cout<<color(red)<< "############################SCRABBLE###########################"<<endl;
    cout<<endl;
    cout<<color(blue)<<"###############################################################"<<endl;
    cout<<color(blue)<<"# 1.LECTURA DE ARCHIVO                                        #"<<endl;
    cout<<color(blue)<<"# 2.JUGAR                                                     #"<<endl;
    cout<<color(blue)<<"# 3.REPORTES                                                  #"<<endl;
    cout<<color(blue)<<"# 4.SALIR                                                     #"<<endl;
    cout<<color(blue)<<"###############################################################"<<endl;


}
int main(){
    int a=0;
    string archivo="";
    //obtenerFichas(); //Obtengo las fichas quemadas y se las reparto a cada jugador
    //LeerJson("entrada.json");
    //graficar();
    //jugador1(listaFichas);
    char opcion=0;
    do{
    menuPrincipal();
    cout<<color(blue)<<"INGRESAR OPCION :";
    cin>>opcion;
    if(opcion>=48&&opcion<=57){
            switch(opcion){

    case 49:///////////////////////////////////////1.Lectura de archivo///////////////////////////////////////////////////////
        cout<<color(blue)<<"LECTURA DE ARCHIVO"<<endl;
        cout<<color(blue)<<"Ingrese el Nombre del Archivo : ";
        cin>>archivo;
        LeerJson(archivo);
        //obtenerFichas();
        system("pause");
        break;
    case 50:///////////////////////////////////////2.REGISTRAR JUGADORES Y JUGAR/////////////////////////////////////////////
        submenu2();
        //system("pause");
        break;
    case 51:
        cout<<color(blue)<<"REPORTES"<<endl;
        reportes();
        system("pause");
        break;
    default:
        cout<<"NO EXISTE ESA OPCION"<<endl;

    }
    system("cls");

    }
    else{
        cout<<"NO SE PERMITEN LETRAS\n";
        system("pause");
        system("cls");
    }

    }while(opcion!=52);

    return 0;
}
