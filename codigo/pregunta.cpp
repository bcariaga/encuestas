/*
Archivo: pregunta.cpp

Propósito:  funciones definidas en  pregunta.h

*/

#include <iostream>
#include "headers/configuracion.h" //para fijar el tamaño de los arrays
#include "headers/sujeto.h" // para la propiedad sujetosEncuestados
#include "headers/encuesta.h"

using namespace std; 

Pregunta::Pregunta(string textoPregunta, string[] opciones)
{
    this.textoPregunta = textoPregunta;
    this.opciones = opciones;    
}
string Pregunta::preguntar()
{
    bool respuestaValida = false;
    string respuesta;

    while(!respuestaValida){
        cout << textoPregunta << endl;
        cout << "ingrese el numero de la opcion que corresponde (nn para salir)" << endl;
        cin >> respuesta;
        respuestaValida = validarRespuesta(respuesta);
    }

    return respuesta;
}

bool Pregunta::validarRespuesta(string respuesta)
{
    // bool esValida = false;
    
    // if (respuesta != PREGUNTA_PALABRA_ESCAPE) 
    // {
    //     esValida = stoi(respuesta) <= PREGUNTA_CANTIDAD_MAXIMA_OPCIONES && stoi(respuesta) > 1;
    // }
    // else
    // {
    //     esValida = true; //es igual a PREGUNTA_PALABRA_ESCAPE 
    // }
    
    return respuesta == PREGUNTA_PALABRA_ESCAPE || (stoi(respuesta) <= PREGUNTA_CANTIDAD_MAXIMA_OPCIONES && stoi(respuesta) > 1);
    
}