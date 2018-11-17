#include <iostream>
using namespace std;

/*==========================Configuracion==============================*/

//para delimitar la cantidad de sujetos a encuestar (Encuesta::sujetosEncuestados)
const int ENCUESTA_CANTIDAD_MAXIMA_SUJETOS = 500; 

//para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)
const int ENCUESTA_CANTIDAD_PREGUNTAS = 2; 

//para delimitar la cantidad de preguntas a realizar (Encuesta::preguntas)
const int PREGUNTA_CANTIDAD_MAXIMA_OPCIONES = 10; 

//para controlar la palabra de escape
const string PREGUNTA_PALABRA_ESCAPE = "nn"; 

/*===================================================================*/


/*==================Prototipo Clase Encuesta========================*/
//Esta clase va a tener informacion de la encuesta,
//contiene las preguntas y los sujetos (con las respuestas)
//se encarga de "hacer" las preguntas a cada Sujeto
class Encuesta
{
private:
    string nombre; //nombre de la encuesta
    Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas; //preguntas de la encuesta
    Sujeto[ENCUESTA_CANTIDAD_MAXIMA_SUJETOS] sujetosEncuestados; //los sujetos encuestados se guardan aca
    int cantidadEncuestados = 0; //contador de sujetos encuestados
    bool finalizada = false; //flag que cierra la encuesta (no permite realizar mas preguntas)
public:
    Encuesta(string nombre, Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas);
    void encuestar(Sujeto sujeto);
    bool finalizada();
    void mostrarResultados();
};
/*===================================================================*/

/*==================Prototipo Clase Pregunta========================*/

//Esta clase es la encargada de mostrar la pregunta por pantalla
//se encarga de entrar los datos del usuario y validar los mismos
class Pregunta
{
private:
    string textoPregunta; //el enunciado de la pregunta Ej: "¿cual es tu comida favorita?"
    string[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES] opciones; //respuestas disponibles para la pregunta.
    bool validarRespuesta(string respuesta); 
public:
    Pregunta(string textoPregunta, string[] opciones);
    string preguntar();
};

/*===================================================================*/


/*==================Prototipo Clase Sujeto========================*/

//El Sujeto va a guardar las respuestas que va generando
class Sujeto
{
private:
    string[ENCUESTA_CANTIDAD_PREGUNTAS] respuestas; //array con las respuestas generadas
public:
    Sujeto();
    void responder(Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas);
    string getRespuesta(int indice);
};
/*===================================================================*/


/*===========================Main=====================================*/

main()
{
    string key;
    cout << "Holo!";
    cin >> key;

    return 0;
}
//TODO
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
//constructor Encuesta
Encuesta::Encuesta(string nombre, Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas)
{
    this.nombre = nombre;
    this.preguntas = preguntas;
}
//Valida que se pueda seguir encuestando
//Recibe un objeto Sujeto y "realiza" las preguntas
void Encuesta::encuestar(Sujeto sujeto)
{
    //valido no haber superado el tope de sujetos a encuestar
    if (cantidadEncuestados > ENCUESTA_CANTIDAD_MAXIMA_SUJETOS) 
        finalizada = true;
    
    //si puedo seguir encuestando
    if (!finalizada) 
    {
        //pido al sujeto que responda
        sujeto.responder(preguntas);
        //valido si hay que parar (si el usuario responde nn en la 1er pregunta)
        if(sujeto.getRespuesta(0) == PREGUNTA_PALABRA_ESCAPE )
        {
            finalizada = true;
        }
        else
        {
            //agrego el sujeto al array de sujetos encuestados
            sujetosEncuestados[cantidadEncuestados] = sujeto;
            // incremento el indice de encuestados
            cantidadEncuestados++; 
        }
        
    }
}

//expone la propiedad interna "finalizada"
bool Encuesta::finalizada()
{
    return finalizada;
}

//Este metodo va a ordenar las respuestas y printearlas por consola
void Encuesta::mostrarResultados()
{
    //TODO: implementar metodo

    //ordenar resultados

    //mostrar resultados

    cout << "Resultados cantidad de encuestados: " << cantidadEncuestados; 
}
/*===================================================================*/


/*=======================Metodos Clase Pregunta======================*/
//constructor Pregunta
Pregunta::Pregunta(string textoPregunta, string[] opciones)
{
    this.textoPregunta = textoPregunta;
    this.opciones = opciones;    
}
//Se encarga de mostrar la preguntas y las opciones por pantalla
//y valida que la respuesta sea valida
//devuelve la opcion seleccionada por el usuario
string Pregunta::preguntar()
{
    //seteo en false hasta que se valide ok
    bool respuestaValida = false;

    string respuesta;

    //mientras que la respuesta no sea valida...
    while(!respuestaValida){
        //printeo la pregunta (el enunciado)
        cout << textoPregunta << endl; 
        cout << "ingrese el numero de la opcion que corresponde (nn para salir)" << endl;
        //leo la respusta
        cin >> respuesta;
        //valido y cargo la variable respuestaValida
        respuestaValida = validarRespuesta(respuesta);
    }

    return respuesta;
}

//valida que la respuesta sea:
// la pregunta de escape (PREGUNTA_PALABRA_ESCAPE)
// o que la opcion este dentro del rango de opciones permitidas
bool Pregunta::validarRespuesta(string respuesta)
{
    //TODO:

    //si respuesta es la palabra de escape el resultado debe ser true

    // si respuesta esta en las opciones disponibles el resultado debe ser true

    // si no se cumplieron los pasos anteriores es false
    
    //posible solucion (ver como obtener la cantidad de opciones)
    // return respuesta == PREGUNTA_PALABRA_ESCAPE || (stoi(respuesta) <= ¿cantidad de opciones? && stoi(respuesta) > 1);

    //nota: stoi trata de convertir un string en un int
    return true;
    
}
/*===================================================================*/


/*==================Prototipo Clase Sujeto========================*/
//esta funcion llena el array de respuestas
//usa los metodos de Pregunta para obtener respuestas
void Sujeto::responder(Pregunta[ENCUESTA_CANTIDAD_PREGUNTAS] preguntas)
{
    //por cada pregunta...

        //pregunto (Pregunta.preguntar())
        //guardo en la posicion de la pregunta la respuesta en array de respuestas   
        // ej.: string respuesta = preguntas[0].preguntar();
        // respuestas[0] = respuesta;
}
//devuelte la respuesta para el indice de la pregunta dada
string Sujeto::getRespuesta(int indice)
{
    //busco la respuesta de mi array de respuestas
    
    //retorno respuesta
}
/*===================================================================*/