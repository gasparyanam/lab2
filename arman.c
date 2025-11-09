#include <stdio.h>

void f()
{
	static int x;
	printf("%d\n", x);
	x++;
}

int main(void)
{
	f();
	f();
	return (0);
}
