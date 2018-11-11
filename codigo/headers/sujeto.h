#ifndef SUJETO
#define SUJETO

#include <string>
#include <configuracion.h> //para fijar el tamaño de los arrays

class Sujeto
{
private:
    string[ENCUESTA_CANTIDAD_PREGUNTAS] respuestas;
public:
    Sujeto();
    void responder(Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas);
    string getRespuesta(int indice);
};

#endif
