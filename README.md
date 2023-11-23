Simulador de Máquina de Lenguaje Ensamblador
Este proyecto es un simulador de una máquina de lenguaje ensamblador implementado en C.
El programa lee instrucciones desde un archivo de texto y las ejecuta.

Características
SET: Permite establecer un valor a una clave.
SHW: Muestra el valor asociado a una clave.
ADD: Suma los valores de dos claves y los almacena en una tercera clave o en el acumulador.
LDR: Carga el valor de una clave en el acumulador.
INC: Incrementa el valor de una clave en 1.
DEC: Decrementa el valor de una clave en 1.
STR: Almacena el valor del acumulador en una clave.
PAUSE: Muestra todos los valores de registro y de memoria.
END: Finaliza la lectura de instrucciones.
Uso
Compila el programa usando tu compilador de C preferido.
Crea un archivo de texto con las instrucciones que deseas que el programa ejecute.
Ejecuta el programa. El programa leerá las instrucciones desde el archivo de texto y las ejecutará.
Ejemplos de archivos de instrucciones
Aquí tienes algunos ejemplos de archivos de instrucciones que puedes usar para probar el programa:

programa2.txt:

SET A1 10 NULL NULL
SET A2 20 NULL NULL
ADD A1 A2 A3 NULL
SHW A3 NULL NULL NULL
END NULL NULL NULL

programa3.txt:

SET B1 5 NULL NULL
SET B2 3 NULL NULL
DEC B1 NULL NULL NULL
INC B2 NULL NULL NULL
SHW B1 NULL NULL NULL
SHW B2 NULL NULL NULL
END NULL NULL NULL

programa4.txt:

SET C1 7 NULL NULL
SET C2 2 NULL NULL
LDR C1 NULL NULL NULL
ADD C2 NULL NULL NULL
STR C1 NULL NULL NULL
SHW C1 NULL NULL NULL
END NULL NULL NULL
