#include <stdbool.h>
#include <stdio.h>

bool is_prime(int x) {
  int divs = 0;
  int i = 0;
  for (i = 0; i < x; i++) {
    if (x%i==0)
      divs++;
  }
  if (divs > 1)
    return false;
  return true;
} 

int main() {
  int i;
  for (i = 0; i < 100; i++) {
    if (is_prime(i))
      printf("%d, ", i);
  }
  return 0;
}
