/*
Juanpablo Escobar
Carlos Ito
2/12/22
.cpp de la clase Producto
*/

#include "producto.h"

//Constructor vacio
Producto :: Producto(){
    claveT = "";
    nombreP = "";
    categoriaP = 0;
    precioP= 0;
    cantidadP = 0;
}

//Constructor que recibe valores
Producto :: Producto(string aClaveT, string aNombreP, int aCategoriaP, float aPrecioP, int aCantidadP){
    claveT = aClaveT;
    nombreP = aNombreP;
    categoriaP = aCategoriaP;
    precioP = aPrecioP;
    cantidadP = aCantidadP;
}

//Destructor
Producto :: ~Producto(){};

//get para clave
string Producto :: getClaveT(){
    return claveT;
}

//get para nombre
string Producto :: getNombreP(){
    return nombreP;
}

//get para categoria
int Producto :: getCategoriaP(){
    return categoriaP;
}

//get para precio
float Producto :: getPrecioP(){
    return precioP;
}

//get para cantidad
int Producto :: getCantidadP(){
    return cantidadP;
}

//set para clave
void Producto :: setClaveT(string aClaveT){
    claveT = aClaveT;
}

//set para nombre
void Producto :: setNombreP(string aNombreP){
    nombreP = aNombreP;
}

//set para categoria
void Producto :: setCategoriaP(int aCategoriaP){
    categoriaP = aCategoriaP;
}

//set para precio
void Producto :: setPrecioP(float aPrecioP){
    precioP = aPrecioP;
}

//set para cantidad
void Producto :: setCantidadP(int aCantidadP){
    cantidadP = aCantidadP;
}

//funcion para actualizar valores del producto
void Producto :: setProducto(string aClaveT, string aNombreP, int aCategoriaP, float aPrecioP, int aCantidadP){
    claveT = aClaveT;
    nombreP = aNombreP;
    categoriaP = aCategoriaP;
    precioP = aPrecioP;
    cantidadP = aCantidadP;
}

//funcion para imprimir producto
void Producto:: imprimirProducto(){
    cout << "*********************************************************************\n";
    cout << "producto" << endl;
    cout << claveT << endl << nombreP << endl << categoriaP << endl << precioP << endl << cantidadP << endl;
}
