#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
const long long number = 1e9 + 7;
typedef long long LL;
long long tree[1010][1010];
int N, M;
LL lowbit(LL x)
{
    return x&(-x);
}
void update(LL x, LL y, LL value) {
	
	while(x<=N+1){
	   int y1 = y;
	   while(y1<=N+1){
	       tree[i][j] += value;
	       y1 += lowbit(y1);
	   }
	   x += lowbit(x);
	}
}
LL sum(LL x, LL y) {
	long long result = 0;
	for(int i=x;i>0;i-=lowbit(i)) {
		for(int j=y;j>0;j-=lowbit(j)) {
			result += tree[i][j]%number;
		}
	}
	return result%number;
}
int main()
{
	memset(tree, 0, sizeof(tree));
	LL x1, y1, x2, y2, value;
	cin >> N >> M;
	string str;
	for (int i = 0; i<M; i++) {
		cin >> str;
		//cout << str << endl;
		if (str == "Add") {
			cin >> x1 >> y1 >> value;
			x1 += 1;
			y1 += 1;
			update(x1, y1, value);
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2;
			x1 += 1; x2 += 1; y1 += 1; y2 += 1;
			LL result = sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);
			while(result<0) result+=number;
			cout << result << endl;
		}
	}
	//system("pause");
	return 0;
}
