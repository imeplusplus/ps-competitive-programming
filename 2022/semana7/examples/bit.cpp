ll bit[N];

void update(ll x, int pos) {
	while(pos <= n) {
		bit[pos] += x;
		pos += pos&(-pos);
	}
}

ll query(int pos) {
	ll r = 0;
	while(pos) {
		r+= bit[pos];
		pos -= pos&(-pos);
	}
	return r;
}

ll rangesum(int l, int r) {
	return query(r) - (l? query(l-1) : 0);
}