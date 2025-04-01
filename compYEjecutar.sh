#/bin/bash
gcc ataque.c -fno-stack-protector -z execstack -g -o ataque

gcc vulner.c -fno-stack-protector -z execstack -g -o vulner

./ataque
