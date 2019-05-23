/*
                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
*/
//guzald.c  Copyright (C) 2019  Mardan

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/wait.h>

int start();
int restart();
int stop();

int main(int argc, char const *argv[])
{
	int status;
	pid_t guzal_id;
	openlog("guzal",LOG_CONS | LOG_PID,LOG_LOCAL0);

	if (daemon(0,0)==-1){
		perror("打开守护进程状态");
		syslog(LOG_INFO,"打开守护进程状态");
		exit(-1);
	}
	syslog(LOG_INFO,"Guzal-Aida--->守护进程已启动");
	if ((guzal_id=fork())<0){
		syslog(LOG_INFO,"Guzal-Aida startup failed.");
		for (int try_count = 0; (guzal_id=fork()); try_count++){
			syslog(LOG_INFO,"try to restart the Guzal-Aida a %d time.",try_count);
		}
		
	}
	while(1){
		if (guzal_id == 0){
			status = execlp("pwd",NULL);
		}else{
			wait(&status);
			syslog(LOG_INFO,"程序状态:%d",status);
		}
	}
	closelog();
	return 0;
}
