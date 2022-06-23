ifeq ($(strip $(DEBUG_BUILD)), yes)
    LTO_ENABLE = no
    OPT = g
    OPT_DEFS += -g
endif
