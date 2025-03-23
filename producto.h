/*
Juanpablo Escobar
Carlos Ito
2/12/22
.h de la clase Producto
*/

#ifndef Producto_h
#define Producto_h

#include <iostream>
using namespace std;

class Producto{

    private:

        //Atributos de la clase Producto
        string claveT;
        string nombreP;
        int categoriaP;
        float precioP;
        int cantidadP;

    public:

        //Constructores y destructor de la clase producto
        Producto();
        Producto(string, string, int, float, int);
        ~Producto();
        //Metodos get de la clase producto
        string getClaveT();
        string getNombreP();
        int getCategoriaP();
        float getPrecioP();
        int getCantidadP();
        //Metodos set de la clase producto
        void setClaveT(string);
        void setNombreP(string);
        void setCategoriaP(int);
        void setPrecioP(float);
        void setCantidadP(int);
        //Metodo set para actualizar todos los valores de producto
        void setProducto(string, string, int, float, int);
        //Metodo para imprimir producto
        void imprimirProducto();

};

#endif