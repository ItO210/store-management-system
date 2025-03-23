/*
Juanpablo Escobar
Carlos Ito
2/12/22
.h de la clase Tienda
*/

#ifndef Tienda_h
#define Tienda_h

#include <iostream>
#include "cliente.cpp"
using namespace std;

//constante para numero de productos en la lista de productos
const int P = 5;
//constante para cantidad de clientes en la lista de clientes
const int C = 3;

class Tienda{

    private:
    
    //Atributos de la clase tienda
    string identificadorT;
    string nombreT;
    string direccionT;
    int cantidadProductosT;
    int cantidadClientesT;
    Producto productosT[P];
    Cliente clientesT[C];
    double ingresoDiarioT;


    public:

        //Constructores y destructor de la clase Tienda
        Tienda();
        Tienda(string, string, string);
        ~Tienda();
        //Metodos get de la clase Tienda
        string getIdentificadorT();
        string getNombreT();
        string getDireccionT();
        int getCantidadProductosT();
        int getCantidadClientesT();
        double getIngresoDiarioT();
        //Metodos set de la clase Tienda
        void setIdentificadorT(string);
        void setNombreT(string);
        void setDireccionT(string);
        void setCantidadProductosT(int);
        void setCantidadClientesT(int);
        void setIngresoDiarioT(double);
        //Metodo para imprimir tienda
        void imprimirTienda();
        void imprimirProductos();
        void imprimirClientes();
        //Metodo para agregar productos mediante un archivo
        int agregarLosProductos();
        //Metodo para agregar productos de manera manual
        void agregarElProducto();
        //Metodo para agregar cliente
        void agregarCliente();
        //Metodo para comprar productos
        int llenarCarrito();
        //Metodo para imprimir ganancias del dia
        void cerrarOperaciones();

};

#endif