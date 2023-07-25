CPP = g++
CFLAGS = -lssl -lcrypto -lpapayitawc -I. -Wall -O2

EXP_DIR = Example

SRC_FILES := $(wildcard $(EXP_DIR)/*.cpp)
OUT_FILES := $(patsubst $(EXP_DIR)/%.cpp,$(EXP_DIR)/%,$(SRC_FILES))

ME_LIB_DIR = /usr

examples: $(OUT_FILES)
	
$(OUT_FILES): $(SRC_FILES) monguitodata.cpp
	$(CPP) -o $@ $^ $(CFLAGS) 

test: test/test.cpp monguitodata.cpp
	$(CPP) -o main $^  $(CFLAGS)

install: libmonguitodata.so
	@install $^ $(ME_LIB_DIR)/lib/
	@install monguitodata.h $(ME_LIB_DIR)/include/
	@ldconfig

libmonguitodata.so: monguitodata.cpp monguitodata.h
	$(CPP) -fPIC -shared -o $@ monguitodata.cpp $(CFLAGS)