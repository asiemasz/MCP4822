#ifndef MCP4822_H
#define MCP4822_H

#include <stdint.h>

#define REF_VOLTAGE 2.048

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

typedef union {
    MCP4822_OUTPUT                   output;
    uint8_t                          res;
    MCP4822_OUTPUT_GAIN              gain;
    MCP4822_OUTPUT_POWERDOWN_CONTROL powerDown;
    uint8_t                          _config;
} MCP4822_OUTPUT_CONFIG;

typedef void (*MCP4822_regWrite) (const struct MCP4822_device dev, void* data,const uint8_t len);
typedef void (*MCP4822_CSenable) (const struct MCP4822_device dev, uint32_t* GPIO_port, uint8_t GPIO_pin);
typedef void (*MCP4822_CSdisable) (const struct MCP4822_device dev, uint32_t* GPIO_port, uint8_t GPIO_pin);


typedef struct {
    const uint8_t           SS_pin;
    const uint32_t*         SS_Port;
    const MCP4822_regWrite  writeFunction;
    const MCP4822_CSenable  CSenableFunction;
    const MCP4822_CSenable  CSdisableFunction;
} MCP4822_device;

void MCP4822_setValue(const struct MCP4822_device, uint16_t value, MCP4822_OUTPUT_CONFIG config);

void MCP4822_setVoltage(const struct MCP4822_device, float value, MCP4822_OUTPUT_CONFIG config);


#endif