all: iotd

iotd: main.cpp
	arm-linux-gnueabihf-g++ -std=c++11 -o $@ -I../libs/include -I.. -L../libs -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 $< IotDaemonProxy.cpp -lpthread -lbinder

clean:
	rm -f iotd
