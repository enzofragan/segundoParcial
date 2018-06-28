#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    int id;
    char nombre[20];
    int sueldo;
    int edad;
    char profecion[20];

}eEmpleados;

#endif // FUNCIONES_H_INCLUDED
eEmpleados* new_empleado();

int setId(eEmpleados*,int);
int getId(eEmpleados*);

int setNombre(eEmpleados*,char*);
char* getNombre(eEmpleados*);

int setSueldo(eEmpleados*,int);
int getSueldo(eEmpleados*);

int setEdad(eEmpleados*,int);
int getEdad(eEmpleados*);

int setProfecion(eEmpleados*,char*);
char* getProfecion(eEmpleados*);

int parser(ArrayList* this);

int mostar(eEmpleados* );

int mostrarLista(ArrayList* listado);
