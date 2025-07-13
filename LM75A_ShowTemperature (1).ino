/*
 * \brief Show temperature in degrees and fahrenheit every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 05 January 2022
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2022 Quentin Comte-Gaz
 * \version 1.2
 */
#include <LM75A.h>
#include <movingAvgFloat.h>
#define window 300
#define AC_RELAY_PIN 27
float currentTemperature;

// Create I2C LM75A instance
LM75A lm75a_sensor(false,  // A0 LM75A pin state (connected to ground = false)
                   false,  // A1 LM75A pin state (connected to ground = false)
                   false); // A2 LM75A pin state (connected to ground = false)
// Equivalent to "LM75A lm75a_sensor;"
movingAvgFloat myAvg(window);  // use 10 data points for the moving average
//myAvg.begin();


void setup(void)
{
  Serial.begin(115200);
  //Serial.println("Temperatures will be displayed every second:");
  pinMode(AC_RELAY_PIN, OUTPUT);
  digitalWrite(AC_RELAY_PIN, LOW);
  myAvg.begin();

}

void loop()
{
  float currentTemperature=Get_Temp();
  float formulaResultAvg = myAvg.reading(A);
  Serial.print(A);
  Serial.print(" ");
  Serial.println(formulaResultAvg);
  HeaterControl(currentTemperature);
  delay(1);
}
