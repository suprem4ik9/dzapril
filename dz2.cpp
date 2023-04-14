#include <fstream>

#include <vector>

#include <algorithm>

#include <cmath>



using namespace std;



ifstream in("input.txt");

ofstream out("output.txt");



struct rocket {

    int n;     

    long long t;  

    long long v;  

};



bool comp(const rocket& a, const rocket& b) {

    return a.t < b.t;

}



int main() {

    long long t, v;

    vector <rocket> r(4);

    long long mn = 1;        

    for (int z = 0; z < 4; z++) { 

        in >> t >> v;

        r[z].n = z;

        r[z].t = t;

        r[z].v = v;

        mn *= v;

    }

    long long dt, d; 

    in >> dt >> d;

    for (int z = 0; z < 4; z++) { 

        r[z].t = r[z].t * mn + d * mn / r[z].v;

    }

    dt *= mn;        

    sort(r.begin(), r.end(), comp); 

    for (int z = 1; z < 3; z++)     

        if (r[z].t == r[z + 1].t)   

            if (abs(r[z - 1].n - r[z].n) == 2) swap(r[z], r[z + 1]);

    int count = 1;   

    int z = 1;

    while (z < 4) { 

        if (r[z - 1].t + dt * (abs(r[z].n - r[z - 1].n) % 2 == 0 ? 2 : 1) <= r[z].t) {

            count++;

            z++;

        }

        else break;

    }

    if (count < 4) out << count;

    else out << "ALIVE";

    return 0;

}
