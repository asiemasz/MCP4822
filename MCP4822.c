#include "MCP4822.h"

void MCP4822_setValue(const MCP4822_device* dev, uint16_t value, MCP4822_OUTPUT_CONFIG* config) {
    dev->CSenableFunction(dev->SS_Port, dev->SS_pin);

    uint8_t data[2];
    data[0] = (config->_config << 4) | ((value << 8) & 0xF);
    data[1] = value & 0xFF;

    dev->writeFunction(data, 2);

    dev->CSdisableFunction(dev->SS_Port, dev->SS_pin);
}

void MCP4822_setVoltage(const MCP4822_device* dev, float value, MCP4822_OUTPUT_CONFIG* config) {
    uint16_t rawVal = value * 4096 / (REF_VOLTAGE * config->gain); 
    MCP48222_setValue(dev, rawVal, config);
}


