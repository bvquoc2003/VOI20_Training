inline int ReadInt() {
	char ch;
	while (ch=getchar(), ch<'0' || ch>'9');
	int res=ch-'0';
	while (ch=getchar(), ch>='0' && ch<='9') res=res*10+ch-'0';
	return res;
}
void WriteInt(int x) {
	if (x>9) WriteInt(x/10);
	putchar(x%10+'0');
}