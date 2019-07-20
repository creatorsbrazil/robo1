#include <Servo.h>

//cria um objeto servo para controlar um servo
Servo myservo1; //servo base
Servo myservo2; //servo frente
Servo myservo3; //servo garra
Servo myservo4; //servo sobe

// valor inteiro para o motores
int mx = 90; //mx=motorX
int my = 20; //my=motorY
int mz = 130; //mz=motorZ
int ma = 150; //ma=motorA

void setup() {
  Serial.begin (9600); //Definindo velocidade do monitor serial

  //Usamos portas PWM do Arduino para os servos motores
  myservo1.attach(3); //servo base na porta 3
  myservo2.attach(5); // servo frente na porta 5
  myservo3.attach(6); // Servo garra na porta 6
  myservo4.attach(9); // Servo sobe na porta 9
  pinMode(2, INPUT_PULLUP); // Fazer garra abrir e fechar. Ex: 0 fechado, 1 aberto
}


void loop() {

  //Lendo os valores recebidos pelo Joystick
  int v = analogRead(3);//Porta Digital 3
  int x = analogRead(2);//Porta Digital 1
  int y = analogRead(1);//Porta Digital 2
  int z = digitalRead(2); //Porta Digital 12
  digitalWrite(2, HIGH);// Escrevendo porta digital para o botão SW do joystick


  //Mapeando os valores a serem lidos pelo joystick.
  int vv = map(v, 0, 1023, -12, 12);
  int vx = map(x, 0, 1023, -9, 10);
  int vy = map(y, 0, 1023, -10, 10);
  int mz = map(z, 0, 1, 130, 168);

  //Classificando as posiçoes do servos quando moviemnto o joystick na linha X e Y
  mx += vx;
  if (mx < 0)
    mx = 0;
  else if (mx > 180)
    mx = 180;


  my += vy;
  if (my < 10)
    my = 10;
  else if (my > 100)
    my = 100;

  ma += vv;
  if (ma < 100)
    ma = 100;
  else if (ma > 190)
    ma = 190;


  //Dando as funções lidas para os servos
  myservo1.write(mx);
  myservo2.write(my);
  myservo3.write(mz);
  myservo4.write(ma);

  //Imprimindo os valores no monitor serial.
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\tvx: ");
  Serial.print(vx);
  Serial.print("\tmx: ");
  Serial.print(mx);

  Serial.print("\tY: ");
  Serial.print(y);
  Serial.print("\tvy: ");
  Serial.print(vy);
  Serial.print("\tmy: ");
  Serial.print(my);

  Serial.print("\tZ: ");
  Serial.print("\tmz: ");
  Serial.print(z);
  Serial.print("\tmz: ");

  Serial.print("\tV: ");
  Serial.print(v);
  Serial.print("\tvv: ");
  Serial.print(vy);
  Serial.print("\tma: ");
  Serial.print(ma);

  Serial.println();

  delay (50);
}