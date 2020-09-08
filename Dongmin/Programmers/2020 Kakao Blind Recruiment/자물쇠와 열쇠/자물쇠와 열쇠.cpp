#include <string>
#include <vector>

using namespace std;
vector<vector<int> > map;
int m,n;
void rotateKey(vector<vector<int> >& key) {
    vector<vector<int> > tmp = key;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            key[i][j] = tmp[m-1-j][i];
        }
    }
}
bool check() {
    bool ret = true;
    for(int i=m-1; i<m+n-1; i++) {
        for(int j=m-1; j<m+n-1; j++) {
            if(map[i][j] == 0 || map[i][j] ==2) {
                ret = false;
                break;
            }        
        }
    }
    return ret;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    m=key.size(), n=lock.size();
    int map_size = 2*m+n-2;
    map.assign(map_size, vector<int>(map_size, -1));
    
    for(int i=m-1; i<m+n-1; i++) {
        for(int j=m-1; j<m+n-1; j++) {
            map[i][j] = lock[i-m+1][j-m+1];
        }
    }
    
    for(int i=0; i<m+n-1; i++) {
        for(int j=0; j<m+n-1; j++) {
            for(int k=0; k<4; k++) {
                rotateKey(key);
                for(int u=i; u<i+m; u++) {
                    for(int v=j; v<j+m; v++) {
                        map[u][v] += key[u-i][v-j];
                    }
                }
                if(check()) {
                    return true;
                }
                for(int u=i; u<i+m; u++) {
                    for(int v=j; v<j+m; v++) {
                        map[u][v] -= key[u-i][v-j];
                    }
                }
            }
        }
    }
    return answer;
}