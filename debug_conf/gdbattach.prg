# set limits of the hardware
set remote hardware-watchpoint-limit 6
set remote hardware-breakpoint-limit 4

monitor arm semihosting enable
# jump to spark core reset handler
jump Reset_Handler

continue