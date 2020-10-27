#include<iostream>
#include<pthread.h>
#include<mutex>
#include<vector>
using namespace std;

int index = 0;


/*第一种最简单的锁*/
mutex mutex1;
void count1() {
	//加锁
	mutex1.lock();
	index += 1;
	cout <<index<< endl;
	mutex1.unlock();
}

/*第二种，类似智能指针
在构造函数加锁，在析构函数解锁*/
mutex mutex2;
void count2() {
	lock_guard<mutex> lock(mutex2);
	index += 1;
}

/*不加锁测试*/
void countNo() {
	index += 1;
	cout << index << endl;
}

void test1() {
	index = 0;

}

int main() {
	//创建一组线程
	vector<thread> v;
	v.reserve(20);
	cout << "有锁" << endl;
	for (int i = 0; i < 20; i++)
	{
		v.emplace_back(&count1);
	}
	//等待所有线程结束
	for (thread&t :v)
	{
		t.join();
	}


	//这组线程没有锁
	vector <thread> v2;
	v.reserve(20);
	cout << "没有锁" << endl;
	for (int i = 0; i < 20; i++)
	{
		v2.emplace_back(&countNo);
	}
	for (thread& t : v2)
	{
		t.join();
	}
}