#include <sys/socket.h>
#include <linux/netlink.h>

#define NETLINK_OBJSTR 17

#define MAX_PAYLOAD 1024 //Maximum payload size
struct sockaddr_nl src_addr, dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock_fd;
struct msghdr msg;

void main()
{
	/*Create Socket
	 * int domain:PF_NETLINK = domain of socket to create (netlink - socket used for kernel to userspace communication)
	 * int type:SOCK_RAW = type of socket to create (SOCK_RAW - raw protocol..might have to change this later for photos)
	 * NETLINK_NITRO = developer defined NETLINK protocol (I defined this in the kernel module, here, and linux/netlink.h)
	 * I used 17 for the NITRO macro since it was the next available integer
	 */
	sock_fd=socket(PF_NETLINK, SOCK_RAW, NETLINK_OBJSTR);
	
	//Checks
	if(sock_fd<0){
		return -1;
	}
	
	//Initialize socket address struct neccessary for socket binding below
	memset(&src_addr, 0, sizeof(src_addr));
	src_addr.nl_family = AF_NETLINK;
	src_addr.nl_pid = getpid(); //current processes' pid, acts like a pointer to this program (used by kernel?)

	//bind the address struct to the socket file descriptor
	bind(sock_fd, (struct sockaddr*)&src_addr, sizeof(src_addr));
	
	//Initialize the destination address struct (to Linux kernel)
	memset(&dest_addr, 0, sizeof(dest_addr));
	dest_addr.nl_family = AF_NETLINK;
	dest_addr.nl_pid = 0; //Linux kernel
	dest_addr.nl_groups = 0; //Unicast
	
	//The kernel assumes the existence of a message header with each netlink message for consistency
	nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
	memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
	nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
	nlh->nlmsg_pid = getpid();
	nlh->nlmsg_flags = 0;

	strcpy(NLMSG_DATA(nlh), "Hello");

	iov.iov_base = (void *)nlh;
	iov.iov_len = nlh->nlmsg_len;
	msg.msg_name = (void *)&dest_addr;
	msg.msg_namelen = sizeof(dest_addr);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	printf("Sending message to kernel\n");
	sendmsg(sock_fd,&msg,0);
	printf("Waiting for message from kernel\n");

	/* Read message from kernel */
	recvmsg(sock_fd, &msg, 0);	
	printf("Received message payload: %s\n", NLMSG_DATA(nlh));
	close(sock_fd);
}
