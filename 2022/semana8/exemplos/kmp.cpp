// KMP - O(n + m)

// max size pattern
const int N = 1e5 + 5;

int lps[N], cnt;

void prekmp(string &p){
  for (int i = 1, j = 0; i < p.size(); i++) {
    while (j and p[j] != p[i]) j = lps[j-1];
    if (p[j] == p[i]) j++;
    lps[i] = j;
  }
}

void kmp(string &s, string &p) {
  for (int i = 0, j = 0; i < s.size(); i++) {
    while (j and p[j] != s[i]) j = lps[j-1];
    if (p[j] == s[i]) j++;
    if (j == p.size()) {
      // match i-j+1
      cnt++;
      j = lps[j-1];
    }
  }
}