void removeDuplicate1(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i];
            for(int j=i+1; j<len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}

void removeDuplicate2(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(!c[s[i]])
        {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';    
}

void removeDuplicate3(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int check = 0, p = 0;
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v))==0)
        {
            s[p++] = s[i];
            check |= (1<<v);
        }
    }
    s[p] = '\0';
}

