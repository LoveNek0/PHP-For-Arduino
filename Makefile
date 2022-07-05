PROJECT = $(shell basename $(CURDIR))

INC_DIR = include
SRC_DIR = src
OUT_DIR = out
BINARY_DIR = $(OUT_DIR)/bin
LIBRARY_DIR = $(OUT_DIR)/lib

OUTPUT_BIN = $(BINARY_DIR)/$(PROJECT)
OUTPUT_LIB = $(LIBRARY_DIR)/$(PROJECT)

INCLUDE_FILES = $(shell find $(INC_DIR) -name "*.h")
SOURCE_FILES = $(shell find $(SRC_DIR) -name "*.cpp")

build:
	@rm -rf $(BINARY_DIR)
	@echo "Compiling source files to binary..."
	@mkdir -p $(SRC_DIR) $(OUT_DIR) $(BINARY_DIR)
	@g++ $(SOURCE_FILES) -I$(INC_DIR) -o $(OUTPUT_BIN)
	@echo "Compilation completed!"
	@echo "Output file: $(OUTPUT_BIN)"
	
run: compile-bin
	@echo "Running \"$(OUTPUT_BIN)\"..."
	@./$(OUTPUT_BIN) $(RUN_ARGS)
	@echo "Program exited with code $$?"
