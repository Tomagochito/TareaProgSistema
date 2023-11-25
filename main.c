#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion;
  int rolInt = 0;
    struct Usuario listaUsuarios[10];
    struct Producto listaProductos[50];
    struct Registro_Ventas listaVentas[50];
    int salir = 0;
  char nombre[10];
  char clave[10];
  char rolEncontrado [15];

  printf("Bienvenido al Sistema!\n");
  do {
        printf("Porfavor Ingrese sus credenciales: \n");
        printf("Ingrese su nombre: ");
        scanf("%9s", nombre);

        printf("Ingrese su clave: ");
        scanf("%9s", clave);
        strcpy(rolEncontrado, validarUsuario(nombre, clave));
        if(rolEncontrado[0] == '\0'){
          printf("Credenciales incorrectas, vuelva a intentarlo: \n");
        }
  }while(rolEncontrado[0] == '\0') ;

        if (strcmp(rolEncontrado, "Administrador") == 0) {
            rolInt = 1;
        } else if (strcmp(rolEncontrado, "Bodeguero") == 0) {
            rolInt = 2;
        } else if (strcmp(rolEncontrado, "Vendedor") == 0) {
            rolInt = 3;
        }

        switch (rolInt) {
            case 1:
                printf("Menú administrador: \n");
                printf("1) Registrar usuario \n");
                printf("2) Actualizar usuario \n");
               printf("3) Finalizar\n");
                printf("Ingrese una opción: \n");
                scanf("%d", &opcion);

                if (opcion == 1) {
                    registrarUsuario();
                } else if (opcion == 2) {
                    actualizarUsuario(listaUsuarios);
                } else if (opcion ==3){
                     salir = 1;
                } else {
                    printf("Opción no válida.\n");
                }

                break;

            case 2:
                printf("Menú bodeguero: \n");
                printf("1) Registrar producto \n");
                printf("2) Actualizar producto \n");
                printf("Ingrese una opción: \n");
                scanf("%d", &opcion);

                if (opcion == 1) {
                    registrarProducto();
                } else if (opcion == 2) {
                    actualizarProducto();
                } else {
                    printf("Opción no válida.\n");
                }

                break;

            case 3:
                printf("Menú vendedor: \n");
                printf("1) Vender producto \n");
                printf("Ingrese una opción: \n");
                scanf("%d", &opcion);

                if (opcion == 1) {
                    venderProducto(listaProductos, listaVentas);
                } else {
                    printf("Opción no válida.\n");
                }

                break;

            default:
                printf("Opción no válida. Por favor, escoge una de las opciones mostradas\n");
        }
    

    printf("Proceso completado.\n");
    return 0;
}
