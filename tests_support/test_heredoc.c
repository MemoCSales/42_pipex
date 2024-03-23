#include <stdio.h>

int main(void)
{
    printf("Esta es una linea de codigo normal. \n");

    //Aqui empieza un here_doc
    printf("Ahora imprimire un mensaje de varias lineas: \n");
    printf("----------------------------------------------\n");
    printf("<<EOF\n");
    printf("Hola!\n");
    printf("Este es un mensaje de varias lineas.\n");
    printf("¡Que tengas un gran día!\n");
    printf("EOF\n");
    printf("-----------\n");

    return 0;
}
