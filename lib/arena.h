#include <iostream>
#include <memory>

/**
 * TODO: Implement an Arena as a Stack data structure;
 * - create()   : Allocate a fixed area of usable memory
 * - destroy()  : Deallocate the created arena;
 * - push()     : Pushing data on to the arena given the size
 * - pop()      : Popping from the arena
 * - clear()    : Clear the arena
 */

typedef struct Arena { 
  std::size_t capacity; 
  std::size_t offset; 
};

namespace Allocator {
  Arena*    create(size_t capacity); 
  void      destroy(Arena *arena); 
}

// Allocating a memory of size `capacity` with a small incremental offset for storing `capacity` and `offset`.
Arena* Allocator::create(size_t capacity) { 
  Arena* arena = (Arena*) malloc(static_cast<size_t>(capacity));
  arena->capacity = static_cast<size_t>(capacity); 
  arena->offset = static_cast<size_t>(sizeof(arena));
  return (arena + arena->offset); 
}

// Destroying the arena manually;
void Allocator::destroy(Arena *arena) { 
  free(arena);
}