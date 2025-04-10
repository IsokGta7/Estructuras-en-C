/* Nombre: main.cpp
   Autor: Ezequiel Isaac Rodriguez Tenorio.
   Fecha: 6/05/21
   Descripci�n: Cliente para probara la clase ArbolBA
*/

#include <fstream>
#include<limits>
#include<windows.h>
#include<iostream>
#include"Vector.h"
#include"ArbolBA.h"

using namespace std;

 /***************************************************************************************
 ********************************  Funci�nes aux  ***************************************
 ***************************************************************************************/
//*************************************************************************************
/** \brief Gestiona la mayor�a de las operaciones
 *
 * \param ab El ArbolBA en la que se realizar� la operaci�n
 * \param op La operaci�n a efectuar
 * \return si La operaci�n se realizo exitosamente
 *
 */
template<typename T,unsigned G>
bool RealizarOp(ArbolBA<T,G> & ab, char op);

//*************************************************************************************
/** \brief Imprime el menu
 */
void ImprMenu();

//*************************************************************************************
/** \brief Lee una opci�n y regresa un car�cter dentro del rango v�lido
 *
 * \param mensaje El mensaje para pedir la opci�n
 * \param opciones Una cadena donde cada car�cter representa una opci�n valida
 * \return Una opci�n v�lida
 *
 */
char LeerOpcion(const char * mensaje,const char *opciones  );


 /***************************************************************************************
 *****************************************  Main  ***************************************
 ***************************************************************************************/
//*************************************************************************************
int main()
{
    cout<<"Buenos dias.A continuaci\242n se mostrara la genialidad de la clase ArbolBA, para ello tendra "<<
            "a su dispoci\242n 3 tipos de arboles:\nuno de enteros(G=3), de caracteres(G=5) y otro de vectores(G=3).\n";

    ArbolBA<int,5> abC;
    ArbolBA<int,5> abV;
    ArbolBA<int,5> abI;
    bool exito;
    char tList,op;

    tList = LeerOpcion("Tipo de arbol inicial: int(i), char(c), vector(v): ","ivc");
    do
    {
        cout<<"Recuerde, el tipo del arbol es: ("<<tList<<")";
        ImprMenu();
        op=LeerOpcion("Opci\242n: ","01234567c");
        if(op == '0' || op=='c' )
        {
            exito=true;
            if(op=='c')
                tList = LeerOpcion("Tipo del arbol inicial: int(i), char(c), vector(v): ","ivc");
        }
        else
        {
            switch (tList)
            {
                case 'i':
                    exito=RealizarOp(abI,op);
                    break;
               case 'v':
                    exito=RealizarOp(abV,op);
                    break;
                case 'c':
                    exito=RealizarOp(abC,op);
                    break;
            }
        }
        if(op != '0')
        {
            if(exito)
                cout<<"\nexito en la operaci\242n\n";
            else
                cout<<"la operaci\242n no altero la grafica...\nTal vez se agreg\242 un elemento repetido, se "<<
                        "elimino un elemento no existente o se vacio algo que ya estaba vac\241o...\n";
        }
        system("pause");
        system("cls");
    }while(op != '0');
    return 0;


}


 /***************************************************************************************
 ********************************  Implementaci�n  **************************************
 ***************************************************************************************/
//*************************************************************************************
char LeerOpcion(const char * mensaje , const char *opciones )
{
    bool opValida=false;
    char op;

    do
    {
        cout<<mensaje;
        cin>>op;

        for(int i=0; opciones[i]!= 0;++i)
        {
            if(op == opciones[i])
            {
                opValida=true;
                break;
            }
        }

        if(!opValida)
            cout<<"Opci\242n no v\240lida...\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

    }while(!opValida);


    return op;
}


//*************************************************************************************
template<typename T,unsigned G>
bool RealizarOp(ArbolBA<T,G> & ab, char op)
{
    char op2;
    T aux;
    try
    {
        switch(op)
        {
            case '1': //Agregar
                cout<<"Clave a agregar: ";
                cin>>aux;
                ab.Agregar(aux);
                break;

            case '2': //Eliminar
                cout<<"Clave a eliminar: ";
                cin>>aux;
                return ab.Eliminar(aux);
                break;

            case '3': //Buscar
                cout<<"Clave a buscar: ";
                cin>>aux;
                cout<<"El nodo "<<(ab.Buscar(aux)? "SI" : "NO" )<<" se encuentra";
                break;

            case '4': //N�mero de nodos
                cout<<"El arbol tiene : "<<ab.NumeroDeClaves()<<" claves";
                break;


            case '5': // Vaciar
                op2=LeerOpcion("\250Seguro que dese\240 borrar el arbol?: Si(S),No(N): ","SNsn");
                if(op2 == 'S' || op2=='s')  return ab.Vaciar();
                else return false;
                break;

            case '6': // Imprimir
                op2=LeerOpcion("Criterio para imprimir: Ascendente(A), Descendente(D), PorNivel(N)","ADN");
                switch(op2)
                {
                    case 'A':
                        ab.Imprimir(ASCENDENTE);
                        break;
                    case 'D':
                        ab.Imprimir(DESCENDENTE);
                        break;
                    case 'N':
                        ab.Imprimir(PORNIVEL);
                        break;
                }
                break;

            case '7': // Imprimir
                cout<<"Original:\n";
                cout<<ab;
                cout<<"Copia:\n";
                ArbolBA<T,G> copia;
                copia =ab;
                cout<<copia;
                copia.Vaciar();

                cout<<'\n'<<ab<<'\n';
                cout<<"La copia ya no existe, y el arbol oriinal sigue intancto, \255 Asombroso !";

                break;
        }
    }
    catch(exception & e)
    {
        cout<<"Algo fuera de mis limites acaba de pasar, posiblemente error "<<
                "al asignar la memoria: "<<e.what()<<endl;
        return false;
    }
    return true;
}


//*************************************************************************************
void ImprMenu()
{
    cout<<"\nMenu:\n";
    cout<<"Agregar clave: 1\n";
    cout<<"Eliminar clave: 2\n";
    cout<<"Buscar clave : 3\n";
    cout<<"Obtener n\243mero de claves : 4\n";
    cout<<"Vaciar arbol: 5\n";
    cout<<"Imprimir arbol : 6\n";
    cout<<"Crear una copia del arbol: 7\n";
    cout<<"Cambiar tipo de lista: c\n";
    cout<<"Salir: 0\n";
}
