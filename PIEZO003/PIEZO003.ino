int notes[] = {262, 294, 330, 349}; 

void setup() { 
  Serial.begin(9600); 
  } 
  
void loop() { 
  int keyVal = analogRead(A0);
    Serial.print("\tKEY VAL :"); Serial.println(keyVal);
    //delay(1000); 
    if(keyVal == 1023){ 
         tone(8, notes[0],100); 
    } 
     else if(keyVal >= 990 && keyVal <= 1010){ 
         tone(8, notes[1],100);
    } 
     else if(keyVal >= 505 && keyVal <= 515){ 
         tone(8, notes[2],100);
    }
      else if(keyVal >= 1 && keyVal <= 500)
    { 
        tone(8, notes[3],100);
    } 
      else{ 
        noTone(8); 
    } 
    } 
