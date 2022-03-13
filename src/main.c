#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, sp, ip
	} registers;
#define hlt 0
#define add 1
#define push 2
#define pop 3
bool run = true;
int stack[64];
#define sp (registers[sp])
#define ip (registers[ip])

const int prgm {
	push, 2,
	push, 2,
	add,
	pop,
	hlt
};

int fetch() {
	return prgm[ip];
}

void execute(int instruction) {
	
}

void main() {
	sp = -1;
	while(run) {
		execute(fetch());
		ip++;
	}
}
