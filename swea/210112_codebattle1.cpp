
#include <iostream>

using namespace std;

int n, cnt;
bool flag;
int map[20][20];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void check(int x, int y, int dir){

    if(cnt >= 4){
        flag = true;
        return;
    }
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];

    if(nx < 0 || nx>= n || ny < 0 || ny >= n || map[nx][ny]==0){
        cnt = 0;
        return;
    }
    else {
        cnt++;
        check(nx, ny, dir);
    }
}

int main(){
    int Tc;
    cin >> Tc;

    for(int T=1; T<=Tc; T++){
        cin >> n;
        for(int i=0; i<n; i++){
            string str;
            cin >> str;
            for(int j=0; j<n; j++){
                if(str[j] == '.'){
                    map[i][j] = 0;
                } else{
                    map[i][j] = 1;
                }
            }
        }

        flag = false;
        cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 1){
                    for(int k=0; k<8; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx <0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 0) continue;
                        else{
                            cnt++;
                            check(nx, ny, k);
                        }
                    }
                    if(cnt >= 4){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }

        string ans = flag ? "YES" : "NO";

        cout << "#" << T <<" "<<ans<<"\n";
    }
}