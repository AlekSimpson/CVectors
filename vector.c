#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <stdarg.h>

typedef struct vec {
  float threshold; // percent of array filled until reallocation
  void* vec;
  int length;
} Vector;

Vector* vnew(void* items, int itemsCount) {
  Vector* newVector = (Vector*) malloc(sizeof(Vector));

  float size = ((float)itemsCount * 1.3);
  int sizeOfElement = sizeof(typeof(items[0]));

  newVector->vec = (void*) malloc(size * sizeOfElement);
  newVector->length = itemsCount;
  newVector->threshold = size * 0.9;

  return newVector;
}

void vdelete(Vector* v) {
  free(v->vec);
  free(v);
}

void vappend(Vector* vector, void* element) {
  // if new item goes past 90% threshold then reallocate
  if ((vector->length + 1) > (vector->threshold)) {
    void* newAlloc = (void*) malloc(vector)
  }

  // using the length here because since the last element is at length-1, the next element to add will at index length
  vector->vec[vector->length] = *element;
  vector->length = vector->length + 1; 
}
