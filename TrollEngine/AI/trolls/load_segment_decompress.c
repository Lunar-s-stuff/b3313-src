#include <PR/ultratypes.h>

#include "sm64.h"

#define INCLUDED_FROM_MEMORY_C

#include "buffers/buffers.h"
#include "decompress.h"
#include "game_init.h"
#include "main.h"
#include "memory.h"
#include "segment_symbols.h"
#include "segments.h"
#include "area.h"

#include "AI/personalization_helpers.h"

// round up to the next multiple
#define ALIGN4(val) (((val) + 0x3) & ~0x3)
#define ALIGN8(val) (((val) + 0x7) & ~0x7)
#define ALIGN16(val) (((val) + 0xF) & ~0xF)

struct MainPoolState {
    u32 freeSpace;
    struct MainPoolBlock *listHeadL;
    struct MainPoolBlock *listHeadR;
    struct MainPoolState *prev;
};

struct MainPoolBlock {
    struct MainPoolBlock *prev;
    struct MainPoolBlock *next;
};

struct MemoryBlock {
    struct MemoryBlock *next;
    u32 size;
};

struct MemoryPool {
    u32 totalSpace;
    struct MemoryBlock *firstBlock;
    struct MemoryBlock freeList;
};

extern uintptr_t sSegmentTable[32];
extern u32 sPoolFreeSpace;
extern u8 *sPoolStart;
extern u8 *sPoolEnd;
extern struct MainPoolBlock *sPoolListHeadL;
extern struct MainPoolBlock *sPoolListHeadR;

extern struct MainPoolState *gMainPoolState;

void *dynamic_dma_read(u8 *srcStart, u8 *srcEnd, u32 side);

void *load_segment_decompress(register s32 segment, u8 *srcStart, u8 *srcEnd) {
    register void *dest = NULL;
    register u32 compSize;
    register u8 *compressed;
    register u32 *size;
    
    interceptSegLoad((u8)segment, &srcStart, &srcEnd); // AI/personalization_helpers.c

    compSize = ALIGN16(srcEnd - srcStart);
    compressed = main_pool_alloc(compSize, MEMORY_POOL_RIGHT);

    // Decompressed size from mio0 header
    size = (u32 *) (compressed + 4);

    if (compressed != NULL) {
        dma_read(compressed, srcStart, srcEnd);
        dest = main_pool_alloc(*size, MEMORY_POOL_LEFT);
        if (dest != NULL) {
            decompress(compressed, dest);
            set_segment_base_addr(segment, dest);
            main_pool_free(compressed);
        }
    }
    return dest;
}
