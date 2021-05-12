#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>

MODULE_AUTHOR("Group 7");
MODULE_DESCRIPTION("Lab 2, using struct list_head");
MODULE_LICENSE("KPI");

#define LIST_LEN 10
#define MSG_PREF "List items: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);

typedef struct {
	struct list_head lnode;
	uint32_t val;
} int_node_t;

// Звільнення пам'яті
#define ilfree(list_head) \
    do {                                                                 \
        int_node_t *__ptr, *__tmp;                                       \
        list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) {     \
            kfree(__ptr);                                                \
        }                                                                \
    } while(0)

// Вивід значень списку в консоль
#define ilprint(list_head) \
    do {                                                                 \
        int_node_t *__ptr;                                               \
        print_msg("List: {");                                            \
        list_for_each_entry(__ptr, (list_head), lnode) {                 \
            printk(KERN_ERR "\t%i ", __ptr->val);                        \
        }                                                                \
        printk(KERN_ERR "}\n");                                          \
    } while(0)

static struct list_head int_list = LIST_HEAD_INIT(int_list);

// Інвертування кожного елемента в лісті
static void task(void) {
	int_node_t *ptr;
	list_for_each_entry(ptr, &int_list, lnode) {
		ptr->val = ~ptr->val;
	}	
}

static int __init list_module_init(void)
{
	int i;
	int ret = 0;
	print_msg("Module initialization!\n");
	print_msg("List allocation start...\n");
	// Виділення пам'яті
	for (i = 0; i < LIST_LEN; ++i) {
		int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
		if (!ptr) {
			print_msg("Can't alloc memory\n");
			ret = -ENOMEM;
			goto alloc_err;
		}
		// Рандомне значення для ліста
		get_random_bytes(&ptr->val, sizeof(ptr->val));
		list_add_tail(&ptr->lnode, &int_list);
	}
	print_msg("List allocation finish\n");
	ilprint(&int_list);

	task();

	ilprint(&int_list);

	return 0;
alloc_err:
	ilfree(&int_list);
	return ret;
}

static void __exit list_module_exit(void)
{
	ilfree(&int_list);
	print_msg("Module exiting!\n");
}
module_init(list_module_init);
module_exit(list_module_exit);
