savedcmd_/home/neelakanta/misc/linux_dd/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/neelakanta/misc/linux_dd/"$$0) }' > /home/neelakanta/misc/linux_dd/mychardev.mod
