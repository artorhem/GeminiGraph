//
// Created by puneet on 12/03/25.
//

#ifndef FLEXOGRAPH_EVAL_MEMCOUNTER_H
#define FLEXOGRAPH_EVAL_MEMCOUNTER_H

#include <sys/resource.h>

namespace _flexograph_profile {
    /**
     * Copied from Blaze. This class is used to measure the memory usage of the program.
     */
    class MemoryCounter {
    public:
        MemoryCounter() {
            getrusage(RUSAGE_SELF, &__memory);
            __previous_mem = __memory.ru_maxrss;
        }

        ~MemoryCounter() {
            getrusage(RUSAGE_SELF, &__memory);
            uint64_t used_mem = __memory.ru_maxrss - __previous_mem;
            printf("MemoryCounter: %lu MB -> %lu MB, %lu MB total\n", __previous_mem/1024, __memory.ru_maxrss/1024, used_mem/1024);
        }

    private:
        struct rusage __memory;
        uint64_t __previous_mem;
    };
} // end namespace _flexograph_profile
#endif //FLEXOGRAPH_EVAL_MEMCOUNTER_H
