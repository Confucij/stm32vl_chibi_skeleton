# connect remote gdbserver on port 3333 (default for openocd)
target remote localhost:3333
# reset core and hold in reset
monitor arm semihosting enable
monitor reset halt
# program core with supplied .elf file
load 
# jump to spark core reset handler
jump Reset_Handler
delete
#Stop execution on main function
#break main
# continue execution (TODO: continue in background so we can disconnect while running continues)
#continue
# disconnect from remote. This pauses execution. Detach is not supported.
disconnect
quit