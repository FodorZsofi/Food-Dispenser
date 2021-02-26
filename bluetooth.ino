#include <Servo.h>

Servo servo;
int pos = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int sensorValue = 0;
int btn = 0;
int btn1 = 0;
int btn2 = 0;
int btn3 = 0;
int count = 0;

#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_DS5 622
#define REST      0
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_AS4 466
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_C6  1047
#define NOTE_F6  1397


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


// change this to make the song slower or faster
int tempo = 140;
int melody2[] = {

  // We Wish You a Merry Christmas

  NOTE_C5, 4, //1
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,

  NOTE_F5, 2

};


int notes = sizeof(melody2) / sizeof(melody2[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;




int tempo2 = 108;
int melody3[] = {

  // Dart Vader theme (Imperial March) - Star wars

  NOTE_AS4, 8, NOTE_AS4, 8, NOTE_AS4, 8, //1
  NOTE_F5, 2, NOTE_C6, 2,
  NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,
  NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,
  NOTE_AS5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_G5, 2

};

int notes2 = sizeof(melody3) / sizeof(melody3[0]) / 2;
int wholenote2 = (60000 * 4) / tempo2;
int divider2 = 0, noteDuration2 = 0;





int tempo4 = 80;
const int melody4[] PROGMEM = {

  // Fur Elise - Ludwig van Beethovem
  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,

  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , 4, REST, 8, 

};

int notes4 = sizeof(melody4) / sizeof(melody4[0]) / 2;

int wholenote4 = (60000 * 4) / tempo4;

int divider4 = 0, noteDuration4 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Tx0 and Rx0  //Set Baud Rate to 9600 for Serial Communication Tx0 and Rx0
  Serial1.begin(9600);  //Tx1 and Rx1  //Connected to Bluetooth Module HC-05 (Bluetooth 2.0)

  servo.attach(9);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(31, INPUT);
  pinMode(30, INPUT);
  pinMode(33, INPUT);
  pinMode(32, INPUT);
  pinMode(A0, INPUT);

}



void smallPortion()
{
  servo.write(0);
  delay(150);
  servo.write(90);
  delay(1000);

  if (sensorValue > 150)
  {
    for (int thisNote = 0; thisNote < 8; thisNote++) {


      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }
  else
  {

    tone(8, melody[1], 1000 / noteDurations[1]);
  }

}


void smallMediumPortion() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);

  if (sensorValue > 150)
  {
    for (int thisNote = 0; thisNote < notes * 2 ; thisNote = thisNote + 2) {

      divider = melody2[thisNote + 1];
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; 
      }

      tone(8, melody2[thisNote], noteDuration * 0.9);
      delay(noteDuration);
      noTone(8);
    }
  }
  else
  {
    tone(8, melody[1], 1000 / noteDurations[1]);
  }

}

void mediumPortion() {
  servo.write(0);
  delay(1500);
  servo.write(90);
  delay(1000);

  if (sensorValue > 150)
  {
    for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) {

      divider2 = melody3[thisNote + 1];
      if (divider2 > 0) {
        noteDuration2 = (wholenote2) / divider2;
      } else if (divider2 < 0) {
        noteDuration2 = (wholenote2) / abs(divider2);
        noteDuration2 *= 1.5; 
      }

      tone(8, melody3[thisNote], noteDuration2 * 0.9);

      delay(noteDuration2);
      noTone(8);
    }
  }
  else
  {
    tone(8, melody[1], 1000 / noteDurations[1]);
  }
}

void bigPortion() {
  servo.write(0);
  delay(2000);
  servo.write(90);
  delay(1000);

  if (sensorValue > 150)
  {
    for (int thisNote = 0; thisNote < notes4 * 2; thisNote = thisNote + 2) {

      divider4 = pgm_read_word_near(melody4 + thisNote + 1);
      if (divider4 > 0) {
        noteDuration4 = (wholenote4) / divider4;
      } else if (divider4 < 0) {
        noteDuration4 = (wholenote4) / abs(divider4);
        noteDuration4 *= 1.5; 
      }

      tone(8, pgm_read_word_near(melody4 + thisNote), noteDuration4 * 0.9);

      delay(noteDuration4);

      noTone(8);
    }
  }
  else
  {
    tone(8, melody[1], 1000 / noteDurations[1]);
  }
}



void loop() {

  if (count == 0) {
    Serial1.println("For small portion, press a"); //To mobile
    Serial1.println("For small-medium portion, press b");
    Serial1.println("For medium portion, press c");
    Serial1.println("For big portion, press d");
    count=1;
  }

  sensorValue = analogRead(A0);
  //Serial.println(sensorValue);


  //We only want the leds to be on when the visibility is reduced, i.e. it is almost dark
  if (sensorValue > 300)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  {
    sensorValue = map(sensorValue, 0, 300, 255, 0);
    analogWrite(2, sensorValue);
    analogWrite(3, sensorValue);
    analogWrite(4, sensorValue);
    analogWrite(5, sensorValue);
  }


  if (Serial1.available() > 0)
  {
    int buffer_value = Serial1.read();
    if (buffer_value == 'a')
    {
      smallPortion();
      Serial1.println("Poured extra small portion");
    }
    else if (buffer_value == 'b')
    {
      smallMediumPortion();
      Serial1.println("Poured small portion");
    }
    else if (buffer_value == 'c')
    {
      mediumPortion();
      Serial1.println("Poured medium portion");
    }
    else if (buffer_value == 'd')
    {
      bigPortion();
      Serial1.println("Poured large portion");
    }
  }


  buttonState1 = digitalRead(31);

  if (buttonState1 == HIGH) {
    Serial.print("Button1: ");
    Serial.print(buttonState1);
  }


  if (buttonState1 == HIGH) {
    smallPortion();
  }



  buttonState2 = digitalRead(30);
  if (buttonState2 == HIGH) {
    Serial.print("  Button2: ");
    Serial.print(buttonState2);
  }
  if (buttonState2 == HIGH) {

    smallMediumPortion();
  }



  buttonState3 = digitalRead(33);

  if (buttonState3 == HIGH) {
    Serial.print("  Button3: ");
    Serial.print(buttonState3);
  }
  if (buttonState3 == HIGH) {
    mediumPortion();
  }


  buttonState4 = digitalRead(32);

  if (buttonState4 == HIGH) {
    Serial.print("   Button4: ");
    Serial.println(buttonState4);
  }
  if (buttonState4 == HIGH) {

    bigPortion();
  }
  delay(1000);
}
