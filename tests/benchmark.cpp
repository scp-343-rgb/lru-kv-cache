#include <random>
#include <iostream>
#include <string>
#include <vector>
#include "lru_cache.h"
#include "Fifo_cache.h"
using namespace std;

enum class OperationType { get, put };

struct Operation
{
    OperationType type;
    string key;
    string value;
};

struct BenchmarkResult
{
    size_t gets = 0;
    size_t hits = 0;
    size_t misses = 0;
    double hitRate = 0;
};

BenchmarkResult runLRU(int capacity, const vector<Operation>& workload)
{
    BenchmarkResult result;
    LRUCache cache(capacity);
    for (auto& i : workload) {
        if (i.type == OperationType::get) {
            result.gets++;
            string temp = i.value;
            if (cache.get(i.key, temp)) result.hits++;
            else result.misses++;
        }
        else {
            cache.put(i.key, i.value);
        }
    }
    if (result.gets != 0) result.hitRate = static_cast<double>(result.hits) / result.gets;
    return result;
}

BenchmarkResult runFIFO(int capacity, const vector<Operation>& workload)
{
    BenchmarkResult result;
    FIFOCache cache(capacity);
    for (auto& i : workload) {
        if (i.type == OperationType::get) {
            result.gets++;
            string temp = i.value;
            if (cache.get(i.key, temp)) result.hits++;
            else result.misses++;
        }
        else {
            cache.put(i.key, i.value);
        }
    }
    if (result.gets != 0) result.hitRate = static_cast<double>(result.hits) / result.gets;
    return result;
}

vector<Operation> makeWorkLoad(int seed, int operations, int putpercent, int keyspace)
{
    vector<Operation> v;
    mt19937 gen(seed);
    uniform_int_distribution<int> keydist(0, keyspace - 1);
    uniform_int_distribution<int> operation(1, 100);
    for (int i = 0;i < operations;i++) {
        int key_i = keydist(gen), operation_i = operation(gen);
        string key = to_string(key_i);
        Operation temp;
        if (operation_i <= putpercent) {
            OperationType type = OperationType::put;
            string value = key;
            temp.type = type;
            temp.key = key;
            temp.value = value;
        }
        else {
            OperationType type = OperationType::get;
            temp.type = type;
            temp.key = key;
        }
        v.emplace_back(temp);
    }
    return v;
}

void printResult(int capacity,const BenchmarkResult& result)
{
    cout << "capacity= " << capacity << " gets= " << result.gets
        << " hits= " << result.hits << " misses= " << result.misses
        << " hitRate= " << result.hitRate << " " << endl;
}

int main() {
    int kseed = 20261116, koperations = 100000, kkeyspace = 10000, kputpercent = 20;
    vector <int> capacities = { 10,100,1000,10000 };
    vector<Operation>v = makeWorkLoad(kseed, koperations, kputpercent, kkeyspace);
    for (auto i : capacities) {
        BenchmarkResult result1 = runLRU(i, v);
        BenchmarkResult result2 = runFIFO(i, v);
        cout << "LRU: ";
        printResult(i, result1);
        cout << "FIFO: ";
        printResult(i, result2);
    }
    return 0;
}