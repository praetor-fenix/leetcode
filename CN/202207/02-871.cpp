#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel;
        int pos = 0;
        int result = 0;
        int size = stations.size();
        for(int i = 0; i <= size; ++i) {
            int station_fuel = (i == size ? 0 : stations[i][1]);
            int station_pos = (i == size ? target : stations[i][0]);
            int distance = station_pos - pos;
            while(fuel < distance && !pq.empty()) {
                fuel += pq.top();
                pq.pop();
                ++result;
            }

            if(fuel < distance) {
                return -1;
            }

            fuel -= distance;
            pos = station_pos;
            pq.push(station_fuel);
        }

        return result;
    }
};