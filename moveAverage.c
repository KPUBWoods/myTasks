#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	FILE* fp;
	fp=fopen("noiseSIN.dat","r");
	char line[32];
	float original[500];
	for(int j=0;j<500;j++)
	{
		original[j]=atof(fgets(line, sizeof line, fp));
	}
	fclose(fp);
	int k=500;
	float output[500];
	int winSize=5;

	if (winSize % 2 != 0)
	{
		fp= fopen("movAvgSIN.dat","w");
		for (int n=0;n<k;n++)
		{
			output[n]=0;
			if (n > (((winSize-1)/2)-1 || n < k-((winSize-1)/2)-1))
			{
				for(int m = 0 - ((winSize-1) / 2);m<=0+((winSize-1)/2);m++)
				{
					output[n]=output[n]+original[n+m];
				}
				output[n]=output[n]/(float)winSize;
			}
			else
			{
				output[n]=original[n];
			}
			fprintf(fp,"%.5f\n",output[n]);
		}
		fclose(fp);
	}
	else
	{
		printf("Needs Odd Window Size");
	}
	return 0;
}