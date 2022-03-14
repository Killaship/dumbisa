#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, stp, inp, numregisters // Four general-purpose registers, stack pointer, instruction pointer
	} reg;
int registers[numregisters]; // Declaration of the registers' array
typedef enum {
	push, pop, add, hlt, set
	} isa; // ISA contained in a typedef enum
bool running = true; // Runs by default, duh
int stack[128];

// Easier declaration of IP and SP
#define sp (registers[stp]) 
#define ip (registers[inp])



const int prgm[16] = { // Program
	push, 2,
	push, 2,
	add,
	pop,
	set, 4, 0,
	hlt
};

int fetch() { // Fetch function
	return prgm[ip];
}

void execute(int instruction) { // Giant switch statement, basically.
	int a;
	int b;
	int sum;
	int popval;
	switch(instruction) {
		case hlt:
			running = false;
			printf("Done!\n");
			break;
		case add:
			a = stack[sp--];
			b = stack[sp--];
			sum = b + a;
			sp++;
			stack[sp] = sum;
			break;
		case push:
			sp++;
			stack[sp] = prgm[++ip];
			break;
		case pop:
			if(sp <= -1) {
				printf("\nError: program tried to pop a nonexistent value.\n");
				running = false;
				break;
			}
			popval = stack[sp--];
			printf("popped %d\n", popval);
			printf("%d", sp);
			break;
		case set:
			registers[prgm[ip + 1]] = prgm[ip + 2];
            		ip = ip + 2;
			break;
	}
}

int main(void) {
	sp = -1;
	ip = 0;
	while(running) {
		execute(fetch());
		ip++;
	}
}
