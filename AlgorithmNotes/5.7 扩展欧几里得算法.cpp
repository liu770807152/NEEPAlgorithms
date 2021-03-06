/**
* 扩展欧几里得算法
**/


/**
* 问题1：给定两个非零整数a和b，求一组整数解(x,y)，使得ax+by=gcd(a,b)成立，其中gcd(a,b)表示a和b的最大公约数
* 递归边界：x=1，y=0
* 递推公式：x1=y2，y1=x2-(a/b)y2
* 全部解：x'=x+b/gcd*K，y'=y-a/gcd*K，其中K为任意整数
*         x和y的所有解分别以b/gcd与a/gcd为周期
*         其中，对任意整数来说，(x%(b/gcd)+(b/gcd))%(b/gcd)为x的最小非负整数解
**/
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int exGcd(int a, int b, int &x, int &y) {
    //x和y使用引用
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y); //递归计算exGcd(b,a%b)
    int temp = x; //存放x的值
    x = y; //更新x = y(old)
    y = temp - a / b * y; //更新y = x(old) - a / b * y(old)
    return g; //g是gcd
}


/**
* 问题2：方程ax+by=c的求解
* 思路：ax+by=c存在解的虫咬条件是c%gcd==0，且一组解(x,y)等于(cx0/gcd,cy0/gcd)
* 全部解：x'=x+b/gcd*K=cx0/gcd+b/gcd*K，y'=y-a/gcd=cy0/gcd-a/gcd*K，其中K为任意整数
*         其中，对任意整数来说，(x%(b/gcd)+(b/gcd))%(b/gcd)为x的最小非负整数解
**/


/**
* 问题3：同余式ax≡c(mod m)的求解
* 同余式：对整数a,b,m来说，如果m整除a-b（即(a-b)%m=0），那么就说a与b模m同余
*         对应的同余式为a≡b(mod m)，m成为称为同余式的模
*         显然，每一个整数都各自与[0,m)中唯一的整数同余
* 结论：设a,c,m是整数，其中m≥1，则
*       ① 若c%gcd(a,m)≠0，则同余式方程ax≡c(mod m)无解
*       ② 若c%gcd(a,m)=0，则同余式方程ax≡c(mod m)恰好有gcd(a,m)个模m意义下不同的解
*          且解的形式为x'=x+m/gcd(a,m)*K，其中K=0,1,...,gcd(a,m)-1，x是ax+my=c的一个解
**/

/**
* 问题4：逆元的求解以及(b/a)%m的计算

* 逆元(此处特指乘法逆元)：假设a,b,m是整数，m>1，且有ab≡1(mod m)成立
*                         那么就说a和b互为模m的逆元，一般也记作a≡(1/b)(mod m)
* 通俗地说，如果两个整数的成绩模m后等于1，就称它们互为m的逆元

* 使用逆元计算(b/a)%m，思路：通过找到a模m的逆元x，就有(b/a)%m=(b*x)%m成立
* 由定义知，求a模m的逆元，就是求解同余式ax≡1(mod m)：
* ① 如果gcd(a,m)≠1，那么同余式ax≡1(mod m)无解，a不存在模m的逆元
* ② 如果gcd(a,m)＝1，那么同余式ax≡1(mod m)在(0,m)上有唯一解

* 费马小定理：设m是素数，a是任意整数且a恒不等于0(mod m)，则a^(m-1)≡1(mod m)
* 由费马小定理可推a^(m-2)%m就是a模m的逆元
* 因此在a和m有可能不互素的情况下，可以使用公式(b/a)%m=(b%(am))/a来计算(b/a)%m的值
**/
int inverse(int a, int m) {
    int x, y;
    int g = exGcd(a, m, x, y); //求解ax+my=1
    return (x % m + m) % m; //a模m的逆元为(x%m+m)%m
}
