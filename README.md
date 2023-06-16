#   TC1030 POO_Simulacion_AOT

Este código busca acercarse a una simulación en el mundo del anime "Attack On Titan". El objetivo es crear tu personaje soldado, dependiendo del departamento al que pertenezca (Exploración, Guarnición o Policia Militar) y simular la interacción que tendría con un titan de cierta altura. 

EL objetivo es simular qué tan efectivo sería un ataque hacia un titán, tomando en cuenta las habilidades que cada soldado posea, así como qué tanto afectaría el ataque de un titán al soldado propuesto. 

Las características de los soldados son acorde a lo que se observa en el programa. 

## Funcionalidad
Se despliega un menú con las opciones disponibles, como crear soldados dependiendo de su sección, crear titanes, visualizar los datos introducidos y generar la interacción entre titanes y soldados. El mismo menú te indica qué dígito escribir, dependiendo de la opción deseada.  

## Restricciones
El inventario sólo puede almacenar 10 objetos en cada arreglo. Sobrepasar el límite genera error.
Un titán sólo puede derrotar a 5 soldados. Sobrepasar el límite generará error. Esto se establece queriendo indicar que si sobrepasa 5 soldados derrotados, puede que se trate de un titán especial. 
Solo se deben teclear los dígitos que se piden en la pantalla. Escribir algún otro lleva a un mensaje de opción no válida en algunas ocasiones y en el corte del programa en otros. 

## Correcciones
Fueron agregadas más variables a las clases HIJAS provenientes de la clase Soldado.
En el main llamado AttackOnTitan.cpp, puede verificarse que las funciones con sobre carga y sobresctritura funcionan adecuadamente En el mismo archivo puede observarse implementado el polimorfismo en los arreglos de clase Soldado en los que cada obeto es de tipo clase hija. 
