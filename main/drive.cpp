#include <iostream>
#include <string>
#include <math.h>

#include "DRV8871.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define MOTOR_PWM_PIN1  GPIO_NUM_27
#define MOTOR_PWM_PIN2  GPIO_NUM_15

static const char* TAG = "Drive";

extern "C" void app_main() {
    ESP_LOGI(TAG, "Test starting");

    ESP_ERROR_CHECK(gpio_reset_pin(MOTOR_PWM_PIN1));
    ESP_ERROR_CHECK(gpio_set_direction(MOTOR_PWM_PIN1,GPIO_MODE_OUTPUT));
    ESP_ERROR_CHECK(gpio_set_pull_mode(MOTOR_PWM_PIN1, GPIO_FLOATING));
    ESP_ERROR_CHECK(gpio_set_level(MOTOR_PWM_PIN1,0));

    ESP_ERROR_CHECK(gpio_reset_pin(MOTOR_PWM_PIN2));
    ESP_ERROR_CHECK(gpio_set_direction(MOTOR_PWM_PIN2,GPIO_MODE_OUTPUT));
    ESP_ERROR_CHECK(gpio_set_pull_mode(MOTOR_PWM_PIN2, GPIO_FLOATING));
    ESP_ERROR_CHECK(gpio_set_level(MOTOR_PWM_PIN2,0));

    vTaskDelay(pdMS_TO_TICKS(1000));

    //DRV8871 motor(MOTOR_PWM_PIN1, MOTOR_PWM_PIN2);
    DRV8871 motor(MOTOR_PWM_PIN1, MOTOR_PWM_PIN2);
    motor.setSpeed(0);

    int8_t speed = 0;
    int8_t increment = 1;

    while(1) {
        motor.setSpeed(speed);

        if(speed == INT8_MAX || speed == INT8_MIN) {
            increment *= -1;
            ESP_LOGI(TAG, "Reached speed %d. Changing ramp direction.", speed);
        }

        speed += increment;
        vTaskDelay(pdMS_TO_TICKS(40));
    }

    //should never get here. But, important to keep oled screen in scope
    vTaskSuspend(NULL);
}
