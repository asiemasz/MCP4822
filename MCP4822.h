#ifndef MCP4822_H
#define MCP4822_H

#include <stdint.h>

typedef enum {
    MCP4822_DAC_A,
    MCP4822_DAC_B
} MCP4822_OUTPUT;

typedef enum {
    MCP4822_OUTPUT_GAIN_x2,
    MCP4822_OUTPUT_GAIN_x1
} MCP4822_OUTPUT_GAIN;

typedef enum {
    MCP4822_OUTPUT_POWERDOWN_CONTROL_BUFFER_DIS,
    MCP4822_OUTPUT_POWERDOWN_CONTROL_BIT
} MCP4822_OUTPUT_POWERDOWN_CONTROL;

typedef struct {
    MCP4822_OUTPUT                   output;
    MCP4822_OUTPUT_GAIN              gain;
    MCP4822_OUTPUT_POWERDOWN_CONTROL powerDown;
} MCP4822_OUTPUT_CONFIG;

typedef void (*MCP4822_regWrite)(const struct MCP4822_device dev, void* data,const uint8_t len);

typedef struct {
    const uint8_t           SS_pin;
    const uint32_t*         SS_Port;
    const MCP4822_regWrite  writeFunction;
    const float             refVoltage;
} MCP4822_device;

void MCP4822_setValue(const struct MCP4822_device, uint16_t value, MCP4822_OUTPUT_CONFIG config);

void MCP4822_setVoltage(const struct MCP4822_device, float value, MCP4822_OUTPUT_CONFIG config);

#endif