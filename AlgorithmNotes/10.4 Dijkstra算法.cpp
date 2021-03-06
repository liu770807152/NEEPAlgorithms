/**
* Dijkstra算法：解决单源最短路径问题
**/

//伪代码
//G为图，一般设为全局变量；数组d为源点到达各点的最短路径长度；s为起点
Dijkstra(G, d[], s) {
    初始化;
    for (循环n次) {
        u = 使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for (从u出发能到达的所有顶点v) {
            if (v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优) {
                优化d[v];
            }
        }
    }
}

//邻接矩阵版
int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = { false }; //标记数组，vis[i]==true表示已访问，初值均为false
//s为起点
void Dijkstra(int s) {
    fill(d, d + MAXV, INF); //fill函数将整个d数组赋值为INF
    d[s] = 0; //起点s到达自身的距离为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        //找到未访问的顶点中d[]最小的
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
            return;
        vis[u] = true; //标记u已被访问
        for (int v = 0; v < n; v++) {
            //如果v未访问 && u能到达v && 以u为中介点可以使d[v]更优
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                d[v] = d[u] + G[u][v]; //优化d[v]
        }
    }
}

//邻接表版
struct Node {
    int v, dis; //v为边的目标顶点，dis为边权
};
vector<Node> Adj[MAXV]; //图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = { false }; //标记数组，vis[i]==true表示已访问，初值均为false
//s为起点
void Dijkstra(int s) {
    fill(d, d + MAXV, INF); //fill函数将整个d数组赋值为INF
    d[s] = 0; //起点s到达自身距离为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        //找到未访问的顶点中d[]最小的
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
            return;
        vis[u] = true; //标记u已被访问
        //只有下面这个for与邻接矩阵的写法不同
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][v].v; //通过邻接表直接获得u能到达的顶点v
            //如果v未访问 && 以u为中介点可以使d[v]更优
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
                d[v] = d[u] + Adj[u][j].dis; //优化d[v]
        }
    }
}

//记录前驱结点的写法见晴神宝典p375

//三种出题方法及其组合见晴神宝典p376
