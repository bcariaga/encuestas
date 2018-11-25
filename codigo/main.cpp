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
    bool validarRespuesta(int opcion);// es un metodo privado, se usa para comprobar si lo que escribe el
                                            // encuestado es una opcion valida o no (si esta en el array opciones o no)
    int cantOpciones;//cantOpciones es una variable para crear los bucles de las opciones mas abajo
    int obtenerNumeroOpcion(string opcion); //pasa el string de la opcion a un int
    string textoPregunta; // textoPregunta contiene el enunciado de la pregunta Ej: "�cual es tu comida favorita?"
    string* opciones; // opciones es un array que contiene las posibles respuestas a las preguntas
public:
    //Pregunta();// es un constructor que no recibe parametros, solo inicia la variables vacias
    Pregunta();
    //este constructor en cambio si recibe parametros, que son 3 en este caso
    //son: el texto de la pregunta, el array de opciones, y la cantidad de opciones que recibe por cada pregunta
    Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES], int _cantOpciones);
    string getOpcion(int indice); //devuleve el texto de la opcion para mostrarlo por pantalla
    string getTextoPregunta(); //devuleve el texto de la opcion para mostrarlo por pantalla
    int getcantOpciones(); //devulte el numero de opciones, util para iterar
    int preguntar(); //metodo preguntar devuelve la opcion elegida
};

/*=======================Metodos Clase Pregunta======================*/
//constructor Pregunta
Pregunta::Pregunta(string _textoPregunta, string _opciones[PREGUNTA_CANTIDAD_MAXIMA_OPCIONES], int _cantOpciones)
{
    textoPregunta = _textoPregunta;//guarda los parametros recibidos en variables privadas
    opciones = _opciones;//guarda los parametros recibidos en variables privadas
    cantOpciones = _cantOpciones;//guarda los parametros recibidos en variables privadas
}
Pregunta::Pregunta()//todo esto lo ya dicho antes de la que inicializa sin parametros
{
    textoPregunta = "no hay texto";
    string _opciones[1];
    _opciones[0] = "no hay opcion";
    opciones = _opciones;
}
int Pregunta::getcantOpciones()
{
    return cantOpciones;
}
string Pregunta::getTextoPregunta()
{
    return textoPregunta;
}
string Pregunta::getOpcion(int indice)
{
    return opciones[indice];
}

int Pregunta::preguntar()//es un metodo que devuelve un int(return respuesta) que representa la opcion elegida
{
    bool respuestaValida = false;//lo inicio en falso

    string respuesta;
    int opcionElegida = -1;

    //mientras que la respuesta no sea valida...
    while(!respuestaValida)
    {
        cout << textoPregunta << " ingrese en la opcion que corresponda (NN para salir)" << endl << endl;//hago una salida por pantalla de lo que es la pregunta
        for (int x = 0; x < cantOpciones; x++)//inicio un bucle
        {
            cout << x+1 << " : " << opciones[x] << endl; //donde x va imprimiendo cada opcion a medida que aumenta
        }                                               //hasta llegar a la cantidad de opciones menos 1
                                                        //opciones es el array ya mencionado
        cout << endl;
        cin >> respuesta; //leo la respuesta del encuestado y la guardo en respuesta

        if (respuesta != PREGUNTA_PALABRA_ESCAPE)
        {
            opcionElegida = obtenerNumeroOpcion(respuesta) - 1; //resto uno porque es base 0 (pero el usuario no sabe)
            respuestaValida = validarRespuesta(opcionElegida);  //repsuestaValida va a guardar o true o false
        }
        else
        {
            //si es la palabra de escape la considero valida para cortar el bucle
            respuestaValida = true;
        }


    }
    return opcionElegida;//regresa la opcion elegida
}
bool Pregunta::validarRespuesta(int opcion)//validarRespuesta devuelve un bool(true o false)
{
    //chequea que la opcion elegida este dentro del rango de las opciones disponibles para la pregunta
    if (opcion < cantOpciones && opcion >= 0)
    {
        cout << endl << "opcion valida" << endl << endl; //dejo un espacio adicional
        return true;//cuando devuelve true es porque es una opcion valida ya sea en NN o del array de opciones (aca)
    }
    else
    {
        cout << endl << "opcion invalida" << endl << endl;;//cuando sale del bucle, significa que el encuestado no ingreso algo valido
        return false;//devuelve false entonces
    }
}

//creo este metodo para pasar el numero de la opcion (string) a opcion(int) (y no usar stoi)
//es mas comodo tratarlo como int para poder usarlo de indice
int  Pregunta::obtenerNumeroOpcion(string opcion)
{
    int resultado = -1;
    if (opcion == "1")
        resultado = 1;
    else if(opcion == "2")
        resultado = 2;
    else if(opcion == "3")
        resultado = 3;
    else if(opcion == "4")
        resultado = 4;
    else if(opcion == "5")
        resultado = 5;
    else if(opcion == "6")
        resultado = 6;
    else if(opcion == "7")
        resultado = 7;
    else if(opcion == "8")
        resultado = 8;
    else if(opcion == "9")
        resultado = 9;
    else if(opcion == "10")
        resultado = 10;
    else if(opcion == "11")
        resultado = 11;

    return resultado;
}

/*===================================================================*/
/*==================Prototipo Clase Sujeto========================*/
//El Sujeto va a guardar las respuestas que va generando
class Sujeto
{ //aca en sujeto vamos a guardar todas las respuestas de todos los sujetos para luego mostrar los resultados
private://EN CONSTRUCCION, ASIQUE NO SE HABLE MAS POR AHORA (hay que terminarlo)
    int respuestas[ENCUESTA_CANTIDAD_PREGUNTAS]; //array con las respuestas generadas
public:
    void responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS]);//metodo
    int getRespuesta(int indice);//metodo
};

//esta funcion llena el array de respuestas
//usa los metodos de Pregunta para obtener respuestas
void Sujeto::responder(Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS])
{
    bool respondioTodo = false;
    int indicePregunta = 0;

    while(!respondioTodo)
    {
        int respuesta = preguntas[indicePregunta].preguntar();
        respuestas[indicePregunta] = respuesta;
        indicePregunta++;
        //corto ya respondio todas las preguntas o si es la respuesta de escape
        if (indicePregunta > ENCUESTA_CANTIDAD_PREGUNTAS - 1 || respuesta < 0)
        {
            respondioTodo = true;
        }
    }

}
//devuelte la respuesta para el indice de la pregunta dada
int Sujeto::getRespuesta(int indice)
{
    return respuestas[indice];
};

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
    Encuesta(string _nombre, Pregunta *_preguntas);
    Encuesta();
    void encuestar(Sujeto sujeto);
    bool getFinalizada();
    void mostrarResultados();
    Pregunta getPregunta(int indice){ //debug
        return preguntas[indice];
    }
};

/*===================================================================*/
/*=======================Metodos Clase Encuesta=======================*/
//constructor Encuesta, tambien recibe dos parametros,
Encuesta::Encuesta(string _nombre, Pregunta *_preguntas)
{
    nombre = _nombre;
    preguntas = _preguntas;
    finalizada = false;
}
Encuesta::Encuesta()
{
    nombre = "s/n";
    Pregunta _preguntas[ENCUESTA_CANTIDAD_PREGUNTAS];
    preguntas = _preguntas;
    finalizada = false;
}
//Valida que se pueda seguir encuestando
//Recibe un objeto Sujeto y "realiza" las preguntas
void Encuesta::encuestar(Sujeto sujeto)
{
    cout << "Encuestando al sujeto nro " << cantidadEncuestados + 1 << endl << endl;
    //valido no haber superado el tope de sujetos a encuestar
    if (cantidadEncuestados > ENCUESTA_CANTIDAD_MAXIMA_SUJETOS){
        finalizada = true;
    }

    //si puedo seguir encuestando
    if (!finalizada)
    {
        //pido al sujeto que responda
        sujeto.responder(preguntas);
        //valido si hay que parar (si el usuario responde nn en la 1er pregunta)
        if(sujeto.getRespuesta(0) < 0 )
        {
            finalizada = true;
            cout << "palabra de escape" << endl;
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
{
    cout << endl;
    cout << "Resultados : " << endl;
    cout << "Cantidad de encuestados: " << cantidadEncuestados << endl;
    //por cada pregunta
    for(int indicePreguntas = 0; indicePreguntas < ENCUESTA_CANTIDAD_PREGUNTAS; indicePreguntas++)
    {
        // busco la pregunta dentro del array de preguntas (atributo de Encuesta)
        Pregunta preguntaEnIteracion = preguntas[indicePreguntas];

        int cantidadOpciones = preguntaEnIteracion.getcantOpciones();
        //creo un array para contar las opciones elegidas (lo inicializo en 0)
        int opcionesContador[cantidadOpciones] = {0};
        //reviso los encuestados
        for(int indiceSujetosEncuestados = 0; indiceSujetosEncuestados < cantidadEncuestados; indiceSujetosEncuestados++)
        {
            int opcionElegida = sujetosEncuestados[indiceSujetosEncuestados].getRespuesta(indicePreguntas);
            //aumento el contador de la opcion elegida
            opcionesContador[opcionElegida]++;
        }

        //ordeno

        //por cada opcion (en el contador)
        for(int indiceOpcion = 0; indiceOpcion < cantidadOpciones - 1; indiceOpcion++)
        {
            //comparo la opcion actual con la sigiente, si es mas chica:
            if (opcionesContador[indiceOpcion] < opcionesContador[indiceOpcion + 1])
            {
                //almaceno el valor (la cantidad) en una variable temporal
                int cantTemp = opcionesContador[indiceOpcion];
                //asigno en la posicion actual el proximo valor (porque es mas grande, logicamente)
                opcionesContador[indiceOpcion] = opcionesContador[indiceOpcion + 1];
                //dejo el valor temporal en la proxima comparacion
                opcionesContador[indiceOpcion  + 1] = cantTemp;
                //la puestro por pantalla el nombre de la opcion y el conteo
            }
          
        }

        //muestro
        cout << endl << "Respuestas de: " << preguntaEnIteracion.getTextoPregunta() << endl << endl;
        for(int opcion = 0; opcion < cantidadOpciones; opcion++)
        {
            cout << preguntas[indicePreguntas].getOpcion(opcion) << " : " << opcionesContador[opcion] << endl;
        }
    }
}
/*===================================================================*/

void iniciarEncuesta()
{

    //genero las opciones
    string opciones[8];
    opciones[0] = "PIZZA";
    opciones[1] = "HAMBURGUESA";
    opciones[2] = "MILANESA";
    opciones[3] = "FIDEOS";                 //genera un array de opciones para cada pregunta
    opciones[4] = "PESCADO";
    opciones[5] = "ENSALADA";
    opciones[6] = "EMPANADA";
    opciones[7] = "OTRA";
    string opciones2[5];
    opciones2[0] = "CARTAS";
    opciones2[1] = "JUEGOS DE MESA";
    opciones2[2] = "VIDEOJUEGOS";
    opciones2[3] = "DEPORTES";
    opciones2[4] = "OTRO";

    //genero las preguntas
    Pregunta preguntas[ENCUESTA_CANTIDAD_PREGUNTAS];

    Pregunta pregunta1("Cual es su comida favorita?", opciones, 8);//creo el obj pregunta1 con tres parametros(nombre de la pregunta, el array de opciones para las repsuestas, la cantidad de opciones)
    Pregunta pregunta2("Cual es su juego favorito?", opciones2, 5);//creo el obj pregunta2 con tres parametros(nombre de la pregunta, el array de opciones para las repsuestas, la cantidad de opciones)
    
    preguntas[0] = pregunta1;
    preguntas[1] = pregunta2;

    //creo la encuesta
    Encuesta encuesta = Encuesta("en1823CJ", preguntas); //crea el objeto encuesta y le manda dos parametros
                                             //el nombre de la encuesta y el array de objetos preguntas(pregunta1 y pregunta2)

    //empiezo a encuestar
    while(!encuesta.getFinalizada())
    {
        Sujeto sujeto = Sujeto();
        encuesta.encuestar(sujeto);

    }

    //muestro los resultados
    encuesta.mostrarResultados();

}

/*===================================================================*/
/*===========================Main=====================================*/
int main()
{
    iniciarEncuesta();

    return 0;
}
