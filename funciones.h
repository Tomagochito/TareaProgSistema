#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Usuario{
    char nombre_usuario[10];
    char password[10];
    enum rol{Administrador, Bodeguero, Vendedor} rolUser;
};

struct Producto{
    char nombre[50];
    char categoria[50];
    char marca[50];
    char bodega[50];
    int codigo;
    int stock;
    double precio_compra;
};

struct Registro_Ventas{
    char local[50];
    char vendedor[50];
    char fecha_venta[50];
    double precio_venta;
};

char* validarUsuario(char nombre[], char clave[]);
void registrarUsuario();
void actualizarUsuario();
void registrarProducto();
void actualizarProducto();
void venderProducto(struct Producto produtos[],struct Registro_Ventas rventas[]);

#endif
