TARGET        := cliente
SOURCE_DIR    := src
OBJ_DIR       := obj
INCLUDE_DIR   := inc
BIN_DIR       := bin
 
SOURCE_EXT    := cpp
SOURCES       := $(shell find $(SOURCE_DIR) -type f -name *.$(SOURCE_EXT))
OBJECTS       := $(patsubst $(SOURCE_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

LIB           := -lssl -lcrypto
INC           := -I $(INCLUDE_DIR)

CXX           := g++ 
CXXFLAGS      := -g -Wall -O3 -std=c++11 

RM            := rm -f

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " $(CXX) $^ -o $(TARGET) $(LIB)"; $(CXX) $^ -o $(BIN_DIR)/$(TARGET) $(LIB)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.$(SOURCE_EXT)
	@mkdir -p $(OBJ_DIR)
	@echo " $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

run: $(TARGET)
	./$(BIN_DIR)/$(TARGET)
clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean