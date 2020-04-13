#include <SoftwareSerial.h>
int bluetoothTx = 2; // D2 to TXD

int bluetoothRx = 3; // D3 to RXD  (Warning! See Text)

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()

{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(115200);
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);

}

void loop()

{
  if (bluetooth.available())

  {
    char response  =(char) bluetooth.read();
    Serial.print(response);
    if(response == '1')digitalWrite(13,HIGH);
    else if(response == '0')digitalWrite(13,LOW);

  }

  if (Serial.available())

  {

    bluetooth.print((char)Serial.read());

  }
}
