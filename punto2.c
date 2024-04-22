#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void cargarMatriz(int mtriz[5][12]);
void mostrarMatriz(int mtriz[5][12]);
void gananciaPorAnio(int mtriz[5][12], int promedio[5]);
void valorMaxim(int mtriz[5][12]);
void valorMinimo(int mtriz[5][12]);

int main()
{

    int mtriz[5][12],promedio[5];

    cargarMatriz(mtriz);
    mostrarMatriz(mtriz);
    gananciaPorAnio(mtriz,promedio);
    valorMaxim(mtriz);
    valorMinimo(mtriz);

    return 0;
}

void cargarMatriz(int mtriz[5][12])
{
    srand(time(NULL));
    for(int i=0; i < 5; i ++)
    {
        for(int j=0; j <12; j++)
        {
            mtriz[i][j] = rand() % 40 + 10;
        }
    }
}

void mostrarMatriz(int mtriz[5][12])
{
    printf("\n\n---------------VALORES CARGADOS--------------\n\n");
    for(int i=0; i < 5; i ++)
    {
        for(int j=0; j <12; j++)
        {
            printf("%d ",mtriz[i][j]);
        }
        printf("\n");
    }
}

void gananciaPorAnio(int mtriz[5][12], int promedio[5])
{
    int suma=0;
    printf("\n------------PROMEDIO POR ANIO------------\n\n");
    for(int i=0; i < 5; i ++)
    {
        for(int j=0; j <12; j++)
        {
            suma += mtriz[i][j];
        }
        promedio[i] = suma /12;

        printf("\nAño %d: %d",i +1,promedio[i]);
        suma = 0;
    }

}

void valorMaxim(int mtriz[5][12])
{
    int maximo = 0,anio,mes;
    printf("\n------------VALOR MAXIMO------------\n\n");
    for(int i=0; i < 5; i ++)
    {
        for(int j=0; j <12; j++)
        {
            if(mtriz[i][j] >= maximo)
            {
                maximo = mtriz[i][j];
                anio = i+1;
                mes = j+1;
            }
        }

    }

    printf("\nValor maximo: %d | Anio: %d | Mes: %d",maximo,anio,mes);
}

void valorMinimo(int mtriz[5][12])
{
    int minimo = 0,anio,mes;
    printf("\n------------VALOR MINIMO------------\n\n");
    for(int i=0; i < 5; i ++)
    {
        for(int j=0; j <12; j++)
        {
            if(mtriz[i][j] <= minimo || minimo ==0)
            {
                minimo = mtriz[i][j];
                anio = i+1;
                mes = j+1;
            }
        }

    }
    printf("\nValor minimo: %d | Anio: %d | Mes: %d",minimo,anio,mes);
}