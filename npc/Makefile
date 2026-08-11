sim: all wave.fst
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gtkwave wave.fst >/dev/null 2>&1 &

include ../Makefile
include ../nvboard/example/Makefile
