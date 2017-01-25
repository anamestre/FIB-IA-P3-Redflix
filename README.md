# Redflix

## Práctica 3 IA: Planificación de películas y series para Redflix.
* Curso 2016 - 2017.
* Ismael Julià, Ana Mestre i Gorka Piñol.

## Compilar los generadores: (No es necesario, ya damos el archivo ejecutable)

 * [Generador extensión 3] g++ -std=c++11 -o gen3 generador_fitxer_3.cpp
 * [Generador extensión 4] g++ -std=c++11 -o gen4 generador_fitxer_4.cpp
 
 Entonces los ejecutables son: gen3 y gen4 respectivamente.
 Cada vez que ejecutamos gen3 o gen4 se escribe el archivo init.pddl que será el problema para el planificador.

## Cómo ejecutar los planificadores (Hay que usar Metric-FF):

* Compilamos el código del Metric-FF (make). Ésto creará el ejecutable "ff".
* Ejecutamos en la consola: 
    [Extensión 3] ./ff -o  entregaDomainExtensio3.pddl -f init.pddl
    [Extensión 4] ./ff -o  entregaDomainExtensio4.pddl -f init.pddl
    
 Siendo init.pddl el juego de pruebas generado.
