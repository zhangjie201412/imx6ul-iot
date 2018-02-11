#ifndef __IOT_DAEMON_PROXY_H__
#define __IOT_DAEMON_PROXY_H__

#include "BnIotDaemon.h"

namespace android {

class IotDaemonProxy: public BnIotDaemon {

public:
    static IotDaemonProxy* getInstance();

    virtual void init();
    virtual int32_t open();
    virtual int32_t close();

private:
    IotDaemonProxy();
    virtual ~IotDaemonProxy();
    virtual void binderDied(const wp<IBinder>& who);

private:
    static IotDaemonProxy *sInstance;
};
};

#endif
