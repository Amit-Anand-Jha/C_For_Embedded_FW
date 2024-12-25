#include<stdio.h>
#include<stdlib.h>
#include "../../Common_Defs/inc/common_defs.h"


// Define the Processor Architecture which decides the number of 
// bits a word will have. A word may have 8, 16, 32 or 64 bits 
// depending on the processor architecture
#define PROC_ARCH              32


// Standards Defintions
#define NUM_BITS_IN_A_NIBBLE   4
#define NUM_BITS_IN_A_BYTE     8
#define NUM_BITS_IN_A_WORD     PROC_ARCH



/*------------------------------------------------------------------------------------------
 *
 *                                       DECLARATIONS
 *
 * ----------------------------------------------------------------------------------------*/



typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t  uint8;




/*------------------------------------------------------------------------------------------
 * Declaration of API  set_bit_at_index()

 * 
 *
 * @BRIEF : This API sets the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  index (index are 0, 1, 2, 3, 4, ....) at which the bit needs to be set
 *           (ii) The number in which the bit at given position needs to be set
 *
 * @RETURN :
 *           (i)  the integer value obtained after the bit at given index is set
 * ----------------------------------------------------------------------------------------*/

uint32_t set_bit_at_index(uint32_t i, uint32_t num);




/*------------------------------------------------------------------------------------------
 * Declaration of API  clear_bit_at_index()

 * 
 *
 * @BRIEF : This API clear the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  index (index are 0, 1, 2, 3, 4, ....) at which the bit needs to be clear
 *           (ii) The number in which the bit at given position needs to be clear 
 *
 * @RETURN :
 *           (i)  the integer value obtained after the bit at given index is clear 
 * ----------------------------------------------------------------------------------------*/

uint32_t clear_bit_at_index(uint32_t i, uint32_t num);






/*------------------------------------------------------------------------------------------
 * Declaration of API  idx_of_first_set_bit()
 * 
 *
 * @BRIEF : This API sets the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  The number for which the index of first set bit is to be found
 *
 * @RETURN :
 *           (i)  The index of the first set bit for the input number
 *                This is also the number of trailing zeroes (from LSB) in the input number
 * ----------------------------------------------------------------------------------------*/

uint32_t idx_of_first_set_bit(uint32_t num);







/*------------------------------------------------------------------------------------------
 * Declaration of API  count_num_set_bits()
 * 
 *
 * @BRIEF : This API counts the total number of bits which are set in a given input
 *
 * @INPUT :
 *           (i)  The number for which the total number of set bits are required
 *
 * @RETURN :
 *           (i)  The count of total number of bits that are set in the given input
 *                (The set bits may or may not be continuous in the input)
 * ----------------------------------------------------------------------------------------*/

uint32_t count_num_set_bits(uint32_t num);





/*------------------------------------------------------------------------------------------
 *
 *                                       DEFINITIONS
 *
 * ----------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------
 * Definition of API  set_bit_at_index()

 * 
 *
 * @BRIEF : This API sets the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  index (index are 0, 1, 2, 3, 4, ....) at which the bit needs to be set
 *           (ii) The number in which the bit at given position needs to be set
 *
 * @RETURN :
 *           (i) the integer value after the bit at given index is set
 * ----------------------------------------------------------------------------------------*/

uint32_t set_bit_at_index(uint32_t idx, uint32_t num)
{
	uint32_t x = 0x1;
	x = (x << idx);
	
	if(num == NULL)
	{
		num = x;
		TRACE_HIGH("The value of x = 0x%x   num = 0x%x", x, (uint32_t)num);
	}
	else
	{
		num = (num | x);
		TRACE_HIGH("The value of x = 0x%x  num = 0x%x", x, (uint32_t)num);
	}

	return num;
}



/*------------------------------------------------------------------------------------------
 * Definition of API  clear_bit_at_index()

 * 
 *
 * @BRIEF : This API clear the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  index (index are 0, 1, 2, 3, 4, ....) at which the bit needs to be clear
 *           (ii) The number in which the bit at given position needs to be clear 
 *
 * @RETURN :
 *           (i)  the integer value obtained after the bit at given index is clear 
 * ----------------------------------------------------------------------------------------*/

uint32_t clear_bit_at_index(uint32_t idx, uint32_t num)
{
	uint32_t x = 0xFFFFFFFF;
	x = x << (idx+1);
	uint32_t y = 0xFFFFFFFF;
	y = y >> (NUM_BITS_IN_A_WORD - idx);

	TRACE_HIGH("x = 0x%x  and   y = 0x%x", x, y);

	uint32_t z = (x | y);
	num = (z & num);

	TRACE_HIGH("z = (x | y) = 0x%x   and   num = 0x%x", z, num);

	return num;
}




/*------------------------------------------------------------------------------------------
 * Declaration of API  idx_of_first_set_bit()
 * 
 *
 * @BRIEF : This API sets the bit in a particular integer at an index which is given as input
 *
 * @INPUT :
 *           (i)  The number for which the index of first set bit is to be found
 *
 * @RETURN :
 *           (i)  The index of the first set bit for the input number
 *                This is also the number of trailing zeroes (from LSB) in the input number
 * ----------------------------------------------------------------------------------------*/

uint32_t idx_of_first_set_bit(uint32_t num)
{
	if(num % 2 == 1)
	{
		// If bit 0 is set then the number would be odd hence
		// remainder when divided by 2 would be 1. So bit 0 is the first set bit
		return 0;
	}
	
	else
	{
		uint32_t count = 0;
		// Unless we get the bit at index 0 set run the loop
		while(num % 2 != 1)
		{
			// Keep left shifting unless the bit at index 0 is set
			num = (num >> 1);
			// Increment the counter to count how many shifts needed
			count = count + 1;
		}

		return count;
	}
}




/*------------------------------------------------------------------------------------------
 * Declaration of API  count_num_set_bits()
 * 
 *
 * @BRIEF : This API counts the total number of bits which are set in a given input
 *
 * @INPUT :
 *           (i)  The number for which the total number of set bits are required
 *
 * @RETURN :
 *           (i)  The count of total number of bits that are set in the given input
 *                (The set bits may or may not be continuous in the input)
 * ----------------------------------------------------------------------------------------*/

uint32_t count_num_set_bits(uint32_t num)
{
	uint32_t count = 0, x =0x1;

	while(num != 0)
	{
		// If XOR with 1 is 0 then the last bit of input is set (1) hence
		// everytime we shift the number to the right and the XOR gives 0
		// we can increment the count for number of set bits in the input
		if( ((num ^ x) & x) == 0)
		{
			count = count + 1;
		}
		num = (num >> 1);
	}
	
	return count;
}
