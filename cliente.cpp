/*
Juanpablo Escobar
Carlos Ito
2/12/22
.cpp de la clase Cliente
*/

#include "cliente.h"

//Constructor vacio
Cliente :: Cliente(){
    identificadorC = "";
    nombreC = "";
    correoElectronicoC = "";
    telefonoC = "";
    totalC = 0;
}

//Constructor que recibe valores
Cliente :: Cliente(string aIdentificadorC, string aNombreC, string aCorreoElectronicoC, string aTelefonoC){
    identificadorC = aIdentificadorC;
    nombreC = aNombreC;
    correoElectronicoC = aCorreoElectronicoC;
    telefonoC = aTelefonoC;
    totalC = 0;
}

//Destructor
Cliente :: ~Cliente(){};

//get para identificador
string Cliente :: getIdentificadorC(){
    return identificadorC;
}

//get para nombre
string Cliente :: getNombreC(){
    return nombreC;
}

//get para correo electronico
string Cliente :: getCorreoElectronicoC(){
    return correoElectronicoC;
}

//get para telefono
string Cliente :: getTelefonoC(){
    return telefonoC;
}

//get para total
double Cliente :: getTotalC(){
    return totalC;
}

//set para identificador
void Cliente :: setIdentificadorC(string aIdentificadorC){
    identificadorC = aIdentificadorC;
}

//set para nombre
void Cliente :: setNombreC(string aNombreC){
    nombreC = aNombreC;
}

//set para correo electronico
void Cliente :: setCorreoElectronicoC(string aCorreoElectronicoC){
    correoElectronicoC = aCorreoElectronicoC;
}

//set para telefono
void Cliente :: setTelefonoC(string aTelefonoC){
    telefonoC = aTelefonoC;
}

//set para total
void Cliente :: setTotalC(double aTotalC){
    totalC = aTotalC;
}

//funcion para calcular el total de los productos en el carrtio
void Cliente :: calcTotalC(){
    double suma = 0;
    for(int i=0; i<A; i++)
        suma = suma + carritoC[i].getCantidadP() * carritoC[i].getPrecioP();
    totalC = suma;
    cout << suma << endl;
}

//funcion para agregar un producto, recibe un indice y los valores del producto
void Cliente :: agregarProducto(int aIndice, string aClaveT, string aNombreP, int aCategoriaP, float aPrecioP, int aCantidadP){
    if(aIndice >= 0 && aIndice < A){
        carritoC[aIndice].setProducto(aClaveT, aNombreP, aCategoriaP, aPrecioP, aCantidadP);
    }
    else
        cout << "INGRESE UN INDICE VALIDO\n";
}

//funcion para darle valores a cliente
void Cliente :: setCliente(string aIdentificadorC, string aNombreC, string aCorreoElectronicoC, string aTelefonoC){
    identificadorC = aIdentificadorC;
    nombreC = aNombreC;
    correoElectronicoC = aCorreoElectronicoC;
    telefonoC = aTelefonoC;
}

//funcion para generar el ticket de compra del cliente
void Cliente :: generarTicket(){
    cout << "*********************************************************************\n";
    cout << "Ticket de Compra\n";
    cout << "*********************************************************************\n";
    cout << "Cliente: \n";
    cout << identificadorC << endl;
    cout << "Productos: \n";
    for(int i=0; i<A; i++)
        carritoC[i].imprimirProducto();
    cout << "*********************************************************************\n";
    cout << "Total: " << totalC << endl;

}

//funcion para imprimir cliente
void Cliente:: imprimirCliente(){
    cout << "*********************************************************************\n";
    cout << "cliente" << endl;
    cout << identificadorC << endl << nombreC << endl << correoElectronicoC << endl << telefonoC << endl << totalC << endl;
    for(int i=0; i<A; i++)
        carritoC[i].imprimirProducto();
}
