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


/*==================Prototipo Clase Pregunta========================*/

//Esta clase es la encargada de mostrar la pregunta por pantalla
//se encarga de entrar los datos del usuario y validar los mismos
class Pregunta
{
private:
    string textoPregunta;   //el enunciado de la pregunta Ej: "¿cual es tu comida favorita?"
    string* opciones;       //respuestas disponibles para la pregunta.
    int cantdeopciones;     //para poder iterar dentro de las opciones
    bool validarRespuesta(string respuesta);
public:
    Pregunta();
    Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES]);
    string preguntar();
};

/*===================================================================*/

/*==================Prototipo Clase Sujeto========================*/

//El Sujeto va a guardar las respuestas que va generando
class Sujeto
{
private:
    string respuestas[ENCUESTA_CANTIDAD_PREGUNTAS]; //array con las respuestas generadas
public:
    void responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS]);
    string getRespuesta(int indice);
};
/*===================================================================*/

/*==================Prototipo Clase Encuesta========================*/
//Esta clase va a tener informacion de la encuesta,
//contiene las preguntas y los sujetos (con las respuestas)
//se encarga de "hacer" las preguntas a cada Sujeto
class Encuesta
{
private:
    string nombre; //nombre de la encuesta
    Pregunta* preguntas; //preguntas de la encuesta
    Sujeto sujetosEncuestados[ENCUESTA_CANTIDAD_MAXIMA_SUJETOS]; //los sujetos encuestados se guardan aca
    int cantidadEncuestados = 0; //contador de sujetos encuestados
    bool finalizada = false; //flag que cierra la encuesta (no permite realizar mas preguntas)
public:
    Encuesta(string _nombre, Pregunta _preguntas[ENCUESTA_CANTIDAD_PREGUNTAS]);
    void encuestar(Sujeto sujeto);
    bool getFinalizada();
    void mostrarResultados();
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


/*===================================================================*/


/*=======================Metodos Clase Pregunta======================*/
//constructor Pregunta
Pregunta::Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES], int _cantdeopciones)
{
    textoPregunta = _textoPregunta;
    opciones = _opciones;
    cantdeopciones = _cantdeopciones;                //SE CREO UNA VARIABLE NUEVA PARA CREARLE LOS BUCLES DE LAS OPCIONES
}
Pregunta::Pregunta()
{
    textoPregunta = "";
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
    
    for(int j = 0; j <= cantdeopciones; j++) {
        if (respuesta == PREGUNTA_PALABRA_ESCAPE) {
            cout << "opcion escape" << endl;
            return true;
        } else if  (respuesta == opciones[j]) {
            cout << "opcion valida" << endl;
            return true;
        }
    }
    cout << "opcion invalida" << endl;
    return false;
}
/*===================================================================*/


/*==================Prototipo Clase Sujeto========================*/
//esta funcion llena el array de respuestas
//usa los metodos de Pregunta para obtener respuestas
void Sujeto::responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS])
{
    //por cada pregunta...
    for(int i =0; i<ENCUESTA_CANTIDAD_PREGUNTAS; i++)
    {
        //pregunto (Pregunta.preguntar())
        string respuesta = preguntas[i].preguntar();
        //guardo en la posicion de la pregunta la respuesta en array de respuestas   
        respuestas[i] = respuesta;
    }
}
//devuelte la respuesta para el indice de la pregunta dada
string Sujeto::getRespuesta(int indice)
{
    //busco la respuesta de mi array de respuestas
    return respuestas[indice];//retorno respuesta
    
}
/*===================================================================*/


/*=======================Metodos Clase Encuesta=======================*/
//constructor Encuesta
Encuesta::Encuesta(string _nombre, Pregunta _preguntas[ENCUESTA_CANTIDAD_PREGUNTAS])
{
    nombre = _nombre;
    preguntas = _preguntas;
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
bool Encuesta::getFinalizada()
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

//TODO
Encuesta crearEncuesta()
{
       
    Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS];
    string opciones[10];
    opciones[0] = "PIZZA";
    opciones[1] = "HAMBURGUESA";
    opciones[2] = "MILANESA";
    opciones[3] = "FIDEOS";                 //ESTO LO PROBE EN EL MAIN, SOLO LO INTERNO DE CREAR ENCUESTA Y FUNCIONA
    opciones[4] = "PESCADO";                //PERO ES SIN NUMEROS, HABRIA QUE COPIAR LAS REPSUESTAS EN MAYUSCULAS
    opciones[5] = "ENSALADA";
    opciones[6] = "EMPANADA";
    opciones[7] = "OTRA";
    string opciones2[5];
    opciones2[0] = "CARTAS";
    opciones2[1] = "JUEGOS DE MESA";
    opciones2[2] = "VIDEO JUEGOS";
    opciones2[3] = "DEPORTES";
    opciones2[4] = "OTRO";

    Sujeto suj;
    Pregunta pregunta1("�Cual es su comida favorita?", opciones, 7);
    Pregunta pregunta2("�Cual es su juego favorito?", opciones2, 5);
    preguntas[0] = pregunta1;
    preguntas[1] = pregunta2;
    Encuesta encuesta("Anonimo", preguntas);
    encuesta.encuestar(suj);
    return encuesta;
}