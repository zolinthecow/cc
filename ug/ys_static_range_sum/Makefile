CPP_FLAGS=-std=c++17 -Wshadow -Wall -D_GLIBCXX_DEBUG

all: ys_static_range_sum

ys_static_range_sum: ys_static_range_sum.cpp
	g++-13 $(CPP_FLAGS) -g ys_static_range_sum.cpp -o ys_static_range_sum

brute: brute.cpp
	g++-13 $(CPP_FLAGS) -g brute.cpp -o brute
	
gen: gen.cpp
	g++-13 $(CPP_FLAGS) -g gen.cpp -o gen
