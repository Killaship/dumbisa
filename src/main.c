#include <stdio.h>
#include <stdbool.h>
typedef enum {
	a, b, c, d, stp, inp, numregisters
	} reg;
static int registers[numregisters];
typedef enum {
	push, pop, add, hlt
	} isa;
bool running = true;
int stack[64];

#define sp (registers[stp])
#define ip (registers[inp])



const int prgm[16] = {
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
	int a;
	int b;
	int sum;
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
			int value = stack[sp--];
			printf("popped %d\n", value);
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
