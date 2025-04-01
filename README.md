# bufferOverflow
Projecto el cual hace un buffer overflow en un sistema FreeBSD, asumiendo que tiene el ASLR desactivado y que en el programa vulnerable se puede ejecutar codigo en la pila
# Archivos:
## ataque.c
Aplicación que realiza el ataque. Se puede modificar para que lo habra directamente con el debuguer para ver el funcionamiento interno del programa.
## vulner.c
Aplicación vunerable, ya que hace un strcpy del buffer sin comprobar la entrada y esta compilada con directivas incorrectas
## compYEjecutar.sh
Bash que compila y ejecuta el programa rapidamente y con las directivas que deseamos
