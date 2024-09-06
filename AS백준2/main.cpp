#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> tree[10001];
vector<int> Level[10001];
int weight[10001];
int w = 1;

void BFS(int root) {
    queue<pair<int, int>> q;  // pair<노드, 깊이>
    q.push({ root, 1 });

    while (!q.empty()) {
        pair<int, int> front = q.front();  // pair<int, int>
        q.pop();
        int node = front.first;
        int depth = front.second;
        Level[depth].push_back(weight[node]);

        if (tree[node][0] != -1) {
            q.push({ tree[node][0], depth + 1 });
        }
        if (tree[node][1] != -1) {
            q.push({ tree[node][1], depth + 1 });
        }
    }
}

void dfs(int node) {
    weight[node] = w++;
    if (tree[node][0] != -1) {
        dfs(tree[node][0]);
    }
    if (tree[node][1] != -1) {
        dfs(tree[node][1]);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int r, L, R;
        cin >> r >> L >> R;
        tree[r].push_back(L);
        tree[r].push_back(R);
    }

    dfs(1);
    BFS(1);

    int max_width = 0, max_height = 0;
    for (int i = 1; i <= N; i++) {
        if (Level[i].empty()) break;
        int min_width = *min_element(Level[i].begin(), Level[i].end());
        int max_width_in_level = *max_element(Level[i].begin(), Level[i].end());
        max_width = max(max_width, max_width_in_level - min_width + 1);
        max_height = i;
    }

    cout << max_height << ' ' << max_width << endl;
    return 0;
}