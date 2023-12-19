TARGET = ./calc.out
HDRS_DIR = \
	   Calculator
SRCS = \
       main.c \
       func.c \
       Hex.c \
       Oct.c \
       Duo.c \
       Dec.c 
.PHONY: all, build, clean, run

$(TARGET):
	gcc -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build run

build: $(TARGET)

clean:
	rm -rf $(TARGET)

run:
	$(TARGET)
