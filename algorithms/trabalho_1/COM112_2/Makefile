LIBS  = 
CFLAGS =

DEPENDENCIES = $(shell find . -type f -name "*.c" ! -name "*main*")
MAIN = $(shell find . -type f -name "*main*.c")

COLOR_CYAN='\033[0;36m'
COLOR_DEFAULT='\033[0m'

build:
	@echo $(COLOR_CYAN)"# BUILDING DEPENDENCIES"$(COLOR_DEFAULT)
	gcc $(DEPENDENCIES) $(CFLAGS) -c $(LIBS)
	@echo $(COLOR_CYAN)"# BUILDING MAIN AND LINKING"$(COLOR_DEFAULT)
	gcc $(DEPENDENCIES) $(MAIN) $(CFLAGS) $(LIBS) -o start
	chmod +x start

run:
	rm *.txt
	./start

build-run: build run

