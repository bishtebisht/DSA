//pair
#include<bits/stdc++.h>
using namespace std;

int main(){
    // pair<int, string> p;
    // p.first = 1;
    // p.second = "hello";
    // cout << p.first << " " << p.second << endl;

    // pair<int, int> p1 = {2, 3};
    // cout << p1.first << " " << p1.second << endl;

    // //pair of pairs
    // pair<int, pair<string, int>> pp;
    // pp.first = 2;
    // pp.second.first = "world";
    // pp.second.second = 3;
    // cout << pp.first << " " << pp.second.first << " " << pp.second.second << endl;

    // pair<int,pair<string,string>> pp1 = {3, {"hello", "world"}};
    // cout << pp1.first << " " << pp1.second.first << " " << pp1.second.second << endl;

    // //array of pairs
    // pair<int, string> arr[3];
    // arr[0] = {1, "one"};
    // arr[1] = {2, "two"};
    // arr[2] = {3, "three"};
    // for(int i=0; i<3; i++) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    // pair<int, int> p1 = {5, 4};
    // pair<int, int> p2 = {10, 4};
    // if(p1.first == p2.first) {
    //     cout << "first elements are equal" << endl;
    // } else if(p1.first > p2.first) {
    //     cout <<p1.first<< " is greater than " << p2.first << endl;
    // } else {
    //     cout << p2.first << " is greater than " << p1.first << endl;
    // }

    // if(p1.second == p2.second) {
    //     cout << "second elements are equal" << endl;
    // } else if(p1.second > p2.second) {
    //     cout <<p1.second<< " is greater than " << p2.second << endl;
    // } else {
    //     cout << p2.second << " is greater than " << p1.second << endl;
    // }

    //sorting pairs
    pair<int,int>p1={1,2};
    pair<int,int>p2={4,7};
    pair<int,int>p3={1,5};
    pair<int,int>p4={4,2};

    vector<pair<int,int>> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //sort the vector of pairs
    for(int i=0; i<v.size()-1; i++) {
        if(v[i].first <=v[i+1].first) {
            if(v[i].first == v[i+1].first) {
                if(v[i].second <= v[i+1].second) {
                    continue;
                } else {
                    swap(v[i], v[i+1]);
                }
            } else {
                continue;
            }
        } else {
            swap(v[i], v[i+1]);
        }
    }

    for(int i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

}