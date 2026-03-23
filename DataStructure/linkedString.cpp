#include <iostream>
using namespace std;

class LinkedString {
private:
	// 链表结点：每个结点存放一个字符
	struct Node {
		char ch;      // 当前字符
		Node* next;   // 指向下一个结点
		
		// 结点构造函数
		Node(char c = '\0', Node* n = nullptr) : ch(c), next(n) {}
	};
	
	Node* head;   // 头指针，指向字符串的第一个字符结点
	int len;      // 字符串长度
	
	// 清空当前链表
	// 用于析构函数、赋值运算符等场景
	void clear() {
		Node* p = head;
		
		// 逐个释放结点
		while (p != nullptr) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
		
		head = nullptr;
		len = 0;
	}
	
	// 从另一个 LinkedString 深拷贝
	// 作用：给当前对象重新构造一条完全独立的新链表
	void copyFrom(const LinkedString& other) {
		// 如果对方是空串
		if (other.head == nullptr) {
			head = nullptr;
			len = 0;
			return;
		}
		
		// 先复制第一个结点
		head = new Node(other.head->ch);
		Node* p = head;              // p 用来在新链表尾部追加
		Node* q = other.head->next;  // q 用来遍历原链表
		
		// 继续复制剩余结点
		while (q != nullptr) {
			p->next = new Node(q->ch);
			p = p->next;
			q = q->next;
		}
		
		len = other.len;
	}
	
public:
	// =========================
	// 1. 默认构造函数
	// 创建一个空字符串
	// =========================
	LinkedString() : head(nullptr), len(0) {}
	
	// =========================
	// 2. 用 C 风格字符串构造
	// 例如：LinkedString s("hello");
	// =========================
	LinkedString(const char* str) : head(nullptr), len(0) {
		if (str == nullptr) return;
		
		Node* tail = nullptr; // 尾指针，方便尾插构造链表
		
		// 逐字符读入，直到遇到 '\0'
		for (int i = 0; str[i] != '\0'; ++i) {
			Node* node = new Node(str[i]);
			
			// 如果是第一个结点
			if (head == nullptr) {
				head = tail = node;
			} else {
				// 否则尾插
				tail->next = node;
				tail = node;
			}
			
			len++;
		}
	}
	
	// =========================
	// 3. 拷贝构造函数
	// 用一个已有对象初始化一个新对象
	// 例如：LinkedString b = a;
	// =========================
	LinkedString(const LinkedString& other) {
		copyFrom(other);
	}
	
	// =========================
	// 4. 赋值运算符重载
	// 用于已经存在的对象之间赋值
	// 例如：b = a;
	// =========================
	LinkedString& operator=(const LinkedString& other) {
		// 防止自赋值，例如 a = a;
		if (this == &other) return *this;
		
		// 先清掉当前对象原有链表
		clear();
		
		// 再深拷贝对方内容
		copyFrom(other);
		
		return *this;
	}
	
	// =========================
	// 5. 析构函数
	// 对象生命周期结束时自动调用
	// =========================
	~LinkedString() {
		clear();
	}
	
	// 返回字符串长度
	int length() const {
		return len;
	}
	
	// 判断是否为空串
	bool empty() const {
		return len == 0;
	}
	
	// =========================
	// 插入操作
	// 在第 pos 个位置插入字符串 t
	// 位置从 1 开始
	// 例如：abcdef，在 3 位置插入 XYZ -> abXYZcdef
	// =========================
	bool insert(int pos, const LinkedString& t) {
		// 合法位置：1 ~ len+1
		if (pos < 1 || pos > len + 1) return false;
		
		// 插入空串，直接成功
		if (t.len == 0) return true;
		
		// 不能直接把 t 的结点接过来
		// 否则两个对象会共享同一批结点，析构时会出错
		// 所以先拷贝一份独立链表
		LinkedString temp(t);
		
		// 找 temp 的尾结点，后面要接回原链表
		Node* tail = temp.head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		
		// 情况1：插在头部
		if (pos == 1) {
			tail->next = head;
			head = temp.head;
		} else {
			// 找到第 pos-1 个结点
			Node* p = head;
			int count = 1;
			
			while (p != nullptr && count < pos - 1) {
				p = p->next;
				count++;
			}
			
			if (p == nullptr) return false;
			
			// 连接：
			// 原来 p -> 后继
			// 现在变成 p -> temp.head -> ... -> tail -> 原后继
			tail->next = p->next;
			p->next = temp.head;
		}
		
		len += temp.len;
		
		// 这里非常关键：
		// 当前对象已经“接管”了 temp 这条链表
		// 所以必须把 temp 置空，否则 temp 析构时会把这些结点删掉
		temp.head = nullptr;
		temp.len = 0;
		
		return true;
	}
	
	// =========================
	// 删除操作
	// 从第 pos 个字符开始删除 delLen 个字符
	// 位置从 1 开始
	// =========================
	bool erase(int pos, int delLen) {
		if (pos < 1 || pos > len || delLen <= 0) return false;
		
		Node* deleted = nullptr;
		
		// 情况1：从头开始删
		if (pos == 1) {
			deleted = head;
			int count = 0;
			
			// 连续删除 delLen 个结点
			while (deleted != nullptr && count < delLen) {
				Node* temp = deleted;
				deleted = deleted->next;
				delete temp;
				count++;
				len--;
			}
			
			// 删除后新的头结点
			head = deleted;
		} else {
			// 先找到第 pos-1 个结点
			Node* p = head;
			int count = 1;
			
			while (p != nullptr && count < pos - 1) {
				p = p->next;
				count++;
			}
			
			// pos 位置不存在
			if (p == nullptr || p->next == nullptr) return false;
			
			// deleted 指向待删除的第一个结点
			deleted = p->next;
			count = 0;
			
			// 删除后续 delLen 个结点
			while (deleted != nullptr && count < delLen) {
				Node* temp = deleted;
				deleted = deleted->next;
				delete temp;
				count++;
				len--;
			}
			
			// 把前半段和后半段重新接起来
			p->next = deleted;
		}
		
		return true;
	}
	
	// =========================
	// 截取子串
	// 从第 pos 个字符开始，截取 subLen 个字符
	// 不足 subLen 个就截到末尾
	// =========================
	LinkedString substr(int pos, int subLen) const {
		LinkedString sub;
		
		if (pos < 1 || pos > len || subLen <= 0) return sub;
		
		// 找到第 pos 个结点
		Node* p = head;
		int count = 1;
		while (p != nullptr && count < pos) {
			p = p->next;
			count++;
		}
		
		if (p == nullptr) return sub;
		
		Node* tail = nullptr;
		count = 0;
		
		// 从 p 开始复制 subLen 个结点
		while (p != nullptr && count < subLen) {
			Node* node = new Node(p->ch);
			
			if (sub.head == nullptr) {
				sub.head = tail = node;
			} else {
				tail->next = node;
				tail = node;
			}
			
			sub.len++;
			p = p->next;
			count++;
		}
		
		return sub;
	}
	
	// =========================
	// 字符串比较
	// 返回：
	//  1  表示当前串 > other
	//  0  表示相等
	// -1 表示当前串 < other
	// =========================
	int compare(const LinkedString& other) const {
		Node* p = head;
		Node* q = other.head;
		
		// 逐字符比较，直到遇到不同字符或某一方结束
		while (p != nullptr && q != nullptr && p->ch == q->ch) {
			p = p->next;
			q = q->next;
		}
		
		// 两边都结束，说明完全相等
		if (p == nullptr && q == nullptr) return 0;
		
		// 当前串先结束，说明更短，且前面全相同
		if (p == nullptr) return -1;
		
		// other 先结束，说明当前串更长
		if (q == nullptr) return 1;
		
		// 出现第一个不同字符，按字符大小比较
		return (p->ch > q->ch) ? 1 : -1;
	}
	
	// =========================
	// 朴素模式匹配 BF
	// 返回模式串第一次出现的位置（1-based）
	// 找不到返回 0
	// =========================
	int find(const LinkedString& pattern) const {
		// 空模式串规定返回 1
		if (pattern.len == 0) return 1;
		
		// 模式串比主串还长，不可能匹配
		if (pattern.len > len) return 0;
		
		Node* start = head;
		
		// 从每个可能的起点开始尝试匹配
		for (int pos = 1; pos <= len - pattern.len + 1; ++pos) {
			Node* p = start;         // 主串当前比较位置
			Node* q = pattern.head;  // 模式串当前比较位置
			
			// 逐字符比较
			while (p != nullptr && q != nullptr && p->ch == q->ch) {
				p = p->next;
				q = q->next;
			}
			
			// 如果模式串走完了，说明匹配成功
			if (q == nullptr) return pos;
			
			// 起点后移一个结点，继续下一轮
			start = start->next;
		}
		
		return 0;
	}
	
	// 输出整个字符串
	friend ostream& operator<<(ostream& os, const LinkedString& s) {
		Node* p = s.head;
		while (p != nullptr) {
			os << p->ch;
			p = p->next;
		}
		return os;
	}
};

int main() {
	LinkedString s("abcdef");
	LinkedString t("XYZ");
	
	cout << "原串 s: " << s << endl;
	
	s.insert(3, t);
	cout << "insert(3, \"XYZ\") 后: " << s << endl;
	
	s.erase(2, 4);
	cout << "erase(2, 4) 后: " << s << endl;
	
	LinkedString sub = s.substr(2, 3);
	cout << "substr(2, 3): " << sub << endl;
	
	LinkedString a("abc");
	LinkedString b("abd");
	cout << "compare(\"abc\", \"abd\") = " << a.compare(b) << endl;
	
	LinkedString text("ababcabcacbab");
	LinkedString pattern("abcac");
	cout << "find(\"abcac\") = " << text.find(pattern) << endl;
	
	return 0;
}
void GetNext(char ch[], int length, int next[]){
	next[0] = -1;
	int i = 0, j = 0;
	while (i < length) {
		if (j == 0 || ch[i] == ch[j]) next[++i] = ++j;
		else j = next[j];
	}
}

