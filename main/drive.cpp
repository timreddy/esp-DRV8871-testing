#include <iostream>
#include <string>
#include <math.h>

#include "DRV8871.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define MOTOR_PWM_TIMER_RESOLUTION_HZ 10000000 // 10MHz, 1 tick = 0.1us
#define MOTOR_PWM_PERIOD              500      // 50us, 20KHz
#define MOTOR_PWM_PIN1  GPIO_NUM_27
#define MOTOR_PWM_PIN2  GPIO_NUM_15

static const char* TAG = "Drive";

extern "C" void app_main() {
    ESP_LOGI(TAG, "Test starting");
    DRV8871 motor(MOTOR_PWM_PIN1, MOTOR_PWM_PIN2);
    while(1) {
	;
    }

    //should never get here. But, important to keep oled screen in scope
    vTaskSuspend(NULL);
}
