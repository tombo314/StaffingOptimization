#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i=a; i<b; i++)
#define rrep(i, a, b) for (ll i=a; i>b; i--)
#define vrep(x, v) for (auto x: v)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.begin(), v.end(), greater<ll>())
#define copy(v1, v2) copy(v1.begin(), v1.end(), v2.begin())
#define vmax(v) *max_element(v.begin(), v.end())
#define vmin(v) *min_element (v.begin(), v.end())
#define vsum(v) accumulate(v.begin(), v.end(), ll(0))
#define rev(v) reverse(v.begin(), v.end())
#define vconcat(v1, v2) v1.insert(v1.end(), v2.begin(), v2.end())
#define now() chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count()
#define choice(in, out, n) sample(in.begin(), in.end(), back_inserter(out), n, mt)
#define bpq(v, T) priority_queue<T> v
#define spq(v, T) priority_queue<T, vector<T>, greater<T>> v
#define pb push_back
#define inf 1e18

mt19937 mt(now());
ll rand(ll n) { return mt()%n; }

double calc(vector<ll> v){
    double cost = 0;
    return cost;
}

vector<ll> next_state(vector<ll> v){
    return {};
}

double prob(ll new_score, ll pre_score, double temp){
    double e = 2.7;
    double p = pow(e, (new_score-pre_score)/temp);
    return p;
}

int main(){
    vector<ll> state;
    double score = calc(state);
    double temp = 1000;
    double ans = 0;
    const ll max_iter = 3e6;

    ll iter = 0;
    while(iter<=max_iter){
        iter++;

        vector<ll> next = next_state(state);
        double new_score = calc(next);
        ans = max(ans, new_score);
        double p = prob(new_score, score, temp)*100;

        if (p>rand(100)){
            state = next;
            score = new_score;
        }

        temp *= 0.999999;
        // debug
        if (iter%ll(1e6)==0){
            cerr << temp << endl;
        }
    }
}