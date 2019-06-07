#ifndef __MENU__
#define __MENU__

/**
 * typedef Menu: TAD de un men�
 * @titulo: t�tulo del men�
 * @opciones: descripciones de las opciones
 * @dimension: cantidad de opciones
 *
 * Este TAD ser� utilizado para presentar opciones y obtener la selecci�n del
 * usuario, encapsulando las operaciones de entrada/salida permitiendo abstraer
 * la apariencia de la aplicaci�n.
 */
typedef struct {
    char *titulo;
    char **opciones;
    int dimension;
} *Menu;

/**
 * crearMenu() - M�todo para crear un men� e inizializar sus atributos.
 * @titulo: t�tulo del men�.
 * @opciones: descripci�n de cada una de las opciones.
 * @dimension: cantidad de opciones.
 *
 * M�todo para crear un men� e inizializar sus atributos. Precondici�n: ninguna.
 * Postcondicion: se aloca memoria para un Menu, se inicializan sus atributos y
 * se devuelve la direccion.
 *
 * Return: un Menu.
 */
Menu crearMenu(char *titulo, char **opciones, int dimension);

/**
 * activarMenu() - M�todo para para solicitar la elecci�n del usuario.
 * @menu: un Menu para activar.
 *
 * M�todo para para solicitar la elecci�n del usuario. Precondici�n: el menu
 * debe haberse creado antes. Postcondicion: a trav�s de las funciones de
 * entrada/salida se muestran el t�tulo del men� y sus opciones. Se solicita
 * la entrada de la opci�n elegida por el usuario.
 *
 * Return: el �ndice de la opci�n seleccionada comenzando por el 1.
 */
int activarMenu(Menu menu);

#endif
