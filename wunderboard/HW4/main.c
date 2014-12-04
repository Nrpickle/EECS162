/** Includes */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "wunder.h"
#include "usart.h"
#include "adc.h"
#include "leds.h"

#define DELAY 250

int swaps = 0; //This is a global variable to track how many swaps occur
int passes = 0;
int comparisons = 0;

int highlight_1 = -1;  //These global variables are used for changing the 
int highlight_2 = -1;  //colors of columns

const int delay = 10;  //This number might represent the delay in the program
/*
   array_print takes a pointer to an array of eight integers
   and displays them on the eight rows of the wunderboard
   screen. 
   Use the set_array_blue or led_blue (or another color) to set each row
   and PORTE to change rows.
   Use the "DELAY" macro and _delay_ms to make this function
   last longer by looping it "DELAY" times.
   */
void array_print(int* array, int duration)
{
  for(int count = 0; count < duration; ++count){
    int output;
    for(int i = 0; i < 8; ++i){
      if(array[i] == 1)
	output = 1;
      else
	output = pow(2,array[i]); 

      PORTE = i;
      if(highlight_1 == i)
	update_row(0,output,0);
      else if(highlight_2 == i)
	update_row(0,0,output);
      else
	update_row(output,0,0);

      _delay_ms(1);
      led_off();
    }
  }
}

/*
   swap_num takes two pointers to integers and swaps them.
   Increment the global variable "swaps" every time this is called.
   */
void swap_num(int* a, int* b)
{
  int temp;
  temp = *b;
  *b = *a;
  *a = temp;
}

/*
   bubble_pass takes a pointer to an array of integers and
   the length of the array being sorted.
   It only does one pass of the bubble sort algorithm, calls
   array_print between every step of the pass, and calls
   swap_num every step if numbers are out of order.
   It should return 1 if a swap occurs during the pass, 0
   otherwise.
   Increment the global variable "passes" every time this is called.
   Increment the global variable "comparisons" every time two variables
   in the array are compared.
   */
int bubble_pass(int* array, int len)
{
  ++passes;
  int delay = 30;
  int swap = 0; //Did the program swap a value?
  for(int i = 0; i < len-1; ++i){
    highlight_1 = i;
    highlight_2 = -1;
    delay = 10;
    if(array[i] < array[i+1]){
      highlight_1 = i;
      highlight_2 = i+1;
      array_print(array,delay);
      swap_num(&array[i],&array[i+1]);
      swap = 1;
      ++swaps;
      highlight_2 = i;
      highlight_1 = i+1;
      delay /= 2;
    }
    PORTC = swaps;
    array_print(array,delay);
  }
  return swap;
}

/*
   bubble_sort takes a pointer to an array of integers and
   the length of the array being sorted.
   It calls bubble_pass until no swap occurs.
   */
void bubble_sort(int* array, int len)
{
  swaps = 0;
  while(bubble_pass(array,len));
  highlight_1 = -1;
}

int main(int argc, char **argv)
{
  /*
     These seven arrays are examples of different situations
     a sorting algorithm may encounter.
     */
  int in_order[] = {8,7,6,5,4,3,2,1};
  int rev_order[] = {1,2,3,4,5,6,7,8};
  int random_1[] = {4, 3, 8, 4, 4, 2, 6, 2};
  int random_2[] = {8, 1, 5, 7, 7, 3, 8, 5};
  int random_3[] = {1, 1, 6, 7, 4, 3, 2, 5};
  int random_4[] = {8, 3, 1, 5, 2, 5, 8, 8};
  int random_5[] = {1, 5, 7, 2, 4, 8, 4, 3};
  int few_unique[] = {3, 2, 2, 1, 3, 1, 1, 2};

  int* to_sort = in_order; //Choose which array to sort with a pointer to one of the arrays above

  initialize();
  led_off();

  //array_print(in_order,500);
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = rev_order;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = random_1;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = random_2;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = random_3;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = random_4;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = random_5;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);
  to_sort = few_unique;
  bubble_sort(to_sort, 8); //Call bubble_sort on the chosen array above here
  array_print(to_sort, 100);









  while(1) {
    array_print(to_sort,100);
    //array_print(in_order, 100);
    //led_off();
    PORTC = swaps;
  }

  //		PORTE = 5;
  //		update_row((1<<5),1,,2);
  //		PORTC = swaps; //Display one of the global variables here. (Displays in binary)
  //		array_print(to_sort); //Keeping the sorted array on screen

  return 0;
}
