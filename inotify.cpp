#include <sys/unistd.h>
#include <sys/inotify.h>
#include <errno.h>
#include <iostream>
#include <thread>
#include <pthread.h>
using namespace std;

void InotifyEvent()
{
    std::cout << "inotify test";
    // 创建 inotify 实例：
    int fd = inotify_init();
    if (fd < 0)
    {
        std::cout << "inotify_init failed";
        // return -1;
    }
    // 下面函数用于添加一个 watch：
    int wd = inotify_add_watch(fd, "/mnt/x/work/bluetooth/test/", IN_ALL_EVENTS);
    if (wd < 0)
    {
        std::cout << "inotify_add_watch failed";
        // return -1;
    }
}
int main()
{
    std::thread InotifyEventThread;
    InotifyEventThread = std::move(
    std::thread([=]() {
        InotifyEvent();
    }));

    // 删除inotify的watch对象
    // wd = inotify_rm_watch (fd, IN_ALL_EVENTS);
    // if (wd < -1) 
    // {
    //     std::cout << "notify_rm_watch error!";
    //     return -1;
    // }
}