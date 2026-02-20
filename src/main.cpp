#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author Uttam Singh
 * @date 2026-02-20
 *
 * @details
 * Reads digital input from IR sensor
 * and detects obstacle presence.
 */

int trigpin = 9;
int echopin = 10;

void setup() {
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigpin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    long duration = pulseIn(echopin, HIGH);
    long distance = duration*0.0343/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}