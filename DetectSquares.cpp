#include<vector>
#include<map>
using namespace std;

class DetectSquares {
public:
    map<pair<int,int>,int> sq;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        sq[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0],y = point[1];
        for(auto& t: sq)
        {
            pair<int,int> p = t.first;
            if((x != p.first) && (y!=p.second) && (abs(p.first-x) == abs(p.second - y)))
            {
                int coord1 = sq[{p.first,p.second}];
                int coord2 = sq[{x,p.second}];
                int coord3 = sq[{p.first,y}];
                count += (coord1*coord2*coord3);
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */