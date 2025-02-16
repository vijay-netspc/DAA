#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void activitySelection(vector<pair<int, int>> &activities) {
    sort(activities.begin(), activities.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int count = 1, last = activities[0].second;
    cout << "Selected activities: (Start, End)\n" << activities[0].first << " " << activities[0].second << endl;

    for (auto &[start, end] : activities) {
        if (start >= last) {
            cout << start << " " << end << endl;
            last = end;
            count++;
        }
    }

    cout << "Total activities: " << count << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);
    cout << "Enter start and end times:\n";
    for (auto &[s, e] : activities) cin >> s >> e;

    activitySelection(activities);
    return 0;
}
