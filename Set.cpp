#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int Maxnum = 200;
template<class T>
class Set
{
private:
	T* data;
	int length;
public:
	Set();
	~Set();
	int getlength() { return length; }
	T get(int i);
	bool IsIn(T e);
	void add(T e);
	void deletem(T e);
	void printall();
	Set& Copy();
	Set& Union(Set& s2);
	Set& Inter(Set& s2);
	Set& Differ(Set& s2);
	T& operator[](int n);
	operator T* ();
};

template<class T>
Set<T>::Set()
{
	data = new T[Maxnum];
	length = 0;
}

template<class T>
Set<T>::~Set()
{
	delete []data;
}

template<class T>
T Set<T>::get(int i)
{
	if (i < 0 || i >= length)
		cout << "参数i错误" << endl;
	return data[i];
}

template<class T>
bool Set<T>::IsIn(T e)
{
	for(int i=0;i<length;i++)
		if (data[i] == e)
		{
			return true;
		}
	return false;
}

template<class T>
void Set<T>::add(T e)
{
	if (!IsIn(e))
	{
		if (length < Maxnum)
		{
			data[length] = e;
			length++;
		}
		else
			cout << "集合已满" << endl;

	}
	else
	{
		cout << "已有该元素" << endl;
	}
}

template<class T>
void Set<T>::deletem(T e)
{
	if (!IsIn(e))
		cout << "集合中没有该元素" << endl;
	else
	{
		for(int i=0;i<length;i++)
			if (data[i] == e)
			{
				for (int j = i + 1; j < length; j++)
					data[j - 1] = data[j];
				length--;
			}

	}
}

template<class T>
void Set<T>::printall()
{
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout<<endl;

}

template<class T>
Set<T>& Set<T>::Copy()
{
	static Set s3;
	for (int i = 0; i < length; i++)
		s3.add(data[i]);
	return s3;

}

template<class T>
Set<T>& Set<T>::Union(Set& s2)
{
	Set& s3 = Copy();
	for (int i = 0; i < s2.length; i++)
		s3.add(s2.data[i]);
	return s3;
	// TODO: 在此处插入 return 语句
}

template<class T>
Set<T>& Set<T>::Inter(Set& s2)
{
	static Set s3;
	for (int i = 0; i < s2.length; i++)
		if (IsIn(s2.data[i]))
			s3.add(s2.data[i]);
	return s3;
	// TODO: 在此处插入 return 语句
}

template<class T>
Set<T>& Set<T>::Differ(Set& s2)
{
	static Set s3;
	for (int i = 0; i < length; i++)
		if (!s2.IsIn(data[i]))
			s3.add(data[i]);
	return s3;
	// TODO: 在此处插入 return 语句
}

template<class T>
T& Set<T>::operator[](int n)
{
	if (n >= 0 && n < length)
		return data[n];
	// TODO: 在此处插入 return 语句
}

template<class T>
Set<T>::operator T* ()
{
	return data;
}

void DifferNum(string filename)
{
	Set<int> s;
	fstream fin(filename);
	streambuf* oldcin = cin.rdbuf(fin.rdbuf());
	int val;
	char c;
	while ((c = fin.get()) != EOF)
	{
		cin >> val;
		s.add(val);
	}
	cout << "不同整数的个数为" << s.getlength() << endl;
}



int main0()
{
	/*Set<int> s;
	for(int i=1;i<=199;i++)
	s.add(i);
	s.deletem(99);
	s.add(1010);
	s.add(200);
	s.add(101);
	cout<<s.get(98);*/
	Set<int> s1, s2;
	s1.add(1);
	s1.add(4);
	s1.add(2);
	s1.add(6);
	s1.add(8);
	cout << "集合s1:"; s1.printall();
	cout << "s1的长度是" << s1.getlength()<<endl;
	s2.add(2);
	s2.add(5);
	s2.add(3);
	s2.add(6);
	cout << "集合s2:"; s2.printall();
	cout << "s2的长度是" << s2.getlength()<<endl;
	cout << "s1 s2的并集：";
	Set<int>& s3 = s1.Union(s2);
	s3.printall();
	cout << "s1 s2的交集：";
	Set<int>& s4 = s1.Inter(s2);
	s4.printall();
	cout << "s1 s2的差集：";
//i然后加入果壳

	Set<int>& s5 = s1.Differ(s2);
	s5.printall();
	cout << s5[2] << endl;

	return 0;


}

int main()
{
	//main0();
	DifferNum("in.txt");
}
