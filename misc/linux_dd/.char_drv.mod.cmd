savedcmd_/home/neelakanta/misc/linux_dd/char_drv.mod := printf '%s\n'   char_drv.o | awk '!x[$$0]++ { print("/home/neelakanta/misc/linux_dd/"$$0) }' > /home/neelakanta/misc/linux_dd/char_drv.mod
