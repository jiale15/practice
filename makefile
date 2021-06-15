t:test.cpp
	g++ -std=c++11 -o t cpptest.cpp
	./t
	rm t
debug:
	g++ -std=c++11 -o t cpptest.cpp -g
	gdb t
clean:
	rm t