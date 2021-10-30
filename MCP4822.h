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
    uint8_t                          _config;
    struct {
        uint8_t powerDown : 1;
        uint8_t gain : 1;
        uint8_t res : 1;
        uint8_t output : 1;
    };
} MCP4822_OUTPUT_CONFIG;

typedef void (*MCP4822_regWrite) (const uint8_t* data,const uint8_t len);
typedef void (*MCP4822_CSenable) (const uint32_t* GPIO_port,const uint8_t GPIO_pin);
typedef void (*MCP4822_CSdisable) (const uint32_t* GPIO_port,const uint8_t GPIO_pin);

typedef struct {
    const uint8_t           SS_pin;
    const uint32_t*         SS_Port;
    const MCP4822_regWrite  writeFunction;
    const MCP4822_CSenable  CSenableFunction;
    const MCP4822_CSenable  CSdisableFunction;
} MCP4822_device;

void MCP4822_setValue(const MCP4822_device* dev,const uint16_t value,const MCP4822_OUTPUT_CONFIG* config);

void MCP4822_setVoltage(const MCP4822_device* dev,const float value,const MCP4822_OUTPUT_CONFIG* config);


#endif