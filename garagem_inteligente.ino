#include "Ultrasonic.h"
Ultrasonic ultrasonic(4, 5); // Trigger na porta 4 e Echo na porta 5

//Declarando os LED como constantes em seus respectivos pinos
const int ledVerde = 8;
const int buzzer = 11;
const int ledAmarelo = 9;
const int ledVermelho = 10;
int frequencia;
float seno;


long microsec = 0; // variaveis de controle
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  pinMode(ledVerde, OUTPUT); //declarando os LEDs como saida
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Lendo o valor do sensor
  microsec = ultrasonic.timing();

  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

  ledDistancia();
  Serial.print(distanciaCM);// mostrar a distancia na porta serial
  Serial.println(" cm");// colocar unidade de medida
  delay(500);// espera de 500 milissegundos
}
void tocaBuzzer(){
  for(int x=0;x<180;x++){
    seno=(sin(x*3.1416/180));
    frequencia = 2000+(int(seno*2500));
    tone(buzzer, frequencia);
    delay(2);
  }
}
void tocaBuzzer2(){
  for(int x=0;x<180;x++){
    seno=(sin(x*3.1416/180));
    frequencia = 1000+(int(seno*2500));
    tone(buzzer, frequencia);
    delay(2);
  }
}

void tocaBuzzer3(){
  for(int x=0;x<180;x++){
    seno=(sin(x*3.1416/180));
    frequencia = 100+(int(seno*1000));
    tone(buzzer, frequencia);
    delay(2);
  }
}

void naoToca(){
  noTone(buzzer);
}


void ledDistancia() {

  //Desliga todos os LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  noTone(buzzer);

  // criando as condicoes se a distancia for entre 30 cm e 20 cm
  if (distanciaCM <= 40 and distanciaCM >= 20) {

    digitalWrite(ledVerde, HIGH); //liga o LED verde
    tocaBuzzer3();

  }
  // se a distancia for 10 cm e 20 cm
  if (distanciaCM <= 20 and distanciaCM >= 10) {
    digitalWrite(ledAmarelo, HIGH); //liga LED amarelo
    tocaBuzzer2();
  }

  if (distanciaCM < 10) { // se a distancia for menor que 10 cm
    digitalWrite(ledVermelho, HIGH); // liga LED vermelho
    tocaBuzzer();
  }
  
}
