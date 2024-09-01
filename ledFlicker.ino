// Pin assignments
const int ledPins[] = {3, 5, 6, 9}; // PWM capable pins
const int numLEDs = 4;

// Flicker parameters
int brightness[numLEDs]; // Current brightness of LEDs
int fadeAmount[numLEDs]; // Amount to fade LEDs by

void setup() {
  // Initialize all LED pins as output
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    brightness[i] = random(50, 255); // Start with a random brightness between 50 and 255
    fadeAmount[i] = random(1, 10); // Start with a random fade amount
  }
}

void loop() {
  for (int i = 0; i < numLEDs; i++) {
    // Adjust the brightness for this LED
    brightness[i] += fadeAmount[i];

    // Reverse the direction of fading at the ends of the range
    if (brightness[i] <= 50 || brightness[i] >= 255) {
      fadeAmount[i] = -fadeAmount[i];
    }

    // Write the brightness to the LED
    analogWrite(ledPins[i], brightness[i]);

    // Randomly change the fade amount to create a more erratic flicker
    if (random(0, 100) > 95) {
      fadeAmount[i] = random(1, 10);
    }
  }

  // Small delay to control the flicker speed
  delay(30);
}

