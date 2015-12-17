#include "ringserver/src/header_server.h"
#include "slinktool/src/header_client.h"
//#include "gest_data.h"
#include <string.h>
#include <time.h>

//thread---->

//get all avalable station's addr
//char** data_addr = get_stations_addr();
//int avl = get_avalable_stations();

//thread to run
//void* data_processing(void* arg);
//pthread_t table_t[avl];
/*

void* data_processing(void *arg)
{
  for(int i = 0; i < avl; ++i)
  {
    
  }
}
*/
int main()
{
    time_t start_time, end_time, run_time;

    start_time = time(NULL);

    /*
        Call slinktool: main_client(argc, argv)
                Default usage ------------------------>
                         argv[0]: app_name
                         argv[1]: -v
                         argv[2]: -o
                         argv[3]: data/miniseed/data.mseed
                         argv[4]: rtserve.iris.washington.edu:18000

        Call ringserver: main_server(argc, argv)
                Default usage ------------------------->
                         argv[0]: app_name
                         argv[1]: ring.conf


*/
    int pid = fork();

    if(pid == 0)
    {
        printf(" -------Server-------\n");
        const char* argv[] = {"my_app", "ring.conf"};
        main_server(2, argv);
    }
    else
    {
        printf(" -------Client-------\n");
        const char* argv[] = {"my_app", "-v", "-o","data/miniseed/data.mseed", "rtserve.iris.washington.edu:18000"};
        main_client(5, argv);
    }


  /*  char** temp = get_stations_addr();

    int l = strlen(temp[0]);
    char subbuff[l-18];

    memcpy( subbuff, &temp[0][18], l-18);
    subbuff[l-18] = '\0';

    printf("data: %s", subbuff);
    */
    return 0;
}

