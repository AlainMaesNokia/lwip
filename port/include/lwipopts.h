#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

struct netif;
struct ip4_addr;
int lwip_hook_ipv4_input_accept(struct netif *netif);
struct netif *lwip_hook_ipv4_route(const struct ip4_addr *dest);

#define LWIP_HOOK_IP4_INPUT_ACCEPT lwip_hook_ipv4_input_accept
#define LWIP_HOOK_IP4_ROUTE lwip_hook_ipv4_route

#define LWIP_DBG_MIN_LEVEL  0

#define TAPIF_DEBUG      LWIP_DBG_OFF
#define TUNIF_DEBUG      LWIP_DBG_OFF
#define UNIXIF_DEBUG     LWIP_DBG_OFF
#define DELIF_DEBUG      LWIP_DBG_OFF
#define SIO_FIFO_DEBUG   LWIP_DBG_OFF
#define TCPDUMP_DEBUG    LWIP_DBG_OFF

#define PPP_DEBUG        LWIP_DBG_OFF
#define MEM_DEBUG        LWIP_DBG_OFF
#define MEMP_DEBUG       LWIP_DBG_OFF
#define PBUF_DEBUG       LWIP_DBG_OFF
#define API_LIB_DEBUG    LWIP_DBG_OFF
#define API_MSG_DEBUG    LWIP_DBG_OFF
#define TCPIP_DEBUG      LWIP_DBG_OFF
#define NETIF_DEBUG      LWIP_DBG_OFF
#define SOCKETS_DEBUG    LWIP_DBG_OFF
#define DEMO_DEBUG       LWIP_DBG_OFF
#define IP_DEBUG         LWIP_DBG_OFF
#define IP_REASS_DEBUG   LWIP_DBG_OFF
#define RAW_DEBUG        LWIP_DBG_OFF
#define ICMP_DEBUG       LWIP_DBG_OFF
#define UDP_DEBUG        LWIP_DBG_OFF
#define TCP_DEBUG        LWIP_DBG_OFF
#define TCP_INPUT_DEBUG  LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG LWIP_DBG_OFF
#define TCP_RTO_DEBUG    LWIP_DBG_OFF
#define TCP_CWND_DEBUG   LWIP_DBG_OFF
#define TCP_WND_DEBUG    LWIP_DBG_OFF
#define TCP_FR_DEBUG     LWIP_DBG_OFF
#define TCP_QLEN_DEBUG   LWIP_DBG_OFF
#define TCP_RST_DEBUG    LWIP_DBG_OFF

extern unsigned char debug_flags;
#define LWIP_DBG_TYPES_ON debug_flags

/* An OS is present */
#define NO_SYS                     0

#define LWIP_ETHERNET              1
#define LWIP_IPV4                  1

/* ---------- IPv6  ---------- */
#define LWIP_IPV6                  1
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS 1
#define LWIP_IPV6_SEND_ROUTER_SOLICIT 1
#define LWIP_IPV6_AUTOCONFIG          1
#define LWIP_IPV6_FORWARD             1
#define LWIP_IPV6_MLD              1
#define MEMP_NUM_MLD6_GROUP           16
#define LWIP_IPV6_NUM_ADDRESSES       6
#define LWIP_IPV6_REASS            1
#define LWIP_IPV6_AUTOCONFIG       1

/* Enable all socket operations */
#define LWIP_SOCKET                (NO_SYS==0)
#define LWIP_NETCONN               (NO_SYS==0)
#define LWIP_TCP_KEEPALIVE          1
#define LWIP_SO_SNDTIMEO            1
#define LWIP_SO_RCVTIMEO            1
#define LWIP_SO_RCVBUF              1
#define LWIP_SO_LINGER              1
#define SO_REUSE                    1
#define LWIP_MULTICAST_TX_OPTIONS   1
#define LWIP_COMPAT_SOCKETS         0 /* TODO */
#define LWIP_SOCKET_OFFSET          1
#define LWIP_POLL                   1
#define LWIP_SOCKET_OPEN_COUNT      1
#define LWIP_SOCKET_SELECT          0

/* ---------- Memory options ---------- */
/* If the system is 64 bit */
#if defined __LP64__
#define MEM_ALIGNMENT            8
#else
#define MEM_ALIGNMENT            4
#endif

/* Use Glibc malloc()/free() */
#define MEM_LIBC_MALLOC          1
#define MEMP_MEM_MALLOC          1
#define MEM_USE_POOLS            0

/* MEM_SIZE: the size of the heap memory. If the application will send
a lot of data that needs to be copied, this should be set high. */
#define MEM_SIZE                 10240

/* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
   sends a lot of data out of ROM (or other static memory), this
   should be set high. */
#define MEMP_NUM_PBUF            128
/* MEMP_NUM_RAW_PCB: the number of UDP protocol control blocks. One
   per active RAW "connection". */
#define MEMP_NUM_RAW_PCB         3
/* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
   per active UDP "connection". */
#define MEMP_NUM_UDP_PCB         4
/* MEMP_NUM_TCP_PCB: the number of simultaneously active TCP
   connections. */
#define MEMP_NUM_TCP_PCB         64
/* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
   connections. */
#define MEMP_NUM_TCP_PCB_LISTEN  64
/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. */
#define MEMP_NUM_TCP_SEG         64
/* MEMP_NUM_SYS_TIMEOUT: the number of simultaneously active
   timeouts. */
#define MEMP_NUM_SYS_TIMEOUT     65

/* The following four are used only with the sequential API and can be
   set to 0 if the application only will use the raw API. */
/* MEMP_NUM_NETBUF: the number of struct netbufs. */
#define MEMP_NUM_NETBUF          2
/* MEMP_NUM_NETCONN: the number of struct netconns. */
#define MEMP_NUM_NETCONN         10
/* MEMP_NUM_TCPIP_MSG_*: the number of struct tcpip_msg, which is used
   for sequential API communication and incoming packets. Used in
   src/api/tcpip.c. */
#define MEMP_NUM_TCPIP_MSG_API   16
#define MEMP_NUM_TCPIP_MSG_INPKT 16

/* ---------- Pbuf options ---------- */
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE          120

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE       256

/* PBUF_LINK_HLEN: the number of bytes that should be allocated for a
   link level header. */
#define PBUF_LINK_HLEN          16

/** SYS_LIGHTWEIGHT_PROT
 * define SYS_LIGHTWEIGHT_PROT in lwipopts.h if you want inter-task protection
 * for certain critical regions during buffer allocation, deallocation and memory
 * allocation and deallocation.
 */
#define SYS_LIGHTWEIGHT_PROT           1

/* ---------- UDP options ---------- */
#define LWIP_UDP              1
#define LWIP_UDPLITE          1

/* ---------- TCP options ---------- */
#define LWIP_TCP                1
#define TCP_TTL                 255

/* Controls if TCP should queue segments that arrive out of
   order. Define to 0 if your device is low on memory. */
#define TCP_QUEUE_OOSEQ         0

/* TCP Maximum segment size. */
#define TCP_MSS                 1024

/* TCP sender buffer space (bytes). */
#define TCP_SND_BUF             (8 * TCP_MSS)

/* TCP sender buffer space (pbufs). This must be at least = 2 *
   TCP_SND_BUF/TCP_MSS for things to work. */
#define TCP_SND_QUEUELEN        (8 * TCP_SND_BUF/TCP_MSS)

/* TCP writable space (bytes). This must be less than or equal
   to TCP_SND_BUF. It is the amount of space which must be
   available in the tcp snd_buf for select to return writable */
#define TCP_SNDLOWAT		    (TCP_SND_BUF/2)

/* TCP receive window. */
#define TCP_WND                 16384

/* Maximum number of retransmissions of data segments. */
#define TCP_MAXRTX              12

/* Maximum number of retransmissions of SYN segments. */
#define TCP_SYNMAXRTX           12

#define TCP_LISTEN_BACKLOG      1
#define LWIP_CALLBACK_API       1

/* ---------- ARP options ---------- */
/* Glibc sends more than one packet in a row during an ARP resolution */
#define LWIP_ARP                 1
#define ARP_QUEUEING             1
#define ARP_QUEUE_LEN            10
#define ETHARP_TABLE_MATCH_NETIF 1

/* ---------- IP options ---------- */
/* Define IP_FORWARD to 1 if you wish to have the ability to forward
   IP packets across network interfaces. If you are going to run lwIP
   on a device with only one network interface, define this to 0. */
#define IP_FORWARD              0

/* IP reassembly and segmentation.These are orthogonal even
 * if they both deal with IP fragments */
#define IP_REASSEMBLY           0
#define IP_FRAG                 0

/* ---------- ICMP options ---------- */
#define LWIP_ICMP               1
#define LWIP_ICMP6              1
#define ICMP_TTL                255

/* ---------- DHCP options ---------- */
/* Define LWIP_DHCP to 1 if you want DHCP configuration of
   interfaces. */
#define LWIP_DHCP               0

/* ---------- AUTOIP options ------- */
#define LWIP_AUTOIP             0

/* ---------- RAW options ---------- */
#define LWIP_RAW                1
#define RAW_TTL                 255

/* ---------- Statistics options ---------- */
/* individual STATS options can be turned off by defining them to 0
 * (e.g #define TCP_STATS 0). All of them are turned off if LWIP_STATS
 * is 0
 * */
#define LWIP_STATS	0
#define LWIP_STATS_DISPLAY  0

/* ---------- General stuff ---------- */

/* Only send complete packets to the device */
#define LWIP_NETIF_TX_SINGLE_PBUF 1

/* Randomize local ports */
#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS  1

/* No loopback */
#define LWIP_NETIF_LOOPBACK   0
#define LWIP_HAVE_LOOPIF      0

/* Throughput settings */
#define LWIP_CHECKSUM_ON_COPY   1

/* Don't abort the whole stack when an error is detected */
#define LWIP_NOASSERT_ON_ERROR   1

/* Threading options */
#define LWIP_TCPIP_CORE_LOCKING   1

#if !NO_SYS
void sys_check_core_locking(void);
#define LWIP_ASSERT_CORE_LOCKED()  sys_check_core_locking()
void sys_mark_tcpip_thread(void);
#define LWIP_MARK_TCPIP_THREAD()   sys_mark_tcpip_thread()

#if LWIP_TCPIP_CORE_LOCKING
void sys_lock_tcpip_core(void);
#define LOCK_TCPIP_CORE()          sys_lock_tcpip_core()
void sys_unlock_tcpip_core(void);
#define UNLOCK_TCPIP_CORE()        sys_unlock_tcpip_core()
#endif
#endif

#endif /* __LWIPOPTS_H__ */
