all: double_switch

double_switch: vsrc/double_switch.v csrc/sim_main.cpp
	verilator --cc vsrc/double_switch.v --exe csrc/sim_main.cpp -j 0 --trace-fst --build
	obj_dir/Vdouble_switch

sim: all wave.fst
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gtkwave wave.fst >/dev/null 2>&1 &

include ../Makefile
