run:
	g++ Final.cpp googletest/build/lib/libgtest.a googletest/build/lib/libgtest_main.a -lpthread -I googletest/googletest/include/ -o Final
	./Final