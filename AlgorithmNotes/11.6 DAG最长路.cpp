/**
* 问题1：求整个DAG中的最长路径（即不固定起点跟终点）
* 问题2：固定终点，求DAG的最长路径
**/

int DP(int i) {
    if (dp[i] > 0)
        return dp[i]; //dp[i]已计算得到
    for (int j = 0; j < n; j++) {
        //遍历i的所有出边
        if (G[i][j] != INF) {
            int temp = DP(j) + G[i][j]; //单独计算，防止if中调用DP函数两次
            if (temp > dp[i]) {
                //可以获得更长的路径
                dp[i] = temp; //覆盖dp[i]
                choice[i] = j; //i号顶点的后继顶点是j
            }
        }
    }
    return dp[i]; //返回计算完毕的dp[i]
}
void printPath(int i) {
    printf("%d", i);
    while (choice[i] != -1) {
        //choice数组初始化为-1
        i = choice[i];
        printf("->%d", i);
    }
}

int DP(int i) {
    if (vis[i])
        return dp[i]; //dp[i]已计算得到
    vis[i] = true;
    for (int j = 0; j < n; j++) {
        //遍历i的所有出边
        if (G[i][j] != INF)
            dp[i] = max(dp[i], DP(j) + G[i][j]);
    }
    return dp[i]; //返回计算完毕的dp[i]
}
