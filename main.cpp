#include<iostream>
#include<array>

constexpr int SIZE = 10;

class TimeSeries
{
    public:
        void insert(int t, int v);
        int find(int t);
        int binSearch(int low, int high, int t);
    private:
        int index{-1};
        // size of array must be known at compile time
        // If size is unknown use a std::vector<> instead
        std::array<int, SIZE> time;
        std::array<int, SIZE> value;
};
void TimeSeries::insert(int t, int v)
{
    index = (index + 1) % SIZE;
    time[index] = t;
    value[index] = v;
}
int TimeSeries::binSearch(int low, int high, int t)
{
    while(high >= low)
    {
        int mid = (low + high) / 2;
        int offsetmid = (mid + index + 1) % SIZE;
        std::cout << "low, mid, high = " << low << ", " << mid << ", " << high << '\n';
        if(t == time[offsetmid]) return offsetmid;
        if(t < time[offsetmid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (high + index + 1) % SIZE;
}
int TimeSeries::find(int t)
{
    int first = (index + 1) % SIZE;
    int last = index;
    if(t < time[first]) return -1;
    if(t > time[last]) return value[last];
    int found = binSearch(0, SIZE - 1,t);
    return value[found];
}
int main()
{
    TimeSeries timeSeries;
    timeSeries.insert(5, 100);
    timeSeries.insert(6, 200);
    timeSeries.insert(7, 300);
    timeSeries.insert(10, 400);
    timeSeries.insert(15, 500);
    timeSeries.insert(16, 600);
    timeSeries.insert(21, 700);
    timeSeries.insert(22, 800);
    timeSeries.insert(24, 900);
    timeSeries.insert(30, 1000);
    timeSeries.insert(34, 1100);
    timeSeries.insert(40, 1200);
    timeSeries.insert(42, 1300);
    timeSeries.insert(54, 1400);

    //std::cout << "Second 10: " << timeSeries.find(10) << '\n';
    //std::cout << "Second 90: " << timeSeries.find(90) << '\n';
    //std::cout << "Second 21: " << timeSeries.find(21) << '\n';
    //std::cout << "Second 40: " << timeSeries.find(40) << '\n';
    //std::cout << "Second 23: " << timeSeries.find(23) << '\n';
    //std::cout << "Second 46: " << timeSeries.find(46) << '\n';
    std::cout << "Second 32: " << timeSeries.find(32) << '\n';

    return 0;
}
