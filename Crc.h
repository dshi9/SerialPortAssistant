
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class CRCcalculator{
public:
	unsigned char getCRC(CString addrcmd);
	CString Display(unsigned char x);
private:
	unsigned char converter(int container);
};