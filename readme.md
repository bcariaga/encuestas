# Proyecto Encuesta

El objetivo del programa es poder llevar a cabo una encuesta y poder procesar los resultados, mostrándolos de manera ordenada.


## Diseño

Las clases del programa seguirán el siguiente esquema:

![uml encuestas](uml_encuesta.png)

La consigna del siguiente trabajo práctico consiste en poder armar una estructura de datos que permita encuestar como máximo a 500 personas de entre 18 y 23 años, con el fin de capturar datos referentes a comidas y juegos del gusto del encuestado, y una vez finalizada, poder exhibir los resultados obtenidos de la totalidad, en forma ordenada.

### Encuesta

Como primera medida, comenzamos el programa a través de un procedimiento que inicia la encuesta, es decir, en él,  se describen las &quot;opciones&quot; a través de dos arrays de tipo string, y se instancia un objeto **preguntas** de **clase Pregunta** , el cual será otro array que contendrá, en este caso, los objetos **pregunta1** y **pregunta2** , con las preguntas de la encuesta, el array de opciones correspondiente a cada pregunta y la cantidad de opciones, para luego, comenzar el proceso que utilizará los atributos de las diferentes clases creadas, por medio de sus respectivos métodos públicos y privados.

Por medio de la clase Encuesta, contamos con el atributo **preguntas** (de tipo **Pregunta** ), el cual permitirá manejar la encuesta con las preguntas correspondientes. También se posee el atributo **cantidadDeEncuestados** de tipo entero, con el que estaremos al tanto de la cantidad de personas que se vayan encuestando; una variable privada **nombre** , de tipo string, en la que se guardará el nombre de la encuesta. Seguidamente, contamos con el método privado **finalizada** (de tipo bool) **,** que indicará si es posible tomar más sujetos a encuestar, ya sea por haber llegado al tope del array o por haber ingresado la palabra &quot;NN&quot; para finalizar el proceso. Por su parte, el array de tipo Sujeto denominado **sujetosEncuestados,** guardará la respuesta que se otorgue dentro del procedimiento público **encuestar.** Asimismo, el método **getFinalizada** , es utilizado por el procedimiento que inicia la encuesta para verificar que sea posible realizarla. **MostrarEncuesta** se encarga de obtener los resultados de la encuesta (guardados en cada **Sujeto** del atributo **respuestas,** array de int), ordenarlos de mayor a menor y mostrarlos por pantalla.

### Sujeto

Por otro lado, generamos la clase **Sujeto** , la cual va a contener un array **respuestas** (de tipo entero)en el que se guardará cada respuesta de los usuarios y un método **responder** , que seráejecutado medianteel procedimiento **encuestar** de la clase **Encuesta** , pasándole el array que contiene las preguntas de la encuesta (de tipo Pregunta) como parámetro, a fin de corroborar si el usuario respondió en su totalidad.

### Pregunta

Finalmente, se describe la clase **Pregunta** , donde el atributo **textoPregunta** contendrá el enunciado de la pregunta a realizar, el atributo **opciones** , será el array generado en el procedimiento **iniciarEncuesta** , de donde se obtendrán las opciones de Comidas y Juegos, pedidas por cada pregunta que se le haga al encuestado. Se mostrará cada pregunta con sus opciones a fin de que se obtenga la respuesta del usuario, donde **validarRespuesta** (método privado de tipo bool) verifique que la respuesta corresponda sólo a las opciones otorgadas. El atributo privado **obtenerNumeroOpcion** será el encargado de tomar cada opción como tipo de dato string para luego, devolverlo como tipo de dato entero. Por parte de los métodos públicos contamos con el método de tipo entero, **preguntar** ,  que exhibe los enunciados de las preguntas y opciones, junto con la validación de la respuesta del usuario para finalmente retornar esta opción elegida.

## Flujo


![flujo_encuesta](flujo_encuesta.png)
