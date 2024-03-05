#include<iostream>
using namespace std;
//by张佳宇
//1.复盘了上课时讲的顺序表类，并根据课本自己写了myvector类
//2.增加由n个element构造myvector的构造函数
//3.修改优化了recap()函数
//4.自己写了mysort算法，可以对myvector中的元素进行排序，并用回调函数（函数指针作为算法参数）来决定由大到小还是由小到大排序。



int capint = 5;
template<class T>
class myvector {
private:
	T* data;
	int size;
	int capacity;
public:
	myvector();
	myvector(int n,T e);//用n个e来初始化
	myvector(const myvector& m);
	~myvector();
	int getsize() { return size; }
	int getcapa() { return capacity; }
	void recap(int n);
	bool geti(int i, T& e);
	bool seti(int i, T& e);
	int getNo(T e);
	void add(T e);
	void insert(int i, T e);
	void deletem(int i);
	void printall();
	T*& begin();
	T* end();
};

template<class T>
myvector<T>::myvector()
{
	data = new T[capint];
	size = 0;
	capacity = capint;
}

template<class T>
myvector<T>::myvector(int n, T e)
{
	data = new T[2 * n];
	for (int i = 0; i < n; i++)
		data[i] = e;
	size = n;
	capacity = 2 * n;
}

template<class T>
myvector<T>::myvector(const myvector& m)
{
	capacity = m.capacity;
	size = m.size;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
		data[i] = m.data[i];
}

template<class T>
myvector<T>::~myvector()
{
	delete[]data;
}

template<class T>
void myvector<T>::recap(int n)
{
	if (n <= 0)return;
	capacity = n;
	T* olddata = data;
	data = new T[capacity];
	if (capacity >= size)
		for (int i = 0; i < size; i++)
			data[i] = olddata[i];
	else if (capacity < size)
	{
		for (int i = 0; i < capacity; i++)
			data[i] = olddata[i];
		size = capacity;
	}
	delete []olddata;

}

template<class T>
bool myvector<T>::geti(int i, T& e)
{
	if (i < 0 || i >= size)return 0;
	e = data[i];
	return 1;
}

template<class T>
bool myvector<T>::seti(int i, T& e)
{
	if (i < 0 || i >= size)return 0;
	data[i]=e;
	return 1;
}

template<class T>
int myvector<T>::getNo(T e)
{
	int i = 0;
	while (data[i] != e)
		i++;
	if (i >= size) return -1;
	return i;
}

template<class T>
void myvector<T>::add(T e)
{
	if (size == capacity)
		recap(2 * size);
	data[size] = e;
	size++;
}

template<class T>
void myvector<T>::insert(int i, T e)
{
	if (i<0 || i>=size)return;
	if (size == capacity)
		recap(2 * size);
	size++;
	for (int j = size-1; j > i; j--)
		data[j]=data[j-1];
	data[i] = e;

}

template<class T>
void myvector<T>::deletem(int i)
{
	if (i < 0 || i >= size)return;
	for (int j = i; j < size-1; j++)
		data[j] = data[j + 1];
	size--;
	if (size <= capacity / 4)
		recap(capacity / 2);

}

template<class T>
void myvector<T>::printall()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<class T>
T*& myvector<T>::begin()
{
	return data;
	// TODO: 在此处插入 return 语句
}

template<class T>
T* myvector<T>::end()
{
	return &data[size - 1] + 1;
}

//算法mysort
template<class T>
void mysort(T* beg,T* end,bool(*fun)(T &a,T &b))
{
	for (T* it = beg; it < end - 1; it++) {
		T* min = it;
		for (T* j = it + 1; j < end; j++)
			if (fun(*j, *min)) min = j;
		swap(*it, *min);

	}
}
template<class T>
bool bigger(T& a,T  &b)
{
	if (a > b)
		return 1;
	return 0;
}
template<class T>
bool smaller(T& a, T& b)
{
	if (a < b)
		return 1;
	return 0;
}
void test1()
{
	using ArrInt = myvector<int>;
	ArrInt v1;
	v1.add(1);
	v1.add(9);
	v1.add(5);
	v1.add(2);
	v1.add(10);
	v1.add(7);
	v1.add(1);
	cout << "v1:";
	v1.printall();
	cout << "v1大小为" << v1.getsize() << endl;
	cout << "v1容量为" << v1.getcapa()<<endl;
	int a;
	if (v1.geti(5, a))cout << "第6个元素为" << a << endl;
	cout << "第" << v1.getNo(5) + 1 << "个元素为" << 5 << endl;
	v1.deletem(2);
	cout << "v1:";
	v1.printall();
	mysort(v1.begin(), v1.end(),bigger);
	cout << "v1:";
	v1.printall();
	mysort(v1.begin(), v1.end(), smaller);
	cout << "v1:";
	v1.printall();


	ArrInt v2(15,2);
	v2.insert(10, 23);
	int b = 112;
	v2.seti(14,b);
	cout << "v2:";
	v2.printall();
	cout << "v2大小为" << v2.getsize() << endl;
	cout << "v2容量为" << v2.getcapa() << endl;
}

int main()
{
	test1();
}