#include "MCP4822.h"
#include <assert.h>

void MCP4822_setValue(const MCP4822_device* dev,const uint16_t value,const MCP4822_OUTPUT_CONFIG* config) {
    assert(value < 4096);
    dev->CSenableFunction(dev->SS_Port, dev->SS_pin);

    uint8_t data[2];
    data[0] = (config->_config << 4) | ((value >> 8) & 0xF);
    data[1] = value & 0xFF;

    dev->writeFunction(data, 2);

    dev->CSdisableFunction(dev->SS_Port, dev->SS_pin);
}

void MCP4822_setVoltage(const MCP4822_device* dev,const float value,const MCP4822_OUTPUT_CONFIG* config) {
    assert(value >= 0);
    uint16_t rawVal;
    if(value > 2.048 * (2 - config->gain)) 
        rawVal = 4095;
    else
        rawVal = value * 4096 / (REF_VOLTAGE * (2 - config->gain)); 
    MCP4822_setValue(dev, rawVal, config);
}


