# Justicia Digital - Clases Computación

Qué es un algoritmo. Un algoritmo es la serie de pasos que hay que seguir para resolver un problema. Las computadoras no son muy inteligentes y sólo van a hacer lo que le digamos, entonces cuando necesitamos que resuelva un problema va a necesitar saber como manejar todas las posibles variedades de ese problema. Por ejemplo si queremos hacer fideos tenemos que poner agua en una olla, poner la olla sobre la hornalla, prender la hornalla, esperar a que hierva el agua, poner los fideos en el agua, esperar un tiempo, apagar la hornalla, colar los fideos. Ahora si esto lo automatizamos pueden pasar cosas inesperadas. ¿Qué pasa si no hay agua? ¿O si la hornalla que queremos usar la estamos usando para otra cosa? En esos caso un humano variaría levemente las instrucciones para poder hacer los fideos de otra forma por ejemplo con agua mineral, o usando otra hornalla. La computadora no tiene esa capacidad, salvo que se la hayamos dado cuando escribimos las instrucciones.

Estas instrucciones les programadores la escriben en lenguajes de programación como C o JavaScript. A veces después de eso el código se "compila" en otro lenguaje, en general un lenguaje máquina. El programa compilado es difícil de entender por humanos, pero más fácil de entender por computadoras, sería como traducir la versión legible por los primeros a una legible por las segundas.

```
libreoffice.calc puntaje.ods
make puntaje
./puntaje "Volver al futuro" 10
```

Los algoritmos también pueden decir por ejemplo cómo interpretar un conjunto de ceros y unos como en una imagen. Cada punto de la imagen tiene una combinación de rojo, verde y azul, y en un archivo pequeño está la información de todos estos puntos y sus combinaciones, distintos algoritmos establecen cómo leer el archivo: jpg, gif, bmp, etc. Las imágenes, además de tener datos tienen metadatos, información sobre la imagen que no es la imagen en sí misma, por ejemplo pueden tener las coordenadas geográficas de dónde estaba la cámara al sacarse la foto.

```
exiftool -c "%.6f" Facultad.jpg
firefox "https://www.google.com/maps/search/34.584532+S,+58.390808+W"
```

Los archivos en un disco además de los datos, que incluyen los metadatos de la imagen, tienen metadatos, por ejemplo el nombre de archivo. Los datos son el contenido, mientras que los metadatos es información sobre el mismo. También tenemos ahí la fecha de creación, fecha de última lectura.

```
stat Facultad.jpg
```

Así que tenemos metadatos de archivo y cada formato de archivo dentro de sus datos puede definir metadatos. Por ejemplo un video puede tener un metadato que sea la duración del video, sin eso habría que ver todo el video para ver su longitud.

Es importante saber que tanto los datos como los metadatos de un disco no son información confiable. Por ejemplo la fecha de creación de un archivo no es prueba fehaciente de haber sido creado en ese momento.

```
touch Facultad.jpg
stat Facultad.jpg
touch -d "2 hours ago" Facultad.jpg
stat Facultad.jpg
```

Un ejemplo especial de metadatos es borrar un archivo. Cuando se borra un archivo en vez de borrarlo realmente la computadora sino que lo marca como borrado. Esto se hace porque es mucho más rápido, y tiene la consecuencia de que la información borrada a veces puede recuperarse. A veces no porque como está marcada como borrada si se necesita el espacio para otra cosa se vuelve a usar.

Ahora estos archivos están guardados en el disco. Yo tengo mi usuario de la computadora con sus documentos. ¿Puede alguien si agarra mi disco y leerlos? La respuesta en general es sí. El sistema operativo previene que los usuarios lean los documentos de otros, pero si alguien saca el disco y lo enchufa a otro sistema operativo puede leer todos los archivos como si fueran suyos. La única salvación en ese caso es encriptación.

La encriptación es un proceso por el cual los datos que queremos están escondidos de forma tal que sólo quien tenga la llave puede verlos. Hay dos grandes tipos, simétrica y asimétrica. Por ahora quedémonos con el primero. En la encriptación simétrica la llave que se usa para encriptar (esconder la información) es la que se usa para desencriptar (agarrar la información escondida y obtener la información legible). Si queremos guardar la privacidad de nuestros archivos podemos tener encriptación simétrica en cada archivo sensible o si queremos también se puede hacer sobre todo el disco. Ahora bien, si perdiéramos esa clave no tendríamos forma de recuperar la información.

Los servicios online no tienen este tipo de protección porque si un usuario perdiese su contraseña no podrían restablecerle el acceso a sus datos. La principal forma de protección de acceso que pueden proveer es un segundo factor, además de la contraseña, que asegura que sólo con la contraseña no es suficiente para ingresar. La contraseña es algo que la persona “sabe”. Eso puede transmitirse, o se puede engañar a la persona para que lo comparta. Tener un segundo factor que sea también algo que sabe no subiría la confianza al identificar a la persona porque es igual de falible. Se suele complementar con algo que la persona “tenga”. En general lo mejor para eso es una aplicación en el teléfono que genera claves de uso único que se renuevan cada pocos segundos. Al “pairear” (¿aparear?) el teléfono con la cuenta se comparte un número aleatorio grande. Después cada veinte segundos se usa la hora y ese número para generar otro, que es el que se tiene que usar. Como el apareamiento ocurre sólo una vez no es posible obtener una copia porque no vuelve a transmitirse. Es importante también que esa transmisión inicial se haga por un canal seguro (por ejemplo el banco lo hace via cajero automático).

Han habido errores de seguridad en sistemas remotos explotando optimizaciones. Uno famoso fue [Heartbleed](https://heartbleed.com/). Estaba en TLS, el protocolo que le da la seguridad a la web. El protocolo tiene la funcionalidad de probar que una conexión ande mandando un mensaje y esperando que le responda lo mismo. Se podía crear un mensaje que esté “incompleto” y el servidor lo completaba con cualquier cosa que tuviese a mano, algo parecido a los archivos borrados que no son efectivamente eliminado. Lo que se usaba podía ser cualquier cosa que el servidor tuviese, por ejemplo la contraseña de otro usuario.

Veamos ahora todo el recorrido que tiene un mensaje de whatsapp desde un teléfono a otro. Lo primero que tenemos que considerar es cómo hacen dos computadoras (siendo el teléfono una computadora) para comunicarse. Para eso se usan las direcciones IP. Las direcciones IP serían el equivalente al domicilio para enviar un paquete. Si la dirección está en la misma red local que mi computadora, puede hablar con ella directamente (LAN), pero si la dirección no está adentro se le manda al router para que busque el IP en internet. Hay que considerar que el router para esto tiene dos IPs, uno en la red local donde nuestras computadoras les pueden hablar y otro en internet donde puede hablar con computadoras que no estén en nuestra red. Entonces el router recibe el mensaje local y lo manda a internet, y también recibe las respuestas de internet y las manda a las computadoras locales.

Ahora para que nuestro teléfono pueda mandar un mensaje por whatsapp tiene que existir una computadora en la nube de whatsapp que lo pueda recibir, y nosotros tenemos que saber su dirección IP para hablarle. Ahora bien, nuestra aplicación en vez de “saber” la dirección IP, lo que tiene es un dominio de whatsapp, por ejemplo whatsapp.com y ese dominio lo puede usar para averiguar la dirección IP, usando un protocolo que se llama DNS, eso le permite a whatsapp usar distintos IPs a lo largo del tiempo sin cambiar el código en nuestro teléfono. Este protocolo es el mismo que averigua a qué IP comunicarse cuando escribimos google.com en nuestro navegador.

La pregunta que puede surgir ahora es qué pasa si somos varias personas usando mi conexión de internet, usando whatsapp, ¿cómo hace whatsapp y nuestro router para no confundirnos y pasarnos los mensajes que iban a otra computadora? Además de un IP que determina la computadora, el protocolo TCP encima de esto tiene un “número de puerto” para cada conversación que está teniendo. Entonces el router a un teléfono le da el puerto 1, a otro el puerto 2, etc. para ir a hablar a whatsapp.com, y cuando vuelve le dice a qué puerto corresponde y así se aseguran no mezclarse.

Esto es importante porque los proveedores de telefonía móvil hacen lo mismo (NAT) que los routers con sus antenas, por lo que distintos clientes usan el mismo IP de internet en distintos momentos y si querés averiguar quién lo estaba usando en un momento determinado necesitás saber, además del IP, el instante preciso y el número de puerto.

Cuando me conecto desde mi computadora con WhatsApp decimos en general que WhatsApp actúa como servidor, que está esperando mensajes, y mi computadora como cliente que los envía. Después el servidor puede responder, pero se mantienen esos roles. Hay otros tipos de conexiones que sería conexiones directas entre dos usuarios sin pasar por ningún servidor, de alguna forma se encuentran en internet (en general a través de un servidor que intercambia sus direcciones) y pueden hablar directamente. Esto es lo que comúnmente se llama p2p, peer-to-peer, par-a-par porque las dos computadoras toman el rol de pares entre ellas.

Las computadoras "se hablan" mandandose mensajes representados con 1 y 0. Una computadora se lo pasa a su router, que se lo pasa a su ISP, que se lo hace llegar al ISP de la otra, al router, a la computadora. En el camino cualquiera de estos intermediarios puede haber visto el mensaje, o peor aún lo puede haber modificado, y no tenemos forma de enterarnos que esto es así. Una forma de evitar que esto pase es con encriptación asimétrica. Cómo funciona exactamente es muy complicado, pero lo que hay que saber es que existen dos archivos, una clave pública y una privada. La clave pública está hecha para compartirse y la privada para guardar de forma segura. Cualquiera de las dos se puede usar para encriptar un mensaje y para desencriptarlo se necesita la otra parte. Entonces si encripto algo con mi clave privada, cualquier persona que tenga mi clave pública puede verlo, y también puede validar que lo emití yo por estar encriptado con mi clave privada que no debo compartir. También si alguien quiere mandarme un mensaje a mí y no quiere que nadie más lo lea o se haga pasar por mí, puede encriptarlo con mi clave pública y sólo yo con mi clave privada puedo desencriptarlo. Entonces se puede usar encriptación asimétrica para hacer conexiones entre dos partes asegurando que nadie más la lee ni modifica su contenido.

Al abrir una página a veces nos dice "esta conexión no es segura" o a veces "esta conexión es segura". ¿Cómo pasa eso? A través de encriptación asimétrica. Tenemos guardado en nuestra computadora una lista de claves de organizaciones que son Autoridades de Certificación y cuando queremos hablar con whatsapp.com le pedimos a este CA que nos dé la clave pública de la empresa correspondiente, entonces aún si el DNS me da un IP incorrecto la encriptación fallaría.

WhatsApp además de esto asegura encriptación "de punta a punta" es decir que ni siquiera el servidor de WhatsApp puede leer (o modificar) el mensaje. Esto lo hace con… ¡otra capa de encriptación! Además de mandar los mensajes al servidor encriptados con su clave pública, también se lo encripta con la clave pública que generó nuestro destinatario, y éste sólo puede desencriptarlo al recibirlo porque la clave privada nunca sale del teléfono. Es como poner el regalo en una caja, y esa caja dentro de otra caja; whatsapp saca una de las cajas y entrega la otra sin abrir.

Entonces en resumen para mandar un mensaje nuestro teléfono tuvo que haber generado un par de claves privadas y públicas, y recibido una clave pública de nuestro destinatario. Entonces el mensaje se envía encriptado con nuestra clave privada, la clave pública del destinatario, y la clave pública de whatsapp. Una vez encriptado esto, se usa DNS para obtener el IP de whatsapp.com, a este IP se le manda un paquete con todo esto. El receptor hace el mismo camino de DNS e IP para preguntarle si tiene un mensaje nuevo, y recibe el mensaje que para desencriptar necesita la clave pública de whatsapp, la del emisor, y su clave privada.

Si un juez quiere prohibir que un sitio sea accedido, ¿qué se puede hacer? Una opción es pedirle a los proveedores de DNS que no incluyan a thepiratebay.com en sus registros, entonces cuando alguien quiera abrir esa página no van a poder encontrar su IP. Pero muchos servidores de DNS están en otras jurisdicciones, y también alguien podría entrar si supiese el IP. Alternativamente se le puede pedir a los ISPs que bloqueen el IP. Pero sería fácil sacar otro IP para esta gente, o los usuarios podrían conectarse a través de VPNs en otras jurisdicciones, e incluso puede pasar que un IP esté siendo compartido por varios sitios y que al querer bloquear uno se bloqueen los otros.

## TODO:
* Logs de telcos y privacidad
* Vpn, Tor
* Git, github
* Licencias?
