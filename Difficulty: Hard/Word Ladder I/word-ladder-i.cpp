class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        set<string> wordset(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        if(wordset.find(targetWord)==wordset.end()){
            return 0;
        }
        
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==targetWord){
                return step;
            }
            
            for(int i=0;i<word.length();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(wordset.find(word)!=wordset.end()){
                        wordset.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=orignal;
            }
        }
        return 0;
    }
};