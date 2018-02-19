#define LOG_TAG             "ThermalTest"
#include <stdio.h>
#include <hardware/thermal.h>
#include <string.h>
#include <stdlib.h>
#include <cutils/log.h>

#define CPU_CORE_MAX        1

struct thermal_module *gThermalModule;
cpu_usage_t *gCpuUsage;
temperature_t *gTemperature;

int main(void)
{
    gThermalModule = NULL;
    gTemperature = NULL;
    gCpuUsage = (cpu_usage_t *)malloc(sizeof(cpu_usage_t) * CPU_CORE_MAX);
    gTemperature = (temperature_t *)malloc(sizeof(temperature_t));
    //gTemperature[0].name = (char *)malloc(50);

    ::memset(gTemperature, 0x00, sizeof(temperature_t));

    ALOGD("------MAIN------");
    int err = hw_get_module(THERMAL_HARDWARE_MODULE_ID,
            (hw_module_t const **)&gThermalModule);
    if(!err) {
        /*
        gThermalModule->getCpuUsages(gThermalModule, gCpuUsage);
        for(int i = 0; i < CPU_CORE_MAX; i++) {
            ALOGD("[%d] online: %d, name: %s, active: %d, total: %d",
                    i, gCpuUsage[i].is_online,
                    gCpuUsage[i].name,
                    gCpuUsage[i].active,
                    gCpuUsage[i].total);
        }
        */
        gThermalModule->getTemperatures(gThermalModule, gTemperature, 1);
        ALOGD("Name: %s, Temp: %f", gTemperature[0].name, gTemperature[0].current_value);
    } else {
        ALOGE("Couldn't load %s module (%s)",
                THERMAL_HARDWARE_MODULE_ID,
                strerror(-err));
    }
    //free((void *)gTemperature[0].name);
    free(gTemperature);
    free(gCpuUsage);

    return 0;
}
