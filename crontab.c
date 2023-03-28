#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void menu(char *opt);
void help();
void get_crontab();
void cron_structure();

int main(int argc, char* argv[argc + 1])
{
	if(argc == 1)
	{
		get_crontab();
	}
	else
	{
		char *opt = (char*)calloc(3,sizeof(char));
		strcpy(opt,argv[1]);

		menu(opt);

		free(opt);
	}

	return EXIT_SUCCESS;
}

void menu(char *opt)
{

	if(opt[0] != '-')
	{
		printf("Wrong flag, run with -h for more info\n");
	}

	if(opt[1] == 'h')
	{
		help();
	}
	else if(opt[1] == 'l')
	{
		cron_structure();
	}

}

void help()
{

	printf("Usage:\n");
	printf("   -h    Show help\n");
	printf("   -l    Show Crontab structure\n");

}

void cron_structure()
{

	printf("\n");
	printf("1 - Minute (0-59)\n");
	printf("2 - Hours  (0-23)\n");
	printf("3 - Day of the month (0-31)\n");
	printf("4 - Month (0-12) # 12 == December\n");
	printf("5 - day of the week (0-7) # 0 == Sunday\n");
	printf("\n");
	printf("*  *  *  *  *  /path\n|  |  |  |  |\n");
	printf("|  |  |  |   ---- Day of the week\n|  |  |   ------- Month\n");
	printf("|  |   ---------- Day of the month\n|   ------------- Hour\n");
	printf(" ---------------- Minute\n");
	printf("\n");

}

void get_crontab()
{
	printf("If you want to set it for every possible value, please use \'-1\'\n");

	int minute;
	int hour;
	int day_of_the_month;
	int month;
	int day_of_the_week;

	printf("Minute > ");
	scanf("%d", &minute);
	if(minute > 59)
	{
		printf("Wrong value for minute (0-59)\n");
		exit(2);
	}
	printf("Hour > ");
	scanf("%d", &hour);
	if(hour > 23)
	{
		printf("Wrong value for hour (0-23)\n");
		exit(2);
	}
	printf("Day of the month > ");
	scanf("%d", &day_of_the_month);
	if(day_of_the_month > 31)
	{
		printf("Wrong value for day of the month (0-31)\n");
		exit(2);
	}
	printf("Month > ");
	scanf("%d", &month);
	if(month > 12)
	{
		printf("Wrong value for month (0-12)\n");
		exit(2);
	}
	printf("Day of the week > ");
	scanf("%d", &day_of_the_week);
	if(day_of_the_week > 7)
	{
		printf("Wrong value for day of the week (0-7)\n");
		exit(2);
	}

	char str[14];

	char num[14];

	if(minute == -1)
	{
		strcpy(str,"* ");
	}
	else
	{
		sprintf(num, "%d ", minute);
		strcpy(str,num);
	}
	if(hour == -1)
	{
		strcat(str,"* ");
	}
	else
	{
		sprintf(num, "%d ",hour);
		strcat(str, num);
	}
	if(day_of_the_month == -1)
	{
		strcat(str,"* ");
	}
	else
	{
		sprintf(num, "%d ",day_of_the_month);
		strcat(str, num);
	}
	if(month == -1)
	{
		strcat(str,"* ");
	}
	else
	{
		sprintf(num, "%d ",month);
		strcat(str, num);
	}
	if(day_of_the_week == -1)
	{
		strcat(str,"* ");
	}
	else
	{
		sprintf(num, "%d ",day_of_the_week);
		strcat(str, num);
	}
	
	printf("Your crontab schedule is: ");
	printf("%s\n", str); 
}
