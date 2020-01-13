/*62048번 멀쩡한 사각형

대각선이 지나는 사각형의 갯수 = (가로 + 세로 - 최대공약수)

*/

#include <iostream>
using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

long long solution(int w,int h)
{
	long long answer = (long long)w*(long long)h;
    long long gcd_num = gcd(w,h);
    answer -= (w + h - gcd_num);
	return answer;
}


int main(){
    cout << solution(8, 12)<<"\n";
    return 0;
}