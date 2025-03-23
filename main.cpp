/*
Juanpablo Escobar
Carlos Ito
2/12/22
Main (Aplicacion con menu)
*/

#include <iostream>
#include <fstream>

#include "tienda.cpp"
using namespace std;

int main(){
    cout << "*********************************************************************\n";
    cout << "Bienvenid@, por favor introduzca la informacion de la tienda\n";
    cout << "*********************************************************************\n";
    //pide los valores de la tienda y creo un objeto de tipo Tienda
    string identificador, nombre, direccion, nombreArchivo;
    cout << "ID: ";
    cin >> identificador;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Direccion: ";
    cin >> direccion;
    Tienda tienda(identificador, nombre, direccion);

    int n, i = 0, j = 0;

    while(i==0){
        //muestra menu y pide un valor
        cout << "*********************************************************************\n";
        cout << "1) Agregar Productos Desde Archivo\n" << "2) Agregar Productos Uno a Uno\n" << "3) Agregar Clientes\n" << "4) Comprar Productos\n" << "5) Realizar Cierre del Dia\n" << "6) Salir\n";
        cout << "*********************************************************************\n";
        cin >> n;
        //ingresamos el valor en nuestro switch
        switch (n)
        {
        case 1:
        //Agregar Productos Desde Archivo
            //para que la funcion solo se pueda llamar una vez ponemos una condicional
            if(j==0){
                //en caso de que sea la primera vez, se ejecuta el metodo y se le suma 1 a la variable
                if(tienda.agregarLosProductos() == 0)
                //en cso de que el archivo se haya encontrado y los productos se agreguen
                    j++;
            }
            else
                //en caso de que ya se haya llamado una vez
                cout << "Ya Ingresaste un Archivo\n";
            //imprimimos productos para verificar que se hayan agregado de manera correcta
            tienda.imprimirProductos();
            break;
        case 2:
        //Agregar Productos Uno a Uno
            //llamamos el metodo para agregar productos uno a uno
            tienda.agregarElProducto();
            //imprimimos los productos para verificar que haya funcionado
            tienda.imprimirProductos();
            break;
        case 3:
        //Agregar Clientes
            //llamamos el metodo para agregar un cliente
            tienda.agregarCliente();
            //imprimimos los clientes para verficar que se haya ejecutado de manera correcta
            tienda.imprimirClientes();
            break;
        case 4:
        //Comprar Productos
            //en caso de que el id ingresado en el metodo llenarCarrito no coincida con alguno de los id de los clientes registrados en la tienda,
            //el metodo regresara 0
            if (tienda.llenarCarrito() == 1){
                //inicia el metodo agregar cliente para que se pueda registrar
                cout << "*********************************************************************\n";
                cout << "Para comprar productos debes estar registrad@\n";
                tienda.agregarCliente();
            }
            break;
        case 5:
        //Realizar Cierre del Dia
            cout << "*********************************************************************\n";
            cout << "Total de ingresos: ";
            //los ingresos se suman en cuanto generamos un ticket en el metodo lenar carrito, por lo que en este caso solo mostramos el valor de ingreso diario
            cout << tienda.getIngresoDiarioT() << endl;
            break;
        case 6:
        //Salir
            //en caso de que se quiera salir
            cout << "Hasta Luego!!!\n";
            //cambiamos el valor para terminar con el loop
            i = 1;
            break;
        case 0:
            //este caso es solo para verificar los valores de la tienda, no es parte funcional de la aplicacion. 
            tienda.imprimirTienda();
            break;        
        default:
            //en caso de que no se ingrese un valor que coincida con alguno de los casos
            cout << "Ingresa un valor valido\n";
            break;
        }
    }
    return 0;
}