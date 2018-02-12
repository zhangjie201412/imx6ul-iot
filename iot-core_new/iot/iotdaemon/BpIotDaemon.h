#ifndef __BP_IOT_DAEMON_H__
#define __BP_IOT_DAEMON_H__

#include "IIotDaemon.h"

namespace android {
class BpIotDaemon: public BpInterface<IIotDaemon> {
public:
    BpIotDaemon(const sp<IBinder>& impl);

    //Binder interface methods
    virtual void init();
    virtual int32_t open();
    virtual int32_t close();

    virtual void binderDied(const wp<IBinder>& who);
};
};

#endif
