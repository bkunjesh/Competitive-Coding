#include<stdio.h>
struct complex
{
	float real;
	float img;
} c3; 
  void complex_product( complex c1, complex c2)
{

	c3.real=c1.real*c2.real-c1.img*c2.img;
	c3.img=c1.real*c2.img+c1.img*c2.real;
	
}
void print()
{
	printf("%f %fi",c3.real,c3.img);
}


main()
{
	complex c1,c2;
	
	scanf("%f%f%f%f",&c1.real,&c1.img,&c2.real,&c2.img);
	complex_product(c1,c2);
	print();
//	printf("product= %d\n",complex_product(struct complex c1,struct complex c2));
}
