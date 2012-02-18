int GREEN_LED = 12;
int BOARD_LED = 13;

bool configuration = false;

void setup() {
    Serial.begin(115200);
    
    delay(500);
    
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BOARD_LED, OUTPUT);
    digitalWrite(13, LOW);
}

void readData() {
    while(!Serial.available());
    digitalWrite(BOARD_LED, HIGH);
    delay(200);
    while(Serial.available()) {
        Serial.read();
    }
    digitalWrite(BOARD_LED, LOW);
    delay(200);
}

void loop() {
    if (!configuration) {
        Serial.print("$$$");
        configuration = true;
        readData();
        
        Serial.println("S~,0");
        readData();
        
        Serial.println("R,1");
        readData();
        
        digitalWrite(GREEN_LED, HIGH);
    }
}