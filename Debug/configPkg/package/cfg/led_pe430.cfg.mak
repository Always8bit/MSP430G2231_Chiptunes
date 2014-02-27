# invoke SourceDir generated makefile for led.pe430
led.pe430: .libraries,led.pe430
.libraries,led.pe430: package/cfg/led_pe430.xdl
	$(MAKE) -f C:\Users\Joseph\workspace_v5_5\GraceTest/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Joseph\workspace_v5_5\GraceTest/src/makefile.libs clean

