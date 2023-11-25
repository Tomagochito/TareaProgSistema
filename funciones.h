#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Usuario{
    char nombre_usuario[10];
    char password[10];
};

struct Producto{
    char nombre[50];
    char categoria[50];
    char marca[50];
    int codigo;
    double precio_compra;
    char bodega[50];
    int stock;
};

struct Registro_Ventas{
    char local[50];
    char vendedor[50];
    char fecha_venta[50];
    double precio_venta;
};


void registrarUsuario(struct Usuario usuarios[]);
void actualizarUsuario(struct Usuario usuarios[]);
void registrarProducto(struct Producto productos[]);
void actualizarProductos(struct Producto productos[]);
void venderProducto(struct Producto produtos[],struct Registro_Ventas rventas[]);

#endif
