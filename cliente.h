/*
Juanpablo Escobar
Carlos Ito
2/12/22
.h de la clase Cliente
*/

#ifndef Cliente_h
#define Cliente_h

#include <iostream>
#include "producto.cpp"
using namespace std;

//constante para numero de productos en la lista de carrito
const int A = 3;

class Cliente{

    private:
    
        //Atributos de la clase Cliente
        string identificadorC;
        string nombreC;
        string correoElectronicoC;
        string telefonoC;
        Producto carritoC[A];
        double totalC;

    public:

        //Constructores y destructor de la clase cliente
        Cliente();
        Cliente(string, string, string, string);
        ~Cliente();
        //Metodos get para la clase cliente
        string getIdentificadorC();
        string getNombreC();
        string getCorreoElectronicoC();
        string getTelefonoC();
        double getTotalC();
        //Metodos set para la clase cliente
        void setIdentificadorC(string);
        void setNombreC(string);
        void setCorreoElectronicoC(string);
        void setTelefonoC(string);
        void setTotalC(double);
        //Metodo para calcular total
        void calcTotalC();
        //Metodo para agregar producto a carrito
        void agregarProducto(int, string, string, int, float, int);
        //Metodo para generar el ticket de compras del cliente
        void generarTicket();
        //Metodo para actualizar los valores de un cliente
        void setCliente(string,string,string,string);
        //Metodo para imprimir Cliente
        void imprimirCliente();
};

#endif