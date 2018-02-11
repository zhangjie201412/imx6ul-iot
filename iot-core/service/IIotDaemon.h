#ifndef __IIOT_DAEMON_H__
#define __IIOT_DAEMON_H__

#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class IIotDaemon: public IInterface, public IBinder::DeathRecipient {
public:
    //DECLARE_META_INTERFACE(IotDaemon);
    static const android::String16 descriptor;
    static android::sp<IIotDaemon> asInterface(
            const android::sp<android::IBinder>& obj);
    virtual const android::String16& getInterfaceDescriptor() const;
    IIotDaemon();                                                     
    virtual ~IIotDaemon();                                            
    enum {
        INIT  = IBinder::FIRST_CALL_TRANSACTION + 0,
        OPEN  = IBinder::FIRST_CALL_TRANSACTION + 1,
        CLOSE = IBinder::FIRST_CALL_TRANSACTION + 2,
    };

    virtual void init() = 0;
    virtual int32_t open() = 0;
    virtual int32_t close() = 0;
};

};

#endif
