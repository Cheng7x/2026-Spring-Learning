#include <iostream>
#include <cstring>
using namespace std;

class SeqString {
private:
	char* data;
	int len;
	int capacity;
	
	// 自动扩容
	void ensureCapacity(int newLen) {
		// 长度 < 容量 不用扩容
		if (newLen <= capacity) return;
		// 新容量扩大到旧容量 2^n 倍
		int newCap = capacity;
		while (newCap < newLen) newCap *= 2;
		// 新数据存在新容量里
		char* newData = new char[newCap + 1];
		// 旧数据迁移
		for (int i = 0; i < len; ++i) newData[i] = data[i];
		// 结尾符
		newData[len] = '\0';
		// 释放掉旧 data
		delete[] data;
		data = newData;
		capacity = newCap;
	}
	
public:
	// 默认构造
	SeqString(int cap = 16) {
		capacity = cap;
		len = 0;
		data = new char[capacity + 1];
		data[0] = '\0';
	}
	
	// 用 C 风格字符串构造
	SeqString(const char* str) {
		if (str == nullptr) {
			capacity = 16;
			len = 0;
			data = new char[capacity + 1];
			data[0] = '\0';
		} else {
			len = strlen(str);
			capacity = (len > 16 ? len : 16);
			data = new char[capacity + 1];
			strcpy(data, str);
		}
	}
	
	// 拷贝构造
	SeqString(const SeqString& other) {
		len = other.len;
		capacity = other.capacity;
		data = new char[capacity + 1];
		strcpy(data, other.data);
	}
	
	// 赋值运算符
	SeqString& operator=(const SeqString& other) {
		if (this == &other) return *this;
		delete[] data;
		len = other.len;
		capacity = other.capacity;
		data = new char[capacity + 1];
		strcpy(data, other.data);
		return *this;
	}
	
	// 析构
	~SeqString() {
		delete[] data;
	}
	
	int length() const {
		return len;
	}
	
	bool empty() const {
		return len == 0;
	}
	
	const char* c_str() const {
		return data;
	}
	
	char& operator[](int index) {
		return data[index];
	}
	
	const char& operator[](int index) const {
		return data[index];
	}
	
	// 插入：pos 从 1 开始
	bool insert(int pos, const SeqString& t) {
		if (pos < 1 || pos > len + 1) return false;
		
		ensureCapacity(len + t.len);
		
		int idx = pos - 1;
		
		// 后移
		for (int i = len - 1; i >= idx; --i) {
			data[i + t.len] = data[i];
		}
		
		// 插入
		for (int i = 0; i < t.len; ++i) {
			data[idx + i] = t.data[i];
		}
		
		len += t.len;
		data[len] = '\0';
		return true;
	}
	
	// 删除：pos 从 1 开始，删除 lenToErase 个字符
	bool erase(int pos, int lenToErase) {
		if (pos < 1 || pos > len || lenToErase < 0) return false;
		if (lenToErase == 0) return true;
		
		int idx = pos - 1;
		
		if (idx + lenToErase >= len) {
			len = idx;
		} else {
			for (int i = idx + lenToErase; i < len; ++i) {
				data[i - lenToErase] = data[i];
			}
			len -= lenToErase;
		}
		
		data[len] = '\0';
		return true;
	}
	
	// 子串：pos 从 1 开始
	SeqString substr(int pos, int subLen) const {
		SeqString sub;
		if (pos < 1 || pos > len || subLen <= 0) return sub;
		
		int idx = pos - 1;
		int realLen = 0;
		while (idx + realLen < len && realLen < subLen) {
			realLen++;
		}
		
		sub.ensureCapacity(realLen);
		for (int i = 0; i < realLen; ++i) {
			sub.data[i] = data[idx + i];
		}
		sub.len = realLen;
		sub.data[sub.len] = '\0';
		return sub;
	}
	
	// 比较：大于返回 1，等于返回 0，小于返回 -1
	int compare(const SeqString& other) const {
		int minLen = (len < other.len ? len : other.len);
		int i = 0;
		while (i < minLen && data[i] == other.data[i]) {
			i++;
		}
		
		if (i == minLen) {
			if (len > other.len) return 1;
			if (len < other.len) return -1;
			return 0;
		}
		
		return (data[i] > other.data[i]) ? 1 : -1;
	}
	
	// 朴素模式匹配 BF：返回首次出现的位置（1-based），找不到返回 0
	int find(const SeqString& pattern) const {
		if (pattern.len == 0) return 1;
		if (pattern.len > len) return 0;
		
		for (int p = 0; p <= len - pattern.len; ++p) {
			int i = 0;
			while (i < pattern.len && data[p + i] == pattern.data[i]) {
				i++;
			}
			if (i == pattern.len) {
				return p + 1;  // 返回 1-based 位置
			}
		}
		
		return 0;
	}
	
	friend ostream& operator<<(ostream& os, const SeqString& s) {
		os << s.data;
		return os;
	}
};

int main() {
	SeqString s("abcdef");
	SeqString t("XYZ");
	
	cout << "原串 s: " << s << endl;
	
	s.insert(3, t);
	cout << "insert(3, \"XYZ\") 后: " << s << endl;
	
	s.erase(2, 4);
	cout << "erase(2, 4) 后: " << s << endl;
	
	SeqString sub = s.substr(2, 3);
	cout << "substr(2, 3): " << sub << endl;
	
	SeqString a("abc");
	SeqString b("abd");
	cout << "compare(\"abc\", \"abd\") = " << a.compare(b) << endl;
	
	SeqString text("ababcabcacbab");
	SeqString pattern("abcac");
	cout << "find(\"abcac\") = " << text.find(pattern) << endl;
	
	return 0;
}

