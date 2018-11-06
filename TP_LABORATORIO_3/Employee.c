#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#define RET_OK 1
#define RET_ERR 0

Employee* employee_new()
{
    Employee* e = (Employee*) malloc(sizeof(Employee));

    e->id = 0;
    strcpy(e->nombre, "");
    e->horasTrabajadas = 0;
    e->sueldo = 0;

    return e;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* e = (Employee*) malloc(sizeof(Employee));

    e->id = *idStr;
    strcpy(e->nombre, nombreStr);
    e->horasTrabajadas = *horasTrabajadasStr;
    e->sueldo = 0;

    return e;
}
void employee_delete()
{

}

int employee_setId(Employee* this,int id)
{
    int r = RET_ERR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        r = RET_OK;
    }

    return r;
}

int employee_getId(Employee* this,int* id)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        *id = this->id ;
        r = RET_OK;
    }

    return r;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        r = RET_OK;
    }

    return r;
}

int employee_getNombre(Employee* p,char* nombre)
{
    int r = RET_ERR;

    if(p != NULL)
    {
        strcpy(nombre, p->nombre);
        r = RET_OK;
    }

    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        r = RET_OK;
    }

    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        r = RET_OK;
    }

    return r;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        r = RET_OK;
    }

    return r;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int r = RET_ERR;

    if(this != NULL)
    {
        *sueldo = this->sueldo ;
        r = RET_OK;
    }

    return r;
}

void employee_show(Employee* this)
{
    if(this != NULL)
    {
        printf("%4d %20s %4d %4d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}
