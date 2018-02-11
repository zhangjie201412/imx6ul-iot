#ifndef __BN_IOT_DAEMON_H__
#define __BN_IOT_DAEMON_H__

#include "IIotDaemon.h"

namespace android {

class BnIotDaemon: public BnInterface<IIotDaemon> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply,
        uint32_t flags = 0);
};
};

#endif
