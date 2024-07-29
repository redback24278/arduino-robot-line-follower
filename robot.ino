const int IN1 =3;
const int IN2 =4;
const int IN3 =5;
const int IN4 =6;

const int ENA =2;
const int ENB =7;

void setup () {
    
    pinMode(9,INPUT);
    pinMode(10,INPUT);
    
    pinMode( IN1 ,OUTPUT);
    pinMode( IN2 ,OUTPUT);
    pinMode( IN3 ,OUTPUT);
    pinMode( IN4 ,OUTPUT);
}

void FORWARD() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void BACKWARD() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void LEFT() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void RIGHT() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void STOP() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void loop() {
    int lsensor=digitalRead(9);
    int rsensor=digitalRead(8);
    
    if((lsensor==HIGH) && (rsensor==HIGH))
    {
        analogWrite(ENA, 120);
        analogWrite(ENB, 120);
        FORWARD();
    }
    
    if((lsensor==HIGH) && (rsensor==LOW))
    {
        analogWrite(ENA, 110);
        analogWrite(ENB, 100);
        RIGHT();
    }
    
    if((lsensor==LOW) && (rsensor==HIGH))
    {
        analogWrite(ENA, 100);
        analogWrite(ENB, 110);
        LEFT();
    }
    else
    {
        STOP();
    }
}
