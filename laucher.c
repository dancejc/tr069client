#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
//#include "common.h"



int main(int argc, char *argv[])
{
    int i = 0;
    struct sockaddr_un address;
    int sockfd;
    int len;
    int result = 0;
    int bytes = 0;
    void *auth = NULL;
    char *index = NULL;
    char	*auth_server = NULL;
    char	*userid = NULL;
    char	*passwd = NULL;
    char  bootcmd[] = "i bs";
    long long oldtime;

    /*if(get_proc_number_by_name("/iapp/app/starttr69c") >= 2) {
        return -1;
    }*/

    //   REPORT(REPORT_LOG, SYSTEM, 0, 0, "start up the tr69c process...\n");
    printf( "start up the tr69c process...\n");

    //system("/iapp/app/tr69c &");
    system("./tr69c &");


    /*oldtime = getTMmillisec();

    while(CheckNetConnect() != 1 ) {

        if(getTMmillisec() - oldtime > (1000 * 30)) {
            break;

        }

        sleep(1);
    }*/



    //while(IsExistProc("/iapp/app/tr69c"))
    /*while(IsExistProc("../tr69c"))
        usleep(1 * 1000);*/


    //REPORT(REPORT_LOG, SYSTEM, 0, 0, "check the platform is setup...\n");
    //  printf("check the platform is setup...\n");
    /*auth = parse_ini_file("platform.cfg");

    if(auth) {
        index = get_item_value(auth, "auth", "authindex", "1");

        if(strcmp(index, "1") == 0) {
            auth_server = get_item_value(auth, "auth", "server1", NULL);

        } else {
            auth_server = get_item_value(auth, "auth", "server2", NULL);

        }

        userid = get_item_value(auth, "auth", "user1", NULL);
        passwd = get_item_value(auth, "auth", "pass1", NULL);


    }*/

    //if(strlen(auth_server) == 0 || strlen(userid) == 0 || strlen(passwd) == 0) {

        //REPORT(REPORT_LOG, SYSTEM, 0, 0, "auto run authprogram for authenticate in background\n");
        // printf("auto run authprogram for authenticate in background\n");
printf( "111111111111111111111\n");
        if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            //close_ini_file(auth);
            perror ("socket");
            exit (EXIT_FAILURE);
        }

        address.sun_family = AF_UNIX;
        strcpy (address.sun_path, "server_socket");
        len = sizeof (address);

        //oldtime = getTMmillisec();
				printf( "111111111111111111111\n");
        while(1)

        {

            /*if(getTMmillisec() - oldtime > (1000 * 10)) {
                break;

            }*/
            sleep(2);
            printf( "111111111111111111111\n");
            result = connect (sockfd, (struct sockaddr *)&address, len);

            if (result == -1) {
                //REPORT (REPORT_ERROR, SYSTEM, 0, 0, "ensure the server is up\n");
                printf ("ensure the server is up\n");

                sleep(1);

            } else {
                //REPORT(REPORT_LOG, SYSTEM, 0, 0, "tr69c connection success...\n");
                printf( "tr69c connection success...\n");

                break;
            }

        }

        if ((bytes = write(sockfd, bootcmd, strlen(bootcmd))) < 0) {
            //close_ini_file(auth);
            close (sockfd);
            unlink ("server_socket");

            perror ("write");
            exit (EXIT_FAILURE);
        }

        //REPORT(REPORT_LOG, SYSTEM, 0, 0, "send boot strap ok\n");
        printf("send boot strap ok %d\n", bytes);
        close (sockfd);
        unlink ("server_socket");
    //}

    //close_ini_file(auth);
    sleep(5);

    return 0;
}


