# =========================================================
# SDL3 + C++17 Makefile (simple, local folder only)
# =========================================================

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# =========================================================
# 🔧 SDL include & lib paths
# =========================================================
SDL_INC := C:/Users/kumar/SDL3-devel-3.2.24-VC/SDL3-3.2.24/include
SDL_LIB := C:/Users/kumar/SDL3-devel-3.2.24-VC/SDL3-3.2.24/lib/x64

CXXFLAGS += -I$(SDL_INC)
LDFLAGS  := -L$(SDL_LIB) -lSDL3

# =========================================================
# Source and object files (current folder only)
# =========================================================
ifeq ($(OS),Windows_NT)
    SRCS := $(shell powershell -Command "Get-ChildItem -Filter *.cpp | ForEach-Object { ($$_.FullName -replace '\\', '/') }")
    RM := powershell -Command "Remove-Item -ErrorAction SilentlyContinue *.o"
else
    SRCS := $(shell find . -maxdepth 1 -name '*.cpp')
    RM := rm -f *.o
endif

OBJS := $(SRCS:.cpp=.o)
TARGET := main

# =========================================================
# Build rules
# =========================================================
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)
	@echo Cleaning up object files...
	@$(RM)
	@echo Build successful!

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================================================
# Utility targets
# =========================================================
clean:
	@$(RM)
	@rm -f $(TARGET) 2>nul || true
	@echo Clean done.

run: $(TARGET)
	./$(TARGET)
