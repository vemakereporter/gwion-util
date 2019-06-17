ifeq (${USE_DOUBLE}, 1)
CFLAGS +=-DUSE_DOUBLE -DSPFLOAT=double
else
CFLAGS+=-DSPFLOAT=float
endif

ifeq (${USE_COVERAGE}, 1)
CFLAGS += -ftest-coverage -fprofile-arcs
LDFLAGS += --coverage
endif

ifeq (${USE_MEMCHECK}, 1)
CFLAGS += -g -Og
else
CFLAGS += -DNDEBUG
endif

ifeq (${USE_LTO}, 1)
CFLAGS += -flto
LDFLAGS += -flto
endif

ifeq (${USE_GETTEXT}, 1)
CFLAGS += -DUSE_GETTEXT=1
endif

ifeq ($(shell uname), Darwin)
AR = /usr/bin/libtool
AR_OPT = -static $^ -o $@
else
AR = ar
AR_OPT = rcs $@ $^
endif
