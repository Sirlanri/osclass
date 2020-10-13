#include <stdio.h>

void writein()
{
	FILE *fp = NULL;
	fp = fopen("data.txt", "w+");
	fputs("abababababa\n", fp);
	fclose(fp);
}
void read()
{
	FILE *fp = NULL;
	char buff[255];
	fp = fopen("data.txt", "r");
	fgets(buff, 255, (FILE *)fp);
	printf("%s\n", buff);
}
int main()
{
	//writein();
	read();

	return 0;
}
