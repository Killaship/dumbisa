#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, stp, inp, numregisters
	} reg;
typedef enum {
	push, pop, add, hlt
	} isa;
bool run = true;
int stack[64];
reg registers[numregisters];
#defne = sp (registers[stp])
#define ip (registers[inp])
sp = -1;


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

int main(void) {
	while(run) {
		execute(fetch());
		inp++;
	}
}
