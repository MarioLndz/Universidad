/**
 * @file Byte.cpp
 * @author MP
 */
#include <iostream>
#include <string>
#include "MPTools.h"
#include "Byte.h"

using namespace std;



void Byte::onBit(int pos)
{
	Byte mask = 1;
	mask.shiftLByte(pos);
	
	_data = getValue() | mask.getValue();
	
}


void Byte::offBit(int pos)
{
	Byte mask = 1;
	mask.shiftLByte(pos);
	
	mask.setValue(~mask.getValue());
	
	_data = getValue() & mask.getValue();
	
}


bool Byte::getBit(int pos) const
{
	Byte mask = 1;
	mask.shiftLByte(pos);
	
	Byte aux = mask.getValue() & getValue();
	
	return (aux.getValue() != 0);
}


std::string Byte::to_string() const
{
	string byte;
	for (int i = MIN_BIT; i < MAX_BIT; i++){
		byte += std::to_string(getBit(i));
	
	}
	
	return byte;
}


void Byte::onByte()
{
	for (int i = MIN_BIT; i < MAX_BIT; i++){
		onBit(i);
		
	}
	
}


void Byte::offByte()
{
	for (int i = MIN_BIT; i < MAX_BIT; i++){
		offBit(i);

	}
}


void Byte::encodeByte(const bool v[])
{
	for (int i = 0; i < MAX_BIT; i++){
		if (v[i]){
			onBit(((MAX_BIT - 1) - i));
		}
		
	}
	
}


void Byte::decodeByte(bool v[]) const
{
	for (int i = 0; i < MAX_BIT; i++){
		v[i] = getBit(i);
		
	}
}


void Byte::decomposeByte(int posic[], int  &cuantos) const
{
	cuantos = 0;
	
	for (int i = MIN_BIT; i < MAX_BIT; i++){
		if (getBit(i)){
			posic[cuantos] = i;
			cuantos++;
			
		}
		
	}
}

void Byte::shiftRByte(int n) {
	_data = _data >> n;
}

void Byte::shiftLByte(int n) {
	_data = _data << n;
}

void Byte::mergeByte(Byte merge, int percentage){
	_data = (_data * (100 - percentage) + merge.getValue() * percentage)/100;
}
