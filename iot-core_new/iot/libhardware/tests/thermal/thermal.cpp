#include <stdio.h>
#include <hardware/thermal.h>
#include <string.h>
#include <stdlib.h>
#include <cutils/log.h>

#define CPU_CORE_MAX        1

struct thermal_module *gThermalModule;
cpu_usage_t *gCpuUsage;

int main(void)
{
    gThermalModule = NULL;
    gCpuUsage = (cpu_usage_t *)malloc(sizeof(cpu_usage_t) * CPU_CORE_MAX);

    int err = hw_get_module(THERMAL_HARDWARE_MODULE_ID,
            (hw_module_t const **)&gThermalModule);
    if(!err) {
        gThermalModule->getCpuUsages(gThermalModule, gCpuUsage);
        for(int i = 0; i < CPU_CORE_MAX; i++) {
            ALOGD("[%d] online: %d, name: %s, active: %d, total: %d\n",
                    i, gCpuUsage[i].is_online,
                    gCpuUsage[i].name,
                    gCpuUsage[i].active,
                    gCpuUsage[i].total);
        }
    } else {
        printf("Couldn't load %s module (%s)\n",
                THERMAL_HARDWARE_MODULE_ID,
                strerror(-err));
    }
    free(gCpuUsage);

    return 0;
}
