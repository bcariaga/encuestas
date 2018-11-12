#ifndef PREGUNTA
#define PREGUNTA

#include <string>
#include <configuracion.h> //para fijar el tamaño de los arrays

class Pregunta
{
private:
    string textoPregunta;
    string[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES] opciones;
    bool validarRespuesta(string respuesta);
public:
    Pregunta(string textoPregunta, string[] opciones);
    string preguntar();
};

#endif

