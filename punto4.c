#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algun valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamanioo de este arreglo depende de la variable
                        // "CantidadProductosAPedir"
}typedef Cliente;

void cargarClientes(Cliente *clientes, int cantidadClientes, char *TiposProductos[]);
void mostrarClientes(Cliente *clientes, int cantidadClientes, char *TiposProductos[]);
float calcularCostoTotalProducto(Producto producto);

int main()
{

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantidadClientes;
    Cliente *clientes;
   

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    fflush(stdin);

    clientes = malloc(cantidadClientes * (sizeof(Cliente)));

    cargarClientes(clientes, cantidadClientes,TiposProductos);
    mostrarClientes(clientes, cantidadClientes,TiposProductos);
    
    
    //liberar memoria dinamica
    free(clientes);
    return 0;
}

void cargarClientes(Cliente *clientes, int cantidadClientes,char *TiposProductos[])
{
    srand(time(NULL));
    char nombre[100];
    printf("\n-------------CARGA DE CLIENTES------------\n");
    for(int i = 0; i<cantidadClientes; i++)
    {
        clientes->ClienteID = i + 1;
        printf("\nNombre del cliente: ");
        gets(nombre);
        //reserva memoria dinamica nombre
        clientes->NombreCliente = malloc((strlen(nombre) + 1) * (sizeof(char)));
        strcpy(clientes->NombreCliente,nombre);
        //cantidad de productos aleatorios
        clientes->CantidadProductosAPedir = rand() % 4 + 1;
        //reserva de memoria dinamica Productos
        clientes->Productos = malloc(clientes->CantidadProductosAPedir * (sizeof(Producto)));
        for(int j =0; j < clientes->CantidadProductosAPedir; j ++)
        {
            clientes->Productos[j].ProductoID = j + 1;
    
            clientes->Productos[j].Cantidad = rand() % 9 + 1;
            //valor aleatorio del tipo producto
            clientes->Productos[j].TipoProducto = malloc(5 * (sizeof(char)));
            strcpy(clientes->Productos[j].TipoProducto,TiposProductos[j]);
            clientes->Productos[j].PrecioUnitario = rand() % 90 + 10;
            //clientes ++;
        }
        clientes ++;

    }
}

void mostrarClientes(Cliente *clientes, int cantidadClientes,char *TiposProductos[])
{
    int tama=3;
    printf("\n-------------MOSTRAR CLIENTES------------\n");
    for(int i= 0; i<cantidadClientes; i++)
    {
        printf("\nID del cliente: %d",clientes[i].ClienteID);
        printf("\nNombre del cliente: %s",clientes[i].NombreCliente);
        //cantidad de productos aleatorios
        printf("\nCantidad de producto a pedir: %d",clientes[i].CantidadProductosAPedir);

        float costoTotalCliente = 0.0;
        for(int j =0; j < clientes[i].CantidadProductosAPedir; j ++)
        {
            printf("\nID del producto: %d",clientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d",clientes[i].Productos[j].Cantidad);
            //valor aleatorio del tipo producto
            printf("\nTipo de producto: %s",clientes[i].Productos[j].TipoProducto);
            printf("\nPrecio unitario: %.2f",clientes[i].Productos[j].PrecioUnitario);

            float costoProducto = calcularCostoTotalProducto(clientes[i].Productos[j]);
            printf("\nCosto total del producto: %.2f", costoProducto);
            
            costoTotalCliente += costoProducto;
            
        }
        printf("\nCosto total del cliente: %.2f", costoTotalCliente);
        printf("\n--------------------------------------------\n");


    }
}

float calcularCostoTotalProducto(Producto producto) 
{
    return producto.Cantidad * producto.PrecioUnitario;
}