all: servicemanager 

servicemanager: binder.o service_manager.o
	arm-linux-gnueabihf-gcc -o $@ $^

clean:
	rm -f *.o servicemanager
	
%.o: %.c
	arm-linux-gnueabihf-gcc -I.. $(CFLAGS) -c -o $@ $<
