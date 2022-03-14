#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, sp, ip, numregisters // Four general-purpose registers, stack pointer, instruction pointer
	} reg;
int registers[numregisters]; // Declaration of the registers' arra#y
typedef enum {
	push, pop, add, hlt, set, pushr
	} isa; // ISA contained in a typedef enum
bool running = true; // Runs by default, duh
int stack[128];




const int prgm[32] = {
	push, 2,
	push, 2,
	add,
	pop,
	set, b, 4,
	pushr, b,
	pop,
	hlt
};

int fetch() { // Fetch function
	return prgm[ip];
}

void execute(int instruction) { // Giant switch statement, basically.
	int x;
	int y;
	int sum;
	int popval;
	switch(instruction) {
		case hlt:
			running = false;
			printf("Done!\n");
			break;
		case add:
			x = stack[sp - 1];
			y = stack[sp - 1];
			sum = y + x;
			sp = sp + 1;
			stack[sp] = sum;
			break;
		case push:
			sp = sp + 1;
			stack[sp] = prgm[++ip];
			break;
	/*	case pushr:
			sp = sp + 1;
			stack[sp] = registers[++ip];
			break; */
		case pop:
			popval = stack[sp - 1];
			printf("popped %d\n", popval);
			printf("%d", sp);
			break;
		/*case set:
			registers[prgm[ip + 1]] = prgm[ip + 2];
			ip = ip + 2;
			break;*/
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
