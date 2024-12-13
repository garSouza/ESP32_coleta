#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//int pins[SIZE] = {14, 18, 19, 21, 22, 23, 25, 26, 27, 33, 4, 34};   
//short data[COLETA];
//int clk_pin = 32, interrup_pin = 39, conta = 0, ct = 0;
//bool flag = false;

void setup() {
  gpio_config_t io_config = {
    .pin_bit_mask = (1ULL << GPIO_NUM_32),
    .mode = GPIO_MODE_OUTPUT,
  };
  gpio_config(&io_config);

  gpio_config_t io_config = {
    .pin_bit_mask = (1ULL << GPIO_NUM_39),
    .mode = GPIO_MODE_INPUT,
    .intr_type = GPIO_INTR_POSEDGE,
  };
  gpio_config(&io_config);
}

void app_main()
{
  setup();
  gpio_config_t io_config =
  {
    .intr_type = GPIO_INTR_DISABLE,
    .mode = GPIO_MODE_INPUT,
    .pin_bit_mask = GPIO_SEL_26 | GPIO_SEL_27 | GPIO_SEL_33 | GPIO_SEL_4 | GPIO_SEL_34,
  };
  ESP_ERROR_CHECK(gpio_config(&io_config));
  
}
/*
TESTAR LIMITE DO ESP32(INT, DEPOIS SHORT INT)
FORMAS DE LER 1 BYTE NO ESP32
CONSEGUIR A FONTE DE 5 VOLTS(FUNTEF) 200mA 1W [FEITO]
TENTAR SOLDAR OS JUMPERS
*/

void Ler(){

  uint32_t io_data = REG_READ(GPIO_IN_REG);
}