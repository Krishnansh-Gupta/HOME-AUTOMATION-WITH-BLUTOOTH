#define RELAY1 8  // Appliance 1 (e.g., Light)
#define RELAY2 9  // Appliance 2 (e.g., Fan)

char incomingChar;

void setup() {
    pinMode(RELAY1, OUTPUT);
    pinMode(RELAY2, OUTPUT);

    digitalWrite(RELAY1, LOW);  // Relays OFF at startup
    digitalWrite(RELAY2, LOW);

    Serial.begin(9600);  // Start serial communication with HC-05
}

void loop() {
    if (Serial.available()) {
        incomingChar = Serial.read();

        switch (incomingChar) {
            case 'A':   // Turn ON Relay 1
                digitalWrite(RELAY1, HIGH);
                Serial.println("Light ON");
                break;
            case 'a':   // Turn OFF Relay 1
                digitalWrite(RELAY1, LOW);
                Serial.println("Light OFF");
                break;
            case 'B':   // Turn ON Relay 2
                digitalWrite(RELAY2, HIGH);
                Serial.println("Fan ON");
                break;
            case 'b':   // Turn OFF Relay 2
                digitalWrite(RELAY2, LOW);
                Serial.println("Fan OFF");
                break;
            default:
                Serial.println("Invalid Command");
        }
    }
}
