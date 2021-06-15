#include <sys/unistd.h>
#include <sys/inotify.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// _syscall0(int, inotify_init)
// _syscall3(int, inotify_add_watch, int, fd, const char *, path, __u32, mask)
// _syscall2(int, inotify_rm_watch, int, fd, __u32, mask)
char * monitored_files[] = {
    "./test.cpp",
    "./history",
    "/mnt/x/work/bluetooth/test"
};
struct wd_name {
    int wd;
    char * name;
};
#define WD_NUM 3
struct wd_name wd_array[WD_NUM];
char * event_array[] = {
    "File was accessed",
    "File was modified",
    "File attributes were changed",
    "writtable file closed",
    "Unwrittable file closed",
    "File was opened",
    "File was moved from X",
    "File was moved to Y",
    "Subfile was created",
    "Subfile was deleted",
    "Self was deleted",
    "Self was moved",
    "",
    "Backing fs was unmounted",
    "Event queued overflowed",
    "File was ignored"
};
#define EVENT_NUM 16
#define MAX_BUF_SIZE 1024

int main(void)
{
    int fd;
    int wd;
    char buffer[1024];
    char * offset = NULL;
    struct inotify_event * event;
    int len, tmp_len;
    char strbuf[16];
    int i = 0;

    fd = inotify_init();
    if (fd < 0) {
        printf("Fail to initialize inotify.\n");
        exit(-1);
    }
    // for (i=0; i<WD_NUM; i++) {
    //     wd_array[i].name = monitored_files[i];
    //     wd = inotify_add_watch(fd, wd_array[i].name, IN_ALL_EVENTS);
    //     if (wd < 0) {
    //         printf("Can't add watch for %s.\n", wd_array[i].name);
    //         exit(-1);
    //     }
    //     wd_array[i].wd = wd;
    // }
    wd = inotify_add_watch(fd, "/mnt/x/work/bluetooth/test/", IN_ALL_EVENTS);
    if (wd < 0) {
        printf("Can't add watch for /mnt/x/work/bluetooth/test/");
        exit(-1);
    }
    // int i = 1;
    while(len = read(fd, buffer, MAX_BUF_SIZE)) {
        offset = buffer;
        printf("Some event happens, len = %d.\n", len);
        event = (struct inotify_event *)buffer;
        while (((char *)event - buffer) < len) {
            if((IN_CREATE|IN_MOVED_TO) & event->mask) {
            // 新增文件
            printf(" 新增文件 = %s.\n", event->name);
                    // sprintf(ndir, "%s/%s", dirset.find(event->wd)->second.c_str(),
                    //     event->name);
            } else if(IN_CLOSE_WRITE & event->mask) {
            // 修改文件内容
            printf(" 修改文件内容 = %d.\n", event->mask);
            }

            // printf("eventis = %d.\n", event->mask);
            // if (event->mask & IN_ISDIR) {
            //     memcpy(strbuf, "Direcotory", 11);
            // }
            // else {
            //     memcpy(strbuf, "File", 5);
            // }
            // printf("Object type: %s\n", strbuf);
            // for (i=0; i<WD_NUM; i++) {
            //     if (event->wd != wd_array[i].wd) continue;
            //     printf("Object name: %s\n", wd_array[i].name);
            //     break;
            // }
            // printf("Event mask: %08X\n", event->mask);
            // for (i=0; i<EVENT_NUM; i++) {
            //     if (event_array[i][0] == '\0') continue;
            //     if (event->mask & (1<<i)) {
            //         printf("Event: %s\n", event_array[i]);
            //     }
            // }
            tmp_len = sizeof(struct inotify_event) + event->len;
            event = (struct inotify_event *)(offset + tmp_len); 
            offset += tmp_len;
        }
    }
}