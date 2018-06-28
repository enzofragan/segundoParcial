#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    int opcion;
    char seguir='s';
    ArrayList* listaEmpleados;

    listaEmpleados=al_newArrayList();

    parser(listaEmpleados);

    while(seguir=='s')
    {
        printf("1- mostrar\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                mostrarLista(listaEmpleados);
                break;
            case 6:
                seguir = 'n';
                break;
        }
        system("pause");

        system("cls");
    }
    return 0;
}
