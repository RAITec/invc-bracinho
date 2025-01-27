#include <Servo.h>

#define Base_Servo 3 // porta digital do servo
#define xControl A0  // entrada analógica do joystick
int X_Servo = 100;   // posição inicial do servo
Servo base;          // servo

#define Cotovelo_Servo 6
#define yControl A2
int Y_Servo = 60;
Servo cotovelo;

#define Ombro_Servo 5
#define zControl A1
int Z_Servo = 90;
Servo ombro;

#define Garra_Servo 9
#define botao 2
int G_Servo = 0;
int contador = 1;
Servo garra;

void setup()
{
  base.attach(Base_Servo);
  base.write(X_Servo);
  pinMode(xControl, INPUT);

  ombro.attach(Ombro_Servo);
  ombro.write(Z_Servo);
  pinMode(zControl, INPUT);

  cotovelo.attach(Cotovelo_Servo);
  cotovelo.write(Y_Servo);
  pinMode(yControl, INPUT);

  garra.attach(Garra_Servo);
  garra.write(100);
  pinMode(botao, INPUT);

  Serial.begin(9600);
}

int x;
int y;
int z;

void loop()
{
  x = analogRead(xControl);

  z = analogRead(zControl);

  y = analogRead(yControl);

  if (x > -1 && x <= 340)
  {
    if (X_Servo > 0)
      X_Servo--;
  }
  else if (x > 340 && x < 680)
  {
    // Não faz nada;
  }
  else
  {
    if (X_Servo < 180)
      X_Servo++;
  }

  base.write(X_Servo);

  if (z > -1 && z <= 340)
  {
    if (Z_Servo > 10)
      Z_Servo--;
  }
  else if (z > 340 && z < 680)
  {
    // Não faz nada;
  }
  else
  {
    if (Z_Servo < 180)
      Z_Servo++;
  }

  ombro.write(Z_Servo);

  if (y > -1 && y <= 340)
  {
    if (Y_Servo > 0)
      Y_Servo--;
  }
  else if (y > 340 && y < 680)
  {
    // Não faz nada;
  }
  else
  {
    if (Y_Servo < 140)
      Y_Servo++;
  }

  cotovelo.write(Y_Servo);

  if (digitalRead(botao) == 1)
  {
    while (digitalRead(botao) == 1)
    {
      digitalRead(botao) == 0;
    }
    contador++;
  }

  if (contador % 2 == 0)
  {
    garra.write(0);
  }
  else
  {
    garra.write(100);
  }

  Serial.println(contador);

  delay(20);
}
