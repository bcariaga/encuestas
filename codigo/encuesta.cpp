/*
Archivo: encuesta.cpp

Propósito:  funciones de encuesta.h

*/

#include <iostream>
#include "headers/configuracion.h" //para fijar el tamaño de los arrays
#include "headers/sujeto.h" // para la propiedad sujetosEncuestados
#include "headers/encuesta.h"

using namespace std; 

Encuesta::Encuesta(string nombre, Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas)
{
    this.nombre = nombre;
    this.preguntas = preguntas;
}
void Encuesta::encuestar(Sujeto sujeto)
{
    
    if (cantidadEncuestados > ENCUESTA_CANTIDAD_MAXIMA_SUJETOS) 
    {
        finalizada = true;
    }
    
    
    if (!finalizada) 
    {
        sujeto.responder(preguntas);
        //valido si hay que parar (si el usuario responde nn en la 1er pregunta)
        if(sujeto.getRespuesta(0) == "nn" )
        {
            finalizada = true;
        }
        else
        {
            sujetosEncuestados[cantidadEncuestados] = sujeto; //agrego el sujeto al array de sujetos encuestados
            cantidadEncuestados++; // incremento el indice
        }
        
    }
    

}

bool Encuesta::finalizada()
{
    return finalizada;
}
void Encuesta::mostrarResultados()
{
    //TODO:

    cout << "Resultados cantidad de encuestados: " << cantidadEncuestados; 
}