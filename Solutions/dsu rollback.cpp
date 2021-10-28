int find(int x)
{
	if(par[x]==x) return x;
	stk.push(mp(x, par[x]));
	par[x]=find(par[x]);
	return par[x];
}
void uni(int x, int y)
{
	x=find(x); y=find(y);
	if(sz[y]>sz[x])
	{
		swap(x, y);
	}
	sz[x]+=sz[y];
	sz[y]=0;
	sizes.push(stk.size());
	stk.push(mp(y, par[y])); //also push the y component size here
	par[y]=x;
}
void rollback()
{
	int lstsz=sizes.top();
	stk.pop();
	while(stk.size()>lstsz)
	{
		par[stk.top().first]=stk.top().second;
		stk.pop();	
	}//also adjust the y component size here
}