#include <stdio.h>
#include "funciones.h"

int main(){
    int opcion;
    struct Usuario listaUsuarios[10];
    struct Producto listaProductos[50];
    struct Registro_Ventas listaVentas[50];

    
    while(opcion!=0){
      printf("Menú:\n");
      printf("1.-ADMINISTRADOR\n");
      printf("2.-BODEGUERO\n");
      printf("3.-VENDEDOR\n");
      printf("0.-SALIR\n");
      printf("Ingrese una opción: \n");
      scanf("%d", &opcion);
      
    switch(opcion){
        case 1:
            printf("Menú administrador: \n");
            printf("1) Registrar usuario \n");
            printf("2) Actualizar usuario \n");
            printf("Ingrese una opción: \n");
            scanf("%d", &opcion);

            if (opcion == 1){
              registrarUsuario(listaUsuarios);
            }

            if (opcion == 2){
              actualizarUsuario(listaUsuarios);
            }
            
            break;
      
        case 2:
            printf("Menú bodeguero: \n");
            printf("1) Registrar producto \n");
            printf("2) Actualizar producto \n");
            printf("Ingrese una opción: \n");
            scanf("%d", &opcion);

            if (opcion == 1){
              registrarProducto(listaProductos);
            }

            if (opcion == 2){
              actualizarProductos(listaProductos);
            }
      
            break;

        case 3:
            printf("Menú vendedor: \n");
            printf("1) Vender producto \n");
            printf("Ingrese una opción: \n");
            scanf("%d", &opcion);
          
            if (opcion == 1){
              venderProducto(listaProductos,listaVentas);
            }
          
            break;
        default :
            printf("Opción no válida. Por favor, escoga una de las opciones mostradas");
    }
    }
    return 0;
}

