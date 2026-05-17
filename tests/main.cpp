#include "../lib/arena.h"
#include <iostream>

struct Node { 
  uint64_t x; 
  uint64_t y;
}

int main(void) { 
  Arena* arena = Allocator::create(1024); 

}