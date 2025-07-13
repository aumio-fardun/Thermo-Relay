float Get_Temp(void){

  float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();

  if (temperature_in_degrees == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature");
  }
  else
  {
    //float formulaResultAvg = myAvg.reading(temperature_in_degrees);
    //Serial.print("Temperature: ");
    //Serial.print(" degrees (");
    //Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees));
    //Serial.println(" fahrenheit)");
  }

  return temperature_in_degrees;

  
  
}

void HeaterControl(float temperature)
{
  
  if (temperature > 60.0)
  {
    digitalWrite(AC_RELAY_PIN, HIGH);
    Serial.println("Temperature > 60°C. Heater turned ON.");
  }
  
  else if (temperature < 20.0)
  {
    digitalWrite(AC_RELAY_PIN, LOW);
    Serial.println("Temperature < 20°C. Heater turned OFF.");
  }
  
}



/*#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H
/**
 * Author  : Nico Verduin (nico.verduin@ziggo.nl)
 * Date   : 31-8-2016
 *
 * generic MovingAverage class
 * This is a template class that allows one to create a parametric moving average object.
 * The class will be initialized based on a template parameter (i.e. float, double, int , uint16_t etc)
 * non floating point objects will always return a new moving average based on the same type as
 * it was initialized.
 * Keep in mind that floating point on Arduino has a limitation in accuracy up to 6-7 digits.
 * If the input for the MA is too lager, intermediate results will lose significant digits causing
 * inaccuracy.
 *
 * functions
 * ---------
 * MovingAverage(uint16_t)    Constructor creating object suitable for the parameterized number of entries
 * ~MovingAverage()       Destructor freeing up unallocated memory
 * T CalculateMovingAverage(T)  Calculate a moving average based on type T (can be any type i.e. float, int etc)
 *                and returns type T (same as values passed)
 *
 * assert
 * ------
 * Operational guard routine  The library has an assert built in but is turned off under normal conditions.
 *                However switching this on through #define DEBUG_MODE will ensure that the
 *                program halts if more memory is requested than available. For example in an
 *                Arduino UNO Ram is limited to 2K. If you want to do a moving average on 1000
 *                floating point values this would require (1000 x 4 bytes) = 4000 bytes. The check
 *                will output an error on the Serial if this occurs.
 *
 *  using RAM effici�ntly
 *  ---------------------
 *  If a moving average does not need to stay alive until the Arduino is reset or switch off, use the
 *  deconstructor (! MovingAverage() to free up Ram.
 *  This will free up the dynamic allocated internal array of sizeof variable type * number of entries for
 *  moving average.
 */

 
