//Knuth-Patt-Morris Algorithm for pattern searching in given string


/*
    txt is text and pat is the pattern to be searched
    vector pos stores the end position where pattern is found
    (0-based indexing)
    Time Conmplexity: O(pat.length + txt.length)
        */
        
        
vector<int> kmp(string txt, string pat) 
{
	string s = pat + '$' + txt;
	int n = s.length(), l = pat.length();
	vector<int> LPS(n, 0);
	int k = 0;
	for(int i = 1; i < n; ++i)
	{
		while(k > 0 && s[i] != s[k])
		{
			k = LPS[k-1];
		}
		if (s[i] == s[k]) 
		    ++k;
		LPS[i] = k;
	}
	vector<int> pos;
	for(int i = l; i < n; ++i)
	{
		if (LPS[i] == l)
		{
			pos.push_back(i-l-1);
		}
	}
	return pos;
}
