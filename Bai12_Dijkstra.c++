#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX // giá trị vô cùng

int main() {
    int n, m; // n là số đỉnh, m là số cạnh
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n); // danh sách kề của đồ thị
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // thêm cạnh (u, v) với trọng số w vào danh sách kề của u
        adj[v].push_back({u, w}); // thêm cạnh (v, u) với trọng số w vào danh sách kề của v (nếu đồ thị vô hướng)
    }

    int s, t; // s là đỉnh bắt đầu, t là đỉnh kết thúc
    cin >> s >> t;

    vector<int> dist(n, INF); // khoảng cách ngắn nhất từ s đến các đỉnh khác
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // nếu khoảng cách đến u đã được cập nhật, bỏ qua

        for (auto e : adj[u]) { // duyệt các đỉnh kề của u
            int v = e.first;
            int w = e.second;
            if (dist[u] + w < dist[v]) { // nếu có đường đi từ s đến v thông qua u ngắn hơn
                dist[v] = dist[u] + w; // cập nhật khoảng cách ngắn nhất từ s đến v
                pq.push({dist[v], v}); // thêm v vào hàng đợi ưu tiên
            }
        }
    }

    if (dist[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << endl;
    } else {
        cout << "Khoang cach ngan nhat tu " << s << " den " << t << " la " << dist[t] << endl;
    }

    return 0;
}
