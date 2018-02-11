#include <stdio.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>

#include <binder/ProcessState.h>

#include <binder/IInterface.h>
#include <utils/String16.h>

#include "IotDaemonProxy.h"

int main(void)
{
    printf("####Iot Daemon####\n");

    ::usleep(10000 * 1000);
    android::sp<android::IServiceManager> serviceManager = android::defaultServiceManager();
    android::sp<android::IotDaemonProxy> proxy =
        android::IotDaemonProxy::getInstance();
    android::status_t ret = serviceManager->addService(
            android::IotDaemonProxy::descriptor, proxy);
    if(ret != android::OK) {
        printf("Couldn't register binder service!\n");
        return -1;
    }

    printf("Iot daemmon is now ready!\n");
    android::IPCThreadState::self()->joinThreadPool();
    printf("Iot daemon Done");

    return 0;
}
