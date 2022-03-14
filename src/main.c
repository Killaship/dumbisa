#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, stp, inp, numregisters
	} reg;
static int registers[numregisters];
typedef enum {
	push, pop, add, hlt
	} isa;
bool run = true;
int stack[64];

#define sp (registers[stp])
#define ip (registers[inp])



const int prgm[32] = {
	push, 2,
	push, 2,
	add,
	pop,
	hlt
};

int fetch() {
	return prgm[sp];
}

void execute(int instruction) {
	
}

int main(void) {
	sp = -1;
	ip = 0;
	while(run) {
		execute(fetch());
		ip++;
	}
}
