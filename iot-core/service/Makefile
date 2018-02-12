all: iotdaemon client

iotdaemon: main.cpp
	arm-linux-gnueabihf-g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< BnIotDaemon.cpp BpIotDaemon.cpp IotDaemonProxy.cpp -lpthread -lbinder

client: client.cpp
	arm-linux-gnueabihf-g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< BpIotDaemon.cpp -lpthread -lbinder

clean:
	rm -f iotdaemon client
