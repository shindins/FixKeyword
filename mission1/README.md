# ����! �˻��� ���� ����  

## ������  
1. ����ð� 17:30  
2. 45�� ���� 15�� �޽�  
3. ���ɽð� 11:30 ~ 12:30  
4. ��ȭ�� ������ �ۿ���  
5. ���ͳ� �˻� ����  
6. �޽Ľð� �� ������ �ۿ����� ��ȭ ����  


## ��������  
1. �򰡽ð����� ������ ������ ��ȭ �Ǵ� ��ȭ��ȭ  
2. �޽��� / �系�Խ��� ���  
3. GPT �� ������ AI ���  
4. �����Կ� �� �� ���� ����  
5. Ÿ���� �ҽ��ڵ�� ����  


## ���  
���� �Ϸ�Ǹ� **�޽Ľð�** �� ��� ����  


## ���� ���  
���� �������丮�� ����꿡 ������ ��, ������ ���� �����մϴ�.  


`mission1/` �������� �޼��� ���� �����丵 �ڵ带 �����մϴ�.  
`mission2/` �������� Ŭ���� ���� �����丵 �ڵ带 �����մϴ�.  


`README.md` ���� ���� ������ �ۼ����ֽʽÿ�.  
1. D1 ~ D5 ���� ���� ���� üũ����Ʈ  
��ũ�ٿ�� ���̺� ������ �ƽŴٸ� ���ø� �Ǳ���, �𸣽Ŵٸ� �����ϰ� �����ּŵ� �����մϴ�.  
1. Code Coverage ���� ������� ĸ��ȭ��  
ĸ��ȭ���� �̹��������̱� ������, `result.jpg` ���� �������� ÷���� �ø��ø� �˴ϴ�.  


D1 ~ D5 ���� üũ����Ʈ�� üũ�� �� �׸���, ä���ڰ� �������� ���� ������ ���ϵ��� �ϰڽ��ϴ�.  
���� üũ�� �� �� �׸��� ����ó���ϰڽ��ϴ�.  
ĸ�� ȭ���� ���°��� ����ó���մϴ�.  


## �ҽ��ڵ� ����  

```cpp
struct Node {
    string w;
    string wk;
};

struct Node2 {
    string name;
    int point;

    bool operator<(const Node2& other) const {
        return point < other.point;
    }
};
```

�ʿ��� ����ü�� ��õǾ� �ֽ��ϴ�. Node2 �� ���, ���� ������ �Ǵ� �Լ��� �����صξ��µ�, ����ü ���͸� �����ϴ� ������ �˴ϴ�.  


```cpp
vector<Node2> weekBest[7]; //�� ~ ��
vector<Node2> twoBest[2]; //����, �ָ�
int UZ = 9;
```

�ʿ��� �������� ����Դϴ�. `weekBest` ���� �� - �� �� �ƴ϶� ��� �� - �� �Դϴ�. `twoBest` �� ����/�ָ��� ��Ÿ���ϴ�.  
���� ������ ����� ������ ������ ������, 10�� �Ѿ�� �� ���� ��Ҹ� ��ü������ �����մϴ�.  
�� �� ���� ���ʹ� point ������ �׻� ���ĵ� ���·� �����ϰڽ��ϴ�.  


`UZ` �� �⺻ �����̸�, ���ο� Ű���尡 �þ������ �ϳ��� �����ϸ�, 10������ �����մϴ�.
���� 21�￡ �����ϸ� int �� �ִ� ���̱� ������ ���� �������� �̷� ���Դϴ�.  


����, `main` �Լ����� ���캸�ڽ��ϴ�.  

```cpp
void input() {
	ifstream fin{ "keyword_weekday_500.txt" }; //500�� ������ �Է�
	for (int i = 0; i < 500; i++) {
		string t1, t2;
		fin >> t1 >> t2;
		string ret = input2(t1, t2);
		std::cout << ret << "\n";
	}
}

int main() {
	input();

}
```

���Ͽ� ����� 500�� �����Ͱ� �Էµ˴ϴ�. ������ ����ø�,  

```
water monday
bread tuesday
potato tuesday
light saturday
shrimp tuesday
pepper monday
music thursday
...
```
���� ���� ���·� Ű����/���� ������ �ԷµǴ°��� ���� �� �ֽ��ϴ�.  

`input2` �Լ��� ��� ������ ������ ���캸�ڽ��ϴ�. �����丵 �ֿ� �򰡻��� �� �ϳ���, �� �Լ��� �м��� ��, ���ȭ�� �� �� �ִ°������Դϴ�.  

```cpp
string input2(string w, string wk) {
	UZ++;

	int index = 0;
	if (wk == "monday") index = 0;
	if (wk == "tuesday") index = 1;
	if (wk == "wednesday") index = 2;
	if (wk == "thursday") index = 3;
	if (wk == "friday") index = 4;
	if (wk == "saturday") index = 5;
	if (wk == "sunday") index = 6;

	//���� / �ָ�
	int index2 = 0;
	if (index >= 0 && index <= 4) index2 = 0;
	else index2 = 1;

	int point = UZ;
```
`UZ` �� ���ʿ� `9` �����Ƿ�, Ű���尡 �Էµ��ڸ��� `10` �� �� ���Դϴ�.  
� �������� ��Ÿ���� `index` ����, �׸��� �������� �ָ������� �Ǵ��ϴ� `index2` �� �ֽ��ϴ�.  
`UZ` �� `point` �� �޾�, �Ϻ� / ���� HIT �� �� �ƴ� ��쿡 ����/�ָ� ���Ϳ� �ش� Ű���带 �߰������� �Ǵ��ϴ� �뵵�� �� ���Դϴ�.  

```cpp
	//���� ��Ͽ� �����ϴ��� Ȯ��
	//�����Ǵ� Ű�����̸� ������ ����

	long long int max1 = 0;
	long long int max2 = 0;

	int flag = 0;
	for (Node2 &node : weekBest[index]) {
		if (node.name == w) {
			max1 = node.point + (node.point * 0.1);
			node.point += (node.point * 0.1);
			flag = 1;
			break;
		}
	}

	for (Node2 &node : twoBest[index2]) {
		if (node.name == w) {
			max2 = node.point + (node.point * 0.1);
			node.point += (node.point * 0.1);
			break;
		}
	}
```

�Ϻ� HIT �� ����Դϴ�. ����, �����Ϻ��� �Ͽ��ϱ����� Ű���带 �����ϴ� `weekBest` �߿��� ��Ȯ�ϰ� ��ġ�ϴ� �˻�� �ִ��� Ȯ���մϴ�.  
�� ����, ���� / �ָ��� �ǹ��ϴ� `twoBest` �߿��� �Ϻ� HIT �� �ִ����� �˻��մϴ�.
�Ϻ� HIT �� ���, ���� �������� 10% �����˴ϴ�.  

```cpp
	//������ �۾�
	if (UZ >= 2100000000 || max1 >= 2100000000 || max2 >= 2100000000) {
		UZ = 9;
		for (int i = 0; i < 5; i++) {
			int num = 1;
			for (Node2& node : weekBest[i]) {
				node.point = num;
				num++;
			}
		}	
		for (int i = 0; i < 2; i++) {
			int num = 1;
			for (Node2& node : twoBest[i]) {
				node.point = num;
				num++;
			}
		}
	}
```
`UZ` �� 21���� �Ѱų�, �Ϻ� HIT �� ���� ���� �����ͼ¿��� 21���� �Ѵ� ��Ȳ�� �߻��� �� �ֽ��ϴ�.  
�� ���, `UZ` �� �ٽ� `9` �� �ʱ�ȭ�ϰ�, ���� ���ĵ� �����ͼ¿��� ���� �αⰡ ���� Ű������� `1` ���� ������ ������ �ο��մϴ�.  

```cpp
	if (flag == 1) {
		return w;
	}
```

�Ϻ� HIT ���� ������ �߰ߵ� ���, `flag` �� �ö󰡸�, �ش� Ű���带 ��ȯ�մϴ�.  


```cpp
	//���� HIT
	for (Node2& node : weekBest[index]) {
		if (similer(node.name, w)) {
			return node.name;
		}
	}
	
	for (Node2& node : twoBest[index]) {
		if (similer(node.name, w)) {
			return node.name;
		}
	}
```
���� HIT �� ���, ���絵 �˻縦 �����մϴ�.  

���Ͱ� �׻� ���ĵ� ���·� �����Ǳ� ������, ������ ���� �ͺ��� ���� �˻��� ���Դϴ�.  

`similar` �Լ��� ���캸�ڽ��ϴ�.  


```cpp
// ������Ÿ�� �Ÿ� ��� �˰��� (���ڿ� ���絵 �˻�)
int levenshtein(const std::string& a, const std::string& b) {
	const size_t len_a = a.size();
	const size_t len_b = b.size();

	std::vector<std::vector<int>> d(len_a + 1, std::vector<int>(len_b + 1));

	for (size_t i = 0; i <= len_a; ++i) d[i][0] = i;
	for (size_t j = 0; j <= len_b; ++j) d[0][j] = j;

	for (size_t i = 1; i <= len_a; ++i) {
		for (size_t j = 1; j <= len_b; ++j) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = 1 + std::min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
		}
	}
	return d[len_a][len_b];
}

bool similer(const std::string& a, const std::string& b) {
	if (a.empty() && b.empty()) return 100;
	if (a.empty() || b.empty()) return 1;

	int dist = levenshtein(a, b);
	int max_len = std::max(a.length(), b.length());
	// ���絵 ���� (1.0: ������ ����, 0.0: ���� �ٸ�)
	double similarity = 1.0 - (double)dist / max_len;
	
	int score = 1 + static_cast<int>(similarity * 99);
	
	if (score >= 80) return true;
	return false;
}
```

���� HIT ���� ���̴� `similer` �Լ������� ������Ÿ�� �˰����� ����� ���ڿ� ���絵�� �˻��մϴ�.  

�� ���� ���ڿ��� ���� ��, ���絵�� 80% �̻����� ���Ͽ� boolean �����ϴ°��� �ٽ��Դϴ�.  

�����丵 �� �䱸���� �� �ϳ���, ��õ �˰����� ����Ǿ��� ���� ���� �ڵ带 ������ �� �ִ����Դϴ�. �� �κ��� �Ű���ֽñ� �ٶ��ϴ�.  

```cpp
	//�Ϻ� HIT / ���� HIT �Ѵ� �ƴѰ��
	if (weekBest[index].size() < 10) {
		weekBest[index].push_back({ w, point });
		std::sort(weekBest[index].begin(), weekBest[index].end());
	}	
	
	if (twoBest[index].size() < 10) {
		twoBest[index].push_back({ w, point });
		std::sort(twoBest[index].begin(), twoBest[index].end());
	}

	if (weekBest[index].size() == 10) {
		if (weekBest[index].back().point < point) {
			weekBest[index].pop_back();
			weekBest[index].push_back({ w, point });
			std::sort(weekBest[index].begin(), weekBest[index].end());
		}		
	}

	if (twoBest[index].size() == 10) {
		if (twoBest[index].back().point < point) {
			twoBest[index].pop_back();
			twoBest[index].push_back({ w, point });
			std::sort(twoBest[index].begin(), twoBest[index].end());
		}		
	}

	return w;
}
```

����������, �Ϻ� HIT / ���� HIT �� �� �ƴ� ����Դϴ�.  
�� ���, ���� ������ ����� ���� ��Ȳ�� �ٸ��ϴ�.  
1. 10 �� ������ ���, ���ο� Ű���带 �߰��մϴ�.  
2. 10 �� �̻��� ���, ���� ���� ����Ʈ�� Ű����� ���� ���ο� Ű������ ����Ʈ�� ���ٸ�, ���ο� Ű����� ��ü�մϴ�.  
���ο� Ű����� ������ ���, point �� ���ĵ�ä�� �����Ǿ�� �ϱ� ������, sort �� �ݵ�� ���־�� �մϴ�.  
