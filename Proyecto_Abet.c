#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos términos que contendran valores constantes, los cuales ayudaran a controlar el recorrido de la matriz al momento de emplear las sentencias repetitivas:
#define carreras 7     
#define anios 5

int main()
{
    int datosAlumnos[anios][carreras];       // Definimos la matriz para almacenar los datos de los alumnos
    int sumalum = 0;                         //Definimos la variable que servira para acumlar las sumas de las filas de la matriz
    int alum[anios];                         //Defnimos una nueva matriz, la cual almacenara las sumatorias de los elementos de cada fila
    int alumnosMaximos = 0;                  // Variable para almacenar momenteneamente la cantidad máxima de alumnos registrados en cada anio
    int maxAlumnosUlt = 0;                   // Variable para almacenar momenteneamente la cantidad máxima de alumnos registrados en el ultimo anio
    int maxAlumnosSoft = 0;                  // Variable para almacenar momenteneamente la cantidad máxima de alumnos en la carrera de Ing. Software
    int anioMaxAlumnos = 0;           // Variable para almacenar el año con la mayor cantidad de alumnos
    int anioMaxAlumnosIngenieria = 0; // Variable para almacenar el año en el que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos
    int carreraMaxAlumnos = 0;        // Variable para almacenar el # de carrera con la mayor cantidad de alumnos en el ultimo anio
    int i, j;
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios diferentes en cada ejecución

    printf("Las carreras son:\n 1. Ingenieria de Software.\n 2. Administración.\n 3. Economia.\n 4. Relaciones Internacionales.\n 5. Matematicas.\n 6. Contabilidad.\n 7. Ingenieria Industrial.\n");

    // Hacemos un for para los años y otro for para contabilizar las carreras
    for (i = 0; i < anios; i++)
    {
        sumalum = 0;   // Reiniciamos dentro del primer for la variable que acumula la suma de las filas de la matriz, pues se desea obtener la suma de cada fila.
        printf("\nAnio %d:\n", i + 1);
        for (j = 0; j < carreras; j++)
        {
            printf("El numero de alumnos en la carrera %d es: ", j + 1);
            datosAlumnos[i][j] = rand() % 101;          // Generar un número aleatorio entre 1 y 100 para representar la cantidad de alumnos en la carrera
            printf("%d\n", datosAlumnos[i][j]);

            sumalum+=datosAlumnos[i][j];                // Se le asigna a la variable acumuladora la suma de los elementos de cada fila de la matriz
            
            /* Verificamos si estamos en el último año y la cantidad de alumnos en la carrera actual es mayor que la máxima registrada */
            if (i==4 && (datosAlumnos[i][j] > maxAlumnosUlt))
            {
                maxAlumnosUlt = datosAlumnos[i][j];
                carreraMaxAlumnos = j + 1; // Se suma 1 porque los índices en el arreglo comienzan desde 0
            }

            /* Verificamos si estamos en la carrera de Ingeniería de Software y la cantidad de alumnos en ese año es mayor que la máxima registrada */
            if (j==0 && (datosAlumnos[i][j] > maxAlumnosSoft))
            {
                maxAlumnosSoft = datosAlumnos[i][j];
                anioMaxAlumnosIngenieria = i + 1; /*El incremento de i + 1 se realiza para ajustar el índice del año,
                ya que los índices en el código comienzan desde 0*/
            }
        }

        alum[i]=sumalum;                // Se ubican los valores guardados en la variable acumuladora en una nueva matriz, la cual los mostrara en pantalla
        if(alum[i] > alumnosMaximos)    // Se aplica este condicional para comparar cada elemento de la matriz "alum[i]"
        {
            alumnosMaximos = alum[i];
            anioMaxAlumnos = i+1;       // De darse la condicion, el valor de la variable iteradora "i" mas una unidad, dictara el anio donde se regustraron mas alumnos;
        }
        printf("La suma de los alumnos registrados en este anio: %d\n", alum[i]);
    }

    /* Imprimimos el año con la mayor cantidad de alumnos ingresados en la universidad y
    ponemos añoMaxAlumnos + 1 ya que cuando no se cumple la condición,
    el añoMaxAlumnos no se sigue aumentando de año*/
    printf("\nEl anio con la mayor cantidad de alumnos ingresados a la universidad es: el anio %d\n", anioMaxAlumnos);

    // Imprimimos la carrera que recibio la mayor cantidad de alumnos en el ultimo anio
    printf("La carrera que recibio la mayor cantidad de alumnos en el ultimo anio es la carrera #%d\n", carreraMaxAlumnos);

    // Imprimimos el anio en el que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos
    printf("En el anio %d, la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos\n", anioMaxAlumnosIngenieria);

    return 0;
}