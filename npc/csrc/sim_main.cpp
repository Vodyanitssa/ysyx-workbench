#include "../obj_dir/Vdouble_switch.h"
#include "verilated_fst_c.h"
#include <stdio.h>

int main(int argc, char **argv) {
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vdouble_switch *top = new Vdouble_switch{contextp};

    Verilated::traceEverOn(true);
    VerilatedFstC *tfp = new VerilatedFstC;

    top->trace(tfp, 99);
    tfp->open("wave.fst");

    for (int i = 0; i < 10 && !contextp->gotFinish(); i++) {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();

        tfp->dump(i * 10);

        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        assert(top->f == (a ^ b));
    }
    tfp->close();

    delete tfp;
    delete top;
}