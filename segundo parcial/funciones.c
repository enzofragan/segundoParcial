#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

eEmpleados* new_empleado()
{
    eEmpleados* aux;

    aux=(eEmpleados*) malloc(sizeof(eEmpleados));

    return aux;
}

int setId(eEmpleados* this,int id)
{
    int seteo=-1;
    if(this!=NULL && id>0)
    {
        this->id=id;
        seteo=0;
    }
    return seteo;
}

int getId(eEmpleados* this)
{
    int id;
    if(this!=NULL)
    {
        id=this->id;
    }
    return id;
}

int setNombre(eEmpleados* this,char* nombre)
{
    int seteo=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        seteo=0;
    }
    return seteo;
}

char* getNombre(eEmpleados* this)
{

    char* nombre=NULL;
    if(this!=NULL)
    {
        nombre=this->nombre;
    }
    return nombre;
}

int setSueldo(eEmpleados* this,int sueldo)
{
    int seteo=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        seteo=0;
    }
    return seteo;
}

int getSueldo(eEmpleados* this)
{
    int sueldo;
    if(this!=NULL)
    {
        sueldo=this->sueldo;
    }
    return sueldo;
}

int setEdad(eEmpleados* this,int edad)
{
    int seteo=-1;
    if(this!=NULL && edad>18 && edad<=70)
    {
        this->edad=edad;
        seteo=0;
    }
    return seteo;
}

int getEdad(eEmpleados* this)
{
    int edad;
    if(this!=NULL)
    {
        edad=this->edad;
    }
    return edad;
}

int setProfecion(eEmpleados* this,char* profecion)
{
    int seteo=-1;
    if(this!=NULL && profecion!=NULL)
    {
        strcpy(this->profecion,profecion);
        seteo=0;
    }
    return seteo;
}

char* getProfecion(eEmpleados* this)
{

    char* profecion=NULL;
    if(this!=NULL)
    {
        profecion=this->profecion;
    }
    return profecion;
}

int parser(ArrayList* this)
{
    char nombre[50];
    char id[50];
    char sueldo[50];
    char edad[50];
    char profecion[50];
    eEmpleados* aux;
    int leer;
    FILE* archivo;
    int parse=-1;

    archivo=fopen("data.csv","r");

    if(archivo!=NULL)
    {
        printf("hola");
        do
        {
            leer=fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,sueldo,edad,profecion);
            if(leer==5)
            {
                aux=new_empleado();
                if(aux!=NULL)
                {
                    setNombre(aux,nombre);
                    setId(aux,atoi(id));
                    setSueldo(aux,atoi(sueldo));
                    setEdad(aux,atoi(edad));
                    setProfecion(aux,profecion);
                    this->add(this,aux);
                }
            }
        }while(!feof(archivo));

        parse=0;
    }
    fclose(archivo);

    return parse;
}

int mostar(eEmpleados* this)
{
    int mostro=-1;
    if(this!=NULL)
    {
        printf("%d--%s--%d--%d--%s\n",getId(this),getNombre(this),getSueldo(this),getEdad(this),getProfecion(this));
        mostro=0;
    }
    return mostro;
}

int mostrarLista(ArrayList* listado)
{
    int listo=-1;
    int i;
    int len;
    eEmpleados* empleado;
    if(listado!=NULL)
    {
        len=listado->len(listado);
        for(i=0;i<len;i++)
        {
            empleado= (eEmpleados*) listado->get(listado,i);
            mostar(empleado);
        }
        listo=0;
    }
    return listo;
}
