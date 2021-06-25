.DEFAULT_GOAL := all
SHELL := /bin/bash

all:
	@if [[ ! -e build/Makefile ]]; then \
		mkdir -p build; \
		cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug; fi
	@make -C build

lib:
	@find source -type f -name "*.cpp" -exec \
		g++ -std=c++17 -O2 -I include -shared -fPIC -o libgraph.so {} +

clean:
	@if [[ -d build ]]; then \
		rm -r build; fi
	@if [[ -e libgraph.so ]]; then \
		rm libgraph.so; fi
