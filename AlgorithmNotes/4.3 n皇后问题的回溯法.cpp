#include <cstdio>
#include <cmath>
const int maxn = 11;

int n, P[maxn], hashTable[maxn] = { false }; //P为当前排列，hashTable记录整数x是否已经在P中
int count = 0;

void generateP(int index) {

    //递归边界，生成一个合法方案
    if (index == n + 1) {
        count++; //能达到这里的一定是合法的
        return;
    }

    //第x行
    for (int x = 1; x <= n; x++) {
        //第x行还没有皇后
        if (hashTable[x] == false) {
            bool flag = true; //flag为true表示当前皇后不会和之前的皇后冲突
            //遍历之前的皇后
            for (int pre = 1; pre < index; pre++) {
                //第index列皇后的行号为x，第pre列皇后的行号为P[pre]
                if (abs(index - pre) == abs(x - P[pre])) {
                    flag = false; //与之前的皇后在一条对角线，冲突
                    break;
                }
            }
            //如果可以把皇后放在第x行
            if (flag) {
                P[index] = x; //令第index列皇后的行号为x
                hashTable[x] = true; //第x行已被占用
                generateP(index + 1); //递归处理第 index+1 行皇后
                hashTable[x] = false; //递归完毕，还原第x行为未占用
            }
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        count = 0;
        generateP(1);
        printf("%d\n", count);
    }
    return 0;
}
