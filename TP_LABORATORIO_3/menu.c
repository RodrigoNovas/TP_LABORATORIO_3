#include "menu.h"

int mostrarMenu()
{
    int r;
    do
    {
        system("cls");
        printf("************************************************************************************\n");
        printf("     Menu:                                                                          \n");
        printf("     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
        printf("     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
        printf("     3. Alta de empleado                                                            \n");
        printf("     4. Modificar datos de empleado                                                 \n");
        printf("     5. Baja de empleado                                                            \n");
        printf("     6. Listar empleados                                                            \n");
        printf("     7. Ordenar empleados                                                           \n");
        printf("     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     \n");
        printf("     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).   \n");
        printf("    10. Salir                                                                       \n");
        printf("************************************************************************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int mostrarMenuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 3);

    return r;
}
