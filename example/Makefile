TARGET = smbus_example

BUILD_DIR = build

C_SOURCES =  \
	main.c \
	../smbus.c \

# C includes
C_INCLUDES =  \
	-I. \
	-I ../ \

# optimization
OPT = -Os

CFLAGS += $(C_INCLUDES) $(OPT) -Wall -Werror -fdata-sections -ffunction-sections -fno-common -ffunction-sections -fdata-sections -Wextra -Wshadow -Wno-unused-variable -Wimplicit-function-declaration -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes  -MD -Wall -Wundef -Werror -Wpedantic -Wparentheses -Wconversion -Wno-uninitialized

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

ifeq ($(DEBUG), 1)
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(DEBUG_C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(DEBUG_C_SOURCES)))
endif

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)


#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)