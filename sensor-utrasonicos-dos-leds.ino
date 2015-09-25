/*Detecta la distancia en CM, si es menor a 20CM prende el primer led, si es menor a 10CM prende
el segundo led*/

long distancia;
long tiempo;
void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(13, OUTPUT); /*activacion del pin 13 para el primer led, este no lleva resistencia*/
  pinMode(11, OUTPUT); /*activacion del pin 11 para el primer led, este lleva resistencia*/
}

void loop(){
  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  
  /* Si la distancia es menor a 20CM prendo el primer led de forma continua */
  
  if (distancia < 20) {
   digitalWrite(11, HIGH);   
  } else {
   digitalWrite(11, LOW);     
}

  /* Si la distancia es menor a 10CM prendo el segundo led de forma intermitente */

  if (distancia < 10) {  
       digitalWrite(13, LOW);
  delay(100);  
  digitalWrite(13, HIGH);
  delay(100); 
  digitalWrite(13, LOW);  
  } else {
       digitalWrite(13, LOW);
}

  delay(1000);
}
