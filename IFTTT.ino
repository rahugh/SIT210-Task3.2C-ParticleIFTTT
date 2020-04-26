/*
 * Project IFTTT
 * Description:
 * Author:
 * Date:
 */

int photosensor = A2;
int lightvalue;
bool sunlight = false;
const int THRESHHOLD = 100;

void setup() {

}

void loop() {

    lightvalue = analogRead(photosensor);

    if (!sunlight && lightvalue >= THRESHHOLD) {
        sunlight = true;
        Particle.publish("sunlight", "true");
    } else if (sunlight && lightvalue < THRESHHOLD) {
        sunlight = false;
        Particle.publish("sunlight", "false");
    }

    delay(500);
}
