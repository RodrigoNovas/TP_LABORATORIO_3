#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define RET_OK 1
#define RET_ERR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;

    char id[4];
    char ht[4];
    char sueldo[4];
    char name[20];
    int line = 0;

    if(pFile != NULL)
    {
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,ht,sueldo);

            if(r==4 && line > 0)
            {
                Employee* e = employee_new();
                e->id = atoi(id);
                strcpy(e->nombre, name);
                e->horasTrabajadas = atoi(ht);
                e->sueldo = atoi(sueldo);
                ll_add(pArrayListEmployee, e);
                line++;
            }
            else if(line == 0)
            {
                line++;
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));
        fclose(pFile);
        r = RET_OK;
    }
    else
    {
        printf("Archivo vacio\n");
    }
    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;

    //int id, ht, sueldo;
    //char name[20];
    int line = 0;

    if(pFile != NULL)
    {
        do
        {

                Employee* e = employee_new();
                fread(e, sizeof(Employee), 1, pFile);
                //e->id = id;
                //strcpy(e->nombre, name);
                //e->horasTrabajadas = ht;
                //e->sueldo = sueldo;
                ll_add(pArrayListEmployee, e);
                line++;

        }
        while(!feof(pFile));
        fclose(pFile);
        r = RET_OK;
    }
    return r;
}
