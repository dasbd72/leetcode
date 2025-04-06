#include <bits/stdc++.h>
using namespace std;

template <class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check) {
    if (check(L)) {
        return {L - 1, L};
    }
    if (!check(R)) {
        return {R, R + 1};
    }
    while (L + 1 < R) {
        Ty M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    return {L, R};
}

typedef tuple<int, int, int> Packet;

class Router {
   public:
    int memory_limit;
    deque<Packet> buffer;
    set<Packet> buffer_set;
    unordered_map<int, deque<int>> ts_buffer;

    Router(int memoryLimit) {
        memory_limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        Packet packet(source, destination, timestamp);
        if (buffer.size() && get<2>(buffer.back()) < timestamp) {
            buffer_set.clear();
        }
        if (buffer_set.find(packet) != buffer_set.end()) {
            return false;
        }
        buffer.push_back(packet);
        buffer_set.insert(packet);
        ts_buffer[destination].push_back(timestamp);
        if (buffer.size() > memory_limit) {
            Packet head = buffer.front();
            buffer.pop_front();
            buffer_set.erase(head);
            ts_buffer[get<1>(head)].pop_front();
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (buffer.empty()) {
            return {};
        }
        Packet head = buffer.front();
        buffer.pop_front();
        buffer_set.erase(head);
        ts_buffer[get<1>(head)].pop_front();
        return {get<0>(head), get<1>(head), get<2>(head)};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (ts_buffer.find(destination) == ts_buffer.end() || ts_buffer[destination].empty()) {
            return 0;
        }
        auto checkStart = [&](int pos) {
            return ts_buffer[destination][pos] >= startTime;
        };
        auto checkEnd = [&](int pos) {
            return ts_buffer[destination][pos] > endTime;
        };
        auto start = binarySearch(0, (int)ts_buffer[destination].size() - 1, checkStart);
        auto end = binarySearch(0, (int)ts_buffer[destination].size() - 1, checkEnd);
        int cnt = end.second - start.second;
        return cnt;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */