unsigned long Start;
unsigned long Count;
int t;


void setup() {
  Serial.begin(115200); // Open a serial coms channel
  analogReadResolution(16); // Can be 8, 10, 12, 16
  analogReadAveraging(1); // can be 1, 2, 4, 8, 16 or 32
  analogReference(0); // Voltage reference - see docs

}

void loop() {
  if (Serial.available()){ // Waiting for commands from the computer
    char input = Serial.read(); // read the command
    
    if (input == 'a'){ // Take a single reading and send over serial (pin A21)
      Serial.println(analogRead(A21));
    }
    
    if (input == 'd'){ // Take 20k readings and send over serial (read one, send one)
      int a0;
      t = micros(); // This lets us see how long the loop takes to execute
      for(int i = 0; i < 20000 ; i++){
        a0 = analogRead(A21);             // read data
        Serial.write((a0 >> 8) & 0xFF); // Send the upper byte first
        Serial.write((a0 & 0xFF)); // Send the lower byte
      }
      t = micros() - t; // Store the time taken - can be read with command 't'
    }
    
    if (input == 'f'){ // store 20,000 samples then send
      int a0;
      int reads[20000];
      t = micros();
      for(int i = 0; i < 20000 ; i++){// read data
        reads[i] = analogRead(A21);             
      }
      t = micros() - t;
      for(int i = 0; i < 20000 ; i++){//send data (as two bytes rather than text)
        a0 = reads[i];
        Serial.write((a0 >> 8) & 0xFF); // Send the upper byte first
        Serial.write((a0 & 0xFF)); // Send the lower byte
      }
      
    }
    
    if (input == 'g'){ // store 20,000 samples then send, sampling from 10 pins in series (2k samples per pin)
      int a0;
      int reads[20000];
      int pins[10] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};
      t = micros();
      for(int i = 0; i < 2000 ; i++){
        for (int j = 1; j < 10; j++){
          reads[i*10+j] = analogRead(pins[j]);  
        }
      }
      t = micros() - t;
      for(int i = 0; i < 20000 ; i++){
        a0 = reads[i];
        Serial.write((a0 >> 8) & 0xFF); // Send the upper byte first
        Serial.write((a0 & 0xFF)); // Send the lower byte
      }
      
    }
    
    if (input == 't'){ // Return the time taken (in microseconds) for the most recetn operation.
      Serial.println(t);
    }

    // You can add commands here...
  }
}
