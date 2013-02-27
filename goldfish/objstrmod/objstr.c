#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/netlink.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#include <linux/skbuff.h>
#define NETLINK_OBJSTR 17

MODULE_LICENSE("GPL");

static struct sock *nl_sk = NULL;

static void nl_data_ready(struct sk_buff *skb){
	struct nlmsghdr *nlh = NULL;
	//sk_buff is a linked list of buffers. In our case we only have 1 buffer.
	if(skb == NULL){
		printk("sk buffer is NULL \n");
		return ;
	}
	//Retrieve head pointer to our data which is contained in a message header.
	nlh = (struct nlmsghdr *)skb->data;
	printk(KERN_INFO "%s: received netlink message payload: %s\n", __FUNCTION__, NLMSG_DATA(nlh));
}

static void netlink_create(){
	//Create the initial socket upon module_init
	nl_sk = netlink_kernel_create(&init_net,NETLINK_OBJSTR,0, nl_data_ready,NULL, THIS_MODULE);
}

static int __init my_module_init(void){
	printk(KERN_INFO "Object Store: Initializing Netlink Socket");
	netlink_create();
return 0;
}

static void __exit my_module_exit(void){
	sock_release(nl_sk->sk_socket);
	printk(KERN_INFO "Released Object Store");
}

module_init(my_module_init);
module_exit(my_module_exit);
