/*
 * ring_buffer.cpp
 *
 *  Created on: Mar 31, 2025
 *      Author: Sezakiaoi
 */

#include "ring_buffer.hpp"

void RINGBUFFER::set_value(float Value){

	buffer[index] = Value;
	
	if(index == max_index){

		index = 0;
	}
	else{

		index++;
	}
}

float RINGBUFFER::get_value(uint8_t index){

	return buffer[index];
}

uint8_t RINGBUFFER::get_index(){

	if(index == 0){

		return max_index;
	}
	else{

		return index - 1;
	}
}
