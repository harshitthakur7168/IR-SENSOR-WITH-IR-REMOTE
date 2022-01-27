#include <IRremote.h>
 
int IR_Recv = 11;   
int bluePin = 13;
int greenPin = 12;
int yellowPin = 10;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  
  irrecv.enableIRIn(); 
  pinMode(13, OUTPUT);      
  pinMode(12, OUTPUT);      
  pinMode(10, OUTPUT);      

}
 
void loop(){
  
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    
    switch (results.value){
      case 16582903:
        digitalWrite(13, HIGH);
        break;   
      case 16591063:
        digitalWrite(13, LOW);   
        break;
       case 16615543:
        digitalWrite(12, HIGH);
        break;           
       case 16623703:
        digitalWrite(12, LOW);
        break;       
       case 16599223:
        digitalWrite(10, HIGH);
        break;       
       case 16607383:
        digitalWrite(10, LOW);
        break;
     
    }
    irrecv.resume(); 
  }
  delay(10);
}
