
#include <SoftwareSerial.h>
SoftwareSerial GM65(3,2); // RX, TX
String incomingData = "";

void setup() {
 // Start serial communication with the GM65 module
  GM65.begin(9600);
    //lcd.begin(9600);
  // Start serial communication with the computer
  Serial.begin(9600);
  
}
void loop() {
 
  // Read data from the GM65 module
  if (GM65.available() > 0) {
   
    incomingData = GM65.readString();
    //Serial.println(incomingData);
    incomingData.trim();

    //Set the checking condition you would like ie 
    // Check if incomingData matches the desired value
    if (incomingData == "BSC/ELE/08/19") {
      Serial.println( "WELCOME ");
      Serial.println("LAST NAME   : MVULA ");
       
      Serial.println("FIRST NAME  : ENOCK ");
      Serial.println("TITLE       : STUDENT ");
      
      Serial.print("REG. NUMBER : ");
      
      Serial.println(incomingData);
      }
      
    else
    {
         Serial.println("");
            Serial.println("ACCESS DENIED");
               Serial.println("");
               Serial.print("USER : ");
                Serial.println(incomingData);
               Serial.println("Tried to login");
     }
    Serial.println("");
  }
}
