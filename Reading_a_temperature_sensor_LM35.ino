/*Reading a temperature sensor LM35*/

#include <liquidCrystal.h>
liquidCrystal lcd(12,11,5,4,3,2);

int temp;
int Setpoint = 68;
int Setpoint1 = 60;

void setup ()
{
  lcd.begin (16,2);
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  
  void loop ()
  {
    Temp = analogRead(A0) * 500.0 / 1023.0; // read the temperature sensor e converte para graus celsius
    lcd.setcursor (0,0);
    lcd.print ("TEMPERATURE=");
    lcd.print (Temp);
    lcd.print (char(223));//insert the o
    lcd.print ("C"); //Insert the C
    lcd.setcursor (1,0);
    
    if (digitalRead(6)==0) // Level sensor to ground? (off)
    {
      lcd.setcursor (0,1);
      lcd.print("FULL");
        if (Temp < Setpoint) //
        {
          digitalWrite(7, HIGH);  //Turn on the heater
        }
    if (Temp>Setpoint1)
       {
         digitalWrite(7, LOW);  //Turn off the heater
       } 
    }
    else (digitalWrite(7,LOW);  //Turn off the heater
    lcd.setcursor (0,1);
    lcd.print("EMPTY");
  }
}
  
