#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

void my_callback(u_char *useless, const struct pcap_pkthdr* pkthdr,const u_char *packet)
{
    static int count = 1;
    fprintf(stderr, "%d, ", count);
    if(count == 4)
        fprintf(stderr, "come on baby sayy you love me!!! ");
    if(count == 7)
        fprintf(stderr, "Tiimmmeesss!!! ");
    count++;
}

void initPcap(int *arg)
{
    int i;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *descr;
    const u_char *packet;
    struct pcap_pkthdr hdr;
    struct ether_header *eptr;

    dev = pcap_lookupdev(errbuf);
    if(!dev)
    {
        fprintf(stderr, "%s\n", errbuf);
        return -1;
    }

    descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
    if(!descr)
    {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return -2;
    }

    pcap_loop(descr, -1, my_callback, NULL);

   fprintf(stdout,"\nDone processing packets... wheew!\n");

   pthread_exit(0);
}

int main(int argc, char *argv[])
{
        pthread_t tid;

        if(pthread_create(&tid, NULL,initPcap,NULL ))
        {
            fprintf(stderr, "can not create thread");
            exit(1);
        }

        pthread_join(tid,NULL);



return 0;

}
