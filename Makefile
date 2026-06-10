.PHONY: build

build:
	chmod u+x ./build.sh
	./build.sh 2> /dev/null

prerequisites: build

target: prerequisites 
