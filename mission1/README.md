# 찰떡! 검색어 교정 서비스  

## 평가일정  
1. 종료시간 17:30  
2. 45분 진행 15분 휴식  
3. 점심시간 11:30 ~ 12:30  
4. 전화는 강의장 밖에서  
5. 인터넷 검색 가능  
6. 휴식시간 내 강의장 밖에서만 대화 가능  


## 부정행위  
1. 평가시간동안 강의장 내에서 대화 또는 전화통화  
2. 메신저 / 사내게시판 사용  
3. GPT 등 생성형 AI 사용  
4. 사진촬영 및 평가 문제 유출  
5. 타인의 소스코드와 유사  


## 퇴실  
과제 완료되면 **휴식시간** 에 퇴실 가능  


## 제출 방법  
개인 리포지토리를 깃허브에 생성한 후, 다음과 같이 제출합니다.  


`mission1/` 폴더에는 메서드 레벨 리팩토링 코드를 포함합니다.  
`mission2/` 폴더에는 클래스 레벨 리팩토링 코드를 포함합니다.  


`README.md` 에는 다음 사항을 작성해주십시오.  
1. D1 ~ D5 까지 적용 여부 체크리스트  
마크다운에서 테이블 문법을 아신다면 쓰시면 되구요, 모르신다면 간단하게 적어주셔도 무방합니다.  
1. Code Coverage 최종 측정결과 캡쳐화면  
캡쳐화면은 이미지파일이기 때문에, `result.jpg` 등의 형식으로 첨부해 올리시면 됩니다.  


D1 ~ D5 까지 체크리스트에 체크가 된 항목은, 채점자가 수동으로 진행 수준을 평가하도록 하겠습니다.  
만약 체크가 안 된 항목은 오답처리하겠습니다.  
캡쳐 화면이 없는경우는 오답처리합니다.  


## 소스코드 설명  

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

필요한 구조체가 명시되어 있습니다. Node2 의 경우, 정렬 기준이 되는 함수를 정의해두었는데, 구조체 벡터를 정렬하는 기준이 됩니다.  


```cpp
vector<Node2> weekBest[7]; //월 ~ 일
vector<Node2> twoBest[2]; //평일, 주말
int UZ = 9;
```

필요한 전역변수 목록입니다. `weekBest` 에선 월 - 금 이 아니라 사실 월 - 일 입니다. `twoBest` 는 주중/주말을 나타냅니다.  
벡터 각각의 요소의 사이즈 제한은 없지만, 10이 넘어갔을 때 기존 요소를 대체할지를 결정합니다.  
위 두 개의 벡터는 point 순으로 항상 정렬된 상태로 유지하겠습니다.  


`UZ` 는 기본 점수이며, 새로운 키워드가 늘어날때마다 하나씩 증가하며, 10점부터 시작합니다.
만약 21억에 도달하면 int 의 최대 값이기 때문에 점수 재정렬을 이룰 것입니다.  


먼저, `main` 함수부터 살펴보겠습니다.  

```cpp
void input() {
	ifstream fin{ "keyword_weekday_500.txt" }; //500개 데이터 입력
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

파일에 저장된 500개 데이터가 입력됩니다. 파일을 열어보시면,  

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
위와 같은 형태로 키워드/요일 순서로 입력되는것을 보실 수 있습니다.  

`input2` 함수는 길기 때문에 나눠서 살펴보겠습니다. 리팩토링 주요 평가사항 중 하나가, 이 함수를 분석한 후, 모듈화를 할 수 있는것인지입니다.  

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

	//평일 / 주말
	int index2 = 0;
	if (index >= 0 && index <= 4) index2 = 0;
	else index2 = 1;

	int point = UZ;
```
`UZ` 는 최초에 `9` 였으므로, 키워드가 입력되자마자 `10` 이 될 것입니다.  
어떤 요일인지 나타내는 `index` 변수, 그리고 주중인지 주말인지를 판단하는 `index2` 가 있습니다.  
`UZ` 를 `point` 로 받아, 완벽 / 찰떡 HIT 둘 다 아닌 경우에 주중/주말 벡터에 해당 키워드를 추가할지를 판단하는 용도로 쓸 것입니다.  

```cpp
	//관리 목록에 존재하는지 확인
	//관리되는 키워드이면 점수가 증가

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

완벽 HIT 의 경우입니다. 먼저, 월요일부터 일요일까지의 키워드를 저장하는 `weekBest` 중에서 정확하게 일치하는 검색어가 있는지 확인합니다.  
그 다음, 주중 / 주말을 의미하는 `twoBest` 중에서 완벽 HIT 가 있는지를 검사합니다.
완벽 HIT 의 경우, 기존 점수에서 10% 증가됩니다.  

```cpp
	//재정렬 작업
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
`UZ` 가 21억이 넘거나, 완벽 HIT 로 인해 기존 데이터셋에서 21억이 넘는 상황이 발생할 수 있습니다.  
이 경우, `UZ` 는 다시 `9` 로 초기화하고, 기존 정렬된 데이터셋에서 가장 인기가 없는 키워드부터 `1` 부터 시작해 점수를 부여합니다.  

```cpp
	if (flag == 1) {
		return w;
	}
```

완벽 HIT 에서 정답이 발견된 경우, `flag` 가 올라가며, 해당 키워드를 반환합니다.  


```cpp
	//찰떡 HIT
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
찰떡 HIT 의 경우, 유사도 검사를 시행합니다.  

벡터가 항상 정렬된 상태로 유지되기 때문에, 점수가 높은 것부터 먼저 검사할 것입니다.  

`similar` 함수를 살펴보겠습니다.  


```cpp
// 레벤슈타인 거리 계산 알고리즘 (문자열 유사도 검사)
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
	// 유사도 비율 (1.0: 완전히 같음, 0.0: 전혀 다름)
	double similarity = 1.0 - (double)dist / max_len;
	
	int score = 1 + static_cast<int>(similarity * 99);
	
	if (score >= 80) return true;
	return false;
}
```

찰떡 HIT 에서 쓰이는 `similer` 함수에서는 레벤슈타인 알고리즘을 사용해 문자열 유사도를 검사합니다.  

두 개의 문자열을 받은 후, 유사도가 80% 이상인지 비교하여 boolean 리턴하는것이 핵심입니다.  

리팩토링 평가 요구사항 중 하나가, 추천 알고리즘이 변경되었을 때도 기존 코드를 유지할 수 있는지입니다. 이 부분을 신경써주시기 바랍니다.  

```cpp
	//완벽 HIT / 찰떡 HIT 둘다 아닌경우
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

마지막으로, 완벽 HIT / 찰떡 HIT 둘 다 아닌 경우입니다.  
이 경우, 기존 벡터의 사이즈에 따라 상황이 다릅니다.  
1. 10 개 이하일 경우, 새로운 키워드를 추가합니다.  
2. 10 개 이상일 경우, 가장 낮은 포인트의 키워드와 비교해 새로운 키워드의 포인트가 높다면, 새로운 키워드로 대체합니다.  
새로운 키워드로 갱신할 경우, point 가 정렬된채로 유지되어야 하기 때문에, sort 를 반드시 해주어야 합니다.  
