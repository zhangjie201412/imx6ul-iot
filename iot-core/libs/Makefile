all: libbinder.a

include cutils/Makefile
include utils/Makefile
include binder/Makefile

CFLAGS := -I.. -Iinclude -DHAVE_PTHREADS -DHAVE_SYS_UIO_H -DHAVE_ENDIAN_H -DHAVE_ANDROID_OS=1 -std=c++11

libbinder.a: $(objects)
	arm-linux-gnueabihf-ar cr $@ $^

clean:
	rm -f  libbinder.a `find -name \*.o`

%.o : %.cpp
	arm-linux-gnueabihf-gcc $(CFLAGS) -c -o $@ $<
%.o : %.c
	arm-linux-gnueabihf-gcc $(CFLAGS) -c -o $@ $<
