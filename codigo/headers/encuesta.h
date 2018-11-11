/*
Archivo: encuesta.h

Propósito:  header para la clase Encuesta

*/
#ifndef ENCUESTA
#define ENCUESTA

#include <string>
#include <configuracion.h> //para fijar el tamaño de los arrays
#include <pregunta.h> // para la propiedad preguntas
#include <sujeto.h> // para la propiedad sujetosEncuestados

class Encuesta
{
private:
    string nombre; 
    Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas;
    Sujeto[ENCUESTA_CANTIDAD_MAXIMA_SUJETOS] sujetosEncuestados;
    int cantidadEncuestados = 0;
    bool finalizada = false;
public:
    Encuesta(string nombre, Pregunta[] preguntas);
    void encuestar(Sujeto sujeto);
    bool finalizada();
    void mostrarResultados();
};

#endif

