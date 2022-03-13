#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, sp, ip, numregisters
	} reg;
typedef enum {
	push, pop, add, hlt
	} isa;

bool run = true;
int stack[64];
int registers[numregisters];
#define stp (registers[sp])
#define inp (registers[ip])
stp = -1;

const int prgm[32] = {
	push, 2,
	push, 2,
	add,
	pop,
	hlt
};

int fetch() {
	return prgm[inp];
}

void execute(int instruction) {
	
}

void main() {
	while(run) {
		execute(fetch());
		inp++;
	}
}
