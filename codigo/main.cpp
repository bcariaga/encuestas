#include <iostream>
using namespace std;

/*==========================Configuracion==============================*/
const int ENCUESTA_CANTIDAD_MAXIMA_SUJETOS = 500; //es una constante para el maximo de gente a encuestar
const int ENCUESTA_CANTIDAD_PREGUNTAS = 2;//maximo de preguntas a realizar, en este caso 2
const int PREGUNTA_CANTIDAD_MAXIMA_OPCIONES = 10;//maximo de opciones para las respuestas (en este caso 10 para cada una)
                                                //aun asi, no utilizamos el 10, solo utilizamos 7 en una y 5 en otra
const string PREGUNTA_PALABRA_ESCAPE = "NN";//es una constante para abandonar el bucle de preguntas

/*===================================================================*/
/*==================Prototipo Clase Pregunta========================*/
class Pregunta
{
private:
    string textoPregunta; // textoPregunta contiene el enunciado de la pregunta Ej: "�cual es tu comida favorita?"
    string* opciones; // opciones es un array que contiene las posibles respuestas a las preguntas
    bool validarRespuesta(string respuesta);// es un metodo privado, se usa para comprobar si lo que escribe el
                                            // encuestado es una opcion valida o no (si esta en el array opciones o no)
    int cantdeopciones;//cantdeopciones es una variable para crear los bucles de las opciones mas abajo
public:
    Pregunta();// es un constructor que no recibe parametros, solo inicia la variables vacias
    Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES], int _cantdeopciones);
    //este constructor en cambio si recibe parametros, que son 3 en este caso
    //son: el texto de la pregunta, el array de opciones, y la cantidad de opciones que recibe por cada pregunta

    string preguntar(); //metodo preguntar()
};

/*=======================Metodos Clase Pregunta======================*/
//constructor Pregunta
Pregunta::Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES], int _cantdeopciones)
{
    textoPregunta = _textoPregunta;//guarda los parametros recibidos en variables privadas
    opciones = _opciones;//guarda los parametros recibidos en variables privadas
    cantdeopciones = _cantdeopciones;//guarda los parametros recibidos en variables privadas
}
Pregunta::Pregunta()//todo esto lo ya dicho antes de la que inicializa sin parametros
{
    textoPregunta = "";
}

string Pregunta::preguntar()//es un metodo que devuelve una string(return respuesta)
{

    bool respuestaValida = false;//lo inicio en falso

    string respuesta;

    //mientras que la respuesta no sea valida...
    while(!respuestaValida){
        cout << textoPregunta << endl;//hago una salida por pantalla de lo que es la pregunta
        cout << "ingrese en mayusculas la opcion que corresponda (NN para salir)" << endl;
        for (int x =0; x<cantdeopciones;x++)//inicio un bucle
        {
            cout << opciones[x] << endl;//donde x va imprimiendo cada opcion a medida que aumenta
        }                               //hasta llegar a la cantidad de opciones menos 1
                                        //opciones es el array ya mencionado

        cin >> respuesta;//leo la respuesta del encuestado y la guardo en respuesta

        respuestaValida = validarRespuesta(respuesta);//repsuestaValida va a guardar o true o false
    }                                                //dependiendo de lo que recibe validarRespuesta
    return respuesta;//regresa la string respuesta
}
bool Pregunta::validarRespuesta(string respuesta)//validarRespuesta devuelve un bool(true o false)
{
//chequea que el texto del encuestado sea igual a nuestras opciones, esto incluye mayusculas
//(BRIAN NO LE PUSE NUMEROS SOLO TEXTO!! no creo haga falta el stoi ya que no lo aprendimos,creo? -y sinceramente no entendi tampoco como usarlo-)
for(int j = 0; j<=cantdeopciones;j++) {//creamos otro bucle que recorre todas las opciones
    if (respuesta == PREGUNTA_PALABRA_ESCAPE) { //analiza si lo ingresado por el encuestado es NN
        cout << "opcion escape" << endl;
        return true;
    } else if  (respuesta == opciones[j]) {//analiza si lo ingresado por el encuestado es una opcion valida
        cout << "opcion valida" << endl;
        return true;//cuando devuelve true es porque es una opcion valida ya sea en NN o del array de opciones (aca)
    }
}
    cout << "opcion invalida" << endl;//cuando sale del bucle, significa que el encuestado no ingreso algo valido
    return false;//devuelve false entonces
}


/*===================================================================*/
/*==================Prototipo Clase Sujeto========================*/
//El Sujeto va a guardar las respuestas que va generando
class Sujeto
{ //aca en sujeto vamos a guardar todas las respuestas de todos los sujetos para luego mostrar los resultados
private://EN CONSTRUCCION, ASIQUE NO SE HABLE MAS POR AHORA (hay que terminarlo)
    string respuestas[ENCUESTA_CANTIDAD_PREGUNTAS]; //array con las respuestas generadas
public:
    void responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS]);//metodo
    string getRespuesta(int indice);//metodo
};

//esta funcion llena el array de respuestas
//usa los metodos de Pregunta para obtener respuestas
void Sujeto::responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS])
{
    for(int i =0; i<ENCUESTA_CANTIDAD_PREGUNTAS; i++)
    {
        string respuesta = preguntas[i].preguntar();
          respuestas[i] = respuesta;
    }
}
//devuelte la respuesta para el indice de la pregunta dada
string Sujeto::getRespuesta(int indice)
{
    return respuestas[indice];
};
//REITERO, RETOMAMOS SUJETO LUEGO DE FINALIZADO(?)


/*==================Prototipo Clase Encuesta========================*/
class Encuesta//
{
private:
    string nombre; //nombre de la encuesta
    Pregunta* preguntas; //preguntas es un array que va a guardar el grupo de objeto-pregunta
                         //me refiero a lo que ya se hizo anterior en
    Sujeto sujetosEncuestados[ENCUESTA_CANTIDAD_MAXIMA_SUJETOS]; //los sujetos encuestados se guardan aca
    int cantidadEncuestados = 0; //contador de sujetos encuestados
    bool finalizada = false; //flag(bandera) indica si se termino la encuesta o no
public:                      //si dice true termino la encuesta sino no sigue
    Encuesta(string _nombre, Pregunta _preguntas[ENCUESTA_CANTIDAD_PREGUNTAS]);
    void encuestar(Sujeto sujeto);
    bool getFinalizada();
    void mostrarResultados();
};

/*===================================================================*/
/*=======================Metodos Clase Encuesta=======================*/
//constructor Encuesta, tambien recibe dos parametros,
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


bool Encuesta::getFinalizada()//devuelve lo que es finalizada
{
    return finalizada;                                    //NO SE SI ESTO ESTA BIEN??? || EN CONSTRUCCION||
}

//Este metodo va a ordenar las respuestas y printearlas por consola
void Encuesta::mostrarResultados()
{                                                                    //EN CONSTRUCCION
    //TODO: implementar metodo
    //ordenar resultados
    //mostrar resultados

    cout << "Resultados cantidad de encuestados: " << cantidadEncuestados;
}
/*===================================================================*/

void crearEncuesta()
{
Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS];
    string opciones[8];
    opciones[0] = "PIZZA";
    opciones[1] = "HAMBURGUESA";
    opciones[2] = "MILANESA";
    opciones[3] = "FIDEOS";                 //genera un array de opciones para cada pregunta
    opciones[4] = "PESCADO";                //PERO ES SIN NUMEROS, HABRIA QUE COPIAR LAS REPSUESTAS EN MAYUSCULAS
    opciones[5] = "ENSALADA";
    opciones[6] = "EMPANADA";
    opciones[7] = "OTRA";
    string opciones2[5];
    opciones2[0] = "CARTAS";
    opciones2[1] = "JUEGOS DE MESA";
    opciones2[2] = "VIDEOJUEGOS";
    opciones2[3] = "DEPORTES";
    opciones2[4] = "OTRO";

    Sujeto suj; //crea el objeto suj para usar el metodo encuestar de abajo(lo cual tambien esta en construccion ya que es de la clase sujeto)
    Pregunta pregunta1("�Cual es su comida favorita?", opciones, 8);//creo el obj pregunta1 con tres parametros(nombre de la pregunta, el array de opciones para las repsuestas, la cantidad de opciones)
    Pregunta pregunta2("�Cual es su juego favorito?", opciones2, 5);//creo el obj pregunta2 con tres parametros(nombre de la pregunta, el array de opciones para las repsuestas, la cantidad de opciones)
    preguntas[0] = pregunta1;
    preguntas[1] = pregunta2;
    Encuesta encuesta("en1823CJ", preguntas); //crea el objeto encuesta y le manda dos parametros
                                             //el nombre de la encuesta y el array de objetos preguntas(pregunta1 y pregunta2)
    encuesta.encuestar(suj);
    //return encuesta;
}

/*===================================================================*/
/*===========================Main=====================================*/
int main()
{
crearEncuesta();//aca solo se esta probando lo que es esto ultimo escrito (crearEncuesta())
    //lo pusimos como void y se comento el return para solamente mostrar como funciona esto, hay que cambiarlo luego para todo el tp
    return 0;
}
