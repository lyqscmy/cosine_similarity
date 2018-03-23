.PHONY: all
all: libcosim.so

bench: bench.o cosine_similarity.o
	g++ -std=c++11  -Wall  -Wextra  -Wshadow  -pedantic  -pedantic-errors  -Wfloat-equal  -fstrict-aliasing  -Wzero-as-null-pointer-constant  -Wstrict-aliasing -O3 -march=native  -Werror -o $@  $^ ~/git/OpenBLAS/libopenblas.a -lbenchmark -lpthread -lrt 

bench.o: bench.cpp
	g++ -std=c++11  -Wall  -Wextra  -Wshadow  -pedantic  -pedantic-errors  -Wfloat-equal  -fstrict-aliasing  -Wzero-as-null-pointer-constant  -Wstrict-aliasing -O3  -march=native -Werror -o $@ -c  $^ -I ~/git/OpenBLAS

cosine_similarity.o: cosine_similarity.c
	gcc -std=c99 -Wall -O2 -march=native -o $@ -c $^ -I ~/git/OpenBLAS/

CosineSimilarity.o: CosineSimilarity.c
	gcc -std=c99 -Wall -O2 -march=native -fpic -o $@ -c $^ -I /usr/lib/jvm/java-1.7.0-openjdk-1.7.0.171-2.6.13.0.el7_4.x86_64/include/ \
	-I /usr/lib/jvm/java-1.7.0-openjdk-1.7.0.171-2.6.13.0.el7_4.x86_64/include/linux/

libcosim.so: CosineSimilarity.o cosine_similarity.o
	gcc -std=c99 -shared -Wall -O2 -march=native -shared -o $@  $^ -I ~/git/OpenBLAS/ ~/git/OpenBLAS/libopenblas.a  -lm

test: main.cpp libcosim.so
	g++ -std=c++11 -O2 -march=native -o test main.cpp -L./ -lcosim
run:
	sudo cpupower frequency-set --governor performance
	./bench
	sudo cpupower frequency-set --governor powersave
clean:
	rm -f bench *.o test libcosim.so
