#include <bits/stdc++.h>

using namespace std;

vector<int>* splice(vector<int>, vector<int>, int, int, int);

// Inserindo um vetor dentro de outro vetor
int main()  {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7};
    int len1 = v1.size();
    int len2 = v2.size();
    int pos = 2;

    vector<int>* v = splice(v1, v2, len1, len2, pos);
    for(int l : *v) {
        cout << l << "\n";
    }

    return 0;
}

vector<int>* splice(vector<int> v1, vector<int> v2, int len1, int len2, int pos) {
    if(pos < 0 || pos > len1) {
        return NULL;
    }
    vector<int>* vf = new vector<int>((len1+len2));

    for(int i = 0; i < pos; i++) {
        (*vf)[i] = v1[i];
    }
    for(int j = 0; j < len2; j++) {
        (*vf)[j+pos] = v2[j];
    }
    for(int m = pos; m < len1; m++) {
        (*vf)[len2+m] = v1[m];
    }
    return vf;
}
