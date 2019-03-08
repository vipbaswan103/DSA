#include<stdio.h>

void p()
{
	int pilani;
	printf("p(): %x\n",&pilani);
}
void g()
{
	int goa;
	//char c;
	printf("g(): %x\n",&goa);
	//printf("c::g() : %u\n",&c);
	p();
}
void h()
{
	int hyd;
	printf("h(): %x\n",&hyd);
	d();
}
void d(int x)
{
	if(x==0)
		return;
	d(x-1);
	printf("d(): %x\n",&x);
}

int bits;

int main()
{
	p();
	g();
	h();
	d(10000);
	printf("bits::global : %x\n",&bits);
	return 0;	
}
