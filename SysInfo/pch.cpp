// pch.cpp: ��Ԥ�����ͷ��Ӧ��Դ�ļ�

#include "pch.h"

// ��ʹ��Ԥ�����ͷʱ����Ҫʹ�ô�Դ�ļ���������ܳɹ���
char hexUnit(unsigned char unit)
{
	if (0 <= unit && unit <= 9)
		return unit + '0';
	else if (10 <= unit && unit <= 15)
		return unit - 10 + 'A';

	return '0';
}
std::string ToHex(int n)
{
	std::string hex = "";
	hex += hexUnit((n & 0xF0000000) >> 28);
	hex += hexUnit((n & 0x0F000000) >> 24);
	hex += hexUnit((n & 0x00F00000) >> 20);
	hex += hexUnit((n & 0x000F0000) >> 16);
	hex += hexUnit((n & 0x0000F000) >> 12);
	hex += hexUnit((n & 0x00000F00) >> 8);
	hex += hexUnit((n & 0x000000F0) >> 4);
	hex += hexUnit((n & 0x0000000F));

	return hex;
}
std::string getcpuid()
{
	std::string CPUID;
	unsigned long s1, s2;

	__asm {
		mov eax, 01h
		xor edx, edx
		cpuid
		mov s1, edx
		mov s2, eax
	}
	CPUID += ToHex(s1);
	CPUID += ToHex(s2);
	return CPUID;
}
