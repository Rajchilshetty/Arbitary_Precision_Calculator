OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
Raj.out: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.out *.o