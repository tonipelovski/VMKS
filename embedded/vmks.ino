#include <SoftwareSerial.h>
int bluetoothTx = 2; // D2 to TXD

int bluetoothRx = 3; // D3 to RXD  (Warning! See Text)

int status = 0;
int current_status = 0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()

{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(115200);
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
  pinMode(12, INPUT);
  if(digitalRead(12)){
      bluetooth.println("       locked");
      status = 1;
  }else{
      bluetooth.println("       unlocked");
      status = 0;
  }
}

void loop()

{
  
  if (bluetooth.available())

  {
    char response  =(char) bluetooth.read();
    Serial.print(response);
    if(response == '1'){
      digitalWrite(13,HIGH);
      current_status = 1;
    }
    else if(response == '0'){
      digitalWrite(13,LOW);
      current_status = 0;
    }

  }
  if(status != current_status){
    if(digitalRead(12)){
        bluetooth.println("        locked");
        Serial.println("locked");
    }else{
        bluetooth.println("        unlocked");
        Serial.println("unlocked");
    }
  }
  
  if (Serial.available())

  {
    bluetooth.print((char)Serial.read());
  }
  status = current_status;


}
