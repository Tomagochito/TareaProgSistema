#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include "string.h"

void registrarUsuario(struct Usuario usuarios[]){
  struct Usuario nuevoUsuario;
  printf("Ingrese su nombre de usuario: \n");
  scanf("%s",nuevoUsuario.nombre_usuario);
  printf("Ingrese su clave: \n");
  scanf("%s",nuevoUsuario.password);
  usuarios[0]=nuevoUsuario;
}

void actualizarUsuario(struct Usuario usuarios[]){
  char name[15];
  int opcion;
  printf("Ingrese el nombre del usuario: \n");
  scanf("%s",name);
  for(int i = 0; i < 10; i++){//10 es el limite de usuarios
    
    if (usuarios[i].nombre_usuario==name){
      printf("Que desea hacer? \n");
      printf(" 1) Actualizar nombre del usuario\n");
      printf(" 2) Actualizar la contraseña del usuario\n");
      scanf("%d",&opcion);
      if (opcion == 1) {
          printf("Ingrese el nuevo nombre de usuario: \n");
          scanf("%s", usuarios[i].nombre_usuario);
          printf("Nombre de usuario actualizado con éxito.\n");
      } else if (opcion == 2) {
          printf("Ingrese la nueva contraseña: \n");
          scanf("%s", usuarios[i].password);
          printf("Contraseña actualizada con éxito.\n");
      } 
    }
    
  }
}

void registrarProducto(struct Producto productos[]){
  int ultimo=0;
  for(int i=0;productos[i].codigo!='\0';i++){
    printf(i);
    //Busca el ultimo registro sin asignarle nombre
    if(i==49){
      printf("La lista de productos esta llena\n");
      return;
    }
    ultimo=i;
  }
  printf("Ingrese el nombre del nuevo producto: ");
  scanf("%s",productos[ultimo].nombre);
  printf("Ingrese la categoria del producto: ");
  scanf( "%s", productos[ultimo].categoria);
  printf("Ingrese la marca del producto: ");
  scanf( "%s", productos[ultimo].marca);
  printf("Ingrese el codigo del producto: ");
  scanf( "%d", &productos[ultimo].codigo);
  printf("Ingrese el precio de compra del producto: ");
  scanf( "%lf", &productos[ultimo].precio_compra);
  printf("Ingrese la bodega donde esta almacenado: ");
  scanf( "%s", productos[ultimo].bodega);
  printf("Ingrese la cantidad en stock: ");
  scanf( "%d", &productos[ultimo].stock);
  
}
  
  


void actualizarProductos(struct Producto productos[]){
  struct Producto product;
  int indice;
  int code;
  int opcion;
  printf("Ingrese el codigo del producto:");
  scanf("%d", &code);
  for(int i = 0; i < 10; i++){
    if (productos[i].codigo == code){
        product = productos[i];
        indice = i;
    }
    
    printf("Que desea hacer? \n");
    printf(" 1) Actualizar nombre del producto\n");
    printf(" 2) Actualizar la categoria del producto\n");
    printf(" 3) Actualizar la marca del producto\n");
    printf(" 4) Actualizar el precio de compra del producto\n");
    printf(" 5) Actualizar la bodega del producto\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
      printf("Ingrese el nuevo nombre del producto:");
      scanf("%s", product.nombre);
      printf("Nombre del producto actualizado con éxito.\n");
      
      } else if (opcion == 2) {
        printf("Ingrese la nueva categoria del producto:");
        scanf("%s", product.categoria);
        printf("Categoria del producto actualizada con éxito.\n");
        
      } else if (opcion == 3) {
        printf("Ingrese la nueva marca del producto:");
        scanf("%s", product.marca);
        printf("Marca del producto actualizada con éxito.\n");
             
      } else if (opcion == 4) {
        printf("Ingrese el nuevo precio de compra del producto:");
        scanf("%f", &product.precio_compra);
        printf("Precio de compra del producto actualizado con éxito.\n");
        
      } else if (opcion == 5) {
        printf("Ingrese la nueva bodega del producto:");
        scanf("%s", product.bodega);
        printf("Bodega del producto actualizada con éxito.\n");
      }

    productos[indice] = product;
  }
}


void venderProducto(struct Producto productos[], struct Registro_Ventas rventas[]) {
    int totalProducto;
    int cod, cantidadDeseada;

    printf("Ingrese el código del producto: \n");
    scanf("%d", &cod);

    // Encontrar el índice del producto en el array
    int indiceProducto = -1;
    for (int i = 0; i < 50; i++) {
        if (productos[i].codigo == cod) {
            indiceProducto = i;
            break;
        }
    }

    // Verificar si se encontró el producto por su código
    if (indiceProducto != -1) {
        printf("Ingrese la cantidad deseada: \n");
        scanf("%d", &cantidadDeseada);

        // Verificar si hay suficiente cantidad en bodega
        if (cantidadDeseada > 0 && cantidadDeseada <= productos[indiceProducto].stock) {
            // Actualizar stock del producto
            productos[indiceProducto].stock -= cantidadDeseada;
            totalProducto = cantidadDeseada * productos[indiceProducto].precio_compra;

            struct Registro_Ventas miRegistro;
            miRegistro.precio_venta = totalProducto;

            printf("Ingrese nombre del local: \n");
            scanf("%s", miRegistro.local);

            printf("Ingrese nombre del vendedor: \n");
            scanf("%s", miRegistro.vendedor);

          time_t now = time(0);
          struct tm *ltm = localtime(&now);

          // Formatear la fecha y la hora
          char formattedDateTime[50]; // Espacio para almacenar la fecha y la hora formateadas
          sprintf(formattedDateTime, "%02d/%02d/%04d - %02d:%02d:%02d",
                  ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900,
                  ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
          strcpy(miRegistro.fecha_venta, formattedDateTime);

            // Encontrar la primera posición vacía en el array rventas
            int indiceVenta = -1;
            for (int i = 0; i < 50; i++) {
                if (rventas[i].precio_venta == 0) { // Verificar si la venta en esta posición está vacía
                    indiceVenta = i;
                    rventas[indiceVenta] = miRegistro;
                    break;
                }
            }

            printf("Compra exitosa. Gracias por su compra.\n");
        } else {
            // No hay suficiente cantidad en bodega
            printf("Compra no válida. La cantidad deseada no está disponible en bodega.\n");
        }
    } else {
        // No se encontró el producto
        printf("Producto no encontrado. Verifique el código del producto.\n");
    }
}






