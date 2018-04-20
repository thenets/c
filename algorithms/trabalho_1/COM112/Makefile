LIBS  = 
CFLAGS =

DEPENDENCIES = $(shell find . -type f -name "*.c" ! -name "*main*")
MAIN = $(shell find . -type f -name "*main*.c")

build:
	@echo "# BUILDING DEPENDENCIES"
	gcc -c $(DEPENDENCIES) $(CFLAGS) $(LIBS)
	@echo "# BUILDING MAIN AND LINKING"
	gcc $(DEPENDENCIES) $(MAIN) $(CFLAGS) $(LIBS) -o start
	chmod +x start

run:
	./start

build-run: build run

