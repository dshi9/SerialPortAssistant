#include "stdafx.h"
#include "Crc.h"

unsigned char CRCcalculator::getCRC(CString addrcmd)
{
	
	string crc_addrcmd = (CStringA)addrcmd;
	unsigned char i = 0x00;
	unsigned char j = 0x00;
	unsigned char counter = 0;
	unsigned int check;
loop1:
	j=crc_addrcmd[counter];
	check=(i^j)*2;
	i = check;
	if(check>255)
	{
		i=i|0x01;
	}
	counter++;
	if(counter!=crc_addrcmd.length())
	{
		goto loop1;
	}
	
	return i;


}
CString CRCcalculator::Display(unsigned char i)
{
	CString output;
	string pre_output;
	int choice;
	unsigned char a = 0xf0;
	unsigned char b = 0x0f;
	unsigned char tmp;
	choice = i & a;
	choice = choice>>4;
	tmp = converter(choice);
	pre_output.push_back(tmp);
	choice = i & b;
	tmp = converter(choice);
	pre_output.push_back(tmp);
	output = pre_output.c_str();
	return output;
	
}
unsigned char CRCcalculator::converter(int choice)
{
	switch(choice)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'a';
	case 11:
		return 'b';
	case 12:
		return 'c';
	case 13:
		return 'd';
	case 14:
		return 'e';
	case 15:
		return 'f';
	}

}