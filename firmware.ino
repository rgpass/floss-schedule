// FLOSS TIMER
// This is my first IoT project. The problem: toothbrushes have timers, floss brushes do not.
// I wanted to have an IoT project that was easy enough across all facets to be implemented quickly, while
// being complicated enough to be interesting.

int led = D0; // Need to have the LED always on
int photoresistor = A0; // aka the PR. What we will measure for light passing through
int power = A5; // Power source for the PR. This is because we want to have a consistent power level.
int onboardLed = D7; // This is how we will indicate that the floss brush is out of the holder

int minThresholdToTrip = 1000; // When the PR is blocked, the voltage will be less than 400 (mV?)
bool isOutOfHolder = false; // Tracks if the brush is out of the holder

int prValue; // The current value of the photoresistor. Allows for a Particle variable to be defined and called for it.
int millisecondsOutOfHolder = 0; // This is the timer for tracking how long it has been out of the holder

int millisecondsPerReading = 500;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(photoresistor, INPUT);
    pinMode(power, OUTPUT);

    digitalWrite(power, HIGH); // To provide a constant power supply to the PR
    digitalWrite(led, HIGH); // Turning on the LED. This will always be on.

    Particle.variable("prValue", &prValue, INT); // Defines the "prValue" variable on Particle. Dev-only.
    Particle.variable("timeOut", &millisecondsOutOfHolder, INT); // Time out of the holder
    Particle.variable("isOut", isOutOfHolder); // Boolean to show if in or out
}

void loop() {
    delay(millisecondsPerReading); // No need to take readings more than twice per second.

    prValue = analogRead(photoresistor);

    isOutOfHolder = prValue > minThresholdToTrip; // high prValue == lots of light, so it is out of the holder

    if (isOutOfHolder) {
        millisecondsOutOfHolder = millisecondsOutOfHolder + millisecondsPerReading;
    }
    else {
        if (millisecondsOutOfHolder > 0) {
            Particle.publish("flossTime", String(millisecondsOutOfHolder), 60, PRIVATE);
        }

        millisecondsOutOfHolder = 0;
    }
}
