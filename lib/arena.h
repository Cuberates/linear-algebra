#include <iostream>
#include <memory>

#define ARENA_BASE_SIZE sizeof(Arena)

typedef struct Arena { 
  std::size_t capacity; 
  std::size_t offset; 
  std::byte* buffer;
};

namespace Allocator {
  Arena*    arena_create(size_t capacity); 
  void      arena_destroy(Arena *arena); 
  void*     arena_push(Arena* arena, std::size_t size); 
  void      arena_pop(Arena* arena, std::size_t size);
  void      arena_clear(Arena* arena);
}

Arena* Allocator::arena_create(size_t capacity) { 
  Arena* arena = static_cast<Arena*>(std::malloc(sizeof(Arena) + capacity));
  if (!arena) 
    return nullptr; 
  arena->capacity = capacity; 
  arena->offset = 0; 
  arena->buffer = reinterpret_cast<std::byte*>(arena) + sizeof(Arena);
}

void Allocator::arena_destroy(Arena *arena) { 
  std::free(arena);
}

void* Allocator::arena_push(Arena *arena, std::size_t size) { 
  if (arena->offset + size > arena->capacity) 
    return nullptr;

  void *ptr = arena->buffer + arena->offset;
  arena->offset += size;

  return ptr;
}