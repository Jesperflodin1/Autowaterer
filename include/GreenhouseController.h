#ifndef _GreenhouseController_h
#define _GreenhouseController_h

#include "Display.h"
#include "GreenhouseControllerConfiguration.h"
#include "PinConfiguration.h"
#include "Sensor.h"

class GreenhouseController {

private:
    GreenhouseControllerConfiguration GreenhouseConfiguration {};
    Sensor Sensors[NUM_SENSORS] = { { 0, GreenhouseConfiguration }, { 1, GreenhouseConfiguration }, { 2, GreenhouseConfiguration } };
    uint8_t lastUpdatedSensor { NUM_SENSORS - 1 };

public:
    unsigned long currentMillis = 0; // stores the value of millis() in each iteration of loop()

    void begin();

    void readSensors();

    byte* readSerializedSensors(byte* emptyBytes, char delimiter);

    void handleSensor(uint8_t);

    Sensor& getSensor(uint8_t sensor) { return Sensors[sensor]; }

    GreenhouseControllerConfiguration& getConfigurationController() { return GreenhouseConfiguration; }
    GreenhouseControllerConfiguration::Configuration& getConfiguration() { return getConfigurationController().getGlobalConfig(); }
    GreenhouseControllerConfiguration::SensorConfiguration& getSensorConfiguration(uint8_t sensor) { return getConfigurationController().getSensorConfig(sensor); }
};

#endif
