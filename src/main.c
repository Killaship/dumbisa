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

void main()
	while(run) {
		execute(fetch());
		ip++;
	}
}
