#include <iostream>
#include <string>
#include <math.h>

#include "DRV8871.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char* TAG = "Drive";

extern "C" void app_main() {
    ESP_LOGE(TAG, "Test starting");

    while(1) {
	;
    }

    //should never get here. But, important to keep oled screen in scope
    vTaskSuspend(NULL);
}
