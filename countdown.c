#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main (int *argc,char **argv){
	 
	 
	unsigned int x_hours=0;
	unsigned int x_minutes=0;
	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;
	
	time_t t;
	char buf[26] = "";
	struct tm* tm_info;
	clock_t x_startTime,x_countTime;
	if(argc != (int*)4){
		printf("error usage: %s hours minutes seconds\n",argv[0]);
		exit(0);
	}
	int hours = atoi(argv[1]);
	int minutes = atoi(argv[2]);
	int seconds = atoi(argv[3]);
	count_down_time_in_secs = (hours * 3600)+(minutes * 60)+seconds;  // 1 minute is 60, 1 hour is 3600
 
    	x_startTime=clock();  // start clock
	time_left=count_down_time_in_secs-x_seconds;  // update timer
	
	FILE *fp;
	fp = fopen("countdown.txt", "w+");
	
	time(&t);

	while (time_left>0) 
	{
		x_countTime=clock(); // update timer difference
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC));//-(x_minutes*60);
		//x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
		//x_hours=x_minutes/60;
	
		time_left=count_down_time_in_secs-x_seconds; // subtract to get difference 
		
		t =(time_t) time_left;
		tm_info = gmtime(&t);
		
		strftime(buf, 26, "%H:%M:%S",tm_info);
		
		rewind(fp);
		fprintf(fp,"%s",buf);

	}

	fclose(fp);
	return 0;
}
