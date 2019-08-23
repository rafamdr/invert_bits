all: library test

library:
	gcc -std=c99 -c invert_bits.c -o invert_bits.o
	ar rcs invert_bits.a invert_bits.o
	rm invert_bits.o
	
test:
	gcc -std=c99 test.c invert_bits.c -o test
	./test
	
clean: 
	rm -rf *.a *.o