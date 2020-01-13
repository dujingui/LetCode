#pragma once

#include <stdint.h>
#include <stdio.h>

//#pragma pack(2) /*1×Ö½Ú¶ÔÆë*/

struct abc {
	int ml = 1;
	char m2 = 2;
	float m3 = 3;

	union uu {
		char ul[5];
		int u2[2]= { 10,10};
	}myaa;
	char m4 = 5;
};

struct student_info {
	char name = 1;
	int age = 2;
	int number = 3;
	char add = 'a';
};


union union1
{
	long a;
	double b;
	char name[9] = { 0 };
	int c[2];
}uniona;

struct A
{
	int a;
	char b;
	short c;
};

struct B
{
	char a;
	int b;
	short c;
};

#pragma pack(2)
struct C
{
	char a;
	int b;
	short c;
};

#pragma pack(1)
struct D
{
	int a;
	char b;
	short c;
};


void byteAlign() {
	student_info s;
	abc aa;
	union1 u;
	A a;
	B b;
	C c;
	D d;
	cout << sizeof(A) << "   " << sizeof B << "   " << sizeof C << "   " << sizeof D << endl;
}