#include <inttypes.h>

#include "BnIotDaemon.h"

namespace android {

status_t BnIotDaemon::onTransact(uint32_t code, const Parcel& data, Parcel* reply,
        uint32_t flags)
{
    switch(code) {
        case INIT: {
            CHECK_INTERFACE(IIotDaemon, data, reply);
            init();
            reply->writeNoException();
            return NO_ERROR;
        }
        case OPEN: {
            CHECK_INTERFACE(IIotDaemon, data, reply);
            const int32_t ret = open();
            reply->writeNoException();
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        case CLOSE: {
            CHECK_INTERFACE(IIotDaemon, data, reply);
            const int32_t ret = close();
            reply->writeNoException();
            reply->writeInt32(ret);
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

}
