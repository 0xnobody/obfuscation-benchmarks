#pragma once

// All annotations used in Polaris should be defined here
// We can enable on a per-file bassis during compilation.
#define POLARIS_ANNOTATE \
 __attribute(( \
    __annotate__(( \
        "aliasaccess,boguscfg,customcc,flatten,indirectbr,indirectcall,linearmba,mergefunction,substitution" \
    )) \
))

#ifdef BACKEND_OBFU_ENABLED
#define BACKEND_OBFU asm("backend_obfu")
#endif
