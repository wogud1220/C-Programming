#include <stdio.h>
void main()
{
int sum(int, int);
int x = 20;
int y = 10, hap, bbal, gop, mog;
hap = sum(x, y);
bbal = minus(x, y);
gop = product(x, y);
mog = quotient(x, y);
printf("x + y = %d\n", hap);
printf("x - y = %d\n", bbal);
printf("x * y = %d\n", gop);
printf("x / y = %d\n", mog);
}
int sum(int x, int y)
{
int hap;
hap = x + y;
return hap;

}
int minus(int x, int y)
{
int bbal;
bbal = x - y;
return bbal;
}
int product(int x, int y)
{
int gop;
gop = x * y;
return gop;
}
int quotient(int x, int y)
{
int mog;
mog = x / y;
return mog;
}