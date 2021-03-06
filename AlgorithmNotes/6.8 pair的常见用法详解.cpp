/**
* pair：可以看作一个内部有两个元素的结构体
*       且这两个元素的类型是可以指定的
*
*		struct pair
*		{
*			typeName1 first;
*			typeName2 second;
*		};
*
**/
#include <cstdio>
#include <utility>
using namespace std;


//pair的定义
pair<typeName1, typeName2> name;
pair<string, int> p;
pair<string, int> p("haha", 5);
//在代码中临时构建的两种方法如下
pair<string, int>("haha", 5);
make_pair("haha", 5);


//pair中元素的访问
{
    pair<string, int> p;
    p.first = "haha";
    p.second = 5;
    cout << p.first << " " << p.second << endl; //haha 5
    p = make_pair("xixi", 55);
    cout << p.first << " " << p.second << endl; //xixi 55
    p = pair<string, int>("heihei", 555);
    cout << p.first << " " << p.second << endl; //heihei 555
}


//pair常用函数实例解析
//比较操作数，两个pair类型数据可以直接使用==、!=、<、<=、>、>=比较大小
//比较规则：先以first的大小为标准，只有当first相等时才去判别second的大小
{
    pair<int, int> p1(5, 10);
    pair<int, int> p2(5, 15);
    pair<int, int> p3(10, 5);
    if (p1 < p3)
        printf("p1 < p3\n");
    if (p1 <= p3)
        printf("p1 <= p3\n");
    if (p1 < p2)
        printf("p1 < p2\n");
}


//pair的常见用途
// (1) 用来代替二元结构体及其构造函数，可以节省编码时间
// (2) 作为map的键值对来进行插入，如下例
{
    map<string, int> mp;
    mp.insert(make_pair("heihei", 5));
    mp.insert(pair<string, int>("haha", 10));
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;
}
