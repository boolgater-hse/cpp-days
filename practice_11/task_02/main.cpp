#include <iostream>
#include <unordered_map>

// https://leetcode.com/problems/design-underground-system

using namespace std;

class UndergroundSystem
{
private:
    unordered_map <string, pair <int, int>> checkoutMap;
    unordered_map <int, pair <string, int>> checkInMap;
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto& checkIn = checkInMap[id];
        string path = checkIn.first + "_" + stationName;
        checkoutMap[path].first += t - checkIn.second;
        checkoutMap[path].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string path = startStation + "_" + endStation;
        auto& checkout = checkoutMap[path];
        return (double) checkout.first / checkout.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15); // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem.checkOut(27, "Waterloo", 20); // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 11.00000
    undergroundSystem.checkOut(10, "Waterloo", 38); // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 12.00000

    return 0;
}
