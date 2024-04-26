#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

    char *buffer, **listaNombres;
    int cantidadNombres;

    // Solicitud de la cantidad de nombres que ingresara el usuario
    printf("Ingrese la cantidad de nombres que desea ingresar: ");
    scanf("%d", &cantidadNombres);
    fflush(stdin);
    
    //reserva de memoria dinamica buffer y listaNombres
    buffer = malloc(100 * (sizeof(char)));
    listaNombres = malloc(cantidadNombres *(sizeof(char*)));

    //solicitud de nombres
    for(int i =0; i < cantidadNombres; i++)
    {
        printf("Ingrese  nombre: ");
        gets(buffer);
        
        //reserva de memoria dinamica nombres
        listaNombres[i] = malloc((strlen(buffer)+1) * (sizeof(char)));
        
        //copiar nombres
        strcpy(listaNombres[i],buffer);
        
        
    }
    //mostrar lista de nombres
    printf("\nNombres ingresados:\n");
    for(int j =0; j < cantidadNombres; j ++)
    {
        printf("%s\n",listaNombres[j]);
    }

    //liberar memoria
    for(int i=0; i<5; i++)
    {
        free(listaNombres[i]);
    }
    free(listaNombres);
    free(buffer);

    return 0;
}
