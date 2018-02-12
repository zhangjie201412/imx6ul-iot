#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "IotDaemonProxy.h"

namespace android {

IotDaemonProxy* IotDaemonProxy::sInstance = NULL;

IotDaemonProxy* IotDaemonProxy::getInstance()
{
    if(sInstance == NULL) {
        sInstance = new IotDaemonProxy();
    }
    return sInstance;
}

IotDaemonProxy::IotDaemonProxy()
{
    printf("++IotDaemonProxy++\n");
}

IotDaemonProxy::~IotDaemonProxy()
{
    printf("--IotDaemonProxy--\n");
}

void IotDaemonProxy::init()
{
    printf("++init++\n");
}

int32_t IotDaemonProxy::open()
{
    printf("++open++\n");
    return 0;
}

int32_t IotDaemonProxy::close()
{
    printf("++close++\n");
    return 0;
}

void IotDaemonProxy::binderDied(const wp<IBinder>& who)
{
    printf("++binder died++\n");
}

}

