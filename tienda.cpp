/*
Juanpablo Escobar
Carlos Ito
2/12/22
.cpp de la clase Tienda
*/

#include "tienda.h"
#include <fstream>
#include <typeinfo>

//Constructor vacio
Tienda :: Tienda(){
    identificadorT = "a";
    nombreT = "a";
    direccionT = "a";
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

//Constructor que recibe valores
Tienda :: Tienda(string aIdentificadorT, string aNombreT, string aDireccionT){
    identificadorT = aIdentificadorT;
    nombreT = aNombreT;
    direccionT = aDireccionT;
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    ingresoDiarioT = 0;
}

//Destructor
Tienda :: ~Tienda(){};

//get para identificador
string Tienda :: getIdentificadorT(){
    return identificadorT;
}

//get para nombre
string Tienda :: getNombreT(){
    return nombreT;
}

//get para direccion
string Tienda :: getDireccionT(){
    return direccionT;
}

//get para cantidad de productos
int Tienda :: getCantidadProductosT(){
    return cantidadProductosT;
}

//get para cantidad de clientes
int Tienda :: getCantidadClientesT(){
    return cantidadClientesT;
}

//get para ingreso diario
double Tienda :: getIngresoDiarioT(){
    return ingresoDiarioT;
}

//set para identificador
void Tienda :: setIdentificadorT(string aIdentificadorT){
    identificadorT = aIdentificadorT;
}

//set para nombre
void Tienda :: setNombreT(string aNombreT){
    nombreT = aNombreT;
}

//set para direccion
void Tienda :: setDireccionT(string aDireccionT){
    direccionT = aDireccionT;
}

//set para cantidad de productos
void Tienda :: setCantidadProductosT(int aCantidadProductosT){
    cantidadProductosT = aCantidadProductosT;
}

//set para cantidad de clientes
void Tienda :: setCantidadClientesT(int aCantidadClientesT){
    cantidadClientesT = aCantidadClientesT;
}

//set para ingreso diario
void Tienda :: setIngresoDiarioT(double aIngresoDiarioT){
    ingresoDiarioT = aIngresoDiarioT;
}

//funcion para imprimir tienda
void Tienda :: imprimirTienda(){
    cout << "tienda" << endl;
    cout << identificadorT << endl << nombreT << endl << direccionT << endl << cantidadProductosT << endl << cantidadClientesT << endl << ingresoDiarioT << endl;
    for(int i=0; i<P; i++)
        productosT[i].imprimirProducto();
    for(int i=0; i<C; i++)
        clientesT[i].imprimirCliente();
}

//funcion para imprimir productos
void Tienda :: imprimirProductos(){
    for(int i=0; i<P; i++)
        productosT[i].imprimirProducto();
}

//funcion para imprimir clientes
void Tienda :: imprimirClientes(){
    for(int i=0; i<C; i++)
        clientesT[i].imprimirCliente();
}

//funcion para agregar productos por archivo
int Tienda :: agregarLosProductos(){
    string nombreArchivo;
    cout << "*********************************************************************\n";
    cout << "Agregando Productos Por Archivo\n";
    cout << "*********************************************************************\n";
    //pide el nombre del archivo que contiene los productos
    cout << "Introduzca el nombre del archivo: ";
    cin >> nombreArchivo;
    ifstream miArchivo;
    miArchivo.open(nombreArchivo.c_str(), ios::out | ios::in);
    //verifica que el archivo exista
    if (!miArchivo){
        cout<<"\nEl archivo no existe\n";
        return 1;
    }
    else{
        //agrega los productos
        cout<<"\nSe agregaron los productos\n";
        string clave, nombre;
        int categoria, cantidad , i = 0;
        float precio;
        while (!miArchivo.eof() && i < P){
            miArchivo >> clave >> nombre >> categoria >> precio >> cantidad;
            productosT[i++].setProducto(clave, nombre, categoria, precio, cantidad);
            //sumamos 1 por cada producto agregado en la tienda
            cantidadProductosT = cantidadProductosT + 1;
        }
        return 0;
    }
}

//funcion para agregar productos uno a uno
void Tienda :: agregarElProducto(){
    int a,d,f;
    string b,c;
    float e;
    cout << "*********************************************************************\n";
    cout << "Nuevo Producto\n";
    cout << "*********************************************************************\n";
    //pide datos del producto
    cout << "Indice: ";
    cin >> a;
    cout << "Clave: ";
    cin >> b;
    cout << "Nombre: ";
    cin >> c;
    cout << "Categoria: ";
    cin >> d;
    cout << "Precio: ";
    cin >> e;
    cout << "Cantidad: ";
    cin >> f;
    //verifica que el indice ingresado sea valido y agrega el producto
    if (a >= 0 && a <= P){
        productosT[a].setProducto(b,c,d,e,f);
        //sumamos 1 a la cantidad de productos en la tienda
        cantidadProductosT = cantidadProductosT + 1;
    }
    else
        cout << "INGRESE UN INDICE VALIDO\n";
}

void Tienda::agregarCliente() {
    int indice;
    string id, nombre, correo, telefono;

    cout << "Ingrese el índice (0-" << C-1 << "): "; cin >> indice;
    cout << "Identificador: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;
    cout << "Correo: "; cin >> correo;
    cout << "Teléfono: "; cin >> telefono;

    if (indice >= 0 && indice < C) {
        clientesT[indice].setCliente(id, nombre, correo, telefono);
        cantidadClientesT++;
        
        // Confirmation message
        cout << "Cliente registrado:\n";
        cout << "Índice: " << indice << "\n";
        cout << "ID: " << clientesT[indice].getIdentificadorC() << "\n";

    } else {
        cout << "Índice inválido.\n";
    }
}

//funcion para agregar productos al carrito
int Tienda :: llenarCarrito(){
    string a, c, f;
    int b, d, e = 0, g, h, j, k;
    cout << "*********************************************************************\n";
    cout << "Llenando Carrito\n";
    cout << "*********************************************************************\n";
    //pide id del cliente
    cout << "Identificador: ";
    cin >> a;
    //verifica si el id coincide con alguno de los clientes registrados
    for(int i=0; i<C; i++)
        if (a == clientesT[i].getIdentificadorC()){
            h = i;
            //comienza un loop para que la accion se repita hasta que el cliente decida salir
            while(e==0){
                cout << "*********************************************************************\n";
                cout << "1) Frutas y verduras\n" << "2) Electrodomésticos\n" << "3) Abarrotes\n" << "4) Higiene personal\n" << "5) Jardinería\n" << "6) Generar Ticket\n" << "7) Salir\n";
                cout << "*********************************************************************\n";
                //pide una categoria
                cout << "Selecciona Una Categoria: ";
                cin >> b;
                    //si el indice coincide con alguna de las categorias de productos
                    if (b >= 1 && b <= 5){
                        for (int i=0; i<P; i++)
                            //imprime los productos de la tienda que tengan el valor de la categoria escogida
                            if(productosT[i].getCategoriaP() == b)
                                productosT[i].imprimirProducto();
                                //pregunta si se desea agregar alguno de los productos al carrito, o desea regresar al menu de categorias
                                cout << "*********************************************************************\n";
                                cout << "1) Agregar producto a carrito\n" << "2) Regresar a categorias\n";
                                cout << "*********************************************************************\n";
                                cin >> k;
                                //en caso de querer agregar un producto al carrito
                                if(k==1){
                                    //pide clave y cantidad
                                    cout << "Clave del Producto: ";
                                    cin >> f;
                                    cout << "Cantidad: ";
                                    cin >> g;
                                    //por cada producto en la tienda
                                    for (int i=0; i<P; i++)
                                        //si la clave coincide
                                        if(productosT[i].getClaveT() == f){
                                            //si la cantidad que se quiere comprar es mayor a 0
                                            if(g > 0){
                                                //si la cantidad que se desea comprar esta disponible en la tienda
                                                if(g <= productosT[i].getCantidadP()){
                                                    //se agrega el producto a l carrito
                                                    clientesT[h].agregarProducto(j, productosT[i].getClaveT(), productosT[i].getNombreP(), productosT[i].getCategoriaP(), productosT[i].getPrecioP() ,g);
                                                    //se le resta la cantidad a la cantidad de producto disponible en la tienda
                                                    productosT[i].setCantidadP(productosT[i].getCantidadP() - g);
                                                    //se suma un indice al carrito del cliente para que si se agregan mas productos, no reescriban los ya ingresados en el carrito
                                                    j++;
                                                    //imprime cliente para visualizar el carrito
                                                    clientesT[h].imprimirCliente();
                                                    //imprime el producto de la tienda actualizado para poder confirmar la cantidad que quedan en tienda
                                                    productosT[i].imprimirProducto();
                                                }
                                                else
                                                    //en caso de no haber suficiente cantidad en tienda
                                                    cout << "No hay suficientes productos en la tienda\n";
                                            }
                                            else
                                                //en caso de que se ingrese un numero invalido
                                                cout << "La cantidad debe de ser mayor a cero\n";
                                        }
                                }
                    }
                    //para generar un ticket
                    else if (b == 6){
                            //se calcula el total del carrito
                            clientesT[h].calcTotalC();
                            //se genera el ticket del cliente mediante su metodo generarTicket
                            clientesT[h].generarTicket();
                            //se actualiza el ingresoDiario de la tienda
                            ingresoDiarioT = ingresoDiarioT + clientesT[h].getTotalC();
                    }
                    else if (b == 7)
                        //para salir del loop
                        e = 1;
                    else
                        //en caso de que no se ingrese un indice valido
                        cout << "Ingrese un indice valido\n";
            }
            //en caso de que el indice dado no coincida con alguno de los clientes registrados en la tienda
            return 0;
        }
        else
            return 1;
}

void Tienda::cerrarOperaciones() {
    cout << "*********************************************************************\n";
    cout << "Cierre diario de operaciones\n";
    cout << "*********************************************************************\n";
    cout << "Tienda: " << nombreT << endl;
    cout << "Dirección: " << direccionT << endl;
    cout << "Total de ventas del día: $" << ingresoDiarioT << endl;
    cout << "*********************************************************************\n";
}
