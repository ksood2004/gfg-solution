class Solution:
    def findOrder(words):
        # code here
        adj={c:set() for w in words for c in w}
        n=len(words)
        vis={}
        ans=[]
        for i in range(n-1):
            s=words[i]
            t=words[i+1]
            n=len(s)
            m=len(t)
            j=0
            k=min(n,m)
            if n>m and s[:k]==t[:k]:
                return ""
            while j<n and j<m:
                if s[j]!=t[j]:
                    adj[s[j]].add(t[j])
                    break
                j+=1
        def dfs(c):
            if c in vis:
                return vis[c]
            vis[c]=True
            for node in adj[c]:
                if dfs(node):
                    return True
            vis[c]=False
            ans.append(c)
        for c in adj:
            if dfs(c):
                return ""
        return "".join(ans[::-1])