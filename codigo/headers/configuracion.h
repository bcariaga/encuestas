/*
Archivo: configuracion.h

Propósito:  Centralizar las configuraciones del programa y 
            fijar el tamaño de los arrays que manejen las distintas clases.
*/
#ifndef CONFIGURACION
#define CONFIGURACION

#include <iostream>


const int ENCUESTA_CANTIDAD_MAXIMA_SUJETOS = 500; //para delimitar la cantidad de sujetos a encuestar (Encuesta::sujetosEncuestados)
const int ENCUESTA_CANTIDAD_PREGUNTAS = 2; //para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)

const int PREGUNTA_CANTIDAD_MAXIMA_OPCIONES = 10; //para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)

const std::string PREGUNTA_PALABRA_ESCAPE = "nn";

#endif