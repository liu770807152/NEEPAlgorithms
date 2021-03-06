#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30010;

struct Student {
    char registration_number[15]; //考号
    int score; //分数
    int location_number; //考场号
    int local_rank; //考场排名
} stu[maxn];

bool cmp(Student a, Student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.registration_number, b.registration_number) < 0;
}

int main() {
    int n, k, num = 0;
    scanf("%d", &n);
    //输入数据并在考场内部排序
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k); //该考场人数
        for (int j = 0; j < k; j++) {
            stu[num].location_number = i; //考场号
            scanf("%s %d", stu[num].registration_number, &stu[num].score);
            num++;
        }
        sort(stu + num - k, stu + num, cmp); //排序
        //考场内排名
        stu[num - k].local_rank = 1;
        for (int j = num - k + 1; j < num; j++) {
            if (stu[j].score != stu[j - 1].score)
                stu[j].local_rank = j + 1 - (num - k);
            else
                stu[j].local_rank = stu[j - 1].local_rank;
        }
    }
    //总成绩排序并排名
    sort(stu, stu + num, cmp);
    int r = 1;
    printf("%d\n", num);
    for (int i = 0; i < num; i++) {
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            r = i + 1;
        }
        printf("%s ", stu[i].registration_number);
        printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
    }
    return 0;
}
