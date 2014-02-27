## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430 linker.cmd package/cfg/led_pe430.oe430

linker.cmd: package/cfg/led_pe430.xdl
	$(SED) 's"^\"\(package/cfg/led_pe430cfg.cmd\)\"$""\"C:/Users/Joseph/workspace_v5_5/GraceTest/.config/xconfig_led/\1\""' package/cfg/led_pe430.xdl > $@
