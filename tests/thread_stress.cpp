#include "thread_safe.h"
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include <atomic>
#include <condition_variable>
using namespace std;

condition_variable cv;
mutex mtx;
atomic<int>cnt = 0;

void worker(int id, ThreadSafeLRUCache& cache, atomic<bool>& flag)
{
    {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [&flag] {
            return flag.load();
            });
    }
    for (int i = 0;i < 100000;i++) {
        int keyIndex = (id + i * 4) % 2000;
        string key = to_string(keyIndex);
        string value = "0";
        cache.put(key, key);
        cache.get(key, value);
        cache.get(key, value);
        cache.get(key, value);
        cache.get(key, value);
        cnt.fetch_add(5, memory_order_relaxed);
    }

}

int main() {
    ThreadSafeLRUCache cache(1000);
    vector<thread>threads;
    for (int i = 0;i < 1000;i++) {
        cache.put(to_string(i), to_string(i));
    }
    atomic<bool>flag = false;
    for (int i = 0;i < 4;i++) {
        threads.emplace_back(worker, i, ref(cache), ref(flag));
    }
    auto start = chrono::steady_clock::now();
    {
        lock_guard<mutex>lock(mtx);
        flag.store(true);
    }
    cv.notify_all();
    for (auto& t : threads) {
        t.join();
    }
    auto end = chrono::steady_clock::now();
    double second = chrono::duration<double>(end - start).count();
    double qps = cnt / second;
    cout << "operations=" << cnt << "seconds=" << second << "qps=" << qps << endl;
    return 0;
}