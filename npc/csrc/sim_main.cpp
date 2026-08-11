#include <Vtop.h>
#include <cstdlib>
#include <nvboard.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME *top);

static void single_cycle() {
    dut.sw = rand() & 3;
    dut.eval();
}

int main() {
    nvboard_bind_all_pins(&dut);
    nvboard_init();

    while (1) {
        single_cycle();
        nvboard_update();
    }
}