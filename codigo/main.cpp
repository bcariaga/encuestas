#include <iostream>
using namespace std;

/*==========================Configuracion==============================*/

const int ENCUESTA_CANTIDAD_MAXIMA_SUJETOS = 500; //para delimitar la cantidad de sujetos a encuestar (Encuesta::sujetosEncuestados)
const int ENCUESTA_CANTIDAD_PREGUNTAS = 2; //para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)

const int PREGUNTA_CANTIDAD_MAXIMA_OPCIONES = 10; //para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)

const std::string PREGUNTA_PALABRA_ESCAPE = "nn";

/*===================================================================*/


/*==================Prototipo Clase Encuesta========================*/
class Encuesta
{
private:
    string nombre; 
    Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas;
    Sujeto[ENCUESTA_CANTIDAD_MAXIMA_SUJETOS] sujetosEncuestados;
    int cantidadEncuestados = 0;
    bool finalizada = false;
public:
    Encuesta(string nombre, Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas);
    void encuestar(Sujeto sujeto);
    bool finalizada();
    void mostrarResultados();
};
/*===================================================================*/

/*==================Prototipo Clase Pregunta========================*/
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

/*===================================================================*/


/*==================Prototipo Clase Sujeto========================*/

class Sujeto
{
private:
    string[ENCUESTA_CANTIDAD_PREGUNTAS] respuestas;
public:
    Sujeto();
    void responder(Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas);
    string getRespuesta(int indice);
};
/*===================================================================*/


/*===========================Main=====================================*/

main(int argc, char const *argv[])
{
    string key;
    cout << "Holo!";
    cin >> key;

    return 0;
}

Encuesta crearEncuesta()
{
       
    Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS];
    preguntas[0] = new Pregunta("Pregunta?", ["opcion 1", "opcion 2"]);
    preguntas[1] = new Pregunta("Pregunta 2 ?", ["opcion 1", "opcion 2"]);
    Encuesta = new Encuesta("pepe", preguntas);
    return Encuesta;
}

/*===================================================================*/


/*=======================Metodos Clase Encuesta=======================*/

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
        if(sujeto.getRespuesta(0) == PREGUNTA_PALABRA_ESCAPE )
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
/*===================================================================*/


/*=======================Metodos Clase Pregunta======================*/

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
/*===================================================================*/


/*==================Prototipo Clase Sujeto========================*/

void Sujeto::responder(Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas)
{
    
}
string Sujeto::getRespuesta(int indice)
{
    
}
/*===================================================================*/