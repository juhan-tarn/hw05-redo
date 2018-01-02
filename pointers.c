/* pointers.c

   Name:
   Resources used (websites, books other than our texts, peers):

*/

#include <stdlib.h>

#include "pointers.h"
/* Returns whether or not the region pointed to by p1 (of length n)
   overlaps with the region pointed to by p2 (of length m). Do not
   assume that p2 is greater than p1. */
bool overlaps(int n, int* p1, int m, int* p2)
{
  /* WRITE THIS FUNCTION */
  if(p1 < p2){
    return ((p1+n) > p2);
  }
  else{
    return ((p2 + m) > p1);
  }
}

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing order. */
void minisort(int* a, int* b, int* c) //x = 4, y=1, z=3
{
  /* WRITE THIS FUNCTION */
  int small, medium, big;
  if(*a > *b){
    big = *a;
    small = *b ;
  }else{
    big = *b;
    small = *a;
  }
  if(*c < small){
    medium = small;
    small = *c;
  }else if(*c > big){
    medium = big;
    big = *c ;
  }else{
    medium = *c ;
  }
  *a = small;
  *b = medium;
  *c = big;
}

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q)
{
  /* WRITE THIS FUNCTION */
  int sum = 0;
  while(p < q){
    sum = sum + *p ;
    p++;
  }
  return sum;
}

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n)
{
  /* WRITE THIS FUNCTION */
  for(int i = step; i<step*n; i = i + step){
    if(*start != *(start+i)){ //if start[0] != start[i]
      return BLANK;
    }
  }
  return start[0];
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
int tic_tac_toe_winner(int n, int* board)
{
  /* WRITE THIS FUNCTION */
  int result;
  //case 1: row
  for(int i = 0; i<n; i++){
    result = check_line((board+i*n), 1, n);
  }

  //case 2: column
  for(int i = 0; i<n; i++){
    result = check_line((board+i), n, n);
  }

  //case 3: left to right diagonal
  result = check_line(board, n+1, n);

  //case 4: right to left diagonal
  result = check_line((board + (n-1)), n-1, n);
  return result;
}
