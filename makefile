CC=gcc

GCC_VERSION := $(shell $(CC) --version | head -n 1)
$(info Using compiler: $(GCC_VERSION))

# Default Lapacke: Openblas at CESGA
LDLIBS=-lopenblas -lm
# CFLAGS=-O2 -fno-tree-vectorize
# CFLAGS=-O3 -ftree-vectorize -fopt-info-vec-all
CFLAGS=-Ofast -ftree-vectorize -fopt-info-vec-all
# CFLAGS=-O0

# Other systems (my Debian boxes, for example)
#LDLIBS=-llapacke

# Intel MKL at CESGA
# Module needed: imkl
# => module load openblas
# LDLIBS for intel compiler: icx (module needed: intel)
# Just invoke make like this: make CC=icx
#LDLIBS=-qmkl=sequential -lmkl_intel_lp64

dgesv_v4: dgesv.o timer.o main.o
	$(CC) -o $@ $^ $(LDLIBS)

clean:
	$(RM) *.o *~