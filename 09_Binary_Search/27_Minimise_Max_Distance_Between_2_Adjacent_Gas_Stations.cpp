#include <bits/stdc++.h>
using namespace std;

double brute_minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();
    vector<int> howMany (n-1, 0);
    for (int gasStation = 1 ; gasStation <= k ; gasStation++)
    {
        double maxiGap = -1;
        int maxiIndex = -1;

        for (int i=0 ; i<=n-2 ; i++)
        {
            int diff = stations[i+1] - stations[i];
            double stationgap = (double)diff/(howMany[i]+1);
            if (maxiGap < stationgap)
            {
                maxiGap = stationgap;
                maxiIndex = i;
            }
        }

        howMany[maxiIndex]++;
    }

    double maxStationGap = -1;
    for (int i=0 ; i<=n-2 ; i++)
    {
        int diff = stations[i+1] - stations[i];
        double stationGap =  (double)diff/(howMany[i]+1);
        maxStationGap = max(maxStationGap, stationGap);
    }

    return maxStationGap;
}

double better_minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();
    priority_queue<pair<double,int>> pq;
    vector<int> howMany (n-1, 0);

    for (int i=0 ; i<=n-2 ; i++)
    {
        double diff = stations[i+1] - stations[i];
        pq.push({diff, i});
    }

    for (int gasStation = 1 ; gasStation <= k ; gasStation++)
    {
        auto tp = pq.top();
        pq.pop();
        int index = tp.second;
        howMany[index]++;
        int diff = stations[index+1] - stations[index];
        double stationGap = (double)diff/(howMany[index]+1);
        pq.push({stationGap, index});
    }

    return pq.top().first;
    
}

bool canWePlace(vector<int>& stations, int k, double limit)
{
    int n = stations.size();
    int count = 0;
    for (int i=0 ; i<=n-2 ; i++)
    {
        double diff = stations[i+1] - stations[i];
        int noOfStations = diff/limit;
        if (diff == noOfStations*limit)
        {
            noOfStations--;
        }
        count += noOfStations;
        if (count > k) return false;
    }
    return true;
}

double optimal_minmaxGasDist(vector<int>& stations, int k) {
    int n = stations.size();

    double low = 0;
    double high = -1;
    for (int i=0 ; i<=n-2 ; i++)
    {
        if (stations[i+1] - stations[i] > high)
        {
            high = stations[i+1] - stations[i];
        }
    }

    while (high - low > 1e-6)
    {
        double mid = (low + high)/2.0;

        if (canWePlace(stations, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    cout << brute_minmaxGasDist(v, 9) << endl;
    cout << better_minmaxGasDist(v, 9) << endl;
    cout << optimal_minmaxGasDist(v, 9) << endl;

    return 0;
}