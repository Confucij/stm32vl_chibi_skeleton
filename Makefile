#Application name
TARGET=STM32Skeleton

#Toolchain definition
CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJSIZE=arm-none-eabi-size

#Base directory tree
OBJDIR=./obj
INCDIR=./inc
SRCDIR=./src
OUTDIR=./out

INCLUDE = $(addprefix -I, $(shell find $(INCDIR) -type d))

SRC = $(shell find $(SRCDIR) -type f -name *.c)
OBJ = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC:.c=.o))

#-nostartfiles --- prevents compiler to add it's own startup code
#-ffunction-sections -fdata-sections --- combination of both alow linker to 
#					 collect an unused code
CCFLAGS = -g -O0 -mlittle-endian -mthumb -std=c99 -mcpu=cortex-m3
CCFLAGS += -ffunction-sections -fdata-sections -MMD -DSTM32F10X_MD_VL 
#For detailed description refer to https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html#ARM-Options
CCFLAGS += -mno-sched-prolog -mtune=cortex-m3 
LDSCRIPT=stm32f100xb_flash.ld
LDFLAGS=-L$(SRCDIR)/startup_files -ffreestanding -nostartfiles -Wl,-T,$(LDSCRIPT) -Wl,--gc-sections

all: directories $(TARGET).bin 

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $^ $@
	$(OBJSIZE) -d $^

$(TARGET).elf: $(OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OUTDIR)

directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OUTDIR)

.PHONY: all clean cleanall directories

-include $(OBJ:.o=.d)