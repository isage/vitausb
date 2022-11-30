PREFIX  ?= $(VITASDK)/arm-vita-eabi
CC      = arm-vita-eabi-gcc
AR      = arm-vita-eabi-ar
CFLAGS  = -Wl,-q -Wall -O3
ASFLAGS = $(CFLAGS)

all: libs

libs:
	vita-libs-gen db/SceUsbd.yml db/SceUsbServ.yml build
	cd build && make && cd ..

clean:
	rm -rf build

install: $(TARGET_LIB)
	@mkdir -p $(DESTDIR)$(PREFIX)/lib/
	cp build/*.a $(DESTDIR)$(PREFIX)/lib/
	@mkdir -p $(DESTDIR)$(PREFIX)/include/psp2
	@mkdir -p $(DESTDIR)$(PREFIX)/include/psp2kern
	cp usbd/user/usbd.h $(DESTDIR)$(PREFIX)/include/psp2
	cp usbd/kernel/usbd.h $(DESTDIR)$(PREFIX)/include/psp2kern
	cp usbserv/user/usbserv.h $(DESTDIR)$(PREFIX)/include/psp2
	cp usbserv/kernel/usbserv.h $(DESTDIR)$(PREFIX)/include/psp2kern
	@echo "Installed!"
