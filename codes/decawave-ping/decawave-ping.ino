// Hardware Serial 2 pins
#define RXD2 16
#define TXD2 17

void setup() {
  // Initialize Serial1 for debug output
  Serial.begin(115200);
  delay(200);
  Serial.println("System starting...");
  
  // Initialize Serial2 for Decawave communication
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(100);
  
  Serial.println("Serial2 initialized");
}

void loop() {
  // Send status request command 0x32 0x00
  Serial.println("\nSending ping command...");
  Serial2.write(0x32);
  Serial2.write(0x00);
  
  // Wait for response
  delay(100);
  
  // Read and print response
  if (Serial2.available() > 0) {
    Serial.println("Response received:");
    // Should see: 40h 01h 00h 5Ah ...
    while (Serial2.available() > 0) {
      byte response = Serial2.read();
      if (response < 0x10) Serial.print("0");
      Serial.print(response, HEX);
      Serial.print("\h");
      Serial.print(" ");
    }
  } else {
    Serial.print("No response received");
  }
  
  delay(2000); // Wait 1 seconds before sending next ping
}
