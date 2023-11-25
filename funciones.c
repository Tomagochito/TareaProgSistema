#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include "string.h"

void registrarUsuario() {
    struct Usuario nuevoUsuario;
    char rolchar[20];
    printf("Ingrese el nombre de usuario: \n");
    scanf("%s", nuevoUsuario.nombre_usuario);
    printf("Ingrese la clave: \n");
    scanf("%s", nuevoUsuario.password);
    printf("Escoja el rol del usuario:\n");
    printf("1. Administrador\n");
    printf("2. Bodeguero\n");
    printf("3. Vendedor\n");
    int opcion;
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
          nuevoUsuario.rolUser = Administrador;
          strcpy(rolchar, "Administrador");
          break;
      case 2:
          nuevoUsuario.rolUser = Bodeguero;
          strcpy(rolchar, "Bodeguero");
          break;
      case 3:
          nuevoUsuario.rolUser = Vendedor;
          strcpy(rolchar, "Vendedor");
          break;
      default:
          printf("Opción no válida.\n");
          return; // Salir de la función si la opción no es válida.
  }
     FILE *archivo;
    archivo = fopen("usuarios.txt", "a"); 
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    // Escribir la información del nuevo usuario al final del archivo
  fprintf(archivo, "\n%s,%s,%s", nuevoUsuario.nombre_usuario, nuevoUsuario.password, rolchar);
    fclose(archivo);
}

/*_______________________________________________________________________*/


void actualizarUsuario() {
  char nombre[10];
      printf("Ingrese el nombre de usuario a actualizar: ");
      scanf("%s", nombre);

      FILE *fp;
      fp = fopen("usuarios.txt", "r+");

      if (fp == NULL) {
          fputs("File error", stderr);
          exit(1);
      }

      char line[50];

      while (fgets(line, sizeof(line), fp) != NULL) {
          char n[10], c[10], r[20];
          sscanf(line, "%9[^,],%9[^,],%19[^\n]", n, c, r);

          if (strcmp(nombre, n) == 0) {
              printf("Usuario encontrado.\n");
              printf("1. Cambiar nombre de usuario\n");
              printf("2. Cambiar clave\n");
              printf("3. Cambiar rol\n");
              int opcion;
              printf("Seleccione una opción: ");
              scanf("%d", &opcion);

              switch (opcion) {
                  case 1:
                      printf("Ingrese el nuevo nombre de usuario: ");
                      scanf("%s", n);
                      break;
                  case 2:
                      printf("Ingrese la nueva clave: ");
                      scanf("%s", c);
                      break;
                case 3:
                printf("Escoja el nuevo rol:\n");
                printf("1. Administrador\n");
                printf("2. Bodeguero\n");
                printf("3. Vendedor\n");
                int opcionRol;
                printf("Seleccione el nuevo rol: ");
                scanf("%d", &opcionRol);

                switch (opcionRol) {
                    case 1:
                        strcpy(r, "Administrador");
                        break;
                    case 2:
                        strcpy(r, "Bodeguero");
                        break;
                    case 3:
                        strcpy(r, "Vendedor");
                        break;
                    default:
                        printf("Opción no válida para el rol.\n");
                        fclose(fp);
                        return;
                }
                break;
                  default:
                      printf("Opción no válida.\n");
              }

              // Mover el puntero de archivo hacia atrás para sobrescribir la línea
              fseek(fp, -strlen(line), SEEK_CUR);
              fprintf(fp, "%s,%s,%s\n", n, c, r);
              fflush(fp);  // Forzar la escritura de cambios en el archivo
              printf("Usuario actualizado con éxito.\n");
              break;  // Salir del bucle después de actualizar el usuario
          }
      }

      fclose(fp);
  }

char* validarUsuario(char nombre[], char clave[]) {
  FILE *fp;
  fp = fopen ( "usuarios.txt", "r" );    
  if (fp==NULL) {fputs ("File error",stderr); exit (1);}
  char line[50];
  static char rol[15];  // Almacena el resultado en un array estático para que persista después de salir de la función
  rol[0] = '\0';  // Inicializa el array como una cadena vacía

  while (fgets(line, sizeof(line), fp) != NULL) {
      // Variables temporales para almacenar los valores de la línea
      char n[10], c[10];
      char r [20] ; // Variable temporal para el rol

      // Descomponer la línea en nombre, rol y clave
      sscanf(line, "%9[^,],%9[^,],%19[^\n]", n, c, r);
      // Comparar nombre y clave
      if (strcmp(nombre, n) == 0 && strcmp(clave, c) == 0) {
          fclose(fp);
          // Convierte el rol a una cadena y copia en el array rol
          snprintf(rol, sizeof(rol), "%s", r);
          return rol;
      }
  }

  fclose(fp);

  // Usuario no encontrado, retorna una cadena vacía
  return rol;
  
}


void registrarProducto(){
  struct Producto productoNuevo;
  int ultimo=0;
  printf("Ingrese el nombre del nuevo producto: ");
  scanf("%s",productoNuevo.nombre);
  printf("Ingrese la categoria del producto: ");
  scanf( "%s", productoNuevo.categoria);
  printf("Ingrese la marca del producto: ");
  scanf( "%s", productoNuevo.marca);
  printf("Ingrese la bodega donde esta almacenado: ");
  scanf( "%s", productoNuevo.bodega);
  printf("Ingrese el codigo del producto: ");
  scanf( "%d", &productoNuevo.codigo);
  printf("Ingrese la cantidad en stock: ");
  scanf( "%d", &productoNuevo.stock);
  printf("Ingrese el precio de compra del producto: ");
  scanf( "%lf", &productoNuevo.precio_compra);


     FILE *archivo;
    archivo = fopen("productos.txt", "a"); 
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    // Escribir la información del nuevo usuario al final del archivo
  fprintf(archivo, "\n%s,%s,%s,%s,%d,%d,%lf", productoNuevo.nombre, productoNuevo.categoria, productoNuevo.marca,productoNuevo.bodega,productoNuevo.codigo,productoNuevo.stock,productoNuevo.precio_compra );
    fclose(archivo);
}


void actualizarProducto() {
    int codigo;
    printf("Ingrese el código del producto: ");
    scanf("%d", &codigo);

    FILE *archivo;
    archivo = fopen("productos.txt", "r+");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct Producto producto;
  char line[100];
  while (fgets(line, sizeof(line), archivo) != NULL) {
  char n[10], c[10], r[20];
  sscanf(line,  "%49[^,],%49[^,],%49[^,],%49[^,],%d,%d,%lf", producto.nombre, producto.categoria,
      producto.marca, producto.bodega, &producto.codigo, &producto.stock, &producto.precio_compra);
 
        if (producto.codigo == codigo) {
            printf("Producto encontrado.\n");
            int opcion;

            do {
                printf("¿Qué desea actualizar?\n");
                printf("1. Nombre del producto\n");
                printf("2. Categoría del producto\n");
                printf("3. Marca del producto\n");
                printf("4. Bodega del producto\n");
                printf("5. Codigo del producto\n");
                printf("6. Stock del producto\n");
                printf("7. Precio del producto\n");
                printf("8. Confirmar cambios\n");

                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        printf("Ingrese el nuevo nombre del producto: ");
                        scanf("%s", producto.nombre);
                        break;
                    case 2:
                        printf("Ingrese la nueva categoría del producto: ");
                        scanf("%s", producto.categoria);
                        break;
                    case 3:
                        printf("Ingrese la nueva marca del producto: ");
                        scanf("%s", producto.marca);
                        break;
                    case 4:
                        printf("Ingrese la nueva bodega del producto: ");
                        scanf("%s", producto.bodega);
                        break;
                    case 5:
                        printf("Ingrese el nuevo codigo del producto: ");
                        scanf("%d", &producto.codigo);
                        break;
                    case 6:
                        printf("Ingrese el nuevo stock del producto: ");
                        scanf("%d", &producto.stock);
                        break;
                    case 7:
                        printf("Ingrese el nuevo precio de compra del producto: ");
                        scanf("%lf", &producto.precio_compra);
                        break;
                    case 8:
                        printf("Saliendo del menú de actualización.\n");
                        break;
                    default:
                        printf("Opción no válida. Inténtelo de nuevo.\n");
                }

            } while (opcion != 8);

          // Mover el puntero de archivo hacia atrás para sobrescribir la línea
          fseek(archivo, -strlen(line), SEEK_CUR);
          fprintf(archivo, "%s,%s,%s,%s,%d,%d,%.2lf\n", producto.nombre, producto.categoria,
              producto.marca, producto.bodega, producto.codigo, producto.stock, producto.precio_compra);
          fflush(archivo);  // Forzar la escritura de cambios en el archivo
          printf("Usuario actualizado con éxito.\n");
          break;  // Salir del bucle después de actualizar el usuario
    
            printf("Producto actualizado con éxito.\n");
            return;
        }
    }

    fclose(archivo);
    printf("Producto no encontrado.\n");
}


void venderProducto() {
    int cantidad;
    int codigo;
    printf("Ingrese el código del producto: ");
    scanf("%d", &codigo);

    FILE *archivo1;
    archivo1 = fopen("productos.txt", "r+");

    if (archivo1 == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    struct Producto producto;
    char line[100];
    while (fgets(line, sizeof(line), archivo1) != NULL) {
        char n[10], c[10], r[20];
        sscanf(line,  "%49[^,],%49[^,],%49[^,],%49[^,],%d,%d,%lf", producto.nombre, producto.categoria,
            producto.marca, producto.bodega, &producto.codigo, &producto.stock, &producto.precio_compra);

        if (producto.codigo == codigo) {
            printf("Producto encontrado.\n");
            printf("Ingrese la cantidad a vender: ");
            scanf("%d", &cantidad);

            if (producto.stock >= cantidad) {
                producto.stock -= cantidad;

                fseek(archivo1, -strlen(line), SEEK_CUR);
                fprintf(archivo1, "%s,%s,%s,%s,%d,%d,%.2lf\n", producto.nombre, producto.categoria,
                    producto.marca, producto.bodega, producto.codigo, producto.stock, producto.precio_compra);
                fflush(archivo1);  // Forzar la escritura de cambios en el archivo
                printf("Producto stock actualizado.\n");

                // Registro de ventas
                struct Registro_Ventas miRegistro;
                miRegistro.precio_venta = cantidad * producto.precio_compra;

                printf("Ingrese nombre del local: ");
                scanf("%s", miRegistro.local);

                printf("Ingrese nombre del vendedor: ");
                scanf("%s", miRegistro.vendedor);

                time_t now = time(0);
                struct tm *ltm = localtime(&now);

                // Formatear la fecha y la hora
                char formattedDateTime[50]; // Espacio para almacenar la fecha y la hora formateadas
                sprintf(formattedDateTime, "%02d/%02d/%04d - %02d:%02d:%02d",
                        ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900,
                        ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
                strcpy(miRegistro.fecha_venta, formattedDateTime);

                FILE *archivo;
                archivo = fopen("ventas.txt", "a");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    return;
                }
                // Escribir la información del nuevo usuario al final del archivo
                fprintf(archivo, "\n%s,%s,%lf,%s", miRegistro.local, miRegistro.vendedor, miRegistro.precio_venta, miRegistro.fecha_venta);
                fclose(archivo);

                printf("Venta registrada con éxito.\n");
                break;  // Salir del bucle después de actualizar el stock y registrar la venta
            } else {
                printf("Venta no válida. La cantidad deseada no está disponible en bodega.\n");
            }
        }
    }

    fclose(archivo1);
}







