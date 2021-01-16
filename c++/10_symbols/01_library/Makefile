CXX = g++



install: main.x

main.x: libsharedlib.so main.cc
	$(CXX) main.cc -o $@ -lsharedlib -I include -L.
	#export LD_LIBRARY_PATH after this


libsharedlib.so: source/hello.o
	$(CXX) -shared -o $@ $^

source/hello.o: source/hello.cc
	$(CXX) -fpic -o $@ -c $< -Iinclude

source/hello.o: include/hello.h

clean:

	@rm -f *~ */*~ libsharedlib.so source/*.o source/*.x *.x

.PHONY: install
