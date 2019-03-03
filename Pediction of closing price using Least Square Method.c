//LEAST SQUARE METHOD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

char** str_split(char* a_str, const char a_delim)
{
	char** result    = 0;
	size_t count     = 0;
	char* tmp        = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	/* Count how many elements will be extracted. */
	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_comma < (a_str + strlen(a_str) - 1);

	/* Add space for terminating null string so caller
	knows where the list of returned strings ends. */
	count++;

	result = malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx  = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

void main(int argc, char** argv)
{
	double a[23][2];
	FILE *fptr;
	char str[1000];
	char** tokens;
	int count;
	double m=0,b=0;
	int i=0,ctr=0;
	double day=1;
	fptr = fopen(argv[1], "r");
	count=0;
	double y[23][2],alpha=0.00000001,res[23][2];
	double xmean=0, ymean=0,xsum=0,ysum=0,sum=0;
	fscanf(fptr, "%[^\n]\n", str);
	while (EOF != fscanf(fptr, "%[^\n]\n", str))
	{
		tokens = str_split(str, ',');
		if (tokens)
		{
			a[count][0] = day;
			a[count][1]=atof(*(tokens + 4));
			count++;
			day++;
			free(tokens);
		}
	}
	//for(i=0;i<23;i++)
	//	printf("%lf\n",a[i][1]);
	//xmean  
	for(i=0;i<23;i++)
		xsum+=a[i][0];
	xmean=xsum/23;
	xsum=0;

	//ymean
	for(i=0;i<23;i++)
		ysum+=a[i][1];
	ymean=ysum/23;

	//(x'-x)**2
	for(i=0;i<23;i++)
		xsum+=pow((a[i][0]-xmean),2);
	for(i=0;i<23;i++)
		sum+=(a[i][0]-xmean)*(a[i][1]-ymean);
	m=sum/xsum;
	b=ymean-(xmean*m);
	for(i=0;i<23;i++)
	{
		res[i][1]=m*(i+1)+b;
		printf("%d %lf %lf\n",i+1,a[i][1],res[i][1]);
	}
    printf(“The value of m is %lf”, m);
    printf(“The value of b is %lf”, b);
}