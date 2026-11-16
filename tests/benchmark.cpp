#include <random>
#include <iostream>
#include <string>
#include <vector>
#include "lru_cache.h"
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

int main() {
    int kseed = 20261116, koperations = 10000, kkeyspace = 1000, kputpercent = 20, kcapacity = 10;
    vector<Operation>v = makeWorkLoad(kseed, koperations, kputpercent, kkeyspace);
    BenchmarkResult result = runLRU(kcapacity, v);
    cout << "capacity= " << kcapacity << " " << result.gets << " " << result.hits << " " << result.misses
        << " " << result.hitRate << " " << endl;
    return 0;
}