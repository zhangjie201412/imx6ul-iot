#include <inttypes.h>

#include "BpIotDaemon.h"

namespace android {

BpIotDaemon::BpIotDaemon(const sp<IBinder>& impl)
    : BpInterface<IIotDaemon>(impl)
{}

void BpIotDaemon::init()
{
    Parcel data, reply;

    data.writeInterfaceToken(IIotDaemon::getInterfaceDescriptor());
    remote()->transact(INIT, data, &reply);
    reply.readExceptionCode();
}

int32_t BpIotDaemon::open()
{
    Parcel data, reply;

    data.writeInterfaceToken(IIotDaemon::getInterfaceDescriptor());
    remote()->transact(OPEN, data, &reply);
    reply.readExceptionCode();

    return reply.readInt32();
}

int32_t BpIotDaemon::close()
{
    Parcel data, reply;

    data.writeInterfaceToken(IIotDaemon::getInterfaceDescriptor());
    remote()->transact(CLOSE, data, &reply);
    reply.readExceptionCode();

    return reply.readInt32();
}

void BpIotDaemon::binderDied(const wp<IBinder>& who)
{
}

IMPLEMENT_META_INTERFACE(IotDaemon, "com.iot.IIotDaemon");

}
