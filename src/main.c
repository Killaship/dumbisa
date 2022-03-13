#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, sp, ip, numregisters
	} reg;
#define hlt 0
#define add 1
#define push 2
#define pop 3
bool run = true;
int stack[64];
int registers[numregisters];
#define stp (registers[sp])
#define inp (registers[ip])

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
	stp = -1;
	while(run) {
		execute(fetch());
		inp++;
	}
}
