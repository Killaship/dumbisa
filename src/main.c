#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, numregisters // Four general-purpose registers, stack pointer, instruction pointer
	} reg;
int registers[numregisters]; // Declaration of the registers' arra#y
typedef enum {
	push, pop, add, hlt, mov, pushr, jmp, print
	} isa; // ISA contained in a typedef enum
bool running = true; // Runs by default, duh
int stack[128];

int ip = 0;
int sp = -1;



const int prgm[32] = {
	push, 'i',
	push, 'h',
	print, 2,
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
	char pchar = 0;
	switch(instruction) {
		case hlt:
			running = false;
			printf("Done!\n");
			break;
		case add:
	        	x = stack[sp--];
	        	y = stack[sp--];
	        	sum = y + x;
	       		sp++; 
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
			popval = stack[sp--];
			printf("popped %d\n", popval);
			printf("Current SP is %d.\n", sp);
			break;
		case print:
			
			for(int i = 1; i < prgm[ip++]; i++) {
				pchar = stack[sp--];
				printf("%c", pchar);
				pchar = 0;
			}
			printf("\n");
			break;
		//case mov:
		//	break;
		//case jmp:
		//	ip = prgm[ip + 1];
		//	break;
	}
}

int main(void) {
	while(running) {
		execute(fetch());
		ip++;
	}
}
