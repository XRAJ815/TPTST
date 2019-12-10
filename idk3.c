#include<stdio.h>

#define set 	32768
#define way 	8


int get_dec(char ch);

////////////////////////////////////////
//			Cache					  //
////////////////////////////////////////
struct cache
{
//	unsigned int index;		//set
	unsigned int state;
	unsigned int tag;
};
struct cache c1[set][way];
////////////////////////////////////////


int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename = argv[2];
	char *mode = argv[1];
	char ch;
	int flag = 0;
	char n;
	unsigned int Address = 0, tAddress = 0;
	
	printf("Filename : %s\n", filename);
 
	printf("Mode working in : :: : %s\n", mode);

	fp = fopen(filename,"r");

while((ch = fgetc(fp)) != EOF)
{
	if(ch != '\n')
	{
		if(flag == 0)
		{
			n = ch;
			flag = 1;
		}
		else
		{
			if(ch != ' ')
			{
				tAddress = get_dec(ch);
				Address = Address*16 + tAddress;
			}
		}
		
	}
	else
	{

		flag = 0;
		printf("\n\nCommand is %c\n", n);
		printf("\nAddress in hex is : %x", Address);
		tAddress = 0;
		Address = 0;

	}
}
}

////////////////////////////////////////
//	Char Hex to Unsigned Decimal 	  //
/////////////////////////////////////////
int get_dec(char ch)
{
	switch (ch)
	{
		case '0' : return 0;
					break;

		case '1' : return 1;
					break;

		case '2' : return 2;
					break;

		case '3' : return 3;
					break;

		case '4' : return 4;
					break;

		case '5' : return 5;
					break;

		case '6' : return 6;
					break;

		case '7' : return 7;
					break;

		case '8' : return 8;
					break;

		case '9' : return 9;
					break;

		case 'a' : return 10;
					break;

		case 'b' : return 11;
					break;

		case 'c' : return 12;
					break;

		case 'd' : return 13;
					break;

		case 'e' : return 14;
					break;

		case 'f' : return 15;
					break;

		default : return 0;
					break;

	}
}
