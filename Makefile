CPP = g++
CFLAGS = -lssl -lcrypto -lpapayitawc -I. -Wall

EXP_DIR = Example

SRC_FILES := $(wildcard $(EXP_DIR)/*.cpp)
OUT_FILES := $(patsubst $(EXP_DIR)/%.cpp,$(EXP_DIR)/%,$(SRC_FILES))

examples: $(OUT_FILES)
	
$(OUT_FILES): $(SRC_FILES) MonguitoData.cpp
	$(CPP) -o $@ $^ $(CFLAGS) 

test: test/test.cpp MonguitoData.cpp
	$(CPP) -o main $^  $(CFLAGS)
